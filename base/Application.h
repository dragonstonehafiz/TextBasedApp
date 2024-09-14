#ifndef APPLICATON_H_
#define APPLICATION_H_

#include "FrameRateHandler.h"
#include "Console.h"
#include "KeyboardHandler.h"
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
private:
	Application();
	~Application();

	void PreFrameUpdate();
	void PostFrameUpdate();
	void Update();

	FrameRateHandler *fpsHandler;
	Console* consoleHandler;
	KeyboardHandler* keyboardHandler;
};

#endif // !APPLICATON_H_




