//
//  Card.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#include "Card.h"
#include "Common.h"
#include "stdlib.h"

bool CardNode::init(Card *card){
    
    if(Node::init()){
        
        if(card){
        
            _card = card;
            _isMonster = _card->getType() == "Monster" ? true : false;
        }else{
            _isMonster = false;
        }
        _animal = new Animal();
        _animal->init(this);
    
        _node = Node::create();
        addChild(_node);
        
        std::string spriteImg;
        std::string statusImg;
        
        if (_card->getLevel()>=25) {
            if(_isMonster){
                spriteImg = "textures/IMG_CurrentCard/card_cat_purple.png";
                statusImg = "textures/IMG_CurrentCard/card_cat_orange_status.png";
            }else{
                spriteImg = "textures/IMG_CurrentCard/card_dog_purple.png";
                statusImg = "textures/IMG_CurrentCard/card_dog_purple_status.png";
            }
        }else if(_card->getLevel() >= 15){
            if(_isMonster){
                spriteImg = "textures/IMG_CurrentCard/card_cat_orange.png";
                statusImg = "textures/IMG_CurrentCard/card_cat_purple_status.png";
            }else{
                spriteImg = "textures/IMG_CurrentCard/card_dog_orange.png";
                statusImg = "textures/IMG_CurrentCard/card_dog_orange_status.png";
            }
        }else{
            if(_isMonster){
                spriteImg = "textures/IMG_CurrentCard/card_cat_green.png";
                statusImg = "textures/IMG_CurrentCard/card_cat_green_status.png";
            }else{
                spriteImg = "textures/IMG_CurrentCard/card_dog_green.png";
                statusImg = "textures/IMG_CurrentCard/card_dog_green_status.png";
            }
        }

        auto sprite = Sprite::create(spriteImg);
        auto status = Sprite::create(statusImg);
        
        auto skillA = Sprite::create("textures/IMG_CardStatus/card_skill_1.png");
        skillA->setPosition(237,185);
        status->addChild(skillA);
        auto skillB = Sprite::create("textures/IMG_CardStatus/card_skill_1.png");
        skillB->setPosition(237,102);
        status->addChild(skillB);
        
        auto pLevel = Sprite::create("textures/IMG_CardStatus/card_lv.png");
        _nHp = Sprite::create("textures/IMG_CardStatus/card_hp.png");
        
        status->setPosition(0,-70);
        pLevel->setPosition(42,78);
        _nHp->setPosition(70,148);
        _nHp->setScale(1.0f, 1.0f);
        _nHp->setAnchorPoint(Point(0,0.5));
        
        _node->addChild(sprite);
        _node->addChild(status);
        sprite->addChild(pLevel);
        sprite->addChild(_nHp);
      
        _level = Label::create();
        _level->setString("1");
        _level->setSystemFontSize(50);
        _level->setPosition(-120, -210);
        _node->addChild(_level);

        _name = Label::create();
        _name->setString("cd");
        _name->setSystemFontSize(50);
        _name->setPosition(0, 208);
        _node->addChild(_name);

        _hp = Label::create();
        _hp->setString("1");
        _hp->setSystemFontSize(40);
        _hp->setPosition(-30, -93);
        _node->addChild(_hp);

        _atk = Label::create();
        _atk->setString("1");
        _atk->setSystemFontSize(40);
        _atk->setPosition(-15, -153);
        _node->addChild(_atk);
        
        return true;
    }
    
    return false;
}

Card* CardNode::getCardInfo(){
    
    return _card;
}

bool CardNode::isMonster(){
    
    return _isMonster;
}

CardNode* CardNode::createWithCombat(Card *card){
    
    auto cardNode = new CardNode();
    cardNode->init(card);
    cardNode->updateInfo();
    cardNode->setScale(0.44);

    auto pAry = getCardPosition();
    auto p = pAry[card->getPos()-1];
    auto p2 = card->getType()=="Monster"?Point(-p.x,p.y):p;
    cardNode->setPosition(p2);
    return cardNode;
}

CardNode* CardNode::createWithInfo(Card *card){
    
    auto cardNode = createWithCombat(card);
    cardNode->getThisNode()->addChild(cardNode->getAnimal()->getThisLayer());
    return cardNode;
}

Node* CardNode::getThisNode(){
    return _node;
}

Animal* CardNode::getAnimal(){
    return _animal;
}

