#include "SoundClass.h"
#include <string>
#include <filesystem>

SoundClass::~SoundClass()
{
	engine->drop();
	engine = nullptr;
}

void SoundClass::init()
{
	if (engine == nullptr)
		engine = createIrrKlangDevice();
}

bool SoundClass::createChannel(const std::string& key)
{
	if (hasChannel(key))
		return false;

	channel_map[key] = SoundChannel();
	return true;
}
bool SoundClass::hasChannel(const std::string& key)
{
	return channel_map.count(key) > 0;
}

bool SoundClass::addSound(const std::string& key, const std::string& path)
{
	// Don't add the sound if there is already a sound using that key
	// OR if that path doesn't actually have a file
	bool check = hasSound(key);
	if (hasSound(key) || !std::filesystem::exists(path))
		return false;

	path_map[key] = path;
	return true;
}
bool SoundClass::hasSound(const std::string& key)
{
	return path_map.count(key) > 0;
}
bool SoundClass::removeSound(const std::string& key)
{
	path_map.erase(key);
	return true;
}
bool SoundClass::playSound(const std::string& channel, const std::string& key, const bool& looped)
{
	if (!hasChannel(channel))
		return false;
	if (!hasSound(key))
		return false;

	channel_map[channel].playSound(engine, path_map[key], looped);
	return true;
}

void SoundClass::setVolume(const std::string& channel, const float& _volCurr)
{
	if (!hasChannel(channel))
		return;

	channel_map[channel].setVolume(_volCurr);
}
float SoundClass::getVolume(const std::string& channel)
{
	if (!hasChannel(channel))
		return -1.f;

	return channel_map[channel].volCurr;
}

void SoundClass::OnSoundStopped(ISound* sound, E_STOP_EVENT_CAUSE reason, void* userData)
{
	for (auto& channel : channel_map)
	{
		if (channel.second.snd == sound)
			channel.second.snd = nullptr;
	}
}