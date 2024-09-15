#include "Console.h"
#include <iostream>

Console::Console(short width, short height) :
	bufferSize{width, height},
	hConsole(GetStdHandle(STD_OUTPUT_HANDLE)),
	hWindow(GetConsoleWindow())
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
void Console::preFrameUpdate()
{
	clearScreen();

	RECT consoleRect;
	GetWindowRect(hWindow, &consoleRect);
	windowPos.x = consoleRect.left;
	windowPos.y = consoleRect.top;
}
void Console::postFrameUpdate()
{

}

void Console::write(std::string str, COORD c, int color)
{
	write(str, c.X, c.Y, color);
}
void Console::write(std::string str, int x, int y, int color)
{
	setColor(color);
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
int Console::getPosX() const
{
	return windowPos.x;
}
int Console::getPosY() const
{
	return windowPos.y;
}
void Console::setConsoleTitle(std::string title)
{
	std::wstring stemp = std::wstring(title.begin(), title.end());
	SetConsoleTitle(stemp.c_str());
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
void Console::disableQuickEdit()
{
	// Get the current input mode
	DWORD prev_mode;
	GetConsoleMode(hConsole, &prev_mode);

	// Disable Quick Edit Mode by turning off the ENABLE_QUICK_EDIT_MODE bit
	DWORD new_mode = prev_mode & ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hConsole, new_mode);
}
void Console::setColor(int color)
{
	SetConsoleTextAttribute(hConsole, color);
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