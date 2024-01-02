/**
 * @file      main.c
 * @brief     [MID-001]-[Vertical Kit from Hand Code]
 * @author    -
 * @version   00.01
 * @date      2018-09-05
 */
#include <stdio.h>
#include "iodefine.h"

/**
 * Type Definition
 */
typedef char               s1;
typedef short              s2;
typedef long               s4;
typedef long long          s8;
typedef unsigned char      u1;
typedef unsigned short     u2;
typedef unsigned long      u4;
typedef unsigned long long u8;
typedef float              f4;

/** Variable Definition*/
#define BUF_SZ             20
#define MIN				   0
#define MAX				   100
#define PWM_MIN_RANGE      0
#define PWM_MAX_RANGE      4175
#define ADC_MIN_RANGE      0
#define ADC_MAX_RANGE      1023

/** ACMS-CANuC/RX62T LEDs (TOP) */
#define	DL2			       PORT9.DR.BIT.B0
#define	DL3			       PORT9.DR.BIT.B1
#define	DL4			       PORT9.DR.BIT.B2
#define	DL5			       PORT9.DR.BIT.B3
#define	DL2_DDR		       PORT9.DDR.BIT.B0
#define	DL3_DDR		       PORT9.DDR.BIT.B1
#define	DL4_DDR		       PORT9.DDR.BIT.B2
#define	DL5_DDR		       PORT9.DDR.BIT.B3

#define DL_ON			   0
#define DL_OFF     		   1
#define DL_EN       	   1

#define ALL_DLS_ON		   { DL2 = DL3 = DL4 = DL5 = DL_ON; }
#define ALL_DLS_OFF		   { DL2 = DL3 = DL4 = DL5 = DL_OFF; }
#define ENABLE_DLS         { DL2_DDR = DL3_DDR = DL4_DDR = DL5_DDR = DL_EN; }


/** RX62T-DBG LEDs (BOTTOM) */
#define	LED1			   PORT8.DR.BIT.B0
#define	LED2			   PORT8.DR.BIT.B1
#define	LED3			   PORT8.DR.BIT.B2
#define	LED1_DDR		   PORT8.DDR.BIT.B0
#define	LED2_DDR		   PORT8.DDR.BIT.B1
#define	LED3_DDR		   PORT8.DDR.BIT.B2

#define LED_ON      	   1
#define LED_OFF     	   0
#define LED_EN       	   1

#define ALL_LEDS_ON		   {LED1 = LED2 = LED3 = LED_ON;}
#define ALL_LEDS_OFF	   {LED1 = LED2 = LED3 = LED_OFF;}
#define ENABLE_LEDS        {LED1_DDR = LED2_DDR = LED3_DDR = LED_EN;}


/**
 * Hardware setup function definition
 */
void hw_init(void);

/**
 * Watch dog definition function
 */
void wdt_init(void);

/**
 * Watch dog clear definition function
 */
void wdt_clear(void);

/**
 * A/D definition function
 */
void adc_init(void);
u4 adc_read(u1);

/**
 * PWM definition function
 */
void pwm_init(void);
void pwm_out(u4);

/**
 * Serial Port definition function
 */
void sci0_init(u4);
void sci0_putc(s1);
void sci0_puts(s1*);
s1 sci0_getc(void);

/**
 * PIDs definition function
 */
s4 PIDs(u4, u4, f4, f4, f4, f4);
s4 saturate(s4, s4, s4);

/**
 * timer 3 definition function
 */
void timer3_init(void);

/**
 * time3_wait_ms definition function
 */
void time3_wait_ms(s4 ms);

/**
 * Variable interrupt timer 4 definition function
 */
void timer4_init(void);

/**
 * initial Variable
 */
s1 buf[BUF_SZ] = { 0 };
u4 feedback    = 0;
u4 setpoint    = 0;
s4 ut          = 0;
f4 ut_tmp      = 0.0f;
f4 Kp          = 0.0f;
f4 Ki          = 0.0f;
f4 Kd          = 0.0f;
f4 Dt          = 0.0f;

/**
 * Main function
 */
