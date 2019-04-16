#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class TitleScreen;
class Ball;
class Pallet;
class Numbers;
class CollisionChecker;
class SoundPlayer;

class Engine {
public:
	explicit Engine(sf::RenderWindow* window);
	~Engine();

	void startGame();
	void updateLoop(float dt);
	void draw();

private:
	enum MODE {TITLE_SCREEN, PLAY};

	MODE currentMode;

	TitleScreen* titleScreen;

	Ball* ball;
	Pallet* leftPallet;
	Pallet* rightPallet;
	Numbers* leftScore;
	Numbers* rightScore;

	CollisionChecker* collisionChecker;

	sf::RenderWindow* appWindow;

	SoundPlayer* soundPlayer;

	int leftScoreNum;
	int rightScoreNum;

	void resetGame();

	void initializeTitleScreen();
	void initializeMode();
	void initializeBall();
	void initializePallets();
	void initializeScore();
	void initializeCollisionChecker();
	void initializeSoundPlayer();
	void initializeAnalogSettings();

	float analogSensivity;
	float deadzone;

	void moveLeftPallet(float dt);
	void moveRightPallet(float dt);
	
	void checkBallCollision();
	void checkBallCollisionWithUpperAndLowerBoundary();
	void checkBallOutsideLeftSide();
	void checkBallOutsideRightSide();
	void checkBallWithLeftPalletCollision();
	void checkBallWithRightPalletCollision();

	void addScoreToLeftPlayer();
	void addScoreToRightPlayer();

	void checkWinner();

	void resetBall();
	void bounceFromPallet();
};

#endif ENGINE_H
