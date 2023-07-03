/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>

#include "xtimer.h"

gpio_t GPIO_SCK = GPIO_PIN(0, 2);
gpio_t GPIO_DT = GPIO_PIN(0, 1);

#define ZERO_LOAD_CELL 8498

long read_weight(void){ //load cell
    long val;
    val=0;
    for (int i=0; i<24; i++){
        gpio_set(GPIO_SCK);
        xtimer_usleep(20);
        val = val<<1;
        gpio_clear(GPIO_SCK);
        if (gpio_read(GPIO_DT)>0){
            val++;
        }
    }
    gpio_set(GPIO_SCK);
    xtimer_usleep(20);
    val = val ^ 0x800000;
    gpio_clear(GPIO_SCK);
    val=val/1000;
    if (val>ZERO_LOAD_CELL){
        val=ZERO_LOAD_CELL;
    }
    int grams = (ZERO_LOAD_CELL-val)/0.104;
    if (grams<=0) return 0;
    else return grams;
}

int main(void)
{

    long weight;

    xtimer_sleep(3);

    puts("Hello World!");

    gpio_init(GPIO_SCK, GPIO_OUT);
    gpio_init(GPIO_DT, GPIO_IN);

    while(true) {
        weight = read_weight();
        printf("Weight: %ld\n", weight);
        xtimer_sleep(1);
    }

    return 0;
}
