#ifndef APPLICATON_H_
#define APPLICATION_H_

#include "FrameRateHandler.h"
#include "SingletonTemplate.h"

class Application
	: public Singleton<Application>
{
	friend Singleton<Application>;
public:
	void init();
	void mainloop();

	double getDeltaTime();
	FrameRateHandler * getFPSHandler();
private:
	Application();
	~Application();

	void PreFrameUpdate();
	void PostFrameUpdate();
	void Update();

	FrameRateHandler *fpsHandler;
};

#endif // !APPLICATON_H_




