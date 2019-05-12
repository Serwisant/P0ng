#ifndef PALLET_H
#define PALLET_H

#include <SFML\Graphics.hpp>
#include "Size.h"
#include "Point.h"
#include "Sprite.h"

class Pallet : public Sprite {
public:
	Pallet();
	explicit Pallet(float x);
	Pallet(float x, sf::RenderWindow* window);
	void movePallet(float dy);
	void update(float dt);
	void draw();

private:
	float dy;
	sf::RectangleShape palletSprite;

	sf::RenderWindow* appWindow;

	void moveUp(float dy);
	void moveDown(float dy);

	void reset();
	Point startPosition;
};

#endif
