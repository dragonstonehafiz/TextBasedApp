#include <iostream>
#include "Application.h"

int main()
{
	Application* app = Application::getInstance();
	app->init();
	app->mainloop();
	Application::Destroy();
	return 1;
}