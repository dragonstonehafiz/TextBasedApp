#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int x = 1;
int y = 1;

Application::Application() :
	fpsHandler(nullptr),
	consoleHandler(nullptr),
	keyboardHandler(nullptr)
{
}
Application::~Application()
{ 
	delete fpsHandler;
	delete consoleHandler;
	delete keyboardHandler;
}

void Application::init()
{
	fpsHandler = new FrameRateHandler(59.94);
	consoleHandler = new Console(100, 30);
	keyboardHandler = new KeyboardHandler();
}
void Application::PreFrameUpdate()
{
	consoleHandler->clearScreen();
	fpsHandler->startOfFrame();
	keyboardHandler->preFrameUpdate();
}
void Application::PostFrameUpdate()
{
	fpsHandler->endOfFrame();
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
	ss << y;
	if (keyboardHandler->isKeyDown('A'))
		y++;
	consoleHandler->write(ss.str(), 5, 2, 0x2E);
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