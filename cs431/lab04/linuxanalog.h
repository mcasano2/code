#ifndef _LINUXANALOG_H
#define _LINUXANALOG_H

#include <math.h>
#include "sys/io.h"
#include "inttypes.h"

#define BADR0 0xCCC0
#define BADR1 0xCC40
#define BADR2 0xCC60
#define BADR3 0xCC80
#define BADR4 0xCCA0

void das1602_initialize();
void dac(uint16_t value);
uint16_t voltage_to_uint12(double voltage);

#endif
