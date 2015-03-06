//============================================================
//   file: stack.cpp
//   description: source file for stack class
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================

#include <iostream>

using namespace std;

// push pushes input newItem to top of stack and returns nothing
	template<class T>
void Stack<T>::push(T const & newItem)
{
	myStack.push_front(newItem);
}

// pop pops the top of the stack and returns the value in temp
	template<class T>
T Stack<T>::pop()
{
	T temp;
	temp = myStack.front();
	myStack.pop_front();
	return temp;
}

// peek returns the top of the stack element without modifying it
template<class T>
T Stack<T>::peek() const
{
	T temp;
	temp = myStack.front();
	return temp;
}

// isEmpty returns 0 if nonempty, 1 if empty
template<class T>
bool Stack<T>::isEmpty() const
{
	if (myStack.empty()) {
		return 1;
	}
	else {
		return 0;
	}
}
