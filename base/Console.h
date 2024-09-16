#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <Windows.h>
#include <string>
#include "SingletonTemplate.h"

class Console
	: public Singleton<Console>
{
	friend Singleton<Console>;
public:
	void init(short width, short height);
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
	Console();
	~Console();

	void setConsoleSize();
	void disableResize();
	/// <summary>
	/// This function just makes it impossing for the user to click on the text in the terminal
	/// </summary>
	void disableQuickEdit();
	void setColor(int color);
	void moveTo(int x, int y);
	void toggleCursor();

	COORD bufferSize;
	HANDLE hConsole;
	HWND hWindow;
	POINT windowPos;
};

#endif
