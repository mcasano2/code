//============================================================
//   file: mp3extras.cpp
//   description: mp3 source file for extra functions
//   date: 27 Feb 2011
//   Machine Problem 3.2
//============================================================

#include <iostream>
#include "doubly-linked-list.h"

using namespace std;


// adds endList to the end of this.List, then clears endList
// endlist is input List passed by reference, not same object as this
template <typename Etype>
void List<Etype>::appendList(List<Etype> & endList)
{
    tail->next = endList.head;  // links this.list tail to start of endList
    endList.head->prev = tail;  // links endList head prev to end of this list
    tail=endList.tail;          // combined list tail is endList tail
    size = size + endList.size; // combined list is the size of both

    endList.head = NULL;        // make endList empty
    endList.tail = NULL;
    endList.size = 0;
}


// splits this.List into 2 separate Lists at position rank
// rank is the integer input which is >= to 1
// creates second List and returns it
template <typename Etype>
List<Etype> List<Etype>::splitList(int rank)
{
    List<Etype> tmp;   // temporary list to return second list

    current=head;      // 1st position is head of this list 

    // initialize tmp List to empty 
    tmp.head= NULL;
    tmp.tail= NULL;
    tmp.size= 0;

    // check if rank is out of range
    if (rank > size) {
        return tmp;  // return empty list if out of range
    }

    // current will point to rankth element after loop
    for (int i=1; i<rank; ++i) {
        current=current->next;
    }

    // make head and tail point to correct places
    tmp.head= current;
    tmp.tail= tail;
    tail= current->prev;

    // set tail and head to point to NULL
    tmp.tail->next=NULL;
    tmp.head->prev = NULL;
    tail->next = NULL;

    // set correct sizes
    tmp.size= size + 1 - rank;
    size= size - tmp.size;

    return tmp;   // return second list
}

// this function mixes in a second list with the current one
// then clears the second list
// secList is input list which is never the same object as current List
template <typename Etype>    
void List<Etype>::mixList(List<Etype> & secList)
{
    ListNode * second;  // points to node in other list
    ListNode * third;   // points to current->next so that node can be
                        // accessed while changing current

    current = head;         // 1st (current) is head of this list
    second = secList.head;  // 2nd is head of secList
    third = current->next;  // 3rd is 2nd element of current list

    size = size + secList.size; // size of new list is size of both

    // changes tail to tail of second list if appropriate
    if (secList.size >= size) {
        tail=secList.tail;
    }    

    // mixes lists until end of one is reached
    while (second != NULL) {  
        current->next = second;  // current next points to other list element
        second->prev = current;  // other list element linked to current
        current= second;         // current, second, third advance
        second= third;           
        third=current->next;
    }
     
    // make secList empty       
    secList.head= NULL;
    secList.tail= NULL;
    secList.size= 0;
}

// removes a block of size blockSize at each Nth position
// blockSize is input for the size of block and N is input for Nth position
// blockSize and N are greater than 0
template <typename Etype> 
void List<Etype>::removeNth(int N, int blockSize)
{
    int x=1;                        // x is blockSize counter
    int y=1;                        // y is N counter
    int exit=0;                     // used to leave function
    ListNode * second;              // points to node after current
    ListNode * last;                // points to node at end of previous block

    current=head;                   // start at beginning of list

    if (N==1) {                     // remove whole list if N=1
        size=0;
        while (current != NULL) {   // cycles through list deleting every node
            second=current->next;   
            delete current;        
            current= second;
        }
    return;                         // exits after deleting list
    }

    if (N*blockSize>size) {         // tests if out of range
        exit=1;                     // exit =1 to skip the while loop
    }   

    while (exit == 0) {     
        second=current->next; 
        if (y==N) {                 // true when N counter is on Nth block
            delete current;         // deletes node
            size= size-1;           // adjusts size of list
            if (second==NULL) {     // returns if at end of list, sets tail
                last->next=NULL;
                tail=last->next;
                return;
            }
        }
        if (second==NULL) {         // tests end of list when N counter != N)
            tail=current;
            return;
        }  
        
        if (x != blockSize) {       // block tracker is incremented
            x=x+1;                  // if in the middle of block
        }
        else {                      // else statement for end of block
            x=1;                    // reset block counter to 1
            if (y != N) {           // for when not on Nth block
                last=current;       // sets last to end of current block
                y=y+1;              // N counter incremented
            }
            else {
                y=1;                // resets N counter when end of Nth block
                                    // is reached
                second->prev= last; // links next block to last block
                last->next= second;  
            }
        }
        current=second;             // current is set to next ListNode
    }
}

// blockSize takes int input which is size of the blocks
// A,B,C is a group of 3 blocks which is rearranged to B,C,A
// blockSize is positive
template <typename Etype> 
void List<Etype>::tripleRotate(int blockSize)
{
    ListNode * aFirst;    // points to first node of A    
    ListNode * aLast;     // points to last node of A    
    ListNode * bFirst;    // points to first node of B    
    ListNode * cLast;     // points to last node of C    
    ListNode * before;    // points to node before aFirst    
    ListNode * after;     // points to node after cLast
    
    current=head;         // sets current to start at beginning of list

    // each time through loop rearranges a group of 3 blocks until end
    for (int i=1; (3*blockSize*i)<= size; i++) {   // ends after last group

        // calculate pointer positions
        aFirst=current;
        before=aFirst->prev;
        for (int x=1; x<blockSize; x++) {  // advances through block A
            current=current->next;
        }                                  // current points to last node of A
        aLast=current; 
        bFirst= aLast->next;
        current = bFirst;                  // current set to start of B
        if (i==1) {
        head=bFirst;                       // sets correct head position
        }
        for (int y=1; y<blockSize; y++) {  // advances through block B
            current=current->next;
        }                                  // current points to last node of B
        current=current->next;             // current points to first of C
        for (int z=1; z<blockSize; z++) {  // advances through block C
            current=current->next;
        }                                  // current points to last of C
        cLast=current;
        after=cLast->next;

// Pointers positions are correct, now prev/next values can be
// changed to go from A,B,C to B,C,A
        bFirst->prev=before;        // link B to node from last group
        if (before != NULL) {
            before->next=bFirst;
        }
        cLast->next=aFirst;         // C is linked to A
        aFirst->prev=cLast;
        aLast->next=after;          // A is linked to next node
        if (after != NULL) {
            after->prev=aLast;
        }
        current=after;   // current set to first element of next group (new A)
    }                // closing brace for outmost for loop

    current=aLast;       // current set to last node    
    while (current->next != NULL) {  // finds end of list
        current=current->next;
    }
    tail=current;       // current points to end of list, which is tail
}
