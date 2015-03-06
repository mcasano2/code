/* nmi.c - Coordinates interacts with NMI
 * vim:ts=4 noexpandtab
 */

#include "nmi.h"
#include "lib.h"

void nmi_enable(void)
{
    outb(0x70, inb(0x70)&0x7F);
}
 
void nmi_disable(void)
{
    outb(0x70, inb(0x70)|0x80);
}
