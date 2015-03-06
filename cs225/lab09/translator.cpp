/**
* C.S. 225 Lab
* translator.cpp
* Written by Alex Lambert <alamber3@uiuc.edu>.
* Updated in spring 2008.
* Modified by Kyle Johnson in fall 2010.
**/


#include "translator.h"


/**
*  The default Translation constructor creats an empty dictionary.
**/
Translator::Translator() : spanishToEnglish() {}


/**
*  This function adds an English word pair to the dictionary.
*
*  @param englishWord:  a constant reference to a string containing an English
*  word.
*  @param spanishWord:  a constant reference to a string containing a Spanish
*  word.
**/
void Translator::insert(string const & englishWord, string const & spanishWord) {
   spanishToEnglish.insert(spanishWord, englishWord);
}


/**
*  Given a Spanish word, this function finds and returns the equivalent 
*  English word or the empty string ("") if the word is not in the dictionary.
*  
*  @param spanishWord:  a constant reference to a string containing a Spanish 
*  word.
**/
string Translator::getEnglish(string const & spanishWord) const {
   return spanishToEnglish.find(spanishWord);
}


/**
*  Overloaded << operator.  Puts the internal state of dictionaries on the 
*  parameter stream.
**/
ostream & operator<<(ostream & out, Translator & translator) {
   out << "-- Spanish-to-English dictionary state:" << endl;
   out << translator.spanishToEnglish;
   out << endl;
   return out;
}
