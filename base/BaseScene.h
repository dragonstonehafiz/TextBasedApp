#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

class BaseScene
{
public:
	BaseScene() {};
	~BaseScene() {};

	/// <summary>
	/// This is called if there are any values that need to be initialized only once.
	/// </summary>
	virtual void init() = 0;

	/// <summary>
	/// Called every frame to update logic.
	/// </summary>
	/// <param name="dt">time elapsed between this frame and previous</param>
	virtual void update(double dt) = 0;
	/// <summary>
	/// Called every frame to print to console.
	/// </summary>
	virtual void render() = 0;

	/// <summary>
	/// Called when you first enter a scene.
	/// </summary>
	virtual void enter() = 0;
	/// <summary>
	/// Called when you are pushing the scene from the scene stack.
	/// </summary>
	virtual void exit() = 0;

	/// <summary>
	/// Called when you returning to this scene from the scene stack.
	/// </summary>
	virtual void reenter() = 0;
	/// <summary>
	/// Called when you are pushing this scene to the scene stack.
	/// </summary>
	virtual void hibernate() = 0;
protected:
};


#endif // !BASE_SCENE_H_
