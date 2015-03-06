#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL 
#include <stdlib.h>
#include <stdio.h>
#include <libpic30.h>
#include <string.h>
#include "types.h"

#include "lab03.h"
#include "lcd.h"
#include "led.h"
#include "flexserial.h"
#include "crc16.h"

/* Initial configuration by EE */
// Primary (XT, HS, EC) Oscillator with PLL
_FOSCSEL(FNOSC_PRIPLL);

// OSC2 Pin Function: OSC2 is Clock Output - Primary Oscillator Mode: XT Crystal
_FOSC(OSCIOFNC_OFF & POSCMD_XT); 

// Watchdog Timer Enabled/disabled by user software
_FWDT(FWDTEN_OFF);

// Disable Code Protection
_FGS(GCP_OFF); 

typedef struct __attribute__((__packed__)) tpacket {
  char startbyte;
  uint16_t crc;
  char length;
} tpacket;

int failedTimes = 0;
uint8_t messageHdr[4];
uint8_t message[MSG_MAX_LEN];
uint16_t crc;
uint16_t lastCRC = 0;
uint16_t failCount = 0;
uint8_t shouldGetByte;


void receiveMsg();
void updateScreen();

uint8_t getByte();

uint16_t ntohs(uint16_t netorder);

void resetTimer();

int main(){


	//Init LCD
	__C30_UART=1;	
	lcd_initialize();
	led_initialize();
	lcd_clear();

	uart2_init(9600);

	updateScreen();			
	U2STAbits.OERR = 0;
	while (1)
	{
		receiveMsg();
		updateScreen();
	}	

	return 0;
}

uint8_t getByte()
{
	uint8_t currentByte;
    while (!uart2_getc(&currentByte) && shouldGetByte) {}	
	return currentByte;
}

void receiveMsg()
{
	shouldGetByte = 1;
	crc = 0x0000;
 	memset(message, 0, MSG_MAX_LEN);
	uint8_t header[4];
	tpacket * structured_header = header;
	
	header[0] = getByte();
	resetTimer();	

	int i;
	for(i = 1; i < 4; i++)
	{
		header[i] = getByte();
	}

	uint16_t remotecrc = ntohs(structured_header->crc);
	lcd_printf("%X\r\n", remotecrc);

	for(i = 0; i < structured_header->length; i++)
	{
		message[i] = getByte();
		crc = crc_update(crc, message[i]);		
	}
	
	if(!T2CONbits.TON)
	{
		if(remotecrc == lastCRC)
			failCount++;
		else
			failCount = 0;
		memset(message, 0, MSG_MAX_LEN);
		crc = 0x0000;
	}	

	lastCRC = remotecrc;
	printf("%X : %X", crc, remotecrc);
	if( crc != remotecrc || crc == 0)
		uart2_putc(MSG_NACK);
	else
		uart2_putc(MSG_ACK);

	T2CONbits.TON = 0;		

}	


uint16_t ntohs(uint16_t netorder)
{
	uint16_t newbyte = (netorder << 8);
	newbyte |= ((netorder >> 8) & 0x00FF);
	return newbyte;
}

void updateScreen()
{
	return;
	lcd_clear();
	lcd_printf("---Lab03---\r\n");
	lcd_printf("CRC: %X\r\n", crc);
	lcd_printf("Msg: %s\r\n", message);
}

void resetTimer()
{
	/* Timer 2 */
	T2CONbits.TON = 0;
	T2CONbits.TCS = 0;
	T2CONbits.TGATE = 0;
	IPC1bits.T2IP = 0x01;
	IFS0bits.T2IF = 0;
	IEC0bits.T2IE = 1;
	T2CONbits.TCKPS = 0b11;
	PR2 = 50000;		        //Period of 50 is 1ms
	T2CONbits.TON = 1;	
}

void __attribute__((__interrupt__)) _T2Interrupt(void) {
	//LED1_PORT^=1;
	T2CONbits.TON = 0;
	shouldGetByte = 0;
	IFS0bits.T2IF = 0;
}