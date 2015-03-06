#include "../lib.h"
#include "execute.h"
#include "../devices/terminal.h"

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
int32_t
load(uint8_t * file, control_block_t * CBptr)
{
	uint8_t data[70000];
	dentry_t entry;
	if(read_dentry_by_name(file, &entry)==-1){
		return -1;
	}
	uint32_t size = read_data(entry.inode,0,data, 70000);
	
	//check for magic numbers
	if(!(data[0]==0x7f && data[1]==0x45 && data[2]==0x4c && data[3]==0x46)){
		return -1;
	}
	
	
	
	page_directory_array[32] =(int)CBptr->thismem;
	
	asm volatile(
			"pushl %%ebx;"
			"movl %%cr3, %%ebx;"
			"movl %%ebx, %%cr3;"
			"popl %%ebx;	\
			" : /*no outputs*/
			  : /* no inputs*/
			  : "ebx"
	);	
	
	memcpy((void*)0x08048000, data, size);
	return (data[27]<<24)+(data[26]<<16)+(data[25]<<8)+data[24];
}


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
int32_t
execute(const uint8_t * command, const uint8_t * args)
{
	uint8_t safeargs[strlen((int8_t *)args)+1];
	strcpy((int8_t *)safeargs,(int8_t *)args);
	uint32_t  CBptr = get_control_ptr();
	
	control_block_t * cbp = find_available_task();
	
	if(cbp==NULL){
		return -1;
	}
	
	uint32_t address =(uint32_t) load((uint8_t *)command,cbp);

	int32_t retvalue;
	if(address == -1){
		cbp->present=0;
		return -1;
	}
	
	tss.esp0 = cbp->thisks;
	tss.ss0 = KERNEL_DS;
	
	
	
	//control_block_t * cb =(control_block_t *) (tss.esp0 & 0x007FF000);
	fill_control_block(cbp, safeargs, (control_block_t *)CBptr);
	uint32_t esp;
	
	
	asm volatile(
			"pushfl;"
			"pushl %%ebp;"
			"pushl $1f;"
			"movl %%esp, %0; \
			" : "=r"(esp)
			  : /*no in*/
			  : "cc"
	);

	cbp->esp = esp;
	
	asm volatile(
			"movl  %4, %%esp;"
			"movl %1, %%ecx;"
			"movw %%cx, %%ds;"
			"movw %%cx, %%es;"
			"movw %%cx, %%fs;"
			"movw %%cx, %%gs;"
			"pushl %%ecx;"
			"pushl $0x083FFFF0;" //bottom of the 4MB page starting at 128MB
			"pushfl;"
			"pushl %2;"
			"pushl %3;"
			"iret			  ;"		
			"1:\t"
			"popl %%ebp;"
			"popfl;"
			"movl %%eax, %0;\
			" : "=a"(retvalue)
			  : "r"(0x0000FFFF&USER_DS), "r"(0x0000FFFF&USER_CS), "r"(address), "r"(tss.esp0)
			  : "%ecx"
	);	

	return retvalue;
}


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
void 
fill_control_block(control_block_t * cb, uint8_t * args, control_block_t * parent)
{
	cb->argsize=(uint8_t)strlen((int8_t *)args);
	memcpy(cb->args,args,cb->argsize+1);
	
	//cb->parentmem=page_directory_array[32]-0x400000;
	//cb->parentesp0=tss.esp0+0x2000;
	cb->parent= (uint32_t)parent;
	static fileops_t stdout;
	stdout.write = (void *)&terminal_write;
	stdout.read = &invalid;
	
	static fileops_t stdin;
	stdin.write = &invalid;
	stdin.read = &terminal_read_wrapper;
	
	cb->files[0].inode = 0;
	cb->files[0].position = 0;
	cb->files[0].flags = 1;
	cb->files[0].funcs = &stdin;
	
	cb->files[1].inode = 0;
	cb->files[1].position = 0;
	cb->files[1].flags = 1;
	cb->files[1].funcs = &stdout;
	int i;
	
	for( i = 2; i<8; i++){
		cb->files[i].flags=0;
	}
}

/* 
 * get_control_ptr()
 * This is used to fine the control block from the kernel stack of the current task
 *
 * INPUTS: none
 *
 * OUTPUTS: The address of the control block
 */
uint32_t
get_control_ptr()
{
	uint32_t top_of_stack = -1;
	asm volatile(
			"movl %%esp, %%eax;"
			"andl $0x007FF000, %%eax;"
			"movl %%eax, %0			  ;\
			" : "=r"(top_of_stack)
			  : /*no inputs */
			  : "eax"
	);

	return top_of_stack;
}


/* 
 * invalid()
 * This function simply returns -1
 * This is the function that is called for a read on stdout or a write to stdin.
 *
 * INPUTS: none
 *
 * OUTPUTS: -1
 */
int32_t
invalid()
{
	return -1;
}

/* 
 * find_available_task()
 * This function finds an empty process control block that should beused to launch a new task
 *
 * INPUTS: none
 *
 * OUTPUTS: A pointer to the control block to use.
 *			NULL if all control blocks are in use.
 */
control_block_t *
find_available_task(){
	control_block_t * cb = (control_block_t *) TCB1;
	if(cb->present==0){
		cb->present=1;
		return cb;
	}
	cb = (control_block_t *) TCB2;
	if(cb->present==0){
		cb->present=1;
		return cb;
	}
	cb = (control_block_t *) TCB3;
	if(cb->present==0){
		cb->present=1;
		return cb;
	}
	cb = (control_block_t *) TCB4;
	if(cb->present==0){
		cb->present=1;
		return cb;
	}
	cb = (control_block_t *) TCB5;
	if(cb->present==0){
		cb->present=1;
		return cb;
	}
	cb = (control_block_t *) TCB6;
	if(cb->present==0){
		cb->present=1;
		return cb;
	}

	return NULL;


}

