//
//  FleeAndArrival.h
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#ifndef __UnderstandingSteeringBehaviors_Seek__Flee__
#define __UnderstandingSteeringBehaviors_Seek__Flee__

#include "cocos2d.h"
#include "TestBaseLayer.h"
USING_NS_CC;
class Flee : public TestBaseLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Flee);
    
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    
    virtual void setTitle();
    
    void update(float dt);
    static Vec2 getFleeSteering(Vec2 characterPosition, Vec2 targetPosition,Vec2& characterVelocity);
    static Vec2 getFleePosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity);
    
    Vec2 velocity;
    Vec2 m_touchPosition;
};

#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Flee__) */
