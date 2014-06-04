//
//  ReadString.h
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#ifndef __CardGameDemo__ReadString__
#define __CardGameDemo__ReadString__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "external/json/document.h"
#include "Card.h"

USING_NS_CC;

class ReadString
{
public:
    static ReadString* creat(char *fileName);
    static ReadString* getReadString(char *fileName);
    ~ReadString(void);
    Card* read(int key, std::string type);
    Combat* readCombat();
    End* readEnd();
private:
    ReadString(char * fileName);
    std::string Beffer;
    Card* setCardData(const rapidjson::Value &a, int key, Card *card, std::string type);
    Combat* setCombatData(const rapidjson::Value &a);
    End* setEndData(const rapidjson::Value &a);
};

#endif /* defined(__CardGameDemo__ReadString__) */
