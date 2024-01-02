/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *	RX610 General I/O interface module
 */
#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "kiss_rx62t_config.h"
#include "target_gpio.h"

/*
 * Initialization of GPIO driver
 */
void gio_initialize(intptr_t exinf)
{
	rx600_gpio_initialize();
}

/*
 * Open GPIO I/O port
 */
GIOPCB* gio_opn_por(ID giopid, intptr_t exinf)
{
	GIOPCB* p_giopcb = NULL;
	ER ercd;

	/*
	 *  Mask GPIO interrupt
	 *  (the dis_int function is described in \kernel\interrupt.c")
	 */
	ercd = dis_int(INTNO_GIO_IRQ2);
	assert(ercd == E_OK);
#if 0
	ercd = dis_int(INTNO_GIO_NMI);
	assert(ercd == E_OK);
	ercd = dis_int(INTNO_GIO_RESET);
	assert(ercd == E_OK);
#endif

	p_giopcb = rx600_gpio_opn_por(giopid, exinf);

	sil_wrb_mem((void*)(ICU_IRQ2_ADDR),
			sil_reb_mem((void*)(ICU_IRQ2_ADDR)) | ICU_IRQMD_BIT);
#if 0

	sil_wrb_mem((void*)(ICU_NMICR_ADDR),
			sil_reb_mem((void*)(ICU_NMICR_ADDR)) | ICU_NMIMD_BIT);
#endif

	/*
	 *  Unmask GPIO interrupt
	 *  (the ena_int function is described in \kernel\interrupt.c")
	 */
	ercd = ena_int(INTNO_GIO_IRQ2);
	assert(ercd == E_OK);
#if 0
	ercd = ena_int(INTNO_GIO_NMI);
	assert(ercd == E_OK);
	ercd = ena_int(INTNO_GIO_RESET);
	assert(ercd == E_OK);
#endif

	return (p_giopcb);
}

/*
 *  Closing GPIO port
 */
void gio_cls_por(GIOPCB* p_giopcb)
{
	ER ercd;

	/*
	 *  Device dependent close processing
	 */
	rx600_gpio_cls_por(p_giopcb);

	/*
	 *  Unmask GPIO interrupt
	 *  (the ena_int function is described in \kernel\interrupt.c")
	 */
	ercd = dis_int(INTNO_GIO_IRQ2);
	assert(ercd == E_OK);
#if 1
	ercd = dis_int(INTNO_GIO_NMI);
	assert(ercd == E_OK);
	ercd = dis_int(INTNO_GIO_RESET);
	assert(ercd == E_OK);
#endif
}

/*
 * GPIO write function
 */
ER_UINT gio_wri_dat(ID giopid, uint8_t pin, uint8_t dat)
{
	rx600_gpio_wri_dat(giopid, pin, dat);

	return E_OK;
}

/*
 * GPIO read function
 */
ER_UINT gio_rea_dat(ID giopid, uint8_t pin, uint8_t* dat)
{
	*dat = rx600_gpio_rea_dat(giopid, pin);

	return E_OK;
}

/*
 * GPIO IRQ2 interrupt handler
 */
void gio_irq2_isr(intptr_t exinf)
{
	rx600_gpio_irq2_isr(exinf);
}

/*
 * GPIO NMI interrupt handler
 */
void gio_nmi_isr(intptr_t exinf)
{
	rx600_gpio_nmi_isr(exinf);
}

/*
 * GPIO reset interrupt handler
 */
void gio_reset_isr(intptr_t exinf)
{
	rx600_gpio_reset_isr(exinf);
}
