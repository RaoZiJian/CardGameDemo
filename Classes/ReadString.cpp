//
//  ReadString.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/21/14.
//
//

#include "ReadString.h"

using namespace std;
using namespace cocostudio;
ReadString* ReadString::rs = nullptr;

ReadString::ReadString(char * fileName){
    
    auto File = cocos2d::FileUtils::getInstance();
    string sFullPath = File->fullPathForFilename(fileName);
    Beffer = File->getStringFromFile(sFullPath);
}

ReadString* ReadString::creat(char * fileName){
    
    ReadString *RS = new ReadString(fileName);
    return RS;
}

ReadString* ReadString::getInstance(){
    
    if(rs == nullptr)
        rs= ReadString::creat("json/cardGroup.json");
    return rs;
}

Card* ReadString::read(int key){
    
    auto card = new Card();
    rapidjson::Document article;
    article.Parse<0>(Beffer.c_str());
    
    if (article.HasParseError()){
        
        CCLOG("GetParseError %s\n",article.GetParseError());
    }else if (article.IsObject()&&article.HasMember("cards")){
        
        const rapidjson::Value &a=article["cards"];
        if (a.IsArray()){
            
            for(unsigned int i=0;i<a.Size();++i){
                
                const rapidjson::Value &val = a[i];
                if(val.HasMember("ID")){
                    
                    const rapidjson::Value &val_id = val["ID"];
                    int i_id = -1;
                    if(val_id.IsInt()){
                        
                        i_id = val_id.GetInt();
                        if(i_id == key){
                            card->setID(val["ID"].GetInt());
                            card = setCardData(val);
                        }
                    }
                }
            }
        }
    }
    
    return card;
}

Card* ReadString::setCardData(const rapidjson::Value &val){
    
    auto card = new Card();
    
    if(val.HasMember("Name")){
        
        if(val["Name"].IsString()){
            
            card->setName(val["Name"].GetString());
        }
    }
    
    if(val.HasMember("HP")){
        
        if(val["HP"].IsInt()){
            
            card->setHP(val["HP"].GetInt());
        }
    }
        
    if(val.HasMember("Attack")){
        
        if(val["Attack"].IsInt()){
            
            card->setAttack(val["Attack"].GetInt());
        }
    }
        
    if(val.HasMember("Defence")){
        
        if(val["Defence"].IsInt()){
            
            card->setDefence(val["Defence"].GetInt());
        }
    }
        
    if(val.HasMember("Speed")){
        
        if(val["Speed"].IsInt()){
            
            card->setSpeed(val["Speed"].GetInt());
        }
    }
    if(val.HasMember("Talent")){
        
        if(val["Talent"].IsInt()){
            
            card->setTalent(val["Talent"].GetInt());
        }
    }
        
    if(val.HasMember("Drop")){
        
        if(val["Drop"].IsInt()){
            
            card->setDrop(val["Drop"].GetInt());
        }
    }
        
    if(val.HasMember("Experience")){
        
        if(val["Experience"].IsInt()){
            
            card->setExperience(val["Experience"].GetInt());
        }
    }
        
    if(val.HasMember("Level")){
        
        if(val["Level"].IsInt()){
            
            card->setLevel(val["Level"].GetInt());
        }
    }
        
    if(val.HasMember("Status")){
        
        if(val["Status"].IsInt()){
            
            card->setStatus(val["Status"].GetInt());
        }
    }
        
    if(val.HasMember("Pos")){
        
        if(val["Pos"].IsInt()){
            
            card->setPos(val["Pos"].GetInt());
        }
    }
    
    return card;
}

ReadString::~ReadString(void){
    
}