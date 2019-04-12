#include "Pallet.h"

Pallet::Pallet(float x, sf::RenderWindow* window) : appWindow(window) {
	Point startPosition{ x, 334.F };
	Size sizeOfPallet{ 20.F, 100.F };
	sf::Vector2f graphicalSpriteSize(sizeOfPallet.width, sizeOfPallet.heigth);

	sprite.setPosition(startPosition);
	sprite.setSize(sizeOfPallet);

	dy = 0.F;

	palletSprite.setSize(graphicalSpriteSize);
	palletSprite.setFillColor(sf::Color::White);
}

void Pallet::move(float dy) {
	this->dy = dy;
}

void Pallet::moveUp(float dy) {
	if (sprite.getPosition().y + dy >= 0.F)
		sprite.move(0.f, dy);
	else {
		sprite.setY(0.f);
	}
}

void Pallet::moveDown(float dy) {
	if (sprite.getBottom() + dy <= 768.F)
		sprite.move(0.F, dy);
	else {
		sprite.setY(768.F - sprite.getSize().heigth);
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
	sf::Vector2f currentPosition(sprite.getPosition().x, sprite.getPosition().y);

	palletSprite.setPosition(currentPosition);
	appWindow->draw(palletSprite);
}

Sprite Pallet::getSprite() {
	return sprite;
}