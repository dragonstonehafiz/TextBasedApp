#include "ObjectMenu.h"
#include <sstream>
#include <iomanip>

#include "../helper/StringHelper.h"
#include "../base/Console.h"

ObjectMenu::ObjectMenu() :
	currOption(0),
	spaceBetweenOptions(1),
	centered(false)
{

}
ObjectMenu::~ObjectMenu()
{

}

void ObjectMenu::setCurrOption(int _currOption)
{
	currOption = _currOption;
	wrap();
}
int ObjectMenu::getCurrOption() const
{
	return currOption;
}
void ObjectMenu::goUp()
{
	currOption -= 1;
	wrap();
}
void ObjectMenu::goDown()
{
	currOption += 1;
	wrap();
}
void ObjectMenu::setOptions(std::string _options)
{
	options = split(_options, ',');
}

void ObjectMenu::setSpaceBetweenOptions(int _spaceBetweenOptions)
{
	spaceBetweenOptions = _spaceBetweenOptions;
}
void ObjectMenu::setCentered(bool _centered)
{
	centered = _centered;
}

void ObjectMenu::update(double dt)
{

}
void ObjectMenu::render()
{
	std::stringstream ss;
	Console* console = Console::getInstance();

	// Loop through all options to print each of them
	for (int i = 0; i < options.size(); ++i)
	{
		std::string option = options[i];
		ss.str("");

		// Changes the color of the text if this is the option the user is on.
		int color = 0x07;
		if (currOption == i)
			color = 0x70;

		ss << option;

		// Centers the text using the length of each option
		int xPos = x;
		if (centered)
			xPos = x - (option.length() / 2);

		// Sets the y position of each option
		int yPos = y + i * spaceBetweenOptions;
		
		console->write(ss.str(), xPos, yPos, color);
	}
}

void ObjectMenu::wrap()
{
	if (currOption < 0)
		currOption = options.size() - 1;
	else if (currOption >= options.size())
		currOption = 0;
}