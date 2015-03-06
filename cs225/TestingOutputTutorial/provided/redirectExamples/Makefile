#*****************************************************
#  CS225 General Makefile
#
#  File originally written by Matt Buchanan in Fall 1995
#
#*****************************************************


#**************************************************************************
# List of .o files that EXENAME depends on.  Edit as appropriate for MP.

OBJS = \
	asserts.o string.o clock.o main.o


#**************************************************************************
# Change this line if you don't like 'a.out'.

EXENAME = example 


#**************************************************************************
# Macros defining the C/C++ compiler and linker.

CC = g++
CCOPTS = -g 
LINK = g++
LINKOPTS = -o $(EXENAME)


#**************************************************************************
# Rules for building EXENAME from OBJS and OBJS from your source.

$(EXENAME):  $(OBJS)
	$(LINK) $(LINKOPTS) $(OBJS)

clean:
	-rm *.o $(EXENAME)

asserts.o : asserts.h asserts.cpp
	$(CC) -c $(CCOPTS) asserts.cpp

string.o : string.h string.cpp asserts.h
	$(CC) -c $(CCOPTS) string.cpp

clock.o : clock.h clock.cpp string.h
	$(CC) -c $(CCOPTS) clock.cpp

main.o : main.cpp asserts.h string.h clock.h 
	$(CC) -c $(CCOPTS) main.cpp



