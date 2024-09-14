#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int x = 1;

Application::Application() :
	fpsHandler(nullptr),
	consoleHandler(nullptr)
{
}
Application::~Application()
{ 
	delete fpsHandler;
	delete consoleHandler;
}

void Application::init()
{
	// Init FPS handler
	fpsHandler = new FrameRateHandler(59.94);
	// Init Console
	consoleHandler = new Console(100, 30);
}
void Application::PreFrameUpdate()
{
	fpsHandler->startOfFrame();
	consoleHandler->clearScreen();
}
void Application::PostFrameUpdate()
{
	fpsHandler->endOfFrame();
}
void Application::Update()
{
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(2) << fpsHandler->getTrueFrameRate() << "fps";
	consoleHandler->write(ss.str(), 5, 0);
	ss.str("");
	ss << x++;
	consoleHandler->write(ss.str(), 5, 1);
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