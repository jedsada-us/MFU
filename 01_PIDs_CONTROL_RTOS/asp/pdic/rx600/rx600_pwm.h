/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX62T pwm driver
 */

#ifndef TOPPERS_RX600_PWM_H
#define TOPPERS_RX600_PWM_H

/*
 *  PWM related definition
 *
 *  use in pdic/rx600/rx600_pwm.c
 */

#define PWM_MAGIC_NUM           (100)
#define PWM_MIN_RANGE           (0)
#define PWM_MAX_RANGE           (10000)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  Definition of PWM port management block
 */
typedef struct pio_port_control_block PIOPCB;

extern void    rx600_pwm_initialize(void);
extern PIOPCB* rx600_pwm_opn_por(ID piopid, intptr_t exinf);
extern void    rx600_pwm_cls_por(PIOPCB* p_piopcb);
extern void    rx600_pwm_wri_dat(ID piopid, uint8_t pin, uint8_t dat);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_RX600_PWM_H */
