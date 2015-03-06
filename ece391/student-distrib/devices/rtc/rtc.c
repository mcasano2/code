/* rtc.c - Functions to interact with the real-time clock
 * vim:ts=4 noexpandtab
 */

#include "rtc.h"
#include "cmos.h"
#include "../i8259.h"
#include "../../lib.h"


/* Bitmapped status byte */
static unsigned long rtc_status = 0;
/* The current IRQ frequency */
static unsigned long rtc_freq = 0;
/* The data */
static unsigned long rtc_irq_data = 0;

volatile static char int_flag = 0;

static int rtc_set_freq(unsigned int freq);

/* RTC status bitmasks */
#define RTC_IS_OPEN     0x01
#define RTC_TIMER_ON    0x02

/* Initialize the 8259 PIC */
#define PIE_ENABLED (1 << 6)

/* rtc_init(void)
 * Initializes the RTC by enabling the correct IRQ on the i8259 PIC.
 *
 * INPUTS:  void
 * OUTPUTS: void
 */
void rtc_init(void)
{
	//info for writing to RTC registers is from
	//http://wiki.osdev.org/RTC
	//http://wiki.osdev.org/CMOS

	enable_irq(8);
    
    printf("RTC initialized.\n");
}

/* rtc_interrupt(void)
 * Handles RTC interrupts by recognizing a tick and printing 
 * it to the screen.
 *
 * INPUTS: void
 * OUTPUTS: void
 */
void rtc_interrupt(void)
{
    static unsigned int counter = 0;
    
    cmos_write(CMOS_IO_SEL, 0xC, 1);
    char reply = cmos_read(CMOS_IO_DATA); // need to do this for every interupt or no more wil be generated
    if ((reply & (1 << 6)) >> 6 == 1)
        //printf("Tick #%d!\n", counter++);

    int_flag = 1;
    
	send_eoi(8);

	cmos_write(CMOS_IO_SEL, 0xA, 0); // Re-enable NMI
}

/* File Operations */

/* rtc_open(void) 
 * Initializes the real-time clock, and changes the rtc status to closed.
 *
 * INPUT:  void
 * OUTPUT: 0 on success, -1 on fail.
 */
int rtc_open(void)
{
    unsigned long flags;
    cli_and_save(flags);

    /* If the RTC is open, return busy. */
    if (rtc_status & RTC_IS_OPEN)
    {
        printf("RTC is already open.\n");
        restore_flags(flags);
        sti();
        return -1; /* replace with correct -EBUSY return value */
    }
    
    /* Else, open the RTC and initialize it. */
    rtc_status |= RTC_IS_OPEN;
    rtc_irq_data = 0;

    /* Enable oscillations */
    cmos_write(CMOS_IO_SEL, 0xA, 1);
    cmos_write(CMOS_IO_DATA, 0x17, 0);

    /* Enable PIE */
    cmos_write(CMOS_IO_SEL, 0xB, 1);
    cmos_write(CMOS_IO_DATA, PIE_ENABLED | 0x40, 0);

    rtc_set_freq(2); // Default freq

	cmos_write(CMOS_IO_SEL, 0xA, 0); // Re-enable NMI

    restore_flags(flags);
    sti();
    return 0;
}

/* rtc_close(void)
 * Halts interrupts and re-opens the RTC for another file descriptor.
 *
 * INPUT:  void
 * OUTPUT: 0 on success. -1 on fail.
 */
int rtc_close(void)
{
    unsigned long flags;
    cli_and_save(flags);
    
	/* Halt interrupts */
    /*cmos_write(CMOS_IO_SEL, 0xB, 1);
    char tmp = cmos_read(CMOS_IO_DATA) & 0x0F;
    cmos_write(CMOS_IO_SEL, 0xB, 1);
    cmos_write(CMOS_IO_DATA, (0 | tmp), 0);*/

    rtc_status &= ~RTC_IS_OPEN;

    restore_flags(flags);
    sti();

	cmos_write(CMOS_IO_SEL, 0xA, 0); // Re-enables NMI

    return 0;
}

/* rtc_write(freq)
 * A simple interface to set the frequency.
 *
 * INPUT:  freq - the frequency of the rtc's periodic interrupts.
 * OUTPUT: 0 on success. -1 on fail.
 */
int rtc_write(int32_t *freq, int32_t nbytes)
{
    return rtc_set_freq(*freq);
}

/* rtc_read(void)
 * A call to read when the rtc's periodic interrupt is activated.
 * This function will loop indefinitely until an interrupt is
 * signaled.
 *
 * INPUT:  void
 * OUTPUT: 0 on success. -1 on fail.
 */
