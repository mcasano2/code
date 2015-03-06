/*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*                               (c) Copyright 2006, Micrium, Weston, FL
*                                          All Rights Reserved
*
*
*                                      Microchip Application Code
*
* File : APP.C
* By   : Eric Shufo
*********************************************************************************************************
*/

#include <includes.h>
#include "ADC.h"
#include "PWM.h"

#define  APP_TASK_START_PRIO                    0                       /* Lower numbers are of higher priority                     */
#define  APP_TASK_DISPLAY_PRIO		            6
#define  APP_TASK_PID_PRIO                          5
#define  APP_TASK_DAC_PRIO                          4

//TODO: Define task priorities for the ball control and DAC writing tasks. Lower numbers are of higher priority.

#define  APP_TASK_START_STK_SIZE              128
#define  APP_TASK_DISPLAY_STK_SIZE            256
#define  APP_TASK_PID_STK_SIZE            256
#define  APP_TASK_DAC_STK_SIZE            256
//TODO: Define task stack sizes for the ball control and DAC writing tasks.

/*
*********************************************************************************************************
*                                                CONSTANTS
*********************************************************************************************************
*/

#define POS_ARRAY_SIZE 1
#define FILTER_SIZE POS_ARRAY_SIZE
#define IO_RATE 20 //Hz

/*
*********************************************************************************************************
*                                                VARIABLES
*********************************************************************************************************
*/

OS_STK  AppStartTaskStk[APP_TASK_START_STK_SIZE];
OS_STK  AppDisplayTaskStk[APP_TASK_DISPLAY_STK_SIZE];

//TODO: Declare the actual task stacks for the ball control and DAC writing tasks.
OS_STK  AppPIDTaskStk[APP_TASK_DISPLAY_STK_SIZE];
OS_STK  AppDACTaskStk[APP_TASK_DISPLAY_STK_SIZE];

//TODO: Add all the variables that you need for your ball_control() function
CPU_INT16U xpos;
CPU_INT16U ypos;
float X_error = 0;
float X_previous_error = 0;
float X_integral = 0;
float X_derivative = 0;

float Y_error = 0;
float Y_previous_error = 0;
float Y_integral = 0;
float Y_derivative = 0;

int xy_flipflop = 0;

#define PID_PERIOD 50
#define MAX_PULSE 2.1
#define MIN_PULSE .9
#define X_SETPOINT 1600
#define Y_SETPOINT 1500

#define Kp .2
#define Kd 30
#define Ki .0001

#define TIMER_PERIOD 20

#define MIN_MAX(x,y,z) x < z ? x : y > z ? y : z

/************************************* DAC related code********************************/

CPU_INT16U vhigh=0x17ff;
CPU_INT16U vlow=0x1000;
//The vhigh and vlow values are the values that are written to the DAC periodically. The highest order
//4 bits are configuration bits and the rest are data bits to specify a digital value to the DAC.
//You need not change these values. You may send these values to the DAC. If you however wish to change it,
//You may refer the MCP4822 datasheet in the course website.

#define DSCK_AD1 AD1PCFGLbits.PCFG11
#define DSCK_AD2 AD2PCFGLbits.PCFG11
#define DSCK_TRIS TRISBbits.TRISB11

#define DSDI_AD1 AD1PCFGLbits.PCFG10
#define DSDI_AD2 AD2PCFGLbits.PCFG10
#define DSDI_TRIS TRISBbits.TRISB10

#define DLDAC_AD1 AD1PCFGLbits.PCFG13
#define DLDAC_AD2 AD2PCFGLbits.PCFG13
#define DLDAC_TRIS TRISBbits.TRISB13


void dac_init()
{
	DSCK_AD1=1; // set Pin to Digital
	Nop();
	DSCK_AD2=1; // set Pin to Digital
	Nop();
	DSCK_TRIS=0; // set Pin to Output
	Nop();

	DSDI_AD1=1; // set Pin to Digital
	Nop();
	DSDI_AD2=1; // set Pin to Digital
	Nop();
	DSDI_TRIS=0; // set Pin to Output
	Nop();

	DLDAC_AD1=1; // set Pin to Digital
	Nop();
	DLDAC_AD2=1; // set Pin to Digital
	Nop();
	DLDAC_TRIS=0; // set Pin to Output
	Nop();
	
	TRISDbits.TRISD8=0;
	Nop();
}

