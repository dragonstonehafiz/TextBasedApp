#include "SceneSettings.h"

#include "../base/Console.h"
#include "../base/KeyboardHandler.h"
#include "../base/SceneManager.h"
#include <cmath>

SceneSettings::SceneSettings()
{

}
SceneSettings::~SceneSettings()
{

}

void SceneSettings::update(double dt)
{
	KeyboardHandler* keyboardHandler = KeyboardHandler::getInstance();
	SceneManager* sceneManager = SceneManager::getInstance();

	if (keyboardHandler->isKeyPressed(VK_ESCAPE))
		sceneManager->popStack();
}
void SceneSettings::render()
{
	renderHeader();
}

void SceneSettings::init()
{

}

void SceneSettings::enter()
{

}
void SceneSettings::exit()
{

}
void SceneSettings::reenter()
{

}
void SceneSettings::hibernate()
{

}

void SceneSettings::renderHeader()
{
	Console* consoleHandler = Console::getInstance();
	int consoleWidth = consoleHandler->getWidth();
	std::string headerBorder = std::string(consoleWidth, '_');
	int xStartPos = (consoleWidth / 2) - std::ceil(59 / 2);
	int yStartPos = 1;

	consoleHandler->write(headerBorder, 0, yStartPos);
	consoleHandler->write("   _____ ______ _______ _______ _____ _   _  _____  _____ ", xStartPos, yStartPos + 1);
	consoleHandler->write("  / ____|  ____|__   __|__   __|_   _| \\ | |/ ____|/ ____|", xStartPos, yStartPos + 2);
	consoleHandler->write(" | (___ | |__     | |     | |    | | |  \\| | |  __| (___  ", xStartPos, yStartPos + 3);
	consoleHandler->write("  \\___ \\|  __|    | |     | |    | | | . ` | | |_ |\\___ \\ ", xStartPos, yStartPos + 4);
	consoleHandler->write("  ____) | |____   | |     | |   _| |_| |\\  | |__| |____) |", xStartPos, yStartPos + 5);
	consoleHandler->write(" |_____/|______|  |_|     |_|  |_____|_| \\_|\\_____|_____/ ", xStartPos, yStartPos + 6);
	consoleHandler->write(headerBorder, 0, yStartPos + 7);
}