////
////  Movement Manager.cpp
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/11.
////
////
//
#include "Movement_Manager.h"
#include "SteeringManager.h"
Movement_Manager::~Movement_Manager()
{
    delete seekBehaviors;
    delete wanderBehaviors;
    SteeringBehaviors::~SteeringBehaviors();
    
}
bool Movement_Manager::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !SteeringBehaviors::init() )
    {
        return false;
    }
    seekBehaviors = new Seek();
//    fleeBehaviors = new Flee();
    wanderBehaviors = new Wander();
    seekBehaviors->max_speed = 5;
    seekBehaviors->max_velocity = 5;
    wanderBehaviors->max_speed = 2;
    wanderBehaviors->max_velocity = 5;
    return true;
}
void Movement_Manager::update(float dt)
{
    SteeringBehaviors::update(dt);
}

Vec2 Movement_Manager::getSeekPosition()
{
    
    float slowingRadius = 200;//检测到的的半径(这时该减速)
    auto distance = (targetPosition - character->getPosition()).length();//计算物体半径
    Vec2 v(0,0);
    if (distance > slowingRadius)
    {
        wanderBehaviors->start();
        seekBehaviors->stop();
        v = wanderBehaviors->getSeekPosition();
    }
    else
    {
        wanderBehaviors->stop();
        seekBehaviors->start();
        v = seekBehaviors->getSeekPosition();
    }
    
    return  v;
}
void Movement_Manager::setCharacter(Node* character, bool start )
{
    SteeringBehaviors::setCharacter(character);
    seekBehaviors->setCharacter(character);
    wanderBehaviors->setCharacter(character , false);
    
}
void Movement_Manager::setTargetPosition(Vec2 position)
{
    SteeringBehaviors::setTargetPosition(position);
    seekBehaviors->setTargetPosition(position);
    wanderBehaviors->setTargetPosition(position);
}
//#include "Seek.h"
//#include "Wander.h"
//bool Movement_Manager::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !TestBaseLayer::init() )
//    {
//        return false;
//    }
//    wanderForce = Vec2(0,0);
//    velocity = Vec2(2, 0);//初始速度
//    velocity.rotate(Vec2(0, 0), random(0.0f, 1.0f) *  M_PI * 2);//初始方向
//    return true;
//}
//void Movement_Manager::update(float dt)
//{
//    Sprite_character->setPosition(getMovement_ManagerSteering(Sprite_character->getPosition(), m_touchPosition, velocity, wanderForce));
//}
//Vec2 Movement_Manager::getMovement_ManagerSteering(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity, Vec2 wanderForce)
//{
//    Vec2 steering;
////    auto distance = (targetPosition - characterPosition).length();
////    if (distance <= 300) {
////        steering = Seek::getSeekSteering( characterPosition,  targetPosition,  characterVelocity);
////    } else
////    {
//        steering = Wander::getWanderSteering( characterPosition,  targetPosition,  characterVelocity, wanderForce);
////    }
//    
//    return steering;
//}
//Vec2 Movement_Manager::getMovement_ManagerPosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity, Vec2 wanderForce)
//{
//    auto steering = getMovement_ManagerSteering(characterPosition, targetPosition, characterVelocity,wanderForce);
//    characterPosition = getBehaviorsPosition(characterPosition, characterVelocity, steering);
//    
//    return characterPosition;
//}
//
//bool Movement_Manager::onTouchBegan(Touch* touch, Event* event)
//{
//    m_touchPosition = touch->getLocation();
//    return true;
//}
//void Movement_Manager::onTouchMoved(Touch* touch, Event* event)
//{
//    m_touchPosition = touch->getLocation();
//}
//void Movement_Manager::onTouchEnded(Touch* touch, Event* event)
//{
//    
//}
//
//void Movement_Manager::setTitle()
//{
//    Text_title->setString("Seek");
//}