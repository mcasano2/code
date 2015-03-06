// **************************************************************
// *                                                            *
// *  doubly-linked-list.def                                    *
// *                                                            *
// *  Definition for a simple generalized (template) list       *
// *   class, implemented via a doubly-linked list              *
// *                                                            *
// *  Written October 2005 by Jason Zych                        *
// *                                                            *
// **************************************************************

#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

// NOTE: doubly-linked-list.h also #includes this file.  Problem?  Well,
//   thanks to the multiple-inclusion guard, things will still work out.
//   This #include is needed in case someone tries to compile this file
//   which, although pointless, should ideally still "work".

#include "doubly-linked-list.h"


// **************** Creation/Destruction/Mass Update




// List
//    - default constructor
//    - initializes list to be empty
template <typename Etype>
List<Etype>::List() : head(NULL), current(NULL), tail(NULL), size(0) 
{
   // initializer list used above; no code needed here
   cout << "Warning: Creating empty List.\n";
}




// List
//    - copy constructor
//    - parameters : origVal - a previously allocated List object
//    - initializes the list to be a copy of origVal
template <typename Etype>
List<Etype>::List(List<Etype> const & origVal)
{
   cout << "Warning: Creating copy of another List.\n";
   copy(origVal);
}




// ~List
//    - destructor
//    - deallocates all dynamically allocated memory associated 
//        with the list
template <typename Etype>
List<Etype>::~List()
{
   clear(); 
}




// operator=
//    - parameters: origVal - a previously allocated List object
//    - return value: reference to this List object, after it's 
//         been assigned to be a copy of the parameter
//    - sets this list to be a copy of origVal
template <typename Etype>
List<Etype> const & List<Etype>::operator=(List<Etype> const & origVal)
{
   cout << "Warning: Entered List::operator=().\n";
   if (this != &origVal)
   {
      clear(); 

      copy(origVal);
   }
   return *this;
} 




// clear
//    - deletes all values from list, resulting in an empty list
template <typename Etype>
void List<Etype>::clear()
{
   cout << "Warning: Entered List::clear().\n";

   typename List<Etype>::ListNode* deletionPtr = head;
   current = head;

   while (deletionPtr != NULL)
   {
      current = current->next;
      delete deletionPtr;
      deletionPtr = current;
   }

   head = NULL;
   current = NULL;
   tail = NULL;
   size = 0;
}




// ************************ Singular Update




// insertAfter
//    - parameters : newElem - an element of the list's type, 
//                       to be inserted
//    - inserts newElem after current position in list (or as
//        the only element in the list, if the list is currently
//        empty), and sets that new element as the current 
//        position. Code does not check to prevent duplicates. 
template <typename Etype>
void List<Etype>::insertAfter(Etype const & newElem)
{
   // The below output had to be commented out so that the given test
   //   cases didn't generate several hundred thousand lines of output.
   //   We will uncomment this during grading, however, to make sure
   //   you don't call this method.  (We'll also use smaller test cases.)  
   //cout << "Warning: Entered List::insertAfter().\n";

   typename List<Etype>::ListNode* tempNode;

   tempNode = new typename List<Etype>::ListNode(newElem);

   if (size == 0)
   {
      head = tempNode;
      current = tempNode;
      tail = tempNode;
   }
   else
   {
      tempNode->next = current->next;      // assignment 1 of 4
      tempNode->prev = current;            // assignment 2 of 4

      current->next = tempNode;            // assignment 3 of 4

      if (tempNode->next != NULL)          //
         tempNode->next->prev = tempNode;  // assignment 4 of 4
      else  // tail == current             //
         tail = tempNode;                  //

      current = tempNode;
   }
   ++size; 
}




// insertBefore
//    - parameters : newElem - an element of the list's type, 
//                       to be inserted
//    - inserts newElem before current position in list (or as
//        the only element in the list, if the list is currently
//        empty), and sets that new element as the current 
//        position. Code does not check to prevent duplicates. 
template <typename Etype>
void List<Etype>::insertBefore(Etype const & newElem)
{
   cout << "Warning: Entered List::insertBefore().\n";

   typename List<Etype>::ListNode* tempNode;
   tempNode = new typename List<Etype>::ListNode(newElem);

   if (size == 0)
   {
      head = tempNode;
      current = tempNode;
      tail = tempNode;
   }
   else
   {
      tempNode->next = current;              // assignment 1 of 4
      tempNode->prev = current->prev;        // assignment 2 of 4

      current->prev = tempNode;              // assignment 3 of 4

      if (tempNode->prev != NULL)            //
         tempNode->prev->next = tempNode;    // assignment 4 of 4
      else // head == current                //
         head = tempNode;                    //

      current = tempNode;
   }
   ++size;
}




