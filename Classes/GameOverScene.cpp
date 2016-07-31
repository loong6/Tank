#include "GameOverScene.h"
#include "SceneM.h"
#include "DataM.h"
#include "Global.h"
#include "AudioM.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

bool GameOverScene::init()
{
	bool bRet = false;
	do
	{
		auto bg = Sprite::create("lgameover.png");
		bg->setAnchorPoint(Vec2(0.0f, 0.0f));
		this->addChild(bg);
		this->scheduleOnce([&](float dt) {
			SceneM::getInstance()->changeScene(kMenuScene);
		}, 3.0f, "delay");

		AudioM::play2d(A_GAME_OVER);
		DataM::getInstance()->updateHighScore();
		this->scheduleUpdate();

		bRet = true;
	}while(false);
	return bRet;
}

void GameOverScene::update(float dt)
{
	if (g_keyStart)
	{
		g_keyStart = false;
		AudioM::stopAll();
		SceneM::getInstance()->changeScene(kMenuScene);
	}
}