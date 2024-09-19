#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "SceneDefault.h"
#include "StringHelper.h"
#include "SceneSound.h"

#include <irrKlang.h>
using namespace irrklang;



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

	soundManager = SoundClass::getInstance();
	soundManager->init();
	soundManager->createChannel("Ambient");
	soundManager->createChannel("SFX");
	soundManager->createChannel("Music");

	sceneManager = SceneManager::getInstance();
	sceneManager->addScene(new DefaultScene(), "Default");
	sceneManager->addScene(new SceneSound(), "Sound");
	sceneManager->changeScene("Sound");
}
void Application::mainloop()
{
	while (isRunning)
	{
		PreFrameUpdate();

		Update();

		PostFrameUpdate();
	}
	consoleHandler->clearScreen();
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