int rtc_read(void)
{
	sti();
    while(!int_flag);
    int_flag = 0;
    return 0;
}

/* rtc_set_freq(freq)
 * rtc_set_freq is an abstracted function that allows easy
 * setting of the rtc frequency. This function could be used
 * by the rtc_write() function, a system call, or some other
 * internal interface.
 * 
 * INPUT:  freq - The frequency in Hz in a 4-byte value
 * OUTPUT: 0 on success. -1 on fail.
 */

static int rtc_set_freq(unsigned int freq)
{
    unsigned long flags;
    unsigned char savemask;
    unsigned int selbits = 0;

    /* Enforce constraints */
    if (freq < 2 || freq > 1024)
    {
        printf("Frequency %d is outside the acceptable range of [2, 1024].\n", freq);
        return -1;
    }

    /* Let's check to see if it's a power of 2 */
    while (freq > (1 << selbits))
        selbits++;

    if (freq != (1 << selbits))
    {
        printf("Frequency %d is not a power of 2.\n", freq);
        return -1; /* Not a power of 2 */
    }

    rtc_freq = freq;
    
    /* Lets set some registers! */
    cli_and_save(flags);
    
    cmos_write(CMOS_IO_SEL, 0xA, 1);
    savemask = cmos_read(CMOS_IO_DATA) & 0xF0;
    savemask |= (16 - selbits);
    cmos_write(CMOS_IO_SEL, 0xA, 1);
    cmos_write(CMOS_IO_DATA, savemask, 0);

    restore_flags(flags);
    sti();

	cmos_write(CMOS_IO_SEL, 0xA, 0); // Re-enables NMI

    return 0;
}

/* Checkpoint 3 Requirements:
 *  (Adapted from the MP3 notes)
 *  - Implement open, read, write, and close functions for the real-time clock
 *    and demonstrate that you can change the clock frequency.
 *  
 *  For the real-time clock, the read system call should always return 0, but only
 *  after an interrupt has occurred (set a flag and wait until the interrupt handler
 *  clears it, then return 0).
 *
 *  The write system call writes data to the terminal or to a device (RTC). In the case
 *  of the real-time clock, the system call should always accept only a 4-byte integer
 *  specifying the interrupt rate in Hz, and should set the rate of periodic interrupts
 *  accordingly.
 * 
 *  The RTC device itself can only generate interrupts at a rate that is a power of 2
 *  (do a parameter check), and only up to 8192 Hz. Your kernel should limit this further
 *  to 1024 Hz -- an operating system shouldn't allow user space programs to generate more
 *  than 1024 interrupts per second by default. 
 *  
 *  Look at drivers/char/rtc.c, include/linux/mc146818rtc.h, and possibly other associated
 *  header files for the macros and port numbers for interfacing with the RTC device.
 * 
 *  Also, see the datasheet at http://courses.ece.uiuc.edu/ece398/references/mc146818.pdf (old)
 *  and http://courses.ece.uiuc.edu/ece398/references/ds12887.pdf (new) for details on registers
 *  and other parameters of the hardware.
 *
 *  Note that you should be using the RTC's Periodic Interrupt function to generate interrupts
 *  at a programmable rate. The RTC interrupt rate should be set to a default value of 2 Hz
 *  (2 interrupts per second) when the real-time clock device is opened, only one program should
 *  be allowed to open the device at any time, and the program should only be allowed to open the
 *  device one (one file descriptor). For simplicity RTC interrupts should remain on at all times.
 * 
 *  The open system call provides access to the file system. The call should find the directory
 *  entry corresponding to the name file, allocate an unused file descriptor, and set up any data
 *  necessary to handle the given type of file (directory, real-time clock device, or regular file).
 *  If the named file does not exist or no descriptors are free, the call returns -1.
 *
 *  The close system call closes the specified file descriptor and makes it available for return from
 *  later calls to open. You should not allow the user to close the default descriptors (0 for input
 *  and 1 for output). Trying to close an invalid descriptor should result in a return value of -1;
 *  successful closes should return 0.
 *
 *  Note that some system calls need to synchronize with interrupt handlers. For example, the read
 *  system call made on the RTC device should wait until the next RTC interrupt has occurred before
 *  it returns. Use simple volatile flag variables to do this synchronization (e.g., something like
 *  int rtc_interrupt_occurred;) when possible (try something more complicated only after everything 
 *  works!), and small critical sections with cli/sti. For example, writing to the RTC should block
 *  interrupts to interact with the device.
 */
