////
////  Pursuit.cpp
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/11.
////
////
//
#include "Pursuit.h"
bool Pursuit::init(SteeringBehaviors* target)
{
    //////////////////////////////
    // 1. super init first
    if ( !Seek::init() )
    {
        return false;
    }
    this->target = target;
    return true;
}
void Pursuit::update(float dt)
{
    SteeringBehaviors::update(dt);
}

Vec2 Pursuit::getSeekPosition()
{
    auto MAX_VELOCITY = 5;
    auto distance = (targetPosition - character->getPosition()).length();
    
    int T = distance / MAX_VELOCITY;//提前预判的更新次数
    targetPosition = target->character->getPosition() + target->velocity * T;
    
    return  Seek::getSeekPosition();
}

//
//bool Pursuit::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !TestBaseLayer::init() )
//    {
//        return false;
//    }
//    Sprite_character2->setPosition(Vec2(200,200));
//    seekTargetBehaviors = Seek::create();
//    seekPursuiterBehaviors = Seek::create();
//    return true;
//}
//void Pursuit::update(float dt)
//{
//    Sprite_character->setPosition(seekTargetBehaviors->getSeekPosition(Sprite_character->getPosition(),m_touchPosition));
//    Sprite_character2->setPosition(getPursuitPosition(Sprite_character2->getPosition(),Sprite_character->getPosition()));
//}
//
//
//Vec2 Pursuit::getPursuitPosition(Vec2 characterPosition,Vec2 targetPosition)
//{
//    auto MAX_VELOCITY = 2;
//    auto distance = (targetPosition - characterPosition).length();
//    
//    int T = distance / MAX_VELOCITY;//提前预判的更新次数
//    Vec2 futurePosition = targetPosition + seekTargetBehaviors->velocity * T;
//    
//    return seekPursuiterBehaviors->getSeekPosition(characterPosition, futurePosition);
//}
//bool Pursuit::onTouchBegan(Touch* touch, Event* event)
//{
//    m_touchPosition = touch->getLocation();
//    return true;
//}
//void Pursuit::onTouchMoved(Touch* touch, Event* event)
//{
//    m_touchPosition = touch->getLocation();
//}
//void Pursuit::onTouchEnded(Touch* touch, Event* event)
//{
//    
//}
//
//void Pursuit::setTitle()
//{
//    Text_title->setString("Pursuit");
//}