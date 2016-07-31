#ifndef __STAGE_H__
#define __STAGE_H__

#include "Bonus.h"
#include "Global.h"
#include "Score.h"
#include "cocos2d.h"

USING_NS_CC;

enum        // 地图元素类型 
{
	LAND,	// 地 
	BRICK,	// 砖 
	GRID,   // 铁 
	GRASS,  // 草 
	WATER,  // 水 
	ICE,    // 冰 
	HOME1,  // 大本营（损坏）其余三角 
	HOME2,  // 大本营（损坏）左上角 
	HOME3,  // 大本营（完好）其余三角 
	HOME4   // 大本营（完好）左上角 
};

/* 舞台类（地图以及右边的信息） */
class Stage : public LayerColor
{
public:
	Stage();
	~Stage();
	CREATE_FUNC(Stage);
    virtual bool init(); 
	/* 获取地图背景 */
	LayerColor* getBG(){return _bg;}
	/* 初始化信息 */
	void initInfo();
	/* 获取地图元素的二维数组 */
	void getMap(int(*&map)[MAP_COL]){ map = _map; }
	/* 是否可打 */
	bool isCanHit(int row, int col);
	/* 是否可行走 */
	bool isCanWalk(int row, int col);
	/* 是否在冰上 */
	bool isOnIce(Vec2 pos);
	/* 更新剩余敌人坦克数量 */
	void updateEnemyNum();
	/* 获取当前出现的敌人坦克的类型 */
	int getEnemyType() { return _type[_enemyID++]; }
	/* 获取当前出现的敌人坦克的id */
	int getCurEnemyId() { return _enemyID; }
	/* 更新地图元素 */
	void updateMapCell(int row, int col);
	/* 更新玩家坦克剩余生命数 */
	void updatePlayerLife(int life);
	/* 创建奖励道具 */
	void createBonus(BonusType type);
	/* 删除奖励道具 */
	void removeBonus();
	/* 显示获得的分数 */
	void addScore(Vec2 pos, int score);
	/* 关卡失败 */
	void fail();
	/* 关卡胜利 */
	void win();
	/* 暂停游戏 */
	void pauseGame();
	/* 继续游戏 */
	void resumeGame();
	/* 设置“铲子”道具效果 */
	void setShovel();

private:
	/* 初始化地图 */
	void initMap();
	/* 创建地图元素 */
	void createMapCell(int row, int col, int newType);
	/* 设置大本营外围的类型 */
	void setHomeWall(int type);
	/* 获取地图元素类型所对应的精灵图片的名字 */
	string getSpriteName(int type);

	int _id;						// 地图id（第一关id为1） 
	int _enemyID;					// 敌人坦克id（第一个出现的敌人坦克id为0） 
	int _map[MAP_ROW][MAP_COL];		// 地图数组 
	int _type[ENEMY_NUM];			// 敌人坦克类型 
	int _shovelStep;				// “铲子”道具的定时器回调次数（用于快到时间的闪烁） 
	Score* _score;					// 关卡结束的分数表 
	LayerColor* _bg;				// 地图的黑色背景 
	Vector<Sprite*> _enemyIcons;	// 敌人坦克剩余数量的图标 
	LabelAtlas* _level;				// 第几关的标签 
	LabelAtlas* _life;				// 玩家坦克剩余数量的标签 
	Bonus* _bonus;					// 道具 
	Sprite* _pause;					// 暂停图片 
};

#endif