//============================================================
//   file: gradientColorPicker.h
//   description: header file for gradientColorPicker class
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================

#ifndef GRADIENTCOLORPICKER_H
#define GRADIENTCOLORPICKER_H

#include"colorPicker.h"
#include<math.h>
#include<iostream>

// gradientColorPicker is a derived class from colorPicker

class gradientColorPicker : public colorPicker{
	public:
		gradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2,
				int radius, int centerX, int centerY); 
		virtual RGBApixel operator()(int x, int y);
	private:
		RGBApixel color1;  
		RGBApixel color2;  
		int theRadius;     
		int xCenter;
		int yCenter;
};

#endif
