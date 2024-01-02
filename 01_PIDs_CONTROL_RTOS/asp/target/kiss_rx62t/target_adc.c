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
#include "target_adc.h"

/*
 * Initialization of ADC driver
 */
void aio_initialize(intptr_t exinf)
{
	rx600_adc_initialize();
}

/*
 * Open ADC I/O port
 */
AIOPCB* aio_opn_por(ID aiopid, intptr_t exinf)
{
	AIOPCB* p_aiopcb = NULL;
	/* ER ercd; */

	/*
	 *  Mask ADC interrupt
	 *  (the dis_int function is described in \kernel\interrupt.c")
	 */
#if 0
	ercd = dis_int(INTNO_AIO_ADI0);
	assert(ercd == E_OK);
#endif

	p_aiopcb = rx600_adc_opn_por(aiopid, exinf);

	/*
	 *  Unmask ADC interrupt
	 *  (the ena_int function is described in \kernel\interrupt.c")
	 */
#if 0
	ercd = ena_int(INTNO_AIO_ADI0);
	assert(ercd == E_OK);
#endif

	return (p_aiopcb);
}

/*
 *  Closing ADC port
 */
void aio_cls_por(AIOPCB* p_aiopcb)
{
	ER ercd;

	/*
	 *  Device dependent close processing
	 */
	rx600_adc_cls_por(p_aiopcb);

	/*
	 *  Unmask ADC interrupt
	 *  (the ena_int function is described in \kernel\interrupt.c")
	 */
	ercd = dis_int(INTNO_AIO_ADI0);
	assert(ercd == E_OK);
}

/*
 * ADC write function
 */
ER_UINT aio_rea_dat(ID aiopid, uint8_t pin, uint16_t* dat)
{
	*dat = rx600_adc_rea_dat(aiopid, pin);

	return E_OK;
}

/*
 * ADC interrupt handler
 */
void aio_isr(intptr_t exinf)
{
	rx600_adc_isr(exinf);
}
