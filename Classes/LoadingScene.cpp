#include "LoadingScene.h"
#include "Global.h"
#include "SceneM.h"
#include "Joystick.h"
#include "AudioM.h"

LoadingScene::LoadingScene()
{
}

LoadingScene::~LoadingScene()
{
}

bool LoadingScene::init()
{
	bool bRet = false;
	do
	{
		/* 其实没多少资源，并不需要预加载，用到的时候再加载就成 */
		const char* image[] = {"brick.png", "bullet.png", "enemyicon.png", "flag.png", "grass.png", "grid.png", "home1.png", "home2.png", "ice.png", "key1.png", "key2.png",
			"key3.png", "key4.png", "lgameover.png", "menu.png", "p1.png", "pause.png", "playericon.png", "score.png", "sgameover.png", "stage.png"};
		for (auto name : image)
		{
			Director::getInstance()->getTextureCache()->addImage(name);
		}
		const char* plist[] = { "num1.plist", "num2.plist", "player.plist", "enemy.plist", "bonus.plist", "bore.plist", "water.plist", "bomb.plist", "shield.plist" };
		for (auto name : plist)
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile(name);
		}

		AudioM::preloadAllAudio();

		auto joystick = Joystick::create();
		joystick->setOpacity(150);
		Director::getInstance()->setNotificationNode(joystick);

		/* 初始化的时候无法切换场景，故延迟一帧再切换场景 */
		this->scheduleOnce([&](float dt) {
			SceneM::getInstance()->changeScene(kMenuScene);
		}, 0.0f, "delay");
		
		bRet = true;
	}while(false);
	return bRet;
}