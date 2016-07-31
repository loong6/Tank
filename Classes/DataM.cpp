#include "DataM.h"
#include "Global.h"
#include "GameScene.h"

static DataM *s_SharedDataM = nullptr;

DataM::DataM() :
_levelId(1),
_highScore(20000),
_score(0),
_playerLife(PLAYER_LIFE),
_playerLevel(PLAYER_INIT_LEVEL)
{
}

DataM::~DataM()
{
}

DataM* DataM::getInstance()
{
	if (!s_SharedDataM)
	{
		s_SharedDataM = new (std::nothrow) DataM();
		CCASSERT(s_SharedDataM, "FATAL: Not enough memory");
		s_SharedDataM->init();
	}

	return s_SharedDataM;
}

bool DataM::init()
{
	bool bRet = false;
	do
	{
		_selectLevelEnable = true;
		_score = 0;
		_levelId = 1;
		_playerLife = PLAYER_LIFE;
		_playerLevel = PLAYER_INIT_LEVEL;

		while (!_addLifeScore.empty())_addLifeScore.pop();
		for (auto score : ADD_LIFE_SCORE)
		{
			_addLifeScore.push(score);
		}

		bRet = true;
	} while (false);
	return bRet;
}

void DataM::addScore(int score)
{
	_score += score;
	if (!_addLifeScore.empty() && _score >= _addLifeScore.top())
	{
		_addLifeScore.pop();
		GameScene::getTankM()->getPlayerTank()->addLife();
	}
}