#ifndef _FILESYS_H
#define _FILESYS_H

#include "../types.h"
#include "../x86_desc.h"


int32_t read_dentry_by_name (const uint8_t* fname, dentry_t* dentry);
int32_t read_dentry_by_index (uint32_t index, dentry_t* dentry);
int32_t read_data (uint32_t inode, uint32_t offset, uint8_t* buf, uint32_t length);

int32_t read_directory(int32_t fd, void * buffer, int32_t nbytes);
uint32_t write_fs();
uint32_t open_fs(uint32_t * boot_block);
uint32_t read_fs();

#endif
