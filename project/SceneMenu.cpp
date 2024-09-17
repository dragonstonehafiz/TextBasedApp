#include "SceneMenu.h"
#include "../base/KeyboardHandler.h"
#include "../base/Console.h"
#include "ObjectMenu.h"

#include <cmath>

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

	// Move Key Up and Down
	if (keyboardHandler->isKeyPressed(VK_UP))
		menu->goUp();
	else if (keyboardHandler->isKeyPressed(VK_DOWN))
		menu->goDown();



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
	int xStartPos = (consoleWidth / 2) - std::ceil(55 / 2);
	int yStartPos = 1;

	consoleHandler->write(headerBorder, 0, yStartPos, 0x07);
	consoleHandler->write("   _____ _             _                              ", xStartPos, yStartPos+1, 0x07);
	consoleHandler->write("  / ____| |           | |           /\\                ", xStartPos, yStartPos+2, 0x07);
	consoleHandler->write(" | (___ | |_ _   _  __| |_   _     /  \\   _ __  _ __  ", xStartPos, yStartPos+3, 0x07);
	consoleHandler->write("  \\___ \\| __| | | |/ _` | | | |   / /\\ \\ | '_ \\| '_ \\ ", xStartPos, yStartPos+4, 0x07);
	consoleHandler->write("  ____) | |_| |_| | (_| | |_| |  / ____ \\| |_) | |_) |", xStartPos, yStartPos+5, 0x07);
	consoleHandler->write(" |_____/ \\__|\\__,_|\\__,_|\\__, | /_/    \\_\\ .__/| .__/ ", xStartPos, yStartPos+6, 0x07);
	consoleHandler->write("                          __/ |          | |   | |    ", xStartPos, yStartPos+7, 0x07);
	consoleHandler->write("                         |___/           |_|   |_|    ", xStartPos, yStartPos+8, 0x07);
	consoleHandler->write(headerBorder, 0, yStartPos+9, 0x07);
}