//
//  SteeringBehaviors.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#include "SteeringBehaviors.h"
#include "SteeringManager.h"
SteeringBehaviors::SteeringBehaviors():mass(50),max_velocity(10),max_speed(10),targetPosition(Vec2(0,0)), character(NULL),isStarting(false){
    
}
SteeringBehaviors::~SteeringBehaviors()
{
    SteeringManager::getManager()->remove(this);
}
bool SteeringBehaviors::init()
{
    return true;
}
void SteeringBehaviors::update(float dt)
{
    if (character && isStarting) {
        character->setPosition(getSeekPosition());
    }

}
//Vec2 SteeringBehaviors::getSeekPosition()
//{
//    
//}
void SteeringBehaviors::setCharacter(Node* character, bool start)
{
    this->character = character;
    this->isStarting = start;
    SteeringManager::getManager()->add(this);
}

void SteeringBehaviors::setTargetPosition(Vec2 position)
{
    this->targetPosition = position;
}

Vec2 SteeringBehaviors::getBehaviorsPosition()
{
    steering = steering / mass;//附加物体质量
    velocity = truncate(velocity + steering, max_speed) ;//实际速度 = 当前速度+转向速度 ( 保证最大速度 )
    
    return  character->getPosition() + velocity;
}

void SteeringBehaviors::start(Vec2 velocity)
{
    isStarting = true;
    this->velocity = velocity;
}
void SteeringBehaviors::stop()
{
    isStarting = false;
}