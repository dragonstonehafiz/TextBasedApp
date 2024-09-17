#ifndef SCENE_STATS_H_
#define SCENE_STATS_H_

#include "../base/BaseScene.h"

class SceneStats :
	public BaseScene
{
public:
	SceneStats();
	~SceneStats();

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

#endif // !SCENE_STATS_H_
