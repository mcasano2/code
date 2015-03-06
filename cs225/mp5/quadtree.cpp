// **************************************************************
// *                                                            *
// *  quadtree.cpp                                              *
// *                                                            *
// *  A quadtree class                                          *
// *                                                            *
// *  CS 225 Spring 2011
//    MP 5.2  , 04-01-11                                        *
// *                                                            *
// **************************************************************

#include <cstddef>
#include <iostream>

using namespace std;

#include "quadtree.h"
#include "EasyBMP.h"



/**** Testing/grading functions ****/


// printTree (public interface)
//   - parameters: none
//   - prints the contents of the Quadtree using a preorder traversal
	void Quadtree::printTree() const {
		if (root == NULL)
			cout << "Empty tree.\n";
		else
			printTree(root, 1);
	}


// operator<< (not a member function)
//   - parameters: ostream & - output stream to be used for output
//                 RGBApixel const & pixel - pixel to be output
//   - prints the contents of the given RGBApixel to the given output stream
ostream & operator<<(ostream & out, RGBApixel const & pixel) {
	out << "(" << (int) pixel.Red << "," << (int) pixel.Green 
		<< "," << (int) pixel.Blue << ")";
	return out;
}


// printTree (private helper)
//   - parameters: QuadtreeNode *current - pointer to the root of the
//                    subQuadtree which we wish to print
//                 int level - the current recursion depth; used for
//                    determining when to terminate recursion (see note below)
//   - prints the leaves of the Quadtree using a preorder traversal
void Quadtree::printTree(QuadtreeNode const * current, int level) const {
	// Is this a leaf?
	// Note: it suffices to check only one of the child pointers,
	// since each node should have exactly zero or four children.
	if (current->neChild == NULL) {
		cout << current->element << " at depth " << level << "\n";
		return;
	}

	// This clause added for the sake of grading; we will never call
	// printTree() on quadtrees larger than  128x128.  (This is a
	// necessary restriction, as the grading scripts choke on programs
	// which produce excessive amounts of output.)
	if (level > 7) {
		cout << "Error: infinite loop detected in printTree();"
			<< " quadtree has a loop.\n";
		cout << "Aborting program.\n";
		exit(1);
	}

	// Standard preorder traversal
	printTree(current->neChild, level + 1);
	printTree(current->seChild, level + 1);
	printTree(current->swChild, level + 1);
	printTree(current->nwChild, level + 1);

	return;
}


// operator==
//   - parameters: Quadtree const & other - reference to a const Quadtree
//                    object, against which the current Quadtree will be
//                    compared
//   - return value: a boolean which is true if the Quadtrees are deemed
//        "equal", and false otherwise
//   - compares the current Quadtree with the parameter Quadtree, and
//        determines whether or not the two are the same
// Note: this method relies on the private helper method compareTrees()
bool Quadtree::operator==(Quadtree const & other) const {
	return compareTrees(root, other.root);
}


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
//   - this function only compares the leaves of the trees, as we did not
//     impose any requirements on what you should do with interior nodes
bool Quadtree::compareTrees(QuadtreeNode const * firstPtr,
		QuadtreeNode const * secondPtr) const {
	if (firstPtr == NULL && secondPtr == NULL)
		return true;

	if (firstPtr == NULL || secondPtr == NULL)
		return false;

	// if they're both leaves, see if their elements are equal
	// note: child pointers should _all_ either be NULL or non-NULL,
	// so it suffices to check only one of each
	if (firstPtr->neChild == NULL && secondPtr->neChild == NULL) {
		if (firstPtr->element.Red != secondPtr->element.Red ||
				firstPtr->element.Green != secondPtr->element.Green ||
				firstPtr->element.Blue != secondPtr->element.Blue)
			return false;
		else
			return true;
	}

	// they aren't both leaves, so recurse
	return (compareTrees(firstPtr->neChild, secondPtr->neChild) &&
			compareTrees(firstPtr->nwChild, secondPtr->nwChild) &&
			compareTrees(firstPtr->seChild, secondPtr->seChild) &&
			compareTrees(firstPtr->swChild, secondPtr->swChild));
}

