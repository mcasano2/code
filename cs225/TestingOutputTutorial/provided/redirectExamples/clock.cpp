// ***********************************************************
// *                                                         *
// *  clock.cpp                                              *
// *                                                         *
// *  Implementation for a class representing a clock        *
// *                                                         *
// *  Written August 2001 by Jason Zych                      *
// *                                                         *
// ***********************************************************

#include <iostream>
#include "asserts.h"
#include "clock.h"

using std::cin;
using std::cout;
using std::endl;


// Clock
//    - constructor
//    - parameters : thePlace - name of clock location
//    - initializes clock to 12:00 AM and parameter location
Clock::Clock(String thePlace)
{
   clockLocation = thePlace;
   hour = 12;
   minutes = 0;
   AM = 1;
}




// PrintClock
//    - prints the current time and clock location
void Clock::PrintClock()  
{
   cout << "The time is " << hour << ":";
   if (minutes <=9)
      cout << "0";
   cout << minutes << " ";
   if (AM == 1)
      cout << "AM." << endl;
   else 
      cout << "PM." << endl;
}



// IncrementOneMinute
//    - moves time forward one minute.  
void Clock::IncrementOneMinute()
{
   cout << "Clock is located at: " << clockLocation << endl;
   if (minutes < 59)
      minutes++;
   else
   {
      minutes = 0;
      if (hour == 12)
         hour = 1;
      else 
      {
         hour++;
         if (hour == 12)
            AM = !AM;
      }
   }
}



  
// Convert24HourTime
//    - parameters : hour24format - an hour of a time 24-hour-time 
//                                    format
//                 : minutes24format - the minutes of a time in 
//                                    24-hour-time format
//    - return type : boolean integer indicating whether parameters
//                      formed legal time
//    - if parameters represent a legal time in 24-hour-time format,
//        set clock to equivalent time in AM/PM format and return 1.
//        Otherwise, don't change clock values at all, and return 0.
int Clock::Convert24HourTime(int hour24format, int minutes24format)
{
   if ((hour24format >= 0) && (hour24format <= 23) && 
           (minutes24format >= 0) && (minutes24format <= 59))
   {
      if (hour24format < 12)
      {
         AM = 1;
         if (hour24format == 0)
            hour = 12;
         else
            hour = hour24format;
      } 
      else // hour24format >= 12
      {
         AM = 0;
         if (hour24format > 12)
            hour = hour24format - 12;
         else
            hour = 12;
      }
      minutes = minutes24format;
      return 1;
   }
   else
      return 0;
}




   
 
// SetTime()
//    - prompts the user to enter hour, minute, and AM/PM
//      values used to reset the time. If any value entered 
//      that is not a valid input, the user will be 
//      re-prompted until acceptable data is entered. 
void Clock::SetTime()
{
   int cannotContinue = 1;
   int newHour, newMinutes, newAM;

   while (cannotContinue)  // in C++, integers can mean "true" or
   {                       //  "false"
      cout << "Enter new value for hour: ";
      cin >> newHour;
      if ((newHour < 1) || (newHour > 12))
         cout << "That is not a legal value! Try again." << endl;
      else
         cannotContinue = 0;
   }

   cannotContinue = 1;

   do
   {
      cout << "Enter new value for minutes: ";
      cin >> newMinutes;
      if ((newMinutes < 0) || (newMinutes > 59))
         cout << "That is not a legal value! Try again." << endl;
      else
         cannotContinue = 0;
   } while (cannotContinue);

 
   cannotContinue = 1;
   while (cannotContinue)
   {
      cout << "Enter 1 for AM and 0 for PM: ";
      cin >> newAM;
      if ((newAM != 1) && (newAM != 0))
         cout << "That is not a legal value! Try again." << endl;
      else
         cannotContinue = 0;
   }

   hour = newHour;
   minutes = newMinutes;
   AM = newAM;
}

