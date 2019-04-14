#include "Sprite.h"

Sprite::Sprite() {
	setPosition(Point{ 0.F, 0.F });

	size.width = 0;
	size.height = 0;
}

Sprite::Sprite(Size size) : size(size) {
	
}

Sprite::Sprite(Point position, Size size) : position(position), size(size) {
	
}


void Sprite::setPosition(Point point) {
	position = point;
}

void Sprite::setX(float x) {
	position.x = x;
}

void Sprite::setY(float y) {
	position.y = y;
}

void Sprite::setSize(Size size) {
	this->size = size;
}

void Sprite::move(float dx, float dy) {
	position.x += dx;
	position.y += dy;
}

float Sprite::getX() {
	return position.x;
}

float Sprite::getY() {
	return position.y;
}

float Sprite::getWidth() {
	return size.width;
}

float Sprite::getHeight() {
	return size.height;
}

float Sprite::getRightSide() {
	return position.x + size.width;
}

float Sprite::getBottom() {
	return position.y + size.height;
}
