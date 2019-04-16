#include "Ball.h"

Ball::Ball(sf::RenderWindow* window) : appWindow(window) {
	Size sizeOfBall{ 20.F, 20.F };
	setSize(sizeOfBall);

	reset();

	ballSprite.setSize(sf::Vector2f(getWidth(), getHeight()));
	ballSprite.setFillColor(sf::Color::White);
}

void Ball::update(float dt) {
	float xMovement = vectorOfMovement.x * dt;
	float yMovement = vectorOfMovement.y * dt;
	move(xMovement, yMovement);
}

void Ball::move(float dx, float dy) {
	Sprite::move(dx, dy);
}

void Ball::draw() {
	ballSprite.setPosition(getX(), getY());
	appWindow->draw(ballSprite);
}

void Ball::increaseSpeed(float ds) {
	if (vectorOfMovement.x > 0)
		vectorOfMovement.x += ds;
	else if (vectorOfMovement.x < 0)
		vectorOfMovement.x -= ds;

	if (vectorOfMovement.y > 0)
		vectorOfMovement.y += ds;
	else if(vectorOfMovement.y < 0)
		vectorOfMovement.y -= ds;
}

void Ball::bounceHorizontally() {
	vectorOfMovement.x *= -1.F;
}

void Ball::bounceVertically() {
	vectorOfMovement.y *= -1.F;
}

void Ball::reset() {
	Point startPosition{ 502.F, 374.F };
	const float INITIALSPEED = 300.F;

	setPosition(startPosition);

	srand(time(NULL));

	vectorOfMovement.x = (rand() % 100 < 50) ? INITIALSPEED : -INITIALSPEED;
	vectorOfMovement.y = (rand() % 100 < 50) ? INITIALSPEED : -INITIALSPEED;
}

Point Ball::getVectorOfMovement() {
	return vectorOfMovement;
}

float Ball::getSpeed() {
	return speed;
}