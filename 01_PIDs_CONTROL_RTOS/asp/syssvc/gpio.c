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
 *  GPIO interface driver
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "target_gpio.h"
#include "gpio.h"
#include "kernel_cfg.h"

/*
 *  GPIO port management block
 */
typedef struct gpio_port_control_block
{
	GIOPCB* p_giopcb;  /* GPIO port management block */
	bool_t  openflag;  /* Open flag */
	bool_t  errorflag; /* Error flag */
	uint_t  ioctl;     /* Operation control setting value */
} GPCB;

static GPCB gpcb_table[TNUM_GIOP];

/*
 * Macro for extracting IO control port management block to GPIO port ID
 */
#define INDEX_PORT(portid)    ((uint_t)((portid)-1))
#define get_gpcb(portid)      (&(gpcb_table[INDEX_PORT(portid)]))

/*
 *  Service call call macro
 *
 * Evaluate the expression exp that contains the service call invocation,
 * and if the return value is an error (negative value)
 * For ercd_exp evaluated ercd_exp is substituted for erc and goto on error_exit.
 */
#define SVC(exp, ercd_exp)     \
{                              \
	if ((exp) < 0)             \
	{                          \
		ercd = (ercd_exp);     \
		goto error_exit;       \
	}                          \
}

/*
 * Generate E_SYS error
 */
static ER gen_ercd_sys(GPCB* p_gpcb)
{
	p_gpcb->errorflag = true;
	return (E_SYS);
}

/*
 *  IO control interface driver initialization routine
 */
void gpio_initialize(intptr_t exinf)
{
	uint_t i;
	GPCB*  p_gpcb;

	for (p_gpcb = gpcb_table, i = 0; i < TNUM_GIOP; p_gpcb++, i++)
	{
		p_gpcb->openflag = false;
	}
}

/*
 * Open IO control port (sevice call)
 */
ER gpio_opn_por(ID portid)
{
	GPCB* p_gpcb;
	ER    ercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_GIOP))
	{
		return (E_ID); /* Check port number */
	}
	p_gpcb = get_gpcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_gpcb));
	if (p_gpcb->openflag) /* Check whether it is open */
	{
		ercd = E_OBJ;
	}
	else
	{
		/*
		 * Initializing variables
		 */
		p_gpcb->ioctl = 0;

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
		p_gpcb->p_giopcb = gio_opn_por(portid, (intptr_t)p_gpcb);

		/*
		 *  Initializing flag variables
		 */
		p_gpcb->openflag  = true;
		p_gpcb->errorflag = false;

		if (unl_cpu() < 0)
		{
			p_gpcb->errorflag = true;
			ercd = E_SYS;
			goto error_exit_enadsp;
		}
		ercd = E_OK;
	}

error_exit_enadsp:
	SVC(ena_dsp(), gen_ercd_sys(p_gpcb));

error_exit:
	return (ercd);
}

/*
 *  Close IO control port (service call)
 */
ER gpio_cls_por(ID portid)
{
	GPCB*  p_gpcb;
	ER     ercd;
	bool_t eflag = false;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_GIOP)) /* Check port number */
	{
		return (E_ID);
	}
	p_gpcb = get_gpcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_gpcb));
	if (!(p_gpcb->openflag)) /* Check whether it is open */
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
		gpio_cls_por(portid);
		p_gpcb->openflag = false;
		if (unl_cpu() < 0)
		{
			eflag = true;
		}

		/*
		 *  Error code setting
		 */
		if (eflag)
		{
			ercd = gen_ercd_sys(p_gpcb);
		}
		else
		{
			ercd = E_OK;
		}
	}
	SVC(ena_dsp(), gen_ercd_sys(p_gpcb));

error_exit:
	return (ercd);
}

/*
 *  Write data to the IO control port (service call)
 */
ER_UINT gpio_wri_dat(ID portid, uint8_t pin, uint8_t dat)
{
	GPCB* p_gpcb;
	ER    ercd, rercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_GIOP)) /* Check port number */
	{
		return (E_ID);
	}

	p_gpcb = get_gpcb(portid);
	if (!(p_gpcb->openflag)) /* Check whether it is open */
	{
		return (E_OBJ);
	}
	if (p_gpcb->errorflag) /* Check for error condition */
	{
		return (E_SYS);
	}

	/* Lock resource */
	SVC(loc_cpu(), gen_ercd_sys(p_gpcb));

	/* Call gpio_write driver for target_gpio.c */
	SVC(rercd = gio_wri_dat(portid, pin, dat), rercd);

	/* Unlock resource */
	SVC(unl_cpu(), gen_ercd_sys(p_gpcb));
	ercd = E_OK;

error_exit:
	return (ercd > 0U ? (ER_UINT)E_OK : ercd);
}

/*
 *  Read data from the IO control port (service call)
 */
ER_UINT gpio_rea_dat(ID portid, uint8_t pin, uint8_t* dat)
{
	GPCB* p_gpcb;
	ER    ercd, rercd;

	if (sns_dpn()) /* Context check */
	{
		return (E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_GIOP)) /* Check port number */
	{
		return (E_ID);
	}

	p_gpcb = get_gpcb(portid);
	if (!(p_gpcb->openflag)) /* Check whether it is open */
	{
		return (E_OBJ);
	}
	if (p_gpcb->errorflag) /* Check for error condition */
	{
		return (E_SYS);
	}

	/* Lock resource */
	SVC(loc_cpu(), gen_ercd_sys(p_gpcb));

	/* Call gpio_write driver for target_gpio.c */
	SVC(rercd = gio_rea_dat(portid, pin, dat), rercd);

	/* Unlock resource */
	SVC(unl_cpu(), gen_ercd_sys(p_gpcb));
	ercd = E_OK;

error_exit:
	return (ercd > 0U ? (ER_UINT)E_OK : ercd);
}
