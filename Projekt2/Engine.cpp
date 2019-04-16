#include "Engine.h"
#include "TitleScreen.h"
#include "Ball.h"
#include "Pallet.h"
#include "Size.h"
#include "Point.h"
#include "numbers.h"
#include "CollisionChecker.h"
#include "SoundPlayer.h"
#include <SFML/System.hpp>

Engine::Engine(sf::RenderWindow* window) : appWindow(window) {
	initializeTitleScreen();
	initializeMode();
	initializeBall();
	initializePallets();
	initializeScore();
	initializeCollisionChecker();
	initializeSoundPlayer();
	initializeAnalogSettings();
}

void Engine::initializeTitleScreen() {
	titleScreen = new TitleScreen(appWindow);
}

void Engine::initializeMode() {
	currentMode = MODE::TITLE_SCREEN;
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
	delete titleScreen;

	delete ball;

	delete leftPallet;
	delete rightPallet;

	delete leftScore;
	delete rightScore;

	delete collisionChecker;

	delete soundPlayer;
}

void Engine::startGame() {
	currentMode = MODE::PLAY;
	resetGame();
}

void Engine::resetGame() {
	leftScoreNum = 0;
	rightScoreNum = 0;

	delete leftPallet;
	delete rightPallet;

	initializePallets();
}

void Engine::updateLoop(float dt) {
	if (currentMode == MODE::TITLE_SCREEN) {
		titleScreen->update(dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			startGame();
	}
	else {
		collisionChecker->setDeltaTime(dt);

		moveLeftPallet(dt);
		moveRightPallet(dt);
		checkBallCollision();

		leftPallet->update(dt);
		rightPallet->update(dt);
		ball->update(dt);

		checkWinner();
	}
}

void Engine::draw() {
	if (currentMode == MODE::TITLE_SCREEN) {
		titleScreen->draw();	
	}
	else {
		ball->draw();
		leftPallet->draw();
		rightPallet->draw();
		leftScore->drawNumber(leftScoreNum);
		rightScore->drawNumber(rightScoreNum);
	}
}


void Engine::moveLeftPallet(float dt) {
	float leftAnalogY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) * analogSensivity;

	if (abs(leftAnalogY) > deadzone)
		leftPallet->movePallet(leftAnalogY);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		leftPallet->movePallet(-1500.F );
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		leftPallet->movePallet(1500.F);
}

void Engine::moveRightPallet(float dt) {
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
		addScoreToRightPlayer();
		resetBall();
	}
}

void Engine::checkBallOutsideRightSide() {
	if (collisionChecker->isBallOutsideRight(ball)) {
		addScoreToLeftPlayer();
		resetBall();
	}
}

void Engine::addScoreToLeftPlayer() {
	leftScoreNum++;
}

void Engine::addScoreToRightPlayer() {
	rightScoreNum++;
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
	ball->increaseSpeed(75.F);
}

void Engine::checkWinner() {
	if (leftScoreNum >= 10) {
		titleScreen->setWinner(TitleScreen::WINNER::LEFT_PALLET);
		currentMode = MODE::TITLE_SCREEN;
	}
	if (rightScoreNum >= 10) {
		titleScreen->setWinner(TitleScreen::WINNER::RIGHT_PALLET);
		currentMode = MODE::TITLE_SCREEN;
	}
}