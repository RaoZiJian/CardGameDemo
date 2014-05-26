//
//  Utile.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/19/14.
//
//

#include "Utile.h"

string Utile::string_replace(string & strBig, const string & strsrc, const string &strdst){
    
    string::size_type pos=0;
    string::size_type srclen=strsrc.size();
    string::size_type dstlen=strdst.size();
    
    while( (pos=strBig.find(strsrc, pos)) != string::npos)
    {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
    
    return strBig;
}

string Utile::convertIntToString (int aNum){
    
    ostringstream oss;
    oss<<aNum;
    
    return oss.str();
}

ActionInterval* Utile::getAnimate(float dt, SpriteFrame** images, CallFunc* fc,  Node *target){
      
    auto am = Animation::create();
    for(int i=0;i<sizeof(images);i++){
        
        auto image = images[i];
        am->addSpriteFrame(image);
    }
    am->setDelayPerUnit(dt);
    am->setRestoreOriginalFrame(false);
    
    if(!fc){
        return RepeatForever::create(Animate::create(am));
    }else{
        return Sequence::create(Animate::create(am),fc ,NULL);
    }
}