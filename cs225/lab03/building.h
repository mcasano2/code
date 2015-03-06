/******************************************************************************
 *                                                                            *
 * building.h                                                                 *
 *                                                                            *
 * Represents an apartment building that contains numerous Apartments, each   *
 * of which have a tenant name and apartment number.                          *
 *                                                                            *
 * Based on code written by Jason Zych                                        *
 * Modified by Daniel Hoodin                                                  *
 *                                                                            *
 *****************************************************************************/

#ifndef BUILDING_H
#define BUILDING_H

#include "apartment.h"
#include <string>
#include <iostream>

class Building
{
public:
   Building(int size);
   Building(const Building& copy);
   ~Building(); //This is a destructor, the '~' is NOT a typo!
   int addApartment(std::string const & tenantName, int apartmentNumber);
   bool removeApartment(int index);
   bool getTenantAt(int index, std::string & tenantName) const;
   int getSize() const;

   friend std::ostream & operator<<(std::ostream & stream, Building const & building);
    
private:
   int getIndexOfVacantApartment() const;

   Apartment* * myApartments;
   int mySize;
};

std::ostream & operator<<(std::ostream & stream, Building const & building);

#endif

