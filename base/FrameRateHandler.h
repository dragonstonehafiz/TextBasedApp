#ifndef FRAME_RATE_HANDLER_H_
#define FRAME_RATE_HANDLER_H_

#include <ctime>
#include "SingletonTemplate.h"


class FrameRateHandler
	: public Singleton<FrameRateHandler>
{
	friend Singleton<FrameRateHandler>;
public:
	void setTargetFramerate(double targetFrameRate);
	void startOfFrame();
	void endOfFrame();
	double getTrueFrameRate();
	double getDeltaTime();
private:
	FrameRateHandler();
	~FrameRateHandler();

	double targetFrameRate;
	double targetFrameTime;
	double deltaTime;
	clock_t frameStartTime;
	clock_t frameEndTime;
};


#endif // !FRAME_RATE_HANDLER_H_

