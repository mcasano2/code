/* kdtree.cpp
 * Implementation of KDTree class
 * 
 * Written by Cinda Heeren for CS225 MP6
 * Spring 2009
 * Revision history:
 * 3/31/2009        Created
 * Spring 2011      Modified by Jack Toole
 */

using namespace std;

	template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
	//copy points data to our points vector
	points=newPoints;
	int right=static_cast<int>(points.size()-1);

	// intialize point_index vector
	for (int i=0; (int) i<=right; i++) {
		point_index.push_back(i);
	}

	//build tree
	buildTree(0, right, 0);
}

	template<int Dim>
void KDTree<Dim>::buildTree(int left, int right, int cDim)
{
	if ((right-left)<1) {
		return;
	}
	int median= static_cast<int>(floor((left + right)/2));
	select(left, right, median, cDim);
	buildTree(left, median-1, (cDim+1)%Dim);
	buildTree(median+1, right, (cDim+1)%Dim);
	return;
}

	template<int Dim>
void KDTree<Dim>::select(int left, int right, int & median, int & cDim)
{
	int result=partition(left, right, cDim);
	if (median==result) {
		return;
	}
	else if (median<result) {
		select(left, result-1, median, cDim);
	}
	else {
		select(result+1, right, median, cDim);
	}
	return;
}

	template<int Dim>
int KDTree<Dim>::partition(int left, int right, int & cDim)
{
	if (right-left<1) {
		return left;
	}
	int pivot=static_cast<int>(floor((left+right)/2));
	int pivotValue=static_cast<int>(points[point_index[pivot]][cDim]);
	swap(pivot,right);
	int storeIndex=left;
	for (int i=left; i<right; i++) {
		if (points[point_index[i]][cDim]<=pivotValue) {
			swap(storeIndex,i);
			storeIndex++;
		}
	}
	swap(storeIndex,right);
	return storeIndex;
}

template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & a) const
{
	Point<Dim> retPoint;
	double distVal=(3*255*255);
	int distInd=0;
	int size=static_cast<int>(point_index.size()-1);
	findNearestNeighbor(a, 0, distInd, distVal, 0, size);
	for (int i=0; i<Dim; i++) {
		retPoint[i]=points[point_index[distInd]][i];
	}
	return retPoint;
}

// define KDTree helper functions here

template<int Dim>
void KDTree<Dim>::findNearestNeighbor(const Point<Dim> & target, int k, int & distInd, double & distVal, int left, int right) const
{
	if (left>right){ 
		right=left;
	}
	//calculate median and distance to current node
	int med=(int) floor((left+right)/2);

	//test if at leaf
	if (right==left) {
		double current=0;
		for (int i=0; i<Dim; i++) {
			current=current + (points[point_index[med]][i]-target[i])*(points[point_index[med]][i]-target[i]);
		}
		if (current<distVal) {
			distVal=current;
			distInd=med;
		}
		return;		  
	}
	// test if go to right first
	if (points[point_index[med]][k] < target[k]) {
		findNearestNeighbor(target, ((k+1)%Dim), distInd, distVal, (med+1), right);
		double test=((points[point_index[med]][k]-target[k])*(points[point_index[med]][k]-target[k]));
		if (test< distVal) {
			double current=0;
			for (int i=0; i<Dim; i++) {
				current=current + (points[point_index[med]][i]-target[i])*(points[point_index[med]][i]-target[i]);
			}
			if (current<distVal) {
				distVal=current;
				distInd=med;
			}
			findNearestNeighbor(target, ((k+1)%Dim), distInd, distVal, left, (med-1));
		}
	}
	else {  // check left, then right
		findNearestNeighbor(target, ((k+1)%Dim), distInd, distVal, left, (med-1));
		double test=((points[point_index[med]][k]-target[k])*(points[point_index[med]][k]-target[k]));
		if (test< distVal) {
			double current=0;
			for (int i=0; i<Dim; i++) {
				current=current + (points[point_index[med]][i]-target[i])*(points[point_index[med]][i]-target[i]);
			}
			if (current<distVal) {
				distVal=current;
				distInd=med;
			}
			findNearestNeighbor(target, ((k+1)%Dim), distInd, distVal, (med+1), right);
		}
	}
}

	template<int Dim>
void KDTree<Dim>::swap(int left, int right)
{
	int temp= point_index[left];
	point_index[left]=point_index[right];
	point_index[right]=temp;
}


