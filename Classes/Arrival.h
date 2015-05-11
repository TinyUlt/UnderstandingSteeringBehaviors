////
////  Arrival.h
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/9.
////
////
//
#ifndef __UnderstandingSteeringBehaviors_Seek__Arrival__
#define __UnderstandingSteeringBehaviors_Seek__Arrival__
//
//#include "cocos2d.h"
//#include "TestBaseLayer.h"
//USING_NS_CC;
//class Arrival : public TestBaseLayer
//{
//public:
//    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//    virtual bool init();
//    
//    // implement the "static create()" method manually
//    CREATE_FUNC(Arrival);
//    
//    bool onTouchBegan(Touch* touch, Event* event);
//    void onTouchMoved(Touch* touch, Event* event);
//    void onTouchEnded(Touch* touch, Event* event);
//    
//    virtual void setTitle();
//    
//    void update(float dt);
//    Vec2 getArrivalSteering(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity, float &max_speed);
//    Vec2 getArrivalPosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity);
//    
//    Vec2 velocity;
//    Vec2 m_touchPosition;
//};
//

#include "cocos2d.h"
#include "SteeringBehaviors.h"
USING_NS_CC;
class Arrival : public SteeringBehaviors
{
public:
    Arrival(){init();};
    
    virtual bool init();
    void update(float dt);
    Vec2 getSeekPosition();
};
#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Arrival__) */
