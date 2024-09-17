#include "SceneMenu.h"

#include <cmath>
#include "../base/KeyboardHandler.h"
#include "../base/Console.h"
#include "../base/SceneManager.h"
#include "../base/Application.h"

#include "ObjectMenu.h"


SceneMenu::SceneMenu() :
	menu(nullptr)
{
}
SceneMenu::~SceneMenu()
{

}

void SceneMenu::update(double dt)
{
	KeyboardHandler* keyboardHandler = KeyboardHandler::getInstance();
	SceneManager* sceneManager = SceneManager::getInstance();

	// Move Key Up and Down
	if (keyboardHandler->isKeyPressed(VK_UP) || keyboardHandler->isKeyPressed('W'))
		menu->goUp();
	else if (keyboardHandler->isKeyPressed(VK_DOWN) || keyboardHandler->isKeyPressed('S'))
		menu->goDown();

	if (keyboardHandler->isKeyPressed(VK_RETURN))
	{
		switch (menu->getCurrOption())
		{
		case OPTION_LEVEL:
			sceneManager->changeScene("Level Select");
			break;
		case OPTION_SETTINGS:
			sceneManager->pushToStack("Settings");
			break;
		case OPTION_STATS:
			sceneManager->pushToStack("Stats");
			break;
		case OPTION_QUIT:
			Application::getInstance()->quit();
			break;
		default:
			break;
		}
	}
}
void SceneMenu::render()
{
	renderHeader();
	menu->render();
}

void SceneMenu::init()
{

}

void SceneMenu::enter()
{
	menu = new ObjectMenu();
	menu->setOptions("Study,Settings,Stats,Quit");
	menu->setPos(64, 13);
	menu->setCentered(true);
	menu->setSpaceBetweenOptions(2);
	reenter();
}
void SceneMenu::exit()
{
	delete menu;
	menu = nullptr;
}
void SceneMenu::reenter()
{

}
void SceneMenu::hibernate()
{

}

void SceneMenu::renderHeader()
{
	Console* consoleHandler = Console::getInstance();
	int consoleWidth = consoleHandler->getWidth();
	std::string headerBorder = std::string(consoleWidth, '_');
	int xStartPos = (consoleWidth / 2) - std::ceil(64 / 2);
	int yStartPos = 1;

	consoleHandler->write(headerBorder, 0, yStartPos, 0x07);
	consoleHandler->write("   _____ _______ _    _ _______     __           _____  _____  ", xStartPos, yStartPos+1, 0x07);
	consoleHandler->write("  / ____|__   __| |  | |  __ \\ \\   / /     /\\   |  __ \\|  __ \\ ", xStartPos, yStartPos+2, 0x07);
	consoleHandler->write(" | (___    | |  | |  | | |  | \\ \\_/ /     /  \\  | |__) | |__) |", xStartPos, yStartPos+3, 0x07);
	consoleHandler->write("  \\___ \\   | |  | |  | | |  | |\\   /     / /\\ \\ |  ___/|  ___/ ", xStartPos, yStartPos+4, 0x07);
	consoleHandler->write("  ____) |  | |  | |__| | |__| | | |     / ____ \\| |    | |     ", xStartPos, yStartPos+5, 0x07);
	consoleHandler->write(" |_____/   |_|   \\____/|_____/  |_|    /_/    \\_\\_|    |_|     ", xStartPos, yStartPos+6, 0x07);
	consoleHandler->write(headerBorder, 0, yStartPos+7, 0x07);
}