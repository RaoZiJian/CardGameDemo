//
//  Utile.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/19/14.
//
//

#include "Utile.h"

string Utile::string_replace(string & strBig, const string & strsrc, const string &strdst){
    
    string::size_type pos=0;
    string::size_type srclen=strsrc.size();
    string::size_type dstlen=strdst.size();
    
    while( (pos=strBig.find(strsrc, pos)) != string::npos)
    {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
    
    return strBig;
}