/* kdtree.h
 * KDTree implementation using Points in k-dimensional space.
 *
 * Written by Cinda Heeren for CS225 MP6
 * Spring 2009
 * 
 * Revision history:
 * 3/31/2009        Created
 * 11/10/2009       Modified for MP6 Submission, Fall 2009
 * Spring 2011      Modified for MP6.1 release by Jack Toole
 */

#ifndef __KDTREE_H__
#define __KDTREE_H__

#include <iostream>
#include <string>
#include <vector>
#include "coloredout.h"
#include "point.h"
#include <math.h>

using namespace std;

template<int Dim>
class KDTree
{
	private:
		// Member variables
		vector< Point<Dim> > points;
		vector<int> point_index;
		// You may add your own member variables here

		// You may add your own helper functions here
		void buildTree(int left, int right, int currDim);
		void swap(int left, int right);
		void select(int left, int right, int & median, int & currDim);
		int partition(int left, int right, int & currDim);
		void findNearestNeighbor(const Point<Dim> & target, int k, int & distInd, double & distVal, int left, int right) const;

		// Print helper functions
		int  getPrintData(int low, int high) const;
		void printTree(int low, int high, vector<string> & output,
				int left, int top, int width, int currd) const;

	public:

		// Print functions
		void printVectors(ostream & out = cout,
				colored_out::enable_t enable_bold = colored_out::COUT) const;

		void printTree(ostream & out = cout,
				colored_out::enable_t enable_bold = colored_out::COUT,
				int modWidth = -1) const;

		void gradingPrint(ostream & out) const;

		// MP 6.1 functions
		KDTree(const vector< Point<Dim> > & newPoints);

		Point<Dim> findNearestNeighbor(const Point<Dim> & a) const;
};

#include "kdtree.cpp"
#include "kdtree_extras.cpp"

#endif

