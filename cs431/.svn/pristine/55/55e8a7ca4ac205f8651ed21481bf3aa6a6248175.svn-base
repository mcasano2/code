#include <p33Fxxxx.h>
//do not change the order of the following 3 definitions
#define FCY 12800000UL 
#include <stdio.h>
#include <libpic30.h>
#include "types.h"

#include "lcd.h"
#include "led.h"
#include "ADC.h"
#include "timers.h"

#define XMIN 0
#define XMAX 1
#define YMIN 2
#define YMAX 3
#define XPULSE 4
#define YPULSE 5

#define MAX_PULSE 2.1
#define MIN_PULSE .9

#define TIMER_PERIOD 20

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

uint8_t debounced(uint16_t port, uint8_t * bool_buffer, uint8_t status);

void main()
{
    //Init LCD
    __C30_UART = 1;
    lcd_initialize();
    led_initialize();
    lcd_clear();

    //Set pin for digital I/O
    AD1PCFGHbits.PCFG20 = 1;

    uint8_t button1_status = 0;
    uint8_t button1_buffer = 0;
    
    setup_ADC();

    
    float pulse_x;
    float pulse_y;
    uint16_t read_values[4];
    const char * message[6] = { "Min X: %u   \n\r",
                                "Max X: %u   \n\r",
                                "Min Y: %u   \n\r",
                                "Max Y: %u   \n\r",
                                "Pul X: %f ms   \n\r",
                                "Pul Y: %f ms   \n\r" };
    uint8_t current = 0;
    uint16_t counter = 0;

    timer2_setup(TIMER_PERIOD,0);
    PWM_setup();

    uint8_t setup = 1;
    
    while (setup) {
        uint8_t newstatus = debounced(PORTEbits.RE8,&button1_buffer, button1_status);
        
        if(newstatus && (newstatus != button1_status) && (current < 6))
        {
            current++;
            //lcd_clear();
        }
        if(current >= 6)
            setup = 0;
        if(current == XMIN || current == XMAX)
        {
            read_values[current] = AD2_read_x();
        }
        else if(current == YMIN || current == YMAX)
        {
            read_values[current] = AD2_read_y();
        }
        else if(current == XPULSE)
        {
            uint16_t xval = MIN_MAX(read_values[XMAX], read_values[XMIN], AD2_read_x());
            read_values[current] = xval;
        }
        else if(current == YPULSE)
        {
            uint16_t yval = MIN_MAX(read_values[YMAX], read_values[YMIN], AD2_read_y());
            read_values[current] = yval;
        }

        counter++;
        if(counter == 5000)
        {
         
            lcd_locate(0, current);
            if(current < 4)
            {
                lcd_printf(message[current], read_values[current]);
            }
            else if(current == XPULSE)
            {
                float denom = read_values[XMAX] - read_values[XMIN];
                float numer = read_values[current] - read_values[XMIN];
                pulse_x = ((numer/denom) * (MAX_PULSE - MIN_PULSE)) + MIN_PULSE;

                lcd_printf(message[current], pulse_x);
                PWM_set_x_cycle(time_to_inverted_clocks(pulse_x, TIMER_PERIOD));
            }
            else if(current == YPULSE)
            {
                float denom = read_values[YMAX] - read_values[YMIN];
                float numer = read_values[current] - read_values[YMIN];
                pulse_y = ((numer/denom) * (MAX_PULSE - MIN_PULSE)) + MIN_PULSE;

                lcd_printf(message[current], pulse_y);
                PWM_set_y_cycle(time_to_inverted_clocks(pulse_y, TIMER_PERIOD));
            }

            counter = 0;
        }
        button1_status = newstatus;
            
    }


    


//    while(1)
//    {
//        counter++;
//        if(counter == 10000)
//        {
//            lcd_locate(0,0);
//            {
//                uint16_t xval = MIN_MAX(read_values[XMAX], read_values[XMIN], AD2_read_x());
//                float denom = read_values[XMAX] - read_values[XMIN];
//                float numer = xval - read_values[XMIN];
//                pulse_x = ((numer/denom) * (MAX_PULSE - MIN_PULSE)) + MIN_PULSE;
//            }
//            {
//                uint16_t yval = MIN_MAX(read_values[YMAX], read_values[YMIN], AD2_read_y());
//                float denom = read_values[YMAX] - read_values[YMIN];
//                float numer = yval - read_values[YMIN];
//                pulse_y = ((numer/denom) * (MAX_PULSE - MIN_PULSE)) + MIN_PULSE;
//            }
//
//            lcd_printf("Pulsx:%f   \r\n", pulse_x);
//            lcd_printf("Timrp:%u   \r\n", TICKS(TIMER_PERIOD));
//
//            PWM_set_x_cycle(time_to_inverted_clocks(pulse_x, TIMER_PERIOD));
//            PWM_set_y_cycle(time_to_inverted_clocks(pulse_y, TIMER_PERIOD));
//            timer2_setup(TIMER_PERIOD,0);
//            counter = 0;
//        }
//    }

    
    
    
    while(1);

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

void __attribute__((__interrupt__)) _T2Interrupt(void) {
        LED1_PORT^=1;
        IFS0bits.T2IF = 0;
}





/* Old While Loop


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


 */