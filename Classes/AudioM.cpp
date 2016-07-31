#include "AudioM.h"

bool AudioM::_startAudioPlaying = false;

void AudioM::preloadAllAudio()
{
	const char* audio[] = { A_ADD_LIFE, A_AWARD, A_BOMB, A_BULLET, A_COUNT, A_ENEMY_BOMB, A_ENEMY_MOVE, A_GAME_OVER, A_HIT_OBSTACLE, 
		A_METAL, A_OBSTACLE_BOMB, A_PAUSE, A_PLAYER_BOMB, A_PLAYER_MOVE, A_SHOW_BONUS, A_SLIP, A_START };
	for (auto name : audio)
	{
		AudioEngine::preload(name);
	}
}

int AudioM::play2d(const std::string& filePath, bool loop, float volume, const AudioProfile *profile)
{
	/* 关卡开场音效期间，除了爆炸和暂停音效除外，其余音效均不播放 */
	if (_startAudioPlaying == true && filePath != A_PAUSE && filePath != A_ENEMY_BOMB && filePath != A_PLAYER_BOMB) return INVALID_AUDIO_ID;
	auto audioID = AudioEngine::play2d(filePath, loop, volume, profile);
	if (filePath == A_START)
	{
		_startAudioPlaying = true;
		AudioM::setFinishCallback(audioID, [&](int id, const std::string& filePath){
			_startAudioPlaying = false;
			NotificationCenter::getInstance()->postNotification("start_audio_end");
		});
	}
	return audioID;
}