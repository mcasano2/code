/* i8259.c - Functions to interact with the 8259 interrupt controller
 * vim:ts=4 noexpandtab
 */

#include "i8259.h"
#include "../lib.h"

/* Interrupt masks to determine which interrupts
 * are enabled and disabled */
uint8_t master_mask; /* IRQs 0-7 */
uint8_t slave_mask; /* IRQs 8-15 */

uint32_t cached_irq_mask = 0xffff;
#define __byte(x, y)       (((unsigned char *)&(y))[x])
#define cached_master_mask (__byte(0, cached_irq_mask))
#define cached_slave_mask  (__byte(1, cached_irq_mask))

/* Initialize the 8259 PIC */
void
i8259_init(void)
{
	unsigned long flags;
    
    cli_and_save(flags);
    
	master_mask = 0xff;
	slave_mask = 0xff;
    outb(master_mask, MASTER_8259_DATA); /* Mask out all of master */
    outb(slave_mask, SLAVE_8259_DATA); /* Mask out all of slave */
    
    /* ICW1: Start Master Init */
    outb(ICW1, MASTER_8259_PORT);
    /* ICW2 */
    outb(ICW2_MASTER, MASTER_8259_DATA);
    /* IC3 */
    outb(ICW3_MASTER, MASTER_8259_DATA);
    /* IC4 */
    outb(ICW4, MASTER_8259_DATA);
    /* ICW1: Start Slave Init */
    outb(ICW1, SLAVE_8259_PORT);
    /* ICW2 */
    outb(ICW2_SLAVE, SLAVE_8259_DATA);
    /* IC3 */
    outb(ICW3_SLAVE, SLAVE_8259_DATA);
    /* IC4 */
    outb(ICW4, SLAVE_8259_DATA);
    
    /* Restore master and slave IRQ masks */
    outb(master_mask, MASTER_8259_DATA); /* Mask out all of master */
    outb(slave_mask, SLAVE_8259_DATA); /* Mask out all of slave */
	
	
    restore_flags(flags);
    //sti();
}

/* Enable (unmask) the specified IRQ */
void
enable_irq(uint32_t irq_num)
{
	uint32_t mask = ~(1 << irq_num); /* Create IRQ mask  ~ is bitwise not*/ 
	unsigned long flags;
	
	cli_and_save(flags); /* Clear interrupt flags and save EFLAGs */
	
	cached_irq_mask &= mask;
	if (irq_num & 8){ /* Check destination */
		slave_mask = inb(SLAVE_8259_DATA);
		mask = mask >> 8;
		slave_mask &= mask;
		master_mask = inb(MASTER_8259_DATA);
		master_mask &= 0xFB;
		outb(slave_mask, SLAVE_8259_DATA); /* Write to slave pic */
		outb(master_mask,  MASTER_8259_DATA);
	} else {
		master_mask = inb(MASTER_8259_DATA);
		master_mask &= mask;
		outb(master_mask, MASTER_8259_DATA); /* Write to master pic */
	}
	restore_flags(flags); /* Restore EFLAGS */
	sti(); /* Restore interrupt flags */
}

/* Disable (mask) the specified IRQ */
void
disable_irq(uint32_t irq_num)
{
	uint32_t mask = 1 << irq_num; /* Create IRQ mask */
	unsigned long flags;

	cli_and_save(flags); /* Clear interrupt flags and save EFLAGs */
	if (irq_num & 8){ /* Check destination */
		mask = mask >> 8;
		slave_mask = inb(SLAVE_8259_DATA);
		slave_mask |= mask;
		outb(slave_mask, SLAVE_8259_DATA); /* Write to slave pic */
	} else{
		master_mask = inb(MASTER_8259_DATA);
		master_mask |= mask;
		outb(cached_master_mask, MASTER_8259_DATA); /* Write to master pic */
	}
	restore_flags(flags); /* Restore EFlags */
	sti(); /* Restore interrupt flags */
}

/* Send end-of-interrupt signal for the specified IRQ */
void
send_eoi(uint32_t irq_num)
{
    uint32_t mask = 1 << irq_num;
    unsigned long flags;
    
    cli_and_save(flags); /* Clear interrupt flags and save EFLAGs */
    
    cached_irq_mask |= mask;
    
    if (irq_num & 8) /* Check destination */
    {
        /* EOI to slave */
        outb(EOI+(irq_num&7), SLAVE_8259_PORT); /* Specific EOI to slave */
        outb(EOI+2, MASTER_8259_PORT); /* Specific EOI to master */
    }
    else
    {
        /* EOI to master */
        outb(EOI+irq_num, MASTER_8259_PORT); /* Specific EOI to master */
    }
    
    restore_flags(flags);
    sti();
}

