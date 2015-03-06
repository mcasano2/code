/*
   Anagram Finder (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "anagram_finder.h"
#include "char_counter.h"
#include "char_counter.cpp"

AnagramFinder::AnagramFinder( string ifile ) : file(true), filename(ifile) {
    /* nothing */
}

AnagramFinder::AnagramFinder( vector<string> istrings ) : file(false),
    strings(istrings) {
    /* nothing */
}

bool AnagramFinder::checkWord( string const & word, string const & test ) {
   CharFreq a(word);
   CharFreq b(test);
   vector< pair<char, int> > A=a.getChars(1);
   vector< pair<char, int> > B=b.getChars(1);
   int size;
   if (A.size() > B.size() ) {
   size=A.size();
   }
   else {
   size=B.size();
   }
   for (int i=0; i<size; i++) {
   if ((A[i].first)!=(B[i].first)||(A[i].second)!=(B[i].second)) {
   return false;
   }
   }
   return true;
   
}

vector<string> AnagramFinder::getAnagrams( string word ) {
    // set up the return vector
    vector<string> ret;

    if( file ) {
        TextFile infile( filename );
        string line;
        vector<string> tests;
        while( infile.good() ) {
            string test = infile.getNextWord();
            if( checkWord( word, test ) ) 
                ret.push_back( test );
        }
    } else {
        for( unsigned int i = 0; i < strings.size(); i++ ) {
            if( checkWord( word, strings[i] ) )
                ret.push_back( strings[i] );
        }
    }
    return ret;
}

void AnagramFinder::writeAnagrams( string word, string filename ) {
    vector<string> anagrams = getAnagrams( word );
    ofstream outfile(filename.c_str());
    if( outfile.is_open() ) {
        for( unsigned int i = 0; i < anagrams.size(); i++ )
            outfile << anagrams[i] << endl;
    }
    outfile.close();
}
