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
class Animal;
class Card : public Node{
    
public:
    
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
    CC_SYNTHESIZE(int, skill, Skill);
    CC_SYNTHESIZE(std::string, damage, Damage);
    CC_SYNTHESIZE(std::string, type, Type);
    
};

class CardNode : public Node{
    
public:
    bool init(Card* card);
    Card* getCardInfo();
    bool isMonster();
    static CardNode* createWithCombat(Card* card);
    static CardNode* createWithInfo(Card* card);
    void updateInfo();
    void updateDisplay(Point scrollViewOffset, float wd);
    Node* getThisNode();
    Animal* getAnimal();
    
private:
    bool _isMonster;
    Animal *_animal;
    Card *_card;
    Node *_node;
    Sprite *_nHp;
    Label *_level;
    Label *_name;
    Label *_hp;
    Label *_atk;
    float _damage = 0;
    static Point* getCardPosition();
};

class Animal : public Node{
    
public:
    
    bool init(Node *node);
    void attack(int effect);
    LayerColor* getThisLayer();

private:
    
    LayerColor *_layer;
    CardNode *_card;
    Point _center;
    Sprite *_animal;
    Sprite *_animate;
    void actCallback(Node* sender);
    void remove(Node* sender);
    void unAnimate();
    Label *_damageLabel;
    ActionInterval *_damageLabelAction;
};

#endif /* defined(__CardGameDemo__Card__) */
