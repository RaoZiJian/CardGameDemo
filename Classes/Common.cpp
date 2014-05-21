
//
//  Common.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/15/14.
//
//

#include "Common.h"

Size VisibleRect::winSize(){
    
    if(s_winSize.width == 0){
        
        s_winSize = Director::getInstance()->getWinSize();
    }
    return s_winSize;
}

Rect VisibleRect::rect(){
    
    if(s_rcVisible.size.width==0){
        
        auto s = Director::getInstance()->getWinSize();
        s_rcVisible = Rect(0,0,s.width,s.height);
    }
    return s_rcVisible;
}

Point VisibleRect::center(){
    
    if(s_ptCenter.x == 0){
        
        auto rc = VisibleRect::rect();
        s_ptCenter.x = rc.origin.x + rc.size.width/2;
        s_ptCenter.y = rc.origin.y + rc.size.height/2;
    }
    
    return s_ptCenter;
}

Point VisibleRect::top(){
    
    if (s_ptTop.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptTop.x = rc.origin.x +rc.size.width/2;
        s_ptTop.y = rc.origin.y + rc.size.height;
    }
    
    return s_ptTop;
}

Point VisibleRect::topRight(){
    
    if (s_ptTopRight.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptTopRight.x = rc.origin.x +rc.size.width;
        s_ptTopRight.y = rc.origin.y + rc.size.height;
    }
    
    return s_ptTopRight;
}

Point VisibleRect::right(){
    
    if (s_ptRight.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptRight.x = rc.origin.x +rc.size.width;
        s_ptRight.y = rc.origin.y + rc.size.height/2;
    }
    
    return s_ptRight;
}

Point VisibleRect::buttomRight(){
    
    if (s_ptBottomRight.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptBottomRight.x = rc.origin.x +rc.size.width;
        s_ptBottomRight.y = rc.origin.y;
    }
    
    return s_ptBottomRight;
}

Point VisibleRect::buttom(){
    
    if (s_ptBottom.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptBottom.x = rc.origin.x +rc.size.width/2;
        s_ptBottom.y = rc.origin.y;
    }
    
    return s_ptBottom;
}

Rect VisibleRect::buttomLeft(){
    
    return VisibleRect::rect();
}

Point VisibleRect::left(){
    
    if (s_ptLeft.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptLeft.x = rc.origin.x;
        s_ptLeft.y = rc.origin.y + rc.size.height/2;
    }
    
    return s_ptLeft;
}

Point VisibleRect::topLeft(){
    
    if (s_ptTopLeft.x==0) {
        
        auto rc =VisibleRect::rect();
        s_ptTopLeft.x = rc.origin.x;
        s_ptTopLeft.y = rc.origin.y + rc.size.height;
    }
    
    return s_ptTopLeft;
}

bool LoadingMode::init(){
    
    if(Layer::init()){
        
        auto loadingBg = Sprite::create("textures/IMG_Loading/loading_bg.png");
        loadingBg->setPosition(Point(VisibleRect::center()));
        addChild(loadingBg);
        
        auto loading = Sprite::create("textures/IMG_Loading/loading.png");
        loading->setPosition(VisibleRect::center());
        addChild(loading);
        
        auto action = RotateBy::create(2, 360);
        loading->runAction(RepeatForever::create(action));
    }
    
    return true;
}
