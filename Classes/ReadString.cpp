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

ReadString::ReadString(char *fileName){
    
    auto File = cocos2d::FileUtils::getInstance();
    string sFullPath = File->fullPathForFilename(fileName);
    Beffer = File->getStringFromFile(sFullPath);
}

ReadString* ReadString::creat(char *fileName){
    
    ReadString *RS = new ReadString(fileName);
    return RS;
}

ReadString* ReadString::getInstance(char *fileName){
    
    if(rs == nullptr)
        rs= ReadString::creat(fileName);
    return rs;
}

Card* ReadString::read(int key, std::string type){
    
    auto card = new Card();
    rapidjson::Document article;
    article.Parse<0>(Beffer.c_str());
    
    if (article.HasParseError()){
        
        CCLOG("GetParseError %s\n",article.GetParseError());
    }else if (article.IsObject()){
        
        if(article.HasMember("cards")&& type=="cards"){
            
            card->setType("cards");
            card = setCardData(article["cards"],key,card,"cards");
        }else if(article.HasMember("Monster")&& type=="Monster"){
            
            card->setType("Monster");
            card = setCardData(article["Monster"],key,card,"Monster");
        }else if(article.HasMember("My")&&type=="My"){
            
            card->setType("My");
            card = setCardData(article["My"],key,card,"My");
        }
    }
    
    return card;
}

Card* ReadString::setCardData(const rapidjson::Value &a, int key ,Card *card, std::string type){
    
    
    if (a.IsArray()){
        
        for(unsigned int i=0;i<a.Size();++i){
            
            const rapidjson::Value &val = a[i];
            if(val.HasMember("ID")){
                
                const rapidjson::Value &val_id = val["ID"];
                int i_id = -1;
                if(val_id.IsInt()){
                    
                    i_id = val_id.GetInt();
                    if(i_id == key){
                        
                        if(val.HasMember("ID")){
                            
                            if(val["ID"].IsInt()){
                                
                                card->setID(val["ID"].GetInt());
                            }
                        }
                        
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
                        
                        if(val.HasMember("Skill")){
                            
                            if(val["Skill"].IsInt()){
                                
                                card->setSkill(val["Skill"].GetInt());
                            }
                        }

                        if(val.HasMember("Hash")){
                            
                            if(val["Hash"].IsString()){
                                
                                card->setHash(val["Hash"].GetString());
                            }
                        }
}
                }
            }
        }
    }
    return card;
}

Combat* ReadString::readCombat(){
    
    auto combat = new Combat();
    rapidjson::Document article;
    article.Parse<0>(Beffer.c_str());
    
    if (article.HasParseError()){
        
        CCLOG("GetParseError %s\n",article.GetParseError());
    }else if (article.IsObject()){
        
        if(article.HasMember("Combat")){
            
            combat = setCombatData(article["Combat"]);
        }
    }
    
    return combat;
}

Combat* ReadString::setCombatData(const rapidjson::Value &a){

    auto combat = new Combat();
    if(a.IsArray()){
        
        for(unsigned int i=0;i<a.Size();++i){
            
            const rapidjson::Value &val = a[i];
            if(val.HasMember("Beattacked")){
                
                const rapidjson::Value &val_id =val["Beattacked"];
                if(val_id.IsString()){
                    
                    combat->setBeattacked(val["Beattacked"].GetString());
                }
            }
            
            if(val.HasMember("Skill")){
                
                const rapidjson::Value &val_id =val["Skill"];
                if(val_id.IsInt()){
                    
                    combat->setSkill(val["Skill"].GetInt());
                }
            }

            if(val.HasMember("Attacker")){
                
                const rapidjson::Value &val_id =val["Attacker"];
                if(val_id.IsString()){
                    
                    combat->setAttacker(val["Attacker"].GetString());
                }
            }
            
            if(val.HasMember("Damage")){
                
                const rapidjson::Value &val_id =val["Damage"];
                if(val_id.IsInt()){
                    
                    combat->setDamage(val["Damage"].GetInt());
                }
            }
        }
    }
    
    return combat;
}

End* ReadString::readEnd(){
    
    auto end = new End();
    rapidjson::Document article;
    article.Parse<0>(Beffer.c_str());
    
    if (article.HasParseError()){
        
        CCLOG("GetParseError %s\n",article.GetParseError());
    }else if (article.IsObject()){
        
        if(article.HasMember("End")){
            
            end = setEndData(article["End"]);
        }
    }
    
    return end;
}

End* ReadString::setEndData(const rapidjson::Value &a){
  
    auto end = new End();
    if(a.IsArray()){
        
        for(unsigned int i=0;i<a.Size();++i){
            
            const rapidjson::Value &val = a[i];
            if(val.HasMember("Experience")){
                
                const rapidjson::Value &val_id =val["Experience"];
                if(val_id.IsInt()){
                    
                    end->setExperience(val["Experience"].GetInt());
                }
            }
            
            if(val.HasMember("Drop")){
                
                const rapidjson::Value &val_id =val["Drop"];
                if(val_id.IsInt()){
                    
                    end->setDrop(val["Drop"].GetInt());
                }
            }

            if(val.HasMember("Result")){
                
                const rapidjson::Value &val_id =val["Result"];
                if(val_id.IsInt()){
                    
                    end->setResult(val["Result"].GetInt());
                }
            }
        }
    }
    
    return end;
}

ReadString::~ReadString(void){
    
}