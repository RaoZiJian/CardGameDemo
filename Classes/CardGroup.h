//
//  CardGroup.h
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#ifndef __CardGameDemo__CardGroup__
#define __CardGameDemo__CardGroup__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;

class GalleryLayer;
class CardGroupScene : public Scene{
    
public:
    bool init();
    CREATE_FUNC(CardGroupScene);
};

class CardGroupLayer : public Layer{
    
public:
    bool init();
    CREATE_FUNC(CardGroupLayer);
    
private:
    GalleryLayer* _galleryLayer;
};

class GalleryLayer : public Layer{
    
public:
    
    bool init();
    CREATE_FUNC(GalleryLayer);
    
private:
    
    extension::ScrollView *_scrollView;
    LayerColor *_colorLayer;
    int _cardWidth;
    int _cardHeight;
    int _cardDistance;
    Size _contentSize;
    
    Point _touchPoint;
    Point _adjustPoint;
    Point _touchOffset;
    
    void updateDisplay();
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event* event);
    void scrollViewDidScroll(extension::ScrollView *view);
    void scrollViewDidZoom(extension::ScrollView* view);
};

#endif /* defined(__CardGameDemo__CardGroup__) */
