//
//  Common.h
//  CardGameDemo
//
//  Created by Kirito on 5/15/14.
//
//

#ifndef CardGameDemo_Common_h
#define CardGameDemo_Common_h
#include "cocos2d.h"

USING_NS_CC;

static Size s_winSize = Size(0,0);
static Rect s_rcVisible = Rect(0,0,0,0);
static Point s_ptCenter = Point(0, 0);
static Point  s_ptTop = Point(0, 0);
static Point  s_ptTopRight = Point(0, 0);
static Point  s_ptRight = Point(0, 0);
static Point  s_ptBottomRight = Point(0, 0);
static Point  s_ptBottom = Point(0, 0);
static Point  s_ptLeft = Point(0, 0);
static Point  s_ptTopLeft = Point(0, 0);

class VisibleRect{
    
public:
    
    static Size winSize();
    static Rect rect();
    static Point center();
    static Point top();
    static Point topRight();
    static Point right();
    static Point buttomRight();
    static Rect buttomLeft();
    static Point buttom();
    static Point left();
    static Point topLeft();
};

//class ModeLayer : public Layer{
//    
//
//};

class LoadingMode : public Layer{
    
public:
    bool init();
    CREATE_FUNC(LoadingMode);
    
};

#endif
