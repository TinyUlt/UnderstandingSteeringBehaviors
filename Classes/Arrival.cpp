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
    Sprite_character->setPosition(getSeekPosition(Sprite_character->getPosition()));
}

Vec2 Arrival::getSeekPosition(Vec2 position)
{
    auto target = m_touchPosition;
    if ((int)target.x == (int)position.x &&(int)target.y == (int)position.y) {
        return position;
    }
    float max_velocity = 10;//原本的期望速度
    float mass = 50;//质量越大,转向越慢
    float max_speed = 8;//最大的实际速度
    float slowingRadius = 100;//检测到的的半径(这时该减速)
    
    auto distance = (target - position).length();//计算物体半径
    auto desired_velocity = normalize(target - position) * max_velocity;//获计算期望速度
    auto steering = desired_velocity - velocity;//计算转向速度
    steering = steering / mass;//附加物体质量
    
    if (distance < slowingRadius)
    {
        max_speed = max_speed * (distance / slowingRadius);//最大速度根据距离缩小而缩小
    }
    velocity = truncate(velocity + steering, max_speed ) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度)
    position = position + velocity;

    
    return position;
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