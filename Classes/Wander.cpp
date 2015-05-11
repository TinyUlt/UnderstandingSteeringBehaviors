//
//  Wander.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#include "Wander.h"
bool Wander::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !TestBaseLayer::init() )
    {
        return false;
    }
    wanderForce = Vec2(0,0);
    velocity = Vec2(2, 0);//初始速度
    velocity.rotate(Vec2(0, 0), random(0.0f, 1.0f) *  M_PI * 2);//初始方向

    return true;
}
void Wander::update(float dt)
{
    Sprite_character->setPosition(getSeekPosition(Sprite_character->getPosition(), m_touchPosition, velocity, wanderForce));
}

Vec2 Wander::getSeekPosition(Vec2 characterPosition, Vec2 targetPosition,Vec2& characterVelocity, Vec2& wanderForce)
{
    static int _timeOffset = 0;
    _timeOffset ++;
    if (_timeOffset >= 10)//变换一次角度
    {
        _timeOffset -=10;
        
        float CIRCLE_DISTANCE = 2;//圆的距离
        float CIRCLE_RADIUS = 10;//源的半径
        float ANGLE_CHANGE = M_PI ;//速度的变换范围
        auto circleCenter = characterVelocity.getNormalized();
        circleCenter.scale(CIRCLE_DISTANCE);//物体到圆的向量
        
        //圆中的单位向量
        Vec2 displacement = characterVelocity.getNormalized();
        displacement.scale(CIRCLE_RADIUS);
        
        float wanderAngle = (random(0.0f, 1.0f)* ANGLE_CHANGE) - (ANGLE_CHANGE * .5);//偏移的角度量
        displacement.rotate(Vec2(0,0), wanderAngle);//获取圆向量
        wanderForce = circleCenter + displacement; //获得偏移向量
    }
    
    
    float mass = 50;//质量越大,转向越慢
    float max_speed = 5;//最大的实际速度
    
    auto steering = wanderForce;//desired_velocity - velocity;//计算转向速度
    steering = steering / mass;//附加物体质量
    characterVelocity = truncate(characterVelocity + steering, max_speed) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度 )
    characterPosition = characterPosition + characterVelocity;
    
    return characterPosition;
}
bool Wander::onTouchBegan(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
    return true;
}
void Wander::onTouchMoved(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
}
void Wander::onTouchEnded(Touch* touch, Event* event)
{
    
}

void Wander::setTitle()
{
    Text_title->setString("Wander");
}