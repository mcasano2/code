/* cmos.c - Defines used in interactions with the real-time clock's CMOS
 * vim:ts=4 noexpandtab
 */

#include "cmos.h"
#include "../../lib.h"

/* cmos_write(port, data, disable_nmi)
 * Writes to the designated CMOS port with the data.
 * This function takes disable_nmi and automatically
 * sets the appropriate bit in the CMOS RAM.
 *
 * This function has the dual purpose for allowing 
 * selections of registers as well as writing data
 * to them. When selecting registers, the data parameter
 * is the register to select, in hex. When writing data,
 * the data parameter is the 8-bit data to write.
 *
 * When writing data, the disable_nmi parameter should always
 * be 0.
 *
 * INPUT:  port - the CMOS port to write to
 *		   data - the data to write to the port
 *		   disable_nmi - whether we should disable NMIs while
 *		                 selecting a register
 * OUTPUT: void
 */
void cmos_write(char port, char data, char disable_nmi)
{
    unsigned long flags;
    cli_and_save(flags);

    outb(((disable_nmi) ? (1 << 7) : 0) | data, port);

    restore_flags(flags);
    sti();
}

/* cmos_read(port)
 * Reads in the data from the described port, and returns it in char.
 * This function needs to be called in conjunction with cmos_write()
 * to select the register to read from. Although programmers will most
 * likely not read from the CMOS_IO_SEL port, this function is abstracted
 * in case we want to use it in the future.
 *
 * INPUT:  port - the port to select in the CMOS
 * OUTPUT: char - the 8-bit value read from the port and register.
 */
char cmos_read(char port)
{
    char tmp;
    unsigned long flags;
    cli_and_save(flags);

    tmp = inb(port);

    restore_flags(flags);
    sti();

    return tmp;
}
