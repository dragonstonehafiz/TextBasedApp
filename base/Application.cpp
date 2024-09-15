#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "..//helper/CSV_Reader.h"

CSV_Reader csv = CSV_Reader::readfile("data/paths.csv");
int x = 1;


Application::Application() :
	fpsHandler(nullptr),
	consoleHandler(nullptr),
	keyboardHandler(nullptr),
	mouseHandler(nullptr)
{
}
Application::~Application()
{ 
	delete fpsHandler;
	delete consoleHandler;
	delete keyboardHandler;
	delete mouseHandler;
}

void Application::init()
{
	fpsHandler = new FrameRateHandler(59.94);

	consoleHandler = new Console(100, 30);
	consoleHandler->setConsoleTitle("Text Based App");

	keyboardHandler = new KeyboardHandler();
	mouseHandler = new MouseHandler(consoleHandler);
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
		std::string toPrint = std::to_string(i);
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

double Application::getDeltaTime()
{
	return fpsHandler->getDeltaTime();
}
FrameRateHandler* Application::getFPSHandler()
{
	return fpsHandler;
}
Console* Application::getConsoleHandler()
{
	return consoleHandler;
}
KeyboardHandler* Application::getKeyboardHandler()
{
	return keyboardHandler;
}
MouseHandler* Application::getMouseHandler()
{
	return mouseHandler;
}