#ifndef _CONTROL_H
#define _CONTROL_H

#include "../types.h"
#include "../x86_desc.h"
#include "../devices/terminal.h"

typedef struct fileops {
	int32_t (*read)(int32_t fd, void* buf, int32_t nbytes);
	int32_t (*write)(void* buf, int32_t nbytes);
} fileops_t;

typedef struct file {
	fileops_t * funcs;
	uint32_t inode;
	uint32_t position;
	uint32_t flags;
} file_t;

typedef struct control_block {
	uint8_t args[1024];
	uint8_t argsize;
	uint32_t parentmem;
	uint32_t parentesp0;
	uint32_t thismem;
	uint32_t thisks;
	uint32_t esp;
	uint32_t realesp;
	int8_t present;
	file_t files[8];
	uint32_t parent;
} control_block_t;


int32_t
find_open_descriptor(control_block_t * cb);

#endif
