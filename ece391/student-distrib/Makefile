
# Makefile for OS project
# To build, first `make dep`, them `make`. Everything should be automatic.
# Will compile all *.c and *.S files in the current directory.


# Flags to use when compiling, preprocessing, assembling, and linking
CFLAGS 	+= -Wall -fno-builtin -fno-stack-protector -nostdlib
ASFLAGS +=
LDFLAGS += -nostdlib -static
CC=gcc

#If you have any .h files in another directory, add -I<dir> to this line
CPPFLAGS +=-nostdinc -g -Idevices -g -Irtc -g -Ikernel

# This generates the list of source files

 

SRC =  $(wildcard *.S) $(wildcard *.c) $(wildcard devices/*.S) $(wildcard devices/*.c) $(wildcard devices/rtc/*.c) $(wildcard kernel/*.c) $(wildcard calls/*.c)


# This generates the list of .o files. The order matters, boot.o must be first
OBJS  = boot.o
OBJS += $(filter-out boot.o,$(patsubst %.S,%.o,$(filter %.S,$(SRC))))
OBJS += $(patsubst %.c,%.o,$(filter %.c,$(SRC))) 


bootimg: Makefile $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -Ttext=0x400000 -o bootimg
	./debug.sh

dep: Makefile.dep

Makefile.dep: $(SRC)
	$(CC) -MM $(CPPFLAGS) $(SRC) > $@

.PHONY: clean
clean: 
	rm -f *.o Makefile.dep bootimg
	rm -rf ./devices/*.o
	rm -f ./kernel/*.o
	rm -f ./calls/*.o
	rm -f ./devices/rtc/*.o

ifneq ($(MAKECMDGOALS),dep)
ifneq ($(MAKECMDGOALS),clean)
include Makefile.dep
endif
endif
