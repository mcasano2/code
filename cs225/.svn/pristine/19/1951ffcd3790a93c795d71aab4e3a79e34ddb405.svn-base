//============================================================
//   file: gradientColorPicker.cpp
//   description: source file for gradientColorPicker class
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================

#include "gradientColorPicker.h"

//functor constructor saves input into private members
gradientColorPicker::gradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int centerX, int centerY) {
	color1=fadeColor1;
	color2=fadeColor2;
	theRadius=radius;
	xCenter=centerX;
	yCenter=centerY;
}

// returns color based on radius and tolerance
RGBApixel gradientColorPicker::operator()(int x, int y) {
	int d;   // distance between points
	RGBApixel retval;  // color to return
	d= abs(xCenter - x) + abs(yCenter - y);  // distance formula
	if (d>theRadius) {         // if distance is greater than radius
		return color2;
	}
	//returns gradient color linear to d
	retval.Red= color1.Red - floor( (d*color1.Red) / theRadius ) + floor( (d*color2.Red) / theRadius );
	retval.Green= color1.Green - floor( (d*color1.Green) / theRadius ) + floor( (d*color2.Green) / theRadius );
	retval.Blue= color1.Blue - floor( (d*color1.Blue) / theRadius ) + floor( (d*color2.Blue) / theRadius );
	return retval;
}
