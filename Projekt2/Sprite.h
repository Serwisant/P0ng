#ifndef SPRITE_H
#define SPRITE_H

#include "Point.h"
#include "Size.h"

class Sprite {
public:
	Sprite();
	Sprite(Size size);
	Sprite(Point position, Size size);

	void setPosition(Point point);
	void setX(float x);
	void setY(float y);
	void setSize(Size size);
	void move(float dx, float dy);

	Point getPosition();
	Size getSize();

	float getRightSide();
	float getBottom();

private:
	Point position;
	Size size;
};

#endif
