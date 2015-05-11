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
    if ( !SteeringBehaviors::init() )
    {
        return false;
    }
    return true;
}
void Seek::update(float dt)
{
    SteeringBehaviors::update(dt);
}

Vec2 Seek::getSeekPosition()
{
    auto desired_velocity = normalize(targetPosition - character->getPosition()) * max_velocity;//获计算期望速度
    steering = desired_velocity - velocity;//计算转向速度
    
    steering = steering / mass;//附加物体质量
    velocity = truncate(velocity + steering, max_speed) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度 )
    
    return  character->getPosition() + velocity;
}
