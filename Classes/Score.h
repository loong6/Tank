#ifndef __SCORE_H__
#define __SCORE_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/* 分数表（关卡结束后的分数统计）类 */
class Score : public Layer
{
public:
	Score();
	~Score();
	CREATE_FUNC(Score);
	virtual bool init();
	/* 分数统计结束后的回调 */
	void setCallBack(const function<void()>  callback) { _callback = callback; }

private:
	/* 统计 */
	void count(float dt);

	int _step;							// 统计的步数（逐步统计的） 
	int _countNum;						// 坦克数 
	int _countScore;					// 分数 
	int _killEnemyNum[5];				// 打倒的每种坦克的数量 
	LabelAtlas* _numLabel;				// 坦克数标签 
	LabelAtlas* _scoreLabel;			// 分数标签 
	function<void()>  _callback;		// 统计完毕的回调函数 
};

#endif