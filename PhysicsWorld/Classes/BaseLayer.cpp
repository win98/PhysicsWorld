//
//  BaseLayer.cpp
//  PhysicsWorld
//
//  Created by Sergey on 2/5/15.
//
//

#include "BaseLayer.h"

NS_CC_BEGIN

bool BaseLayer::init()
{
    if (Layer::init())
    {
        _touchListener = cocos2d::EventListenerTouchAllAtOnce::create();
        _touchListener->onTouchesBegan = CC_CALLBACK_2(BaseLayer::onTouchesBegan, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    
    return true;
}

void BaseLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    
}

NS_CC_END