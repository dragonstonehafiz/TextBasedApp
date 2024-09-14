#ifndef KEYBOARD_HANDLER_H_
#define KEYBOARD_HANDLER_H_

#include <Windows.h>

#define MAX_KEYS 256

class KeyboardHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();

	void preFrameUpdate();
	void postFrameUpdate();

	bool isKeyDown(unsigned char key);
	bool isKeyUp(unsigned char key);
	bool isKeyPressed(unsigned char key);
	bool isKeyReleased(unsigned char key);
	bool isAnyKeyPressed();
	bool isAnyKeyDown();
private:

	bool currState[MAX_KEYS], prevState[MAX_KEYS];
	bool anyKeyDown;
	bool anyKeyPressed;
};

#endif // !1

