/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-04-22     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

int main(void)
{
    int count = 1;

    rt_pin_mode(BSP_LED1_PIN, PIN_MODE_OUTPUT);
    LOG_D("Hello RT-Thread!");

    while (count++)
    {
        rt_thread_mdelay(500);
        rt_pin_write(BSP_LED1_PIN, PIN_LOW);
        rt_thread_mdelay(500);
        rt_pin_write(BSP_LED1_PIN, PIN_HIGH);
    }

    return RT_EOK;
}
