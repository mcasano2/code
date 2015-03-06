#include "../lib.h"
#include "filesys.h"
#include "../calls/execute.h"



int32_t
read_dentry_by_name (const uint8_t* fname, dentry_t* dentry)
{
	uint32_t num_dentry, namelength, bytesmatch, i, arglength;
	uint32_t *dentry_ptr;
	uint8_t name_temp[32]; 
	num_dentry= (uint32_t)*(boot_block_ptr);
	dentry_ptr=boot_block_ptr+16;
	for (i=0; i<num_dentry; i++)
	{
		memcpy(name_temp,dentry_ptr,32); /* copy file name into array */
		if(name_temp[31] =='\0'){
			namelength=strlen((int8_t*)name_temp); //changed from fname
		} else {
			namelength = 32;
		}
		bytesmatch=strncmp((int8_t*)name_temp,(int8_t*)fname,(int32_t)namelength);
		if (bytesmatch==0)
		{
			arglength = strlen((int8_t*)fname);
			if(namelength<arglength){
				return -1;
			}
			memcpy(dentry,dentry_ptr,64); /* copy current data entry */
										  /* into dentry pointer */
			return 0;							  
		}
		dentry_ptr += 16;
	}
	return -1;	
}

int32_t
read_dentry_by_index (uint32_t index, dentry_t* dentry)
{
	uint32_t num_dentry, i;
	uint32_t *dentry_ptr;
	num_dentry= (uint32_t)*(boot_block_ptr);
	dentry_ptr=boot_block_ptr+16;
	for (i=0; i<num_dentry; i++)
	{
		if (i==index)
		{
			memcpy(dentry,dentry_ptr,64); /* copy current data entry */
										  /* into dentry pointer */
			return 0;							  
		}
		dentry_ptr += 16;
	}
	return -1;	
}

int32_t
read_data (uint32_t inode, uint32_t offset, uint8_t* buf, uint32_t length)
{
	uint32_t num_inode, num_dblock, i, bytes_length, curr_dblock;
	uint32_t *dblock_ptr;
	uint8_t *data;
	num_inode= (uint32_t)*(boot_block_ptr+1);
	num_dblock= (uint32_t)*(boot_block_ptr+2);
	if ( (inode<0)||(inode>=num_inode) )
		return -1;
	dblock_ptr=boot_block_ptr+1024+(1024*inode);
	bytes_length=(uint32_t)*(dblock_ptr);
	for (i=offset; i<bytes_length; i++)
	{
		if (i>=(length+offset))
			return i-offset;
		dblock_ptr=boot_block_ptr+1024+(1024*inode)+1+(i)/4096+(i)/4190208;
		curr_dblock=(uint32_t)*(dblock_ptr);
		if ((curr_dblock<0)||(curr_dblock>=num_dblock))
			return -1;
		dblock_ptr=boot_block_ptr+1024+(1024*num_inode)+(1024*curr_dblock);
		data=(uint8_t*)dblock_ptr;
		memcpy(&buf[i-offset],&data[i%4096],1);
	}
	return i-offset;
}


uint32_t
open_fs(uint32_t * boot_block)
{
	return 0;
}

uint32_t
read_fs(int32_t fd, void* buf, int32_t nbytes)
{
	control_block_t * cbptr =(control_block_t *) get_control_ptr();
	uint32_t nbytesread, num_dentry, bytes_length;
	uint32_t *dblock_ptr;
	
	dblock_ptr=boot_block_ptr+1024+(1024*cbptr->files[fd].inode);
	bytes_length=(uint32_t)*(dblock_ptr);
	
	num_dentry= (uint32_t)*(boot_block_ptr);
	if (cbptr->files[fd].position>=bytes_length)
		return 0;
	
	
	nbytesread=read_data(cbptr->files[fd].inode,cbptr->files[fd].position,buf,(uint32_t)nbytes);
	cbptr->files[fd].position+=nbytesread;
	return nbytesread;
	
}

uint32_t
write_fs()
{
	return -1;
}

int32_t
read_directory(int32_t fd, void * buffer, int32_t nbytes)
{
	control_block_t * cbptr =(control_block_t *) get_control_ptr();
	uint32_t num_dentry;
	uint32_t *dentry_ptr;
	num_dentry= (uint32_t)*(boot_block_ptr);
	if(cbptr->files[fd].position>=num_dentry-1){
		return 0;
	}
	dentry_ptr=boot_block_ptr+32+(16*(cbptr->files[fd].position));
	cbptr->files[fd].position++;
	memcpy(buffer,dentry_ptr,32); /* copy file name into array */
	return 32;
	
}
