//
//  Arrival.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#include "Arrival.h"
bool Arrival::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !TestBaseLayer::init() )
    {
        return false;
    }
    
    
    return true;
}
void Arrival::update(float dt)
{
    Sprite_character->setPosition(getArrivalPosition(Sprite_character->getPosition(), m_touchPosition, velocity));
}
Vec2 Arrival::getArrivalSteering(Vec2 characterPosition,Vec2 targetPosition, Vec2& characterVelocity, float &max_speed)
{
    auto target = targetPosition;
    float max_velocity = 10;//原本的期望速度
    float slowingRadius = 100;//检测到的的半径(这时该减速)
    
    auto distance = (target - characterPosition).length();//计算物体半径
    auto desired_velocity = normalize(target - characterPosition) * max_velocity;//获计算期望速度
    if (distance < slowingRadius)
    {
        max_speed = max_speed * (distance / slowingRadius);//最大速度根据距离缩小而缩小
    }
    auto steering = desired_velocity - characterVelocity;//计算转向速度
    
    return steering;
}
Vec2 Arrival::getArrivalPosition(Vec2 characterPosition, Vec2 targetPosition,Vec2& characterVelocity)
{
    if ((int)targetPosition.x ==
        (int)characterPosition.x &&
        (int)targetPosition.y ==
        (int)characterPosition.y)
    {
        return characterPosition;
    }
    
    float max_speed = 10;
    auto steering = getArrivalSteering(characterPosition, targetPosition, characterVelocity, max_speed);
    characterPosition = getBehaviorsPosition(characterPosition, characterVelocity, steering, max_speed);
   
    return characterPosition;
}
bool Arrival::onTouchBegan(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
    return true;
}
void Arrival::onTouchMoved(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
}
void Arrival::onTouchEnded(Touch* touch, Event* event)
{
    
}

void Arrival::setTitle()
{
    Text_title->setString("Arrival");
}