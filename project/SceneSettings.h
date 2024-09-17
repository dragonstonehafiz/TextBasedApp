#ifndef SCENE_SETTINGS_H_
#define SCENE_SETTINGS_H_

#include "../base/BaseScene.h"

class SceneSettings :
	public BaseScene
{
public:
	SceneSettings();
	~SceneSettings();

	void update(double dt);
	void render();

	void init();

	void enter();
	void exit();
	void reenter();
	void hibernate();
private:
	void renderHeader();
};

#endif // !SCENE_SETTINGS_H_