// default Quadtree constructor
Quadtree::Quadtree(): root(NULL) { }

// Quadtree constructor
// takes BMP iamge
// d represents d x d square to be cropped from image
// into Quadtree
Quadtree::Quadtree(BMP const & image, int d) {
	root=new QuadtreeNode;
	size=d;
	buildTree(image,d,root,0,0);
}

//Quadtree destructor
Quadtree::~Quadtree() {
	clear(root);
}

//Quadtree copy constructor
Quadtree::Quadtree(Quadtree const & original) {
	root=copy(original.root);
	size=original.size;
}

//Quadtree Assgn Op
Quadtree const & Quadtree::operator=(Quadtree const & rhs) {
	if (this!=&rhs) {
		clear(root);
		root=copy(rhs.root);
		size=rhs.size;
	}
	return *this;
}

//copy private function
// current parameter is root node to be copied
Quadtree::QuadtreeNode * Quadtree::copy(QuadtreeNode const * current) {
	if (current==NULL) {
		return NULL;
	}
	QuadtreeNode * temp=new QuadtreeNode(current->element);
	// repeat for children
	temp->neChild=copy(current->neChild);
	temp->seChild=copy(current->seChild);
	temp->swChild=copy(current->swChild);
	temp->nwChild=copy(current->nwChild);
	return temp;
}

//QuadtreeNode constructor
Quadtree::QuadtreeNode::QuadtreeNode() { }

// QuadtreeNode constructor
// sets children to NULL and saves RGBApixel _element
// into element field of QuadtreeNode
Quadtree::QuadtreeNode::QuadtreeNode(RGBApixel _element) {
	element=_element;
	nwChild=NULL;
	neChild=NULL;
	swChild=NULL;
	seChild=NULL;
}


//clear() private functino
// deletes tree or subtree at current, freeing memory
void Quadtree::clear(QuadtreeNode * current) {
	if (current==NULL) {
		return;
	}
	clear(current->neChild);
	clear(current->seChild);
	clear(current->swChild);
	clear(current->nwChild);
	delete current;
}

//buildTree public
// takes BMP image to build as size d x d
void Quadtree::buildTree(BMP const & image, int d) {
	clear(root);
	root=new QuadtreeNode;
	size=d;
	buildTree(image, d, root, 0, 0);
}

//buildTree private 
// image is BMP image
// step keeps track of how much to move x,y positions
// current is node to be subdivided
// x, y keeps track of x,y coord of bmp
// to be represented
void Quadtree::buildTree(BMP const & image, int step,
		QuadtreeNode * current, int x, int y) {  
	// when step is 1, leaves are reached
	if (step==1) {
		// set children to null to indicate leaf
		current->nwChild=NULL;
		current->neChild=NULL;
		current->swChild=NULL;
		current->seChild=NULL;
		// save rgb values to element
		current->element.Red=image(x,y)->Red;
		current->element.Green= image(x,y)->Green;
		current->element.Blue=image(x,y)->Blue;
	}
	// if not at a leaf step isn't 1
	if (step!=1) {
		// allocate space for children
		current->neChild=new QuadtreeNode;
		current->seChild=new QuadtreeNode; 
		current->swChild=new QuadtreeNode;
		current->nwChild=new QuadtreeNode;
		// build children
		buildTree(image, step/2, current->neChild,x+step/2,y);
		buildTree(image, step/2, current->seChild,x+step/2,y+step/2);
		buildTree(image, step/2, current->swChild,x,y+step/2);
		buildTree(image, step/2, current->nwChild,x,y);
		// calc avg
		int avgRed=(current->nwChild->element.Red+
				current->neChild->element.Red+
				current->swChild->element.Red+
				current->seChild->element.Red)/4;
		int avgGreen=(current->nwChild->element.Green+
				current->neChild->element.Green+
				current->swChild->element.Green+
				current->seChild->element.Green)/4;
		int avgBlue=(current->nwChild->element.Blue+
				current->neChild->element.Blue+
				current->swChild->element.Blue+
				current->seChild->element.Blue)/4;
		// write average
		current->element.Red=avgRed;
		current->element.Green=avgGreen;
		current->element.Blue=avgBlue;
	}
}

