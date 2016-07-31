#include "TankM.h"
#include "GameScene.h"
#include "DataM.h"
#include "AudioM.h"

enum AppearPos		// 敌人坦克出现的位置 
{
	POS_LEFT,		// 左边 
	POS_MIDDLE,		// 中间 
	POS_RIGHT		// 右边 
};

TankM::TankM():
_allAppear(0),
_halt(false),
_playerTank(nullptr),
_enemyMoveAudioId(AudioM::INVALID_AUDIO_ID)
{
	for (auto i = 0; i < 5; i++)
	{
		_killEnemyNum[i] = 0;
	}

	/* 监听开场音效结束事件，开场音效结束后才开始播放敌人坦克行走音效 */
	NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR(TankM::startAudioEnd), "start_audio_end", nullptr);
}

TankM::~TankM()
{
	NotificationCenter::getInstance()->removeAllObservers(this);
}

bool TankM::init()
{
	bool bRet = false;
	do
	{
		_pos = POS_MIDDLE;
		this->createNewPlayer();
		this->schedule(CC_SCHEDULE_SELECTOR(TankM::timer), 3.0f, kRepeatForever, 0.001f);
		
		bRet = true;
	}while(false);
	return bRet;
}

void TankM::timer(float dt)
{
	this->createNewEnemy();
	GameScene::getStage()->updateEnemyNum();
}

Sprite* TankM::createBore(const function<void(Node*)>  callback)
{
	auto bore = Sprite::createWithSpriteFrameName("bore_01.png");
	bore->setName("bore");
	Vector<SpriteFrame*> animFrames(16);
	auto cache = SpriteFrameCache::getInstance();
	/* 动画按照1 2 3 4 4 3 2 1 1 2 3 4 4 3 2 1 顺序播放 */
	for (auto i = 0; i < 4; i++)
	{
		for (auto j = 1; j < 5; j++)
		{
			int id;
			if (i % 2 == 1)
			{
				id = 5 - j;
			}
			else
			{
				id = j;
			}
			auto str = String::createWithFormat("bore_%02d.png", id)->getCString();
			auto frame = cache->getSpriteFrameByName(str);
			animFrames.pushBack(frame);
		}
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto action = Sequence::create(
		Animate::create(animation),
		RemoveSelf::create(),
		CallFuncN::create(callback),
		nullptr);
	bore->runAction(action);
	return bore;
}

void TankM::playerBombEnd()
{
	auto dataM = DataM::getInstance();
	auto life = dataM->getPlayerLife();
	life--;
	if (life == 0)
	{
		NotificationCenter::getInstance()->postNotification("game_fail");
	}
	else
	{
		GameScene::getStage()->updatePlayerLife(life);
		dataM->setPlayerLife(life);
		dataM->setPlayerLevel(PLAYER_INIT_LEVEL);
		this->createNewPlayer();
	}
}

void TankM::createNewPlayer()
{
	auto bore = this->createBore([&](Node* sender){
		_playerTank = PlayerTank::create(0);
		this->addChild(_playerTank);
		_tanks.pushBack(_playerTank);
	});
	bore->setPosition(getPos(25, 9));
	this->addChild(bore, 1);
}

void TankM::createNewEnemy()
{
	auto bore = this->createBore([&](Node* sender){
		auto stage = GameScene::getStage();
		auto tank = EnemyTank::create(stage->getEnemyType(), sender->getPosition());
		this->addChild(tank);
		_tanks.pushBack(tank);
		_enemyTanks.pushBack(tank);
		if (_enemyTanks.size() == 4)
		{
			this->unschedule(CC_SCHEDULE_SELECTOR(TankM::timer));
		}
		auto curEnemyId = stage->getCurEnemyId();
		if ((curEnemyId - 4) % 7 == 0)
		{
			tank->setBonus();
			stage->removeBonus();
		}
		if (curEnemyId == ENEMY_NUM)
		{
			_allAppear = true;
			this->unschedule(CC_SCHEDULE_SELECTOR(TankM::timer));
		}
	});
	bore->setPosition(Vec2((_pos * 12 + 1)*CELL_WIDTH, 25 * CELL_HEIGHT));
	this->addChild(bore, 1);
	_pos++;
	if (_pos >= 3)
	{
		_pos = 0;
	}
}
	

void TankM::removeTank(Tank* tank, bool addScore)
{
	if(tank == _playerTank)
	{
		_playerTank = nullptr;
	}
	else
	{
		if (addScore)
		{
			_killEnemyNum[4]++;
			_killEnemyNum[tank->getType() - 1]++;
		}
		_enemyTanks.eraseObject((EnemyTank*)tank);
		if (!_allAppear && _enemyTanks.size() == 3)
		{
			this->schedule(CC_SCHEDULE_SELECTOR(TankM::timer), 3.0f, kRepeatForever, 1.0f);
		}
	}
	_tanks.eraseObject(tank);
	tank->removeFromParent();
	if (_allAppear && _enemyTanks.size() == 0) 
	{
		if (GameScene::getGameState() == kRuning)
		{
			this->stopEnemyMoveAudio();
			NotificationCenter::getInstance()->postNotification("game_win");
		}
	}
}

void TankM::fail()
{
	this->stopEnemyMoveAudio();
	if (_playerTank)
	{
		_playerTank->stopMoveAudio();
	}
}

void TankM::killAllEnemy()
{
	for (auto i = _enemyTanks.size() - 1; i >= 0; i--)
	{
		auto enemy = _enemyTanks.at(i);
		enemy->die();
	}
}
void TankM::setHaltEnemy()
{
	_halt = true;
	this->unschedule("halt");
	this->scheduleOnce([&](float dt) {
		_halt = false;
	}, 10.0f, "halt");
}

void TankM::pauseGame()
{
	_scheduler->pauseTarget(this);
	for (auto child : this->getChildren())
	{
		if (child->getName() == "bore")
		{
			child->pause();
		}
	}
	if (_playerTank)
	{
		_playerTank->pauseGame();
	}
}

void TankM::resumeGame()
{
	_scheduler->resumeTarget(this);
	for (auto child : this->getChildren())
	{
		if (child->getName() == "bore")
		{
			child->resume();
		}
	}
	if (_playerTank)
	{
		_playerTank->resumeGame();
	}
}

void TankM::playEnemyMoveAudio()
{
	if (GameScene::getGameState() == kRuning)
	{
		if (_enemyMoveAudioId == AudioM::INVALID_AUDIO_ID)
		{
			_enemyMoveAudioId = AudioM::play2d(A_ENEMY_MOVE, true);
		}
	}
}

void TankM::stopEnemyMoveAudio()
{
	if (_enemyMoveAudioId != AudioM::INVALID_AUDIO_ID)
	{
		AudioM::stop(_enemyMoveAudioId);
		_enemyMoveAudioId = AudioM::INVALID_AUDIO_ID;
	}
}

void TankM::startAudioEnd(Ref* obj)
{
	if (GameScene::getGameState() == kRuning)
	{
		this->playEnemyMoveAudio();
	}
}