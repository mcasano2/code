/* cmos.h - Defines used in interactions with the real-time clock's CMOS
 * vim:ts=4 noexpandtab
 */

#ifndef _CMOS_H
#define _CMOS_H

/* Externally-visible declarations/variables */
#define CMOS_IO_SEL         0x70
#define CMOS_IO_DATA        0x71

/* RTC CMOS Registers */
#define CMOS_RTCR_SECONDS   0x00
#define CMOS_RTCR_MINUTES   0x02
#define CMOS_RTCR_HOURS     0x04
#define CMOS_RTCR_WEEKDAY   0x06
#define CMOS_RTCR_DAYOFMTH  0x07
#define CMOS_RTCR_MONTH     0x08
#define CMOS_RTCR_YEAR      0x09
#define CMOS_RTCR_CENTURY   0x32

/* Externally-visible functions */
void cmos_write(char port, char data, char disable_nmi);

char cmos_read(char port);


#endif /* _CMOS_H */
