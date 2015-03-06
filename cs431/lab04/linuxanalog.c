#include "linuxanalog.h"

void das1602_initialize()
{
	uint16_t init = 0x0067;
	uint16_t zero = 0x0000;

	outw(init, BADR1+8);
	outw(zero, BADR4+2);
}

void dac(uint16_t value)
{
    // MAYBE MASK?
    outw(value, BADR4);
}

uint16_t voltage_to_uint12(double voltage)
{
    uint16_t IntsPerVolt = (pow(2,12) / 10);
    return (voltage + 5) * IntsPerVolt;
}
