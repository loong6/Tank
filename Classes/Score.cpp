#include "Score.h"
#include "DataM.h"
#include "SceneM.h"
#include "Global.h"
#include "GameScene.h"
#include "AudioM.h"

Score::Score():
_step(0),
_countNum(0),
_countScore(0),
_callback(nullptr)
{
}

Score::~Score()
{
}

bool Score::init()
{
	bool bRet = false;
	do
	{
		AudioM::stopAll();

		auto bg = Sprite::create("score.png");
		bg->setAnchorPoint(Vec2(0.0f, 0.0f));
		this->addChild(bg);

		auto highScore = DataM::getInstance()->getHighScore();
		auto highScoreLabel = LabelAtlas::create(String::createWithFormat("%d", highScore)->getCString(), "num1.plist");
		highScoreLabel->setColor(Color3B(255, 160, 0));
		highScoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
		highScoreLabel->setPosition(Vec2(384, 425));
		this->addChild(highScoreLabel);

		auto score = DataM::getInstance()->getScore();
		auto scoreLabel = LabelAtlas::create(String::createWithFormat("%d", score)->getCString(), "num1.plist");
		scoreLabel->setColor(Color3B(255, 160, 0));
		scoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
		scoreLabel->setPosition(Vec2(176, 329));
		this->addChild(scoreLabel);

		auto levelId = DataM::getInstance()->getLevelId();
		auto levelLabel = LabelAtlas::create(String::createWithFormat("%d", levelId)->getCString(), "num1.plist");
		levelLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
		levelLabel->setPosition(Vec2(320, 393));
		this->addChild(levelLabel);

		memcpy(_killEnemyNum, GameScene::getTankM()->getkillEnemyNum(), sizeof(_killEnemyNum));
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(Score::count), 0.5f);

		bRet = true;
	} while (false);
	return bRet;
}

void Score::count(float dt)
{
	if (_step < 4)
	{
		if (_countNum == 0)
		{
			_numLabel = LabelAtlas::create("0", "num1.plist");
			_numLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
			_numLabel->setPosition(Vec2(224, 281 - _step * 48));
			this->addChild(_numLabel);

			_scoreLabel = LabelAtlas::create("0", "num1.plist");
			_scoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
			_scoreLabel->setPosition(Vec2(112, 281 - _step * 48));
			this->addChild(_scoreLabel);

			this->schedule([&](float dt) {
				if (_countNum == _killEnemyNum[_step])
				{
					_countNum = 0;
					_step++;
					this->unschedule("count2");
					this->scheduleOnce(CC_SCHEDULE_SELECTOR(Score::count), 0.4f);
				}
				else
				{
					_countNum++;
					_numLabel->setString(String::createWithFormat("%d", _countNum)->getCString());
					_scoreLabel->setString(String::createWithFormat("%d", _countNum * ENEMY_SCORE[_step])->getCString());
					AudioM::play2d(A_COUNT);
				}
			}, 0.2f, "count2");
		}
	}
	else if (_step == 4)
	{
		_numLabel = LabelAtlas::create(String::createWithFormat("%d", _killEnemyNum[4])->getCString(), "num1.plist");
		_numLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
		_numLabel->setPosition(Vec2(224, 105));
		this->addChild(_numLabel);
		this->scheduleOnce([&](float dt) {
			if (_callback)
			{
				_callback();
			}
		}, 1.0f, "delay");
	}
}