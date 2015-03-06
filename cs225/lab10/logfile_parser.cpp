/*
   Logfile Parser (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "logfile_parser.h"

#include <iostream>

// creates a LogLine from the given line---you can ignore this.
LogfileParser::LogLine::LogLine( string line ) {
    istringstream iss( line );
    iss >> customer;
    customer = customer.substr(1, customer.length()-3);
    iss >> url;
    string dte = "";
    string dline;
    do {
        iss >> dline;
        dte += dline;
    } while( iss );

    date = time(NULL);
    tm * tme = localtime( &date );
    strptime( dte.c_str(), "%c", tme );
    date = mktime( tme );
}

LogfileParser::LogfileParser( string fname ) : whenVisitedTable(256, hasher) {
    SCHashTable< string, bool > pageVisitedTable(256, hasher);
    ifstream infile( fname.c_str() );
    string line;
    bool testit=true;
    		vector<string>::iterator it;
    while( infile.good() ) {
        getline( infile, line );
        
        // if the line's length is 0, move to the next loop iteration
        if( line.length() == 0 )
            continue;

        LogLine ll( line );
        whenVisitedTable.insert(ll.url,ll.date);
       for (it=uniqueURLs.begin(); it<uniqueURLs.end(); it++) {
        if ( (*it)==(ll.url) ) {
        testit=false;
        }
        }
        if (testit){
        uniqueURLs.push_back(ll.url);
        }
        // given the LogLine above, update the member variable hash table and
        // any other hash tables necessary to solve this problem. this should
        // also build the uniqueURLs vector.
    }
}

pair< bool, time_t > LogfileParser::dateVisited( string customer, string url ) {
    pair< bool, time_t > ret;
    bool a=whenVisitedTable.keyExists(url);
    time_t temp=whenVisitedTable.find(url);
    ret.first=a;
    ret.second=temp;
    return ret;
}

vector<string> LogfileParser::uniquePages() {
    return uniqueURLs;
}
