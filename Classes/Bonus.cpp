#include "Bonus.h"
#include "Global.h"
#include "GameScene.h"
#include "AudioM.h"

Bonus::Bonus()
{
}

Bonus::~Bonus()
{
}

Bonus* Bonus::create(BonusType type)
{
	Bonus *pRet = new Bonus();
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

bool Bonus::init(BonusType type)
{
	bool bRet = false;
	do
	{
		_type = type;
		this->initWithSpriteFrameName(String::createWithFormat("bonus_%02d.png", _type)->getCString());
		int row, col;
		do
		{
			row = rand() % 20 + 3;	// 从没在最上面和最下面见过道具出现，所以应该是不会出现的 
			col = rand() % 24 + 1;
		} while (isCollidePlayer()); // 道具不会一出现就直接被吃掉 
		this->setPosition(getPos(row, col));
		this->runAction(RepeatForever::create(Blink ::create(0.3f, 1)));
		this->scheduleUpdate();

		AudioM::play2d(A_SHOW_BONUS);

		bRet = true;
	} while (false);
	return bRet;
}

void Bonus::update(float dt)
{
	if (isCollidePlayer())
	{
		switch (_type)
		{
		case kTank:
			/* 由于达到一定分数也会加一条命，所以该音效写在addLife里 */
			GameScene::getTankM()->getPlayerTank()->addLife();
			break;
		case kTimer:
			AudioM::play2d(A_AWARD);
			GameScene::getTankM()->setHaltEnemy();
			break;
		case kShovel:
			AudioM::play2d(A_AWARD);
			GameScene::getStage()->setShovel();
			break; 
		case kBomb:
			AudioM::play2d(A_BOMB);
			GameScene::getTankM()->killAllEnemy();
			break;
		case kStar:
			AudioM::play2d(A_AWARD);
			GameScene::getTankM()->getPlayerTank()->addLevel();
			break;
		case kHelmet:
			AudioM::play2d(A_AWARD);
			GameScene::getTankM()->getPlayerTank()->setShield();
			break;
		default:
			break;
		}
		GameScene::getStage()->addScore(_position, BONUS_SCORE);
		GameScene::getStage()->removeBonus();
	}
}

bool Bonus::isCollidePlayer()
{
	auto player = GameScene::getTankM()->getPlayerTank();
	if (player == nullptr)
	{
		return false;
	}
	auto boundingBox1 = player->getBoundingBox();
	auto boundingBox2 = this->getBoundingBox();
	/* 不使用intersectsRect，因为边缘重合的时候并不算 */
	return !(boundingBox1.getMaxX() <= boundingBox2.getMinX() ||
		boundingBox2.getMaxX() <= boundingBox1.getMinX() ||
		boundingBox1.getMaxY() <= boundingBox2.getMinY() ||
		boundingBox2.getMaxY() <= boundingBox1.getMinY());
}