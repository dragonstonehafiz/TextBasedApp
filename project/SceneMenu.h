#ifndef SCENE_MENU_H_
#define SCENE_MENU_H_

#include "../base/BaseScene.h"

class ObjectMenu;

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
	enum MENU_OPTIONS
	{
		OPTION_LEVEL = 0,
		OPTION_SETTINGS,
		OPTION_STATS,
		OPTION_QUIT,

		NUM_OPTIONS
	};
	
	ObjectMenu* menu;
	
	void renderHeader();
};

#endif // !SCENE_MENU_H_
