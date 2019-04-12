#ifndef ENGINE_H
#define ENGINE_H

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class Ball;
class Pallet;
class Numbers;
class CollisionChecker;
class SoundPlayer;

class Engine {
public:
	Engine(sf::RenderWindow* window);
	~Engine();

	void updateLoop(float dt);
	void draw();

private:
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

	void movePallets();
	void checkBallCollision();
};

#endif ENGINE_H
