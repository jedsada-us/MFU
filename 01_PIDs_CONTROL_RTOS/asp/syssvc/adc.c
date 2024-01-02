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
 *  ADC control interface driver
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "target_adc.h"
#include "adc.h"
#include "kernel_cfg.h"

/*
 *  ADC control port management block
 */
typedef struct adc_port_control_block
{
	AIOPCB* p_aiopcb;  /* ADC port management block */
	bool_t  openflag;  /* Open flag */
	bool_t  errorflag; /* Error flag */
	uint_t  ioctl;	   /* Operation control setting value */
} APCB;

static APCB apcb_table[TNUM_AIOP];

/*
 * Macro for extracting ADC control port management block to ADC port ID
 */
#define INDEX_PORT(portid)      ((uint_t)((portid)-1))
#define get_apcb(portid)        (&(apcb_table[INDEX_PORT(portid)]))

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
static ER gen_ercd_sys(APCB* p_apcb)
{
	p_apcb->errorflag = true;
	return (E_SYS);
}

/*
 *  IO control interface driver initialization routine
 */
void adc_initialize(intptr_t exinf)
{
	uint_t i;
	APCB*  p_apcb;

	for (p_apcb = apcb_table, i = 0; i < TNUM_AIOP; p_apcb++, i++)
	{
		p_apcb->openflag = false;
	}
}

/*
 * Open IO control port (sevice call)
 */
ER adc_opn_por(ID portid)
{
	APCB* p_apcb;
	ER    ercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_AIOP))
	{
		return (E_ID); /* Check port number */
	}
	p_apcb = get_apcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_apcb));
	if (p_apcb->openflag) /* Check whether it is open */
	{
		ercd = E_OBJ;
	}
	else
	{
		/*
		 * Initializing variables
		 */
		p_apcb->ioctl = 0;

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
		p_apcb->p_aiopcb = aio_opn_por(portid, (intptr_t)p_apcb);

		/*
		 *  Initializing flag variables
		 */
		p_apcb->openflag = true;
		p_apcb->errorflag = false;

		if (unl_cpu() < 0)
		{
			p_apcb->errorflag = true;
			ercd = E_SYS;
			goto error_exit_enadsp;
		}
		ercd = E_OK;
	}

error_exit_enadsp:
	SVC(ena_dsp(), gen_ercd_sys(p_apcb));

error_exit:
	return (ercd);
}

/*
 *  Close IO control port (service call)
 */
ER adc_cls_por(ID portid)
{
	APCB*  p_apcb;
	ER     ercd;
	bool_t eflag = false;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_AIOP)) /* Check port number */
	{
		return (E_ID);
	}
	p_apcb = get_apcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_apcb));
	if (!(p_apcb->openflag)) /* Check whether it is open */
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
		adc_cls_por(portid);
		p_apcb->openflag = false;
		if (unl_cpu() < 0)
		{
			eflag = true;
		}

		/*
		 *  Error code setting
		 */
		if (eflag)
		{
			ercd = gen_ercd_sys(p_apcb);
		}
		else
		{
			ercd = E_OK;
		}
	}
	SVC(ena_dsp(), gen_ercd_sys(p_apcb));

error_exit:
	return (ercd);
}

/*
 *  Read data from the IO control port (service call)
 */
ER_UINT adc_rea_dat(ID portid, uint8_t pin, uint16_t* dat)
{
	APCB* p_apcb;
	ER    ercd, rercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_AIOP)) /* Check port number */
	{
		return (E_ID);
	}

	p_apcb = get_apcb(portid);
	if (!(p_apcb->openflag)) /* Check whether it is open */
	{
		return (E_OBJ);
	}
	if (p_apcb->errorflag) /* Check for error condition */
	{
		return (E_SYS);
	}

	/* Lock resource */
	SVC(loc_cpu(), gen_ercd_sys(p_apcb));

	/* Call gpio_write driver for target_adc.c */
	SVC(rercd = aio_rea_dat(portid, pin, dat), rercd);

	/* Unlock resource */
	SVC(unl_cpu(), gen_ercd_sys(p_apcb));
	ercd = E_OK;

error_exit:
	return (ercd > 0U ? (ER_UINT)E_OK : ercd);
}