Point* CardNode::getCardPosition(){
    
    Point* pointArray = new Point[5];
    
    pointArray[0]=Point(-198,-120);
    pointArray[1]=Point(-198,120);
    pointArray[2]=Point(-370,-225);
    pointArray[3]=Point(-370,0);
    pointArray[4]=Point(-370,225);
    
    return pointArray;
}

void CardNode::updateInfo(){
    
    _level->setString(Utile::convertIntToString(_card->getLevel()));
    _name->setString(_card->getName());
    _hp->setString(Utile::convertIntToString(_card->getHP()));
    _atk->setString(Utile::convertIntToString(_card->getAttack()));
    _nHp->setScaleX(1- _damage/_card->getHP());
}

void CardNode::updateDisplay(Point scrollViewOffset, float wd){

    auto distance = getPosition().x+ scrollViewOffset.x;

    auto value = VisibleRect::center().x-distance;
    
    auto temp = value/VisibleRect::center().x/2.5;
    
    setScale(1- abs(temp));
    
    auto x = value/wd;
 
    _node->setPosition(x*x*x*30,0);
    
    auto pLength = 14450+7720;
    float offset =_node->getPositionX()+7720;
    
    if(offset/pLength<0.342)
        _node->setRotation3D(Vertex3F(0, 90*offset/pLength,0));
    else if (offset/pLength>0.35){
        _node->setRotation3D(Vertex3F(0, -90*offset/pLength,0));
    }
    else
        _node->setRotation3D(Vertex3F(0,0,0));
}

void CardNode::attack(int effect){
    
    _animal->attack(effect);
}

void CardNode::hurt(int damage, bool effect){
    
    auto hurt = damage;
    
    if(_damage+damage>_card->getHP()){
        
        hurt = _card->getHP()-_damage;
        _damage=_card->getHP();
    }else{
        
        _damage = _damage+damage;
    }
    
    if (_damage == _card->getHP()) {
        _animal->die();
    }
    
    updateInfo();
    _animal->hurt(hurt, effect);
}

bool Animal::init(Node *node){
    
    if(Node::init()){
        
        _card = (CardNode*)node;
        std::string str1 = *new std::string("textures/IMG_Animals/card_animal_");
        std::string str2 = *new std::string(Utile::convertIntToString(_card->getCardInfo()->getID()));
        std::string str3 = *new std::string(".png");
        
        _animal = Sprite::create(str1+str2+str3);
        Size animalSize = _animal->getContentSize();
        
        _center = Point(animalSize.width/2,animalSize.height/2);
        _layer = LayerColor::create(*new Color4B(0,0,125,0),animalSize.width,animalSize.height);
        _layer->setPosition(-animalSize.width/2, -animalSize.height/2+50);
        _layer->addChild(_animal);
        _animal->setPosition(_center);
        
        return true;
    }
    
    return false;
}

void Animal::attack(int effect){
    
    if(effect){
        
        if(effect>0){
            auto scale = ScaleBy::create(0.3, 1.3);
            _layer->runAction(Sequence::create(scale,scale->reverse(), NULL));
        }
        
        if(effect==1){
            
            auto effectAtk = Layer::create();
            effectAtk->setPosition(Point(0,0) - VisibleRect::center());
            _layer->getParent()->getParent()->addChild(effectAtk);
            
            auto etk2 = Sprite::create("textures/IMG_Attack/attack_effect_1_2.png");
            etk2->setPosition(VisibleRect::center()+Point(250,700));

            auto actionEtk2 = MoveTo::create(0.3, VisibleRect::center()+Point(0,80));
            auto actionEtk2_2 = MoveTo::create(0.5, VisibleRect::center()+Point(250,700));
            
            auto actionE2 = Sequence::create(DelayTime::create(0.6),actionEtk2, CallFunc::create(CC_CALLBACK_0(Animal::actCallback, this,effectAtk)), actionEtk2_2, CallFunc::create(CC_CALLBACK_0(Animal::remove,this, effectAtk)),NULL);
            
            etk2->runAction(actionE2);
            effectAtk->addChild(etk2);
        }else if(effect == 2){
            
            auto effectAtk2 = Layer::create();
            effectAtk2->setPosition(Point(0,0) - VisibleRect::center());
            _layer->getParent()->getParent()->addChild(effectAtk2);
            
            auto sprite =Sprite::create("textures/IMG_Attack/attack_effect_2_1.png");
            sprite->setPosition(VisibleRect::center());
            effectAtk2->addChild(sprite);
            
            auto ea2 = Animation::create();
            for(int i = 1; i<7;i++){
                
                auto frameName = "textures/IMG_Attack/attack_effect_2_" + Utile::convertIntToString(i) + ".png";
                ea2->addSpriteFrameWithFile(frameName);
            }
            ea2->setDelayPerUnit(0.08f);
            
            sprite->runAction(Sequence::create(DelayTime::create(0.6),Animate::create(ea2),FadeOut::create(0.3) ,NULL));
            effectAtk2->runAction(Sequence::create(DelayTime::create(0.6),DelayTime::create(1.0),CallFunc::create(CC_CALLBACK_0(Animal::remove, this, effectAtk2)), NULL));
            
        }
        return;
    }
    
    if(!_animate){
        
        _animate = Sprite::create("textures/IMG_Attack/attack_1");
        if(_card->isMonster()){
            _animate->setFlippedX(true);
        }
        _animate->cocos2d::Node::setPosition(_center+Point(30,0));
        _layer->addChild(_animate);
        
        SpriteFrame **images;
        
        for(int i=1;i<8;i++){
            
            auto atk =  SpriteFrame::create("textures/IMG_Attack/attack"+Utile::convertIntToString(i)+".png", Rect(0, 0, 312, 219));
            images[i] = atk;
        }
        
        _animate->runAction(Utile::getAnimate(0.08, images, CallFunc::create(CC_CALLBACK_0(Animal::unAnimate, this)), this));
    }else{
        unAnimate();
        attack(5);
    }
}

