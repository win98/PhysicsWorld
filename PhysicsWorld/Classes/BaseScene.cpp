//
//  BaseScene.cpp
//  PhysicsWorld
//
//  Created by Sergey on 2/5/15.
//
//

#include "BaseScene.h"

#include "BaseLayer.h"

NS_CC_BEGIN

bool BaseScene::init()
{
    if (Scene::init())
    {
        BaseLayer *layer = BaseLayer::create();
        addChild(layer);
    }
    
    return true;
}

NS_CC_END