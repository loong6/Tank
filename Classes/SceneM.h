#ifndef __SCENE_M_H__
#define __SCENE_M_H__

#include "cocos2d.h"

USING_NS_CC;

enum SceneType			// 场景类型 
{
	kLoadingScene,		// 加载场景 
	kMenuScene,			// 菜单场景 
	kLevelScene,		// 关卡过渡场景 
	kGameScene,			// 游戏场景 
	kGameOverScene		// 游戏结束场景 
};

enum TransitionType		// 场景切换效果类型 
{
	kTransitionNone,	// 无 
	kTransitionExA,		// 扩展效果A（进入关卡过渡场景的效果） 
	kTransitionExB,		// 扩展效果B（离开关卡过渡场景的效果） 
};


/* 场景管理类 */
class SceneM : public Ref
{
public:
	SceneM();
	~SceneM();
	static SceneM* getInstance();
	bool init();
	/* 切换场景 */
	void changeScene(SceneType sceneType, TransitionType transitionType=kTransitionNone);
	/* 获取当前场景的图层 */
	Layer* getCurScene(){ return _layer; }

private:
	Layer* _layer;		// 当前场景的图层 

};
#endif