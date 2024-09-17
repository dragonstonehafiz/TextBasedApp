#ifndef OBJECT_BASE_H_
#define OBJECT_BASE_H_

class ObjectBase
{
public:
	ObjectBase();
	~ObjectBase();

	void setPos(int _x, int _y);
	void setX(int _x);
	int getX() const;
	void setY(int _y);
	int getY() const;

	bool getActive() const;
	void setActive(bool _active);
	bool getShow() const;
	void setShow(bool _show);

	virtual void update(double dt) = 0;
	virtual void render() = 0;
protected:
	int x, y;
	bool active, show;
};

#endif // !OBJECT_BASE_H_
