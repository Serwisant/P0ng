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
	initializeBall();
	initializePallets();
	initializeScore();
	initializeCollisionChecker();
	initializeSoundPlayer();
	initializeAnalogSettings();
}

void Engine::initializeBall(){
	ball = new Ball(appWindow);
}

void Engine::initializePallets() {
	leftPallet = new Pallet(0.F, appWindow);
	rightPallet = new Pallet(1004.F, appWindow);
}

void Engine::initializeScore() {
	leftScoreNum = 0;
	rightScoreNum = 0;

	leftScore = new Numbers(Point{ 50.F, 50.F }, appWindow);
	rightScore = new Numbers(Point{ 924.F, 50.F }, appWindow);
}

void Engine::initializeCollisionChecker() {
	collisionChecker = new CollisionChecker();
}

void Engine::initializeSoundPlayer() {
	soundPlayer = new SoundPlayer();
}

void Engine::initializeAnalogSettings() {
	analogSensivity = 15.F;
	deadzone = 300.F;
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
	moveLeftPallet();
	moveRightPallet();
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
	moveLeftPallet();
	moveRightPallet();
}

void Engine::moveLeftPallet() {
	float leftAnalogY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) * analogSensivity;

	if (abs(leftAnalogY) > deadzone)
		leftPallet->movePallet(leftAnalogY);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		leftPallet->movePallet(-1500.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		leftPallet->movePallet(1500.F);
}

void Engine::moveRightPallet() {
	float rightAnalogY = sf::Joystick::getAxisPosition(0, sf::Joystick::R) * analogSensivity;

	if (abs(rightAnalogY) > deadzone)
		rightPallet->movePallet(rightAnalogY);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote))
		rightPallet->movePallet(-1500.F);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
		rightPallet->movePallet(1500.F);
}

void Engine::checkBallCollision() {
	checkBallCollisionWithUpperAndLowerBoundary();

	checkBallOutsideLeftSide();
	checkBallOutsideRightSide();
	
	checkBallWithLeftPalletCollision();
	checkBallWithRightPalletCollision();
}

void Engine::checkBallCollisionWithUpperAndLowerBoundary() {
	if (collisionChecker->isBallInCollisionWithUpperBound(ball) ||
		collisionChecker->isBallInCollisionWithLowerBound(ball))
		ball->bounceVertically();
}

void Engine::checkBallOutsideLeftSide() {
	if (collisionChecker->isBallOutsideLeft(ball)) {
		rightScoreNum++;
		resetBall();
	}
}

void Engine::checkBallOutsideRightSide() {
	if (collisionChecker->isBallOutsideRight(ball)) {
		leftScoreNum++;
		resetBall();
	}
}

void Engine::resetBall() {
	soundPlayer->playCrash();
	ball->reset();
}

void Engine::checkBallWithLeftPalletCollision() {
	if (collisionChecker->isBallInCollisionWithPallet(ball, leftPallet)
		&& ball->getVectorOfMovement().x < 0) {
		float leftPalletRightSide = leftPallet->getRightSide();

		ball->setX(leftPalletRightSide);

		bounceFromPallet();

		soundPlayer->playLowerSound();
	}
}

void Engine::checkBallWithRightPalletCollision(){
	if (collisionChecker->isBallInCollisionWithPallet(ball, rightPallet)
		&& ball->getVectorOfMovement().x > 0) {
		float rightPalletLeftSide = rightPallet->getX();
		float ballWidth = ball->getWidth();

		ball->setX(rightPalletLeftSide - ballWidth);

		bounceFromPallet();

		soundPlayer->playHigherSound();
	}
}

void Engine::bounceFromPallet() {
	ball->bounceHorizontally();
	ball->increaseSpeed(30.F);
}