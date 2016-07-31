#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

enum Option		// 选项 
{
	ONE_PLAYER,		// 一个玩家 
	TWO_PLAYERS,	// 两个玩家（未实现该选项功能） 
	CONSTRUCTION,	// 建造地图（未实现该选项功能） 
};

/* 菜单场景类 */
class MenuScene : public Layer
{
public:
	MenuScene();
	~MenuScene();
	CREATE_FUNC(MenuScene);
    virtual bool init();  

private:
	void update(float dt);
	/* 移动完毕，显示坦克（箭头） */
	void moveOver();
	/* 设置坦克（箭头）所指选项 */
	void setOption(int option);

	Sprite *_bg;		// 菜单背景 
	Sprite *_tank;		// 坦克（箭头） 
	bool _moveOver;		// 是否移动完毕 
	int _option;		// 选项 
};

#endif