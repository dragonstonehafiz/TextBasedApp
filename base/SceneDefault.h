#ifndef SCENE_DEFAULT_H_
#define SCENE_DEFAULT_H_

#include "BaseScene.h"

class DefaultScene :
	public BaseScene
{
public:
	DefaultScene();
	~DefaultScene();

	void init();
	void update(double dt);
	void render();
	void enter();
	void exit();
private:
	double totalElapsedTime;
	int counter;
};

#endif // !SCENE_DEFAULT_H_
