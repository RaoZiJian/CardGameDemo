//
//  Login.h
//  CardGameDemo
//
//  Created by Kirito on 5/15/14.
//
//


#ifndef CardGameDemo_Login_h
#define CardGameDemo_Login_h

#include "cocos2d.h"
#include "Common.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "Utile.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;

class CharacterScene : public Scene{
    
public:
    
    bool init();
    CREATE_FUNC(CharacterScene);
private:
    
    EditBox* _charName;
};

class LoginScene : public Scene{
    
public:
    bool init();
    CREATE_FUNC(LoginScene);
    static void onOpen(Ref *ref);
    void callLogin(Ref *ref);
    
    Label *getShowMessage();
    void setShowMessage(Label *message);
    
    Layer *getLoginLayer();
  
private:
    
    Layer *loginLayer;
    Size _winSize;
    Point _pCenter;
    Label *_showMessage;
    EditBox* _loginName;
    EditBox* _loginPwd;
};

class LoadingScene : public Scene{
    
public:
    bool init();
    CREATE_FUNC(LoadingScene);
    static void replaceLoading(Scene *scene);
};
#endif
