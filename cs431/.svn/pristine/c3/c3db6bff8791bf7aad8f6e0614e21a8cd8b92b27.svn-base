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

#define XMIN 0
#define XMAX 1
#define YMIN 2
#define YMAX 3
#define XPULSE 4
#define YPULSE 5

#define TIMER_PERIOD 20
#define MAX_PULSE 2.1
#define MIN_PULSE .9

#define MAX_X_POS 3000
#define MAX_Y_POS 2500
#define MIN_X_POS 295
#define MIN_Y_POS 450

int xy_flipflop = 0;

//#define X_SETPOINT 1600
//#define Y_SETPOINT 1500
uint16_t X_SETPOINT = 1600;
uint16_t Y_SETPOINT = 1500;

#define T1_PERIOD 50

#define Kp .2
#define Kd 30
#define Ki .0001
//.0001

float X_error = 0;
float X_previous_error = 0;
float X_integral = 0;
float X_derivative = 0;

float Y_error = 0;
float Y_previous_error = 0;
float Y_integral = 0;
float Y_derivative = 0;

uint16_t xpos_glob;
uint16_t ypos_glob;

float X_output;
float X_noutput;

float Y_output;
float Y_noutput;


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
uint8_t debounced(uint16_t port, uint8_t * bool_buffer, uint8_t status);
float normalize_value(float min_val, float max_val, float current, float norm_min, float norm_max);

void main()
{
    //Init LCD
    __C30_UART = 1;
    led_initialize();
    lcd_initialize();
    lcd_clear();

    //Set pin for digital I/O
    AD1PCFGHbits.PCFG20 = 1;

    uint8_t button1_status = 0;
    uint8_t button1_buffer = 0;
    uint16_t read_values[4];
    const char * message[4] = { "Min X: %u   \n\r",
                                "Max X: %u   \n\r",
                                "Min Y: %u   \n\r",
                                "Max Y: %u   \n\r"};
    uint8_t current = 0;
    uint16_t counter = 0;

    touch_init();
    setup_ADC2();

    int setup = 1;

    while (setup) {

        uint8_t newstatus = debounced(PORTEbits.RE8,&button1_buffer, button1_status);
        
        if(newstatus && (newstatus != button1_status) && (current < 4))
        {
            current++;
            //lcd_clear();
        }
        if(current >= 4)
            setup = 0;
        if(current == XMIN || current == XMAX)
        {
            read_values[current] = AD2_read_x();
        }
        else if(current == YMIN || current == YMAX)
        {
            read_values[current] = AD2_read_y();
        }
        

        counter++;
        if(counter == 5000)
        {

            lcd_locate(0, current);
            lcd_printf(message[current], read_values[current]);
            counter = 0;
        }
        button1_status = newstatus;

    }

    lcd_clear();
    timer1_setup(T1_PERIOD, WITH_INT);
    timer2_setup(TIMER_PERIOD, NO_INT);
    PWM_setup();
    
    touch_select_dim(X);

    uint16_t xval;
    uint16_t yval;

    int i = 0;
    while(1)
    {
        uint8_t newstatus = debounced(PORTEbits.RE8,&button1_buffer, button1_status);

        if(newstatus && !button1_status)
        {
            X_SETPOINT = xval;
            Y_SETPOINT = yval;
        }

        if(i == 5000)
        {
            xval = (uint16_t)normalize_value(read_values[XMIN], read_values[XMAX], MIN_MAX(read_values[XMAX], read_values[XMIN], AD2_read_x()), MIN_X_POS, MAX_X_POS);
            yval = (uint16_t)normalize_value(read_values[YMIN], read_values[YMAX], MIN_MAX(read_values[YMAX], read_values[YMIN], AD2_read_y()), MIN_Y_POS, MAX_Y_POS);

            lcd_locate(0,0);
            lcd_printf("P_X.Y: %d.%d    \r\nSET_X.Y: %d.%d  \r\nJOY_X.Y: %d.%d  \r\n\r\nKp: %.2f    \r\nKd: %.2f    \r\nKi: %.5f    \r\n",
                      xpos_glob,
                      ypos_glob,
                      X_SETPOINT,
                      Y_SETPOINT,
                      xval,
                      yval,
                      (float)Kp,
                      (float)Kd,
                      (float)Ki);        
            i=0;
        }
        i++;
        button1_status = newstatus;
    }

    
    while(1);

}

int compare(uint16_t * elem1, uint16_t * elem2)
{
    return (*elem1) - (*elem2);
}

float normalize_pulse(float min, float max, float current)
{
    return normalize_value(min, max, current, MIN_PULSE, MAX_PULSE);
}

float normalize_value(float min_val, float max_val, float current, float norm_min, float norm_max)
{
    current = MIN_MAX(max_val,min_val,current);
    float denom = max_val - min_val;
    float numer = current - min_val;
    return ((numer/denom) * (norm_max - norm_min)) + norm_min;
}

void get_loc()
{
        int j;
        if(xy_flipflop)
        {
            uint16_t ypos[5];
            for(j = 0; j < 5; j++)
            {
                ypos[j] = touch_adc();
            }
        
            qsort(ypos, 5, sizeof(uint16_t), compare);

            ypos_glob = ypos[2];

            touch_select_dim_nodelay(X);
        }
        else
        {
            uint16_t xpos[5];
            for(j = 0; j < 5; j++)
            {
                xpos[j] = touch_adc();
            }
            qsort(xpos, 5, sizeof(uint16_t), compare);

            xpos_glob = xpos[2];

            touch_select_dim_nodelay(Y);
        }
}

void __attribute__((__interrupt__)) _T1Interrupt(void) {
	LED2_PORT^=1;

        get_loc();

        float dt = T1_PERIOD;

        if(xy_flipflop)
        {

            Y_error = ((float)Y_SETPOINT - ypos_glob);
            Y_integral = Y_integral + (Y_error * dt);
            Y_derivative = (Y_error - Y_previous_error)/((float)dt);
            Y_output = Kp * Y_error + Ki * Y_integral + Kd * Y_derivative;
            Y_previous_error = Y_error;

            Y_noutput = normalize_pulse(-500, 500, Y_output);

            PWM_set_y_cycle(time_to_inverted_clocks(Y_noutput, TIMER_PERIOD));
        }
        else
        {
            X_error = ((float)X_SETPOINT - xpos_glob);
            X_integral = X_integral + (X_error * dt);
            X_derivative = (X_error - X_previous_error)/((float)dt);
            X_output = Kp * X_error + Ki * X_integral + Kd * X_derivative;
            X_previous_error = X_error;
            //lcd_printf("%f\n", output);

            X_noutput = normalize_pulse(-500, 500, X_output);

            PWM_set_x_cycle(time_to_inverted_clocks(X_noutput, TIMER_PERIOD));

        }
        xy_flipflop = !xy_flipflop;
        IFS0bits.T1IF = 0;
}

/* If port is 0, status is 1.*/
/* Returns 1 when pressed. (duh)*/
uint8_t debounced(uint16_t port, uint8_t * bool_buffer, uint8_t status)
{
    (*bool_buffer) = ((*bool_buffer) << 1) | (port == 0);

    if (*bool_buffer == 0xFF)
        return 1;
    if (*bool_buffer == 0x00)
        return 0;
    return status;

}