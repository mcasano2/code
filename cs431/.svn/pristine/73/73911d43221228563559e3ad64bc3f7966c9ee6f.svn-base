#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL 
#include <stdio.h>
#include <libpic30.h>
#include "types.h"

#include "lcd.h"
#include "led.h"

/* Initial configuration by EE */
// Primary (XT, HS, EC) Oscillator with PLL
_FOSCSEL(FNOSC_PRIPLL);

// OSC2 Pin Function: OSC2 is Clock Output - Primary Oscillator Mode: XT Crystal
_FOSC(OSCIOFNC_OFF & POSCMD_XT); 

// Watchdog Timer Enabled/disabled by user software
_FWDT(FWDTEN_OFF);

// Disable Code Protection
_FGS(GCP_OFF);  

uint8_t debounced(uint16_t port, uint8_t * bool_buffer, uint8_t status);

void main(){
	//Init LCD
	__C30_UART=1;	
	lcd_initialize();
	led_initialize();
	lcd_clear();
	
	lcd_locate(0,0);
	lcd_printf("CS 431 Lab #1 group04\rKyle Nusbaum\rAlex Hendrix\rMark Casanova\r\rTrigger press count:\r");

	//Set pin for digital I/O
	AD1PCFGHbits.PCFG20 = 1;

	uint8_t button1_status = 0;
	uint8_t button1_buffer = 0;

	uint8_t button2_status = 0;
	uint8_t button2_buffer = 0;

	uint16_t steps = 0;
	uint8_t click_count = 0;

	lcd_locate(0,7);
	lcd_printf("0");
	while(1){
		uint8_t newstatus1 = debounced(PORTEbits.RE8,&button1_buffer, button1_status);
		uint8_t newstatus2 = debounced(PORTDbits.RD10,&button2_buffer, button2_status);
	
		if(newstatus1 != button1_status)
		{
			LED1_PORT = newstatus1;
			button1_status = newstatus1;
			if(newstatus1)
			{
				lcd_locate(0,7);
				lcd_printf("%u",++click_count);
			}
		}
		if(newstatus2 != button2_status)
		{
			LED2_PORT = newstatus2;
			button2_status = newstatus2;
		}

		LED3_PORT = (button1_status != button2_status);
		
		
				

		if(steps++ == 50000)
		{
			steps = 0;
			LED4_PORT^=1;
		}
	}
}

/* If port is 0, status is 1.*/
uint8_t debounced(uint16_t port, uint8_t * bool_buffer, uint8_t status)
{
	(*bool_buffer) = ((*bool_buffer) << 1) | (port == 0);
	
	if(*bool_buffer == 0xFF)
		return 1;
	if(*bool_buffer == 0x00)
		return 0;
	return status;

}
