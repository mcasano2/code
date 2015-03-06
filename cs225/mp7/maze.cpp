/**
 * maze.cpp
 *
 * 
 * 
 * 
 * 
 *
 */

#include <iostream>
#include "maze.h"
#include <ctime>


using namespace std;


// SquareMaze constructor
SquareMaze::SquareMaze()
{
	clearMaze();
}


//clearMaze() clears the Maze
void SquareMaze::clearMaze()
{
	rArray.clear();
	dArray.clear();
	mazeWidth=0;
	mazeHeight=0;
	maxPath=0;
}

//makeMaze
void SquareMaze::makeMaze(int width, int height)
{
	// set random number, clear maze
	srand ( time(NULL) );
	if (mazeHeight!=0)
		clearMaze();
	mazeWidth=width;
	mazeHeight=height;

	// initialize array to true
	for (int a=0; a<(mazeWidth*mazeHeight); a++)
	{
		rArray.push_back(true);
		dArray.push_back(true);
	}

	DisjointSets nodes;
	nodes.addelements(mazeHeight*mazeWidth);
	bool done=false;
	// union disjoint sets until all are connected
	while (done==false)
	{
		for (int x=0; x<mazeWidth; x++)
		{
			for (int y=0; y<mazeHeight; y++)
			{
				if (rand() % 2 == 1)
				{
					if (rand() % 2 == 0)
					{
						if (testRight(x,y,nodes))
						{
							setWall(x,y,0,false);
							nodes.setunion((y*mazeWidth+x),(y*mazeWidth+x+1));
						}
					}
				}
				else
				{
					if (rand() % 2 == 0)
					{
						if (testDown(x,y,nodes))
						{
							setWall(x,y,1,false);
							nodes.setunion((y*mazeWidth+x),((y+1)*mazeWidth+x));
						}
					}
				}
			}
		}    
		if (nodes.myTree[nodes.find(0)]==(-mazeWidth*mazeHeight))
			done=true;
	}


}

//canTravel
// returns true if travel is possible
bool SquareMaze::canTravel(int x, int y, int dir)
{
	// test bounds near edges
	if ( (x==0)||(y==0)||(x==mazeWidth-1)||(y==mazeHeight-1) )
	{
		if ( (x==0)&&(dir==2) )
			return false;
		if ( (x==mazeWidth-1)&&(dir==0) )
			return false;
		if ( (y==0)&&(dir==3) )
			return false;
		if ( (y==mazeHeight-1)&&(dir==4) )
			return false;
	}    
	// test directions
	if (dir==0)
		return !rArray[x+y*mazeWidth];
	if (dir==1)
		return !dArray[x+y*mazeWidth];
	if (dir==2)
		return !rArray[x-1+y*mazeWidth];
	if (dir==3)
		return !dArray[x+(y-1)*mazeWidth];
}

//setWall sets the wall of a particular x,y coord
void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
	if (dir==0)
		rArray[x+y*mazeWidth]=exists;
	else
		dArray[x+y*mazeWidth]=exists;
}

//testRight tests if a delete is possible, returns true for yes
bool SquareMaze::testRight(int x, int y, DisjointSets & mynodes)
{
	// test bounds
	if (x==mazeWidth-1)
		return false;
	if (rArray[x+y*mazeWidth]==false)
		return false;
	if ((mynodes.find(y*mazeWidth+x))==(mynodes.find(y*mazeWidth+x+1)))
		return false;

	return true;  
}

//testDown tests if a delete is possible
bool SquareMaze::testDown(int x, int y, DisjointSets & mynodes)
{
	// test bounds
	if (y==mazeHeight-1)
		return false;
	if (dArray[x+y*mazeWidth]==false)
		return false;
	if ((mynodes.find(y*mazeWidth+x))==(mynodes.find((y+1)*mazeWidth+x)))
		return false;

	return true;
}

// draws the maze without the solution, returning a poitner to BMP
BMP* SquareMaze::drawMaze()
{
	BMP * pic=new BMP;
	pic->SetSize(mazeWidth*10+1,mazeHeight*10+1);
	// draw borders
	for (int i=10; i<(mazeWidth*10+1); i++)
	{
		pic->operator()(i,0)->Red=0;
		pic->operator()(i,0)->Green=0;
		pic->operator()(i,0)->Blue=0;
	}  
	for (int i=0; i<(mazeHeight*10+1); i++)
	{
		pic->operator()(0,i)->Red=0;
		pic->operator()(0,i)->Green=0;
		pic->operator()(0,i)->Blue=0;
	}
	// draw walls
	for (int x=0; x<mazeWidth; x++)
	{
		for (int y=0; y<mazeHeight; y++)
		{		
			if (rArray[x+y*mazeWidth])
			{
				for (int j=0; j<=10; j++)
				{   
					pic->operator()((x*10+10),(y*10+j))->Red=0;
					pic->operator()((x*10+10),(y*10+j))->Green=0;
					pic->operator()((x*10+10),(y*10+j))->Blue=0;
				}
			}
			if (dArray[x+y*mazeWidth])
			{
				for (int k=0; k<=10; k++)
				{   
					pic->operator()((x*10+k),(y*10+10))->Red=0;
					pic->operator()((x*10+k),(y*10+10))->Green=0;
					pic->operator()((x*10+k),(y*10+10))->Blue=0;
				}
			}
		}
	} 
	// return poitner to BMP
	return pic;
}

