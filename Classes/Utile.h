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
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class Utile{
    
public:
    
    static string string_replace(string & strBig, const string & strsrc, const string &strdst);
    static string convertIntToString (int aNum);
    static ActionInterval* getAnimate(float dt, SpriteFrame* images[], CallFunc* fc, Node* target);
};

#endif /* defined(__CardGameDemo__Utile__) */
