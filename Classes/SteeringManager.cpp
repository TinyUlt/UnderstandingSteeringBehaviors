//
//  SteeringManager.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#include "SteeringManager.h"
SteeringManager* SteeringManager::instance = NULL;
SteeringManager* SteeringManager::getManager()
{
    if (instance == NULL) {
        instance = new SteeringManager();
    }
    return instance;
}
void SteeringManager::add(SteeringBehaviors* steering)
{
    steeringArray.push_back(steering);
}
void SteeringManager::update(float dt)
{
    for (auto & child : steeringArray) {
        child->update(dt);
    }
}

void SteeringManager::remove(SteeringBehaviors* steering)
{
    for (auto iter = steeringArray.begin(); iter != steeringArray.end(); iter++) {
        if (*iter == steering) {
            steeringArray.erase(iter);
        }
    }
}