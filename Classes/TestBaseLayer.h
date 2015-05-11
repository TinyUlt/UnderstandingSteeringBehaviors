//
//  TestBaseLayer.h
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#ifndef __UnderstandingSteeringBehaviors_Seek__TestBaseLayer__
#define __UnderstandingSteeringBehaviors_Seek__TestBaseLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SteeringManager.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrival.h"
#include "Wander.h"
#include "Pursuit.h"
#include "Evading.h"
#include "Movement_Manager.h"
USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;




class TestBaseLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    TestBaseLayer();
    ~TestBaseLayer();//{delete behaviors;};
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    CREATE_FUNC(TestBaseLayer);
    virtual bool init();
    
    void Button_pre_Event(Ref *pSender, Widget::TouchEventType type);
    void Button_next_Event(Ref *pSender, Widget::TouchEventType type);
    void Button_restart_Event(Ref *pSender, Widget::TouchEventType type);
    

    
    // overrides
    virtual void setTitle();
    
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    
    virtual void update(float dt);

    Text*  Text_title;
    Sprite* Sprite_character;
    Sprite* Sprite_character2;
    Vec2 m_touchPosition;
    
    SteeringBehaviors* behaviors;
    SteeringBehaviors* behaviors2;
    
};

class SeekLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(SeekLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
class FleeLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(FleeLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
class ArrivalLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(ArrivalLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
class WanderLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(WanderLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
class PursuitLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(PursuitLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
class EvadingLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(EvadingLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
class Movement_ManagerLayer : public TestBaseLayer
{
public:
    virtual bool init();
    
    CREATE_FUNC(Movement_ManagerLayer);
    
    virtual void setTitle();
    
    void update(float dt);
    
};
#endif /* defined(__UnderstandingSteeringBehaviors_Seek__TestBaseLayer__) */
