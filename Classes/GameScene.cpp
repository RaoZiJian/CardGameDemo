//
//  GameScene.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/20/14.
//
//

#include "GameScene.h"

bool GameScene::init(){
    
    if(Scene::init()){
    
        auto layer = GameLayer::create();
        addChild(layer);
        
        return true;
    }
    
    return false;
}

void GameScene::openScene(Ref *sender){
    
    Director::getInstance()->replaceScene(GameScene::create());
}

bool GameLayer::init(){
    
    if (Layer::init()){

        auto background = Sprite::create("textures/IMG_Background/bg_main.png");
        background->setPosition(VisibleRect::center());
        addChild(background);
        
        auto itemImgInstance = MenuItemImage::create("textures/IMG_Button/btn_instance.png", "textures/IMG_Button/btn_instance_press.png",CC_CALLBACK_1(GameLayer::instanceSceneCallback, this));
        auto itemImgShop = MenuItemImage::create("textures/IMG_Button/btn_shop.png", "textures/IMG_Button/btn_shop_press.png");
        auto itemImgCardUpgrade = MenuItemImage::create("textures/IMG_Button/btn_card_upgrade.png", "textures/IMG_Button/btn_card_upgrade_press.png");
        auto itemImgCardGroup = MenuItemImage::create("textures/IMG_Button/btn_card_group.png", "textures/IMG_Button/btn_card_group_press.png", CC_CALLBACK_1(GameLayer::CardSceneCallback, this));
        
        itemImgInstance->setPosition(VisibleRect::center() + Point(270,170));
        itemImgShop->setPosition(VisibleRect::center() + Point(180,-150));
        itemImgCardUpgrade->setPosition(VisibleRect::center() + Point(-220,90));
        itemImgCardGroup->setPosition(VisibleRect::center() + Point(-300,-160));
        
        auto menu = Menu::create(itemImgInstance, itemImgShop, itemImgCardUpgrade, itemImgCardGroup ,NULL);
        menu->setPosition(0.0f,0.0f);
        addChild(menu);
        
        auto charInfo = CharInfo::create();
        charInfo->setPosition(VisibleRect::topLeft()+Point(200.0f,-80.0f));
        addChild(charInfo);
        charInfo->updateInfo("CHEN", "1");
        
        return true;
    }
    
    return false;
}

void GameLayer::instanceSceneCallback(cocos2d::Ref *sender){
    
    
}

void GameLayer::CardSceneCallback(cocos2d::Ref *sender){
    
    Director::getInstance()->replaceScene(CardGroupScene::create());
}


bool CharInfo::init(){
    
    if(Node::init()){
        
        auto usBack = Sprite::create("textures/IMG_User/us_back.png");
        auto usImg = Sprite::create("textures/IMG_User/us_img.png");
        auto usImgBack = Sprite::create("textures/IMG_User/us_img_back.png");
        auto usName = Sprite::create("textures/IMG_User/us_name.png");
        auto usLevel = Sprite::create("textures/IMG_User/us_level.png");
        _vit = Sprite::create("textures/IMG_User/us_vit.png");
        
        usImg->setPosition(-120.0f,0.0f);
        usImgBack->setPosition(-120,0);
        usName->setPosition(5,22);
        usLevel->setPosition(-160,45);
        
        _vit->setPosition(-100, -33);
        _vit->setAnchorPoint(Point(0.05f,0.5f));
        
        addChild(_vit);
        addChild(usName);
        addChild(usImgBack);
        addChild(usImg);
        addChild(usBack);
        addChild(usLevel);
        
        _name = Label::create();
        _name->setSystemFontSize(24);
        _name->setPosition(15,22);
        
        _level = Label::create();
        _level->setSystemFontSize(24);
        _level->setPosition(usLevel->getPosition());
        
        addChild(_name);
        addChild(_level);

        _name = Label::create();
        _name->setPosition(15,22);
        _name->setSystemFontSize(24);
        
        _level = Label::create();
        _level->setPosition(usLevel->getPosition());
        _level->setSystemFontSize(24);
        
        addChild(_name);
        addChild(_level);
      
        return true;
    }
    return false;
}

void CharInfo::updateInfo(std::string name, std::string level){
    
    _name->setString(name);
    _level->setString(level);
}