////
////  Movement Manager.h
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/11.
////
////
//
#ifndef __UnderstandingSteeringBehaviors_Seek__Movement_Manager__
#define __UnderstandingSteeringBehaviors_Seek__Movement_Manager__
#include "cocos2d.h"
#include "SteeringBehaviors.h"
#include "Seek.h"
#include "Flee.h"
#include "Wander.h"
USING_NS_CC;
class Movement_Manager : public SteeringBehaviors
{
public:
    Movement_Manager(){init();};
    ~Movement_Manager();
    virtual bool init();
    void update(float dt);
    void setTargetPosition(Vec2 position);
    Vec2 getSeekPosition();
    void setCharacter(Node* character, bool start = true);
    
    SteeringBehaviors* seekBehaviors;
    SteeringBehaviors* fleeBehaviors;
    SteeringBehaviors* wanderBehaviors;
};
//
//#include "cocos2d.h"
//#include "TestBaseLayer.h"
//USING_NS_CC;
//class Movement_Manager : public TestBaseLayer
//{
//public:
//    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//    virtual bool init();
//    
//    // implement the "static create()" method manually
//    CREATE_FUNC(Movement_Manager);
//    
//    bool onTouchBegan(Touch* touch, Event* event);
//    void onTouchMoved(Touch* touch, Event* event);
//    void onTouchEnded(Touch* touch, Event* event);
//    
//    virtual void setTitle();
//    
//    void update(float dt);
//    static Vec2 getMovement_ManagerSteering(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity, Vec2 wanderForce);
//    static Vec2 getMovement_ManagerPosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity, Vec2 wanderForce);
//    Vec2 velocity;
//    Vec2 m_touchPosition;
//    Vec2 wanderForce;
//};
//
#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Movement_Manager__) */
