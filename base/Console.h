#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <Windows.h>
#include <string>

class Console
{
public:
	Console(short width, short height);
	~Console();

	void clearScreen();
	void preFrameUpdate();
	void postFrameUpdate();

	void write(std::string str, COORD c, int color = 0x07);
	void write(std::string str, int x, int y, int color = 0x07);
	
	int getWidth() const;
	int getHeight() const;
	int getPosX() const;
	int getPosY() const;
	void setConsoleTitle(std::string title);
private:

	void setConsoleSize();
	void disableResize();
	/// <summary>
	/// This function just makes it impossing for the user to click on the text in the terminal
	/// </summary>
	void disableQuickEdit();
	void setColor(int color);
	void moveTo(int x, int y);
	void toggleCursor();

	const COORD bufferSize;
	const HANDLE hConsole;
	const HWND hWindow;
	POINT windowPos;
};

#endif
