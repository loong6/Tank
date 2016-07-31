#ifndef __BONUS_H__
#define __BONUS_H__

#include "cocos2d.h"

USING_NS_CC;

enum BonusType		// 奖励道具类型 
{
	kTank = 1,		// 坦克（增加一条命） 
	kTimer,			// 定时器（敌人定身） 
	kShovel,		// 头盔（无敌） 
	kBomb,			// 炸弹（消灭现有敌人） 
	kStar,			// 星星（玩家坦克等级+1） 
	kHelmet			// 铲子（大本营外围变铁） 
};

/* 奖励道具 */
class Bonus : public Sprite
{
public:
	Bonus();
	~Bonus();
	static Bonus* create(BonusType type);
	bool init(BonusType type);

private:
	void update(float dt);
	/* 是否与玩家坦克接触 */
	bool isCollidePlayer();

	BonusType _type;	// 奖励道具类型 
};

#endif