//
//  BaseScene.h
//  PhysicsWorld
//
//  Created by Sergey on 2/5/15.
//
//

#ifndef __PhysicsWorld__BaseScene__
#define __PhysicsWorld__BaseScene__

#include "cocos2d.h"

NS_CC_BEGIN

class BaseScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(BaseScene);
    
    bool init();
};

NS_CC_END

#endif /* defined(__PhysicsWorld__BaseScene__) */
