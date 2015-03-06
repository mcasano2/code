#ifndef _CALLS_H
#define _CALLS_H

#include "../types.h"
#include "../x86_desc.h"

#define HALT 1
#define EXECUTE 2
#define READ 3
#define WRITE 4
#define OPEN 5
#define CLOSE 6
#define GETARGS 7
#define VIDMAP 8
#define SET_HANDLER 9
#define SIGRETURN 10


/* 
 * syscall_handler_finish()
 * This function handles system calls
 *
 * INPUTS: none 
 *
 * OUTPUTS: none
 */
int32_t syscall_handler_finish();



#endif
