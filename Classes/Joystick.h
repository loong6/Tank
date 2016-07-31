#ifndef  __JOYSTICK_H__
#define  __JOYSTICK_H__

#include "cocos2d.h"

USING_NS_CC;

/* 虚拟手柄（包含键盘）类 */
class Joystick : public Layer
{
public:
	Joystick();
	~Joystick();
    CREATE_FUNC(Joystick)
    virtual bool init();  

private:
	/* 设置触摸（虚拟手柄） */
	void setTouch(Sprite* target, Vec2 location, bool state);
	/* 设置按键状态（键盘） */
	void setKeyState(EventKeyboard::KeyCode keyCode, bool state);
    //is first touch back
    bool _bBackFlag;

};

#endif
