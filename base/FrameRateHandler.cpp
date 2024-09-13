#include "FrameRateHandler.h"
#include <Windows.h>

FrameRateHandler::FrameRateHandler(double targetFrameRate) :
	targetFrameRate(targetFrameRate), targetFrameTime(1000 / targetFrameRate),
	deltaTime(0),
	frameEndTime(clock_t()), frameStartTime(clock_t())
{
	
}
FrameRateHandler::~FrameRateHandler()
{

}
void FrameRateHandler::startOfFrame()
{
	frameStartTime = clock();
}
void FrameRateHandler::endOfFrame()
{
	frameEndTime = clock();

	// This code makes sure the program meets the set frame rate
	// basically, it checks how much time has passed for the current frame and compares it to the target frame time
	// if the time passed is less than the target frame time, 
	// we have to make the program stop for however long it needs to make sure it meets the frame time.
	double elapsedTime = frameEndTime - frameStartTime;
	if (elapsedTime < targetFrameTime)
		Sleep(targetFrameTime - elapsedTime);

	// We set this variable so we can get the true frame rate if we want to
	deltaTime = elapsedTime > targetFrameTime ? elapsedTime : targetFrameTime;
}

double FrameRateHandler::getTrueFrameRate()
{
	return 1000 / deltaTime;
}
double FrameRateHandler::getDeltaTime()
{
	return deltaTime;
}