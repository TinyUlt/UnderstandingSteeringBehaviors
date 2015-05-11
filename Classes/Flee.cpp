//
//  FleeAndArrival.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#include "Flee.h"
bool Flee::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !TestBaseLayer::init() )
    {
        return false;
    }
    
    
    return true;
}
void Flee::update(float dt)
{
    Sprite_character->setPosition(getSeekPosition(Sprite_character->getPosition(), m_touchPosition, velocity));
}

Vec2 Flee::getSeekPosition(Vec2 characterPosition, Vec2 targetPosition,Vec2& characterVelocity)
{
    auto target = targetPosition;
    float max_velocity = 10;//原本的期望速度
    float mass = 50;//质量越大,转向越慢
    float max_speed = 10;//最大的实际速度
    
    auto desired_velocity = normalize(-target + characterPosition) * max_velocity;//获计算期望速度
    auto steering = desired_velocity - characterVelocity;//计算转向速度
    steering = steering / mass;//附加物体质量
    characterVelocity = truncate(characterVelocity + steering, max_speed) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度 )
    characterPosition = characterPosition + characterVelocity;
    
    return characterPosition;
}

bool Flee::onTouchBegan(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
    return true;
}
void Flee::onTouchMoved(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
}
void Flee::onTouchEnded(Touch* touch, Event* event)
{
    
}

void Flee::setTitle()
{
    Text_title->setString("Flee");
}