#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "SingletonTemplate.h"
#include "BaseScene.h"
#include <string>
#include <map>
#include <vector>

class SceneManager
	: public Singleton<SceneManager>
{
	friend Singleton<SceneManager>;
public:
	bool addScene(BaseScene* toAdd, std::string sceneName);
	bool removeScene(std::string sceneName);
	bool hasScene(std::string sceneName);
	BaseScene* getScene(std::string sceneName);
	
	void update(double dt);
	void clearScenes();

	/// <summary>
	/// replace the scene at the top of the stack.
	/// </summary>
	/// <param name="sceneName">The key of the scene to change to that is stored on the map</param>
	/// <returns></returns>
	bool changeScene(std::string sceneName);
	/// <summary>
	/// push a new scene to the top of the stack.
	/// </summary>
	/// <param name="sceneName">The key of the scene to change to that is stored on the map</param>
	/// <returns></returns>
	bool pushToStack(std::string sceneName);
	/// <summary>
	/// removes the scene at the top of the stack.
	/// </summary>
	/// <returns></returns>
	bool popStack();
private:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// Gets the scene at the top of the stack.
	/// Or nullptr if there are no scenes in the stack.
	/// </summary>
	/// <returns></returns>
	BaseScene* getCurrScene();

	/// <summary>
	/// The scene map stores every single scene that will be accessed onto a map.
	/// </summary>
	std::map<std::string, BaseScene*> sceneMap;
	/// <summary>
	/// The top of the stack is the scene that will be rendered and updated.
	/// Every scene below will be in 'hibernation' mode where they wait to be returned to.
	/// Called stack, but using a vector so that we can make sure scenes that are on the stack are not removed 
	/// (which will definitely cause crashes when those scenes are deleted)
	/// </summary>
	std::vector<BaseScene*> sceneStack;

};

#endif // !SCENE_MANAGER_H_