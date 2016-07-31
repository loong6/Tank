#include "Stage.h"
#include "GameScene.h"
#include "DataM.h"
#include "SceneM.h"
#include <sstream>
#include <string>

using namespace std;

Stage::Stage():
_enemyID(0),
_shovelStep(0),
_bonus(nullptr)
{
}

Stage::~Stage()
{
}

bool Stage::init()
{
	bool bRet = false;
	do
	{
		LayerColor::initWithColor(Color4B(126, 126, 126, 255));

		_id = DataM::getInstance()->getLevelId();

		auto size = Size(MAP_WIDTH, MAP_HEIGHT);
		_bg = LayerColor::create(Color4B(0, 0, 0, 255));
		_bg->setContentSize(size);
		_bg->setPosition(Vec2(32, (SCREEN_HEIGHT - size.height)/2));
		this->addChild(_bg);

		this->initMap();

		bRet = true;
	}while(false);
	return bRet;
}

void Stage::initInfo()
{
	auto flag = Sprite::create("flag.png");
	flag->setPosition(Vec2(480, 96));
	this->addChild(flag);

	auto levelId = DataM::getInstance()->getLevelId();
	_level = LabelAtlas::create(String::createWithFormat("%d", levelId)->getCString(), "num1.plist");
	_level->setColor(Color3B::BLACK);
	_level->setAnchorPoint(Vec2(1.0f, 0.5f));
	_level->setPosition(Vec2(496, 74));
	this->addChild(_level);

	auto p1 = Sprite::create("p1.png");
	p1->setPosition(Vec2(482, 202));
	this->addChild(p1);

	auto playericon = Sprite::create("playericon.png");
	playericon->setPosition(Vec2(473, 184));
	this->addChild(playericon);

	auto lifeNum = DataM::getInstance()->getPlayerLife();
	_life = LabelAtlas::create(String::createWithFormat("%d", lifeNum - 1)->getCString(), "num1.plist");
	_life->setColor(Color3B::BLACK);
	_life->setAnchorPoint(Vec2(0.0f, 0.5f));
	_life->setPosition(Vec2(482, 184));
	this->addChild(_life);
	for (auto i = 0; i < ENEMY_NUM; i++) 
	{
		auto x = 473 + i % 2 * 16;
		auto y = 424 - i / 2 * 16;
		auto enemyicon = Sprite::create("enemyicon.png");
		enemyicon->setPosition(Vec2(x, y));
		this->addChild(enemyicon, 0, ENEMY_NUM - 1 - i);
	}
}

void Stage::initMap()
{
	/* 本来打算用fstream读取文件的，但是在Android读取不了，故采取以下方法 */
	stringstream file1;
	auto id = (_id - 1) % LEVEL_NUM + 1; // 最后一关之后，地图从第一关开始 
	auto name = String::createWithFormat("map%d.txt", id)->getCString();
	auto data = FileUtils::getInstance()->getStringFromFile(name);
	file1.str(data);
	for (auto i = 0; i < MAP_ROW; i++)
	{
		for (auto j = 0; j < MAP_COL; j++)
		{
			file1 >> _map[i][j];
			if(_map[i][j] == BRICK)
			{
				_map[i][j] |= 0xf0;		// 设置该砖块为完整的砖块 
			}
			this->createMapCell(i, j, _map[i][j]);
		}
	}
	stringstream file2;
	id = _id > LEVEL_NUM ? LEVEL_NUM : _id; // 最后一关之后，敌人坦克类型与最后一关一样 
	name = String::createWithFormat("enemy%d.txt", id)->getCString();
	data = FileUtils::getInstance()->getStringFromFile(name);
	file2.str(data);
	for (auto i = 0; i < ENEMY_NUM; ++i)
	{
		file2 >> _type[i];
	}
}

