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
uint16_t ms;
uint8_t sec;
uint8_t min;
//uint16_t looptime;

int main(){
	//Init LCD
	__C30_UART=1;	
	lcd_initialize();
	led_initialize();
	lcd_clear();
	
	//Set pin for digital I/O
	AD1PCFGHbits.PCFG20 = 1;

	/* Timer 2 */
	T2CONbits.TON = 0;
	T2CONbits.TCS = 0;
	T2CONbits.TGATE = 0;
	IPC1bits.T2IP = 0x01;
	IFS0bits.T2IF = 0;
	IEC0bits.T2IE = 1;
	T2CONbits.TCKPS = 0b11;
	PR2 = 100;			        //Period of 50 is 1ms
	T2CONbits.TON = 1;

	/* Timer 1 */
	__builtin_write_OSCCONL(OSCCONL | 2);
	T1CONbits.TON = 0;
	T1CONbits.TCS = 1;
	T1CONbits.TSYNC = 0;
	IPC0bits.T1IP = 0x01;
	IFS0bits.T1IF = 0;
	IEC0bits.T1IE = 1;
	T1CONbits.TCKPS = 0b00;
	TMR1 = 0x00;
	PR1 = 32767;
	T1CONbits.TON = 1;

	/* Trigger  */
	IPC5bits.INT1IP = 0x01;
	IFS1bits.INT1IF = 0;
	IEC1bits.INT1IE = 1;


	/* Timer 3 */
	T3CONbits.TON = 0;
	T3CONbits.TCS = 0;
	T3CONbits.TGATE = 0;
	IPC2bits.T3IP = 0x01;
	IFS0bits.T3IF = 0;
	IEC0bits.T3IE = 1;
	T3CONbits.TCKPS = 0b00;
	//Period of 12800 is 1ms
	PR3=0xFFFF;    //Ideally never fire an interrupt. We'll manually reset the timer.
	TMR3 = 0x0000;
	T3CONbits.TON = 1;

	uint16_t timer3;
	uint16_t count = 0;
	while(1){

		LED4_PORT^=1;
		count++;	
		if(count == 2000)
		{
			lcd_locate(0,0);
			lcd_printf("%02u:%02u.%03u", min, sec, ms);
			lcd_locate(0,1);
			lcd_printf("TMR3 Count: %-10u", timer3);
			lcd_locate(0,2);
			lcd_printf("Loop ms: %.4f", ((float)timer3)/((float)12800));
			count = 0;
			timer3 = TMR3;
		}
		TMR3 = 0x0000;
	}
	return 0;
}

void __attribute__((__interrupt__)) _T2Interrupt(void) {
	LED1_PORT^=1;
	IFS0bits.T2IF = 0;
	ms+=2;
	if(ms == 1000)
	{
		ms = 0;
		sec++;
		if(sec == 60)
		{
			sec = 0;
			min++;
		}
	}
}

void __attribute__((__interrupt__)) _T1Interrupt(void) {
	LED2_PORT^=1;
	IFS0bits.T1IF = 0;
}

void __attribute__((__interrupt__)) _T3Interrupt(void) {
	//looptime += 11 ;
	IFS0bits.T3IF = 0;
}

void __attribute__((__interrupt__)) _INT1Interrupt(void) {
	IFS1bits.INT1IF = 0;
	uint32_t * timer = &ms;
	(*timer) = 0;
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
