#include "SceneDefault.h"
#include "FrameRateHandler.h"
#include "Console.h"
#include "../helper/StringHelper.h"

DefaultScene::DefaultScene()
{
}
DefaultScene::~DefaultScene()
{

}

void DefaultScene::init()
{
}
void DefaultScene::update(double dt)
{
	totalElapsedTime += FrameRateHandler::getInstance()->getDeltaTime();
	counter += 1;
}
void DefaultScene::render()
{
	FrameRateHandler* fpsHandler = FrameRateHandler::getInstance();
	Console* consoleHandler = Console::getInstance();
	consoleHandler->write(fpsHandler->getFPS_str(), 1, 0);
	
	std::string toPrint = format("Counter: %03d", counter);
	consoleHandler->write(toPrint, 1, 1);

	toPrint = format("Total Elapsed Time: %0.2f", (float)(totalElapsedTime));
	consoleHandler->write(toPrint, 1, 2);
}
void DefaultScene::enter()
{
	totalElapsedTime = 0;
	counter = 0;
}
void DefaultScene::exit()
{

}