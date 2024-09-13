#include "Application.h"
#include <iostream>

Application::Application() :
	fpsHandler(nullptr)
{
}
Application::~Application()
{ 
	delete fpsHandler;
}

void Application::init()
{
	fpsHandler = new FrameRateHandler(59.94);
}
void Application::PreFrameUpdate()
{
	fpsHandler->startOfFrame();
}
void Application::PostFrameUpdate()
{
	fpsHandler->endOfFrame();
}
void Application::Update()
{
	std::cout << fpsHandler->getTrueFrameRate() << std::endl;
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