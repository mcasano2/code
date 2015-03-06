#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL
#include <stdlib.h>
#include <stdio.h>
#include <libpic30.h>
#include "types.h"
#include "led.h"
#include "lcd.h"
#include "ADC.h"
#include "PWM.h"

#define TIMER_PERIOD 20
#define MAX_PULSE 2.1
#define MIN_PULSE .9
#define Y_PULSE 1.9


#define X_SETPOINT 1600
#define T1_PERIOD 50

#define Kp .3
#define Kd 100
#define Ki .0001

float error = 0;
float previous_error = 0;
float integral = 0;
float derivative = 0;

uint16_t xpos_glob;
uint16_t ypos_glob;
float output;
float noutput;

#define MIN_MAX(x,y,z) x < z ? x : y > z ? y : z

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
    led_initialize();
    lcd_initialize();
    lcd_clear();

    //Set pin for digital I/O
    //AD1PCFGHbits.PCFG20 = 1;
    
    
    touch_init();
    timer1_setup(T1_PERIOD, WITH_INT);
    timer2_setup(TIMER_PERIOD, NO_INT);
    PWM_setup();
    
    PWM_set_y_cycle(time_to_inverted_clocks(Y_PULSE, TIMER_PERIOD));
    touch_select_dim(X);

    int i = 0;
    while(1)
    {
        if(i == 5000)
        {
            

            lcd_locate(0,0);
            lcd_printf("Kp: %.2f    \rKd: %.2f    \rKi: %.5f    \rSet_x: %d    \rP_X: %d    \rD_x: %.2f    \rI_x: %.2f    \rF_x: %.2f    \r",
                    (float)Kp,
                    (float)Kd,
                    (float)Ki,
                    X_SETPOINT,
                    xpos_glob,
                    derivative,
                    integral,
                    noutput)
 //           lcd_printf("Y: %d    \r\nX: %d    \r\nOutput: %.2f    \r\nNOutput: %.2f    \r\n",ypos[2], xpos[2], output, noutput);
        
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

float normalize_pulse(float min, float max, float current)
{
    current = MIN_MAX(max,min,current);
    float denom = max - min;
    float numer = current - min;
    return ((numer/denom) * (MAX_PULSE - MIN_PULSE)) + MIN_PULSE;
}

void get_loc()
{
    /*
        uint16_t ypos[5];
        
        for(j = 0; j < 5; j++)
        {
            ypos[j] = touch_adc();
        }
        
        qsort(ypos, 5, sizeof(uint16_t), compare);

*/
        int j;
        uint16_t xpos[5];
        for(j = 0; j < 5; j++)
        {
            xpos[j] = touch_adc();
        }
//        touch_select_dim(Y);
        qsort(xpos, 5, sizeof(uint16_t), compare);

        xpos_glob = xpos[2];
      //  ypos_glob = ypos[2];
}

void __attribute__((__interrupt__)) _T1Interrupt(void) {
	LED2_PORT^=1;


        get_loc();

        float dt = T1_PERIOD;

        error = ((float)X_SETPOINT - xpos_glob);
        integral = integral + (error * dt);
        derivative = (error - previous_error)/((float)dt);
        output = Kp * error + Ki * integral + Kd * derivative;
        previous_error = error;
        //lcd_printf("%f\n", output);

        noutput = normalize_pulse(-1000, 1000, output);

        PWM_set_x_cycle(time_to_inverted_clocks(noutput, TIMER_PERIOD));

	IFS0bits.T1IF = 0;
}