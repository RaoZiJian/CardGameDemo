//
//  Card.h
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#ifndef __CardGameDemo__Card__
#define __CardGameDemo__Card__

#include <iostream>
#include "cocos2d.h"
#include "Utile.h"

USING_NS_CC;

class Card : public Node{
    
public:
    
    bool init();
    
    CC_SYNTHESIZE(std::string, name, Name);
    CC_SYNTHESIZE(int, ID, ID);
    CC_SYNTHESIZE(int, HP, HP);
    CC_SYNTHESIZE(int, attack, Attack);
    CC_SYNTHESIZE(int, defence, Defence);
    CC_SYNTHESIZE(int, speed, Speed);
    CC_SYNTHESIZE(int, talent, Talent);
    CC_SYNTHESIZE(int, drop, Drop);
    CC_SYNTHESIZE(int, experience, Experience);
    CC_SYNTHESIZE(int, level, Level);
    CC_SYNTHESIZE(int, status, Status);
    CC_SYNTHESIZE(int, pos, Pos);
    CC_SYNTHESIZE(std::string, damage, Damage);
};

class Animal : public Node{
    
public:
    
    bool init(Node *node);
    void attack(int effect);

private:
    
    LayerColor *_layer;
    Card *_card;
    Point _center;
    Sprite *_animal;
};

#endif /* defined(__CardGameDemo__Card__) */
