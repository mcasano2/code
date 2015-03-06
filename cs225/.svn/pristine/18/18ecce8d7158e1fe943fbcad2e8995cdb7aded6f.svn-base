/**
* C.S. 225 Lab
* stringAVLTree.h
* Written by Alex Lambert <alamber3@uiuc.edu>.
* Updated in spring 2008.
* Modified by Kyle Johnson in fall 2010.
**/


#ifndef STRINGAVLTREE_H
#define STRINGAVLTREE_H


#include <cmath>
#include <cstddef>
#include <iostream>
#include <queue>
#include <string>


using namespace std;


/**
*  This class serves as a blueprint for an AVLTree object.  Objects of this 
*  class support efficient (O(lg(N)) find and insert operations.
**/
class StringAVLTree {
private:

   /**
   *  This class serves as a blueprint for a single node in an AVLTree.  Objects
   *  of this class contain left and right pointers, height information and a 
   *  pair (a heterogeneous tuple capable of holding two elements) object as 
   *  data.
   **/
   class AVLTreeNode {
      public:
         //The default constructor creates an AVLTreeNode with no children and a default element.
         AVLTreeNode();

         //This constructor creates an AVLTreeNode with no children and the given element.
         AVLTreeNode(pair<string, string> const & theElement);

         AVLTreeNode * left;
         AVLTreeNode * right;
         int height;

         pair<string, string> element;
   };
   

   AVLTreeNode * root;

   //Helper functions used for printing.
   string makeSpacesString(int numSpaces) const;
   int* getLastNodes(int h) const;
   void printSpaces(int numSpaces, ostream& out) const;
   int getSpacing(int lastINode, int index) const; 
   void print(ostream& out) const;
   void printInOrder(AVLTreeNode * subtree, ostream& out) const;
   bool prettyPrint(AVLTreeNode * subtree, ostream& out) const;

   //Private helper functions.
   AVLTreeNode * copy(AVLTreeNode * subtree) const;
   void clear(AVLTreeNode * & subtree);
   void insert(AVLTreeNode *& subtree, string const & theKey, string const & theValue);
   string find(AVLTreeNode * subtree, string const & theKey) const;
   int height(AVLTreeNode const * node) const;
   int max(int a, int b) const;
   void rotateRight(AVLTreeNode *& node);
   void rotateLeft(AVLTreeNode *& node);
   void rotateRightLeft(AVLTreeNode *& node);
   void rotateLeftRight(AVLTreeNode *& node);
    
public:

   StringAVLTree();
   StringAVLTree(StringAVLTree const & origVal);
   ~StringAVLTree();
   
   StringAVLTree const & operator=(StringAVLTree const & origVal);

   void insert(string const & theKey, string const & theValue);
   string find(string const & theKey) const;

   friend ostream & operator<<(ostream & out, const StringAVLTree& tree);   
};


#endif
