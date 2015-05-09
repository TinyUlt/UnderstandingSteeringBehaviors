//
//  ExMath.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#include "ExMath.h"
Vec2 truncate(Vec2 v, float speed)
{
    
    float l = v.length();
    if (l < speed) {
        return v;
    }
    else
    {
        return v.getNormalized() * speed;
    }
    //return v1.length() < v2.length() ? v1 : v2;
}

Vec2 normalize(Vec2 v)
{
    return v.getNormalized();
}