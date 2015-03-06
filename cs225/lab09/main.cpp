/**
* C.S. 225 Lab 9
* main.cpp
* Created by Daniel Hoodin in spring 2008.
* Modified by Kyle Johnson in fall 2010.
**/


#include <iostream>
#include <sstream>
#include <string>
#include "translator.h"


using namespace std;


/**
*  Expected strings.  Each test case (below) uses one of these strings to verify
*  that the AVLTree rotate functions have been implemented properly.
**/
string expectedRotateLeft = "-- Spanish-to-English dictionary state:\nNULL\n\n-- Spanish-to-English dictionary state:\n  [cosa]  \n\n-- Spanish-to-English dictionary state:\n        [cosa]  \n        /    \\  \n   NULL      [lugar]  \n\n-- Spanish-to-English dictionary state:\n       [lugar]  \n       /     \\  \n  [cosa]     [tierra] \n\n";
string expectedRotateRight = "-- Spanish-to-English dictionary state:\nNULL\n\n-- Spanish-to-English dictionary state:\n [tierra] \n\n-- Spanish-to-English dictionary state:\n       [tierra] \n       /      \\ \n [lugar]       NULL   \n\n-- Spanish-to-English dictionary state:\n       [lugar]  \n       /     \\  \n  [cosa]     [tierra] \n\n";
string expectedRotateLeftRight = "-- Spanish-to-English dictionary state:\nNULL\n\n-- Spanish-to-English dictionary state:\n [tierra] \n\n-- Spanish-to-English dictionary state:\n       [tierra] \n       /      \\ \n  [cosa]       NULL   \n\n-- Spanish-to-English dictionary state:\n       [lugar]  \n       /     \\  \n  [cosa]     [tierra] \n\n";
string expectedRotateRightLeft = "-- Spanish-to-English dictionary state:\nNULL\n\n-- Spanish-to-English dictionary state:\n  [cosa]  \n\n-- Spanish-to-English dictionary state:\n        [cosa]  \n        /    \\  \n   NULL      [tierra] \n\n-- Spanish-to-English dictionary state:\n       [lugar]  \n       /     \\  \n  [cosa]     [tierra] \n\n";
string expectedRotateCombination = "-- Spanish-to-English dictionary state:\n                                           [lugar]  \n                                           /     \\  \n                      [casa]                                     [nombre] \n                      /    \\                                     /      \\ \n         [ayuda]                [cosa]                  [mano]              [profeta] \n         /     \\                /    \\                  /    \\              /       \\ \n  [agua]    [caridad]    [comida]    [fuego]      [luna]     [noche]     [perro]     [tierra] \n\n";
string expectedComida = "food";
            

/**
*  This function compares two strings (the actual string extracted from the 
*  Translator/AVL Tree and the expected string) and prints them out if they 
*  differ.  It is used as a helper function by all of the tests.  It returns a
*  boolean value indicating whether the two strings were identical.
*
*  @param out: The output stream to print to if the strings differ.
*  @param actualString: The string extracted from the Translator/AVL Tree.
*  @param expectedString: The expected string.
*  @return A boolean value indicating whether the two strings were identical.
**/
bool compare(ostream & out, string actualString, string expectedString) {
   if(actualString == expectedString) {
      out << "PASS" << endl;
      
      return true;
   }
   else {
      out << "FAIL" << endl << endl;
      out << "Actual:" << endl << actualString << endl << "Expected:" << endl << expectedString << endl;
      
      return false;
   }
}


/**
*  This function tests the correctness of the rotateRightLeft function.  The 
*  status and results of the test are printed to the given output stream and the
*  function returns a boolean value indicating whether the test was successful.
*
*  @param out: The output stream to print the status and results of the test to.
*  @return A boolean value indicating whether the test was successful.
**/
bool testRotateRightLeft(ostream & out) {
   out << "Testing Right-Left Rotation...  ";
   Translator theTranslator;
   ostringstream os;

   os << theTranslator;
   theTranslator.insert("thing", "cosa");
   os << theTranslator;
   theTranslator.insert("earth", "tierra");
   os << theTranslator;
   theTranslator.insert("place", "lugar");
   os << theTranslator;

   return compare(out, os.str(), expectedRotateRightLeft);
}


/**
*  This function tests the correctness of the rotateLeftRight function.  The 
*  status and results of the test are printed to the given output stream and the
*  function returns a boolean value indicating whether the test was successful.
*
*  @param out: The output stream to print the status and results of the test to.
*  @return A boolean value indicating whether the test was successful.
**/
bool testRotateLeftRight(ostream & out) {
   out << "Testing Left-Right Rotation...";
   Translator theTranslator;
   ostringstream os;

   os << theTranslator;
   theTranslator.insert("earth", "tierra");
   os << theTranslator;
   theTranslator.insert("thing", "cosa");
   os << theTranslator;
   theTranslator.insert("place", "lugar");
   os << theTranslator;

   return compare(out, os.str(), expectedRotateLeftRight);
}


