#include "MouseHandler.h"

MouseHandler::MouseHandler() :
	mousePos{ 0, 0 }
{
	for (int i = 0; i < MAX_MOUSE; ++i)
	{
		prevState[i] = false;
		currState[i] = false;
	}
}
MouseHandler::~MouseHandler()
{

}

void MouseHandler::preFrameUpdate()
{
	GetCursorPos(&mousePos);
	prevState[MOUSE_LEFT] = currState[MOUSE_LEFT];
	currState[MOUSE_LEFT] = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
	prevState[MOUSE_RIGHT] = currState[MOUSE_RIGHT];
	currState[MOUSE_RIGHT] = GetAsyncKeyState(VK_RBUTTON) & 0x8000;
	prevState[MOUSE_MIDDLE] = currState[MOUSE_MIDDLE];
	currState[MOUSE_MIDDLE] = GetAsyncKeyState(VK_MBUTTON) & 0x8000;
}
void MouseHandler::postFrameUpdate()
{
}

POINT MouseHandler::getMousePos() const
{
	return mousePos;
}
int MouseHandler::getMousePosX() const
{
	return mousePos.x;
}
int MouseHandler::getMousePosY() const
{
	return mousePos.y;
}

bool MouseHandler::isMouseDown(int mouse)
{
	if (mouse >= MAX_MOUSE)
		return false;
	return currState[mouse];
}
bool MouseHandler::isMouseUp(int mouse)
{
	if (mouse >= MAX_MOUSE)
		return false;
	return !currState[mouse];
}
bool MouseHandler::isMousePressed(int mouse)
{
	if (mouse >= MAX_MOUSE)
		return false;
	return !prevState[mouse] && currState[mouse];
}
bool MouseHandler::isMouseReleased(int mouse)
{
	if (mouse >= MAX_MOUSE)
		return false;
	return prevState[mouse] && !currState[mouse];
}
