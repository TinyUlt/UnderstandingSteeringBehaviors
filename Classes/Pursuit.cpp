//
//  Pursuit.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#include "Pursuit.h"
#include "Seek.h"
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
    Sprite_character->setPosition(Seek::getSeekPosition(Sprite_character->getPosition(),m_touchPosition, velocity));
    Sprite_character2->setPosition(getPursuitPosition(Sprite_character2->getPosition(),Sprite_character->getPosition(), velocity));
}


Vec2 Pursuit::getPursuitPosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& targetVelocity)
{
    auto MAX_VELOCITY = 2;
    auto distance = (targetPosition - characterPosition).length();
    
    int T = distance / MAX_VELOCITY;//提前预判的更新次数
    Vec2 futurePosition = targetPosition + targetVelocity * T;
    
    return Seek::getSeekPosition(characterPosition, futurePosition, velocity2);
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