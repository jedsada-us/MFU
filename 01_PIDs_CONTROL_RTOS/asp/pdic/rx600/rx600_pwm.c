/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX610 pwm driver
 */

#include <sil.h>
#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "rx600_pwm.h"

/*
 *  Definition of GPT register initialization block
 */
typedef struct pio_port_initialization_block
{
    volatile uint8_t*  ioport_pfcmtu_reg;
    volatile uint8_t*  mtu_tstra_reg;
    volatile uint8_t*  mtu0_tcr_reg;
    volatile uint8_t*  mtu0_tmdr1_reg;
    volatile uint8_t*  mtu0_tiorh_reg;
    volatile uint8_t*  mtu0_tiorl_reg;
    volatile uint8_t*  mtu0_tier_reg;
    volatile uint8_t*  mtu0_tsr_reg;
    volatile uint16_t* mtu0_tgra_reg;
    volatile uint16_t* mtu0_tgrb_reg;
    volatile uint16_t* mtu0_tgrc_reg;
    volatile uint16_t* mtu0_tgrd_reg;
} PIOPINIB;

struct pio_port_control_block
{
    const    PIOPINIB* p_piopinib; /* PWM register initialization block */
    intptr_t exinf;                /* Extended information */
    bool_t   openflag;             /* open flag */
    bool_t   is_initialized;       /* Device initialized flag */
};

static PIOPCB piopcb_table[TNUM_PIOP];

/*
 *  PWM initialization block
 */
static const PIOPINIB piopinib_table[TNUM_PIOP] = {
    {
        (volatile uint8_t*)  IOPORT_PFCMTU_ADDR,
        (volatile uint8_t*)  MTU_TSTRA_ADDR,
        (volatile uint8_t*)  MTU0_TCR_ADDR,
        (volatile uint8_t*)  MTU0_TMDR1_ADDR,
        (volatile uint8_t*)  MTU0_TIORH_ADDR,
        (volatile uint8_t*)  MTU0_TIORL_ADDR,
        (volatile uint8_t*)  MTU0_TIER_ADDR,
        (volatile uint8_t*)  MTU0_TSR_ADDR,
        (volatile uint16_t*) MTU0_TGRA_ADDR,
        (volatile uint16_t*) MTU0_TGRB_ADDR,
        (volatile uint16_t*) MTU0_TGRC_ADDR,
        (volatile uint16_t*) MTU0_TGRD_ADDR,
    },
};

/*
 *  Macro for extracting management block from PWM port ID
 */
#define INDEX_PWMP(piopid)   ((uint_t)((piopid)-1))
#define get_piopcb(piopid)   (&(piopcb_table[INDEX_PWMP(piopid)]))
#define get_piopinib(piopid) (&(piopinib_table[INDEX_PWMP(piopid)]))

void rx600_pwm_initialize(void)
{
    PIOPCB* p_piopcb;
    uint_t i;

    /*
	 * Initialization of PWM port management block
	 */
    for (p_piopcb = piopcb_table, i = 0; i < TNUM_PIOP; p_piopcb++, i++)
    {
        p_piopcb->p_piopinib = &(piopinib_table[i]);
        p_piopcb->openflag = false;
    }
}

PIOPCB* rx600_pwm_opn_por(ID piopid, intptr_t exinf)
{
    PIOPCB* p_piopcb;

    p_piopcb = get_piopcb(piopid);

    /* Prevention of double initialization  */
    if (!(p_piopcb->is_initialized))
    {
		/* Clear timer data */
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu0_tcr_reg,      0x00);
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu0_tmdr1_reg,    0x00);
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu0_tiorh_reg,    0x00);
        sil_wrh_mem((void*)p_piopcb->p_piopinib->mtu0_tgra_reg,     0x0000);
        sil_wrh_mem((void*)p_piopcb->p_piopinib->mtu0_tgrb_reg,     0x0000);
        sil_wrb_mem((void*)p_piopcb->p_piopinib->ioport_pfcmtu_reg, 0x00);
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu_tstra_reg,     0x00);

		/* Disable low power mode and enable peripheral clock */
        sil_wrw_mem((void*)(SYSTEM_MSTPCRA_ADDR),
            (sil_rew_mem((void*)(SYSTEM_MSTPCRA_ADDR))) & ~(SYSTEM_MSTPCRA_MSTPA9_BIT));

		/* Set clock and select TGRA */
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu0_tcr_reg,
            (sil_reb_mem((void*)p_piopcb->p_piopinib->mtu0_tcr_reg)) | (0x20));

		/* Set mode pwm mode 1 */
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu0_tmdr1_reg,
            (sil_reb_mem((void*)p_piopcb->p_piopinib->mtu0_tmdr1_reg)) | (0x02));

		/*
		 * Set Timer I/O control with IOA => Initial output High,
		 * output Low when match high and IOB =>Initial output LOW,
		 * output High when match high
		 */
		sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu0_tiorh_reg,
				(sil_reb_mem((void*)p_piopcb->p_piopinib->mtu0_tiorh_reg)) | (0x25));

		/* Set frequency = 9.95 KHz */
        sil_wrh_mem((void*)p_piopcb->p_piopinib->mtu0_tgra_reg,
            (sil_reh_mem((void*)p_piopcb->p_piopinib->mtu0_tgra_reg)) & (PWM_MAX_RANGE));

		/* Select destination channel */
        sil_wrb_mem((void*)p_piopcb->p_piopinib->ioport_pfcmtu_reg,
            (sil_reb_mem((void*)p_piopcb->p_piopinib->ioport_pfcmtu_reg)) | (0x01));

		/**< start timer */
        sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu_tstra_reg,
            (sil_reb_mem((void*)p_piopcb->p_piopinib->mtu_tstra_reg)) | (0x01));

        p_piopcb->is_initialized = true;
    }

    p_piopcb->exinf = exinf;
    p_piopcb->openflag = true;

    /* syslog(LOG_NOTICE, "Test PWM driver program starts xxx\n"); */
    return (p_piopcb);
}

/*
 * Closing the PWM port
 */
void rx600_pwm_cls_por(PIOPCB* p_piopcb)
{
    /*
	 *  PWM close
	 */
    sil_wrb_mem((void*)p_piopcb->p_piopinib->mtu_tstra_reg, 0U);
    p_piopcb->openflag       = false;
    p_piopcb->is_initialized = false;
}

void rx600_pwm_wri_dat(ID piopid, uint8_t pin, uint8_t dat)
{
    static  uint16_t duty = 0;
    PIOPCB* p_piopcb      = get_piopcb(piopid);

    /* Conver 0-100% to 0-10000 */
    duty = dat * PWM_MAGIC_NUM;
    if (duty <= PWM_MIN_RANGE)
    {
        duty = PWM_MIN_RANGE;
    }
    if (duty >= PWM_MAX_RANGE)
    {
        duty = PWM_MAX_RANGE;
    }

    duty = (PWM_MAX_RANGE - duty) + 1;
    sil_wrh_mem((void*)p_piopcb->p_piopinib->mtu0_tgrb_reg, duty);

    /* syslog(LOG_NOTICE, "Test pwm write val : %d ", duty); */
}
