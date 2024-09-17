#include "SceneLevelSelect.h"

#include <cmath>

#include "../base/Console.h"
#include "../base/KeyboardHandler.h"
#include "../base/SceneManager.h"
#include "../base/SceneManager.h"
#include "QuestionManager.h"

#include "ObjectMenu_LevelSelect.h"


SceneLevelSelect::SceneLevelSelect() :
	datafolder("data"),
	menuWhichCSV(nullptr)
{

}
SceneLevelSelect::~SceneLevelSelect()
{

}

void SceneLevelSelect::update(double dt)
{
	KeyboardHandler* keyboardHandler = KeyboardHandler::getInstance();
	SceneManager* sceneManager = SceneManager::getInstance();

	// Move Key Up and Down
	if (keyboardHandler->isKeyPressed(VK_UP) || keyboardHandler->isKeyPressed('W'))
		menuWhichCSV->goUp();
	else if (keyboardHandler->isKeyPressed(VK_DOWN) || keyboardHandler->isKeyPressed('S'))
		menuWhichCSV->goDown();

	if (keyboardHandler->isKeyPressed(VK_RETURN))
	{
		int selection = menuWhichCSV->getCurrOption();
		// Back will always be one option above the all the directories
		if (menuWhichCSV->isCurr_Back())
			sceneManager->changeScene("Menu");
		else
		{
			// Selection should always be within the range of the level selector
			std::string csvPath = menuWhichCSV->getCurrCSVPath();
			QuestionManager::getInstance()->loadQuestions(csvPath);
			sceneManager->changeScene("Game");
		}
	}
}
void SceneLevelSelect::render()
{
	renderHeader();

	if (menuWhichCSV != nullptr)
		menuWhichCSV->render();
}

void SceneLevelSelect::init()
{

}

void SceneLevelSelect::enter()
{
	// Create the menu items for choosing which directory to open
	menuWhichCSV = new ObjectMenu_LevelSelect();
	menuWhichCSV->setPos(2, 10);
	menuWhichCSV->setSpaceBetweenOptions(1);
	menuWhichCSV->loadDirectories(datafolder);
}
void SceneLevelSelect::exit()
{
	delete menuWhichCSV;
	menuWhichCSV = nullptr;
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