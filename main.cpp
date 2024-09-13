#include <iostream>
#include "base/Application.h"

void main()
{
	Application *app = Application::getInstance();
	app->init();
	app->mainloop();
	Application::Destroy();
}