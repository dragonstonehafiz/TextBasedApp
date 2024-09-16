#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "../helper/CSV_Reader.h"
#include "../helper/StringHelper.h"

#include "SceneDefault.h"

CSV_Reader csv = CSV_Reader::readfile("data/paths.csv");
int x = 1;


Application::Application() :
	fpsHandler(nullptr),
	consoleHandler(nullptr),
	keyboardHandler(nullptr),
	mouseHandler(nullptr),
	sceneManager(nullptr)
{
}
Application::~Application()
{
}

void Application::init()
{
	fpsHandler = FrameRateHandler::getInstance();
	fpsHandler->setTargetFramerate(59.94);

	consoleHandler = Console::getInstance();
	consoleHandler->init(128, 48);
	consoleHandler->setConsoleTitle("Text Based App");

	keyboardHandler = KeyboardHandler::getInstance();
	mouseHandler = MouseHandler::getInstance();

	sceneManager = SceneManager::getInstance();
	sceneManager->addScene(new DefaultScene(), "Default Scene");
	sceneManager->changeScene("Default Scene");
}
void Application::PreFrameUpdate()
{
	consoleHandler->preFrameUpdate();
	fpsHandler->startOfFrame();
	keyboardHandler->preFrameUpdate();
	mouseHandler->preFrameUpdate();
}
void Application::PostFrameUpdate()
{
	fpsHandler->endOfFrame();
	keyboardHandler->postFrameUpdate();
	mouseHandler->postFrameUpdate();
}
void Application::Update()
{
	sceneManager->update(fpsHandler->getDeltaTime());
}
void Application::mainloop()
{
	while (true)
	{
		PreFrameUpdate();

		Update();

		PostFrameUpdate();
	}
}