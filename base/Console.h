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
	void write(std::string str, COORD c, int color = 0x07);
	void write(std::string str, int x, int y, int color = 0x07);
	
	int getWidth() const;
	int getHeight() const;
private:

	void setConsoleSize();
	void disableResize();
	void setColor(int color);
	void moveTo(int x, int y);
	void toggleCursor();

	const COORD bufferSize;
	const HANDLE hConsole;
};

#endif
