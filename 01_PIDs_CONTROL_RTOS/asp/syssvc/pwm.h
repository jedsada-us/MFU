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
 *   PWM control interface driver
 */

#ifndef TOPPERS_PWM_H
#define TOPPERS_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  PWM control interface driver initialization routine
 */
extern void	pwm_initialize(intptr_t exinf) throw();

/*
 *  IO control interface driver service call
 */
extern ER		pwm_opn_por(ID portid) throw();
extern ER		pwm_cls_por(ID portid) throw();
extern ER_UINT  pwm_wri_dat(ID portid, uint8_t pin, uint8_t dat) throw();

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_PWM_H */
