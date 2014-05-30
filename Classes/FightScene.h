//
//  Fight.h
//  CardGameDemo
//
//  Created by Kirito on 5/27/14.
//
//

#ifndef __CardGameDemo__Fight__
#define __CardGameDemo__Fight__

#include <iostream>
#include "cocos2d.h"
#include "Card.h"
#include "ReadString.h"

USING_NS_CC;

class FightScene : public Scene{
    
public:
    bool init();
    CREATE_FUNC(FightScene);
    static void onOpen(Ref *sender);
};

class FightLayer : public Layer{
    
public:
    bool init();
    CREATE_FUNC(FightLayer);
    
private:
    Size _bgSize;
    Size _bgOffset;
    Vector<CardNode*> _monsterVec;
    Vector<CardNode*> _myVec;
    Vector<Combat*> _combatVec;
    Vector<End*> _endVec;
    LayerColor *_nFight;
    Node *_animalNode;
    
    void initCard();
    void updatePoint(Node *nd, Point p);
    void initDisplay();
    void combatAction(int index);
    void combatEnd();
    CardNode* getCardByHash(std::string hash);
};

#endif /* defined(__CardGameDemo__Fight__) */
