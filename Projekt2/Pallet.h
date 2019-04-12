#ifndef PALLET_H
#define PALLET_H

#include <SFML\Graphics.hpp>
#include "Size.h"
#include "Point.h"
#include "Sprite.h"

class Pallet {
public:
	Pallet(float x, sf::RenderWindow* window);
	void move(float dy);
	void update(float dt);
	void draw();
	
	Sprite getSprite();

private:
	Sprite sprite;
	float dy;
	sf::RectangleShape palletSprite;

	sf::RenderWindow* appWindow;

	void moveUp(float dy);
	void moveDown(float dy);
};

#endif
