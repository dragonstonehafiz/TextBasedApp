#ifndef SCENE_SOUND_H_
#define SCENE_SOUND_H_

#include "BaseScene.h"
#include "SoundClass.h"

class SceneSound :
	public BaseScene
{
public:
	SceneSound();
	~SceneSound();

	void init();

	void update(double dt);
	void render();

	void enter();
	void exit();

	void reenter();
	void hibernate();

private:
	SoundClass* soundManager;
};

#endif // !SCENE_SOUND_H_
