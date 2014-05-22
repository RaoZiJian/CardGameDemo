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
#include "ui/CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;

class CardGroup : public Scene{
    
    
};

class GalleryLayer : public Layer{
    
public:
    
    bool init();
    CREATE_FUNC(GalleryLayer);
    
private:
    
    ui::ScrollView *_scrollView;
    LayerColor *_colorLayer;
    int _cardWidth;
    int _cardHeight;
    int _cardDistance;
    Size _contentSize;
    
    Point _touchPoint;
    Point _adjustPoint;
};

#endif /* defined(__CardGameDemo__CardGroup__) */
