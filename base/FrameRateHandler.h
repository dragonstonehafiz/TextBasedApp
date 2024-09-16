#ifndef FRAME_RATE_HANDLER_H_
#define FRAME_RATE_HANDLER_H_

#include "SingletonTemplate.h"
#include <string>
#include <chrono>

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

	/// <summary>
	/// Frame rate we want.
	/// </summary>
	double targetFrameRate;
	/// <summary>
	/// How long a single frame should last (in milliseconds because sleep is alos in milliseconds)
	/// </summary>
	double targetFrameTime;
	/// <summary>
	/// The time between the start of this frame and the start of the frame before.
	/// </summary>
	double deltaTime;
	/// <summary>
	/// The time between the start of this frame and the end of this frame. This is used 
	/// </summary>
	double frameDuration;
	std::chrono::time_point<std::chrono::high_resolution_clock> frameStartTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> frameEndTime;
};


#endif // !FRAME_RATE_HANDLER_H_

