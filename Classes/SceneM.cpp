#include "SceneM.h"
#include "TransitionEx.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "LevelScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

static SceneM *s_SharedSceneM = nullptr;

SceneM::SceneM()
{
}

SceneM::~SceneM()
{
}

SceneM* SceneM::getInstance()
{
    if (!s_SharedSceneM)
    {
        s_SharedSceneM = new (std::nothrow) SceneM();
        CCASSERT(s_SharedSceneM, "FATAL: Not enough memory");
        s_SharedSceneM->init();
    }

    return s_SharedSceneM;
}

bool SceneM::init()
{
	bool bRet = false;
	do
	{
		bRet = true;
	}while(false);
	return bRet;
}

void SceneM::changeScene(SceneType sceneType, TransitionType transitionType)
{
	auto scene = Scene::create();
	switch(sceneType)
	{
	case kLoadingScene:
		_layer = LoadingScene::create();
		break;
	case kMenuScene:
		_layer = MenuScene::create();
		break;
	case kLevelScene:
		_layer = LevelScene::create();
		break;
	case kGameScene:
		_layer = GameScene::create();
		break;
	case kGameOverScene:
		_layer = GameOverScene::create();
		break;
	}
	scene->addChild(_layer);
	auto director = Director::getInstance();
	auto curScene = director->getRunningScene();
	switch (transitionType)
	{
	case kTransitionExA:
		scene = TransitionExA::create(0.5f, scene);
		break;
	case kTransitionExB:
		scene = TransitionExB::create(0.5f, scene);
		break;
	default:
		break;
	}
	if(curScene)
	{
		director->replaceScene(scene);
	}
	else
	{
		director->runWithScene(scene);
	}
}
