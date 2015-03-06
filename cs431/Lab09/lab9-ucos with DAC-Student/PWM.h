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
//#include "types.h"
#include "lcd.h"
#include <includes.h>
#include "timers.h"

#define CLEARBIT(BIT)		(BIT = 0)
#define SETBIT(BIT)		(BIT = 1)

void PWM_setup();
void PWM_set_x_cycle(CPU_INT16U clocks);
void PWM_set_y_cycle(CPU_INT16U clocks);

//ms is the duration of the pulse, period_ms is the period of the timer.
CPU_INT16U time_to_inverted_clocks(float ms, int period_ms);

#endif	/* PWM_H */

