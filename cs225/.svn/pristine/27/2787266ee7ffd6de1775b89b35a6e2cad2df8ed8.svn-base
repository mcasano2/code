//============================================================
//   file: queue.cpp
//   description: Queue class implemented with stacks
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================

#include <iostream>

using namespace std;

// enqueue adds inpuit newItem to the back of queue
	template<class T>
void Queue<T>::enqueue(T const & newItem)
{
	outStack.push(newItem);
}

// dequeue pops front element of queue and returns it
	template<class T>
T Queue<T>::dequeue()
{
	T temp;	
	//reversed queue written to inStack
	while (!outStack.isEmpty()) {
		inStack.push(outStack.pop());
	}	
	// element to be returned is popped
	temp=inStack.pop();
	//restore stack
	while (!inStack.isEmpty()) {
		outStack.push(inStack.pop());
	}    
	return temp;
}

// peek returns the front element
	template<class T>
T Queue<T>::peek()
{
	T temp;
	//reversed queue written to inStack
	while (!outStack.isEmpty()) {
		inStack.push(outStack.pop());
	}
	// element to be returned is peeked
	temp=inStack.peek();
	while (!inStack.isEmpty()) {
		outStack.push(inStack.pop());
	}    
	return temp;
}

// isEmpty returns 1 for empty and 0 for nonempty
template<class T>
bool Queue<T>::isEmpty() const
{
	if (outStack.isEmpty()) {
		return 1;
	}
	else {
		return 0;
	}
}
