//
//  ExMath.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#include "ExMath.h"
Vec2 truncate(Vec2 v, float max)
{
    log("%f", v.length());
    auto i = max / v.length();
    i = i < 1.0 ? i : 1.0;
    v.scale(i);
    return v;
}

Vec2 normalize(Vec2 v)
{
    return v.getNormalized();
}