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
    //rt_pm_module_delay_sleep(PM_POWER_ID, 2000);

    // LED
    rt_pin_mode(BSP_LED1_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(BSP_LED2_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(BSP_LED3_PIN, PIN_MODE_OUTPUT);

    rt_pin_write(BSP_LED1_PIN, PIN_HIGH);
    rt_pin_write(BSP_LED2_PIN, PIN_HIGH);
    rt_pin_write(BSP_LED3_PIN, PIN_HIGH);

    // KEY
    rt_pin_mode(BSP_KEY1_PIN, PIN_MODE_INPUT);
    rt_pin_mode(BSP_KEY2_PIN, PIN_MODE_INPUT);
    rt_pin_mode(BSP_KEY3_PIN, PIN_MODE_INPUT);

    // BEEP
    rt_pin_mode(BSP_BEEP_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(BSP_BEEP_PIN, PIN_LOW);

    LOG_D("Hello RT-Thread!");

#ifdef RT_USING_PM
    rt_pm_module_release(PM_POWER_ID, RT_PM_DEFAULT_SLEEP_MODE);
#endif

    return RT_EOK;
}
