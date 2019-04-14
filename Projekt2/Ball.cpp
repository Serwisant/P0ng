#include "Ball.h"

Ball::Ball(sf::RenderWindow* window) : appWindow(window) {
	Size sizeOfBall{ 20.F, 20.F };
	setSize(sizeOfBall);

	reset();

	ballSprite.setSize(sf::Vector2f(getWidth(), getHeight()));
	ballSprite.setFillColor(sf::Color::White);
}

void Ball::update(float dt) {
	float xMovement = vectorOfMovement.x * speed * dt;
	float yMovement = vectorOfMovement.y * speed * dt;
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
	speed += ds;
}

void Ball::bounceHorizontally() {
	vectorOfMovement.x *= -1.F;
}

void Ball::bounceVertically() {
	vectorOfMovement.y *= -1.F;
}

void Ball::reset() {
	Point startPosition{ 502.F, 374.F };
	speed = 300.F;

	setPosition(startPosition);

	srand(time(NULL));

	vectorOfMovement.x = (rand() % 100 < 50) ? 1.F : -1.F;
	vectorOfMovement.y = (rand() % 100 < 50) ? 1.F : -1.F;
}

Point Ball::getVectorOfMovement() {
	return vectorOfMovement;
}
