#include <stdio.h>
#include "periph/adc.h"
#include "periph/gpio.h"
#include "analog_util.h"
#include "xtimer.h"

#define ADC_IN_USE  ADC_LINE(0)
#define ADC_RES     ADC_RES_12BIT

#define DELAY       (1LU * US_PER_SEC)

int main(void)
{
    puts("Hello World!");

    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    if (adc_init(ADC_IN_USE) < 0) {
        printf("Failed to initialize ADC");
        return 1;
    } else {
        printf("ADC OK");
    }

    xtimer_ticks32_t last = xtimer_now();
    int sample = 0;
    int lux = 0;

    while (1) {
        sample = adc_sample(ADC_IN_USE, ADC_RES);
        lux = adc_util_map(sample, ADC_RES, 10, 100);
        printf("Raw value %i \t LUX: %i \n", sample, lux
        );

        xtimer_periodic_wakeup(&last, DELAY);
    }

    return 0;
}
