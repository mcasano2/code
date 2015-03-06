#include    "PWM.h"

void PWM_setup()
{
    CLEARBIT(TRISDbits.TRISD7);
    OC8CON = 0x0006;
    OC7CON = 0x0006;
}

void PWM_set_x_cycle(uint16_t clocks)
{
    OC8R = clocks;
    OC8RS = clocks;
}

void PWM_set_y_cycle(uint16_t clocks)
{
    OC7R = clocks;
    OC7RS = clocks;
}

uint16_t time_to_inverted_clocks(float ms, int period_ms)
{
    int ticks_per_ms = TICKS(1);
    int our_ticks = ms * ticks_per_ms;
    return TICKS(period_ms) - our_ticks;
}

void motor_set_duty(uint8_t chan, uint16_t duty_us)
{
    switch(chan) {
        case MOTOR_X_CHAN:
            PWM_set_x_cycle(time_to_inverted_clocks(((float)duty_us)/1000, TIMER_PERIOD));
            break;
        case MOTOR_Y_CHAN:
            PWM_set_y_cycle(time_to_inverted_clocks(((float)duty_us)/1000, TIMER_PERIOD));
            break;
    }
}