#ifndef APPLICATON_H_
#define APPLICATION_H_

#include "FrameRateHandler.h"
#include "Console.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "SceneManager.h"
#include "SingletonTemplate.h"

class Application
	: public Singleton<Application>
{
	friend Singleton<Application>;
public:
	void init();
	void mainloop();

	void quit();
private:
	Application();
	~Application();

	void PreFrameUpdate();
	void PostFrameUpdate();
	void Update();
	void RenderInfo();

	FrameRateHandler *fpsHandler;
	Console* consoleHandler;
	KeyboardHandler* keyboardHandler;
	MouseHandler* mouseHandler;
	SceneManager* sceneManager;

	bool isRunning;
	double runTime;
};

#endif // !APPLICATON_H_