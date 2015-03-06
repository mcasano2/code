/**
 * dsets.cpp
 *
 * 
 * 
 * 
 * 
 *
 */

#include <iostream>
#include "dsets.h"

using namespace std;

void DisjointSets::addelements(int n)
{
	for (int i=0; i<n; i++)
		myTree.push_back(-1);
}

int DisjointSets::find(int ind)
{
	if (myTree[ind] < 0)
		return ind;
	else
		return myTree[ind]=find(myTree[ind]);
}

void DisjointSets::setunion(int a, int b)
{
	int rootA=find(a);
	int rootB=find(b);
	int newSize=myTree[rootA]+myTree[rootB];

	if ( myTree[rootA]>myTree[rootB] )
	{
		myTree[rootA]=rootB;
		myTree[rootB]=newSize;
	}
	else 
	{
		myTree[rootB]=rootA;
		myTree[rootA]=newSize;
	}
}




