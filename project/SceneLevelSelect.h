#ifndef SCENE_LEVEL_SELECT_H_
#define SCENE_LEVEL_SELECT_H_

#include "../base/BaseScene.h"

class SceneLevelSelect :
	public BaseScene
{
public:
	SceneLevelSelect();
	~SceneLevelSelect();

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

#endif // !SCENE_LEVEL_SELECT_H_
