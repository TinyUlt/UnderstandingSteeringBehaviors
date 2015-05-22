//
//  SteeringBehaviors.h
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#ifndef __UnderstandingSteeringBehaviors_Seek__SteeringBehaviors__
#define __UnderstandingSteeringBehaviors_Seek__SteeringBehaviors__

#include "cocos2d.h"
#include "ExMath.h"
USING_NS_CC;
class SteeringBehaviors
{
public:
    SteeringBehaviors();
    virtual ~SteeringBehaviors();
    virtual bool init();
    
    // implement the "static create()" method manually
    //CREATE_FUNC(Seek);

    virtual void update(float dt);
    virtual Vec2 getSeekPosition() = 0;
    virtual void setCharacter(Node* character, bool start = true);
    virtual void setTargetPosition(Vec2 position);
    Vec2 getBehaviorsPosition();
    void start(Vec2 velocity);
    void stop();

    
    bool isStarting;
    Node* character;
    
    Vec2 velocity;
    float mass ;//质量越大,转向越慢
    float max_speed;
    Vec2 targetPosition;
    Vec2 steering;
    float max_velocity;//原本的期望速度
};

#endif /* defined(__UnderstandingSteeringBehaviors_Seek__SteeringBehaviors__) */
