#include "SceneStats.h"

#include "../base/Console.h"
#include "../base/KeyboardHandler.h"
#include "../base/SceneManager.h"
#include <cmath>

SceneStats::SceneStats()
{

}
SceneStats::~SceneStats()
{

}

void SceneStats::update(double dt)
{
	KeyboardHandler* keyboardHandler = KeyboardHandler::getInstance();
	SceneManager* sceneManager = SceneManager::getInstance();

	if (keyboardHandler->isKeyPressed(VK_ESCAPE))
		sceneManager->popStack();
}
void SceneStats::render()
{
	renderHeader();
}

void SceneStats::init()
{

}

void SceneStats::enter()
{

}
void SceneStats::exit()
{

}
void SceneStats::reenter()
{

}
void SceneStats::hibernate()
{

}

void SceneStats::renderHeader()
{
	Console* consoleHandler = Console::getInstance();
	int consoleWidth = consoleHandler->getWidth();
	std::string headerBorder = std::string(consoleWidth, '_');
	int xStartPos = (consoleWidth / 2) - std::ceil(35 / 2);
	int yStartPos = 1;

	consoleHandler->write(headerBorder, 0, yStartPos);
	consoleHandler->write("   _____ _______    _______ _____ ", xStartPos, yStartPos + 1);
	consoleHandler->write("  / ____|__   __|/\\|__   __/ ____|", xStartPos, yStartPos + 2);
	consoleHandler->write(" | (___    | |  /  \\  | | | (___  ", xStartPos, yStartPos + 3);
	consoleHandler->write("  \\___ \\   | | / /\\ \\ | |  \\___ \\ ", xStartPos, yStartPos + 4);
	consoleHandler->write("  ____) |  | |/ ____ \\| |  ____) |", xStartPos, yStartPos + 5);
	consoleHandler->write(" |_____/   |_/_/    \\_\\_| |_____/ ", xStartPos, yStartPos + 6);
	consoleHandler->write(headerBorder, 0, yStartPos + 7);
}