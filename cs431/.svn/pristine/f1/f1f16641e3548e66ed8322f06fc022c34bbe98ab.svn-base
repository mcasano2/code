//
// CS 431 - Lab 03 Server Skeleton
// PC/Linux (Provided)
//

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "pc_crc16.h"
#include "lab03.h"
#include <inttypes.h>
#include <string.h>

typedef struct __attribute__((__packed__)) tpacket {
  char startbyte;
  uint16_t crc;
  char length;
} tpacket;

void rev_crc(uint16_t crc, uint16_t * revcrc);

int main(int argc, char* argv[])
{
	double troll_pct=0;		// Perturbation % for the troll (if needed)
	int ifd,ofd,i,N,troll=0;	// Input and Output file descriptors (serial/troll)
	char str[MSG_BYTES_MSG],opt;	// String input
	struct termios oldtio, tio;	// Serial configuration parameters
	int VERBOSE = 0;		// Verbose output - can be overriden with -v

	// Command line options
	while ((opt = getopt(argc, argv, "t:v")) != -1) {
		switch (opt) {
			case 't':	troll = 1; 
					troll_pct = atof(optarg);
					break;
			case 'v':	VERBOSE = 1; break;
			default: 	break;
		}
	}

	printf("CS431 - Lab 03 Server\n(Enter a message to send.  Type \"quit\" to exit)\n");
	

       

	//
	// WRITTEN: Open the serial port (/dev/ttyS0) read-write
	//
	
	//FILE * ifdFILE = fopen("/dev/ttyS0", "rw");
	//perror(NULL);
	ifd = open("/dev/ttyS0", O_RDWR | O_NOCTTY); //fileno(ifdFILE);	

	if(ifd < 0)
	{
	  printf("Couldn't open /dev/ttyS0\n");
	  exit (1);
	}

	// Start the troll if necessary
	if (troll)
	{
	  // Open troll process (lab03_troll) for output only
	  FILE * pfile;		// Process FILE for troll (used locally only)
	  char cmd[128];		// Shell command
	  
	  snprintf(cmd, 128, "./lab03_troll -p%f %s", troll_pct, (VERBOSE) ? "-v" : "");
	  
	  pfile = popen(cmd, "w");
	  if (!pfile) { perror("lab03_troll"); exit(-1); }
	  ofd = fileno(pfile);
	}
	else ofd = ifd;		// Use the serial port for both input and output
	
	

	//
 	// WRITTEN: Set up the serial port parameters and data format
	//
	
	struct termios backup;
	struct termios tty_settings;
	tcgetattr(ifd, &backup);
	

	//cfsetospeed(&tty_settings, B9600);       //Set Baud.
	tty_settings.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
	tty_settings.c_iflag = 0;
	tty_settings.c_oflag = 0;
	tty_settings.c_lflag = 0;

	tcflush(ifd, TCIFLUSH);
	tcsetattr(ifd, TCSANOW, &tty_settings);



	while(1)
	{

	  //
	  // WRITTEN: Read a line of input (Hint: use fgetc(stdin) to read each character)
	  //
	  
	  int headerLength = 4;
	  char buffer[260];
	  char * str = buffer + headerLength;
	  int i = 0;
	  while((str[i++] = fgetc(stdin)) != '\n' && i <= 255);	  
	  
	  // Make sure we have a null terminator.
	  if(str[i-1] == '\n')
	    str[i-1] = 0; 
	  else
	    str[i] = 0;

	  if (strcmp(str, "quit") == 0) break;

	  //
	  // WRITTEN: Compute crc (only lowest 16 bits are returned)
	  //
	  
	  size_t length = strlen(str);

	  uint16_t crc = pc_crc16(str, length);

	  char ack = 0;
	  int attempts = 0;
	
	  while (!ack)
	  {
	    printf("Sending (attempt %d)...\n", ++attempts);
	    
	    
	    // 
	    // WRITTEN: Send message
	    //
	    tpacket * t = (tpacket *)buffer;
	    t->startbyte = 0x00;
	    t->crc = htons(crc);
	    t->length = length;
	    
	    //Check for off-by-one error. Might be length + 4.
	    size_t x = write(ofd, buffer, length + headerLength);	    
	   
	    printf("Wrote %lu bytes, & CRC: %X\n", x, crc);
	    printf("Message sent, waiting for ack... ");
	    
			
	    //
	    // WRITTEN: Wait for MSG_ACK or MSG_NACK
	    //
	    read(ifd, &ack, 1); 

	    printf("%s\n", ack ? "ACK" : "NACK, resending");
	  }
	  printf("\n");
	}



	//
	// WRITTEN: Reset the serial port parameters
	//
	tcsetattr(ifd, TCSANOW, &backup);


	// Close the serial port
	close(ifd);
	
	return 0;
}
