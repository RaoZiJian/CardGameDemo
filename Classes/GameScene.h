//
//  GameScene.h
//  CardGameDemo
//
//  Created by Kirito on 5/20/14.
//
//

#ifndef __CardGameDemo__GameScene__
#define __CardGameDemo__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "Common.h"

USING_NS_CC;

class GameScene : public Scene{
    
public:
    bool init();
    CREATE_FUNC(GameScene);
};

class GameLayer : public Layer{
    
public:
    bool init();
    CREATE_FUNC(GameLayer);
    
};

class CharInfo : public Node{
    
public:
    bool init();
    CREATE_FUNC(CharInfo);
    void updateInfo(std::string name, std::string level);
    
private:
    Label *_name;
    Label *_level;
    Sprite *_vit;
};

#endif /* defined(__CardGameDemo__GameScene__) */
