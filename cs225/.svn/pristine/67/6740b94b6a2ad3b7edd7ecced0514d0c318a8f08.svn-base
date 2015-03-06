//============================================================
//   file: scene.h
//   description: Scene class header file
//   date: 13 Feb 2011
//   Machine Problem 2
//============================================================

#include "image.h"

#ifndef __SCENE_H__
#define __SCENE_H__


class Scene {

public: 

Scene(int max);
~Scene();
Scene(Scene const & source);
Scene const & operator=(Scene const & source);
void addpicture(const char* FileName, int index, int x, int y);
void changemaxlayers(int newmax);
void changelayer(int index, int newindex);
void translate(int index, int xcoord, int ycoord);
void deletepicture(int index);
Image* getpicture(int index) const;
Image drawscene() const;

private:

Image* x;        // x coordinate
Image* y;        // y coordinate
int maxval;     // maximum for array
Image* * imageArray;   // Pointer to array of Image pointers
int* xArray;           // x coordinate array
int* yArray;           // y coordinate array

};

#endif
