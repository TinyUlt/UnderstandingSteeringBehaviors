////
////  FleeAndArrival.h
////  UnderstandingSteeringBehaviors_Seek
////
////  Created by TinyUlt on 15/5/9.
////
////
//
#ifndef __UnderstandingSteeringBehaviors_Seek__Flee__
#define __UnderstandingSteeringBehaviors_Seek__Flee__


#include "cocos2d.h"
#include "SteeringBehaviors.h"
USING_NS_CC;
class Flee : public SteeringBehaviors
{
public:
    Flee(){init();};
    
    virtual bool init();
    void update(float dt);
    Vec2 getSeekPosition();
};
#endif /* defined(__UnderstandingSteeringBehaviors_Seek__Flee__) */
