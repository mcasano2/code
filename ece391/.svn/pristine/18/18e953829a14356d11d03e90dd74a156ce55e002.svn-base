#include "../lib.h"
#include "general.h"
#include "../devices/terminal.h"
#include "../devices/rtc/rtc.h"
#include "execute.h"
#include "control.h"
#include "../kernel/filesys.h"


/* 
 * syscall_handler_finish()
 * This function handles system calls
 *
 * INPUTS: none 
 *
 * OUTPUTS: none
 */
int32_t
syscall_handler_finish()
{
	
	uint32_t call;
	uint32_t arg1;
	uint32_t arg2;
	uint32_t arg3;
	
	asm volatile(
			"movl %%eax, %0;"
			"movl %%ebx, %1;"
			"movl %%ecx, %2;"
			"movl %%edx, %3; \
			" : "=a"(call), "=b"(arg1), "=c"(arg2), "=d"(arg3)
			  : /*no inputs*/
			  : "cc"
	);	
	
	control_block_t * cbptr =(control_block_t *) get_control_ptr();
	
	if(call == WRITE){
		
		return cbptr->files[arg1].funcs->write((void*) arg2,arg3);
	}
	
	if(call == READ){
		return cbptr->files[arg1].funcs->read(arg1,(void*)arg2,arg3);
	}
	
	if(call == EXECUTE){
		uint8_t * file =(uint8_t *) arg1;
		uint8_t * args =(uint8_t *) arg1;
		uint8_t snip=0;
		while(*args != ' ' && *args != '\0'){
			args++;
			snip++;
		}
		if(*args == ' '){
			file[snip] = '\0';
			args++;
		}
		// +1 to get over the next character
		// if the next character is null, there are no args
		while(*args == ' ')
			args++;
		
		return execute(file,args);
	}
	
	if(call == HALT){
		int i;
		for (i = 0; i < 1024; i++){
			cbptr->args[i]='\0';
		}
		cbptr->present=0;
		control_block_t * parent =(control_block_t *) cbptr->parent;
		page_directory_array[32] =(int) parent->thismem; 
		
		
		// This code causes the TLB (transition lookaside buffer) to be flushed.
		// Which is needed because we have just changed one of the entries in the 
		// page directory. 
		// Writing anything to CR3 causes the TLB to be refreshed. Since we are 
		// changing a value in the page directory but not the location of the 
		// page directory, CR3 is read into ebx then ebx is written into CR3.
		asm volatile(
		"pushl %%ebx;"
		"movl %%cr3, %%ebx;"
		"movl %%ebx, %%cr3;"
		"popl %%ebx;	\
		" : /*no outputs*/
		  : /* no inputs*/
		  : "ebx"
		);	
		
		uint32_t esp = cbptr->esp;
		tss.esp0 = parent->thisks; //changed from esp
		tss.ss0 = KERNEL_DS;
		
		asm volatile(
			"movl %0, %%esp;"
			"movl %1, %%eax;"
			"andl $0x000000FF, %%eax;"
			"ret	    ; \
			" : /* no outputs */
			  :"r"(esp), "r"(arg1)
			  : "cc"
		);
	}
	
	if(call == OPEN){
		uint32_t fd = find_open_descriptor(cbptr);
	
		if(fd == -1 ){
			return -1;
		}
		
		cbptr->files[fd].flags = 1;
		cbptr->files[fd].position = 0;
		
		if(strncmp((int8_t*)arg1, "rtc", 3)==0){
			static fileops_t rtc;
			rtc.read = (void*)&rtc_read;
			rtc.write = (void*)&rtc_write;
			cbptr->files[fd].funcs = (void*)&rtc;
			cbptr->files[fd].flags |= 0x6;
			cbptr->files[fd].inode = 0;
			rtc_open();
		} else if(strncmp((int8_t*)arg1, ".", 1)==0) {
			static fileops_t directory;
			directory.read = (void*)&read_directory;
			directory.write = (void*)&write_fs;
			cbptr->files[fd].funcs = (void*)&directory;
			dentry_t entry;
			read_dentry_by_name((uint8_t *)arg1, &entry);
			cbptr->files[fd].inode = 0;
		} else {
			static fileops_t normal;
			normal.read = (void*)&read_fs;
			normal.write = (void*)&write_fs;
			cbptr->files[fd].funcs = &normal;
			dentry_t entry;
			if(read_dentry_by_name((uint8_t *)arg1, &entry) == -1){
				return -1;
			}
			if(entry.file_type == 2){
				cbptr->files[fd].inode = entry.inode;
			}else{
				cbptr->files[fd].inode = 0;
			}
		}
		return fd;
	}
	
	if(call == CLOSE){
		if(arg1 < 2 || arg1 > 7)
			return -1;
		if(cbptr->files[arg1].flags == 0)
			return -1;
		if(cbptr->files[arg1].flags & 0x6){
			rtc_close();
		}
		cbptr->files[arg1].flags = 0;
		return 0;
	}
	
	if(call == VIDMAP){
		uint8_t ** base =(uint8_t **) arg1;
		int i;
		if((int)base<0x08000000 || (int)base > 0x08400000){
			return -1;
		} else {
			for(i = 0; i < 4096; i++){
				*(base + i) = (uint8_t *)(0xB8000 + i);
			}
			return 0;
		}
	}
	
	if(call == GETARGS){
		if(cbptr->argsize+1>arg2){
			return -1;
		}
		strcpy((int8_t *)arg1,(int8_t *)cbptr->args);
		return 0;
	}
	
	if(call == SIGRETURN){
		return -1;
	}
	
	if(call == SET_HANDLER){
		return -1;
	}
	return 0;
}



