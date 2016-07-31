#include "MenuScene.h"
#include "SceneM.h"
#include "Global.h"
#include "DataM.h"

MenuScene::MenuScene():
_moveOver(false),
_option(ONE_PLAYER)
{
}

MenuScene::~MenuScene()
{
}

bool MenuScene::init()
{
	bool bRet = false;
	do
	{
		_bg = Sprite::create("menu.png");
		_bg->setAnchorPoint(Vec2(0, 0));
		_bg->setPosition(Vec2(0, -SCREEN_HEIGHT));
		this->addChild(_bg);

		auto action = Sequence::create(
			MoveBy::create(5.0f, Vec2(0, SCREEN_HEIGHT)),
			CallFunc::create(CC_CALLBACK_0(MenuScene::moveOver, this)),
			nullptr);
		_bg->runAction(action);

		auto score = DataM::getInstance()->getScore();
		auto strScore = String::createWithFormat("%02d", score)->getCString();
		auto scoreLabel = LabelAtlas::create(strScore, "num1.plist");
		scoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
		scoreLabel->setPosition(Vec2(170, 425));
		_bg->addChild(scoreLabel);

		auto hightScore = DataM::getInstance()->getHighScore();
		auto strhightScore = String::createWithFormat("%02d", hightScore)->getCString();
		auto hightScoreLabel = LabelAtlas::create(strhightScore, "num1.plist");
		hightScoreLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
		hightScoreLabel->setPosition(Vec2(329, 425));
		_bg->addChild(hightScoreLabel);

		this->scheduleUpdate();

		bRet = true;
	}while(false);
	return bRet;
}

void MenuScene::update(float dt)
{
	if (g_keyStart)
	{
		g_keyStart = false;
		if (_moveOver)
		{
			switch (_option)
			{
			case ONE_PLAYER:
				this->removeAllChildren();
				DataM::getInstance()->init();
				SceneM::getInstance()->changeScene(kLevelScene, kTransitionExB);
				break;
			case TWO_PLAYERS:
				/* 未实现该选项功能 */
				break;
			case CONSTRUCTION:
				/* 未实现该选项功能 */
				break;
			default:
				break;
			}
			
		}
		else  // 菜单移动中点击开始按键会直接移动完毕 
		{
			_bg->stopAllActions();
			_bg->setPosition(Vec2(0, 0));
			this->moveOver();
		}
	}

	if (g_keySelect)
	{
		g_keySelect = false;
		if (_moveOver)
		{
			_option++;
			if (_option > 2)
			{
				_option = 0;
			}
			this->setOption(_option);
		}
	}
}

void MenuScene::moveOver()
{
	_moveOver = true;
	
	_tank = Sprite::createWithSpriteFrameName("player1_1_2_1.png");
	this->addChild(_tank);
	this->setOption(ONE_PLAYER);

	Vector<SpriteFrame*> animFrames(2);
	auto cache = SpriteFrameCache::getInstance();
    for (auto i = 1; i < 3; i++) 
    {
		auto str = String::createWithFormat("player1_1_2_%d.png", i)->getCString();
        auto frame = cache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.01f);
    _tank->runAction(RepeatForever::create(Animate::create(animation)));
}

void MenuScene::setOption(int option)
{
	_option = option;
	auto x = 145.0f;
	auto y = 202.0f - option * 32.0f;
	_tank->setPosition(Vec2(x, y));
}