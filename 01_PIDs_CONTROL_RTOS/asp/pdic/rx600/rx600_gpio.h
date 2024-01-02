/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX62T gpio driver
 */

#ifndef TOPPERS_RX600_GPIO_H
#define TOPPERS_RX600_GPIO_H

/*
 *  GPIO related definition
 *
 *  use in pdic/rx600/rx600_gpio.c
 */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  Definition of GPIO port management block
 */
typedef struct gio_port_control_block GIOPCB;

extern void    rx600_gpio_initialize(void);
extern GIOPCB* rx600_gpio_opn_por(ID giopid, intptr_t exinf);
extern void    rx600_gpio_cls_por(GIOPCB* p_giopcb);
extern void    rx600_gpio_wri_dat(ID giopid, uint8_t pin, uint8_t dat);
extern uint8_t rx600_gpio_rea_dat(ID giopid, uint8_t pin);
extern void    rx600_gpio_irq2_isr(ID giopid);
extern void    rx600_gpio_nmi_isr(ID giopid);
extern void    rx600_gpio_reset_isr(ID giopid);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_RX600_GPIO_H */
