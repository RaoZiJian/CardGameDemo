//
//  Login.h
//  CardGameDemo
//
//  Created by Kirito on 5/15/14.
//
//


#ifndef CardGameDemo_Login_h
#define CardGameDemo_Login_h

#include "cocos2d.h"

USING_NS_CC;

class CharacterLayer : public Layer{
    
public:
    
    bool init();
    CREATE_FUNC(CharacterLayer);
private:
    
    void callCreate();
};

#endif
