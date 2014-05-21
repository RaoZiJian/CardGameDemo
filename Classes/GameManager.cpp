//
//  GameManager.cpp
//  CardGameDemo
//
//  Created by Kirito on 5/16/14.
//
//

#include "GameManager.h"

static GameManager *s_pGameManager;
static LoadingMode *loadingLayer = nullptr;

GameManager* GameManager::getInstance(){
    
    if(! s_pGameManager){
        
        s_pGameManager = new GameManager;
    }
    
    return s_pGameManager;
}

void GameManager::loading(Node* node){
    
    auto layer = LoadingMode::create();
    node->addChild(layer,1.0f);
    loadingLayer = layer;
}

void GameManager::unLoading(){
    
    if(loadingLayer){
        
        loadingLayer->getParent()->removeChild(loadingLayer);
        loadingLayer = nullptr;
    }
}