void Stage::createMapCell(int row, int col, int type)
{
	Sprite* cell = NULL;
	auto zorder = 1;
	if (type == WATER)
	{
		cell = Sprite::createWithSpriteFrameName("water_01.png");
		cell->setName("water");
		Vector<SpriteFrame*> animFrames(2);
		auto cache = SpriteFrameCache::getInstance();
		for (auto i = 1; i < 3; i++) 
		{
			auto name = String::createWithFormat("water_%02d.png", i)->getCString();
			auto frame = cache->getSpriteFrameByName(name);
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
		cell->runAction(RepeatForever::create(Animate::create(animation)));
	}
	else
	{
		auto name = this->getSpriteName(type);
		if (type == GRASS)
		{
			zorder = 3;		// 草在坦克上方，所以要修改渲染层级 
		}
		if (name != "")
		{
			cell = Sprite::create(name);
		}
	}
	if (cell)
	{
		auto tag = row*100 + col;
		cell->setAnchorPoint(Vec2(0.0f, 1.0f));
		cell->setPosition(getPos(row, col));
		_bg->addChild(cell, zorder, tag);
	}
}

string Stage::getSpriteName(int type)
{
	string name;
	switch (type & 0x0f)
	{
	case BRICK:
		name = "brick.png";
		break;
	case GRID:
		name = "grid.png";
		break;
	case GRASS:
		name = "grass.png";
		break;
	case ICE:
		name = "ice.png";
		break;
	case HOME2:
		name = "home2.png";
		break;
	case HOME4:
		name = "home1.png";
		break;
	default:
		break;
	}
	return name;
}

void Stage::updateMapCell(int row, int col)
{
	auto type = _map[row][col];
	auto tag = row*100 + col;
	auto cell = (Sprite*)_bg->getChildByTag(tag);
	if (type == LAND)
	{ 
		if (cell)
		{
			cell->removeFromParent();
		}
	}
	else if ((type & 0x0f) == BRICK && (type & 0xf0) != 0xf0) // 残缺的砖块 
	{
		auto left = 0, right = CELL_WIDTH, bottom = 0, top = CELL_HEIGHT;
		auto pos = getPos(row, col);
		if ((type & 0x30) == 0) // 下边为空 
		{
			top -= CELL_HEIGHT / 2;
		}
		if ((type & 0xc0) == 0) // 上边为空 
		{
			bottom += CELL_HEIGHT / 2;
			pos.y -= bottom;
		}
		if ((type & 0x50) == 0) // 右边为空 
		{
			right -= CELL_WIDTH / 2;
		}
		if ((type & 0xa0) == 0) // 左边为空 
		{
			left += CELL_WIDTH / 2;
			pos.x += left;
		}
		cell->setTextureRect(Rect(left, bottom, right - left, top - bottom));
		cell->setPosition(pos); // 锚点为左上角，当左边或上边为空时需要改变坐标 
	}
	else
	{
		if (cell)
		{
			cell->setTexture(getSpriteName(type));
			cell->setPosition(getPos(row, col));
		}
		else
		{
			this->createMapCell(row, col, type);
		}
	}
}

bool Stage::isCanHit(int row, int col)
{
	if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_COL)
		return false;
	switch (_map[row][col] & 0x0f)
	{
	case BRICK:
	case GRID:
	case HOME3:
	case HOME4:
		return true;
	default:
		return false;
	}
}

bool Stage::isCanWalk(int row, int col)
{
	if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_COL)
		return false;
	switch (_map[row][col] & 0x0f)
	{
	case ICE:
	case LAND:
	case GRASS:
		return true;
	default:
		return false;
	}
}

bool Stage::isOnIce(Vec2 pos)
{
	auto col = (int)(pos.x / CELL_WIDTH);
	auto row  = (int)(MAP_ROW - pos.y / CELL_HEIGHT);
	if (_map[row][col] == ICE)
		return true;
	return false;
}
void Stage::updateEnemyNum()
{
	this->removeChildByTag(_enemyID);
}

