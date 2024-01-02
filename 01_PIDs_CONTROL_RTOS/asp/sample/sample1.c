/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  @(#) $Id: sample1.c 1797 2010-06-07 04:24:19Z ertl-hiro $
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/gpio.h"
#include "syssvc/adc.h"
#include "syssvc/pwm.h"
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"

/* Variable Definition*/
#define PWM_MIN_RANGE      0
#define PWM_MAX_RANGE      100
#define ADC_MIN_RANGE      0
#define ADC_MAX_RANGE      1023

/*
 * PIDs definition function
 */
static int32_t PIDs(uint32_t, uint32_t, float32_t, float32_t, float32_t, float32_t);
static uint8_t saturate(int32_t, int32_t, int32_t);

#ifdef DEF_ADC_DRV
	/*
	 * Declaration variable
	 * CN5 = Set Point
	 * CN4 = Feedback
	 */
	static uint16_t an5_dat = 0;
	static uint16_t an4_dat = 0;
#endif


/*
 * initial Variable
 */
static uint16_t  feedback = 0;
static uint16_t  setpoint = 0;
static int32_t   ut       = 0;
static float32_t Kp       = 0.0f;
static float32_t Ki       = 0.0f;
static float32_t Kd       = 0.0f;
static float32_t Dt       = 0.0f;

/*
 * Call Error log service
 */
Inline void svc_perror(const char* file, int_t line, const char* expr, ER ercd)
{
    if (ercd < 0)
    {
        t_perror(LOG_ERROR, file, line, expr, ercd);
    }
}

#define SVC_PERROR(expr) svc_perror(__FILE__, __LINE__, #expr, (expr))

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
static int32_t PIDs(uint32_t sp, uint32_t fb, float32_t kp, float32_t ki, float32_t kd, float32_t dt)
{
	/*
	 * intitial PIDs Variable
	 */
	int32_t error               = 0;
	float32_t P                 = 0.0f;
	static float32_t accumError = 0.0f;
	float32_t I                 = 0.0f;
	static float32_t lastError  = 0.0f;
	float32_t D                 = 0.0f;
	float32_t errorDiff         = 0.0f;

	/* P term */
	error = sp - fb;
	P     = kp * error;

	/* I term */
	accumError += error * dt;
	if (accumError < PWM_MIN_RANGE)
	{
		accumError = PWM_MIN_RANGE;
	}
	if (accumError > PWM_MAX_RANGE)
	{
		accumError = PWM_MAX_RANGE;
	}
	I = ki * accumError;

	/* D term */
	errorDiff = (error - lastError) / dt;
	lastError = error;
	D         = kd * errorDiff;

	/* return PIDs value */
	return (int32_t)(P + I + D);
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
static uint8_t saturate(int32_t input, int32_t min, int32_t max)
{
	if (input <= min)
	{
		return min;
	}
	if (input > max)
	{
		return max;
	}

	return (uint8_t)input;
}

/*
 *  Tasks to be executed concurrently
 */
void task(intptr_t exinf)
{
	int_t tskno = (int_t) exinf;
    ER_UINT ercd;
	static uint8_t led_state = 0;

	/** Set PIDs gain */
	Kp = 2.0f;
	Ki = 1.0f;
	Kd = 0.1f;
	Dt = 0.024f;

	syslog(LOG_NOTICE, "task%d is running", tskno);

	while (1)
	{
#ifdef DEF_GPIO8_DRV
				/* LED3 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 2, led_state);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
				led_state = led_state ^ 1;
#endif

#ifdef DEF_ADC_DRV
				/* Reading AN2 - Debugging board */
				ercd = adc_rea_dat(TASK_ADCID, 5, &an5_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `adc_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
				SVC_PERROR(dly_tsk(1));                                  /**< Waiting ADC conversion (1 ms) */

				/* Reading AN3 - Debugging board */
				ercd = adc_rea_dat(TASK_ADCID, 4, &an4_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `adc_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
				SVC_PERROR(dly_tsk(1));                                  /**< Waiting ADC conversion (1 ms) */
#endif
#ifdef DEF_PWM_DRV
				/**
				 * ADC calculation
				 */
				setpoint = an5_dat;                               /**< Get set point value from port AN5 */
				feedback = an4_dat;;                           /**< Get feedback value from port AN4 */

				/**
				 * PIDs calculation
				 */
				ut = PIDs(setpoint, feedback, Kp, Ki, Kd, Dt);        /**< Calculate PIDs */
				ut = saturate(ut, PWM_MIN_RANGE, PWM_MAX_RANGE);      /**< Limit PIDs output */

				/**
				 * PIDs calculation
				 */
				if (setpoint < 10)
				{
					ut = 0;
				}

				/* Wrinting PWM2 - Debugging board */
				ercd = pwm_wri_dat(TASK_PWMID, 2, (uint8_t)(ut));
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `pwm_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif

		syslog(LOG_NOTICE, "#PID,%d,%d,%d", setpoint, feedback, ut);
		SVC_PERROR(dly_tsk(10));
	}
}

/*
 *  Main Task
 */
void main_task(intptr_t exinf)
{
#ifdef DEF_ADC_DRV
	/*
	 * Declaration variable
	 * VR1 = AN2 channel
	 * VR2 = AN3 channel
	 */
	static uint16_t an2_dat = 0;
	static uint16_t an3_dat = 0;
#endif

#ifdef DEF_GPIO5_DRV
	/*
	 * Declaration variable
	 * SW4, SW5, SW6 and SW7
	 */
	static uint8_t sw4_dat = 0;
	static uint8_t sw5_dat = 0;
	static uint8_t sw6_dat = 0;
	static uint8_t sw7_dat = 0;
#endif

    char_t  c;
	ID      tskid = MAIN_TASK;
    int_t   tskno = 1;
    ER_UINT ercd;
    PRI     tskpri;

    SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
    syslog(LOG_NOTICE, "Test device driver program starts (exinf = %d).", (int_t)exinf);

    /*
	 *  Initialize serial port driver
	 *
	 */
    ercd = serial_opn_por(TASK_SERIALID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
            itron_strerror(ercd), SERCD(ercd));
    }
    SVC_PERROR(serial_ctl_por(TASK_SERIALID, (IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));

#ifdef DEF_GPIO3_DRV
	/*
	 *  Initialize io control port 3 driver
	 *
	 */
    ercd = gpio_opn_por(TASK_PORT3_GPIOID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `gpio_opn_por'(3).",
            itron_strerror(ercd), SERCD(ercd));
    }
#endif

#ifdef DEF_GPIO5_DRV
	/*
	 *  Initialize io control port 5 driver
	 *
	 */
    ercd = gpio_opn_por(TASK_PORT5_GPIOID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `gpio_opn_por'(5).",
            itron_strerror(ercd), SERCD(ercd));
    }
#endif


#ifdef DEF_GPIO8_DRV
    /*
	 *  Initialize io control port 8 driver
	 *
	 */
    ercd = gpio_opn_por(TASK_PORT8_GPIOID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `gpio_opn_por'(8).",
            itron_strerror(ercd), SERCD(ercd));
    }
#endif

#ifdef DEF_GPIO9_DRV
	/*
	 *  Initialize io control port 9 driver
	 *
	 */
    ercd = gpio_opn_por(TASK_PORT9_GPIOID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `gpio_opn_por'(9).",
            itron_strerror(ercd), SERCD(ercd));
    }
#endif


#ifdef DEF_ADC_DRV
	/*
	 *  Initialize ADC driver
	 *
	 */
    ercd = adc_opn_por(TASK_ADCID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `adc_opn_por'.",
            itron_strerror(ercd), SERCD(ercd));
    }
#endif

#ifdef DEF_PWM_DRV
	/*
	 *  Initialize PWM driver
	 *
	 */
    ercd = pwm_opn_por(TASK_PWMID);
    if (ercd < 0 && MERCD(ercd) != E_OBJ)
    {
        syslog(LOG_ERROR, "%s (%d) reported by `pwm_opn_por'.",
            itron_strerror(ercd), SERCD(ercd));
    }
#endif

	/*
	 *  Activate task
	 */
	SVC_PERROR(act_tsk(TASK1));

    /*
	 *   Main Loop
	 */
    do
    {
		SVC_PERROR(serial_rea_dat(TASK_SERIALID, &c, 1));
		switch (c)
		{
			case '1':
#ifdef DEF_GPIO3_DRV
				/* LED4 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT3_GPIOID, 2, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO8_DRV
				/* LED1 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 0, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO9_DRV
				/* LED1 On - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 0, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '2':
#ifdef DEF_GPIO3_DRV
				/* LED5 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT3_GPIOID, 1, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO8_DRV
				/* LED2 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 1, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO9_DRV
				/* LED2 On - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 1, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '3':
#ifdef DEF_GPIO3_DRV
				/* LED6 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT3_GPIOID, 0, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO8_DRV
				/* LED3 On - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 2, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO9_DRV
				/* LED3 - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 2, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '4':
#ifdef DEF_GPIO9_DRV
				/* LED4 - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 3, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '5':
#ifdef DEF_GPIO3_DRV
				/* LED4 Off - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT3_GPIOID, 2, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO8_DRV
				/* LED2 Off - Debugging board  board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 0, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO9_DRV
				/* LED1 Off - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 0, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '6':
#ifdef DEF_GPIO3_DRV
				/* LED5 Off - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT3_GPIOID, 1, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO8_DRV
				/* LED2 Off - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 1, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO9_DRV
				/* LED2 - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 1, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '7':
#ifdef DEF_GPIO3_DRV
				/* LED6 Off - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT3_GPIOID, 0, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO8_DRV
				/* LED3 Off - Debugging board */
				ercd = gpio_wri_dat(TASK_PORT8_GPIOID, 2, 1);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
#ifdef DEF_GPIO9_DRV
				/* LED3 Off - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 2, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case '8':
#ifdef DEF_GPIO9_DRV
				/* LED4 Off - ACMS-CANuC board */
				ercd = gpio_wri_dat(TASK_PORT9_GPIOID, 3, 0);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case 'a':
#ifdef DEF_ADC_DRV
				/* Reading AN2 - Debugging board */
				ercd = adc_rea_dat(TASK_ADCID, 2, &an2_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `adc_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}

				/* Reading AN3 - Debugging board */
				ercd = adc_rea_dat(TASK_ADCID, 3, &an3_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `adc_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}

				syslog(LOG_NOTICE, "Main TASK VR1 : %d ", an2_dat);
				syslog(LOG_NOTICE, "Main TASK VR2 : %d ", an3_dat);
#endif
#ifdef DEF_PWM_DRV

				/* Wrinting PWM2 - Debugging board */
				ercd = pwm_wri_dat(TASK_PWMID, 2, (uint8_t)(an2_dat / 10));
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `pwm_wri_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}
#endif
				break;
			case 'b':
#ifdef DEF_GPIO5_DRV
				/* Reading SW4 - Debugging board */
				ercd = gpio_rea_dat(TASK_PORT5_GPIOID, 1, &sw4_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}

				/* Reading SW5 - Debugging board */
				ercd = gpio_rea_dat(TASK_PORT5_GPIOID, 2, &sw5_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}

				/* Reading SW4 - Debugging board */
				ercd = gpio_rea_dat(TASK_PORT5_GPIOID, 3, &sw6_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}

				/* Reading SW4 - Debugging board */
				ercd = gpio_rea_dat(TASK_PORT5_GPIOID, 4, &sw7_dat);
				if (ercd < 0 && MERCD(ercd) != E_OBJ)
				{
					syslog(LOG_ERROR, "%s (%d) reported by `gpio_rea_dat'.",
							itron_strerror(ercd), SERCD(ercd));
				}

				syslog(LOG_NOTICE, "Main TASK SW4 : %d ", sw4_dat);
				syslog(LOG_NOTICE, "Main TASK SW5 : %d ", sw5_dat);
				syslog(LOG_NOTICE, "Main TASK SW6 : %d ", sw6_dat);
				syslog(LOG_NOTICE, "Main TASK SW7 : %d ", sw7_dat);
#endif
				break;
			case 'G':
				syslog(LOG_INFO, "#get_pri(%d, &tskpri)", tskno);
				SVC_PERROR(ercd = get_pri(tskid, &tskpri));
				if (ercd >= 0)
				{
					syslog(LOG_NOTICE, "priority of task %d is %d", tskno, tskpri);
				}
				break;
			default:
				/* Do nothing */
				break;
        }

    } while (c != '\003' && c != 'Q');

#if 0
	ercd = gpio_cls_por(TASK_PORT3_GPIOID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ)
	{
		syslog(LOG_ERROR, "%s (%d) reported by `gpio_cls_por'.",
				itron_strerror(ercd), SERCD(ercd));
	}

	ercd = gpio_cls_por(TASK_PORT8_GPIOID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ)
	{
		syslog(LOG_ERROR, "%s (%d) reported by `gpio_cls_por'.",
				itron_strerror(ercd), SERCD(ercd));
	}

	ercd = gpio_cls_por(TASK_PORT9_GPIOID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ)
	{
		syslog(LOG_ERROR, "%s (%d) reported by `gpio_cls_por'.",
				itron_strerror(ercd), SERCD(ercd));
	}
#endif

    syslog(LOG_NOTICE, "Test device driver program");
    SVC_PERROR(ext_ker());
    assert(0);
}
