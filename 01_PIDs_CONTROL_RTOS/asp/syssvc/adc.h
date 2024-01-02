/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 */

/*
 *   ADC control interface driver
 */

#ifndef TOPPERS_ADC_H
#define TOPPERS_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ADC control interface driver initialization routine
 */
extern void	adc_initialize(intptr_t exinf) throw();

/*
 *  ADC control interface driver service call
 */
extern ER		adc_opn_por(ID portid) throw();
extern ER		adc_cls_por(ID portid) throw();
extern ER_UINT	adc_rea_dat(ID portid, uint8_t pin, uint16_t* dat) throw();

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_ADC_H */
