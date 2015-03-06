/* keyboard.c - Functions to interact with the keyboard
 * vim:ts=4 noexpandtab
 */


#include "keyboard.h"
#include "i8259.h"
#include "../lib.h"
#include "terminal.h"

//This is used to keep track of special modifer keys such as ctrl shift caps lock
//num lock etc.
static uint8_t statemask = 0x00;




#define CTRL     0x01
#define ALT      0x02
#define SHIFT    0x04
#define CAPS     0x08
#define NUMLOCK  0x10
#define SCRLOCK  0x20
		
//This map of post codes was taken from:
//http://www.osdever.net/bkerndev/Docs/keyboard.htm
/* KBDUS means US Keyboard Layout. This is a scancode table
*  used to layout a standard US keyboard. I have left some
*  comments in to give you an idea of what key is what, even
*  though I set it's array index to 0. You can change that to
*  whatever you want using a macro, if you wish! */
 uint8_t kbdus[128] =
	{
		0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
	  '9', '0', '-', '=', '\b',	/* Backspace */
	  '\t',			/* Tab */
	  'q', 'w', 'e', 'r',	/* 19 */
	  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
		0,			/* 29   - Control */
	  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
	 '\'', '`',   0,		/* Left shift */
	 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
	  'm', ',', '.', '/',   0,				/* Right shift */
	  '*',
		0,	/* Alt */
	  ' ',	/* Space bar */
		0,	/* Caps lock */
		0,	/* 59 - F1 key ... > */
		0,   0,   0,   0,   0,   0,   0,   0,
		0,	/* < ... F10 */
		0,	/* 69 - Num lock*/
		0,	/* Scroll Lock */
		0,	/* Home key */
		0,	/* Up Arrow */
		0,	/* Page Up */
	  '-',
		0,	/* Left Arrow */
		0,
		0,	/* Right Arrow */
	  '+',
		0,	/* 79 - End key*/
		0,	/* Down Arrow */
		0,	/* Page Down */
		0,	/* Insert Key */
		0,	/* Delete Key */
		0,   0,   0,
		0,	/* F11 Key */
		0,	/* F12 Key */
		0,	/* All other keys are undefined */
	};

uint8_t shdus[128] =
	{
		0,  27, '!', '@', '#', '$', '%', '^', '&', '*',	/* 9 */
	  '(', ')', '_', '+', '\b',	/* Backspace */
	  '\t',			/* Tab */
	  'q', 'w', 'e', 'r',	/* 19 */
	  't', 'y', 'u', 'i', 'o', 'p', '{', '}', '\n',	/* Enter key */
		0,			/* 29   - Control */
	  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
	 '|', '~',   0,		/* Left shift */
	 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
	  'm', '<', '>', '?',   0,				/* Right shift */
	  '*',
		0,	/* Alt */
	  ' ',	/* Space bar */
		0,	/* Caps lock */
		0,	/* 59 - F1 key ... > */
		0,   0,   0,   0,   0,   0,   0,   0,
		0,	/* < ... F10 */
		0,	/* 69 - Num lock*/
		0,	/* Scroll Lock */
		0,	/* Home key */
		0,	/* Up Arrow */
		0,	/* Page Up */
	  '-',
		0,	/* Left Arrow */
		0,
		0,	/* Right Arrow */
	  '+',
		0,	/* 79 - End key*/
		0,	/* Down Arrow */
		0,	/* Page Down */
		0,	/* Insert Key */
		0,	/* Delete Key */
		0,   0,   0,
		0,	/* F11 Key */
		0,	/* F12 Key */
		0,	/* All other keys are undefined */
	};

/* 
 * keyboard_init(void)
 * This function initializes the keyboard. There is nothing to do except enable
 * irq 1.
 *
 * INPUTS: none.
 * 
 * OUTPUTS: none.
 */
void keyboard_init(void)
{
    enable_irq(1);
}

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
void keyboard_interrupt(uint8_t c)
{
	uint8_t letter;
	if ((c & 0x80)){ //if the MSB is set a key was released.
	/*
	 * Remove the MSB. The MSB is used to signal that a key was released.
	 * This makes it easier to see that these are checking for the same
	 * keys as the statements bellow.
	 */
		c &= 0x7F;
		switch (c){
			case 0x1D:
				statemask &= (~CTRL);
				break;
			case 0x38:
				statemask &= (~ALT);
				break;
			case 0x2A:
				statemask &= (~SHIFT);
				break;
			case 0x36:
				statemask &= (~SHIFT);
				break;
			default:
				break;
		}
    } else {
		switch (c)
		{
			case 0x1D:
				statemask |= CTRL;
				break;
			case 0x38:
				statemask |= ALT;
				break;
			case 0x2A: //left shift
				statemask |= SHIFT;
				break;
			case 0x36: //right shift
				statemask |= SHIFT;
				break;
			case 0x3A:
				if(statemask & CAPS){
					statemask &= (~CAPS);
				}else{
					statemask |= CAPS;
				}
				break;
			case 0x45:
				if(statemask & NUMLOCK){
					statemask &= (~NUMLOCK);
				}else{
					statemask |= NUMLOCK;
				}
				break;
			case 0x46:
				if(statemask & SCRLOCK){
					statemask &= (~SCRLOCK);
				}else{
					statemask |= SCRLOCK;
				}
				break;
			default:
				letter = kbdus[c];
				if (statemask & CTRL){
					if(letter == 'l'){
						clear();
					}
				}else if (statemask & ALT){				
					if((c == 0x3B)&&(currterminal!=1)){
						change_terminal(1);
					}
					if((c == 0x3C)&&(currterminal!=2)){
						change_terminal(2);
					}
					if((c == 0x3D)&&(currterminal!=3)){
						change_terminal(3);
					}					
				}else{ 
					if (!(statemask & SHIFT) != !(statemask & CAPS)){
						if(letter > 0x60 && letter < 0x7B){ 
							letter -= 0x20;
						}else if(letter>0x5A&&letter<0x5E){
							letter+=0x20;
						} else if(letter == 0x2D){
							letter=0x5F;
						}else if(letter == 0x2C || letter == 0x2E){
							letter+=0x10;
						}else if(letter == 0x60){
							letter = 0x7E;
						}else if(letter == 0x3B){
							letter = 0x3A;
						}else{
							letter = shdus[c];
						}
						
					}else if (statemask & SHIFT){
						if(letter>0x5A&&letter<0x5E){
							letter+=0x20;
						} else if(letter == 0x2D){
							letter=0x5F;
						}else if(letter == 0x2C || letter == 0x2E){
							letter+=0x10;
						}else if(letter == 0x60){
							letter = 0x7E;
						}else if(letter == 0x3B){
							letter = 0x3A;
						}else{
							letter = shdus[c];
						}
					}
					terminal_write_to_buffer(letter);
				}
		}
	}
    send_eoi(1);
}
