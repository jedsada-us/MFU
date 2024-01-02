/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX610 gpio driver
 */

#include <sil.h>
#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "rx600_gpio.h"

/*
 *  Definition of GPIO port initialization block
 */
typedef struct gio_port_initialization_block
{
	volatile uint8_t* ddr_reg;      /* Data direction register */
	volatile uint8_t* dr_reg;       /* Data register */
	volatile uint8_t* port_reg;     /* port register */
	volatile uint8_t* icr_reg;      /* Input buffer control register */
} GIOPINIB;

struct gio_port_control_block
{
	const    GIOPINIB* p_giopinib; /* GPIO port initialization block */
	intptr_t exinf;                /* Extended information */
	bool_t   openflag;             /* open flag */
	bool_t   is_initialized;       /* Device initialized flag */
};

static GIOPCB giopcb_table[TNUM_GIOP];

/*
 *  GPIO initialization block
 */
static const GIOPINIB giopinib_table[TNUM_GIOP] = {
	{
		( volatile uint8_t* )PORT3_DDR_ADDR,
		( volatile uint8_t* )PORT3_DR_ADDR,
		( volatile uint8_t* )PORT3_PORT_ADDR,
		( volatile uint8_t* )PORT3_ICR_ADDR,
	},
#if TNUM_GIOP > 1
	{
		( volatile uint8_t* )NULL,
		( volatile uint8_t* )NULL,
		( volatile uint8_t* )PORT5_PORT_ADDR,
		( volatile uint8_t* )PORT5_ICR_ADDR,
	},
#endif
#if TNUM_GIOP > 2
	{
		( volatile uint8_t* )PORT8_DDR_ADDR,
		( volatile uint8_t* )PORT8_DR_ADDR,
		( volatile uint8_t* )PORT8_PORT_ADDR,
		( volatile uint8_t* )PORT8_ICR_ADDR,
	},
#endif
#if TNUM_GIOP > 3
	{
		( volatile uint8_t* )PORT9_DDR_ADDR,
		( volatile uint8_t* )PORT9_DR_ADDR,
		( volatile uint8_t* )PORT9_PORT_ADDR,
		( volatile uint8_t* )PORT9_ICR_ADDR,
	},
#endif
#if TNUM_GIOP > 4
	{
		( volatile uint8_t* )PORTE_DDR_ADDR,
		( volatile uint8_t* )PORTE_DR_ADDR,
		( volatile uint8_t* )PORTE_PORT_ADDR,
		( volatile uint8_t* )PORTE_ICR_ADDR,
	},
#endif
};

/*
 *  Macro for extracting management block from GPIO port ID
 */
#define INDEX_GIOP(giopid)   ((uint_t)((giopid)-1))
#define get_giopcb(giopid)   (&(giopcb_table[INDEX_GIOP(giopid)]))
#define get_giopinib(giopid) (&(giopinib_table[INDEX_GIOP(giopid)]))

void rx600_gpio_initialize(void)
{
	GIOPCB* p_giopcb;
	uint_t  i;

	/*
	 * Initialization of GPIO port management block
	 */
	for (p_giopcb = giopcb_table, i = 0; i < TNUM_GIOP; p_giopcb++, i++)
	{
		p_giopcb->p_giopinib = &(giopinib_table[i]);
		p_giopcb->openflag   = false;
	}
}

GIOPCB* rx600_gpio_opn_por(ID giopid, intptr_t exinf)
{
	GIOPCB*  p_giopcb;
	p_giopcb = get_giopcb(giopid);

	/* Prevention of double initialization  */
	if (!(p_giopcb->is_initialized))
	{
		sil_wrb_mem((void*)p_giopcb->p_giopinib->ddr_reg, 0x00);

		p_giopcb->is_initialized = true;
	}

	p_giopcb->exinf    = exinf;
	p_giopcb->openflag = true;

	return (p_giopcb);
}

/*
 * Closing the GPIO port
 */
void rx600_gpio_cls_por(GIOPCB* p_giopcb)
{
	/*
	 *  GPIO close
	 */
	sil_wrb_mem((void*)p_giopcb->p_giopinib->ddr_reg, 0xFFU);
	p_giopcb->openflag       = false;
	p_giopcb->is_initialized = false;
}


void rx600_gpio_wri_dat(ID giopid, uint8_t pin, uint8_t val)
{
	GIOPCB* p_giopcb = get_giopcb(giopid);

#if 0
	/* Solution 1 */
	sil_wrb_mem((void *)(PORT9_DDR_ADDR) ,
			sil_reb_mem((void *)(PORT9_DDR_ADDR)) | pin);
	sil_wrb_mem((void *)(PORT9_DR_ADDR) ,
			sil_reb_mem((void *)(PORT9_DR_ADDR)) & ~(val));
#endif

	/* Configure GPIO as output */
	sil_wrb_mem((void*)p_giopcb->p_giopinib->ddr_reg,
			sil_reb_mem((void*)p_giopcb->p_giopinib->ddr_reg) | (1 << pin));
	if (val &  0x01)
	{
		sil_wrb_mem((void*)p_giopcb->p_giopinib->dr_reg,
				sil_reb_mem((void*)p_giopcb->p_giopinib->dr_reg) & ~(val << pin));
	}
	else
	{
		sil_wrb_mem((void*)p_giopcb->p_giopinib->dr_reg,
				sil_reb_mem((void*)p_giopcb->p_giopinib->dr_reg) | (1 << pin));
	}
}

uint8_t rx600_gpio_rea_dat(ID giopid, uint8_t pin)
{
	GIOPCB* p_giopcb = get_giopcb(giopid);

	/* Return GPIO input status */
	return ((sil_reb_mem((void*)p_giopcb->p_giopinib->port_reg) & (1 << pin)) >> pin);
}

void rx600_gpio_irq2_isr(ID giopid)
{
	/* GIOPCB* p_giopcb = get_giopcb(giopid); */
	/* print log */
	syslog(LOG_NOTICE, "irq2 isr (giopid = %d).", giopid);
}

void rx600_gpio_nmi_isr(ID giopid)
{
	/* GIOPCB* p_giopcb = get_giopcb(giopid); */
	/* print log */
	syslog(LOG_NOTICE, "nmi isr (giopid = %d).", giopid);
}

void rx600_gpio_reset_isr(ID giopid)
{
	/* GIOPCB* p_giopcb = get_giopcb(giopid); */
	/* print log */
	syslog(LOG_NOTICE, "reset isr (giopid = %d).", giopid);
}
