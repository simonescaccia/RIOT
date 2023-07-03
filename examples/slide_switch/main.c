#include <stdio.h>
#include "xtimer.h"

#define SLIDE_PIN GPIO_PIN(0,48)

int main(void)
{
    xtimer_sleep(3);

    puts("Hello World!");
    gpio_init(SLIDE_PIN, GPIO_IN);

    while(1) {
        bool slide = gpio_read(SLIDE_PIN);
        printf("Slide switch: %d\n", slide);
        xtimer_sleep(1);
    }

    return 0;
}