/**
*  This function tests the correctness of the rotateLeft function.  The 
*  status and results of the test are printed to the given output stream and the
*  function returns a boolean value indicating whether the test was successful.
*
*  @param out: The output stream to print the status and results of the test to.
*  @return A boolean value indicating whether the test was successful.
**/
bool testRotateLeft(ostream & out) {
   out << "Testing Left Rotation...  ";
   Translator theTranslator;
   ostringstream os;

   os << theTranslator;
   theTranslator.insert("thing", "cosa");
   os << theTranslator;
   theTranslator.insert("place", "lugar");
   os << theTranslator;
   theTranslator.insert("earth", "tierra");
   os << theTranslator;
            
   return compare(out, os.str(), expectedRotateLeft);
}


/**
*  This function tests the correctness of the rotateRight function.  The 
*  status and results of the test are printed to the given output stream and the
*  function returns a boolean value indicating whether the test was successful.
*
*  @param out: The output stream to print the status and results of the test to.
*  @return A boolean value indicating whether the test was successful.
**/
bool testRotateRight(ostream & out) {
   out << "Testing Right Rotation...  ";
   Translator theTranslator;
   ostringstream os;

   os << theTranslator;
   theTranslator.insert("earth", "tierra");
   os << theTranslator;
   theTranslator.insert("place", "lugar");
   os << theTranslator;
   theTranslator.insert("thing", "cosa");
   os << theTranslator;
            
   return compare(out, os.str(), expectedRotateRight);
}


/**
*  This function tests the correctness of the rotation functions by combining 
*  all types of rotations. The status and results of the test are printed to the
*  given output stream and the function returns a boolean value indicating 
*  whether the test was successful.
*
*  @param out: The output stream to print the status and results of the test to.
*  @return A boolean value indicating whether the test was successful.
**/
bool testRotateCombo(ostream & out) {
   out << "Testing Rotation Combo...  ";
   Translator theTranslator;
   ostringstream os;

   theTranslator.insert("night", "noche");
   theTranslator.insert("thing", "cosa");
   theTranslator.insert("place", "lugar");
   theTranslator.insert("earth", "tierra");
   theTranslator.insert("food", "comida");
   theTranslator.insert("name", "nombre");
   theTranslator.insert("water", "agua");
   theTranslator.insert("help", "ayuda");
   theTranslator.insert("house", "casa");
   theTranslator.insert("prophet", "profeta");
   theTranslator.insert("charity", "caridad");
   theTranslator.insert("dog", "perro");
   theTranslator.insert("fire", "fuego");
   theTranslator.insert("hand", "mano");
   theTranslator.insert("moon", "luna");
   os << theTranslator;

   return compare(out, os.str(), expectedRotateCombination);
}


// testTranslation
//     - tests the correctness of translation from spanish to english
//     - puts summary of the test on parameter ostream
/**
*  This function tests whether a query to the AVL Tree produces the correct 
*  output.  The status and results of the test are printed to the given output 
*  stream and the function returns a boolean value indicating whether the test 
*  was successful.
*
*  @param out: The output stream to print the status and results of the test to.
*  @return A boolean value indicating whether the test was successful.
**/
bool testTranslation(ostream & out) {
   out << "Testing Translation...  ";
   Translator theTranslator;
   ostringstream os;

   theTranslator.insert("night", "noche");
   theTranslator.insert("thing", "cosa");
   theTranslator.insert("place", "lugar");
   theTranslator.insert("earth", "tierra");
   theTranslator.insert("food", "comida");
   theTranslator.insert("name", "nombre");
   theTranslator.insert("water", "agua");
   theTranslator.insert("help", "ayuda");
   theTranslator.insert("house", "casa");
   theTranslator.insert("prophet", "profeta");
   theTranslator.insert("charity", "caridad");
   theTranslator.insert("dog", "perro");
   theTranslator.insert("fire", "fuego");
   theTranslator.insert("hand", "mano");
   theTranslator.insert("moon", "luna");
   
   os << "*** Looking up the Spanish word 'comida'..." << endl;
   string comidaTranslation = theTranslator.getEnglish("comida");

   if (comidaTranslation == "") {
      os << "Could not find a translation for 'comida'" << endl;
   }
   else {
      os << "The translation is: " << comidaTranslation << endl;
   }

   return compare(out, comidaTranslation, expectedComida);
}


/**
*  The main function which serves as the starting point of execution for all 
*  tests.
**/
int main() {
   bool allPass = true;
   
   cout << endl << "Testing AVL Tree Functionality...  " << endl << endl;
   
   allPass &= testRotateLeft(cout);
   allPass &= testRotateRight(cout);
   allPass &= testRotateLeftRight(cout);
   allPass &= testRotateRightLeft(cout);
   allPass &= testRotateCombo(cout);
   allPass &= testTranslation(cout);
   
   if(allPass) {
      cout << endl << "All tests pass!" << endl << endl;
   }
   else {
      cout << endl << "One or more tests have failed!" << endl << endl;
   }
   
   return EXIT_SUCCESS; 
}
