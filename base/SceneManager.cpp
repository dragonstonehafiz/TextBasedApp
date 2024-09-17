#include "SceneManager.h"

SceneManager::SceneManager()
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
	return true;
	
}
bool SceneManager::removeScene(std::string sceneName)
{
	if (hasScene(sceneName))
	{
		BaseScene* toRemove = getScene(sceneName);

		// Don't delete the scene if it is in the stack
		for (auto scene : sceneStack)
		{
			if (scene == toRemove)
				return false;
		}

		delete toRemove;
		sceneMap.erase(sceneName);
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
BaseScene* SceneManager::getCurrScene()
{
	if (sceneStack.size() > 0)
		return sceneStack.back();
	else
		return nullptr;
}

void SceneManager::update(double dt)
{
	BaseScene* currScene = getCurrScene();

	// Make sure to exit the previous scene
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

	sceneStack.clear();
}

bool SceneManager::changeScene(std::string sceneName)
{
	if (hasScene(sceneName))
	{
		BaseScene* nextScene = getScene(sceneName);
		BaseScene* currScene = getCurrScene();

		// Make sure to exit the previous scene
		if (currScene != nullptr)
		{
			currScene->exit();
			sceneStack.pop_back();
		}


		nextScene->enter();
		sceneStack.push_back(nextScene);
		return true;
	}
	else
		return false;
}
bool SceneManager::pushToStack(std::string sceneName)
{
	if (hasScene(sceneName))
	{
		BaseScene* nextScene = getScene(sceneName);

		BaseScene* currScene = getCurrScene();
		// Make sure to put the previous scene into hibernation
		if (currScene != nullptr)
			currScene->hibernate();

		// Push the new scene to the stack.
		nextScene->enter();
		sceneStack.push_back(nextScene);
		return true;
	}
	else
		return false;
}
bool SceneManager::popStack()
{
	if (sceneStack.size() <= 1)
		return false;

	BaseScene* currScene = getCurrScene();
	// Make sure to exit the curr scene before going down the stack
	if (currScene != nullptr)
	{
		currScene->exit();
		sceneStack.pop_back();
	}
	
	// Reenter the previous scene in the stack.
	sceneStack.back()->reenter();
	return true;
}