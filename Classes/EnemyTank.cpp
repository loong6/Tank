#include "EnemyTank.h"
#include "Global.h"
#include "GameScene.h"
#include "AudioM.h"

EnemyTank::EnemyTank():
_addScore(false),
_bonus(false),
_bonusStep(0)
{
}

EnemyTank::~EnemyTank()
{
}

EnemyTank* EnemyTank::create(int type, Vec2 pos)
{
	EnemyTank *pRet = new EnemyTank(); 
    if (pRet && pRet->init(type, pos))
    {
        pRet->autorelease();
        return pRet; 
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool EnemyTank::init(int type, Vec2 pos)
{
	bool bRet = false;
	do
	{
		_type = type;
		_direction = DOWN;
		this->setPosition(pos);
		_newPos = pos;
		switch(type)
		{
		case 1:
			_level = 1;
			_speed = 1.0f;
			_bulletNumMax = 1;
			_bulletSpeed = 4.0f;
			_bulletPower = 0;
			_stepMax = 2;
			break;
		case 2:
			_level = 1;
			_speed = 2.0f;
			_bulletNumMax = 1;
			_bulletSpeed = 4.0f;
			_bulletPower = 0;
			_stepMax = 2;
			break;
		case 3:
			_level = 1;
			_speed = 1.0f;
			_bulletNumMax = 1;
			_bulletSpeed = 8.0f;
			_bulletPower = 0;
			_stepMax = 2;
			break;
		case 4:
			_level = 4;
			_speed = 1.0f;
			_bulletNumMax = 1;
			_bulletSpeed = 4.0f;
			_bulletPower = 0;
			_stepMax = 4;
			break;
		default:
			break;
		}
		auto name = String::createWithFormat("enemy%d_%d_%d_1.png", _type, _level, _direction)->getCString();
		this->initWithSpriteFrameName(name);
		
		this->scheduleUpdate();

		bRet = true;
	}while(false);
	return bRet;
}

void EnemyTank::update(float dt)
{
	_dt = dt;
	if (!GameScene::getTankM()->isHaltEnemy() && GameScene::getGameState() != kPause)
	{
		switch (_direction)
		{
		case UP:
			this->moveUp();
			break;
		case DOWN:
			this->moveDown();
			break;
		case LEFT:
			this->moveLeft();
			break;
		case RIGHT:
			this->moveRight();
			break;
		default:
			break;
		}
		if (collide() || overlapCheck() || rand() % 40 == 0)
		{
			switch (rand() % 4)
			{
			case 0:
				turnUp();
				break;
			case 1:
				turnDown();
				break;
			case 2:
				turnLeft();
				break;
			case 3:
				turnRight();
				break;
			default:
				break;
			}
		}
		if (rand() % 30 == 0)
		{
			shoot();
		}
	}
	int step;
	if (_bonus)
	{
		step = _stepMax * _bonusStep + _step % (_bonusStep + 1) + 1;
	}
	else
	{
		step = _step+ 1;
	}
	auto spriteFrameName = String::createWithFormat("enemy%d_%d_%d_%d.png", _type, _level, _direction, step)->getCString();
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
	this->setSpriteFrame(frame);

	this->setPosition(_newPos);
}

void EnemyTank::hit()
{
	if (_bonus)
	{
        GameScene::getStage()->createBonus((BonusType)(rand() % 6 + 1));
	}
	_level -= 1;
	if(_level <= 0)
	{
		_addScore = true;
		die();
	}
	else
	{
		AudioM::play2d(A_METAL);
		if(_type == 4 )
		{
			if (_level == 1)
			{
				_step = 0;
				_stepMax = 2;
			}
			this->cancelBonus();
		}
	}
}

void EnemyTank::die()
{
	if (_addScore)
	{
		AudioM::play2d(A_ENEMY_BOMB);
		GameScene::getBombM()->createBomb(kEnemyTankBomb, _position, ENEMY_SCORE[_type - 1]);
	}
	else
	{
		/* 被道具杀死，不得分，且吃道具的音效自带爆炸声 */
		GameScene::getBombM()->createBomb(kEnemyTankBomb, _position);
	}
	GameScene::getTankM()->removeTank(this, _addScore);
}

void EnemyTank::setBonus()
{
	_bonus = true;
	this->schedule([&](float dt) {
		_bonusStep = 1 - _bonusStep;
	}, 0.13f, "BonusStep");
}

void EnemyTank::cancelBonus()
{
	this->unschedule("BonusStep");
	_bonus = false;
	_bonusStep = 0;
}
