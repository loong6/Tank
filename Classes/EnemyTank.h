#ifndef __ENEMY_TANK_H__
#define __ENEMY_TANK_H__

#include "Tank.h"

/* 敌人坦克类 */
class EnemyTank : public Tank
{
public:
	EnemyTank();
	~EnemyTank();
	static EnemyTank* create(int type, Vec2 pos);
	bool init(int type, Vec2 pos);
	/* 被子弹打到 */
	virtual void hit();
	/* 死亡 */
	void die();
	/* 设置该坦克有道具奖励 */
	void setBonus();
	/* 取消该坦克的道具奖励 */
	void cancelBonus();

private:
	void update(float dt);

	bool _addScore;		// 是否加分（被道具炸死的不加分） 
	bool _bonus;		// 是否有道具奖励 
	int _bonusStep;	    // 带奖励的坦克的帧数 
};

#endif
