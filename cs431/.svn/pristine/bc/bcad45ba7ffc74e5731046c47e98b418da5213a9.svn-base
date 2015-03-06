SERVER = lab04
SERVER_OBJS = $(SERVER).o\
	      linuxanalog.o

CC = gcc
CFLAGS = -I.. -g -Wall -lrt

all: $(SERVER)

# Server (PC)
$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(SERVER)
