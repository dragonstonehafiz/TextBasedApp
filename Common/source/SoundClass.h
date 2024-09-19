#ifndef SOUNDCLASS_H_
#define SOUNDCLASS_H_

#include <irrKlang.h>
#include <string>
#include <map>
#include "SingletonTemplate.h"

using namespace irrklang;

struct SoundChannel
{
	ISound* snd;
	float volCurr;

	SoundChannel() : volCurr(1.f), snd(nullptr) {};

	void setVolume(float _volCurr) {
		volCurr = _volCurr > 1.f ? 1.f : _volCurr;
		volCurr = _volCurr < 0.f ? 0.f : _volCurr;
		if (snd)
			snd->setVolume(volCurr);
	}
	bool playSound(ISoundEngine* engine, std::string path, bool looped = false) {
		snd = engine->play2D(path.c_str(), looped, false, true);
		
		if (snd)
			setVolume(volCurr);
		return true;
	}
};

class SoundClass :
	public ISoundStopEventReceiver,
	public Singleton<SoundClass>
{
	friend Singleton<SoundClass>;
public:
	void init();

	bool createChannel(const std::string& key);
	bool hasChannel(const std::string& key);

	bool addSound(const std::string& key, const std::string& path);
	bool hasSound(const std::string& key);
	bool removeSound(const std::string& key);
	bool playSound(const std::string& channel, const std::string& key, const bool& looped = true);

	void setVolume(const std::string& channel, const float& _volCurr);
	float getVolume(const std::string& channel);

	/// <summary>
	/// Removes hanging pointers when irrKlang cleans up finished audio files
	/// </summary>
	void OnSoundStopped(ISound* sound, E_STOP_EVENT_CAUSE reason, void* userData) override;
private:
	ISoundEngine* engine = nullptr;
	std::map<std::string, SoundChannel> channel_map;
	std::map<std::string, std::string> path_map;


	~SoundClass();
};

#endif // !1