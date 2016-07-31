#include "PlayerTank.h"
#include "Global.h"
#include "GameScene.h"
#include "DataM.h"
#include "AudioM.h"
#include "math.h"

PlayerTank::PlayerTank():
_shield(nullptr),
_shootInterval(0.0f),
_move(false),
_moveAudioId(AudioM::INVALID_AUDIO_ID)
{
	_stepMax = 2;
}

PlayerTank::~PlayerTank()
{
}

PlayerTank* PlayerTank::create(int type)
{
	PlayerTank *pRet = new PlayerTank(); 
    if (pRet && pRet->init(type))
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

bool PlayerTank::init(int type)
{
	bool bRet = false;
	do
	{
		_type = type;
		_life = DataM::getInstance()->getPlayerLife();
		this->initWithSpriteFrameName("player1_1_1_1.png");
		this->initPos();
		this->setLevel(DataM::getInstance()->getPlayerLevel());
		this->setShield(2.5f);
		this->scheduleUpdate();
		bRet = true;
	}while(false);
	return bRet;
}

void PlayerTank::update(float dt)
{
	_dt = dt;
	auto state = GameScene::getGameState();
	if (state == kPause || state == kFail)
	{
		return;
	}
	_shootInterval += dt;
	if(g_keyUp)
	{
		_move = true;
		if(_direction == UP)
		{
			moveUp();
			_inertia = 32;
		}
		else
		{
			turnUp();
		}		
	}
	else if(g_keyDown)
	{
		_move = true;
		if(_direction == DOWN)
		{
			moveDown();
			_inertia = 32;
		}
		else
		{
			turnDown();
		}		
	}
	else if(g_keyLeft)
	{
		_move = true;
		if(_direction == LEFT)
		{
			moveLeft();
			_inertia = 32;
		}
		else
		{
			turnLeft();
		}		
	}
	else if(g_keyRight)
	{
		_move = true;
		if(_direction == RIGHT)
		{
			moveRight();
			_inertia = 32;
		}
		else
		{
			turnRight();
		}
	}
	else
	{
		_move = false;
		trackSlip();
	}

	if (_moveAudioId != AudioM::INVALID_AUDIO_ID && _move == false)
	{
		this->stopMoveAudio();
	}
	else if (_moveAudioId == AudioM::INVALID_AUDIO_ID && _move == true)
	{
		this->playMoveAudio();
	}

	if(g_keyB || g_keyA)
	{
		if(g_keyB)
		{
			g_keyB = false;
		}
		if (_shootInterval > 0.1f)
		{
			_shootInterval = 0.0f;
			if (shoot())
			{
				AudioM::play2d(A_BULLET);
			}
		}
	}
	if(overlapCheck())
	{
		_newPos = _position;
	}
	if (collide())
	{
		_inertia = 0;
	}
    auto spriteFrameName = String::createWithFormat("player1_%d_%d_%d.png", min(_level,4), _direction, _step + 1)->getCString();
	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
	this->setSpriteFrame(frame);

	this->setPosition(_newPos);
}
void PlayerTank::trackSlip()
{
	_onIce = GameScene::getStage()->isOnIce(_position);
	if (_onIce && _inertia > 0)
	{
		if (_inertia == 32)
		{
			AudioM::play2d(A_SLIP);
		}
		if (_direction == UP)
		{
			moveUp();
		}
		else if (_direction == DOWN)
		{
			moveDown();
		}
		else if (_direction == LEFT)
		{
			moveLeft();
		}
		else if (_direction == RIGHT)
		{
			moveRight();
		}
		_inertia--;
	}
}

void PlayerTank::initPos()
{
	this->setPos(getPos(25, 9), UP);
	_onIce = false;
}

void PlayerTank::setLevel(int level)
{
    if(level < 1 || level > 8) return;
	_level = level;
	switch(_level)
	{
	case 1:
		_speed = 1.5f;
        _bulletNumMax = 1;
		_bulletSpeed = 4.0f;
		_bulletPower = 0;
		break;
	case 2:
		_speed = 1.5f;
        _bulletNumMax = 2;
        _bulletSpeed = 4.0f;
		_bulletPower = 0;
		break;
	case 3:
		_speed = 1.5f;
        _bulletNumMax = 4;
        _bulletSpeed = 4.0f;
		_bulletPower = 0;
		break;
	case 4:
    case 5:
    case 6:
    case 7:
    case 8:
		_speed = 1.5f;
        _bulletNumMax = 5 + (_level - 4)*5 ;
        _bulletSpeed = 4.0f;
		_bulletPower = 1;
		break;
	default:
		break;
	}
}

void PlayerTank::hit()
{
	if(!_shield)
	{
		this->stopMoveAudio();
		AudioM::play2d(A_PLAYER_BOMB);
		GameScene::getBombM()->createBomb(kPlayerTankBomb, _position);
		GameScene::getTankM()->removeTank(this);
	}
}

void PlayerTank::setShield(float time)
{ 
	if (!_shield)
	{
		_shield = Sprite::createWithSpriteFrameName("shield_01.png");
		Vector<SpriteFrame*> animFrames(2);
		auto cache = SpriteFrameCache::getInstance();
		for (int i = 1; i < 3; i++)
		{
			auto name = String::createWithFormat("shield_%02d.png", i)->getCString();
			auto frame = cache->getSpriteFrameByName(name);
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.03f);
		_shield->runAction(RepeatForever::create(Animate::create(animation)));
		
		_shield->setAnchorPoint(Vec2(0.0f, 0.0f));
		this->addChild(_shield);
	}
	this->unschedule("shield");
	this->scheduleOnce([&](float dt) {
		_shield->removeFromParent();
		_shield = nullptr;
	}, time, "shield");
	
}

void PlayerTank::addLife()
{
	AudioM::play2d(A_ADD_LIFE);
	if (_life < 99)
	{
		_life++;
		DataM::getInstance()->setPlayerLife(_life);
		GameScene::getStage()->updatePlayerLife(_life);
	}
}

void PlayerTank::addLevel()
{
    if (_level < 8)
	{
		_level++;
		DataM::getInstance()->setPlayerLevel(_level);
		this->setLevel(_level);
	}
}

void PlayerTank::pauseGame()
{
	_scheduler->pauseTarget(this);
	if (_shield)
	{
		_shield->setVisible(false);
	}
}

void PlayerTank::resumeGame()
{
	_scheduler->resumeTarget(this);
	if (_shield)
	{
		_shield->setVisible(true);
	}
}

void PlayerTank::playMoveAudio()
{
	if (_moveAudioId == AudioM::INVALID_AUDIO_ID)
	{
		_moveAudioId = AudioM::play2d(A_PLAYER_MOVE, true);
	}
	GameScene::getTankM()->stopEnemyMoveAudio();
}

void PlayerTank::stopMoveAudio()
{
	if (_moveAudioId != AudioM::INVALID_AUDIO_ID)
	{
		AudioM::stop(_moveAudioId);
		_moveAudioId = AudioM::INVALID_AUDIO_ID;
	}
	GameScene::getTankM()->playEnemyMoveAudio();
}
