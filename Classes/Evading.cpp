//
//  Evading.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#include "Evading.h"
#include "Flee.h"
#include "Seek.h"
bool Evading::init()
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
void Evading::update(float dt)
{
    Sprite_character->setPosition(Seek::getSeekPosition(Sprite_character->getPosition(),m_touchPosition, velocity));
    Sprite_character2->setPosition(getSeekPosition(Sprite_character2->getPosition(),Sprite_character->getPosition(), velocity));
}


Vec2 Evading::getSeekPosition(Vec2 characterPosition,Vec2 targetPosition, Vec2& targetVelocity)
{
    auto MAX_VELOCITY = 2;
    auto distance = (targetPosition - characterPosition).length();
    
    int T = distance / MAX_VELOCITY;//提前预判的更新次数
    Vec2 futurePosition = targetPosition + targetVelocity * T;
    
    return Flee::getSeekPosition(characterPosition, futurePosition, velocity2);
}
bool Evading::onTouchBegan(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
    return true;
}
void Evading::onTouchMoved(Touch* touch, Event* event)
{
    m_touchPosition = touch->getLocation();
}
void Evading::onTouchEnded(Touch* touch, Event* event)
{
    
}

void Evading::setTitle()
{
    Text_title->setString("Pursuit");
}