#ifndef SCENE_GAME_H_
#define SCENE_GAME_H_

#include "../base/BaseScene.h"

class SceneGame :
	public BaseScene
{
public:
	SceneGame();
	~SceneGame();

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

#endif // !SCENE_GAME_H_
