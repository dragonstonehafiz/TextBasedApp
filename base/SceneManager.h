#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "SingletonTemplate.h"
#include "BaseScene.h"
#include <string>
#include <map>

class SceneManager
	: public Singleton<SceneManager>
{
	friend Singleton<SceneManager>;
public:
	bool addScene(BaseScene* toAdd, std::string sceneName);
	bool removeScene(std::string sceneName);
	bool changeScene(std::string sceneName);
	bool hasScene(std::string sceneName);
	BaseScene* getScene(std::string sceneName);
	
	void update(double dt);
	void clearScenes();
private:
	SceneManager();
	~SceneManager();

	std::map<std::string, BaseScene*> sceneMap;
	BaseScene* currScene;

};

#endif // !SCENE_MANAGER_H_