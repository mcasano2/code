#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL
#include <stdlib.h>
#include <stdio.h>
#include <libpic30.h>
#include "types.h"
#include "lcd.h"
#include "ADC.h"


/* Initial configuration by EE */
// Primary (XT, HS, EC) Oscillator with PLL
_FOSCSEL(FNOSC_PRIPLL);

// OSC2 Pin Function: OSC2 is Clock Output - Primary Oscillator Mode: XT Crystal
_FOSC(OSCIOFNC_OFF & POSCMD_XT);

// Watchdog Timer Enabled/disabled by user software
_FWDT(FWDTEN_OFF);

// Disable Code Protection
_FGS(GCP_OFF);

void touch_init();
int compare(uint16_t * elem1, uint16_t * elem2);

void main()
{
    //Init LCD
    __C30_UART = 1;
    lcd_initialize();
    lcd_clear();

    //Set pin for digital I/O
    //AD1PCFGHbits.PCFG20 = 1;
    
    
    touch_init();

    int i = 0;
    while(1)
    {
        if(i == 5000)
        {
            lcd_locate(0,0);
            uint16_t ypos[5];
            int j;
            for(j = 0; j < 5; j++)
            {
                ypos[j] = touch_adc();
            }
            touch_select_dim(X);
            qsort(ypos, 5, sizeof(uint16_t), compare);
            
            
            lcd_locate(0,1);
            uint16_t xpos[5];
            for(j = 0; j < 5; j++)
            {
                xpos[j] = touch_adc();
            }
            touch_select_dim(Y);
            qsort(xpos, 5, sizeof(uint16_t), compare);
            lcd_printf("Y: %d        \r\nX: %d        ",ypos[2], xpos[2]);
            i=0;
        }
        i++;
        
    }

    
    while(1);

}

int compare(uint16_t * elem1, uint16_t * elem2)
{
    return (*elem1) - (*elem2);
}