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
    Sprite_character->setPosition(getSeekPosition(Sprite_character->getPosition()));
}

Vec2 Flee::getSeekPosition(Vec2 position)
{
    auto target = m_touchPosition;
    float max_velocity = 10;//原本的期望速度
    float mass = 50;//质量越大,转向越慢
    float max_speed = 10;//最大的实际速度
    
    
    auto desired_velocity = normalize(-target + position) * max_velocity;
    auto steering = desired_velocity - velocity;
    steering = steering / mass;
    velocity = truncate(velocity + steering, max_speed) ;
    position = position + velocity;
        
    return position;
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