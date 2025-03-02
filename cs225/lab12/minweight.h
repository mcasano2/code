/*
    Lab 12: Minimum Weight
    Written by Sean Massung for CS 225 Spring 2011
*/

#ifndef _MINWEIGHT_H_
#define _MINWEIGHT_H_

/*
  Tasks:
    1. Return the minimum edge weight in the Graph g.
    2. Label the minimum edge as "MIN"
        (it will appear blue when g.printPNG() is called in minweight_test!)
  Notes/hints:
    - You are *NOT* allowed to call getAllEdges(), you must do a traversal.
    - You may use the stack and queue classes from the STL if you'd like.
    - You may also use the EdgeData struct if you deem it necessary.
        (it is defined at the top of graph.h for your reference)
*/

#include <stack>
#include <queue>
#include "graph.h"

using std::stack;
using std::queue;

int minWeight(Graph & g);

// define any helper functions here

#endif
