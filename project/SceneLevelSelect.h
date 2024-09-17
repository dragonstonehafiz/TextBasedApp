#ifndef SCENE_LEVEL_SELECT_H_
#define SCENE_LEVEL_SELECT_H_

#include "../base/BaseScene.h"
#include <string>

class ObjectMenu_LevelSelect;

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

	/// <summary>
	/// The path to the folder that stores all directories that will be used
	/// </summary>
	std::string datafolder;
	ObjectMenu_LevelSelect* menuWhichCSV;
};

#endif // !SCENE_LEVEL_SELECT_H_
