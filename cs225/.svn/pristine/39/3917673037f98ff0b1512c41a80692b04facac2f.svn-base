//============================================================
//   file: image.cpp
//   description: Image class source file
//   date: 13 Feb 2011
//   Machine Problem 2
//============================================================

#include <iostream>
#include "image.h"

using namespace std;

//Following functions are declared in image.h

// invertcolors() inverts the color of each pixel of an image
void Image::invertcolors()
{

// gets width and height of image
   int width= TellWidth();
   int height= TellHeight();

// outer 'for loop' runs from top of image to bottom
// inner 'for loop' runs from left side of image to right side
   for (int j=0; j<height; j++)
   {

      for (int i = 0; i<width; i++)
      {

// gets RGB values stores back into pixel
         int red = operator()(i, j)->Red;
         int green = operator()(i, j)->Green;
         int blue = operator()(i, j)->Blue;

// subtracts RGB values from 255
         red = 255 - red;
         green = 255 - green;
         blue = 255 - blue;

// writes modified RGB values into pixel
         operator()(i, j)->Red = red;
         operator()(i, j)->Green = green;
         operator()(i, j)->Blue = blue;

      }               // closes inner for loop
   }                  // closes outer for loop
}                     // closes function

// flipleft() function flips an image through a vertical
// axis by swapping pixels
void Image::flipleft()
{

// gets width and height of image
   int width= TellWidth();
   int height= TellHeight();

// outer 'for loop' runs from top of image to bottom
// inner 'for loop' runs from left of image to middle
   for (int j=0; j<height; j++)
   {

      for (int i = 0; i<=(width/2 - 1); i++)
      {

// RGB values from pixel on left are written to temp variables
         int redtemp = operator()(i, j)->Red;
         int greentemp = operator()(i, j)->Green;
         int bluetemp = operator()(i, j)->Blue;

// The pixel from the right side is written to the left side
         operator()(i, j)->Red = operator()( width-1-i , j)->Red;
         operator()(i, j)->Green = operator()(width-1-i, j)->Green;
         operator()(i, j)->Blue = operator()(width-1-i, j)->Blue;

// The pixel on left side is written to the right side         
         operator()( width-1-i , j)->Red = redtemp;
         operator()( width-1-i , j)->Green = greentemp;
         operator()( width-1-i , j)->Blue = bluetemp;

      }               // closes inner for loop
   }                  // closes outer for loop
}                     // closes function

// the adjustbrightness function adjusts the brightness of 
// RGB values at each pixel by input values r, g, b
void Image::adjustbrightness(int r, int g, int b)
{

// gets width and height of image
   int width= TellWidth();
   int height= TellHeight();

// outer 'for loop' runs from top of image to bottom
// inner 'for loop' runs from left side of image to right side
   for (int j=0; j<height; j++)
   {

      for (int i = 0; i<width; i++)
      {

// RGB values from pixel are written to variables
         int red = operator()(i, j)->Red;
         int green = operator()(i, j)->Green;
         int blue = operator()(i, j)->Blue;

// parameters passed into function are added to RGB values
         red = r + red;
         green = g + green;
         blue = b + blue;

// error handling, sets RGB values to 0/255 if out of range

         if (red>255)
            red= 255;
         if (red<0)
            red= 0;

         if (green>255)
            green= 255;
         if (green<0)
            green= 0;

         if (blue>255)
            blue= 255;
         if (blue<0)
            blue= 0;
         
         operator()(i, j)->Red = red;
         operator()(i, j)->Green = green;
         operator()(i, j)->Blue = blue;

      }               // closes inner for loop
   }                  // closes outer for loop
}                     // closes function

