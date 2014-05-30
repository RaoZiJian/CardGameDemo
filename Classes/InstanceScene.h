//
//  InstanceScene.h
//  CardGameDemo
//
//  Created by Kirito on 5/27/14.
//
//

#ifndef __CardGameDemo__InstanceScene__
#define __CardGameDemo__InstanceScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class InstanceScene : public Scene{
    
public:
    
    bool init();
    CREATE_FUNC(InstanceScene);
    static void onOepn(Ref *sender);
};

class InstanceLayer : public Layer{
    
public:
    
    bool init();
    CREATE_FUNC(InstanceLayer);
    
private:
    
    void showLevel(int level);
    void onLoad(Node *node);
};

#endif /* defined(__CardGameDemo__InstanceScene__) */
