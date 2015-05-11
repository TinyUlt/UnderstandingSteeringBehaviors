////
////  Arrival.cpp
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/9.
////
////
//
#include "Arrival.h"
bool Arrival::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !SteeringBehaviors::init() )
    {
        return false;
    }
    return true;
}
void Arrival::update(float dt)
{
    SteeringBehaviors::update(dt);
}

Vec2 Arrival::getSeekPosition()
{
    if ((int)targetPosition.x ==
        (int)character->getPosition().x &&
        (int)targetPosition.y ==
        (int)character->getPosition().y)
    {
        return character->getPosition();
    }
    
    float slowingRadius = 100;//检测到的的半径(这时该减速)
    auto distance = (targetPosition - character->getPosition()).length();//计算物体半径
    float speed = 10;
    if (distance < slowingRadius)
    {
        speed = max_speed * (distance / slowingRadius);//最大速度根据距离缩小而缩小
    }
    
    
    auto desired_velocity = normalize(targetPosition - character->getPosition()) * max_velocity;//获计算期望速度
    steering = desired_velocity - velocity;//计算转向速度
    
    steering = steering / mass;//附加物体质量
    
    log("%f, %f", speed,(velocity + steering).length());
    velocity = truncate(velocity + steering, speed) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度 )
    
    return  character->getPosition() + velocity;
}