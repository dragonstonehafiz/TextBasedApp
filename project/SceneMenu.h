#ifndef SCENE_MENU_H_
#define SCENE_MENU_H_

#include "../base/BaseScene.h"

class SceneMenu :
	public BaseScene
{
public:
	SceneMenu();
	~SceneMenu();

	void update(double dt);
	void render();

	void init();

	void enter();
	void exit();
	void reenter();
	void hibernate();
private:
};

#endif // !SCENE_MENU_H_