//decompress()
// no parameters, returns BMP by value
// representing Quadtree
BMP Quadtree::decompress() {
	// empty Quadtree case
	if (root==NULL) {
		return BMP();
	}
	//temporary variables
	BMP image;
	RGBApixel temp;
	image.SetSize(size,size);
	// goes through BMP row by row writing RGB values
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			temp=getPixel(i,j);
			image(i,j)->Red=temp.Red;
			image(i,j)->Green=temp.Green;
			image(i,j)->Blue=temp.Blue;
		}
	}
	return image;
}

// getPixel public
// x,y correspond to pixel location to get
// returns RGBApixel at x,y
RGBApixel Quadtree::getPixel(int x, int y) {
	if ( (x>=0)&&(y>=0)&&(x<size)&&(y<size)&&(root!=NULL) ) {
		return getPixel(x,y,size/2,root,0,0);
	}
	else {
		return RGBApixel();
	}
}

// getPixel private
// x,y are coord to get pixel
// step is to keep track of level through quadtree
// current is node currently worked on
// _x, _y is to keep track of location in Quadtree
RGBApixel Quadtree::getPixel(int x, int y, int step,
		QuadtreeNode * current, int _x, int _y) {
	//test if at leaf
	if (current->nwChild==NULL) {
		return current->element;
	}
	// test for NW
	if ( (x<_x+step)&&(y<_y+step)) {
		return getPixel(x,y,step/2,current->nwChild,_x,_y);
	}
	//test for NE
	if ( (x>=_x+step)&&(y<_y+step)) {
		return getPixel(x,y,step/2,current->neChild,_x+step,_y);
	}
	//test for  SW
	if ( (x<_x+step)&&(y>=_y+step)) {
		return getPixel(x,y,step/2,current->swChild,_x,_y+step);
	} 
	//test for SE
	if ( (x>=_x+step)&&(y>=_y+step)) {
		return getPixel(x,y,step/2,current->seChild,_x+step,_y+step);
	}  
}

//pruneSize public
// tolerance is to compare difference between pixels
// and averages
// returns # leaves left after a prune
int Quadtree::pruneSize(int tolerance) {
	return pruneSize(root, tolerance);
}

//private pruneSize
// current is root
// tolerance is for comparing difference between pixels
int Quadtree::pruneSize(QuadtreeNode * current, int tolerance) {
	if (current==NULL) {
		return 0;
	}  
	//make queue for level order traversal
	queue<QuadtreeNode *> Q;
	QuadtreeNode * temp;
	int count=0;  // counter for leaves left after pruning
	temp=current;
	// push root
	Q.push(temp);
	while (!Q.empty()) {
		//pop front of queue
		temp=Q.front();
		Q.pop();
		//test popped value
		// if leaf already or leaf to prune, add 1 to count
		if ( (testPrune(temp, tolerance)) or( temp->nwChild==NULL) ) {
			count=count+1;
		}
		// test children if not leaf
		else {
			Q.push(temp->neChild);
			Q.push(temp->seChild);
			Q.push(temp->swChild);
			Q.push(temp->nwChild);

		}
	}
	// return # leaves left after prune
	return count;
}

//public idealPrune
// numLeaves is number of leaves to compare
// to tolerance
// returns tolerance which guarantees # leaves in tree
// is less than or equal to numLeaves
int Quadtree::idealPrune(int numLeaves) {
	// return tolerance 0 if empty
	if (root==NULL) {
		return 0;
	} 
	// right is maximum distance between pixels
	int right=255*255+255*255+255*255; // max distance between 2 points
	int left=0;
	// binary search for correct tolerance
	while ((right-left)>1) {
		if (pruneSize(left+((right-left)/2))<=numLeaves) { // try lower tolerance
			right=left+((right-left)/2);
		}
		// too low of a tolerance, set left to middle
		else {
			left=left+((right-left)/2);
		}
	}
	// if left and right differ by 1, return lowest tolerance
	if (pruneSize(left)<=numLeaves) {
		return left;
	}
	else {
		return right;
	}
}