void Stage::updatePlayerLife(int life)
{
	_life->setString(String::createWithFormat("%d", life - 1)->getCString());
}

void Stage::createBonus(BonusType type)
{
	if (_bonus)
	{
		_bonus->removeFromParent();
	}
	_bonus = Bonus::create(type);
	_bg->addChild(_bonus, 5);
}

void Stage::removeBonus()
{
	if (_bonus)
	{
		_bonus->removeFromParent();
		_bonus = nullptr;
	}
}

void Stage::addScore(Vec2 pos, int score)
{
	DataM::getInstance()->addScore(score);
	auto scoreLabel = LabelAtlas::create(String::createWithFormat("%d", score)->getCString(), "num2.plist");
	scoreLabel->setName("score");
	scoreLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
	scoreLabel->setPosition(pos);
	scoreLabel->runAction(Sequence::create(DelayTime::create(0.5f), RemoveSelf::create(), nullptr));
	_bg->addChild(scoreLabel, 4);
}

void Stage::fail()
{
	auto gameOver = Sprite::create("sgameover.png");
	gameOver->setPosition(Vec2(MAP_WIDTH / 2 + 32, -15));
	this->addChild(gameOver);
	auto action = Sequence::create(MoveTo::create(2.0f, Vec2(MAP_WIDTH / 2 + 32, SCREEN_CY)),
		DelayTime::create(0.5f),
		CallFunc::create([&]() {
			_score = Score::create();
			_score->setCallBack([]() {
				SceneM::getInstance()->changeScene(kGameOverScene);
			});
			this->addChild(_score, 1);
			GameScene::getBulletM()->removeFromParent();
			this->removeBonus();
			GameScene::getTankM()->removeFromParent();
		}),
		RemoveSelf::create(),
		nullptr);
	gameOver->runAction(action);
}

void Stage::win()
{
	this->scheduleOnce([&](float dt) {
		_score = Score::create();
		_score->setCallBack([=]() {
			_score->removeFromParent();
			SceneM::getInstance()->changeScene(kLevelScene, kTransitionExB);
		});
		this->addChild(_score, 1);
		DataM::getInstance()->nextLevel();
		this->removeBonus();
		GameScene::getBulletM()->removeFromParent();
		GameScene::getTankM()->removeFromParent();
	}, 2.0f, "delay");
}

void Stage::pauseGame()
{
	_pause = Sprite::create("pause.png");
	_pause->setPosition(Vec2(MAP_WIDTH / 2 + 32, SCREEN_CY));
	_pause->runAction(RepeatForever::create(Blink::create(0.5f, 1)));
	this->addChild(_pause);

	for (auto node : _bg->getChildren())
	{
		string name = node->getName();
		if (name == "score" || name == "water")
		{
			node->pause();
		}
	}
}

void Stage::resumeGame()
{
	_pause->removeFromParent();

	for (auto node : _bg->getChildren())
	{
		auto name = node->getName();
		if (name == "score" || name == "water")
		{
			node->resume();
		}
	}
}

void Stage::setShovel()
{
	_shovelStep = 0;
	this->setHomeWall(GRID);
	this->unschedule("shovel");
	this->schedule([&](float dt) {
		/* 快到时间的闪烁 */
		if (_shovelStep % 2 == 0)
		{
			this->setHomeWall(BRICK | 0xf0);
		}
		else
		{
			this->setHomeWall(GRID);
		}
		_shovelStep++;
	}, 0.23f, 14, 17.0f, "shovel");
}

void Stage::setHomeWall(int newType)
{
	for (auto row = 23; row <= 25; row++)
	{
		for (auto col = 11; col <= 14; col++)
		{
			auto &type = _map[row][col];
			if ((type & 0x0f) < HOME1) // 判断是否为大本营外围的墙（为了把大本营排除掉） 
			{
				type = newType;
				updateMapCell(row, col);
			}
		}
	}
}