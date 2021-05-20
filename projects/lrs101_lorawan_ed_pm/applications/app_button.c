/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-08     zhangsz      init first
 */
#include <rtthread.h>
#include <board.h>

#define DBG_ENABLE
#define DBG_SECTION_NAME    "key"
#define DBG_LEVEL           DBG_LOG
#include <rtdbg.h>

#define PIN_KEY0    BSP_KEY1_PIN
#define PIN_KEY1    BSP_KEY2_PIN
#define PIN_KEY2    BSP_KEY3_PIN

void key0_irq_callback(void *parameter)
{
    static uint8_t key0_status = 0x00;

    key0_status ^= 0x01;

    if(key0_status == 0x00)
        rt_pm_module_release(PM_BOARD_ID, PM_SLEEP_MODE_IDLE);
    else
        rt_pm_module_request(PM_BOARD_ID, PM_SLEEP_MODE_IDLE);

    LOG_D("[key0_irq]\n");
}

void key1_irq_callback(void *parameter)
{
    static uint8_t key1_status = 0x00;

    key1_status ^= 0x01;

    if(key1_status == 0x00)
        rt_pm_module_release(PM_BSP_ID, PM_SLEEP_MODE_LIGHT);
    else
        rt_pm_module_request(PM_BSP_ID, PM_SLEEP_MODE_LIGHT);

    LOG_D("[key1_irq]\n");
}

void key2_irq_callback(void *parameter)
{
    static uint8_t key2_status = 0x00;

    key2_status ^= 0x01;

    if(key2_status == 0x00)
        rt_pm_module_release(PM_LCD_ID, PM_SLEEP_MODE_NONE);
    else
        rt_pm_module_request(PM_LCD_ID, PM_SLEEP_MODE_NONE);

    LOG_D("[key2_irq]\n");
}

int key_gpio_init(void)
{
    LOG_D("key_gpio_init.\n");

    /* set key pin mode to input */
    LOG_D("PIN_KEY0=%d,PIN_KEY1=%d,PIN_KEY2=%d\n",
                PIN_KEY0,PIN_KEY1,PIN_KEY2);

    rt_pin_mode(PIN_KEY0, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(PIN_KEY1, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(PIN_KEY2, PIN_MODE_INPUT_PULLUP);

    /* set interrupt mode and attach interrupt callback function */
    rt_pin_attach_irq(PIN_KEY0, PIN_IRQ_MODE_FALLING, key0_irq_callback, NULL);
    rt_pin_attach_irq(PIN_KEY1, PIN_IRQ_MODE_FALLING, key1_irq_callback, NULL);
    rt_pin_attach_irq(PIN_KEY2, PIN_IRQ_MODE_FALLING, key2_irq_callback, NULL);

    /* enable interrupt */
    rt_pin_irq_enable(PIN_KEY0, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(PIN_KEY1, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(PIN_KEY2, PIN_IRQ_ENABLE);

    return RT_EOK;
}
INIT_BOARD_EXPORT(key_gpio_init);
