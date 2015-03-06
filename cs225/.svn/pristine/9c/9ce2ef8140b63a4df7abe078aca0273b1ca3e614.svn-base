#include <iostream>
#include <algorithm>

using namespace std;

double getTime();

// MinHeap
//	 - default constructor
template <class T>
MinHeap<T>::MinHeap()
	: array(1)
{ }


// MinHeap
//	 - constructor 
//	 - inserts oneDatum into array vector 
//	 - initializes size to 1
template <class T>
MinHeap<T>::MinHeap(const vector<T> & unsortedArray, bool fast /* = true */)
	: array(1)
{
	if (fast == true) // BuildHeap version
	{
		// Your code here
	}
	else // N repeated insertions version
	{
		// Your code here
	}
}

// size - returns the number of elements in the heap
template<class T>
inline int MinHeap<T>::size() const
{
	return array.size() - 1;
}

// clear
// removes all values from the heap by setting size to 0
template <class T>
void MinHeap<T>::clear()
{
	array.resize(1);
}

// findMin
//  - return value:  reference to the least element in the heap;
//  - assumes heap is not empty
template <class T>
T const & MinHeap<T>::findMin() const
{
	return array[1];
}

// removeMin
//	- returns an element of type T that is the least
//	  element in the heap.  
//	- removes that element from the heap and reheapifies 
template <class T>
T MinHeap<T>::removeMin()
{
	if (isEmpty())
	{
		std::cout << "empty heap" << std::endl;
		return T();
	}

	T temp = array[1];
	array[1] = array[size()];
	array.resize(array.size()-1);
	heapifyDown(1);
	return temp;
}


// insert
//	- insElem - the item to be inserted into the minHeap
//	- performs the insert and reheapifies
template <class T>
void MinHeap<T>::insert(T const & insElem)
{
	array.push_back(insElem);
	heapifyUp(size());
}

// isEmpty
//  - returns true if there is no data in the heap
//  - returns false, otherwise
template<class T>
inline bool MinHeap<T>::isEmpty() const
{
	return (size() == 0);
}

// heapifyDown
//  - helper function traverses tree restoring heap property
template<class T>
void MinHeap<T>::heapifyDown(int cIndex)
{
	// Your code here
	// You will probably find it helpful to declare your own
	// helper functions to implement this
}

// heapifyUp
//  - helper function traverses tree restoring heap property
template<class T>
void MinHeap<T>::heapifyUp(int cIndex)
{
	if (cIndex > 1)
	{
		int tempParent = parent(cIndex);
		if (array[cIndex] < array[tempParent])
		{
			swap(array[cIndex], array[tempParent]);
			heapifyUp(tempParent);
		}
	}
}

// parent
//  - returns the index of the parent of cIndex
template<class T>
inline int MinHeap<T>::parent(int cIndex) const
{
	return cIndex/2;
}

// swap
//  - swaps the values of the input parameters
template<class T>
inline void MinHeap<T>::swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}


// print
//  - prints out the heap's array
template<class T>
void MinHeap<T>::print() const
{
	std::cout << "[ - ";
	for (unsigned int i = 1; i < array.size(); i++)
		std::cout << array[i] << ' ';
	std::cout << ']';
}
