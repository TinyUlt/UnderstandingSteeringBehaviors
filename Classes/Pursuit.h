////
////  Pursuit.h
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/11.
////
////
//
#ifndef __UnderstandingSteeringBehaviors_Seek__Pursuit__
#define __UnderstandingSteeringBehaviors_Seek__Pursuit__
#include "cocos2d.h"
#include "Seek.h"
USING_NS_CC;
class Pursuit : public Seek
{
public:
    Pursuit(SteeringBehaviors* target){init(target);};
    
    virtual bool init(SteeringBehaviors* target);
    void update(float dt);
    Vec2 getSeekPosition();
    
    SteeringBehaviors* target;
};
//
//#include "cocos2d.h"
//#include "TestBaseLayer.h"
//#include "Seek.h"
//USING_NS_CC;
//class Pursuit : public TestBaseLayer
//{
//public:
//    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//    virtual bool init();
//    
//    // implement the "static create()" method manually
//    CREATE_FUNC(Pursuit);
//    
//    bool onTouchBegan(Touch* touch, Event* event);
//    void onTouchMoved(Touch* touch, Event* event);
//    void onTouchEnded(Touch* touch, Event* event);
//    
//    virtual void setTitle();
//    
//    void update(float dt);
//    Vec2 getPursuitPosition(Vec2 characterPosition,Vec2 targetPosition);
//   
//    Vec2 m_touchPosition;
//    Seek* seekTargetBehaviors;
//    Seek* seekPursuiterBehaviors;
//};
//
#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Pursuit__) */
