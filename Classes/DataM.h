#ifndef __DATA_M_H__
#define __DATA_M_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/* 数据管理类 */
class DataM : public Ref
{
public:
	DataM();
	~DataM();
	static DataM* getInstance();
	bool init();

	/* 是否可选择关卡 */
	bool isSelectLevelEnable() { return _selectLevelEnable; }
	/* 设置是否可选择关卡 */
	void setSelectLevelEnable(bool value) { _selectLevelEnable = value; }

	/* 获取关卡id */
	int getLevelId() { return _levelId; }
	/* 设置关卡id */
	void setLevelId(int id) { _levelId = id; }
	/* 下一关（即关卡id+1） */
	void nextLevel() { _levelId++; }
	
	/* 获取玩家坦克生命 */
	int getPlayerLife() { return _playerLife; }
	/* 设置玩家坦克生命 */
	void setPlayerLife(int life) { _playerLife = life; }

	/* 获取玩家坦克等级 */
	int getPlayerLevel() { return _playerLevel; }
	/* 设置玩家坦克等级 */
	void setPlayerLevel(int level) { _playerLevel = level; }

	/* 获取最高分 */
	int getHighScore() { return _highScore; }
	/* 更新最高分（游戏结束的时候） */
	void updateHighScore() { if (_score > _highScore)_highScore = _score; }
	/* 获取分数 */
	int getScore() { return _score; }
	/* 增加分数 */
	void addScore(int score);

private:
	bool _selectLevelEnable;	// 是否可选择关卡 
	int _levelId;				// 关卡id 
	int _playerLife;			// 玩家坦克生命 
	int _playerLevel;			// 玩家坦克等级 
	int _score;					// 分数 
	int _highScore;				// 最高分 
	stack<int> _addLifeScore;	// 增加生命的分数（即超过该分加一条命，可能有多个分数） 
};

#endif
