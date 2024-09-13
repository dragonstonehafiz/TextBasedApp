#ifndef FRAME_RATE_HANDLER_H_
#define FRAME_RATE_HANDLER_H_

#include <ctime>
#include "SingletonTemplate.h"

class FrameRateHandler
{
public:
	FrameRateHandler(double targetFrameRate);
	~FrameRateHandler();

	void startOfFrame();
	void endOfFrame();
	double getTrueFrameRate();
	double getDeltaTime();
private:

	const double targetFrameRate;
	const double targetFrameTime;
	double deltaTime;
	clock_t frameStartTime;
	clock_t frameEndTime;
};


#endif // !FRAME_RATE_HANDLER_H_

