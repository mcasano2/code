/* keyboard.h - Defines used in interactions with the keyboard
 * vim:ts=4 noexpandtab
 */

#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "../types.h"


/* 
 * keyboard_init(void)
 * This function initializes the keyboard. There is nothing to do except enable
 * irq 1.
 *
 * INPUTS: none.
 * 
 * OUTPUTS: none.
 */
void keyboard_init(void);

/* 
 * keyboard_interrupt(uint8_t c)
 * This function handle the interrupts generated from the keyboard.
 * The beginning of the keyboard interrupt handler is in x86_desc.S.
 *
 * INPUTS: c: This is the 8 bit scan code of the key that was pressed or released.
 * If the MSB of the scan code is 1 then the key was released.
 * 
 * OUTPUTS: none.
 */
void keyboard_interrupt(uint8_t c);

#endif  /*_KEYBOARD_H*/
