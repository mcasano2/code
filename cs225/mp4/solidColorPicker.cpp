//============================================================
//   file: solidColorPicker.cpp
//   description: source file for solidColorPicker class
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================

#include "solidColorPicker.h"

// private member color gets input fillColor
solidColorPicker::solidColorPicker(RGBApixel fillColor) {
	color = fillColor;
}

// color is returned always
RGBApixel solidColorPicker::operator()(int x, int y) {
	return color;
}
