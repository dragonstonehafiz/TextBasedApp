#include "ObjectBase.h"

ObjectBase::ObjectBase(): 
	x(0), y(0),
	active(true), show(false)
{

}
ObjectBase::~ObjectBase()
{

}

void ObjectBase::setPos(int _x, int _y)
{
	x = _x;
	y = _y;
}
void ObjectBase::setX(int _x)
{
	x = _x;
}
int ObjectBase::getX() const
{
	return x;
}
void ObjectBase::setY(int _y)
{
	y = _y;
}
int ObjectBase::getY() const
{
	return y;
}

bool ObjectBase::getActive() const
{
	return active;
}
void ObjectBase::setActive(bool _active)
{
	active = _active;
}
bool ObjectBase::getShow() const
{
	return show;
}
void ObjectBase::setShow(bool _show)
{
	show = _show;
}