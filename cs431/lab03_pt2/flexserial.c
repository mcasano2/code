#include "flexserial.h"


void uart2_init(uint16_t baud)
{
	CLEARBIT(U2MODEbits.UARTEN);


	// Disable Interrupts
	IEC1bits.U2RXIE = 0;
	IEC1bits.U2TXIE = 0;

	// Clear Interrupts.
	IFS1bits.U2RXIF = 0;
	IFS1bits.U2TXIF = 0;

	TRISFbits.TRISF2 = 1;
	TRISFbits.TRISF3 = 0;

	// Set Baud Rate.
	U2MODEbits.BRGH = 0;
	U2BRG = (uint32_t)800000 / baud - 1;

	// Operation settings and start port
	U2MODE = 0;				//8-bit, no parity, 1 stop bit.
	U2MODEbits.RTSMD = 0; 	//simplex mode
	U2MODEbits.UEN = 0;		//simplex mode
	U2MODE |= 0x00;

	//Enable UART2
	U2MODEbits.UARTEN = 1;
	U2STA = 0;
	U2STAbits.UTXEN = 1;	//Enable Transmission on UART2 TX	
}

void uart2_putc(uint8_t c)
{
	while(U2STAbits.UTXBF);
	U2TXREG = c;
	while(!U2STAbits.TRMT);
}

int8_t uart2_getc(uint8_t * data) 
{
	char ReceivedChar;
	/* check for receive errors 
	if(U2STAbits.FERR == 1)
	{
		U2
		return -1;
	}*/
	
	/* get the data */
	if(U2STAbits.URXDA == 1)
	{
		ReceivedChar = U2RXREG & 0x00FF;
		*data = ReceivedChar;
		return 1;
	}

	/* must clear the overrun error to keep uart receiving */
	if(U2STAbits.OERR == 1)
	{
		U2STAbits.OERR = 0;
		return 1;
	}

	return 0;
}



