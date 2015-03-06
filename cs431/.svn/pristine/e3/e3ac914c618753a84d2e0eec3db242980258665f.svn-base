#include "lcd.h"
#include "types.h"
#include "led.h"
//#include "flexmotor.h"
//#include "flextouch.h"
#include "performance.h"
#include "math.h"
#include "ADC.h"
#include "PWM.h"

#include <p33Fxxxx.h>
#include <stdlib.h>

#define FCY 12800000UL

// control task frequency (Hz)
#define RT_FREQ 50

//setpoint parameters
#define SPEED 0.08  // tested up to .12!
#define RADIUS 350
#define CENTER_X 1650
#define CENTER_Y 1350

// Servo defines
#define MAX_DUTY_MICROSEC 2100
#define MIN_DUTY_MICROSEC 900
#define SERVO_PWM_PERIOD_MICROSEC 20000
#define INIT_DUTYX_MICROSEC 1410    // leveled plate on X axis: 1410
#define INIT_DUTYY_MICROSEC 1400     // leveled plate on Y axis: 1400
#define MOTOR_X_CHAN 1
#define MOTOR_Y_CHAN 2

// Touch screen definitions
//#define X_DIM 1
//#define Y_DIM 2

//#define MAX_PULSE 2.1
//#define MIN_PULSE .9

#define MIN_MAX(x,y,z) x < z ? x : y > z ? y : z

#define Kp .10
#define Kd 12
#define Ki .00001

uint16_t TOUCH_MIN_X = 340;
uint16_t TOUCH_MAX_X = 3020;
uint16_t TOUCH_MIN_Y = 454;
uint16_t TOUCH_MAX_Y = 2657;

// do not change position of this include
#include <libpic30.h>

/* Initial configuration by EE */
// Primary (XT, HS, EC) Oscillator with PLL
_FOSCSEL(FNOSC_PRIPLL);

// OSC2 Pin Function: OSC2 is Clock Output - Primary Oscillator Mode: XT Crystal
_FOSC(OSCIOFNC_OFF & POSCMD_XT);

// Watchdog Timer Enabled/disabled by user software
_FWDT(FWDTEN_OFF);

// Disable Code Protection
_FGS(GCP_OFF);

float normalize_value(float min_val, float max_val, float current, float norm_min, float norm_max);
float normalize_pulse(float min, float max, float current);

// control setpoint
double Xpos_set = 1650.0, Ypos_set = 1550.0;

// raw, unfiltered X and Y position of the ball
volatile uint16_t Xpos, Ypos;
volatile uint8_t start = 0;
volatile uint8_t select = X;
volatile uint8_t deadline_miss = 0;


float X_error = 0;
float X_previous_error = 0;
float X_integral = 0;
float X_derivative = 0;

float Y_error = 0;
float Y_previous_error = 0;
float Y_integral = 0;
float Y_derivative = 0;

float X_output;
double X_noutput;

float Y_output;
double Y_noutput;


double pidX_controller(double Xp) {
    float dt = 15;
    //double pid;
    // TODO: Implement PID X
    X_error = (Xpos_set - Xpos);
    X_integral = X_integral + (X_error * dt);
    X_derivative = (X_error - X_previous_error)/(dt);
    X_output = Kp * X_error + Ki * X_integral + Kd * X_derivative;
    X_previous_error = X_error;
    //lcd_printf("%f\n", output);

    X_noutput = (double)normalize_pulse(-400, 400, X_output);

    //PWM_set_x_cycle(time_to_inverted_clocks(X_noutput, TIMER_PERIOD));
    return X_noutput;
}


double pidY_controller(double Yp) {
    float dt = 15;
    //double pid;
    // TODO: Implement PID Y
    Y_error = (Ypos_set - Ypos);
    Y_integral = Y_integral + (Y_error * dt);
    Y_derivative = (Y_error - Y_previous_error)/(dt);
    Y_output = Kp * Y_error + Ki * Y_integral + Kd * Y_derivative;
    Y_previous_error = Y_error;


    Y_noutput = (double)normalize_pulse(-400, 400, Y_output);

    //PWM_set_y_cycle(time_to_inverted_clocks(Y_noutput, TIMER_PERIOD));
    return Y_noutput;
}


// Configure the real-time task timer and its interrupt.
void timers_initialize() {

  //Set Timer1 to generate an interrupt every 10ms (100Hz) ==> PR1=500
  CLEARBIT(T1CONbits.TON); //Disable Timer
  CLEARBIT(T1CONbits.TCS); //Select internal instruction cycle clock
  CLEARBIT(T1CONbits.TGATE); //Disable Gated Timer mode
  T1CONbits.TCKPS = 0b11; //Select 1:256 Prescaler
  PR1 = 500; //Load the period value ==> running at 100Hz now!
  TMR1 = 0x00; //Clear timer register
  IPC0bits.T1IP = 0x01; // Set Timer1 Interrupt Priority Level
  CLEARBIT(IFS0bits.T1IF); // Clear Timer1 Interrupt Flag
  SETBIT(IEC0bits.T1IE); // Enable Timer1 interrupt
  SETBIT(T1CONbits.TON); // Start Timer
}

