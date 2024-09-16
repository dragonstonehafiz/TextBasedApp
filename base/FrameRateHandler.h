#ifndef FRAME_RATE_HANDLER_H_
#define FRAME_RATE_HANDLER_H_

#include <ctime>
#include "SingletonTemplate.h"
#include <string>

class FrameRateHandler
	: public Singleton<FrameRateHandler>
{
	friend Singleton<FrameRateHandler>;
public:
	void startOfFrame();
	void endOfFrame();

	void setTargetFramerate(double targetFrameRate);
	double getTrueFrameRate() const;
	std::string getFPS_str() const;
	double getDeltaTime() const;
private:
	FrameRateHandler();
	~FrameRateHandler();
	double getDeltaTime_ms() const;

	double targetFrameRate;
	double targetFrameTime;
	double deltaTime;
	clock_t frameStartTime;
	clock_t frameEndTime;
};


#endif // !FRAME_RATE_HANDLER_H_

