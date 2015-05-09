//
//  Seek.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
// 参考网站
//http://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-seek--gamedev-849
#include "Seek.h"
bool Seek::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !TestBaseLayer::init() )
    {
        return false;
    }
    return true;
}
void Seek::update(float dt)
{
    Sprite_character->setPosition(getSeekPosition(Sprite_character->getPosition()));
}

Vec2 Seek::getSeekPosition(Vec2 position)
{
    auto target = m_touchPosition;
    float max_velocity = 10;//原本的期望速度
    float mass = 50;//质量越大,转向越慢
    float max_speed = 100000;//最大的实际速度
    
    /*以下为作者源码 http://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-seek--gamedev-849*/
    auto desired_velocity = normalize(target - position) * max_velocity;
    auto steering = desired_velocity - velocity;
    steering = steering / mass;
    velocity = truncate(velocity + steering, max_speed) ;
    position = position + velocity;
    /************/
    
    return position;
}
bool Seek::onTouchBegan(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
    return true;
}
void Seek::onTouchMoved(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
}
void Seek::onTouchEnded(Touch* touch, Event* event)
{
    
}

void Seek::setTitle()
{
    Text_title->setString("Seek");
}