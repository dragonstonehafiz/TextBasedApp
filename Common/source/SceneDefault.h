#ifndef SCENE_DEFAULT_H_
#define SCENE_DEFAULT_H_

#include "BaseScene.h"

class DefaultScene :
	public BaseScene
{
public:
	DefaultScene();
	~DefaultScene();

	void update(double dt);
	void render();

	void init();

	void enter();
	void exit();
	void reenter();
	void hibernate();
private:
	double totalElapsedTime;
	int counter;
	int seconds_passed;
};

#endif // !SCENE_DEFAULT_H_
