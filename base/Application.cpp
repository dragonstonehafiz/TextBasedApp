#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "../helper/CSV_Reader.h"
#include "../helper/StringHelper.h"

#include "SceneDefault.h"
#include "../project/SceneMenu.h"

CSV_Reader csv = CSV_Reader::readfile("data/paths.csv");
int x = 1;

Application::Application() :
	isRunning(true),
	fpsHandler(nullptr),
	consoleHandler(nullptr),
	keyboardHandler(nullptr),
	mouseHandler(nullptr),
	sceneManager(nullptr),
	runTime(0)
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
	sceneManager->addScene(new SceneMenu(), "Menu");
	sceneManager->changeScene("Menu");
}
void Application::mainloop()
{
	while (isRunning)
	{
		PreFrameUpdate();

		Update();

		PostFrameUpdate();
	}
}

void Application::quit()
{
	isRunning = false;
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
	runTime += fpsHandler->getDeltaTime();
	sceneManager->update(fpsHandler->getDeltaTime());

	RenderInfo();
}
void Application::RenderInfo()
{
	// calculate run time
	std::string toPrint = "Run Time: " + getStringTime((int)runTime);
	consoleHandler->write(toPrint, { 0, 0 });

	// calculate fps
	toPrint = fpsHandler->getFPS_str();
	consoleHandler->write(toPrint, consoleHandler->getWidth() - toPrint.length(), 0);
}