#include "exercises.h"

int sumDigits(int n)
{
    if (n==0) {                // returns 0 when n is 0
        return 0;
    }
    return ( (n%10) + sumDigits(n/10) );  // returns right digit + sum of rest

}

int triangle(int rows)
{
    if (rows==0) {            // returns 0 if rows is empty
        return 0;
    }
    return (rows + triangle(rows-1) ); // returns largest row+rest of triangle
}
