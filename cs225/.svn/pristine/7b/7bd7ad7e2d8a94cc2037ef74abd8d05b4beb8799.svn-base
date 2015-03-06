/**
 * maze.h
 * SquareMaze Class
 * MP7
 * 
 * 
 * 
 *
 */


#ifndef __MAZE_H__
#define __MAZE_H__

#include <iostream>
#include <vector>
#include <math.h>
#include "dsets.h"
#include "EasyBMP.h"

using namespace std;

class SquareMaze
{

	private:
		// arrays to hold wall values
		vector<bool> rArray;
		vector<bool> dArray;

		int mazeWidth;
		int mazeHeight;
		void clearMaze();  
		int exitLoc;  // x value of solution point
		int maxPath;   // length of solution point
		bool winMaze(int x, int y, int dir); // constructos solution vect
		// tests if delete is possible
		bool testRight(int x, int y, DisjointSets & mynodes);
		bool testDown(int x, int y, DisjointSets & mynodes);
		void solveMaze(int x, int y, int dir, int pathSize);

	public:
		SquareMaze();
		void makeMaze(int width, int height);  
		void setWall(int x, int y, int dir, bool exists);
		bool canTravel(int x, int y, int dir);
		BMP* drawMaze();
		void solveMaze();
		vector<int> solution;
		BMP* drawMazeWithSolution();



};


#endif