// remove
//    - removes the element at the current position of the list.
//       Upon completion of the removal, the current position  
//       will be the next element in the list, or if there is no
//       next element, then the first position (or no position at
//       all, if the list is empty). Attempting to remove using a 
//       meaningless current position (which for this class can 
//       only happen when the list is empty) will result in a warning.
template <typename Etype> 
void List<Etype>::remove()
{
   cout << "Warning: Entered List::remove().\n";

   typename List<Etype>::ListNode* removePtr;
 
   if (size == 0)
   {
      cout << "Warning: Attempt to remove an element from an empty list.\n"; 
   }   
   else if (size == 1)
   {
      delete current; 
      head = NULL;
      current = NULL;
      tail = NULL;
      size = 0;
   }
   else 
   {
      removePtr = current;

      // reposition current
      if (current->next != NULL)
         current = current->next;
      else
         current = head;


      // standard code for getting node pointed to by removePtr
      //   out of list
      if (removePtr->prev == NULL)
         head = removePtr->next;
      else
         removePtr->prev->next = removePtr->next;
    
      if (removePtr->next == NULL)
         tail = removePtr->prev;
      else
         removePtr->next->prev = removePtr->prev;
   
 
      // additional "cleanup" work
      delete removePtr;
      --size;
   }
}




// update
//    - parameters : updateElem - an element of the list's type
//    - replaces the value at the current position with updateElem
//      Attempting to update using a meaningless current position
//      (which for this class can only happen when the list is empty)
//      will result in a warning.

// Not available for MP3!  We've left it here so that you can see how
// this List class would normally work.

/*template <typename Etype>
void List<Etype>::update(Etype const & updateElem)
{  
   if (size > 0)
      current->element = updateElem;
   else
      cout << "Warning: Cannot update an element in an empty list.\n"; 
}*/




// ********************* Control of Current Position




// front
//    - makes the first position in the list the current position
//      Attempting to do this when there is no first position in the 
//      list which for this class can only happen when the list is
//      empty) will result in a warning.
template <typename Etype>
void List<Etype>::front()
{
   cout << "Warning: Entered List::front().\n";

   if (size > 0)
      current = head;
   else
      cout << "Warning: Cannot move current to head of an empty list.\n";
}




// back
//    - makes the last position in the list the current position
//      Attempting to do this when there is no last position in the 
//      list (which for this class can only happen when the list is
//      empty) will result in a warning.
template <typename Etype>
void List<Etype>::back()
{
   cout << "Warning: Entered List::back().\n";

   if (size > 0)
      current = tail; 
   else
      cout << "Warning: Cannot move current to tail of an empty list.\n";
}




// forwardOne
//    - moves the current position one position forward in the list.
//      Attempting to move forward from a meaningless current position
//      (which for this class can only happen when the list is empty)
//      will result in a warning. Attempting to move forward from the
//      last position in the list will result in a warning and the
//      current position remaining unchanged.
template <typename Etype>
void List<Etype>::forwardOne()
{
   // output statement removed so that the given testing file doesn't
   // generate several hundred thousand lines of output.  It will be
   // uncommented for grading, however, so we can make sure you didn't 
   // use this function.
   //cout << "Warning: Entered List::forwardOne().\n";

   if (size > 0)   // if there are nodes in the list
   {
      if (current->next != NULL)  // and we are not at the last one
         current = current->next;   // increment the current pointer 
      else
         cout << "Warning: Cannot advance current position past end position.\n";
   }
   else
      cout << "Warning: Cannot move to next position of an empty list.\n";
}




// backwardOne
//    - moves the current position one position backward in the list.
//      Attempting to move backward from a meaningless current position
//      (which for this class can only happen when the list is empty)
//      will result in a warning. Attempting to move backward from the
//      first position in the list will result in a warning and the
//      current position remaining unchanged.
template <typename Etype>
void List<Etype>::backwardOne()
{
   cout << "Warning: Entered List::backwardOne().\n";

   if (size > 0)   // if there are nodes in the list
   {
      if (current->prev != NULL)  // and we are not at the first one
         current = current->prev;   // increment the current pointer
      else
         cout << "Warning: Cannot decrement current position when at first element.\n";
   }
   else
      cout << "Warning: Cannot move to previous position of an empty list.\n";
}




// ******************** Information Access




// retrieve
//    - returns the element at the current list position
//      Attempting to retrieve from a meaningless current position
//      (which for this class can only happen when the list is empty)
//      will result in an error message and termination of program.

// Slightly changed for MP3

template <typename Etype>
Etype const & List<Etype>::retrieve() const
{
   // Spurious warnings withheld.  This function wouldn't help you much anyway.

   if (size <= 0) {
      cout <<  "Error: Cannot Retrieve an element from an empty list.";
      // give up?
      exit(0);
   } 

   return current->getElement();    
}