// public solveMaze() function finds solution vector
void SquareMaze::solveMaze()
{
	solveMaze(0,0,1,0);
	winMaze(0,0,1);
	// pop extra direction from start
	solution.pop_back();
	vector<int> temp;
	// reverse order of solution
	for (int i=0; i<maxPath; i++)
	{
		temp.push_back(solution.back());
		solution.pop_back();
	}
	// save correct order into solution
	solution=temp;
}

//private solveMaze finds end point and size of path
void SquareMaze::solveMaze(int x, int y, int dir, int pathSize)
{
	// if at the bottom row
	if (y==(mazeHeight-1))
	{
		if (pathSize==maxPath)
		{
			if (x<exitLoc)
				exitLoc=x;
		}
		if (pathSize>maxPath)
		{
			maxPath=pathSize;
			exitLoc=x; 
		}
	}
	// test if you can traverse
	if ( ((dir+2)%4!=0)&&(canTravel(x,y,0)))
		solveMaze(x+1,y,0,pathSize+1);
	if ( ((dir+2)%4!=1)&&(canTravel(x,y,1)))
		solveMaze(x,y+1,1,pathSize+1);
	if ( ((dir+2)%4!=2)&&(canTravel(x,y,2)))
		solveMaze(x-1,y,2,pathSize+1);
	if ( ((dir+2)%4!=3)&&(canTravel(x,y,3)))
		solveMaze(x,y-1,3,pathSize+1);
}

//winMaze actually constructs the vector solution
// modified solveMaze returning true for path, false for dead end
bool SquareMaze::winMaze(int x, int y, int dir)
{
	if (y==(mazeHeight-1))
	{
		if (x==exitLoc)
		{
			solution.push_back(dir);
			return true;
		}
	}
	bool rValue=false;
	if ( ((dir+2)%4!=0)&&(canTravel(x,y,0)))
		rValue=(rValue||winMaze(x+1,y,0));
	if ( ((dir+2)%4!=1)&&(canTravel(x,y,1)))
		rValue=(rValue||winMaze(x,y+1,1));
	if ( ((dir+2)%4!=2)&&(canTravel(x,y,2)))
		rValue=(rValue||winMaze(x-1,y,2));
	if ( ((dir+2)%4!=3)&&(canTravel(x,y,3)))
		rValue=(rValue||winMaze(x,y-1,3));
	if (rValue)
		solution.push_back(dir);
	return rValue;    
}

// draws the maze with a red solution line, first calling drawMaze
BMP* SquareMaze::drawMazeWithSolution()
{
	BMP * pic=drawMaze();

	//draw exit
	for (int k=1; k<10; k++)
	{
		pic->operator()(exitLoc*10+k,mazeHeight*10)->Red=255;
		pic->operator()(exitLoc*10+k,mazeHeight*10)->Green=255;
		pic->operator()(exitLoc*10+k,mazeHeight*10)->Blue=255;
	}
	int x=5;
	int y=5;
	// draw solution line
	for (int i=0; i<maxPath; i++)
	{
		//test for directions
		if (solution[i]==0)
		{
			for (int k=0; k<=10; k++)
			{   
				pic->operator()((x+k),y)->Red=255;
				pic->operator()((x+k),y)->Green=0;
				pic->operator()((x+k),y)->Blue=0;
			}
			x=x+10;
		}
		if (solution[i]==1)
		{
			for (int k=0; k<=10; k++)
			{   
				pic->operator()(x,y+k)->Red=255;
				pic->operator()(x,y+k)->Green=0;
				pic->operator()(x,y+k)->Blue=0;
			}
			y=y+10;    
		}
		if (solution[i]==2)
		{
			for (int k=0; k<=10; k++)
			{   
				pic->operator()((x-k),y)->Red=255;
				pic->operator()((x-k),y)->Green=0;
				pic->operator()((x-k),y)->Blue=0;
			} 
			x=x-10;   
		}
		if (solution[i]==3)
		{
			for (int k=0; k<=10; k++)
			{   
				pic->operator()(x,y-k)->Red=255;
				pic->operator()(x,y-k)->Green=0;
				pic->operator()(x,y-k)->Blue=0;
			}
			y=y-10;      
		}
	}


	return pic;
}













