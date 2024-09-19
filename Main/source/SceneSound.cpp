#include "SceneSound.h"

SceneSound::SceneSound()
{

}
SceneSound::~SceneSound()
{

}

void SceneSound::init()
{
	soundManager = SoundClass::getInstance();
	soundManager->addSound("richtofen", "sfx/test.mp3");
	soundManager->playSound("SFX", "richtofen", true);
}

void SceneSound::update(double dt)
{

}
void SceneSound::render()
{

}

void SceneSound::enter()
{

}
void SceneSound::exit()
{

}

void SceneSound::reenter()
{

}
void SceneSound::hibernate()
{

}