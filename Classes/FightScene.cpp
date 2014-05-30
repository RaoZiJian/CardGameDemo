//
//  Fight.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/27/14.
//
//

#include "FightScene.h"
#include "Common.h"
#include "Utile.h"

bool FightScene::init(){
    
    if(Scene::init()){
        
        auto layer = FightLayer::create();
        addChild(layer);
        
        return true;
    }
    return false;
}

void FightScene::onOpen(Ref *sender){
    
    Director::getInstance()->replaceScene(FightScene::create());
}

bool FightLayer::init(){
    
    if(Layer::init()){
        
        _bgOffset = Size(98,92);
        
        auto background =Sprite::create("textures/IMG_Background/bg_fight.png");
        background->setPosition(VisibleRect::center());
        addChild(background);

        ReadString* rs = ReadString::getInstance("json/combat.json");
        
        for(int i=1;i<3;i++){
            
            auto monsterCard = rs->read(i, "Monster");
            _monsterVec.pushBack(CardNode::createWithCombat(monsterCard));
            
            auto myCard = rs->read(i, "My");
            _myVec.pushBack(CardNode::createWithCombat(myCard));
            
            auto combat = rs->readCombat();
            _combatVec.pushBack(combat);
            
            auto end = rs->readEnd();
            _endVec.pushBack(end);
        }
        
        initCard();
        initDisplay();
        combatAction(0);
        
        return true;
    }
    return false;
}

void FightLayer::initCard(){
    
    auto fightBackground = Sprite::create("textures/IMG_Background/fight_background.png");
    auto cs = fightBackground->getContentSize();
    
    _bgSize = cs;
    _nFight = LayerColor::create(Color4B(255,0,0,0),cs.width,cs.height);
    _nFight->setAnchorPoint(Point(0.5,0));

    _animalNode = Node::create();
    
    auto p = VisibleRect::topRight()-Point(cs.width,cs.height);
    _nFight->setPosition(p.x/2,p.y/2);
    _animalNode->setPosition(Point(cs.width/2,cs.height/2)+Point(p.x/2,p.y/2));
    
    addChild(_nFight);
    addChild(_animalNode);
    
    auto node = Node::create();
    node->setPosition(cs.width/2,cs.height/2);
    node->addChild(fightBackground);
    _nFight->addChild(node);

    for(auto id=0;id<_myVec.size();id++){
        
        auto myCard = _myVec.at(id);
        auto scale = myCard->getScaleX();
        node->addChild(myCard);
        auto myAn = myCard->getAnimal()->getThisLayer();
        
        auto dcp = myCard->getPosition();
        auto dp = myAn->getPosition();
        auto np = dcp + Point(0, dp.y*scale);
        
        auto nd = Node::create();
        myAn->setScale(scale);
        myAn->setPosition(myAn->getPosition().x,0);
        nd->addChild(myAn);
        
        updatePoint(nd, np);
        _animalNode->addChild(nd);
    }
    
    for(auto ic = 0;ic<_monsterVec.size();ic++){
        
        auto msCard = _monsterVec.at(ic);
        auto cScale = msCard->getScaleX();
        node->addChild(msCard);
        auto msAn = msCard->getAnimal()->getThisLayer();
        
        auto cDcp = msCard->getPosition();
        auto cDp = msAn->getPosition();
        auto dNp = cDcp+Point(0,cDp.y*cScale);
        
        auto cNd = Node::create();
        msAn->setScale(cScale);
        msAn->setPosition(msAn->getPositionX(),0);
        cNd->addChild(msAn);
        
        updatePoint(cNd, dNp);
        _animalNode->addChild(cNd);
    }
}

void FightLayer::combatAction(int index){
    
    if(index>=_combatVec.size()){
        
        runAction(Sequence::create(DelayTime::create(0.6),CallFunc::create(CC_CALLBACK_0(FightLayer::combatEnd, this)) ,NULL));
        return;
    }
 
    auto cb = _combatVec.at(index);
    
    auto attacker = getCardByHash(cb->getAttacker());
    auto beattacked = getCardByHash(cb->getBeattacked());
    
    if(!attacker||!beattacked){
        return;
    }
    
    auto delay =2;

    if (cb->getSkill()>0) {
        
        attacker->attack(cb->getSkill());

        beattacked->runAction(Sequence::create(DelayTime::create(1.4),CallFunc::create([beattacked](){beattacked->hurt(1, true);}),NULL));
        delay = 2.5;
    }else{
        
        attacker->attack(0);
        auto ba = Sequence::create(DelayTime::create(delay),
                                   CallFunc::create([&](){beattacked->hurt(cb->getDamage(), false);}),NULL);
        beattacked->runAction(ba);
    }
    
    auto action = Sequence::create(DelayTime::create(delay),CallFunc::create([index, this](){auto ni = index+1; combatAction(ni);}), NULL);
    
    runAction(action);
}


CardNode* FightLayer::getCardByHash(std::string hash){

    for(auto my : _myVec){
        
        if(hash == my->getCardInfo()->getHash()){
            return my;
        }
    }
    
    for(auto ri : _monsterVec){
        
        if(hash == ri->getCardInfo()->getHash()){
            return ri;
        }
    }
    
    return NULL;
}

void FightLayer::combatEnd(){
    
    auto endLayer = LayerColor::create(Color4B(0,0,0,192),VisibleRect::rect().size.width, VisibleRect::rect().size.height);
    endLayer->setPosition(0,0);
    addChild(endLayer);
    
    auto lblExperience = Label::create();
    lblExperience->setString("Experience:" + Utile::convertIntToString(_endVec.at(0)->getExperience()));
    lblExperience->setSystemFontSize(66);
    lblExperience->setPosition(VisibleRect::center()+Point(0,100));
    
    auto lblisWin = Label::create();
    lblisWin->setString(_endVec.at(0)->getResult()?"You Win !": "You Lost!");
    lblisWin->setSystemFontSize(66);
    lblisWin->setPosition(VisibleRect::center()+Point(0,-100));
    
    endLayer->addChild(lblExperience);
    endLayer->addChild(lblisWin);
}

void FightLayer::updatePoint(Node *nd, Point p){
    
    auto xPercent = -p.x/_bgSize.width*2;
    auto yPercent = (p.y+_bgSize.height/2)/_bgSize.height;
    
    auto xOffset = yPercent*_bgOffset.width*xPercent;
    auto yOffset = yPercent*yPercent*_bgOffset.height;
    
    auto rp = Point(p.x+xOffset,p.y-yOffset);
    auto scale = (_bgSize.width/2-yPercent*_bgOffset.width)/(_bgSize.width/2);
    auto offsetY = (1-scale)*_bgOffset.height/2;
    nd->setPosition(rp+Point(0,offsetY-50));
    nd->setScale(scale);
}

void FightLayer::initDisplay(){
    
    _nFight->setRotation3D(Vertex3F(-20,0,0));
}
