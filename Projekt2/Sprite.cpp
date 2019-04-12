#include "Sprite.h"

Sprite::Sprite() {
	setPosition(Point{ 0.f, 0.f });

	size.width = 0;
	size.heigth = 0;
}

Sprite::Sprite(Size size) {
	this->size = size;
}

Sprite::Sprite(Point position, Size size) {
	this->position = position;
	this->size = size;
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


Point Sprite::getPosition() {
	return position;
}

Size Sprite::getSize() {
	return size;
}

float Sprite::getRightSide() {
	return position.x + size.width;
}

float Sprite::getBottom() {
	return position.y + size.heigth;
}
