#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL
#include <libpic30.h>
#include "types.h"

void setup_ADC();
uint16_t AD2_read_x();
uint16_t AD2_read_y();