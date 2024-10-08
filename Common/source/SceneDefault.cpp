#include "SceneDefault.h"
#include "FrameRateHandler.h"
#include "Console.h"
#include "StringHelper.h"
#include "KeyboardHandler.h"

DefaultScene::DefaultScene()
{
	enter();
}
DefaultScene::~DefaultScene()
{

}

void DefaultScene::init()
{
}
void DefaultScene::update(double dt)
{
	totalElapsedTime += dt;
	if (counter % 60 == 0)
		seconds_passed += 1;

	if (KeyboardHandler::getInstance()->isKeyPressed('A'))
	{
		seconds_passed = 0;
		counter = 0;
		totalElapsedTime = 0.f;
	}
	if (KeyboardHandler::getInstance()->isKeyDown('B'))
	{
		counter += 1;
	}
}
void DefaultScene::render()
{
	FrameRateHandler* fpsHandler = FrameRateHandler::getInstance();
	Console* consoleHandler = Console::getInstance();
	consoleHandler->write(fpsHandler->getFPS_str(), 1, 0);
	
	std::string toPrint = format("Counter: %d", counter);
	consoleHandler->write(toPrint, 1, 1);

	toPrint = format("seconds passed: %d", seconds_passed);
	consoleHandler->write(toPrint, 1, 2);

	toPrint = format("Total Elapsed Time: %0.2f", (float)(totalElapsedTime));
	consoleHandler->write(toPrint, 1, 3);

	toPrint = format("dt: %0.5f", (float)(fpsHandler->getDeltaTime()));
	consoleHandler->write(toPrint, 1, 4);
}

void DefaultScene::enter()
{
	seconds_passed = 0;
	counter = 0;
	totalElapsedTime = 0.f;
}
void DefaultScene::exit()
{

}
void DefaultScene::reenter()
{

}
void DefaultScene::hibernate()
{

}