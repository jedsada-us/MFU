/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 */

/*
 *  PWM interface driver
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "target_pwm.h"
#include "pwm.h"
#include "kernel_cfg.h"

/*
 *  PWM port management block
 */
typedef struct pwm_port_control_block
{
	PIOPCB* p_piopcb;  /* PWM port management block */
	bool_t  openflag;  /* Open flag */
	bool_t  errorflag; /* Error flag */
	uint_t  ioctl;       /* Operation control setting value */
} PPCB;

static PPCB ppcb_table[TNUM_PIOP];

/*
 * Macro for extracting IO control port management block to PWM port ID
 */
#define INDEX_PORT(portid)   ((uint_t)((portid)-1))
#define get_ppcb(portid)   (&(ppcb_table[INDEX_PORT(portid)]))

/*
 *  Service call call macro
 *
 * Evaluate the expression exp that contains the service call invocation,
 * and if the return value is an error (negative value)
 * For ercd_exp evaluated ercd_exp is substituted for erc and goto on error_exit.
 */
#define SVC(exp, ercd_exp) \
{                          \
	if ((exp) < 0)         \
	{                      \
		ercd = (ercd_exp); \
		goto error_exit;   \
	}                      \
}

/*
 * Generate E_SYS error
 */
static ER gen_ercd_sys(PPCB* p_ppcb)
{
	p_ppcb->errorflag = true;
	return (E_SYS);
}

/*
 *  IO control interface driver initialization routine
 */
void pwm_initialize(intptr_t exinf)
{
	uint_t i;
	PPCB* p_ppcb;

	for (p_ppcb = ppcb_table, i = 0; i < TNUM_PIOP; p_ppcb++, i++)
	{
		p_ppcb->openflag = false;
	}
}

/*
 * Open IO control port (sevice call)
 */
ER pwm_opn_por(ID portid)
{

	PPCB* p_ppcb;
	ER ercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PIOP))
	{
		return (E_ID); /* Check port number */
	}
	p_ppcb = get_ppcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_ppcb));
	if (p_ppcb->openflag) /* Check whether it is open */
	{
		ercd = E_OBJ;
	}
	else
	{
		/*
		 * Initializing variables
		 */
		p_ppcb->ioctl = 0;

		/*
		 *  After this, interrupts are prohibited.
		 */
		if (loc_cpu() < 0)
		{
			ercd = E_SYS;
			goto error_exit_enadsp;
		}

		/*
		 *  Hardware dependent open processing
		 */
		p_ppcb->p_piopcb = pio_opn_por(portid, (intptr_t)p_ppcb);

		/*
		 *  Initializing flag variables
		 */
		p_ppcb->openflag = true;
		p_ppcb->errorflag = false;

		if (unl_cpu() < 0)
		{
			p_ppcb->errorflag = true;
			ercd = E_SYS;
			goto error_exit_enadsp;
		}
		ercd = E_OK;
	}

error_exit_enadsp:
	SVC(ena_dsp(), gen_ercd_sys(p_ppcb));

error_exit:
	return (ercd);
}

/*
 *  Close IO control port (service call)
 */
ER pwm_cls_por(ID portid)
{
	PPCB* p_ppcb;
	ER ercd;
	bool_t eflag = false;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PIOP)) /* Check port number */
	{
		return (E_ID);
	}
	p_ppcb = get_ppcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_ppcb));
	if (!(p_ppcb->openflag)) /* Check whether it is open */
	{
		ercd = E_OBJ;
	}
	else
	{
		/*
		 *  Hardware dependent close processing
		 */
		if (loc_cpu() < 0)
		{
			eflag = true;
		}
		pwm_cls_por(portid);
		p_ppcb->openflag = false;
		if (unl_cpu() < 0)
		{
			eflag = true;
		}

		/*
		 *  Error code setting
		 */
		if (eflag)
		{
			ercd = gen_ercd_sys(p_ppcb);
		}
		else
		{
			ercd = E_OK;
		}
	}
	SVC(ena_dsp(), gen_ercd_sys(p_ppcb));

error_exit:
	return (ercd);
}

/*
 *  Write data to the IO control port (service call)
 */
ER_UINT pwm_wri_dat(ID portid, uint8_t pin, uint8_t dat)
{
	PPCB* p_ppcb;
	ER ercd, rercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PIOP)) /* Check port number */
	{
		return (E_ID);
	}

	p_ppcb = get_ppcb(portid);
	if (!(p_ppcb->openflag)) /* Check whether it is open */
	{
		return (E_OBJ);
	}
	if (p_ppcb->errorflag) /* Check for error condition */
	{
		return (E_SYS);
	}

	/* Lock resource */
	SVC(loc_cpu(), gen_ercd_sys(p_ppcb));

	/* Call gpio_write driver for target_pwm.c */
	SVC(rercd = pio_wri_dat(portid, pin, dat), rercd);

	/* Unlock resource */
	SVC(unl_cpu(), gen_ercd_sys(p_ppcb));
	ercd = E_OK;

error_exit:
	return (ercd > 0U ? (ER_UINT)E_OK : ercd);
}
