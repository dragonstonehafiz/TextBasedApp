#include "Console.h"
#include <iostream>

Console::Console(short width, short height) :
	bufferSize{width, height},
	hConsole(GetStdHandle(STD_OUTPUT_HANDLE))
{
	disableResize();
	setConsoleSize();
	toggleCursor();
}
Console::~Console()
{

}

void Console::clearScreen()
{
	int size = getHeight() * getWidth();
	std::string clearString = std::string(size, ' ');
	moveTo(0, 0);
	std::cout << clearString;
}
void Console::write(std::string str, COORD c)
{
	moveTo(c.X, c.Y);
	std::cout << str;
}
void Console::write(std::string str, int x, int y)
{
	moveTo(x, y);
	std::cout << str;
}

int Console::getWidth() const
{
	return bufferSize.X;
}
int Console::getHeight() const
{
	return bufferSize.Y;
}

void Console::setConsoleSize()
{
	// Set buffer size
	SetConsoleScreenBufferSize(hConsole, bufferSize);
	// Set window size
	SMALL_RECT windowSize;
	windowSize.Left = 0;
	windowSize.Top = 0;
	windowSize.Right = getWidth() - 1;
	windowSize.Bottom = getHeight() - 1;
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}
void Console::disableResize()
{
	// Get the console window handle
	HWND consoleWindow = GetConsoleWindow();
	// Get current window style and disable resizing (removing WS_SIZEBOX)
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style &= ~WS_SIZEBOX;  // Disable the size box (resize border)
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void Console::moveTo(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);
}
void Console::toggleCursor()
{
	// Get current cursor information
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);

	// Set the cursor visibility to false (hide it)
	cursorInfo.bVisible = !cursorInfo.bVisible;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}