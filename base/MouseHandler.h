#ifndef MOUSE_HANDLER_H_
#define MOUSE_HANDLER_H_

#define MAX_MOUSE 3
#define MOUSE_LEFT 0
#define MOUSE_RIGHT 1
#define MOUSE_MIDDLE 2

#include <Windows.h>
#include "Console.h"
#include "SingletonTemplate.h"

class MouseHandler
	: public Singleton<MouseHandler>
{
	friend Singleton<MouseHandler>;
public:
	void preFrameUpdate();
	void postFrameUpdate();

	POINT getMousePos() const;
	int getMousePosX() const;
	int getMousePosY() const;
	
	/// <summary>
	/// MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE
	/// </summary>	
	bool isMouseDown(int mouse);
	/// <summary>
	/// MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE
	/// </summary>	
	bool isMouseUp(int mouse);
	/// <summary>
	/// MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE
	/// </summary>	
	bool isMousePressed(int mouse);
	/// <summary>
	/// MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE
	/// </summary>	
	bool isMouseReleased(int mouse);
private:
	MouseHandler();
	~MouseHandler();

	void calcRelativeMousePos();

	bool currState[MAX_MOUSE], prevState[MAX_MOUSE];
	POINT trueMousePos, relMousePos;
	Console* consoleHandler;
};

#endif // !MOUSE_HANDLER_H_
