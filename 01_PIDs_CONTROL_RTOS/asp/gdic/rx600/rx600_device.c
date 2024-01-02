/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 */

/*
 *  RX610 device driver
 */

#include <sil.h>
#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "rx600_device.h"

void print_bit(int32_t val)
{
    int32_t i = 0;
    int32_t idx = 0;
    int32_t mask = 0;
    for (i = 31; i >= 0; i--)
    {
        mask = 1 << i;
        (val & mask) == 0 ? (*target_fput_log)('0') : (*target_fput_log)('1');

        idx++;
        if (idx == 4)
        {
            (*target_fput_log)(' ');
            idx = 0;
        }
    }
    (*target_fput_log)('\n');
}

