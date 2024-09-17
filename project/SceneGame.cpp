#include "SceneGame.h"

#include "../base/Console.h"
#include "../base/SceneManager.h"
#include <cmath>

SceneGame::SceneGame()
{

}
SceneGame::~SceneGame()
{

}

void SceneGame::update(double dt)
{

}
void SceneGame::render()
{
	renderHeader();
}

void SceneGame::init()
{

}

void SceneGame::enter()
{

}
void SceneGame::exit()
{

}
void SceneGame::reenter()
{

}
void SceneGame::hibernate()
{

}

void SceneGame::renderHeader()
{
	Console* consoleHandler = Console::getInstance();
	int consoleWidth = consoleHandler->getWidth();
	std::string headerBorder = std::string(consoleWidth, '_');
	int xStartPos = (consoleWidth / 2) - std::ceil(33 / 2);
	int yStartPos = 1;

	consoleHandler->write(headerBorder, 0, yStartPos);
	consoleHandler->write("   _____          __  __ ______ ", xStartPos, yStartPos + 1);
	consoleHandler->write("  / ____|   /\\   |  \\/  |  ____|", xStartPos, yStartPos + 2);
	consoleHandler->write(" | |  __   /  \\  | \\  / | |__   ", xStartPos, yStartPos + 3);
	consoleHandler->write(" | | |_ | / /\\ \\ | |\\/| |  __|  ", xStartPos, yStartPos + 4);
	consoleHandler->write(" | |__| |/ ____ \\| |  | | |____ ", xStartPos, yStartPos + 5);
	consoleHandler->write("  \\_____/_/    \\_\\_|  |_|______|", xStartPos, yStartPos + 6);
	consoleHandler->write(headerBorder, 0, yStartPos + 7);
}