//clockwiseRotate public
// no parameters
// rotates bmp image represented in quadtree by 90 degrees clockwise
void Quadtree::clockwiseRotate() {
	clockwiseRotate(root);
}

//clockwiseRotate private
// current is node to be worked on
// starts at root travelling downwards
void Quadtree::clockwiseRotate(QuadtreeNode * current) {
	// keep rotating if not at leaf
	if (current!=NULL) {
		QuadtreeNode * temp1=current->neChild;
		QuadtreeNode * temp2=current->seChild;
		QuadtreeNode * temp3=current->swChild;
		QuadtreeNode * temp4=current->nwChild;
		current->neChild=temp4;
		current->seChild=temp1;
		current->swChild=temp2;
		current->nwChild=temp3;
		clockwiseRotate(current->nwChild);
		clockwiseRotate(current->neChild);
		clockwiseRotate(current->swChild);
		clockwiseRotate(current->seChild);
	}
	return;
}


// public prune
// parameter tolerance is to compare
// difference between average and leaves
void Quadtree::prune(int tolerance) {
	prune(root, tolerance);
}


//private prune
// current represents root
// tolerance is to compare difference with average
void Quadtree::prune(QuadtreeNode * current, int tolerance) {
	if (current==NULL) {
		return;
	}  
	//make queue for level order traversal
	queue<QuadtreeNode *> Q;
	QuadtreeNode * temp;
	// push root
	temp=current;
	Q.push(temp);
	while (!Q.empty()) {
		//pop front of queue
		temp=Q.front();
		Q.pop();
		//test popped value for a prune
		if (testPrune(temp, tolerance) ) {
			doPrune(temp);
		}
		// if not a leaf, call children
		if (temp->nwChild!=NULL) {

			Q.push(temp->neChild);
			Q.push(temp->seChild);
			Q.push(temp->swChild);
			Q.push(temp->nwChild);

		}
	}
}

// testPrune private function
// tests if prune should occur
// returns true if prune should occur
// returns false if prune should not occur
// current is node to be tested
// tolerance is to compare difference between average and leaves
bool Quadtree::testPrune(QuadtreeNode * current, int tolerance) {
	queue<QuadtreeNode *> Q;
	QuadtreeNode * temp;
	// variables for leaf to be tested
	int redLeaf;
	int greenLeaf;
	int blueLeaf;
	// difference between points
	int diff;
	// original root node RGB values
	int redOrig=current->element.Red;
	int greenOrig=current->element.Green;
	int blueOrig=current->element.Blue;
	temp=current;
	Q.push(temp);
	while (!Q.empty()) {
		//pop front of queue
		temp=Q.front();
		Q.pop();
		//test popped value if child
		// adds children if not
		if (temp->nwChild!=NULL) {

			Q.push(temp->neChild);
			Q.push(temp->seChild);
			Q.push(temp->swChild);
			Q.push(temp->nwChild);
		}
		// tests for prune if leaf
		if (temp->nwChild==NULL) {
			redLeaf=temp->element.Red;
			greenLeaf=temp->element.Green;
			blueLeaf=temp->element.Blue;
			diff=(redOrig-redLeaf)*(redOrig-redLeaf) +
				(blueOrig-blueLeaf)*(blueOrig-blueLeaf) +
				(greenOrig-greenLeaf)*(greenOrig-greenLeaf);
			// if diff> tolerance for any leaf in tree
			// returns a false
			// otherwise the queue is tested until empty
			// resulting in a true at the end
			if (diff>tolerance) {
				return false;
			}
		}
	}
	return true;
}

//doPrune private function
// performs prune at node current
void Quadtree::doPrune(QuadtreeNode * current) {

	clear(current->neChild);
	clear(current->seChild);
	clear(current->swChild);
	clear(current->nwChild);

	current->nwChild=NULL;
	current->neChild=NULL;
	current->swChild=NULL;
	current->seChild=NULL;
}



