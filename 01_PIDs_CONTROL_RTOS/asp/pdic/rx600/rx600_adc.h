/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX62T adc driver
 */

#ifndef TOPPERS_RX600_ADC_H
#define TOPPERS_RX600_ADC_H

/*
 *  ADC related definition
 *
 *  use in pdic/rx600/rx600_adc.c
 */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  Definition of ADC port management block
 */
typedef struct aio_port_control_block AIOPCB;

extern void     rx600_adc_initialize(void);
extern AIOPCB*  rx600_adc_opn_por(ID aiopid, intptr_t exinf);
extern void     rx600_adc_cls_por(AIOPCB* p_aiopcb);
extern uint16_t rx600_adc_rea_dat(ID aiopid, uint8_t pin);
extern void     rx600_adc_isr(ID aiopid);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_RX600_ADC_H */
