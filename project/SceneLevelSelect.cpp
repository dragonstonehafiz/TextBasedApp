#include "SceneLevelSelect.h"

#include <cmath>
#include "../base/Console.h"
#include "../base/KeyboardHandler.h"
#include "../base/SceneManager.h"
#include "../base/SceneManager.h"

SceneLevelSelect::SceneLevelSelect()
{

}
SceneLevelSelect::~SceneLevelSelect()
{

}

void SceneLevelSelect::update(double dt)
{
	KeyboardHandler* keyboardHandler = KeyboardHandler::getInstance();
	SceneManager* sceneManager = SceneManager::getInstance();

	if (keyboardHandler->isKeyPressed(VK_ESCAPE))
		sceneManager->changeScene("Menu");
}
void SceneLevelSelect::render()
{
	renderHeader();
}

void SceneLevelSelect::init()
{

}

void SceneLevelSelect::enter()
{

}
void SceneLevelSelect::exit()
{

}
void SceneLevelSelect::reenter()
{

}
void SceneLevelSelect::hibernate()
{

}

void SceneLevelSelect::renderHeader()
{
	Console* consoleHandler = Console::getInstance();
	int consoleWidth = consoleHandler->getWidth();
	std::string headerBorder = std::string(consoleWidth, '_');
	int xStartPos = (consoleWidth / 2) - std::ceil(84 / 2);
	int yStartPos = 1;

	consoleHandler->write(headerBorder, 0, yStartPos);
	consoleHandler->write("  _      ________      ________ _         _____ ______ _      ______ _____ _______ ", xStartPos, yStartPos + 1);
	consoleHandler->write(" | |    |  ____\\ \\    / /  ____| |       / ____|  ____| |    |  ____/ ____|__   __|", xStartPos, yStartPos + 2);
	consoleHandler->write(" | |    | |__   \\ \\  / /| |__  | |      | (___ | |__  | |    | |__ | |       | |   ", xStartPos, yStartPos + 3);
	consoleHandler->write(" | |    |  __|   \\ \\/ / |  __| | |       \\___ \\|  __| | |    |  __|| |       | |   ", xStartPos, yStartPos + 4);
	consoleHandler->write(" | |____| |____   \\  /  | |____| |____   ____) | |____| |____| |___| |____   | |   ", xStartPos, yStartPos + 5);
	consoleHandler->write(" |______|______|   \\/   |______|______| |_____/|______|______|______\\_____|  |_|   ", xStartPos, yStartPos + 6);
	consoleHandler->write(headerBorder, 0, yStartPos + 7);
}