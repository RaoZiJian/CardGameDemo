//
//  Login.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/15/14.
//
//

#include "Login.h"
#include "GameManager.h"
#include "GameScene.h"

bool CharacterScene::init(){
    
    Scene::init();
    
    auto background = Sprite::create("textures/IMG_Background/login_background.png");
    background->setPosition(VisibleRect::center());
    addChild(background);
    
    auto layer = Layer::create();
    layer->setPosition(Point(0,0));
    layer->addChild(layer);
    
    auto loginBox = Sprite::create("textures/IMG_Background/login_box.png");
    loginBox->setPosition(VisibleRect::center() + Point(0,0));
    layer->addChild(loginBox);
    
    auto editBoxSize = Size(350,80);
    _charName = EditBox::create(editBoxSize, Scale9Sprite::create("textures/IMG_CardStatus/edit_box.png"),Scale9Sprite::create("textures/IMG_CardStatus/edit_box.png"));
    
    _charName->setPosition(VisibleRect::center()+Point(0,0));
    _charName->setPlaceHolder("Char Name");
    layer->addChild(_charName);
    
    addChild(layer);
    
    return true;
}

bool LoginScene::init(){
    
    if (Scene::init()) {
        
        _winSize = Director::getInstance()->getWinSize();
      
        auto background = Sprite::create("textures/IMG_Background/login_background.png");
        background->setPosition(VisibleRect::center());
        addChild(background);
       
        loginLayer = Layer::create();
        loginLayer->setPosition(Point(0,0));
        addChild(loginLayer);
        
        auto boxSize = Size(350,80);
        
        _loginName = EditBox::create(boxSize, Scale9Sprite::create("textures/IMG_CardStatus/edit_box.png"),Scale9Sprite::create("textures/IMG_CardStatus/edit_box.png"));

        _loginPwd = EditBox::create(boxSize, Scale9Sprite::create("textures/IMG_CardStatus/edit_box.png"),Scale9Sprite::create("textures/IMG_CardStatus/edit_box.png"));
        
        _loginPwd->setInputFlag(EditBox::InputFlag::PASSWORD);
        
        _loginName->setPlaceHolder("Login Name");
        _loginPwd->setPlaceHolder("Password");
        
        loginLayer->addChild(_loginName);
        loginLayer->addChild(_loginPwd);
        
        _loginName->setPosition(VisibleRect::center()+Point(0,170));
        _loginPwd->setPosition(VisibleRect::center()+Point(0,30));
        
        auto itemImgLogin = MenuItemImage::create("textures/IMG_Button/btn_login.png", "textures/IMG_Button/btn_login_press.png",CC_CALLBACK_1(LoginScene::callLogin, this));
        auto itemImgLoginRegister = MenuItemImage::create("textures/IMG_Button/btn_register.png", "textures/IMG_Button/btn_register_press.png");
        
		itemImgLogin->setPosition(VisibleRect::center()+Point(-170, -200));
		itemImgLoginRegister->setPosition(VisibleRect::center()+Point(170, -200));
        
		auto menu = Menu::create(itemImgLogin, itemImgLoginRegister, NULL);
		menu->setPosition(0 ,0);
		loginLayer->addChild(menu);
        
        _showMessage = Label::create();
        _showMessage->setColor(Color3B::BLUE);
        _showMessage->setPosition(VisibleRect::center()+Point(0,-270));
        _showMessage->setSystemFontSize(20.0);
        loginLayer->addChild(_showMessage,5);
    }
    
    return true;
}


void LoginScene::callLogin(Ref *ref){
    
    std::string namestr = _loginName->getText();
    std::string pwdstr  = _loginPwd->getText();
    _showMessage->setString("");
    
    if(Utile::string_replace(namestr, " ", "").length()==0 || Utile::string_replace(pwdstr, " ", "").length()==0){

        _showMessage->setString("Username or password can not be blank!");
    }else{
        
        Director::getInstance()->replaceScene(GameScene::create());
    }
}

Label* LoginScene::getShowMessage(){
    
    return _showMessage;
}

void LoginScene::setShowMessage(Label *message){
    
    _showMessage = message;
}

Layer* LoginScene::getLoginLayer(){
 
    return loginLayer;
}

void LoginScene::onOpen(Ref* ref){
    
    Director::getInstance()->replaceScene(LoginScene::create());
}

bool LoadingScene::init(){
    
    if(Scene::init()){
        
        auto layer = Layer::create();
        auto background = Sprite::create("textures/IMG_Background/bg_loading.png");
        background->setPosition(VisibleRect::center());
        layer->addChild(background);
               
        GameManager::getInstance()->loading(this);
        
        addChild(layer,0.0f);
        
        return true;
    }
    
    return false;
}

void LoadingScene::replaceLoading(Scene *scene){
    
    auto transition = TransitionCrossFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

