#include "BombM.h"
#include "Global.h"
#include "GameScene.h"

BombM::BombM()
{
}

BombM::~BombM()
{
}

void BombM::createBomb(BombType type, Vec2 pos, int score)
{
	auto bomb = Bomb::create(type, score);
	bomb->setPosition(pos);
	this->addChild(bomb, 1);
}

void BombM::pauseGame()
{
	for (auto bomb : getChildren())
	{
		bomb->pause();
	}
}

void BombM::resumeGame()
{
	for (auto bomb : getChildren())
	{
		bomb->resume();
	}
}