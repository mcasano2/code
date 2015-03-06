// ***********************************************************
// *                                                         *
// *  clock.h                                                *
// *                                                         *
// *  Interface for a class representing a clock             *
// *                                                         *
// *  Written August 2001 by Jason Zych                      *
// *                                                         *
// ***********************************************************

#ifndef _CLOCK_H
#define _CLOCK_H

#include "string.h"

class Clock
{
public:

   // Clock
   //    - constructor
   //    - parameters : thePlace - name of clock location 
   //    - initializes clock to 12:00 AM and parameter location
   Clock(String thePlace);

   
   // PrintClock
   //    - prints the current time and clock location
   void PrintClock();


   // IncrementOneMinute
   //    - moves time forward one minute.  
   void IncrementOneMinute();
  

   // Convert24HourTime
   //    - parameters : hour24format - an hour of a time in 24-hour-time 
   //                                    format
   //                 : minutes24format - the minutes of a time in 
   //                                    24-hour-time format
   //    - return type : boolean integer indicating whether parameters
   //                      formed legal time
   //    - if parameters represent a legal time in 24-hour-time format,
   //        set clock to equivalent time in AM/PM format and return 1.
   //        Otherwise, don't change clock values at all, and return 0.
   int Convert24HourTime(int hour24format, int minutes24format);
 
 
   // SetTime()
   //    - prompts the user to enter hour, minute, and AM/PM
   //      values used to reset the time. If any value entered 
   //      that is not a valid input, the user will be 
   //      re-prompted until acceptable data is entered. 
   void SetTime();



private:

   String clockLocation;
   int hour;
   int minutes;
   int AM;        // will be 1 if AM, 0 if PM
};


#endif


