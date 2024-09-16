#include "SceneManager.h"

SceneManager::SceneManager():
	currScene(nullptr)
{

}
SceneManager::~SceneManager()
{
	clearScenes();
}


bool SceneManager::addScene(BaseScene* toAdd, std::string sceneName)
{
	// If no scene was provided don't add it to the map
	if (toAdd == nullptr)
		return false;

	// If there is already a scene with the same name, don't add the new scene.
	if (hasScene(sceneName))
		return false;

	sceneMap[sceneName] = toAdd;
	
}
bool SceneManager::removeScene(std::string sceneName)
{
	if (hasScene(sceneName))
	{
		BaseScene* toRemove = getScene(sceneName);
		// Don't delete the scene if it is the active scene
		if (currScene == toRemove)
			return false;
		delete toRemove;
		sceneMap.erase(sceneName);
		return true;
	}
	else
		return false;
}
bool SceneManager::changeScene(std::string sceneName)
{
	if (hasScene(sceneName))
	{
		BaseScene* nextScene = getScene(sceneName);
		// Make sure to leave the current scene
		if (currScene != nullptr)
			currScene->exit();
		nextScene->enter();
		currScene = nextScene;
		return true;
	}
	else
		return false;
}
bool SceneManager::hasScene(std::string sceneName)
{
	return sceneMap.count(sceneName) != 0;
}
BaseScene* SceneManager::getScene(std::string sceneName)
{
	if (hasScene(sceneName))
		return sceneMap[sceneName];
	else
		return nullptr;
}

void SceneManager::update(double dt)
{
	if (currScene != nullptr)
	{
		currScene->update(dt);
		currScene->render();
	}
}
void SceneManager::clearScenes()
{
	std::map<std::string, BaseScene*>::iterator it = sceneMap.begin();
	while (it != sceneMap.end())
	{
		delete it->second;
		sceneMap.erase(it);
		it = sceneMap.begin();
	}
}