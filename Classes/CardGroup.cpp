//
//  CardGroup.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#include "CardGroup.h"
#include "Common.h"
#include "ReadString.h"
#include "Card.h"
#include "GameScene.h"
#include <stdio.h>

bool CardGroupScene::init(){
    
    if(Scene::init()){
        
        auto cardGrouplayer = CardGroupLayer::create();
        addChild(cardGrouplayer);
        return true;
    }
    
    return false;
}

bool CardGroupLayer::init(){
    
    if(Layer::init()){
        
        auto background = Sprite::create("textures/IMG_Background/bg_loading.png");
        background->setPosition(VisibleRect::center());
        addChild(background);
        
        auto bgColor = LayerColor::create(Color4B(0,0,0,175), VisibleRect::rect().size.width, VisibleRect::rect().size.height);
        addChild(bgColor);

        auto itemImgBack = MenuItemImage::create("textures/IMG_Button/btn_back.png", "textures/IMG_Button/btn_back_press.png", CC_CALLBACK_0(GameScene::openScene, this));
       
        itemImgBack->setPosition(VisibleRect::topRight()+Point(-65.0f,-120.0f));
        
        auto menu = Menu::create(itemImgBack, NULL);
        menu->setPosition(0.0f,0.0f);
        addChild(menu);

        auto cardGroup = extension::Scale9Sprite::create("textures/IMG_CardStatus/card_group.png");
        cardGroup->setContentSize(Size(880.0f,180.0f));
        
        auto dogFace1=Sprite::create("textures/IMG_DogFace/card_dog_face_1.png");
        auto dogFace2=Sprite::create("textures/IMG_DogFace/card_dog_face_2.png");
        auto dogFace3=Sprite::create("textures/IMG_DogFace/card_dog_face_3.png");
        auto dogFace4=Sprite::create("textures/IMG_DogFace/card_dog_face_4.png");
        auto dogFace5=Sprite::create("textures/IMG_DogFace/card_dog_face_5.png");
        
        cardGroup->setPosition(450.0f,650.0f);
        dogFace1->setPosition(100.0f,650.0f);
        dogFace2->setPosition(275.0f,650.0f);
        dogFace3->setPosition(450.0f,650.0f);
        dogFace4->setPosition(625.0f,650.0f);
        dogFace5->setPosition(800.0f,650.0f);
        
        addChild(cardGroup);
        addChild(dogFace1);
        addChild(dogFace2);
        addChild(dogFace3);
        addChild(dogFace4);
        addChild(dogFace5);
        
        _galleryLayer = new GalleryLayer();
        _galleryLayer->init();
        _galleryLayer->setPosition(0.0f,-85.0f);
        addChild(_galleryLayer);
        
        return true;
    }
    
    return false;
}

bool GalleryLayer::init(){
    
    if(Layer::init()){
        
        _colorLayer = LayerColor::create();
        _cardWidth = 200;
        _cardDistance = 80;
        _cardHeight = 290;
        _contentSize = VisibleRect::winSize();
        
        ReadString* rs = ReadString::getInstance();
        
        for(int i=1;i<9;i++){
            
            auto card = rs->read(i);
            auto cardNode = CardNode::createWithInfo(card);
            cardNode->setPosition((_cardWidth+_cardDistance)*(i-1), _contentSize.height/2);
            _colorLayer->addChild(cardNode,0.0f,i);
        }

        auto listener1 = EventListenerTouchOneByOne::create();
        listener1->onTouchBegan = CC_CALLBACK_2(GalleryLayer::onTouchBegan, this);
        listener1->onTouchMoved = CC_CALLBACK_2(GalleryLayer::onTouchMoved, this);
        listener1->onTouchEnded = CC_CALLBACK_2(GalleryLayer::onTouchEnded, this);
        
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);
        
        _scrollView = extension::ScrollView::create(_contentSize, _colorLayer);
        _scrollView->setTouchEnabled(false);
        addChild(_scrollView);
        
        updateDisplay();
        
        return true;
    }
    return false;
}

void GalleryLayer::updateDisplay(){
    
    for(int i=1;i<9;i++){
        
        auto cardNode = (CardNode*)_colorLayer->getChildByTag(i);
        cardNode->updateDisplay(_scrollView->getContentOffset(), _cardWidth+_cardDistance);
        cardNode->setScale(cardNode->getScaleX()*0.75f);
    }
}


bool GalleryLayer::onTouchBegan(Touch *touch, Event *event){
    
    _touchPoint = touch->getLocationInView();
    if(_touchPoint.y>=300.0f&&_touchPoint.y<=655.0f){
        _touchOffset = _scrollView->getContentOffset();
    }else{
        return false;
    }
    
    return true;
}

void GalleryLayer::onTouchMoved(Touch *touch, Event *event){
  
    auto movePoint = touch->getLocationInView();
    auto distance = movePoint.x-_touchPoint.x;
    auto adjustPoint = Point(_touchOffset.x+distance,0.0f);
    _adjustPoint = adjustPoint;
    
    if(adjustPoint.x>=528.0f){
        adjustPoint.x=528.0f;
    }else if(adjustPoint.x<-1228.0f){
        adjustPoint.x=-1199.0f;
    }
    _scrollView->setContentOffset(adjustPoint,false);
    updateDisplay();
}

void GalleryLayer::onTouchEnded(Touch *touch, Event* event){
    
    auto width = _cardWidth + _cardDistance;
    auto winOffset = (int)(VisibleRect::winSize().width/2)%width;
    
    auto touchOffset = _scrollView->getContentOffset();
    auto index = std::round((touchOffset.x-winOffset)/width);
    
    auto adjustPoint = Point(width * index + winOffset,0.0f);
    _scrollView->setContentOffsetInDuration(adjustPoint, 0.3f);
    updateDisplay();
}
