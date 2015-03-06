/* 
 * File:   PWM.h
 * Author: kyle
 *
 * Created on October 30, 2013, 2:26 PM
 */

#ifndef PWM_H
#define	PWM_H

#include <p33Fxxxx.h>
#include <libpic30.h>
#include "types.h"
#include "timers.h"
#include "lcd.h"

void PWM_setup();
void PWM_set_x_cycle(uint16_t clocks);
void PWM_set_y_cycle(uint16_t clocks);

//ms is the duration of the pulse, period_ms is the period of the timer.
uint16_t time_to_inverted_clocks(float ms, int period_ms);

#endif	/* PWM_H */

