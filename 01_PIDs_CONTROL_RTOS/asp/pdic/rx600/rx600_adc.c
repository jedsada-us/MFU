/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX610 adc driver
 */

#include <sil.h>
#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "rx600_adc.h"

/*
 *  Definition of ADC port initialization block
 */
typedef struct aio_port_initialization_block
{
    volatile uint16_t* addra_reg;   /* A/D data register A */
    volatile uint16_t* addrb_reg;   /* A/D data register B */
    volatile uint16_t* addrc_reg;   /* A/D data register C */
    volatile uint16_t* addrd_reg;   /* A/D data register D */
    volatile uint16_t* addre_reg;   /* A/D data register E */
    volatile uint16_t* addrf_reg;   /* A/D data register F */
    volatile uint16_t* addrg_reg;   /* A/D data register G */
    volatile uint16_t* addrh_reg;   /* A/D data register H */
    volatile uint16_t* addri_reg;   /* A/D data register I */
    volatile uint16_t* addrj_reg;   /* A/D data register J */
    volatile uint16_t* addrk_reg;   /* A/D data register K */
    volatile uint16_t* addrl_reg;   /* A/D data register L */
    volatile uint8_t*  adcsr_reg;   /* A/D control/status register */
    volatile uint8_t*  adcr_reg;    /* A/D control register */
    volatile uint8_t*  adsstr_reg;  /* A/D sampling state register */
    volatile uint8_t*  addiagr_reg; /* A/D self-diagnostic register */
    volatile uint8_t*  adstrgr_reg; /* A/D start trigger select register */
    volatile uint8_t*  addpr_reg;   /* ADDRn format select register */
} AIOPINIB;

struct aio_port_control_block
{
    const    AIOPINIB* p_aiopinib; /* ADC port initialization block */
    intptr_t exinf;                /* Extended information */
    bool_t   openflag;             /* open flag */
    bool_t   is_initialized;       /* Device initialized flag */
};

static AIOPCB aiopcb_table[TNUM_AIOP];

/*
 *  ADC initialization block
 */
static const AIOPINIB aiopinib_table[TNUM_AIOP] = {
    {
        (volatile uint16_t*) ADC_ADDRA_ADDR,
        (volatile uint16_t*) ADC_ADDRB_ADDR,
        (volatile uint16_t*) ADC_ADDRC_ADDR,
        (volatile uint16_t*) ADC_ADDRD_ADDR,
        (volatile uint16_t*) ADC_ADDRE_ADDR,
        (volatile uint16_t*) ADC_ADDRF_ADDR,
        (volatile uint16_t*) ADC_ADDRG_ADDR,
        (volatile uint16_t*) ADC_ADDRH_ADDR,
        (volatile uint16_t*) ADC_ADDRI_ADDR,
        (volatile uint16_t*) ADC_ADDRJ_ADDR,
        (volatile uint16_t*) ADC_ADDRK_ADDR,
        (volatile uint16_t*) ADC_ADDRL_ADDR,
        (volatile uint8_t*)  ADC_ADCSR_ADDR,
        (volatile uint8_t*)  ADC_ADCR_ADDR,
        (volatile uint8_t*)  ADC_ADSSTR_ADDR,
        (volatile uint8_t*)  ADC_ADDIAGR_ADDR,
        (volatile uint8_t*)  ADC_ADSTRGR_ADDR,
        (volatile uint8_t*)  ADC_ADDPR_ADDR,
    },
};

/*
 *  Macro for extracting management block from ADC port ID
 */
#define INDEX_ADCP(aiopid)   ((uint_t)((aiopid)-1))
#define get_aiopcb(aiopid)   (&(aiopcb_table[INDEX_ADCP(aiopid)]))
#define get_aiopinib(aiopid) (&(aiopinib_table[INDEX_ADCP(aiopid)]))