void main(void)
{
	/** Hardware initialize */
	hw_init();

	/** Watch dog initialize */
	wdt_init();

	/** Serial Port initialize */
	sci0_init(115200);

	/**  PWM Port initialize */
	pwm_init();

	/** ADC Port initialize */
	adc_init();

	/** Timer 3 Port initialize */
	timer3_init();

	/** Timer 4 Port initialize */
	timer4_init();

	/** Set DL ports as outputs. */
	ENABLE_DLS

	/** Turn the user DLs off */
	ALL_DLS_OFF

	/** Set LED ports as outputs. */
	ENABLE_LEDS

	/** Turn the user LEDs off */
	ALL_LEDS_OFF

	/** Print Vertical Kit version */
	sci0_puts("VT KIT V00.01\n");

	/** Set PIDs gain */
	Kp = 30.0f;
	Ki = 20.0f;
	Kd = 1.5f;
	Dt = 0.01f;

	while (1)
	{
		/** Led board status watch dog reset */
		LED3 = LED3 ^ 1;

		/**
		 * Print the data to serial port
		 */
		sci0_puts("#PID,");                                      /**< Print "\n" to serial port */
		sprintf(buf, "%d,", setpoint);                           /**< Convert set point value to integer number */
		sci0_puts(buf);                                          /**< Print set point buffer to serial port */
		sprintf(buf, "%d,", feedback);                           /**< Convert feedback value to integer number */
		sci0_puts(buf);                                          /**< Print feedback buffer to serial port */
		sprintf(buf, "%.0f,\n", (ut_tmp / PWM_MAX_RANGE) * 100); /**< Convert ut_tmp value to percentage */
		sci0_puts(buf);                                          /**< Print buffer to serial port */

		/** Waiting 10 ms */
		time3_wait_ms(10);

		/** Clear watch dog timer */
		wdt_clear();
	}
}

/** @brief [Module ID]-[Module name]hw_init  */
void hw_init(void)
{
	/** ICLK = EXTAL x 8 = 12.5MHz x 8 = 100 MHz. */
	SYSTEM.SCKCR.BIT.ICK = 0;

	/** PCLK = EXTAL x 4 = 12.5MHz x 4 = 50 MHz. */
	SYSTEM.SCKCR.BIT.PCK = 1;

	/** Disable low power mode and enable peripheral clock */
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
}

/** @brief [Module ID]-[Module name]wdt_init  */
void wdt_init(void)
{
	WDT.WRITE.WINA = 0x5A00;   /**< Writing data into TCNT */
	WDT.WRITE.WINB = 0x5A5F;   /**< Writing data into RSTCSR */
	WDT.WRITE.WINA = 0xA5FD;   /**< Writing data into TCSR */
}

/** @brief [Module ID]-[Module name]wdt_clear  */
void wdt_clear(void)
{
	WDT.WRITE.WINA = 0x5A00;   /**< Clearing data into TCNT */
}

/** @brief [Module ID]-[Module name]adc_init  */
void adc_init(void)
{
	SYSTEM.MSTPCRA.BIT.MSTPA23 = 0;    /**< enable ADC */
	AD0.ADCSR.BYTE             = 0x05; /**< select channel AN0- AN5 */
	AD0.ADCR.BYTE              = 0x0F; /**< configure continuous single mode and clk 25MHz */
	AD0.ADDPR.BYTE             = 0x00; /**< configure format of data */
	AD0.ADDIAGR.BYTE           = 0x00; /**< Self-diagnostic function is off. */
	AD0.ADCSR.BIT.ADST         = 0;    /**< stop read ADC */
}

/**
 * @brief [Module ID]-[Module name]adc_read
 *
 * @param channel
 *
 * @retval
 */
u4 adc_read(u1 channel)
{
	u4 val = 0;

	/** start conversion */
	AD0.ADCSR.BIT.ADST = 1;

	/** Waiting conversion complete */
	while (AD0.ADCSR.BIT.ADST == 0);

	switch (channel)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			val = (AD0.ADDRC & 0x03FF); /**< get value from AN2 Port */
			break;
		case 3:
			val = (AD0.ADDRD & 0x03FF); /**< get value from AN3 port */
			break;
		case 4:
			val = (AD0.ADDRE & 0x03FF); /**< get value from AN4 port */
			break;
		case 5:
			val = (AD0.ADDRF & 0x03FF); /**< get value from AN5 port */
			break;
		default:
			val = 0;
			break;
	}

	return val;
}

/** @brief [Module ID]-[Module name]pwm_init  */
void pwm_init()
{
	MTU0.TCR.BYTE            = 0x20; /**< set clock and select TGRA */
	MTU0.TMDR.BIT.MD         = 2;    /**< set mode pwm mode 1 */

	/**
	 * Set Timer I/O control with IOA => Initial output High,
	 * output Low when match high and IOB =>Initial output LOW,
	 * output High when match high
	 */
	MTU0.TIORH.BYTE         = 0x25;
	IOPORT.PFCMTU.BIT.MTUS0 = 1;             /**< select destination channel */
	MTU0.TGRA               = PWM_MAX_RANGE; /**< set freq. 6kHz */
	MTU.TSTRA.BIT.CST0      = 1;             /**< start timer */
}

/**
 * @brief [Module ID]-[Module name]pwm_out
 *
 * @param duty
 */
