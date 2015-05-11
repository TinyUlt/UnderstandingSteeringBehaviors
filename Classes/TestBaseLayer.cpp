//
//  TestBaseLayer.cpp
//  UnderstandingSteeringBehaviors_Seek
//
//  Created by TinyUlt on 15/5/9.
//
//

#include "TestBaseLayer.h"

#include "Seek.h"
#include "Flee.h"
#include "Arrival.h"
#include "Wander.h"
#include "Pursuit.h"
#include "Evading.h"
static int sceneIdx = -1;
#define CL(__className__) [](){ return __className__::create();}
static std::function<Layer*()> createFunctions[] =
{
    CL(Seek),
    CL(Flee),
    CL(Arrival),
    CL(Wander),
    CL(Pursuit),
    CL(Evading),

};
#define MAX_LAYER    (sizeof(createFunctions) / sizeof(createFunctions[0]))

void restartCallback(Ref* sender);
void nextCallback(Ref* sender);
void backCallback(Ref* sender);
void replaceSceneCallback();
Scene* TestBaseLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Seek::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    sceneIdx ++;
    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool TestBaseLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    auto Panel_conttrol = static_cast<cocos2d::ui::Layout*>(rootNode->getChildByName("Panel_conttrol"));
    
    Button* Button_pre = static_cast<Button*>(Helper::seekWidgetByName(Panel_conttrol, "Button_pre"));
    Button_pre->addTouchEventListener(CC_CALLBACK_2(TestBaseLayer::Button_pre_Event, this));
    
    Button* Button_next = static_cast<Button*>(Helper::seekWidgetByName(Panel_conttrol, "Button_next"));
    Button_next->addTouchEventListener(CC_CALLBACK_2(TestBaseLayer::Button_next_Event, this));
    
    Button* Button_restart = static_cast<Button*>(Helper::seekWidgetByName(Panel_conttrol, "Button_restart"));
    Button_restart->addTouchEventListener(CC_CALLBACK_2(TestBaseLayer::Button_restart_Event, this));
    
    Text_title = static_cast<Text*>(rootNode->getChildByName("Text_title"));
    
    Sprite_character = static_cast<Sprite*>(rootNode->getChildByName("Sprite_character"));
    Sprite_character2 = static_cast<Sprite*>(rootNode->getChildByName("Sprite_character2"));
    addChild(rootNode);
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(TestBaseLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TestBaseLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(TestBaseLayer::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    setTitle();
    
    this->scheduleUpdate();
    
    return true;
}
void TestBaseLayer::update(float dt)
{
    
}
void TestBaseLayer::Button_pre_Event(Ref *pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED) {
        backCallback(NULL);;
    }
}
void TestBaseLayer::Button_next_Event(Ref *pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED) {
        nextCallback(NULL);
    }
}
void TestBaseLayer::Button_restart_Event(Ref *pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED) {
        restartCallback(NULL);
    }
}

bool TestBaseLayer::onTouchBegan(Touch* touch, Event* event)
{
    return true;
}
void TestBaseLayer::onTouchMoved(Touch* touch, Event* event)
{
    
}
void TestBaseLayer::onTouchEnded(Touch* touch, Event* event)
{
    
}


void TestBaseLayer::setTitle()
{
    
}

void restartCallback(Ref* sender)
{
    replaceSceneCallback();
}
void nextCallback(Ref* sender)
{
    sceneIdx++;
    sceneIdx = sceneIdx % MAX_LAYER;

    replaceSceneCallback();
    
}
void backCallback(Ref* sender)
{
    sceneIdx--;
    if( sceneIdx < 0 ) sceneIdx += MAX_LAYER;
    
    replaceSceneCallback();

}
void replaceSceneCallback()
{
    auto scene = Scene::create();
    Layer* layer = (createFunctions[sceneIdx])();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(scene);
}