// find
//    - parameters : queryElem - a reference to an object of the
//                    generic type; the object cannot be changed
//                    through the parameter reference. This item
//                    will be searched for in the list
//    - return value : boolean with true indicating value was found
//    - searches list for queryElem; if found, make that position
//         the current position and return true; otherwise, return
//         false and do not change what position is marked as the
//         current position. Assumes existence of operator== for
//         generic type.
template <typename Etype>
bool List<Etype>::find(Etype const & queryElem)
{
   cout << "Warning: Entered List::find().\n";

   typename List<Etype>::ListNode* searchPtr = head;
   bool result;

   while ((searchPtr !=NULL) && (searchPtr->getElement() != queryElem))
      searchPtr = searchPtr->next; 

   if (searchPtr == NULL)    // stopped because ran out of values
      result = false;
   else                      // stopped because search key was found
   {
      current = searchPtr; 
      result = true;
   }
   return result;
}




// length
//    - return value : a non-negative integer holding the
//        length of the list
//    - returns the length of the list
template <typename Etype>
int List<Etype>::length() const
{
   // Spurious warnings withheld.  This function DEFINITELY wouldn't help.

   return size; 
}




// print
//    - prints out the values in the list, in order by position
//        from first to last position. Assumes existence of
//        operator<< for generic type.
template <typename Etype>
void List<Etype>::print() const
{
   // Spurious warnings withheld.  This function would print stuff anyway.

   typename List<Etype>::ListNode* outPtr = head;

   if (size == 0)
      cout << "< empty list >";  
   else
   { 
      cout << "< "; 
      while (outPtr != NULL)  
      {
         cout << outPtr->getElement() << " ";
         outPtr = outPtr->next; 
      } 
      cout << ">";
   } 
}




// copy
//    - parameters : origVal - a previously allocated List object
//    - sets the list to be a copy of origVal; assumes there is no
//         dynamic memory that needs to be cleaned out of the list
template <typename Etype>
void List<Etype>::copy(List<Etype> const & origVal)
{
   cout << "Warning: Entered List::copy().\n";

   typename List<Etype>::ListNode* paramListPtr;
   typename List<Etype>::ListNode* thisListPtr;
   typename List<Etype>::ListNode* newestNode;

   paramListPtr = origVal.head;
   if (paramListPtr == NULL)  // then origList is empty
   {
      head = NULL;
      current = NULL;
      tail = NULL;
      size = 0;
   }
   else
   {
      while (paramListPtr != NULL)
      {
         newestNode = new typename List<Etype>::ListNode(paramListPtr->getElement());

         if (paramListPtr == origVal.head)
         {
            thisListPtr = newestNode;
            head = thisListPtr;
         }
         else                   // adding some other non-first node to list
         {
            thisListPtr->next = newestNode;
            newestNode->prev = thisListPtr;
            thisListPtr = thisListPtr->next;
         }

         if (paramListPtr == origVal.current)  // this runs, first or not
            current = thisListPtr;
         paramListPtr = paramListPtr->next;
      }
      tail = thisListPtr;
      size = origVal.size;
   }
}



// atBack
//   - returns whether current node is the tail.  Do not trust
//     return value for an empty list.
template <typename Etype>
bool List<Etype>::atBack() const
{
   cout << "Warning: Entered List::atBack().\n";

   return(current == tail);
}
 


// ListNode
//    - constructor
//    - initializes element to default Etype, and pointers to NULL
template <typename Etype>
List<Etype>::ListNode::ListNode() : next(NULL), prev(NULL), element()
{
   // output statement removed so that the given testing file doesn't
   // generate several hundred thousand lines of output.  It will be
   // uncommented for grading, however, so we can make sure you didn't 
   // use this function.
   //cout << "Warning: Entered ListNode constructor.\n";

   // no code needed here due to initializer list above
}




// ListNode
//    - constructor
//    - parameters : value - the value to store in the element field
//    - initializes node to hold value and NULL pointers
template <typename Etype>
List<Etype>::ListNode::ListNode(Etype const & value) :
                                     next(NULL), prev(NULL), element(value)
{
   // output statement removed so that the given testing file doesn't
   // generate several hundred thousand lines of output.  It will be
   // uncommented for grading, however, so we can make sure you didn't 
   // use this function.
   //cout << "Warning: Entered ListNode constructor.\n";

   // no code needed here due to initializer list above
}


// ListNode::getElement
//    - returns the element in this ListNode
// Added for MP3
template <typename Etype>
Etype const & List<Etype>::ListNode::getElement() const
{
   return element;
}


