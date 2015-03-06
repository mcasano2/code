// **************************************************************
// *                                                            *
// *  quadtree.h                                                *
// *                                                            *
// *  Quadtree class                                            *
// *                                                            *
// *  CS 225 Spring 2011
//    MP 5.2
//    04-01-11                                                  *
// *                                                            *
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "EasyBMP.h"
#include <queue>

class Quadtree
{
	public:

		Quadtree();       
		Quadtree(BMP const & image, int d);
		~Quadtree(); 
		// buildTree constructs tree from image, cropping it dxd
		void buildTree(BMP const & image, int d);
		// assignment operator
		Quadtree const & operator=(Quadtree const & rhs);
		// quadtree constructor
		Quadtree(Quadtree const & original);
		// pruneSize returns # leaves to be pruned based on tolerance
		int pruneSize(int tolerance);
		// idealPrune returns a tolerance 
		int idealPrune(int numLeaves);
		// rotates quadtree clockwise
		void clockwiseRotate();
		// prunes tree based on tolerance
		void prune(int tolerance);



		/**** Functions added for testing/grading ****/


		// printTree (public interface)
		//   - parameters: none
		//   - prints the leaves of the Quadtree using a preorder traversal
		void printTree() const;
		// decompress converts tree into BMP, returning BMP
		BMP decompress();
		// getPixel returns pixel at x,y in RGBApixel
		RGBApixel getPixel(int x, int y);




		// operator==
		//   - parameters: Quadtree const & other - reference to a const Quadtree
		//                    object, against which the current Quadtree will be
		//                    compared
		//   - return value: a boolean which is true if the Quadtrees are deemed
		//        "equal", and false otherwise
		//   - compares the current Quadtree with the parameter Quadtree, and
		//        determines whether or not the two are the same
		// Note: this method relies on the private helper method compareTrees()
		bool operator==(Quadtree const & other) const;


	private:

		// A simple class representing a single node of a Quadtree.
		// You may want to add to this class; in particular, it could probably
		// use a constructor or two...
		class QuadtreeNode
		{
			public:
				QuadtreeNode();
				QuadtreeNode(RGBApixel _element);


				QuadtreeNode* nwChild;  // pointer to northwest child
				QuadtreeNode* neChild;  // pointer to northeast child
				QuadtreeNode* swChild;  // pointer to southwest child
				QuadtreeNode* seChild;  // pointer to southeast child

				RGBApixel element;  // the pixel stored as this node's "data"

		};

		QuadtreeNode* root;    // pointer to root of quadtree
		int size;                 // holds width by height


		/*** Testing/grading functions ***/

		// printTree (private helper)
		//   - parameters: QuadtreeNode *current - pointer to the root of the
		//                    subQuadtree which we wish to print
		//                 int level - the current recursion depth; used for
		//                    determining when to terminate recursion (see note below)
		//   - prints the contents of the Quadtree using a preorder traversal
		void printTree(QuadtreeNode const *current, int level) const;

		// compareTrees
		//   - parameters: QuadtreeNode const * firstPtr - pointer to the root
		//                    of a subtree of the "first" Quadtree under
		//                    consideration
		//                 QuadtreeNode const * secondPtr - pointer to the root
		//                    of a subtree of the "second" Quadtree under
		//                    consideration
		//   - return value: a boolean which is true if the subQuadtrees are deemed
		//        "equal", and false otherwise
		//   - compares the subQuadtree rooted at firstPtr with the subQuadtree
		//        rooted at secondPtr, and determines whether the two are the same
		bool compareTrees(QuadtreeNode const *firstPtr,
				QuadtreeNode const *secondPtr) const;
		// builds tree from image
		void buildTree(BMP const & image, int step, QuadtreeNode * current,
				int x, int y);
		// clears quadtree
		void clear(QuadtreeNode * current);
		// tests if prune should occur
		bool testPrune(QuadtreeNode * current, int tolerance);
		// copies tree
		QuadtreeNode * copy(QuadtreeNode const * current);
		// prunse tree based on tolerance
		void prune(QuadtreeNode * current, int tolerance);
		// performs the actual prune removal of nodes
		void doPrune(QuadtreeNode * current);
		// gets pixel at x,y
		RGBApixel getPixel(int x, int y, int step, QuadtreeNode * current,
				int _x, int _y);
		// returns # leaves removed if prune were to occur
		int pruneSize(QuadtreeNode * current, int tolerance);
		// rotates quadtree clockwise
		void clockwiseRotate(QuadtreeNode * current);




};

#endif
