#include "ADC.h"
#include "cpu.h"

void setup_ADC2()
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

void touch_init()
{

    CLEARBIT(AD1CON1bits.ADON);
    SETBIT(TRISEbits.TRISE8);

    CLEARBIT(AD1PCFGLbits.PCFG15);
    CLEARBIT(AD1PCFGLbits.PCFG9);

    SETBIT(AD1CON1bits.AD12B);

    AD1CON1bits.FORM = 0;
    AD1CON1bits.SSRC = 0x7;
    AD1CON2 = 0;

    CLEARBIT(AD1CON3bits.ADRC);
    AD1CON3bits.SAMC = 0x1F;
    AD1CON3bits.ADCS = 0x02;
    SETBIT(AD1CON1bits.ADON);

    CLEARBIT(TRISEbits.TRISE1);
    CLEARBIT(TRISEbits.TRISE2);
    CLEARBIT(TRISEbits.TRISE3);


}

void touch_select_dim_nodelay(CPU_INT08U dim)
{
    if(dim == X)
    {
        CLEARBIT(LATEbits.LATE1);
        SETBIT(LATEbits.LATE2);
        SETBIT(LATEbits.LATE3);
        AD1CHS0bits.CH0SA = 0x0F;
    }
    else if(dim == Y)
    {
        SETBIT(LATEbits.LATE1);
        CLEARBIT(LATEbits.LATE2);
        CLEARBIT(LATEbits.LATE3);
        AD1CHS0bits.CH0SA = 0x09;
    }
}

void touch_select_dim(CPU_INT08U dim)
{
    touch_select_dim_nodelay(dim);
    __delay_ms(10);
}

CPU_INT16U touch_adc()
{
    SETBIT(AD1CON1bits.SAMP);
    while(!AD1CON1bits.DONE);
    CLEARBIT(AD1CON1bits.DONE);

    return ADC1BUF0;
}

CPU_INT16U AD2_read_x()
{
    AD2CHS0bits.CH0SA = 0x04;
    SETBIT(AD2CON1bits.SAMP);
    while (!AD2CON1bits.DONE);
    CLEARBIT(AD2CON1bits.DONE);

    return ADC2BUF0;
}

CPU_INT16U AD2_read_y()
{
    AD2CHS0bits.CH0SA = 0x05;
    SETBIT(AD2CON1bits.SAMP);
    while (!AD2CON1bits.DONE);
    CLEARBIT(AD2CON1bits.DONE);
    
    return ADC2BUF0;
}