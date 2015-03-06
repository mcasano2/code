#include "timers.h"

void timer1_setup(uint8_t ms, uint8_t interrupt)
{
    /* Timer 1 */
   // __builtin_write_OSCCONL(OSCCONL | 2);
    T1CONbits.TON = 0;
    T1CONbits.TCS = 0;
    T1CONbits.TSYNC = 0;
    IPC0bits.T1IP = 0x01;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = interrupt;
    T1CONbits.TCKPS = 0b10;
    TMR1 = 0x00;
    PR1 = TICKS(ms);
    T1CONbits.TON = 1;
}

void timer2_setup(uint8_t ms, uint8_t interrupt)
{
        /* Timer 2 */
        T2CONbits.TON = 0;
        T2CONbits.TCS = 0;
        T2CONbits.TGATE = 0;
        IPC1bits.T2IP = 0x01;
        IFS0bits.T2IF = 0;
        IEC0bits.T2IE = interrupt;
        T2CONbits.TCKPS = 0b10;
        PR2 = TICKS(ms);                              //Period of 200 is 1ms
        T2CONbits.TON = 1;
}