int main(){
  uint8_t start_r, old_IPL;
  uint8_t hz50_scaler, hz5_scaler, hz1_scaler, sec;
  uint32_t tick = 0;

  hz50_scaler = hz5_scaler = hz1_scaler = sec = 0;

  //touch_init();
  //dac_init();
  touch_init();
  setup_ADC2();
  PWM_setup();
  timer2_setup(TIMER_PERIOD, NO_INT);

  __delay_ms(200);
  lcd_initialize();             // Initialize the LCD 


  lcd_clear();
  lcd_locate(0,0);
  lcd_printf("-- Ball position: --");

  timers_initialize();          // Initialize timers

  while (1) {
    start_r = 0;
    while(!start_r) {      
      // disable all maskable interrupts
      SET_AND_SAVE_CPU_IPL(old_IPL, 7);
      start_r = start;

      // enable all maskable interrupts
      RESTORE_CPU_IPL(old_IPL);
    }

    // Periodic real-time task code starts here!!!
    double pidX, pidY;
    uint16_t duty_us_x, duty_us_y;

    // 50Hz control task
    if(hz50_scaler == 0) {
      calcQEI(Xpos_set, Xpos, Ypos_set, Ypos);

      Xpos_set = CENTER_X + RADIUS * cos(tick * SPEED);
      Ypos_set = CENTER_Y + RADIUS * sin(tick * SPEED);
      tick++;

      pidX = pidX_controller(Xpos);
      pidY = pidY_controller(Ypos);

      duty_us_x = pidX;
      duty_us_y = pidY;

      // TODO: Convert PID to motor duty cycle (900-2100 us)

      // setMotorDuty is a wrapper function that calls your motor_set_duty
      // implementation in flexmotor.c. The 2nd parameter expects a value
      // between 900-2100 us
      setMotorDuty(MOTOR_X_CHAN, duty_us_x);
      setMotorDuty(MOTOR_Y_CHAN, duty_us_y);
      //lcd_printf("d: %4u %4u\r\n", duty_us_x, duty_us_y);
      //PWM_set_x_cycle(time_to_inverted_clocks(pidX, TIMER_PERIOD));
      //PWM_set_y_cycle(time_to_inverted_clocks(pidY, TIMER_PERIOD));
    }

    // 5Hz display task
    if(hz5_scaler == 0) {
      lcd_locate(0,1);
      //lcd_printf("Xf(t)=%4u %4u\r\n", Xpos, Ypos);
      lcd_printf("Df(t)=%d %d", duty_us_x, duty_us_y);
      //lcd_printf("Pf(t)=%d %df\r\n", (int)Xpos_set, (int)Ypos_set);

      if(deadline_miss >= 1) {
        lcd_locate(0,6);
        lcd_printf("%4d d_misses!!!", deadline_miss);
      }
    }

    // 1Hz seconds display task
    if(hz1_scaler == 0) {
      lcd_locate(0,7);
      lcd_printf("QEI: %5u", getQEI());
      sec++;
    }
    
    hz50_scaler = (hz50_scaler + 1) % 2;
    hz5_scaler = (hz5_scaler + 1) % 20;
    hz1_scaler = (hz1_scaler + 1) % 100;

    start = 0;
  }

  return 0;
}

int compare(const void * elem1, const void * elem2)
{
    return (*((uint16_t*)elem1)) - (*((uint16_t*)elem2));
}

float normalize_pulse(float min, float max, float current)
{
    return normalize_value(min, max, current, MIN_DUTY_MICROSEC, MAX_DUTY_MICROSEC);
}

float normalize_value(float min_val, float max_val, float current, float norm_min, float norm_max)
{
    current = MIN_MAX(max_val,min_val,current);
    float denom = max_val - min_val;
    float numer = current - min_val;
    return ((numer/denom) * (norm_max - norm_min)) + norm_min;
}

// This ISR will execute whenever Timer1 has a compare match.
// it kicks off the periodic execution of user code and performs I/O
// Min period: 10msec due to X,Y switch time for touchscreen
void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
  IFS0bits.T1IF = 0; // clear interrupt flag

  if(start == 1)
    deadline_miss++;

  int j;
  if (select == X) {
    // TODO: read 5 samples from X-dimension and set Xpos as the median

      uint16_t xpos_arr[5];
      for(j = 0; j < 5; j++)
      {
          xpos_arr[j] = touch_adc();
      }
      qsort(xpos_arr, 5, sizeof(uint16_t), compare);
      
      Xpos = xpos_arr[2];

      
    touch_select_dim_nodelay(Y);
    select = Y;
  }
  else {
    // TODO: read 5 samples from Y-dimension and set Ypos as the median
    uint16_t ypos_arr[5];
    for(j = 0; j < 5; j++)
    {
        ypos_arr[j] = touch_adc();
    }

    qsort(ypos_arr, 5, sizeof(uint16_t), compare);

    Ypos = ypos_arr[2];

    touch_select_dim_nodelay(X);
    select = X;
  }

  start = 1;
}
