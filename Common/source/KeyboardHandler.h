#ifndef KEYBOARD_HANDLER_H_
#define KEYBOARD_HANDLER_H_

#include <Windows.h>
#include "SingletonTemplate.h"

#define MAX_KEYS 256

class KeyboardHandler
	: public Singleton<KeyboardHandler>
{
	friend Singleton<KeyboardHandler>;
public:
	void preFrameUpdate();
	void postFrameUpdate();

	bool isKeyDown(unsigned char key);
	bool isKeyUp(unsigned char key);
	bool isKeyPressed(unsigned char key);
	bool isKeyReleased(unsigned char key);
	bool isAnyKeyPressed();
	bool isAnyKeyDown();
private:
	KeyboardHandler();
	~KeyboardHandler();

	bool currState[MAX_KEYS], prevState[MAX_KEYS];
	bool anyKeyDown;
	bool anyKeyPressed;
};

#endif // !1

