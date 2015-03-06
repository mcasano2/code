// ***********************************************************
// *                                                         *
// *  main.cpp                                               *
// *                                                         *
// *  Testing code for the Clock class                       *
// *                                                         *
// *  Written August 2001 by Jason Zych                      *
// *                                                         *
// ***********************************************************

#include <iostream>
#include "clock.h"

using std::cout;
using std::endl;

int main()
{
   Clock c1("House");

   c1.PrintClock();
   cout << endl;

   cout << "Incrementing time one minute..." << endl;
   c1.IncrementOneMinute();
   c1.PrintClock();
   cout << endl;  
 
   c1.SetTime();
   c1.PrintClock();
   cout << "Incrementing time one minute..." << endl;
   c1.IncrementOneMinute();
   c1.PrintClock();
   cout << endl;

   c1.SetTime();
   c1.PrintClock();
   cout << "Incrementing time one minute..." << endl;  
   c1.IncrementOneMinute();
   c1.PrintClock();
   cout << endl;

   if (c1.Convert24HourTime(25, 01) == 1)
   {
      cout << "Time converted!" << endl;
      c1.PrintClock();
      cout << endl;
   }
   else
      cout << "2501 is not a legal 24-hour time." << endl;

   if (c1.Convert24HourTime(22, 63) == 1)
   {  
      cout << "Time converted!" << endl;
      c1.PrintClock();
      cout << endl;
   }
   else
      cout << "2263 is not a legal 24-hour time." << endl;

   if (c1.Convert24HourTime(18, 11) == 1)
   {  
      cout << "Time converted!" << endl;
      c1.PrintClock();
      cout << endl;
   }
   else
      cout << "1811 is not a legal 24-hour time." << endl;


   return 0;
}

