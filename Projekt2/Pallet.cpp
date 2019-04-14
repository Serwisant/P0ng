#include "Pallet.h"

Pallet::Pallet(float x, sf::RenderWindow* window) : appWindow(window) {
	Point startPosition{ x, 334.F };
	Size sizeOfPallet{ 20.F, 100.F };
	sf::Vector2f graphicalSpriteSize(sizeOfPallet.width, sizeOfPallet.height);

	setPosition(startPosition);
	setSize(sizeOfPallet);

	dy = 0.F;

	palletSprite.setSize(graphicalSpriteSize);
	palletSprite.setFillColor(sf::Color::White);
}

void Pallet::movePallet(float dy) {
	this->dy = dy;
}

void Pallet::moveUp(float dy) {
	if (getY() + dy >= 0.F)
		Sprite::move(0, dy);
	else {
		setY(0.F);
	}
}

void Pallet::moveDown(float dy) {
	if (getBottom() + dy <= 768.F)
		Sprite::move(0, dy);
	else {
		setY(768.F - getHeight());
	}
}

void Pallet::update(float dt) {
	float movement = dy * dt;

	if (movement > 0.F)
		moveDown(movement);
	else if(movement < 0.F)
		moveUp(movement);

	dy = 0;
}

void Pallet::draw() {
	sf::Vector2f currentPosition(getX(), getY());

	palletSprite.setPosition(currentPosition);
	appWindow->draw(palletSprite);
}