//
//  FleeAndArrival.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#include "FleeAndArrival.h"
bool FleeAndArrival::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !TestBaseLayer::init() )
    {
        return false;
    }
    
    
    return true;
}
bool FleeAndArrival::onTouchBegan(Touch* touch, Event* event)
{
    return true;
}
void FleeAndArrival::onTouchMoved(Touch* touch, Event* event)
{
    
}
void FleeAndArrival::onTouchEnded(Touch* touch, Event* event)
{
    
}

void FleeAndArrival::setTitle()
{
    Text_title->setString("FleeAndArrival");
}