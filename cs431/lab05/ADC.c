#include "ADC.h"

void setup_ADC()
{
    CLEARBIT(AD2CON1bits.ADON);
    SETBIT(TRISEbits.TRISE8);
    SETBIT(AD2PCFGLbits.PCFG4);
    SETBIT(AD2PCFGLbits.PCFG5);
    CLEARBIT(AD2CON1bits.AD12B);
    AD2CON1bits.FORM = 0;
    AD2CON1bits.SSRC = 0x7;
    AD2CON2 = 0;
    CLEARBIT(AD2CON3bits.ADRC);
    AD2CON3bits.SAMC = 0x1F;
    AD2CON3bits.ADCS = 0x02;
    SETBIT(AD2CON1bits.ADON);

}

uint16_t AD2_read_x()
{
    AD2CHS0bits.CH0SA = 0x04;
    SETBIT(AD2CON1bits.SAMP);
    while (!AD2CON1bits.DONE);
    CLEARBIT(AD2CON1bits.DONE);

    return ADC2BUF0;
}

uint16_t AD2_read_y()
{
    AD2CHS0bits.CH0SA = 0x05;
    SETBIT(AD2CON1bits.SAMP);
    while (!AD2CON1bits.DONE);
    CLEARBIT(AD2CON1bits.DONE);
    
    return ADC2BUF0;
}