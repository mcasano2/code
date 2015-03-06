#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL
#include <libpic30.h>
#include "types.h"

#define X 0
#define Y 1

void touch_init();
void touch_select_dim(uint8_t dim);
void touch_select_dim_nodelay(uint8_t dim);
uint16_t touch_adc();

void setup_ADC2();
uint16_t AD2_read_x();
uint16_t AD2_read_y();