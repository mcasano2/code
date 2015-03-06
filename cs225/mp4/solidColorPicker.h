//============================================================
//   file: solidColorPicker.h
//   description: header file for solidColorPicker class
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================

#ifndef SOLIDCOLORPICKER_H
#define SOLIDCOLORPICKER_H

#include"colorPicker.h"
// Functor is derived class of colorPicker, chooses color passed
// as a parameter

class solidColorPicker : public colorPicker{
	public:
		solidColorPicker(RGBApixel fillColor); 
		virtual RGBApixel operator()(int x, int y);
	private:
		RGBApixel color;  // color to fill
};

#endif
