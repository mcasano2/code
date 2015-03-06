#**********************************************************
#    MP1 Makefile
#**********************************************************

#**********************************************************
#  Macros
#   - These are simply variables that enable us to use
#       shorthand for certain commands or filenames.
#
#   - We use these later by using this syntax: $(COMPILER),
#       for example, for the COMPILER macro
#

# Name of the program
NAME_OF_EXECUTABLE_FILE = mp1

# We're using gcc for our compiling and linking
# Default options
COMPILER = g++
COMPILER_OPTS = -c

# We can define macros using other macros
LINKER = g++
LINKER_OPTS = -o $(NAME_OF_EXECUTABLE_FILE)

# Object list
#   - In general, we will create an object file for every
#       .cpp file we have. These contain machine code
#       compiled from our source files, and will be
#       "linked" together to make our final program

OBJS = EasyBMP.o main.o

#  End of macros
#**********************************************************

#**********************************************************
#  Linking rule
#   - This is what takes all of our object files and links
#       them together into one executable.
#
#   - The format for rules is:
#       filename : dependencies
#       	command line to run
#
#   - Note that we MUST USE *ACTUAL* TABS
#   
#   - This can use macros.
#
#   - "dependencies" are the files we need for this command
#       to work
#
#   - In this case, the command line to run will do the
#       linking of the object files we created
#

$(NAME_OF_EXECUTABLE_FILE) : $(OBJS)
	$(LINKER) $(LINKER_OPTS) $(OBJS)

#
#  End linking rule
#**********************************************************

#**********************************************************
#  Compiling rules for each object file
#   
#   - This is the same format as the linking rule above
#   

EasyBMP.o : EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h \
        EasyBMP_VariousBMPutilities.h EasyBMP.cpp
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

main.o : main.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp

#
#  End compilation rules for objects
#**********************************************************

#**********************************************************
#  Clean rule
#
#   - run when using "make clean"
#   - deletes all files with extension .o and the
#       executable file
#

clean:
	-rm *.o $(NAME_OF_EXECUTABLE_FILE)

#
#  End clean rule
#**********************************************************