void pwm_out(u4 duty)
{
	/**
	 * PWM_MAX_RANGE - value because PWM get start is low and add + 1
	 * because PWM not work when is 0
	 */
	MTU0.TGRB = (PWM_MAX_RANGE - duty) + 1;
}

/**
 * @brief [Module ID]-[Module name]sci0_init
 *
 * @param bspeed
 */
void sci0_init(u4 bspeed)
{
	MSTP(SCI0)          = 0;    /**< Enable SCI0 module */
	PORTB.DDR.BIT.B1    = 0;    /**< Assign Rx (PB1) as input */
	PORTB.ICR.BIT.B1    = 1;    /**< Input RX (PB1) enable */
	PORTB.DDR.BIT.B2    = 1;    /**< Assign TX (PB2) as output */
	SCI0.SCR.BYTE       = 0x00; /**< Disable transmit and reception interrupt */
	SCI0.SMR.BYTE       = 0x00; /**< Set SCI in Asynchronous mode with 8 bits of data */
	SCI0.SCR.BIT.RIE    = 1;    /**< Enable receive interrupt of SCI0, Generate flag */
	SCI0.SCR.BIT.TIE    = 1;    /**< Enable transmit interrupt of SCI0, Generate flag */
	IR(SCI0, RXI0)      = 0;    /**< Clear the interrupt request for receive */
	IR(SCI0, TXI0)      = 0;    /**< Clear the interrupt request for transmit */
	IEN(SCI0, RXI0)     = 0;    /**< Disable the interrupt request for receive */
	IEN(SCI0, TXI0)     = 0;    /**< Disable the interrupt request for transmit */

	/**
	 * Calculate buad rate speed
	 *        N = BRR setting for baud rate generator (0 <= N <= 255)
	 *        n = Determined by the SMR setting shown in the following table (n = 0)
	 *
	 *        N = ((25MHz / 32^(2n-1) x bspeed)) - 1
	 *        N = ((25MHz / 32^(2(0)-1) x bspeed)) - 1
	 *        N = ((25MHz / 16 x bspeed)) - 1
	 *        N = N + 0.5  Rounding the number
	 * SCIO.BRR = N
	 *
	 * Example :
	 *        bspeed = 115200
	 *        N      = ((25MHz / 16 x 115200)) - 1
	 *		  N      = 12.5634
	 *		  N      = 12.5634 + 0.5  Rounding the number
	 *		  N      = (u1) 13.0634   Type casting
	 *		  N      = 13
	 */
	SCI0.BRR = (u1)((25000000 / (16 * bspeed)) - 1) + 0.5;

	/** Enable transmission and reception */
	SCI0.SCR.BYTE |= 0x30;
}

/**
 * @brief [Module ID]-[Module name]sci0_getc
 *
 * @retval
 */
s1 sci0_getc(void)
{
	s1 c = 0;

	while (IR(SCI0, RXI0) == 0);
	c = SCI0.RDR;
	IR(SCI0, RXI0) = 0;

	return c;
}

/**
 * @brief [Module ID]-[Module name]sci0_putc
 *
 * @param c
 */
void sci0_putc(s1 c)
{
	while (IR(SCI0, TXI0) == 0);
	IR(SCI0, TXI0) = 0;
	SCI0.TDR = c;
}

/**
 * @brief [Module ID]-[Module name]sci0_puts
 *
 * @param str
 */
void sci0_puts(s1* str)
{
	while (*str != '\0')
	{
		sci0_putc(*str++);
	}
}

/**
 * @brief [Module ID]-[Module name]PIDs
 *
 * @param setpoint
 * @param feedback
 * @param kp
 * @param ki
 * @param kd
 * @param dt
 *
 * @retval
 */
s4 PIDs(u4 setpoint, u4 feedback, f4 kp, f4 ki, f4 kd, f4 dt)
{
	/**
	 * intitial PIDs Variable
	 */
	s4 error             = 0;
	f4 P                 = 0.0f;
	static f4 accumError = 0.0f;
	f4 I                 = 0.0f;
	static f4 lastError  = 0.0f;
	f4 D                 = 0.0f;
	f4 errorDiff         = 0.0f;

	/** P term */
	error = setpoint - feedback;
	P     = kp * error;

	/** I term */
	accumError += error * dt;
	if (accumError < MIN)
	{
		accumError = MIN;
	}
	if (accumError > MAX)
	{
		accumError = MAX;
	}
	I = ki * accumError;

	/** D term */
	errorDiff = (error - lastError) / dt;
	lastError = error;
	D         = kd * errorDiff;

	/** return PIDs value */
	return (s4)(P + I + D);
}

/**
 * @brief [Module ID]-[Module name]saturate
 *
 * @param input
 * @param min
 * @param max
 *
 * @retval
 */
