#ifndef SOUNDCLASS_H_
#define SOUNDCLASS_H_

#include <irrKlang.h>
#include "SingletonTemplate.h"
#include <string>

using namespace irrklang;

struct SoundChannel
{
	ISound* snd;
	float maxVolume;
	float currVolume;

	void setVolume(float _currVolume) {
		currVolume = _currVolume > maxVolume ? maxVolume : _currVolume;
		currVolume = _currVolume < 0.f ? 0.f : _currVolume;
		if (snd)
			snd->setVolume(currVolume);
	}
	bool playSound(ISoundEngine* engine, char* path, bool looped = false) {
		snd = engine->play2D(path, looped, false, true);
		
		if (snd)
			setVolume(currVolume);
	}
};

class SoundClass
	: public Singleton<SoundClass>
{
	friend Singleton<SoundClass>;
public:
private:
	ISoundEngine* engine;

	SoundClass();
	~SoundClass();
};

#endif // !1