//
//  Wander.h
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#ifndef __UnderstandingSteeringBehaviors_Seek__Wander__
#define __UnderstandingSteeringBehaviors_Seek__Wander__

#include "cocos2d.h"
#include "TestBaseLayer.h"
USING_NS_CC;
class Wander : public TestBaseLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Wander);
    
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    
    virtual void setTitle();
    
    void update(float dt);
    Vec2 getSeekPosition(Vec2 position);
    
    Vec2 velocity;
    Vec2 m_touchPosition;
    Vec2 wanderForce;
};

#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Wander__) */
