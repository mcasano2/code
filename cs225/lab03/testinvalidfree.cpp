// ***********************************************
// *                                             *
// *  main.cpp (Lab3)                            *
// *                                             *
// *  Driver for the Building class              *
// *                                             *
// *                                             *
// *  Based on code by Jason Zych                *
// *                                             *
// ***********************************************

#include <iostream>
#include <string>
#include "building.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
   Building a(1);
   Building b(1);

   a.addApartment("Adam",123);

   cout << "*****Printing building a" << endl << a << endl;

   b = a;

   cout << "*****Printing building b" << endl << b << endl;

   a.removeApartment(1);
   b.removeApartment(1);

   return 0;
}

