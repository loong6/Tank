#ifndef __AUDIO_M_H__
#define __AUDIO_M_H__

#include "cocos2d.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;

/*******************************************************************
 所有平台都支持的格式好像只有mp3，但是mp3精度低，循环音效会断断续续。 
 Windows不支持wav，iOS不支持ogg，Android使用wav有的机子音效循环无效，
 所以两个循环的音效在iOS下使用wav，在Android和Windows下使用ogg，其余
 音效则都采用mp3。目前这样，有的机子音效还是有问题，例如声音失真、有
 的音效有时出不来之类的，如果你手机上音效有异样，都是AudioEngine的错。
 *******************************************************************/
const auto A_ADD_LIFE = "addlife.mp3";				// 增加玩家坦克生命的音效 
const auto A_AWARD = "award.mp3";					// 吃到道具的音效 
const auto A_BOMB = "bomb.mp3";						// 吃到爆炸道具的音效 
const auto A_BULLET = "bullet.mp3";					// 发射子弹的音效 
const auto A_COUNT = "count.mp3";					// 分数表数字变化时的音效 
const auto A_ENEMY_BOMB = "enemybomb.mp3";			// 敌人坦克爆炸的音效 
const auto A_GAME_OVER = "gameover.mp3";			// 游戏结束的音效 
const auto A_HIT_OBSTACLE = "hitobstacle.mp3";		// 打到铁上且打不破时的音效 
const auto A_METAL = "metal.mp3";					// 打到敌人坦克（打多次才能死的那只）时的音效 
const auto A_OBSTACLE_BOMB = "obstaclebomb.mp3";	// 打破砖或铁时的音效 
const auto A_PAUSE = "pause.mp3";					// 游戏暂停的音效 
const auto A_PLAYER_BOMB = "playerbomb.mp3";		// 玩家坦克和大本营爆炸的音效 
const auto A_SHOW_BONUS = "showbonus.mp3";			// 显示道具时的音效 
const auto A_SLIP = "slip.mp3";						// 冰上滑动的音效 
const auto A_START = "start.mp3";					// 关卡开始时的音效 
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
const auto A_ENEMY_MOVE = "enemymove.wav";			// 敌人坦克移动的音效（其实应该算是游戏背景音效吧，我姑且就这么叫吧） 
const auto A_PLAYER_MOVE = "playermove.wav";		// 玩家坦克移动的音效 
#else
const auto A_ENEMY_MOVE = "enemymove.ogg";		
const auto A_PLAYER_MOVE = "playermove.ogg";
#endif

/* 声音管理类 */
class AudioM : public AudioEngine
{
public:
	/* 预加载声音 */
	static void preloadAllAudio();
	/* 重写父类play2d函数，添加游戏自己的逻辑 */
	static int play2d(const std::string& filePath, bool loop = false, float volume = 1.0f, const AudioProfile *profile = nullptr);

private:
	static bool _startAudioPlaying;		// 关卡开场音效是否播放中 
};

#endif