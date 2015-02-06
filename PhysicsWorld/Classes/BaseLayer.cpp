//
//  BaseLayer.cpp
//  PhysicsWorld
//
//  Created by Sergey on 2/5/15.
//
//

#include "BaseLayer.h"
#include <iostream>

NS_CC_BEGIN

bool BaseLayer::init()
{
    if (Layer::init())
    {
        _touchListener = cocos2d::EventListenerTouchAllAtOnce::create();
        _touchListener->onTouchesBegan = CC_CALLBACK_2(Layer::onTouchesBegan, this);
        _touchListener->onTouchesMoved = CC_CALLBACK_2(Layer::onTouchesMoved, this);
        _touchListener->onTouchesEnded = CC_CALLBACK_2(Layer::onTouchesCancelled, this);
        _touchListener->onTouchesCancelled = CC_CALLBACK_2(Layer::onTouchesCancelled, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    
    this->setColor(Color3B(255, 255, 255));
    
    point = Sprite::create("MaterialPoint.png");
    point->setRotation(-45);
    point->setPosition(0, 0);
    addChild(point);
    
    return true;
}

void BaseLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    Touch *t = touches[0];
    
    point->setPosition(t->getLocation());
}

void BaseLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
    Touch *t = touches[0];
    
    point->setPosition(t->getLocation());
}

void BaseLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
    Touch *t = touches[0];
    
    point->setPosition(t->getLocation());
}

void BaseLayer::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
    
}

NS_CC_END