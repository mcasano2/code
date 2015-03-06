/* rtc.h - Defines used in interactions with the real-time clock
 * vim:ts=4 noexpandtab
 */

#ifndef _RTC_H
#define _RTC_H

#include "../../types.h"

/* Externally-visible functions */

/* Initialize both PICs */
void rtc_init(void);
/* Handle RTC interrupts */
void rtc_interrupt(void);

/* File Operations */
int rtc_open(void);
int rtc_write(int32_t *freq, int32_t nbytes);
int rtc_read(void);
int rtc_close(void);

#endif /* _RTC_H */