s4 saturate(s4 input, s4 min, s4 max)
{
	if (input <= min)
	{
		return min;
	}
	if (input > max)
	{
		return max;
	}

	return input;
}

/** @brief [Module ID]-[Module name]timer3_init  */
void timer3_init(void)
{
	MTU3.TCR.BIT.TPSC  = 3;    /**< Clock prescale divide by 64 */
	MTU3.TCR.BIT.CCLR  = 1;    /**< Selecting counter clear source as TGRA */
	MTU3.TGRA          = 1553; /**< Timing target set to 1 ms*/
	MTU3.TGRB          = 0;    /**< Clear TGRB value */
	MTU3.TSR.BIT.TGFA  = 0;    /**< Clear timer flag */
	MTU.TSTRA.BIT.CST3 = 1;    /**< Start the timer */
}

/**
 * @brief [Module ID]-[Module name]time3_wait_ms
 *
 * @param ms
 */
void time3_wait_ms(s4 ms)
{
	do {
		if (MTU3.TSR.BIT.TGFA == 1)
		{
			ms--;
			MTU3.TSR.BIT.TGFA  = 0U;
		}
	} while (ms > 0);
}

/** @brief [Module ID]-[Module name]timer_init  */
void timer4_init(void)
{
	MTU4.TCR.BIT.TPSC                = 3;     /**< ICLK divide by 64 */
	MTU4.TCR.BIT.CCLR                = 1;     /**< Configure counter clear source as TGRD / 6 original */
	MTU4.TGRA                        = 15546; /**< Set Period 10 ms. */
	ICU.IER[IER_MTU4_TGIA4].BIT.IEN6 = 0;     /**< Disable Interrupt Request */
	ICU.IPR[IPR_MTU4_TGIA4].BIT.IPR  = 1;	  /**< Priority Level 1 */
	ICU.IR[IR_MTU4_TGIA4].BIT.IR     = 0;	  /**< Clear Interrupt Flag */
	MTU4.TSR.BIT.TGFA                = 0;     /**< Clear comparison flag */
	MTU4.TIER.BIT.TGIEA              = 1;	  /**< Enable Timer Interrupt */
	ICU.IER[IER_MTU4_TGIA4].BIT.IEN6 = 1;	  /**< Enable Interrupt Request */
	MTU.TSTRA.BIT.CST4               = 1;     /**< Start Counting */
}

/** @brief [Module ID]-[Module name]irq_timer4_10ms  */
#pragma interrupt (irq_timer4_10ms(vect = 134))
void irq_timer4_10ms(void)
{
	LED1 = LED1 ^ 1;                                      /**< LED test point at 10 ms */
	LED2 = LED_ON;                                        /**< LED on for estimate time for calculation */

	/**
	 * ADC calculation
	 */
	setpoint = adc_read(5);                               /**< Get set point value from port AN5 */
	feedback = adc_read(4);                               /**< Get feedback value from port AN4 */
	time3_wait_ms(1);                                     /**< Waiting ADC conversion (1 ms) */

	/**
	 * PIDs calculation
	 */
	ut = PIDs(setpoint, feedback, Kp, Ki, Kd, Dt);        /**< Calculate PIDs */
	ut = saturate(ut, PWM_MIN_RANGE, PWM_MAX_RANGE);      /**< Limit PIDs output */
	ut_tmp = ut;									      /**< PIDs output temporary */
	time3_wait_ms(1);                                     /**< Waiting ADC conversion (1 ms) */

	/**
	 * PIDs calculation
	 */
	if (setpoint < 10)
	{
		ut = 0;
	}
	pwm_out((u4)ut);                                      /**< Set pwm duty cycle */

#if 0
	/**
	 * Print the data to serial port
	 */
	sci0_puts("#PID,");                                   /**< Print "\n" to serial port */
	sprintf(buf, "%d,", setpoint);                        /**< Convert set point value to integer number */
	sci0_puts(buf);                                       /**< Print set point buffer to serial port */
	sprintf(buf, "%d,", feedback);                        /**< Convert feedback value to integer number */
	sci0_puts(buf);                                       /**< Print feedback buffer to serial port */
	sprintf(buf, "%.2f,", (ut_tmp/ PWM_MAX_RANGE) * 100); /**< Convert ut_tmp value to percentage */
	sci0_puts(buf);                                       /**< Print buffer to serial port */
	sci0_puts("1,1,0,0,\n");                              /**< Print "\n" to serial port */
#endif

	ICU.IR[IR_MTU4_TGIA4].BIT.IR = 0;	                   /**< Clear timer 4 interrupt flag */
	MTU4.TSR.BIT.TGFA            = 0;                      /**< Clear comparison flag */
	LED2                         = LED_OFF;                /**< LED off for estimate time for calculation */
}
