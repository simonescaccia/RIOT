/**
 * Define the PWM pins in boards/esp32s3-devkit/include/periph_conf.h
 * define PWM0_GPIOS  { GPIO19, GPIO20, GPIO21 } 
 * stands for PWM_DEV0
 * Channel 0: GPIO19, Channel 1: GPIO20, Channel 2: GPIO21
 * 
 * For servo 0°-90°, use:
 * #define SERVO_MIN   (1000U)
 * #define SERVO_MAX   (2000U)
 * 
 * For servo 0°-180°, use:
 * #define SERVO_MIN   (500U)
 * #define SERVO_MAX   (2500U)
 * 
 * 
*/

#include <stdio.h>

// servo
#include "servo.h"
#include "xtimer.h"

// servo
#define POS0 0
#define POS1 UINT8_MAX

#define SERVO_PWM_PARAM_RES 256
#define SERVO_PWM_PARAM_FREQ 100
#define SERVO_PWM_PARAM_CHAN 0
#define SERVO_PWM_PARAM_DEV PWM_DEV(0)
#define SERVO_PARAM_MIN_US 1000UL
#define SERVO_PARAM_MAX_US 2000UL

servo_t servo;
servo_pwm_params_t my_servo_pwm_params = {
    .pwm = SERVO_PWM_PARAM_DEV,
    .freq = SERVO_PWM_PARAM_FREQ,
    .res = SERVO_PWM_PARAM_RES
};

servo_params_t my_servo_params = {
    .pwm = &my_servo_pwm_params, 
    .pwm_chan = SERVO_PWM_PARAM_CHAN,
    .min_us = SERVO_PARAM_MIN_US,
    .max_us = SERVO_PARAM_MAX_US
};

int main(void)
{
    if (servo_init(&servo, &my_servo_params)) {
        printf("Error to initialize servo");
        return -1;
    } else {
        printf("Servo init ok\n");
    }

    while(1) {
        printf("Servo set\n");
        servo_set(&servo, POS0);
        xtimer_sleep(1);
        printf("Servo set2\n");
        servo_set(&servo, POS1);
        xtimer_sleep(1);
    }

    return 0;
}
