//
//  Card.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#include "Card.h"
#include "Common.h"

bool Card::init(){
    
    if(Node::init()){
        
        
        
        return true;
    }
    
    return false;
}

bool Animal::init(Node *node){
    
    if(Node::init()){
        
        _card = (Card*)node;
        std::string str1 = *new std::string("textures/IMG_Animals/card_animal_");
        std::string str2 = *new std::string(Utile::convertIntToString(_card->getID()));
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
            
            auto etk2 = Sprite::create("texutres/IMG_Attack/attack_effect_1_2.png");
            etk2->setPosition(VisibleRect::center()+Point(250,700));

            auto actionEtk2 = MoveTo::create(0.3, VisibleRect::center()+Point(0,80));
            auto actionEtk2_2 = MoveTo::create(0.5, VisibleRect::center()+Point(250,700));
            
//            var actionE2 = cc.Sequence.create(
//                                              cc.DelayTime.create(0.6),
//                                              actionEtk2, cc.CallFunc.create(function(){
//                
//                var etk1l = cc.Sprite.create(IMG.attackEffect["1_1"]);
//                etk1l.setPosition(cc.pAdd(VisibleRect.center(), cc.p(-340, -135)));
//                
//                var etk1r = cc.Sprite.create(IMG.attackEffect["1_1"]);
//                etk1r.setFlipX(true);
//                etk1r.setPosition(cc.pAdd(VisibleRect.center(), cc.p(325, -125)));
//                
//                var fadeOut = cc.FadeOut.create(0.1);
//                etk1l.runAction(fadeOut);
//                etk1r.runAction(fadeOut.copy());
//                
//                effectAtk.addChild(etk1l);
//                effectAtk.addChild(etk1r);				
//                
//            }), actionEtk2_2, cc.CallFunc.create(function(){
//                this.removeFromParent();
//            }, effectAtk));
//            etk2.runAction(actionE2);
//            effectAtk.addChild(etk2);

        }
    }
}