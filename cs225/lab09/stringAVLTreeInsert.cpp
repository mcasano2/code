/**
* C.S. 225 Lab
* stringAVLTree.cpp
* Written by Alex Lambert <alamber3@uiuc.edu>
* Updated in spring 2008.
* Modified by Kyle Johnson in fall 2010.
**/


#include "stringAVLTree.h"


/**
*  This function add a (key, value) pair to the AVL Tree.
*
*  @param subbtree: A reference to a pointer to root of destination subtree.
*  @param theKey: A constant reference to a string containing the key.
*  @param theValue: A constant reference to a string containing the value.
**/
void StringAVLTree::insert(AVLTreeNode *& subtree, string const & theKey, string const & theValue) {

}


/**
*  This function performs a single right rotation.
*  
*  @param node: A reference to a tree node pointer about which to rotate.
**/
void StringAVLTree::rotateRight(StringAVLTree::AVLTreeNode *& node) {

}


/**
*  This function performs a right-left double rotation.
*  
*  @param node: A reference to a tree node pointer about which to rotate.
**/
void StringAVLTree::rotateRightLeft(StringAVLTree::AVLTreeNode *& node) {

}


/**
*  This function is a public wrapper function which can be called by client 
*  code to insert a key-value pair element into the AVLTree.  The sole purpose 
*  of this function is to preserve encapsulation and resultantly, it simply 
*  calls the private helper function with the same name on the root node.
*
*  @param theKey: A constant reference to a string which contains the key.
*  @param theValue: A constant reference to a string which contains the value.
**/
void StringAVLTree::insert(string const & theKey, string const & theValue) {
   insert(root, theKey, theValue);
}
