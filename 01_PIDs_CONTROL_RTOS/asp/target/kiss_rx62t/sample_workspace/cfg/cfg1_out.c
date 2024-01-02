/* cfg1_out.c */
#define TOPPERS_CFG1_OUT  1
#include "kernel/kernel_int.h"
#include "target_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_syssvc.h"
#include <target_gpio.h>
#include "syssvc/gpio.h"
#include "target_syssvc.h"
#include <target_adc.h>
#include "syssvc/adc.h"
#include "target_syssvc.h"
#include <target_pwm.h>
#include "syssvc/pwm.h"
#include "target_syssvc.h"
#include <target_serial.h>
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "sample1.h"


#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include <target_cfg1_out.h>

const uint32_t TOPPERS_cfg_magic_number = 0x12345678;
const uint32_t TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);
const unsigned_t TOPPERS_cfg_CHAR_BIT = CHAR_BIT;
const unsigned_t TOPPERS_cfg_CHAR_MAX = CHAR_MAX;
const unsigned_t TOPPERS_cfg_CHAR_MIN = CHAR_MIN;
const unsigned_t TOPPERS_cfg_SCHAR_MAX = SCHAR_MAX;
const unsigned_t TOPPERS_cfg_SHRT_MAX = SHRT_MAX;
const unsigned_t TOPPERS_cfg_INT_MAX = INT_MAX;
const unsigned_t TOPPERS_cfg_LONG_MAX = LONG_MAX;

