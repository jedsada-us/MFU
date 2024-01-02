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
 *	I/O control device (GPIO) driver (for KISS-RX62T)
 */

#ifndef TOPPERS_TARGET_GPIO_H
#define TOPPERS_TARGET_GPIO_H

#include "kiss_rx62t_config.h"
#include "rx600/rx600_gpio.h"

/*
 * Vector number of I/O interrupt handler
 */
#define INTNO_GIO_IRQ2    INT_IRQ2  /* Interrupt nCANuC_PBSW1 */
#define INTNO_GIO_NMI     INT_NMI   /* Interrupt nCANuC_PBSW2 */
#define INTNO_GIO_RESET   INT_RESET /* Interrupt nCANuC_IRQI */
#define INTPRI_GIO        -4        /* Interrupt priority */
#define INTATR_GIO        (TA_NULL) /* Interrupt attribute */

#ifndef TOPPERS_MACRO_ONLY

/*
 * Initialization of GPIO driver
 */
extern void gio_initialize(intptr_t exinf);

/*
 *  Open GPIO port
 */
extern GIOPCB* gio_opn_por(ID giopid, intptr_t exinf);

/*
 *  Closing GPIO port
 */
extern void gio_cls_por(GIOPCB* p_giopcb);

/*
 * GPIO write function
 */
extern ER_UINT gio_wri_dat(ID giopid, uint8_t pin, uint8_t dat);

/*
 * GPIO read function
 */
extern ER_UINT gio_rea_dat(ID giopid, uint8_t pin, uint8_t* dat);


/*
 * GPIO IRQ2 interrupt handler
 */
extern void gio_irq2_isr(intptr_t exinf);

/*
 * GPIO NMI interrupt handler
 */
extern void gio_nmi_isr(intptr_t exinf);

/*
 * GPIO reset interrupt handler
 */
extern void gio_reset_isr(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_GPIO_H */
