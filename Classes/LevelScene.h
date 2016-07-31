#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

/* 关卡过渡场景（每两关之间显示第几关的）类 */
class LevelScene : public LayerColor
{
public:
	LevelScene();
	~LevelScene();
	CREATE_FUNC(LevelScene);
    virtual bool init();  
	virtual void onEnterTransitionDidFinish();

private:
	void update(float dt);
	/* 更新显示的关卡id */
	void updateLevel();

	int _id;			// 关卡id 
	bool _first;		// 是否刚从菜单进入游戏（此时可选关） 
	bool _start;		// 是否开始游戏 
	float _interval;	// 控制选关时关卡id变化的时间间隔 
	Sprite * _stage;	// "STAGE"图片的精灵 
	LabelAtlas* _num;	// 关卡id的标签 
};

#endif