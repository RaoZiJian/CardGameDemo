//
//  GameManager.h
//  CardGameDemo
//
//  Created by Kirito on 5/16/14.
//
//

#ifndef __CardGameDemo__GameManager__
#define __CardGameDemo__GameManager__

#include "cocos2d.h"
#include "Common.h"

class GameManager{
    
public:
    
    static GameManager* getInstance();
    void loading(Node* node);
    void unLoading();
};

#endif /* defined(__CardGameDemo__GameManager__) */
