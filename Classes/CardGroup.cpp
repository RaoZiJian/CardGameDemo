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

bool GalleryLayer::init(){
    
    if(Layer::init()){
        
        _colorLayer = LayerColor::create();
        _cardWidth = 200;
        _cardDistance = 40;
        _cardHeight = 290;
        _contentSize = VisibleRect::winSize();
        
        ReadString* rs = ReadString::getInstance();
        
        for(int i=0;i<8;i++){
            
            auto card = rs->read(0);
            
        }
        
        return true;
    }
    return false;
}