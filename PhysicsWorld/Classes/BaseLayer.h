//
//  BaseLayer.h
//  PhysicsWorld
//
//  Created by Sergey on 2/5/15.
//
//

#ifndef __PhysicsWorld__BaseLayer__
#define __PhysicsWorld__BaseLayer__

#include "cocos2d.h"

NS_CC_BEGIN

class BaseLayer : public cocos2d::Layer
{
protected:
    cocos2d::EventListenerTouchAllAtOnce *_touchListener;
    
public:
    CREATE_FUNC(BaseLayer);
    
    bool init();
    
    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
};

NS_CC_END

#endif /* defined(__PhysicsWorld__BaseLayer__) */
