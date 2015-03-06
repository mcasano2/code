/**
* C.S. 225 Lab
* translator.h
* Written by Alex Lambert <alamber3@uiuc.edu>.
* Updated in spring 2008.
* Modified by Kyle Johnson in fall 2010.
**/


#ifndef TRANSLATOR_H
#define TRANSLATOR_H


#include <iostream>
#include <string>

#include "stringAVLTree.h"
#include "translator.h"


using namespace std;


/**
*  This class serves as a blueprint for a Translator foreign language dictionary
*  object which allows one to insert English-Spanish word pairs into the 
*  dictionary, get an English translation of a Spanish word or print out all 
*  words in the dictionary.
**/
class Translator {
private:
    StringAVLTree spanishToEnglish;
    
public:

   Translator();

   void insert(string const & englishWord, string const & spanishWord);
   string getEnglish(string const & spanishWord) const;
   friend ostream & operator<<(ostream & out, Translator & translator);
};


#endif