void rx600_adc_initialize(void)
{
    AIOPCB* p_aiopcb;
    uint_t  i;

    /*
	 * Initialization of ADC port management block
	 */
    for (p_aiopcb = aiopcb_table, i = 0; i < TNUM_AIOP; p_aiopcb++, i++)
    {
        p_aiopcb->p_aiopinib = &(aiopinib_table[i]);
        p_aiopcb->openflag   = false;
    }
}

AIOPCB* rx600_adc_opn_por(ID aiopid, intptr_t exinf)
{
    AIOPCB*  p_aiopcb;
    p_aiopcb = get_aiopcb(aiopid);

    /* Prevention of double initialization  */
    if (!(p_aiopcb->is_initialized))
    {
		/* Clear ADC data */
		sil_wrb_mem((void*)p_aiopcb->p_aiopinib->adcsr_reg,   0x00);
		sil_wrb_mem((void*)p_aiopcb->p_aiopinib->adcr_reg,    0x00);
		sil_wrb_mem((void*)p_aiopcb->p_aiopinib->addpr_reg,   0x00);
		sil_wrb_mem((void*)p_aiopcb->p_aiopinib->addiagr_reg, 0x00);

		/* Enable ADC */
		sil_wrw_mem((void*)(SYSTEM_MSTPCRA_ADDR),
				(sil_rew_mem((void*)(SYSTEM_MSTPCRA_ADDR))) & ~(SYSTEM_MSTPCRA_MSTPA23_BIT));

		/* Configure continuous scan mode and clk 25MHz */
		sil_wrb_mem((void*)p_aiopcb->p_aiopinib->adcr_reg,
				(sil_reb_mem((void*)p_aiopcb->p_aiopinib->adcr_reg)) | (0x0E));

		/* Select channel AN0- AN5 and start ADC */
		sil_wrb_mem((void*)p_aiopcb->p_aiopinib->adcsr_reg,
				(sil_reb_mem((void*)p_aiopcb->p_aiopinib->adcsr_reg)) | (0x25));

		p_aiopcb->is_initialized = true;
	}

    p_aiopcb->exinf    = exinf;
    p_aiopcb->openflag = true;

    return (p_aiopcb);
}

/*
 * Closing the ADC port
 */
void rx600_adc_cls_por(AIOPCB* p_aiopcb)
{
    /*
	 *  ADC close
	 */
    sil_wrb_mem((void*)p_aiopcb->p_aiopinib->adcr_reg, 0x00);
    p_aiopcb->openflag       = false;
    p_aiopcb->is_initialized = false;
}

uint16_t rx600_adc_rea_dat(ID aiopid, uint8_t pin)
{
	static uint16_t dat = 0;
    AIOPCB*  p_aiopcb   = get_aiopcb(aiopid);

	switch (pin)
	{
		case 0:
			/* get value from AN0 Port */
			dat = ((sil_reh_mem((void*)p_aiopcb->p_aiopinib->addra_reg)) & 0x03FF);
			break;
		case 1:
			/* ACMS-CANuC not support this channel */
			break;
		case 2:
			/* get value from AN2 Port */
			dat = ((sil_reh_mem((void*)p_aiopcb->p_aiopinib->addrc_reg)) & 0x03FF);
			break;
		case 3:
			/* get value from AN3 Port */
			dat = ((sil_reh_mem((void*)p_aiopcb->p_aiopinib->addrd_reg)) & 0x03FF);
			break;
		case 4:
			/* get value from AN4 Port */
			dat = ((sil_reh_mem((void*)p_aiopcb->p_aiopinib->addre_reg)) & 0x03FF);
			break;
		case 5:
			/* get value from AN5 Port */
			dat = ((sil_reh_mem((void*)p_aiopcb->p_aiopinib->addrf_reg)) & 0x03FF);
			break;
		default:
			dat = 0;
			break;
	}

	return (dat);
}

void rx600_adc_isr(ID aiopid)
{
    /* AIOPCB* p_aiopcb = get_aiopcb(aiopid); */
    /* print log */
    syslog(LOG_NOTICE, "adc isr (aiopid = %d).", aiopid);
}
