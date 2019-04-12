#include "CollisionChecker.h"
#include "Ball.h"
#include "Pallet.h"

bool CollisionChecker::checkBallWithPalletCollision(Ball* ball, Pallet* pallet) {
	float ballX = ball->getSprite().getPosition().x;
	float ballY = ball->getSprite().getPosition().y;
	float ballRightSide = ball->getSprite().getRightSide();
	float ballBottom = ball->getSprite().getBottom();

	float palletX = pallet->getSprite().getPosition().x;
	float palletY = pallet->getSprite().getPosition().y;
	float palletRightSide = pallet->getSprite().getRightSide();
	float palletBottom = pallet->getSprite().getBottom();

	float predictedLeftSideOfBall = ballX + ball->getVectorOfMovement().x;
	float predictedRightSideOfBall = ballRightSide + ball->getVectorOfMovement().x;
	float predictedTopOfBall = ballY + ball->getVectorOfMovement().y;
	float predictedBottomOfBall = ballBottom + ball->getVectorOfMovement().y;

	if (predictedRightSideOfBall > palletX && predictedLeftSideOfBall < palletRightSide &&
		predictedBottomOfBall > palletY && predictedTopOfBall < palletBottom) {

		if (ball->getVectorOfMovement().x < 0.f)
			ball->getSprite().setX(palletRightSide);
		else
			ball->getSprite().setX(palletX - ball->getSprite().getSize().width);

		ball->bounceHorizontally();
		ball->increaseSpeed(30.F);

		return true;
	}
}

void CollisionChecker::checkBallWithUpperBoundCollision(Ball* ball) {
	float predictedYPosition = ball->getSprite().getPosition().y + ball->getVectorOfMovement().y;

	if (predictedYPosition <= 0)
		ball->bounceVertically();
}

void CollisionChecker::checkBallWithLowerBoundCollision(Ball* ball) {
	float ballY = ball->getSprite().getPosition().y;
	float ballHeigth = ball->getSprite().getSize().heigth;
	float predictedYPosition = ballY + ballHeigth + ball->getVectorOfMovement().y;

	if (predictedYPosition >= 768.F)
		ball->bounceVertically();
}

bool CollisionChecker::isBallOutsideLeft(Ball* ball) {
	float ballX = ball->getSprite().getPosition().x;
	float ballWidth = ball->getSprite().getSize().width;

	return ballX < (-ballWidth);
}

bool CollisionChecker::isBallOutsideRight(Ball* ball) {
	float ballX = ball->getSprite().getPosition().x;
	float ballWidth = ball->getSprite().getSize().width;

	return ballX > 1024.F + ballWidth;
}
