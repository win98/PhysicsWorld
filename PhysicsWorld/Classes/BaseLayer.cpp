//
//  BaseLayer.cpp
//  PhysicsWorld
//
//  Created by Sergey on 2/5/15.
//
//

#include <iostream>
#include "BaseLayer.h"

#include "PHEngine.h"

NS_CC_BEGIN

struct Ball{
    float mass;
    float radius;
    Vec2 velocity;
    Vec2 position;
    float restortion;
};

Ball b1, b2;
Vec2 center;
Sprite *point1, *point2;
Sprite *aimPoint;

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
    
    point1 = Sprite::create("MaterialPoint.png");
    point1->setColor(Color3B(255, 10, 10));
    point2 = Sprite::create("MaterialPoint.png");
    aimPoint = Sprite::create("MaterialPoint.png");
    aimPoint->setColor(Color3B(192, 239, 251));
    aimPoint->setVisible(false);
    addChild(point1);
    addChild(point2);
    addChild(aimPoint);
    
    b1.mass = 0.01f;
    b2.mass = 1.0f;
    b1.radius = 10.0f;
    b2.radius = 10.0f;
    b1.restortion = 1.0f;
    b2.restortion = 1.0f;
    
    point1->setScale(b1.radius/10.0f);
    point2->setScale(b2.radius/10.0f);
    
    b1.velocity = Vec2(0, 0);
    b2.velocity = Vec2(0, 0);
    b1.position = Vec2(100, 100);
    b2.position = Vec2(700, 400);
    
    center = getContentSize() * 0.5f;
    
    scheduleUpdate();
    
    return true;
}

void BaseLayer::update(float delta)
{
    
    //detect collision
    float distSquared = (b2.position - b1.position).lengthSquared();
    float minDistSquared = b1.radius + b2.radius;
    minDistSquared *= minDistSquared;
    
    if (distSquared < minDistSquared)
    {
        Vec2 n = b2.position - b1.position;
        n.normalize();
        Vec2 v1 = b1.velocity;
        Vec2 v2 = b2.velocity;
        float m1 = b1.mass;
        float m2 = b2.mass;
        float e = b1.restortion * b2.restortion * 0.5f;//restortion
        
        
        float v1p = v1.dot(n);
        float v2p = v2.dot(n);
        
        float v1pnew = (v1p * (m1-e*m2) + v2p * m2*(1+e)) / (m1+m2);
        float v2pnew = (v2p * (m2-e*m1) + v1p * m1*(1+e)) / (m1+m2);
        
        Vec2 v1new = v1 + n * (v1pnew-v1p);
        Vec2 v2new = v2 + n * (v2pnew-v2p);
        
        b1.velocity = v1new;
        b2.velocity = v2new;
    }
    
    b1.position += b1.velocity * delta;
    b2.position += b2.velocity * delta;
    
    point1->setPosition(b1.position);
    point2->setPosition(b2.position);
}

void BaseLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
    Touch *t = touches[0];
    
    b1.velocity = Vec2(0, 0);
    b2.velocity = Vec2(0, 0);
    b1.position = Vec2(100, 100);
    b2.position = Vec2(700, 400);
    
    Vec2 touchPos = t->getLocation();
    b1.position = touchPos;
    Vec2 diff = center - touchPos;
    Vec2 aimPos = center + diff;
    aimPoint->setPosition(aimPos);
    
    aimPoint->setVisible(true);
}

void BaseLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
    Touch *t = touches[0];
    
    Vec2 touchPos = t->getLocation();
    b1.position = touchPos;
    Vec2 diff = center - touchPos;
    Vec2 aimPos = center + diff;
    aimPoint->setPosition(aimPos);
    
    aimPoint->setVisible(true);
}

void BaseLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
    
}

void BaseLayer::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
    Touch *t = touches[0];
    
    Vec2 touchPos = t->getLocation();
    Vec2 diff = center - touchPos;
    b1.velocity = diff;
    
    aimPoint->setVisible(false);
}

NS_CC_END