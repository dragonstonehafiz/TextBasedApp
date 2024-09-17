#include "FrameRateHandler.h"
#include <Windows.h>
#include "StringHelper.h"

FrameRateHandler::FrameRateHandler() :
	targetFrameRate(59.94), 
	targetFrameTime(1000 / targetFrameRate),
	deltaTime(0),
	frameDuration(0)
{
	frameStartTime = std::chrono::high_resolution_clock::now();
	frameEndTime = std::chrono::high_resolution_clock::now();
}
FrameRateHandler::~FrameRateHandler()
{
}

void FrameRateHandler::startOfFrame()
{
	// delta time is the time between this frame and the previous frame,
	// NOT the time between this frame and this frame's end. (i think)
	auto prevFrameStartTime = frameStartTime;
	frameStartTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedTime = frameStartTime - prevFrameStartTime;
	deltaTime = elapsedTime.count();
}
void FrameRateHandler::endOfFrame()
{
	frameEndTime = std::chrono::high_resolution_clock::now();

	// This code makes sure the program meets the set frame rate
	// basically, it checks how much time has passed for the current frame and compares it to the target frame time
	// if the time passed is less than the target frame time, 
	// we have to make the program stop for however long it needs to make sure it meets the frame time
	std::chrono::duration<double, std::milli> frameTime = (frameEndTime - frameStartTime);
	double frameTimeMS = frameTime.count();
	if (frameTimeMS < targetFrameTime)
		Sleep(targetFrameTime - frameTimeMS);

	frameDuration = frameTimeMS > targetFrameTime ? frameTimeMS : targetFrameTime;
	frameDuration /= 1000.f;
}

void FrameRateHandler::setTargetFramerate(double targetFrameRate)
{
	this->targetFrameRate = targetFrameRate;
	targetFrameTime = 1000 / targetFrameRate;
}
double FrameRateHandler::getTrueFrameRate() const
{
	return 1.f / frameDuration;
}
std::string FrameRateHandler::getFPS_str() const
{
	std::string output = format("%.2f", (float)getTrueFrameRate());
	output += "fps";
	return output;
}
double FrameRateHandler::getDeltaTime() const
{
	return deltaTime;
}