//
//  InstanceScene.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/27/14.
//
//

#include "InstanceScene.h"
#include "Common.h"
#include "GameScene.h"
#include "GameManager.h"
#include "FightScene.h"

bool InstanceScene::init(){
    
    if(Scene::init()){
        
        auto layer = InstanceLayer::create();
        addChild(layer);
        
        return true;
    }
    
    return false;
}

void InstanceScene::onOepn(Ref *sender){
    
    Director::getInstance()->replaceScene(InstanceScene::create());
}

bool InstanceLayer::init(){
    
    if(Layer::init()){
        
        auto background = Sprite::create("textures/IMG_Background/bg_instance.png");
        background->setPosition(VisibleRect::center());
        addChild(background);
        
        auto levelBg = Sprite::create("textures/IMG_Level/level_bg.png");
        levelBg->setPosition(VisibleRect::top()+Point(-180, -130));
        addChild(levelBg);
        
        auto itemLevel1 = MenuItemImage::create("textures/IMG_Level/level_1.png","textures/IMG_Level/level_1_press.png", CC_CALLBACK_0(InstanceLayer::showLevel, this,1));
        itemLevel1->setPosition(levelBg->getPosition()+Point(-100,0));
        
        auto itemImgBack = MenuItemImage::create("textures/IMG_Button/btn_back.png","textures/IMG_Button/btn_back_press.png", CC_CALLBACK_0(GameScene::openScene, this));
        itemImgBack->setPosition(VisibleRect::topRight()+Point(-120,-120));
        
        auto menu = Menu::create(itemImgBack,itemLevel1, NULL);
        menu->setPosition(0,0);
        
        addChild(menu);
        showLevel(1);
        
        return true;
    }
    return false;
}

void InstanceLayer::showLevel(int level){
    
    auto level_tag = 1000;
//    removeChildByTag(level_tag);
    
    if(level==1){
        
        auto item1 = MenuItemImage::create("textures/IMG_Level/level_1_1.png", "textures/IMG_Level/level_1_1.png", CC_CALLBACK_0(FightScene::onOpen, this));
        
        auto item2 = MenuItemImage::create("textures/IMG_Level/level_1_2.png", "textures/IMG_Level/level_1_2.png");
        auto item3 = MenuItemImage::create("textures/IMG_Level/level_1_3.png", "textures/IMG_Level/level_1_3.png");
        auto item4 = MenuItemImage::create("textures/IMG_Level/level_1_4.png", "textures/IMG_Level/level_1_4.png");
        
        item1->setPosition(VisibleRect::center()+Point(-310,40));
        item2->setPosition(VisibleRect::center()+Point(0,80));
        item3->setPosition(VisibleRect::center()+Point(120,-225));
        item4->setPosition(VisibleRect::center()+Point(365,-90));
        
        auto menu = Menu::create(item1,item2,item3,item4,NULL);
        menu->setPosition(0,0);
        addChild(menu,0,level_tag);
   }
}

void InstanceLayer::onLoad(Node *node){
    
    GameManager::getInstance()->loading(node);
}