const unsigned_t TOPPERS_cfg_TA_NULL = TA_NULL;
const unsigned_t TOPPERS_cfg_TA_ACT = TA_ACT;
const unsigned_t TOPPERS_cfg_TA_TPRI = TA_TPRI;
const unsigned_t TOPPERS_cfg_TA_MPRI = TA_MPRI;
const unsigned_t TOPPERS_cfg_TA_WMUL = TA_WMUL;
const unsigned_t TOPPERS_cfg_TA_CLR = TA_CLR;
const unsigned_t TOPPERS_cfg_TA_STA = TA_STA;
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = TA_NONKERNEL;
const unsigned_t TOPPERS_cfg_TA_ENAINT = TA_ENAINT;
const unsigned_t TOPPERS_cfg_TA_EDGE = TA_EDGE;
const signed_t TOPPERS_cfg_TMIN_TPRI = TMIN_TPRI;
const signed_t TOPPERS_cfg_TMAX_TPRI = TMAX_TPRI;
const signed_t TOPPERS_cfg_TMIN_DPRI = TMIN_DPRI;
const signed_t TOPPERS_cfg_TMAX_DPRI = TMAX_DPRI;
const signed_t TOPPERS_cfg_TMIN_MPRI = TMIN_MPRI;
const signed_t TOPPERS_cfg_TMAX_MPRI = TMAX_MPRI;
const signed_t TOPPERS_cfg_TMIN_ISRPRI = TMIN_ISRPRI;
const signed_t TOPPERS_cfg_TMAX_ISRPRI = TMAX_ISRPRI;
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = TMAX_MAXSEM;
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = TMAX_RELTIM;
const signed_t TOPPERS_cfg_TMIN_INTPRI = TMIN_INTPRI;
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = 
#if defined(OMIT_INITIALIZE_INTERRUPT)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = 
#if defined(OMIT_INITIALIZE_EXCEPTION)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_USE_TSKINICTXB = 
#if defined(USE_TSKINICTXB)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_sizeof_ID = sizeof(ID);
const unsigned_t TOPPERS_cfg_sizeof_uint_t = sizeof(uint_t);
const unsigned_t TOPPERS_cfg_sizeof_SIZE = sizeof(SIZE);
const unsigned_t TOPPERS_cfg_sizeof_ATR = sizeof(ATR);
const unsigned_t TOPPERS_cfg_sizeof_PRI = sizeof(PRI);
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_VP = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = sizeof(intptr_t);
const unsigned_t TOPPERS_cfg_sizeof_FP = sizeof(FP);
const unsigned_t TOPPERS_cfg_sizeof_TINIB = sizeof(TINIB);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = offsetof(TINIB,tskatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = offsetof(TINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = offsetof(TINIB,task);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = offsetof(TINIB,ipriority);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = 
#if !defined(USE_TSKINICTXB)
(offsetof(TINIB,stksz));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = 
#if !defined(USE_TSKINICTXB)
(offsetof(TINIB,stk));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texatr = offsetof(TINIB,texatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texrtn = offsetof(TINIB,texrtn);
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = sizeof(SEMINIB);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = offsetof(SEMINIB,sematr);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = offsetof(SEMINIB,isemcnt);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = offsetof(SEMINIB,maxsem);
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = sizeof(FLGPTN);
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = sizeof(FLGINIB);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = offsetof(FLGINIB,flgatr);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = offsetof(FLGINIB,iflgptn);
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = sizeof(DTQINIB);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = offsetof(DTQINIB,dtqatr);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = offsetof(DTQINIB,dtqcnt);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = offsetof(DTQINIB,p_dtqmb);
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = sizeof(PDQINIB);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = offsetof(PDQINIB,pdqatr);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = offsetof(PDQINIB,pdqcnt);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = offsetof(PDQINIB,maxdpri);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = offsetof(PDQINIB,p_pdqmb);
const unsigned_t TOPPERS_cfg_sizeof_MBXINIB = sizeof(MBXINIB);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_mbxatr = offsetof(MBXINIB,mbxatr);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_maxmpri = offsetof(MBXINIB,maxmpri);
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = sizeof(MPFINIB);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = offsetof(MPFINIB,mpfatr);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = offsetof(MPFINIB,blkcnt);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = offsetof(MPFINIB,blksz);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = offsetof(MPFINIB,mpf);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = offsetof(MPFINIB,p_mpfmb);
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = sizeof(CYCINIB);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = offsetof(CYCINIB,cycatr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = offsetof(CYCINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cychdr = offsetof(CYCINIB,cychdr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = offsetof(CYCINIB,cyctim);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = offsetof(CYCINIB,cycphs);
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = sizeof(ALMINIB);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = offsetof(ALMINIB,almatr);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = offsetof(ALMINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almhdr = offsetof(ALMINIB,almhdr);
const unsigned_t TOPPERS_cfg_sizeof_INHNO = sizeof(INHNO);
const unsigned_t TOPPERS_cfg_sizeof_INTNO = sizeof(INTNO);
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = sizeof(EXCNO);
const unsigned_t TOPPERS_cfg_TA_LOWLEVEL = TA_LOWLEVEL;
const unsigned_t TOPPERS_cfg_TA_BOTHEDGE = TA_BOTHEDGE;
const unsigned_t TOPPERS_cfg_TA_NEGEDGE = TA_NEGEDGE;
const signed_t TOPPERS_cfg_TIPM_LOCK = TIPM_LOCK;
const unsigned_t TOPPERS_cfg_IPL_LOCK = IPL_LOCK;
const unsigned_t TOPPERS_cfg_PSW_I_MASK = PSW_I_MASK;
const unsigned_t TOPPERS_cfg_PSW_IPL_MASK = PSW_IPL_MASK;
const unsigned_t TOPPERS_cfg_EXC_GET_PSW_OFFSET = EXC_GET_PSW_OFFSET;
const unsigned_t TOPPERS_cfg_LOG_DSP_ENTER = LOG_DSP_ENTER;
const unsigned_t TOPPERS_cfg_LOG_DSP_LEAVE = LOG_DSP_LEAVE;
const unsigned_t TOPPERS_cfg_LOG_INH_ENTER = LOG_INH_ENTER;
const unsigned_t TOPPERS_cfg_LOG_INH_LEAVE = LOG_INH_LEAVE;
const unsigned_t TOPPERS_cfg_LOG_EXC_ENTER = LOG_EXC_ENTER;
const unsigned_t TOPPERS_cfg_LOG_EXC_LEAVE = LOG_EXC_LEAVE;
const unsigned_t TOPPERS_cfg_SIL_DLY_TIM1 = SIL_DLY_TIM1;
const unsigned_t TOPPERS_cfg_SIL_DLY_TIM2 = SIL_DLY_TIM2;


/* #include "target_timer.h" */

#line 6 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_0 = 0;
const unsigned_t TOPPERS_cfg_valueof_iniatr_0 = ( TA_NULL ); 
#line 7 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
const unsigned_t TOPPERS_cfg_valueof_teratr_1 = ( TA_NULL ); 
#line 8 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
const unsigned_t TOPPERS_cfg_valueof_inhno_2 = ( INHNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_inhatr_2 = ( TA_NULL ); 
#line 9 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
const unsigned_t TOPPERS_cfg_valueof_intno_3 = ( INTNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_intatr_3 = ( INTATR_TIMER ); const signed_t TOPPERS_cfg_valueof_intpri_3 = ( INTPRI_TIMER ); /* #include "syssvc/syslog.h" */

#line 10 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/syslog.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
const unsigned_t TOPPERS_cfg_valueof_iniatr_4 = ( TA_NULL ); /* #include "syssvc/banner.h" */

#line 10 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/banner.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
const unsigned_t TOPPERS_cfg_valueof_iniatr_5 = ( TA_NULL ); /* #include "target_syssvc.h" */
/* #include <target_gpio.h> */

#line 7 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
const unsigned_t TOPPERS_cfg_valueof_iniatr_6 = ( TA_NULL ); 
#line 9 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
const unsigned_t TOPPERS_cfg_valueof_intno_7 = ( INTNO_GIO_IRQ2 ); const unsigned_t TOPPERS_cfg_valueof_intatr_7 = ( INTATR_GIO ); const signed_t TOPPERS_cfg_valueof_intpri_7 = ( INTPRI_GIO ); 
#line 10 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
const unsigned_t TOPPERS_cfg_valueof_intno_8 = ( INTNO_GIO_NMI ); const unsigned_t TOPPERS_cfg_valueof_intatr_8 = ( INTATR_GIO ); const signed_t TOPPERS_cfg_valueof_intpri_8 = ( INTPRI_GIO ); 
#line 11 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
const unsigned_t TOPPERS_cfg_valueof_intno_9 = ( INTNO_GIO_RESET ); const unsigned_t TOPPERS_cfg_valueof_intatr_9 = ( INTATR_GIO ); const signed_t TOPPERS_cfg_valueof_intpri_9 = ( INTPRI_GIO ); 
#line 13 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
const unsigned_t TOPPERS_cfg_valueof_isratr_10 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_10 = ( INTNO_GIO_IRQ2 ); const signed_t TOPPERS_cfg_valueof_isrpri_10 = ( 1 ); 
#line 14 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
const unsigned_t TOPPERS_cfg_valueof_isratr_11 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_11 = ( INTNO_GIO_NMI ); const signed_t TOPPERS_cfg_valueof_isrpri_11 = ( 1 ); 
#line 15 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
const unsigned_t TOPPERS_cfg_valueof_isratr_12 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_12 = ( INTNO_GIO_RESET ); const signed_t TOPPERS_cfg_valueof_isrpri_12 = ( 1 ); /* #include "syssvc/gpio.h" */

#line 13 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/gpio.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
const unsigned_t TOPPERS_cfg_valueof_iniatr_13 = ( TA_NULL ); /* #include "target_syssvc.h" */
/* #include <target_adc.h> */

#line 7 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_adc.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
const unsigned_t TOPPERS_cfg_valueof_iniatr_14 = ( TA_NULL ); 
#line 9 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_adc.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
const unsigned_t TOPPERS_cfg_valueof_intno_15 = ( INTNO_AIO_ADI0 ); const unsigned_t TOPPERS_cfg_valueof_intatr_15 = ( INTATR_AIO ); const signed_t TOPPERS_cfg_valueof_intpri_15 = ( INTPRI_AIO ); 
#line 11 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_adc.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
const unsigned_t TOPPERS_cfg_valueof_isratr_16 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_16 = ( INTNO_AIO_ADI0 ); const signed_t TOPPERS_cfg_valueof_isrpri_16 = ( 1 ); /* #include "syssvc/adc.h" */

#line 13 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/adc.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
const unsigned_t TOPPERS_cfg_valueof_iniatr_17 = ( TA_NULL ); /* #include "target_syssvc.h" */
/* #include <target_pwm.h> */

#line 7 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_pwm.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
const unsigned_t TOPPERS_cfg_valueof_iniatr_18 = ( TA_NULL ); /* #include "syssvc/pwm.h" */

#line 13 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/pwm.cfg"
const unsigned_t TOPPERS_cfg_static_api_19 = 19;
const unsigned_t TOPPERS_cfg_valueof_iniatr_19 = ( TA_NULL ); /* #include "target_syssvc.h" */
/* #include <target_serial.h> */

#line 6 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_20 = 20;
const unsigned_t TOPPERS_cfg_valueof_iniatr_20 = ( TA_NULL ); 
#line 7 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_21 = 21;
const unsigned_t TOPPERS_cfg_valueof_intno_21 = ( INTNO_SIO_TX ); const unsigned_t TOPPERS_cfg_valueof_intatr_21 = ( INTATR_SIO ); const signed_t TOPPERS_cfg_valueof_intpri_21 = ( INTPRI_SIO ); 
#line 8 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_22 = 22;
const unsigned_t TOPPERS_cfg_valueof_intno_22 = ( INTNO_SIO_RX ); const unsigned_t TOPPERS_cfg_valueof_intatr_22 = ( INTATR_SIO ); const signed_t TOPPERS_cfg_valueof_intpri_22 = ( INTPRI_SIO ); 
#line 10 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_23 = 23;
const unsigned_t TOPPERS_cfg_valueof_isratr_23 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_23 = ( INTNO_SIO_TX ); const signed_t TOPPERS_cfg_valueof_isrpri_23 = ( 1 ); 
#line 11 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../target/kiss_rx62t/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_24 = 24;
const unsigned_t TOPPERS_cfg_valueof_isratr_24 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_24 = ( INTNO_SIO_RX ); const signed_t TOPPERS_cfg_valueof_isrpri_24 = ( 1 ); /* #include "syssvc/serial.h" */

#line 13 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_25 = 25;
const unsigned_t TOPPERS_cfg_valueof_iniatr_25 = ( TA_NULL ); 
#line 15 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_26 = 26;
#define SERIAL_RCV_SEM1	(<>)

#line 15 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_26 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_26 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_26 = ( 1 ); 
#line 16 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_27 = 27;
#define SERIAL_SND_SEM1	(<>)

#line 16 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_27 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_27 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_27 = ( 1 ); 
#if TNUM_PORT >= 2

#line 18 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_28 = 28;
#define SERIAL_RCV_SEM2	(<>)

#line 18 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_28 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_28 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_28 = ( 1 ); 
#line 19 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_29 = 29;
#define SERIAL_SND_SEM2	(<>)

#line 19 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_29 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_29 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_29 = ( 1 ); 
#endif 

#if TNUM_PORT >= 3

#line 22 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_30 = 30;
#define SERIAL_RCV_SEM3	(<>)

#line 22 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_30 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_30 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_30 = ( 1 ); 
#line 23 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_31 = 31;
#define SERIAL_SND_SEM3	(<>)

#line 23 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_31 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_31 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_31 = ( 1 ); 
#endif 
/* #include "syssvc/logtask.h" */

#line 10 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_32 = 32;
#define LOGTASK	(<>)

#line 10 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_32 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_32 = ( LOGTASK_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_32 = ( LOGTASK_STACK_SIZE ); 
#line 12 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_33 = 33;
const unsigned_t TOPPERS_cfg_valueof_teratr_33 = ( TA_NULL ); /* #include "sample1.h" */

#line 18 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../sample/sample1.cfg"
const unsigned_t TOPPERS_cfg_static_api_34 = 34;
#define TASK1	(<>)

#line 18 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../sample/sample1.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_34 = ( TA_NULL ); const signed_t TOPPERS_cfg_valueof_itskpri_34 = ( MID_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_34 = ( STACK_SIZE ); 
#line 19 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../sample/sample1.cfg"
const unsigned_t TOPPERS_cfg_static_api_35 = 35;
#define MAIN_TASK	(<>)

#line 19 "C:/cygwin/home/jedsada/01_utkernel/Workshop/01_Template/Workshop6/01_PIDs_Control_RTOS/asp/target/kiss_rx62t/sample_workspace/../../../sample/sample1.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_35 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_35 = ( MAIN_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_35 = ( STACK_SIZE ); 
