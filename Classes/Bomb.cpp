#include "Bomb.h"
#include <string>
#include "GameScene.h"

using namespace std;

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

Bomb* Bomb::create(BombType type, int score)
{
	Bomb *pRet = new Bomb();
	if (pRet && pRet->init(type, score))
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

bool Bomb::init(BombType type, int score)
{
	bool bRet = false;
	do
	{
		_type = type;
		_score = score;
		string name;
		int size;
		switch (_type)
		{
		case kPlayerTankBomb:
		case kEnemyTankBomb:
		case kStrongholdBomb:
			name = "tankbomb";
			size = 7;
			break;
		case kBulletBomb:
			name = "bulletbomb";
			size = 3;
			break;
		default:
			break;
		}
		auto str = String::createWithFormat("%s_01.png", name.c_str())->getCString();
		this->initWithSpriteFrameName(str);

		Vector<SpriteFrame*> animFrames(size);
		auto cache = SpriteFrameCache::getInstance();

		for (auto i = 1; i < size + 1; i++)
		{
			auto str = String::createWithFormat("%s_%02d.png", name.c_str(), i)->getCString();
			auto frame = cache->getSpriteFrameByName(str);
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.08f);
		auto action = Sequence::create(
			Animate::create(animation), 
			RemoveSelf::create(), 
			CallFuncN::create(CC_CALLBACK_1(Bomb::bombEnd, this)),
			nullptr);
		this->runAction(action);
		 
		bRet = true;
	} while (false);
	return bRet;
}

void Bomb::bombEnd(Node* sender)
{
	if (_type == kEnemyTankBomb)
	{
		if (_score > 0)
		{
			GameScene::getStage()->addScore(_position, _score);
		}
	}
	else if (_type == kPlayerTankBomb)
	{
		GameScene::getTankM()->playerBombEnd();
	}
	else if (_type == kStrongholdBomb)
	{
		NotificationCenter::getInstance()->postNotification("game_fail");
	}
}