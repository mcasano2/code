#include "control.h"

int32_t find_open_descriptor(control_block_t * cb)
{
	int i;
	for(i=2; i<7; i++){
		if(cb->files[i].flags==0){
			return i;
		}
	}
	return -1;
}

