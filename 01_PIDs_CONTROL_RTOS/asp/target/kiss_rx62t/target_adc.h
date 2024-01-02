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
 *
 */

/*
 *	Analog to digital control device driver (A/D) (for KISS-RX62T)
 */

#ifndef TOPPERS_TARGET_ADC_H
#define TOPPERS_TARGET_ADC_H

#include "kiss_rx62t_config.h"
#include "rx600/rx600_adc.h"

/*
 * Vector number of A/D interrupt handler
 */
#define INTNO_AIO_ADI0   INT_AD0_ADI0 /* Interrupt AD0 */
#define INTPRI_AIO       -4           /* Interrupt priority */
#define INTATR_AIO       (TA_NULL)    /* Interrupt attribute */

#ifndef TOPPERS_MACRO_ONLY

/*
 * Initialization of ADC driver
 */
extern void aio_initialize(intptr_t exinf);

/*
 *  Open ADC port
 */
extern AIOPCB* aio_opn_por(ID aiopid, intptr_t exinf);

/*
 *  Closing ADC port
 */
extern void aio_cls_por(AIOPCB* p_aiopcb);

/*
 * ADC write function
 */
extern ER_UINT aio_rea_dat(ID aiopid, uint8_t pin, uint16_t* dat);

/*
 * ADC interrupt handler
 */
extern void aio_isr(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_ADC_H */
