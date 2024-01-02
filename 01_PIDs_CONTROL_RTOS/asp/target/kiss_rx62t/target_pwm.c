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
#include "target_pwm.h"

/*
 * Initialization of PWM driver
 */
void pio_initialize(intptr_t exinf)
{
	rx600_pwm_initialize();
}

/*
 * Open PWM I/O port
 */
PIOPCB* pio_opn_por(ID piopid, intptr_t exinf)
{
	PIOPCB* p_piopcb = NULL;

	p_piopcb = rx600_pwm_opn_por(piopid, exinf);

	return (p_piopcb);
}

/*
 *  Closing PWM port
 */
void pio_cls_por(PIOPCB* p_piopcb)
{
	/*
	 *  Device dependent close processing
	 */
	rx600_pwm_cls_por(p_piopcb);
}

/*
 * PWM write function
 */
ER_UINT pio_wri_dat(ID piopid, uint8_t pin, uint8_t dat)
{
	rx600_pwm_wri_dat(piopid, pin, dat);

	return E_OK;
}
