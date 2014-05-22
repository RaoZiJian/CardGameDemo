//
//  Utile.h
//  CardGameDemo
//
//  Created by Kirito on 5/19/14.
//
//

#ifndef __CardGameDemo__Utile__
#define __CardGameDemo__Utile__

#include <iostream>
#include <sstream>

using namespace std;

class Utile{
    
public:
    
    static string string_replace(string & strBig, const string & strsrc, const string &strdst);
    static string convertIntToString (int aNum);
};

#endif /* defined(__CardGameDemo__Utile__) */