void writeDAC(CPU_INT16U val)
{
		PORTDbits.RD8=0;//CS is active low
		PORTBbits.RB13 = 1;   // set it high
		Nop();
		PORTBbits.RB11=0;
		Nop();
		int i=0;
		CPU_INT16U dacval = val;
		for(i=0;i<16;i++)
		{
			if(dacval&0x8000)
				PORTBbits.RB10=1;
			else
				PORTBbits.RB10=0;
	
			Nop();		
			PORTBbits.RB11=0;
			Nop();
			PORTBbits.RB11=1;
			Nop();
			dacval=  dacval<<1;
		}

		PORTDbits.RD8=1;//CS is active low
		Nop();	
		PORTBbits.RB13 = 0;
		Nop();
		PORTBbits.RB13 = 1;
		OSTimeDlyHMSM(0,0,0,1);

}
/******************************************************************************************/


/*
*********************************************************************************************************
*                                            FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppStartTask(void *p_arg);
static	void  AppDisplayTask(void *p_arg);
static  void  AppTaskCreate(void);
//TODO: Add your function prototype declarations here.
static	void  AppPIDTask(void *p_arg);
static	void  AppDACTask(void *p_arg);

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.
* Arguments   : none
*********************************************************************************************************
*/

CPU_INT16S  main (void)
{
    CPU_INT08U  err;

    BSP_IntDisAll();                                                    /* Disable all interrupts until we are ready to accept them */
    OSInit();                                                           /* Initialize "uC/OS-II, The Real-Time Kernel"              */

    OSTaskCreateExt(AppStartTask,										/* Create the start-up task for system initialization       */
                    (void *)0,
                    (OS_STK *)&AppStartTaskStk[0],
                    APP_TASK_START_PRIO,
                    APP_TASK_START_PRIO,
                    (OS_STK *)&AppStartTaskStk[APP_TASK_START_STK_SIZE-1],
                    APP_TASK_START_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    OSTaskNameSet(APP_TASK_START_PRIO, (CPU_INT08U *)"Start Task", &err);

    OSStart();                                                          /* Start multitasking (i.e. give control to uC/OS-II)       */
	return (-1);                                                        /* Return an error - This line of code is unreachable       */
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppStartTask()' by 'OSTaskCreate()'.
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*               2) Interrupts are enabled once the task start because the I-bit of the CCR register was
*                  set to 0 by 'OSTaskCreate()'.
*********************************************************************************************************
*/

static  void  AppStartTask (void *p_arg)
{
	(void)p_arg;
	
    BSP_Init();                                                         /* Initialize BSP functions                                 */
    OSStatInit();                                                       /* Determine CPU capacity                                   */
	DispInit();
	dac_init();
        touch_init();
        setup_ADC2();
        PWM_setup();
        timer2_setup(TIMER_PERIOD, NO_INT);
	OSTimeDlyHMSM(0, 0, 2, 0);
	//TODO: do all necessary initializations here.

    AppTaskCreate();                                                    /* Create additional user tasks                             */

    while (DEF_TRUE) {
	    OSTimeDlyHMSM(0, 0, 5, 0);
    }
}


/*
*********************************************************************************************************
*                              CREATE ADDITIONAL APPLICATION TASKS
*********************************************************************************************************
*/

OS_TMR *DisplayTimerHandler;
OS_TMR *PIDTimerHandler;
OS_TMR *DACTimerHandler;
    //TODO: declare the timer handlers here for the ball control and DAC writing tasks, similiar to the DisplayTimerHandler.
	CPU_INT08U led;
	CPU_INT32S count;
	CPU_INT08U buffer[50];
	OS_EVENT *displaySem;
	//TODO: declare semaphores for the ball control and the DAC tasks as well.
        OS_EVENT *pidSem;
        OS_EVENT *dacSem;

static void DisplayTimer (void *ptmr, void *p_arg)
{	
	OSSemPost(displaySem);
}

static void PIDTimer (void *ptmr, void *p_arg)
{	
	OSSemPost(pidSem);
}

static void DACTimer (void *ptmr, void *p_arg)
{	
	OSSemPost(dacSem);
}

//TODO: Add timer ISRs ( callback functions ) for ball control and DAC writing tasks as well.

static  void  AppTaskCreate (void)
{
    
	CPU_INT08U  err;
    

    OSTaskCreateExt(AppDisplayTask,										
                    (void *)0,
                    (OS_STK *)&AppDisplayTaskStk[0],
                    APP_TASK_DISPLAY_PRIO,
                    APP_TASK_DISPLAY_PRIO,
                    (OS_STK *)&AppDisplayTaskStk[APP_TASK_DISPLAY_STK_SIZE-1],
                    APP_TASK_DISPLAY_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    OSTaskNameSet(APP_TASK_DISPLAY_PRIO, (CPU_INT08U *)"Display Task", &err);

	//TODO: Create tasks for ball control and writing to DAC. You may use the OSTaskCreateExt
	//line given above as an example to create your tasks. Each task should use its own stack 
	//and should have its own priority, as shown above. You may refer the uCOS-II reference
	//document for more information on this function.

    OSTaskCreateExt(AppPIDTask,
                    (void *)0,
                    (OS_STK *)&AppPIDTaskStk[0],
                    APP_TASK_PID_PRIO,
                    APP_TASK_PID_PRIO,
                    (OS_STK *)&AppPIDTaskStk[APP_TASK_PID_STK_SIZE-1],
                    APP_TASK_PID_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    OSTaskNameSet(APP_TASK_PID_PRIO, (CPU_INT08U *)"PID Task", &err);


    OSTaskCreateExt(AppDACTask,
                    (void *)0,
                    (OS_STK *)&AppDACTaskStk[0],
                    APP_TASK_DAC_PRIO,
                    APP_TASK_DAC_PRIO,
                    (OS_STK *)&AppDACTaskStk[APP_TASK_DAC_STK_SIZE-1],
                    APP_TASK_DAC_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    OSTaskNameSet(APP_TASK_DAC_PRIO, (CPU_INT08U *)"DAC Task", &err);
	

	//Creating the timers
	//The second parameter in this function call specifies the period of the timer in milli-seconds. The fourth parameter specifies the name of the
	//timer ISR ( the callback function ). 
	DisplayTimerHandler=OSTmrCreate(0, 
						1000,    
						OS_TMR_OPT_PERIODIC,
                        DisplayTimer,
                      	(void *)0,
                      	"Display Timer",
                        &err);
	OSTmrStart(DisplayTimerHandler, &err);
	
	//TODO: Create the actual timers associated with each of the tasks. When a timer fires, you must set 
	//the semaphore in the ISR. The corresponding task must wait on this semaphore. This structure
	//of code ensures that the tasks run periodically, without actually putting task bodies inside
	//the ISR.
	//For additional information on the function and its parameters, you may refer the os_tmr.c file.
        PIDTimerHandler=OSTmrCreate(0,
						50,
						OS_TMR_OPT_PERIODIC,
                        PIDTimer,
                      	(void *)0,
                      	"PID Timer",
                        &err);
	OSTmrStart(PIDTimerHandler, &err);

        DACTimerHandler=OSTmrCreate(0,
						5,
						OS_TMR_OPT_PERIODIC,
                        DACTimer,
                      	(void *)0,
                      	"DAC Timer",
                        &err);
	OSTmrStart(DACTimerHandler, &err);

	
	//TODO: Output boilerplate text
	DispClrScr();
	DispStr(0,0,(CPU_INT08U *)"CS 431 Group 4 Lab 9");
    LED_Off(0);                                                         /* Turn OFF all the LEDs and cycle through                  */
	count = 0;
	led = 1;

	displaySem = OSSemCreate(0);
        pidSem = OSSemCreate(0);
        dacSem = OSSemCreate(0);
	//TODO: Create semaphores for the other 2 tasks as well. You may refer the reference uCOS-II document if you need more information on this function.
}

static void AppDisplayTask(void *p_arg)
{
	
	(void)p_arg;
        int x = 1;
	while (DEF_TRUE) {
		// execute loop every second  

		CPU_INT08U  err;
		OSSemPend(displaySem, 0,  &err);

		// update active LED
		LED_Off(led);
		led = (led == 5 ? 1 : led+1);
		LED_On(led);

		// display updated time on LCD
		sprintf(buffer, "Uptime: %ld seconds", count++);
		DispStr(1, 0, buffer);
		//TODO: Print out the ball's X and Y positions here.
                sprintf(buffer, "X: %u  Y: %u    ", xpos, ypos);
                DispStr(2, 0, buffer);
    }
}

//TODO: Create ball control and DAC writing tasks. These tasks' structure should resemble the display 
//task's structure. Inside the infinite while loop, the tasks should wait on a semaphore that is set
//in their corresponding timer ISR's body.

float normalize_value(float min_val, float max_val, float current, float norm_min, float norm_max);

int compare(CPU_INT16U * elem1, CPU_INT16U * elem2)
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
            CPU_INT16U ypos_arr[5];
            for(j = 0; j < 5; j++)
            {
                ypos_arr[j] = touch_adc();
            }

            qsort(ypos_arr, 5, sizeof(CPU_INT16U), compare);

            ypos = ypos_arr[2];

            touch_select_dim_nodelay(X);
        }
        else
        {
            CPU_INT16U xpos_arr[5];
            for(j = 0; j < 5; j++)
            {
                xpos_arr[j] = touch_adc();
            }
            qsort(xpos_arr, 5, sizeof(CPU_INT16U), compare);

            xpos = xpos_arr[2];

            touch_select_dim_nodelay(Y);
        }
}


static void AppPIDTask(void *p_arg)
{
    (void)p_arg;

    float X_error = 0;
    float X_previous_error = 0;
    float X_integral = 0;
    float X_derivative = 0;

    float Y_error = 0;
    float Y_previous_error = 0;
    float Y_integral = 0;
    float Y_derivative = 0;
    
    float X_output;
    float X_noutput;

    float Y_output;
    float Y_noutput;

    while(DEF_TRUE){
        CPU_INT08U  err;
	OSSemPend(pidSem, 0,  &err);

        get_loc();

        float dt = PID_PERIOD;

        if(xy_flipflop)
        {

            Y_error = ((float)Y_SETPOINT - ypos);
            Y_integral = Y_integral + (Y_error * dt);
            Y_derivative = (Y_error - Y_previous_error)/((float)dt);
            Y_output = Kp * Y_error + Ki * Y_integral + Kd * Y_derivative;
            Y_previous_error = Y_error;

            Y_noutput = normalize_pulse(-500, 500, Y_output);

            PWM_set_y_cycle(time_to_inverted_clocks(Y_noutput, TIMER_PERIOD));
        }
        else
        {
            X_error = ((float)X_SETPOINT - xpos);
            X_integral = X_integral + (X_error * dt);
            X_derivative = (X_error - X_previous_error)/((float)dt);
            X_output = Kp * X_error + Ki * X_integral + Kd * X_derivative;
            X_previous_error = X_error;
            //lcd_printf("%f\n", output);

            X_noutput = normalize_pulse(-500, 500, X_output);

            PWM_set_x_cycle(time_to_inverted_clocks(X_noutput, TIMER_PERIOD));

        }
        xy_flipflop = !xy_flipflop;
    }
}


static void AppDACTask(void *p_arg)
{
    (void)p_arg;

    int x = -1;
    while(DEF_TRUE){
        CPU_INT08U  err;
	OSSemPend(dacSem, 0,  &err);
        writeDAC(x == -1 ? vlow : vhigh);
        x = -x;
    }
}