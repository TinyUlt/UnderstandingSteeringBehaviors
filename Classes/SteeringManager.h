//
//  SteeringManager.h
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/11.
//
//

#ifndef __UnderstandingSteeringBehaviors_Seek__SteeringManager__
#define __UnderstandingSteeringBehaviors_Seek__SteeringManager__
#include "SteeringBehaviors.h"
#include <vector>
using namespace std;
class SteeringManager
{
public:
    static SteeringManager* getManager();
    
    static SteeringManager* instance;
    
    void add(SteeringBehaviors* steering);
    void remove(SteeringBehaviors* steering);
    vector<SteeringBehaviors*> steeringArray;
    void update(float dt);
};

#endif /* defined(__UnderstandingSteeringBehaviors_Seek__SteeringManager__) */
