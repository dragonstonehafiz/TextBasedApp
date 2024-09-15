#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler():
	anyKeyDown(false),
	anyKeyPressed(false)
{
	for (int i = 0; i < MAX_KEYS; ++i)
	{
		currState[i] = false;
		prevState[i] = false;
	}
}
KeyboardHandler::~KeyboardHandler()
{

}
 
void KeyboardHandler::preFrameUpdate()
{
	// Basically, at the start of every frame, we check the state of each key
	// However, before doing that, we make sure to track the previous state of that key
	// By storing both the previous and the current state, we can get more specific input information
	anyKeyDown = false;
	anyKeyPressed = false;
	for (int i = 0; i < MAX_KEYS; ++i)
	{
		prevState[i] = currState[i];
		currState[i] = GetAsyncKeyState(i) & 0x8000;
		if (currState[i])
		{
			// If the key was not down in the previous frame, and is down now, that means the user just pressed it
			if (!prevState[i])
				anyKeyPressed = true;
			else
				anyKeyDown = true;
		}
	}
}
void KeyboardHandler::postFrameUpdate()
{

}

bool KeyboardHandler::isKeyDown(unsigned char key)
{
	if (key >= MAX_KEYS)
		return false;
	return currState[key];
}
bool KeyboardHandler::isKeyUp(unsigned char key)
{
	if (key >= MAX_KEYS)
		return false;
	return !currState[key];
}
bool KeyboardHandler::isKeyPressed(unsigned char key)
{
	if (key >= MAX_KEYS)
		return false;
	// if key was up in the previous frame but is down now
	return !prevState[key] && currState[key];
}
bool KeyboardHandler::isKeyReleased(unsigned char key)
{
	if (key >= MAX_KEYS)
		return false;
	// if the key was up in the previous frame but is down now
	return prevState[key] && !currState[key];
}
bool KeyboardHandler::isAnyKeyPressed()
{
	return anyKeyPressed;
}
bool KeyboardHandler::isAnyKeyDown()
{
	return anyKeyDown;
}
