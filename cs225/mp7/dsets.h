/**
 * dsets.h
 * Disjointsets
 * MP7
 * 
 * 
 * 
 *
 */


#ifndef __DSETS_H__
#define __DSETS_H__

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class DisjointSets
{

	private:


	public:
		vector<int> myTree;
		void addelements(int n);
		int find(int ind);
		void setunion(int a, int b);



};


#endif
