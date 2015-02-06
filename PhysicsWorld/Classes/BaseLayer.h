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
private:
    Sprite *point;
    
protected:
    cocos2d::EventListenerTouchAllAtOnce *_touchListener;
    
public:
    CREATE_FUNC(BaseLayer);
    
    bool init();
    
    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event) override;
    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *event) override;
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event) override;
    virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event) override;
};

NS_CC_END

#endif /* defined(__PhysicsWorld__BaseLayer__) */
