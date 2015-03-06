#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL
#include <libpic30.h>
#include "cpu.h"

#define CLEARBIT(BIT)		(BIT = 0)
#define SETBIT(BIT)		(BIT = 1)

#define X 0
#define Y 1

void touch_init();
void touch_select_dim(CPU_INT08U dim);
void touch_select_dim_nodelay(CPU_INT08U dim);
CPU_INT16U touch_adc();

void setup_ADC2();
CPU_INT16U AD2_read_x();
CPU_INT16U AD2_read_y();