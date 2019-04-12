#include "Ball.h"

Ball::Ball(sf::RenderWindow* window) : appWindow(window) {
	Size sizeOfBall{ 20.f, 20.f };
	sprite.setSize(sizeOfBall);

	reset();

	ballSprite.setSize(sf::Vector2f(sprite.getSize().width, sprite.getSize().heigth));
	ballSprite.setFillColor(sf::Color::White);
}

void Ball::update(float dt) {
	float xMovement = vectorOfMovement.x * speed * dt;
	float yMovement = vectorOfMovement.y * speed * dt;
	move(xMovement, yMovement);
}

void Ball::move(float dx, float dy) {
	sprite.move(dx, dy);
}

void Ball::draw() {
	float ballX = sprite.getPosition().x;
	float ballY = sprite.getPosition().y;

	ballSprite.setPosition(ballX, ballY);
	appWindow->draw(ballSprite);
}

void Ball::increaseSpeed(float ds) {
	speed += ds;
}

void Ball::bounceHorizontally() {
	vectorOfMovement.x *= -1.f;
}

void Ball::bounceVertically() {
	vectorOfMovement.y *= -1.f;
}

void Ball::reset() {
	Point startPosition{ 502.f, 374.f };
	speed = 150.f;

	sprite.setPosition(startPosition);

	srand(time(NULL));

	vectorOfMovement.x = (rand() % 100 < 50) ? 1.f : -1.f;
	vectorOfMovement.y = (rand() % 100 < 50) ? 1.f : -1.f;
}

Point Ball::getVectorOfMovement() {
	return vectorOfMovement;
}

Sprite& Ball::getSprite() {
	return sprite;
}