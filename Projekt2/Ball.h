#ifndef BALL_H
#define BALL_H

#include <SFML\Graphics.hpp>
#include "Size.h"
#include "Point.h"
#include "Sprite.h"

class Ball : public Sprite {
public:
	explicit Ball(sf::RenderWindow* window);
	void update(float dt);
	void move(float dx, float dy);
	void draw();
	void increaseSpeed(float ds);
	void bounceHorizontally();
	void bounceVertically();
	void reset();

	Point getVectorOfMovement();
	float getSpeed();

private:
	float speed;
	Point vectorOfMovement;
	sf::RectangleShape ballSprite;

	sf::RenderWindow* appWindow;
};

#endif