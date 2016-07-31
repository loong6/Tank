#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

/* 游戏结束场景类 */
class GameOverScene : public Layer
{
public:
	GameOverScene();
	~GameOverScene();
	CREATE_FUNC(GameOverScene);
    virtual bool init();  

private:
	void update(float dt);
};

#endif