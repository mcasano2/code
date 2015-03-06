/* 
 * File:   timers.h
 * Author: kyle
 *
 * Created on October 30, 2013, 2:03 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

#include <p33Fxxxx.h>
#include <libpic30.h>
#include "types.h"

#define TICKS(x) x * 200

#define WITH_INT 1
#define NO_INT 0

void timer1_setup(uint8_t ms, uint8_t interrupt);
void timer2_setup(uint8_t ms, uint8_t interrupt);


#endif	/* TIMERS_H */

