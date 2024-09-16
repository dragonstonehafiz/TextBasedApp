#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "..//helper/CSV_Reader.h"
#include "../helper/StringHelper.h"

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
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(2) << fpsHandler->getTrueFrameRate() << "fps";
	consoleHandler->write(ss.str(), 5, 0, 0x1E);


	ss.str("");
	ss << x++;
	consoleHandler->write(ss.str(), 5, 1);


	ss.str("");
	if (mouseHandler->isMouseDown(MOUSE_LEFT))
		ss << "left mouse down";
	else
		ss << "left mouse up";
	consoleHandler->write(ss.str(), 5, 2, 0x2E);
	ss.str("");
	ss << mouseHandler->getMousePosX() << ":" << mouseHandler->getMousePosY();
	consoleHandler->write(ss.str(), 5, 3, 0x2E);

	ss.str("");
	ss << csv.getcolnames();
	consoleHandler->write(ss.str(), 5, 4, 0xF0);

	for (int i = 0; i < consoleHandler->getHeight(); ++i)
	{
		COORD c = { 0, i };
		std::string toPrint = format("%02d", i);
		consoleHandler->write(toPrint, c);
	}
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