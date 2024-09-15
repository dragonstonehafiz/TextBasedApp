#ifndef APPLICATON_H_
#define APPLICATION_H_

#include "FrameRateHandler.h"
#include "Console.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "SingletonTemplate.h"

class Application
	: public Singleton<Application>
{
	friend Singleton<Application>;
public:
	void init();
	void mainloop();

	double getDeltaTime();
	FrameRateHandler* getFPSHandler();
	Console* getConsoleHandler();
	KeyboardHandler* getKeyboardHandler();
	MouseHandler* getMouseHandler();
private:
	Application();
	~Application();

	void PreFrameUpdate();
	void PostFrameUpdate();
	void Update();

	FrameRateHandler *fpsHandler;
	Console* consoleHandler;
	KeyboardHandler* keyboardHandler;
	MouseHandler* mouseHandler;
};

#endif // !APPLICATON_H_




