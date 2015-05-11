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
#include "ExMath.h"
USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;




class TestBaseLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
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
    static Vec2 getBehaviorsPosition(Vec2 characterPosition,Vec2& characterVelocity, Vec2 steering, float max_speed = 10);
    Text*  Text_title;
    Sprite* Sprite_character;
    Sprite* Sprite_character2;
};



#endif /* defined(__UnderstandingSteeringBehaviors_Seek__TestBaseLayer__) */
