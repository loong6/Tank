#include "LevelScene.h"
#include "Global.h"
#include "SceneM.h"
#include "DataM.h"
#include "AudioM.h"
#include <string>

using namespace std;

LevelScene::LevelScene():
_start(false),
_interval(-1.0f)
{
}

LevelScene::~LevelScene()
{
}

void LevelScene::onEnterTransitionDidFinish()
{
	auto stage = Sprite::create("stage.png");
	stage->setPosition(Vec2(234, SCREEN_CY));
	this->addChild(stage);

	auto num = String::createWithFormat("%d", _id)->getCString();
	_num = LabelAtlas::create(num, "num1.plist");
	_num->setColor(Color3B::BLACK);
	_num->setAnchorPoint(Vec2(1.0f, 0.5f));
	_num->setPosition(Vec2(321, SCREEN_CY));
	this->addChild(_num);

	auto time = 1.0f;
	if (_first)
	{
		time = 0.01f;
	}
	this->scheduleOnce([&](float dt) {
		this->scheduleUpdate();
	}, time, "delay");
}

bool LevelScene::init()
{
	bool bRet = false;
	do
	{
		LayerColor::initWithColor(Color4B(126, 126, 126, 255));
		
		_id = DataM::getInstance()->getLevelId();
		_first = DataM::getInstance()->isSelectLevelEnable();
		DataM::getInstance()->setSelectLevelEnable(false);

		bRet = true;
	}while(false);
	return bRet;
}

void LevelScene::update(float dt)
{
	if (_first)
	{
		if (_interval >= 0)
		{
			_interval += dt;
		}
		if (_interval < 0 || _interval > 0.15f)
		{
			if (g_keyA)
			{
				_interval = 0.0f;
				if (_id < LEVEL_NUM)
				{
					_id++;
					this->updateLevel();
				}
			}
			else if (g_keyB)
			{
				_interval = 0.0f;
				if (_id > 1)
				{
					_id--;
					this->updateLevel();
				}
			}
			else
			{
				_interval = -1.0f;
			}
		}
		
		if (g_keyStart)
		{
			g_keyStart = false;
			_start = true;
		}
	}
	else
	{
		_start = true;
	}
	if (_start)
	{
		this->unscheduleUpdate();
		AudioM::play2d(A_START);
		this->schedule([&](float dt) {
			removeAllChildren();
			SceneM::getInstance()->changeScene(kGameScene, kTransitionExA);
		},1.5f, "delay");
	}
}

void LevelScene::updateLevel()
{
	DataM::getInstance()->setLevelId(_id);
	auto num = String::createWithFormat("%d", _id)->getCString();
	_num->setString(num);
}