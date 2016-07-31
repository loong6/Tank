#include "GameScene.h"
#include "SceneM.h"
#include "Global.h"
#include "Score.h"
#include "DataM.h"
#include "AudioM.h"

GameState GameScene::_gameState = kNone;
Stage* GameScene::_stage = nullptr;
TankM* GameScene::_tankM = nullptr;
BulletM* GameScene::_bulletM = nullptr;
BombM* GameScene::_bombM = nullptr;

GameScene::GameScene()
{
	NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR(GameScene::win), "game_win", nullptr);
	NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR(GameScene::fail), "game_fail", nullptr);
}

GameScene::~GameScene()
{
	NotificationCenter::getInstance()->removeAllObservers(this);
}

void GameScene::onEnterTransitionDidFinish()
{
	_tankM = TankM::create();
	_stage->getBG()->addChild(_tankM, 2);

	_bulletM = BulletM::create();
	_stage->getBG()->addChild(_bulletM, 2);

	_bombM = BombM::create();
	_stage->getBG()->addChild(_bombM, 4);

	_stage->initInfo();

	this->scheduleUpdate();
}

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		_gameState = kRuning;

		_stage = Stage::create();
		this->addChild(_stage, 0);

		bRet = true;
	}while(false);
	return bRet;
}

void GameScene::update(float dt)
{
	if (g_keyStart)
	{
		g_keyStart = false;
		if (_gameState == kRuning)
		{
			AudioM::pauseAll();
			AudioM::play2d(A_PAUSE);
			_gameState = kPause;
			this->pauseGame();
		}
		else if (_gameState == kPause)
		{
			AudioM::resumeAll();
			_gameState = kRuning;
			this->resumeGame();
		}
	}
}

void GameScene::pauseGame()
{
	_stage->pauseGame();
	_tankM->pauseGame();
	_bombM->pauseGame();
}

void GameScene::resumeGame()
{
	_stage->resumeGame();
	_tankM->resumeGame();
	_bombM->resumeGame();
}

void GameScene::fail(Ref* obj)
{
	if (_gameState == kFail) return;
	_gameState = kFail;
	_tankM->fail();
	_stage->fail();
}

void GameScene::win(Ref* obj)
{
	_gameState = kWin;
	_stage->win();
}