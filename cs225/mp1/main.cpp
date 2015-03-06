//============================================================
//   file: main.cpp
//   description: reads BMP image, rotates 180 degrees,
//   outputs BMP image
//   date: 25 Jan 2011
//   Machine Problem 1
//============================================================

#include <iostream>
#include "EasyBMP.h"

using namespace std;

// int main() function reads in.bmp, rotates the bitmap image
// 180 degrees, then outputs rotated image to out.bmp

int main()
{

// original is BMP member used for opening file
// final is BMP member used for rotated image workspace

   BMP original;
   BMP final;

// Using the EasyBMP library, in.bmp is read into both original
// and final to set up matching height and width

   original.ReadFromFile("in.bmp");
   final.ReadFromFile("in.bmp");

   int width= original.TellWidth();
   int height= original.TellHeight();

// i: horizontal position, j: vertical position
// Outer loop runs for each vertical line from top to bottom
// Inner loop copies pixels one by one from left to right


   for (int j=0; j<height; j++)
   {
      for (int i = 0; i<width; i++)
      {

// RGB values are read from original image at (i,j)

         int red = original(i, j)->Red;
         int green = original(i, j)->Green;
         int blue = original(i, j)->Blue;

// x,y positions calculated to write RGB value to proper location
// in final to acheive rotated image
// for example (3,4) is copied to (right - 3, bottom - 4)
// where right and bottom correspond to the edges of the pixel grid

         int x = width - 1 - i;
         int y = height - 1 - j;

         final(x, y)->Red = red;
         final(x, y)->Green = green;
         final(x, y)->Blue = blue;

      }
   }

// After bottom row of original is copied to top row of final,
// the rotated image is contained in final and written to file

   final.WriteToFile("out.bmp");

   return 0;
}


