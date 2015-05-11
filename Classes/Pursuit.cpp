//
//  Pursuit.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#include "Pursuit.h"
bool Pursuit::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !TestBaseLayer::init() )
    {
        return false;
    }
    Sprite_character2->setPosition(Vec2(200,200));
    return true;
}
void Pursuit::update(float dt)
{
    Sprite_character->setPosition(getSeekPosition(Sprite_character->getPosition(),m_touchPosition, velocity));
    Sprite_character2->setPosition(getPursuitPosition(Sprite_character2->getPosition(),Sprite_character->getPosition(), velocity));
}

Vec2 Pursuit::getSeekPosition(Vec2 characterPosition, Vec2 targetPosition,Vec2& characterVelocity)
{
    auto target = targetPosition;
    float max_velocity = 10;//原本的期望速度
    float mass = 50;//质量越大,转向越慢
    float max_speed = 10;//最大的实际速度
    
    auto desired_velocity = normalize(target - characterPosition) * max_velocity;//获计算期望速度
    auto steering = desired_velocity - characterVelocity;//计算转向速度
    steering = steering / mass;//附加物体质量
    characterVelocity = truncate(characterVelocity + steering, max_speed) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度 )
    characterPosition = characterPosition + characterVelocity;
    log("%f", characterVelocity.length());
    
    return characterPosition;
}
Vec2 Pursuit::getPursuitPosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& targetVelocity)
{
    auto MAX_VELOCITY = 2;
    auto distance = (targetPosition - characterPosition).length();
    
    int T = distance / MAX_VELOCITY;//提前预判的更新次数
    Vec2 futurePosition = targetPosition + targetVelocity * T;
    
    return getSeekPosition(characterPosition, futurePosition, velocity2);
}
bool Pursuit::onTouchBegan(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
    return true;
}
void Pursuit::onTouchMoved(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
}
void Pursuit::onTouchEnded(Touch* touch, Event* event)
{
    
}

void Pursuit::setTitle()
{
    Text_title->setString("Pursuit");
}