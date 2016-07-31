#ifndef __BOMB_H__
#define __BOMB_H__

#include "cocos2d.h"

USING_NS_CC;

enum BombType			// 爆炸类型 
{
	kPlayerTankBomb,	// 玩家坦克爆炸 
	kEnemyTankBomb,		// 敌人坦克爆炸 
	kStrongholdBomb,	// 大本营爆炸 
	kBulletBomb			// 子弹爆炸 
};

/* 爆炸类 */
class Bomb : public Sprite
{
public:
	Bomb();
	~Bomb();
	/**
	* 创建爆炸 
	* type 爆炸类型 
	* score 爆炸后显示的分数 
	*/
	static Bomb* create(BombType type, int score);
	virtual bool init(BombType type, int score);

private:
	/* 爆炸动画结束后的回调 */
	void bombEnd(Node* sender);

	BombType _type;		// 爆炸类型 
	int _score;			// 敌人坦克爆炸后显示的分数 
};

#endif

