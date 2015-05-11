////
////  Evading.h
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/11.
////
////
//
#ifndef __UnderstandingSteeringBehaviors_Seek__Evading__
#define __UnderstandingSteeringBehaviors_Seek__Evading__
#include "cocos2d.h"
#include "Flee.h"
USING_NS_CC;
class Evading : public Flee
{
public:
    Evading(SteeringBehaviors* target){init(target);};
    
    virtual bool init(SteeringBehaviors* target);
    void update(float dt);
    Vec2 getSeekPosition();
    
    SteeringBehaviors* target;
};
//#include "cocos2d.h"
//#include "Flee.h"
//#include "Seek.h"
//USING_NS_CC;
//class Evading : public Seek, public Flee
//{
//public:
//    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//    virtual bool init();
//    
//    // implement the "static create()" method manually
//    CREATE_FUNC(Evading);
//    
//    bool onTouchBegan(Touch* touch, Event* event);
//    void onTouchMoved(Touch* touch, Event* event);
//    void onTouchEnded(Touch* touch, Event* event);
//    
//    virtual void setTitle();
//    
//    void update(float dt);
//    Vec2 getEvadingPosition(Vec2 position,Vec2 targetPosition, Vec2& targetVelocity);
//    Vec2 velocity;
//    Vec2 velocity2;
//    Vec2 m_touchPosition;
//};
#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Evading__) */
