#include "MouseHandler.h"

MouseHandler::MouseHandler(Console* _consoleHandler) :
	trueMousePos{ 0, 0 },
	relMousePos{ 0, 0 },
	consoleHandler(_consoleHandler)
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
	calcRelativeMousePos();
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
	return relMousePos;
}
int MouseHandler::getMousePosX() const
{
	return relMousePos.x;
}
int MouseHandler::getMousePosY() const
{
	return relMousePos.y;
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

void MouseHandler::calcRelativeMousePos()
{
	GetCursorPos(&trueMousePos);
	relMousePos.x = trueMousePos.x - consoleHandler->getPosX();
	relMousePos.y = trueMousePos.y - consoleHandler->getPosY();
}
