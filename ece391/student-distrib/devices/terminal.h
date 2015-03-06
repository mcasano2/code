#ifndef _TERMINAL_H
#define _TERMINAL_H

#include "../types.h"


extern uint32_t currterminal;

/* 
 * terminal_open(void)
 * Initializes the terminal driver buffer.
 *
 * INPUTS:  none
 * OUTPUTS: 0 - System calls return 0 for success
 */
int terminal_open();

/* 
 * terminal_read(uint32_t * count)
 * This initializes the buffer. - Characters typed before the read
 * syscall should not be returned in the buffer.
 *
 * INPUTS: count: pointer to a 32 bit unsigned int. This will contain the
 * number of letters in the buffer when the call returns.
 * This is not necessarrily the same thing as the size of the buffer.
 * 
 * OUTPUTS: pointer to the character buffer.
 * Because the pointer returned is in kernel memory this needs to
 * be copied to user memory in the system call handler.
 */
uint8_t * terminal_read(uint32_t * count);


/* 
 * terminal_read_wrapper(int32_t fd, void * buffer, int32_t nbytes)
 * This function is used to access the terminal_read function through a system call.
 * This was needed because the initial terminal_read wars written without too much concern
 * for how system calls work. In order to reduce the number of code locations to debug 
 * this was added instead of modifying the original function.
 *
 * INPUTS: fd: The file descriptor so read from. (this isn't actually used)
 * buffer: The location to copy the input to 
 * nbytes: The size of the buffer that is being read into
 *
 * OUTPUTS: The number of bytes used in the buffer.
 */
int32_t terminal_read_wrapper(int32_t fd, void * buffer, int32_t size);

/* 
 * terminal_write(uint32_t * count)
 * This writes a buffer to the terminal. This function does not check for 
 * NULL characters. This is useful if you want to output a hex dump to 
 * the terminal.
 *
 * INPUTS: buf: pointer to the buffer that should be written to the terminal.
 * size: the number of characters in the buffer. 
 * 
 * OUTPUTS: The number of characters written to the terminal.
 */
int32_t terminal_write(uint8_t * buf, uint16_t size);

/* 
 * terminal_write_to_buffer(uint8_t c)
 * This is used to write a single character in the terminal buffer.
 * This function is called from the keyboard interupt handler.
 *
 * INPUTS: c: The character that should be put in the buffer.
 * 
 * OUTPUTS: none.
 */
void terminal_write_to_buffer(uint8_t c);

//taken from http://wiki.osdev.org/Text_Mode_Cursor and converted to AT&T syntax
//details are at http://www.osdever.net/FreeVGA/vga/crtcreg.htm#0F
/* 
 * update_cursor(uint8_t col, uint8_t row)
 * This function updates the position of the cursor on the terminal.
 *
 * INPUTS: col: The new column position of the cursor
 * row: The new row position of the cursor 
 *
 * OUTPUTS: none.
 */
void update_cursor(uint8_t row, uint8_t col);

/* 
 * change_terminal(int32_t dest)
 * This function is used for chenging which terminal is in use
 *
 * INPUTS: dest: This is the number of the terminal that is being switched to.
 *
 * OUTPUTS: none
 */
 int32_t change_terminal(int32_t dest);

#endif
