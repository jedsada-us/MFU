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
 *	PWM control device driver (for KISS-RX62T)
 */

#ifndef TOPPERS_TARGET_PWM_H
#define TOPPERS_TARGET_PWM_H

#include "kiss_rx62t_config.h"
#include "rx600/rx600_pwm.h"

/*
 * Vector number of PWM interrupt handler
 */
/* Do nothing */

#ifndef TOPPERS_MACRO_ONLY

/*
 * Initialization of PWM driver
 */
extern void pio_initialize(intptr_t exinf);

/*
 *  Open PWM port
 */
extern PIOPCB* pio_opn_por(ID piopid, intptr_t exinf);

/*
 *  Closing PWM port
 */
extern void pio_cls_por(PIOPCB* p_piopcb);

/*
 * PWM write function
 */
extern ER_UINT pio_wri_dat(ID piopid, uint8_t pin, uint8_t dat);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_PWM_H */
