#ifndef __TANK_M_H__
#define __TANK_M_H__

#include "cocos2d.h"
#include "Global.h"
#include "PlayerTank.h"
#include "EnemyTank.h"

USING_NS_CC;
using namespace std;

/* 坦克管理类 */
class TankM : public Layer
{
public:
	TankM();
	~TankM();
	CREATE_FUNC(TankM);
	bool init();
	/* 获取玩家坦克 */
	PlayerTank* getPlayerTank(){return _playerTank;}
	/* 获取敌人坦克 */
	Vector<EnemyTank*>& getEnemyTanks(){return _enemyTanks;}
	/* 获取所有坦克 */
	Vector<Tank*>& getAllTanks(){return _tanks;}
	/* 删除坦克 */
	void removeTank(Tank* tank, bool addScore = false);
	/* 获取各种敌人坦克的杀敌数 */
	int *getkillEnemyNum() { return _killEnemyNum; }
	/* 玩家坦克爆炸后 */
	void playerBombEnd();
	/* 关卡失败 */
	void fail();
	/* 杀死所有敌人坦克 */
	void killAllEnemy();
	/* 定住所有敌人坦克 */
	void setHaltEnemy();
	/* 敌人坦克是否处于定住中 */
	bool isHaltEnemy(){ return _halt; }
	/* 暂停游戏 */
	void pauseGame();
	/* 继续游戏 */
	void resumeGame();
	/* 播放敌人坦克行走音效 */
	void playEnemyMoveAudio();
	/* 停止敌人坦克行走音效 */
	void stopEnemyMoveAudio();

private:
	/* 定时器回调（出现新的敌人坦克） */
	void timer(float dt);
	/* 创建坦克出现前的闪光点 */
	Sprite* createBore(const function<void(Node*)>  callback);
	/* 创建新的玩家坦克 */
	void createNewPlayer();
	/* 创建新的敌人坦克 */
	void createNewEnemy();
	/* 开场音效结束 */
	void startAudioEnd(Ref* obj);

	int _pos;								// 敌人坦克出现的位置 
	bool _allAppear;						// 敌人坦克是否全部出现 
	PlayerTank* _playerTank;				// 玩家坦克 
	Vector<EnemyTank*> _enemyTanks;			// 敌人坦克 
	Vector<Tank*> _tanks;					// 所有坦克 
	int _killEnemyNum[5];					// 打倒的各类型坦克的数量(道具炸死的不算，4是所有数量) 
	bool _halt;								// 敌人坦克是否定住中 
	int _enemyMoveAudioId;					// 敌人坦克行走音效 
};
#endif