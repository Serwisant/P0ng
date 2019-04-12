#include "Engine.h"
#include "Ball.h"
#include "Pallet.h"
#include "Size.h"
#include "Point.h"
#include "numbers.h"
#include "CollisionChecker.h"
#include "SoundPlayer.h"
#include <SFML/System.hpp>

Engine::Engine(sf::RenderWindow* window) : appWindow(window) {
	ball = new Ball(window);
	leftPallet = new Pallet(0.f, window);
	rightPallet = new Pallet(1004.f, window);
	leftScore = new Numbers(Point{ 50.f, 50.f }, window);
	rightScore = new Numbers(Point{ 924.f, 50.f }, window);

	collisionChecker = new CollisionChecker();

	soundPlayer = new SoundPlayer();

	leftScoreNum = 0;
	rightScoreNum = 0;
}

Engine::~Engine() {
	delete ball;

	delete leftPallet;
	delete rightPallet;

	delete leftScore;
	delete rightScore;

	delete collisionChecker;

	delete soundPlayer;
}

void Engine::updateLoop(float dt) {
	movePallets();
	checkBallCollision();

	leftPallet->update(dt);
	rightPallet->update(dt);
	ball->update(dt);
}

void Engine::draw() {
	ball->draw();
	leftPallet->draw();
	rightPallet->draw();
	leftScore->drawNumber(leftScoreNum);
	rightScore->drawNumber(rightScoreNum);
}


void Engine::movePallets() {
	float analogSensivity = 15.F;
	float deadzone = 300.F;

	float leftAnalogY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) * analogSensivity;
	float rightAnalogY = sf::Joystick::getAxisPosition(0, sf::Joystick::R) * analogSensivity;

	if (abs(leftAnalogY) > deadzone)
		leftPallet->move(leftAnalogY);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		leftPallet->move(-1500.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		leftPallet->move(1500.F);

	if (abs(rightAnalogY) > deadzone)
		rightPallet->move(rightAnalogY);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote))
		rightPallet->move(-1500.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
		rightPallet->move(1500.F);
}

void Engine::checkBallCollision() {
	collisionChecker->checkBallWithUpperBoundCollision(ball);
	collisionChecker->checkBallWithLowerBoundCollision(ball);

	if (collisionChecker->isBallOutsideLeft(ball)) {
		rightScoreNum++;
		soundPlayer->playCrash();
		ball->reset();
	}

	if (collisionChecker->isBallOutsideRight(ball)) {
		leftScoreNum++;
		soundPlayer->playCrash();
		ball->reset();
	}

	if (collisionChecker->checkBallWithPalletCollision(ball, leftPallet))
		soundPlayer->playLowerSound();

	if (collisionChecker->checkBallWithPalletCollision(ball, rightPallet))
		soundPlayer->playHigherSound();
}