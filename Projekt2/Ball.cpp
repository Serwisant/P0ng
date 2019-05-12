#include <random>
#include "Ball.h"

Ball::Ball() {
	appWindow = nullptr;
	reset();
}

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
	if (appWindow == nullptr)
		return;
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

	std::default_random_engine dre;
	std::uniform_int_distribution<int> distribution(0, 3);

	switch (distribution(dre))
	{
	case 0:
		vectorOfMovement.x = -INITIALSPEED;
		vectorOfMovement.y = -INITIALSPEED;
		break;
	case 1:
		vectorOfMovement.x = INITIALSPEED;
		vectorOfMovement.y = -INITIALSPEED;
		break;
	case 2:
		vectorOfMovement.x = -INITIALSPEED;
		vectorOfMovement.y = INITIALSPEED;
		break;
	case 3:
		vectorOfMovement.x = INITIALSPEED;
		vectorOfMovement.y = INITIALSPEED;
		break;
	default:
		break;
	}
}

Point Ball::getVectorOfMovement() {
	return vectorOfMovement;
}

float Ball::getSpeed() {
	return speed;
}