void Animal::actCallback(Node* sender){
    
    auto etk1l = Sprite::create("textures/IMG_Attack/attack_effect_1_1.png");
    etk1l->setPosition(VisibleRect::center() + Point(-340,-135));
    
    auto etk1r = Sprite::create("textures/IMG_Attack/attack_effect_1_1.png");
    etk1r->setFlippedX(true);
    etk1r->setPosition(VisibleRect::center() + Point(325,-125));
    
    auto fadeOut = FadeOut::create(0.1f);
    etk1l->runAction(fadeOut);
    etk1r->runAction(fadeOut->clone());
    
    sender->addChild(etk1l);
    sender->addChild(etk1r);
}

void Animal::hurt(int damage, bool effect){

    if(!_animate){
        
        _animate = Sprite::create("textures/IMG_Hurt/hurt_1.png");
        _animate->setPosition(_center+Point(0,0));
        _layer->addChild(_animate);
        
        SpriteFrame* images[] = {SpriteFrame::create("textures/IMG_Hurt/hurt_1.png", Rect(0, 0, 148, 200)),SpriteFrame::create("textures/IMG_Hurt/hurt_2.png", Rect(0, 0, 148, 200)),SpriteFrame::create("textures/IMG_Hurt/hurt_3.png", Rect(0, 0, 148, 200))};
        
        if(effect){
            
            _animate->runAction(Utile::getAnimate(0.1, images, CallFunc::create(CC_CALLBACK_0(Animal::unAnimate,this)), this));
        }else{
            
            _animate->runAction(Utile::getAnimate(0.1, images,
                                                  CallFunc::create([&](){
                _animate->setFlippedX(true);
                _animate->runAction(Utile::getAnimate(0.1, images, CallFunc::create(CC_CALLBACK_0(Animal::unAnimate,this)), this));}), this));
        }
        if (!_damageLabel) {
            _damageLabel = Label::create();
            _damageLabel->setString("-"+Utile::convertIntToString(damage));
            _damageLabel->setSystemFontSize(60);
            _damageLabel->setColor(Color3B::RED);
        }
        
        _damageLabel->setPosition(_center+Point(0,80));
        
        auto fadeIn = FadeIn::create(0.3);
        auto fadeOut = FadeOut::create(1.5);
        auto mu = MoveBy::create(1, Point(0,60));
        auto action = Spawn::create(fadeIn,fadeOut, mu,NULL);
        
        _damageLabel->runAction(action);
    }else{
        unAnimate();
        hurt(damage, false);
    }
 }

void Animal::unAnimate(){
    if(_animate){
        _animate->removeFromParent();
        _animate=NULL;
    }
}

void Animal::remove(cocos2d::Node *sender){
    
    removeFromParent();
}

void Animal::die(){
    
    auto t1 = TintTo::create(0.5, 200, 0, 0);
    auto t2 = TintTo::create(1, 100, 100, 100);
    auto action = Sequence::create(t1,t2,NULL);
    _animal->runAction(action);
}

LayerColor* Animal::getThisLayer(){
    return _layer;
}