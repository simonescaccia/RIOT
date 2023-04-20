#include <stdio.h>
#include <periph/adc.h>
#include <periph/gpio.h>
#include "analog_util.h"
#include "xtimer.h"
#include "led.h"
#include "periph/gpio.h"

#define DELAY (1LU * US_PER_SEC)

// GPIO that works:
// 0,36,35,34,33,47,48,21,20,19,37,46,45,42,41,40,39,38,1,2,3,4,5,6,7
// 44,43 UARTS
// 26 N/A signal

int main(void)
{
    
    int pins[] = {37,46,45,42,41,40,39,38,1,2,3,4,5,6,7,0,36,35,34,33,47,48,21,20,19};
    int n = sizeof(pins)/sizeof(pins[0]);
    gpio_t gpios[n];

    xtimer_sleep(3);

    for (int i = 0; i < n; i++ ) {
        gpios[i] = GPIO_PIN(0, pins[i]);
    }

    for (int i = 0; i < n; i++ ) {
        printf("pin: %d, gpio_init %d\n", pins[i], gpio_init(gpios[i], GPIO_OUT));
    }

    xtimer_ticks32_t last = xtimer_now();

    while(1) {
        for (int i = 0; i < n; i++ ) {
            gpio_clear(gpios[i]);
        }

        // xtimer_periodic_wakeup(&last, DELAY);
        xtimer_periodic_wakeup(&last, DELAY);

        for (int i = 0; i < n; i++ ) {
            gpio_set(gpios[i]);
        }

        xtimer_periodic_wakeup(&last, DELAY);
    }

    return 0;
}
