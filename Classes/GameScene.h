#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Stage.h"
#include "TankM.h"
#include "BulletM.h"
#include "BombM.h"

USING_NS_CC;

enum GameState	// 游戏状态 
{
	kRuning,	// 进行中 
	kPause,		// 暂停 
	kWin,		// 胜利 
	kFail,		// 失败 
	kNone		// 无（初始值） 
};

/* 游戏场景类 */
class GameScene : public Layer
{
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
    virtual bool init();  
	virtual void onEnterTransitionDidFinish();
	/* 获取游戏状态 */
	static GameState getGameState(){ return _gameState; }
	/* 获取舞台类对象 */
	static Stage* getStage(){return _stage;}
	/* 获取坦克管理类对象 */
	static TankM* getTankM(){return _tankM;}
	/* 获取子弹管理类对象 */
	static BulletM* getBulletM(){return _bulletM;}
	/* 获取爆炸管理类对象 */
	static BombM* getBombM() { return _bombM; }
	
private:
	void update(float dt);
	/* 暂停游戏 */
	void pauseGame();
	/* 继续游戏 */
	void resumeGame();
	/* 关卡失败 */
	void fail(Ref* obj);
	/* 关卡胜利 */
	void win(Ref* obj);

	static GameState _gameState;	// 游戏状态 
	static Stage *_stage;			// 舞台类对象 
	static TankM* _tankM;			// 坦克管理类对象 
	static BulletM* _bulletM;		// 子弹管理类对象 
	static BombM* _bombM;			// 爆炸管理类对象 
};

#endif