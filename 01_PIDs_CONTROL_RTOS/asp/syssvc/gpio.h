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
 * General I/O control interface driver
 */

#ifndef TOPPERS_GPIO_H
#define TOPPERS_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * General I/O control interface driver initialization routine
 */
extern void gpio_initialize(intptr_t exinf) throw();

/*
 * General I/O control interface driver service call
 */
extern ER      gpio_opn_por(ID portid) throw();
extern ER      gpio_cls_por(ID portid) throw();
extern ER_UINT gpio_wri_dat(ID portid, uint8_t pin, uint8_t dat) throw();
extern ER_UINT gpio_rea_dat(ID portid, uint8_t pin, uint8_t* dat) throw();

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_GPIO_H */
