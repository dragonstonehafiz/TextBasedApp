#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

class BaseScene
{
public:
	BaseScene() {};
	~BaseScene() {};

	virtual void init() = 0;
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;
private:
};


#endif // !BASE_SCENE_H_
