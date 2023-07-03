#include <stdio.h>
#include "xtimer.h"

#define RELAY_PIN GPIO_PIN(0,21)

int main(void)
{
    xtimer_sleep(3);

    puts("Hello World!");
    gpio_init(RELAY_PIN, GPIO_OUT);
    gpio_set(RELAY_PIN);

    return 0;
    
    while(1) {
        gpio_clear(RELAY_PIN);
        printf("OFF\n");
        xtimer_sleep(2);
        gpio_set(RELAY_PIN);
        printf("ON\n");
        xtimer_sleep(2);

    }

    return 0;
}
