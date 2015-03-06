#ifndef _EXECUTE_H
#define _EXECUTE_H

#include "../types.h"
#include "../x86_desc.h"
#include "../kernel/filesys.h"
#include "control.h"
#include "../devices/terminal.h"

// These are the addresses of the controll block for each task.
#define TCB0 0x007FF000
#define TCB1 0x007FD000
#define TCB2 0x007FB000
#define TCB3 0x007F9000
#define TCB4 0x007F7000
#define TCB5 0x007F5000
#define TCB6 0x007F3000

//These are the addresses of the bottom of the kernel stack for each task.
#define TKS1 0x007FDFF0
#define TKS2 0x007FBFF0
#define TKS3 0x007F9FF0
#define TKS4 0x007F7FF0
#define TKS5 0x007F5FF0
#define TKS6 0x007F3FF0
#define TKS7 0x007F1FF0

//These are the physical memory addresses that each task should be copied to.
#define MB8 0x00800087
#define MB12 0x00C00087
#define MB16 0x01000087
#define MB20 0x01400087
#define MB24 0x01800087
#define MB28 0x01C00087
#define MB32 0x02000087


/* 
 * load(uint8_t * file, control_block_t * CBptr)
 * This function loads a program into memory, and then returns the start 
 * address of the program.
 *
 * INPUTS: file: The program to be loaded
 * CBptr: a pointer to the current control block 
 *
 * OUTPUTS: the address to jump into.
 */
int32_t load(uint8_t * file, control_block_t * CBptr);

/* 
 * execute(const uint8_t * command, const uint8_t * args)
 * This function is used to execute a new program
 *
 * INPUTS: command: The file name of the program to launch
 * args: The arguments of the new program
 *
 * OUTPUTS: 0 on success
 *          -1 on failure
 */
int32_t execute(const uint8_t * command, const uint8_t * args);

/* 
 * get_control_ptr()
 * This is used to fine the control block from the kernel stack of the current task
 *
 * INPUTS: none
 *
 * OUTPUTS: The address of the control block
 */
uint32_t get_control_ptr();

/* 
 * fill_control_block(control_block_t * cb, uint8_t * args, control_block_t * parent)
 * This function fills the control block of the new task being started.
 *
 * INPUTS: cb: A pointer to the control block of the new task
 * args: The arguments of the new task
 * parent: A pointer to the control block of the task that started this task
 *
 * OUTPUTS: 0 on success
 *          -1 on failure
 */
void  fill_control_block(control_block_t * cb, uint8_t * args, control_block_t * parent);


/* 
 * find_available_task()
 * This function finds an empty process control block that should beused to launch a new task
 *
 * INPUTS: none
 *
 * OUTPUTS: A pointer to the control block to use.
 *			NULL if all control blocks are in use.
 */
control_block_t * find_available_task();

/* 
 * invalid()
 * This function simply returns -1
 * This is the function that is called for a read on stdout or a write to stdin.
 *
 * INPUTS: none
 *
 * OUTPUTS: -1
 */
int32_t invalid();
#endif
