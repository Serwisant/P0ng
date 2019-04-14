#include "CollisionChecker.h"
#include "Ball.h"
#include "Pallet.h"

bool CollisionChecker::isBallInCollisionWithPallet(Ball* ball, Pallet* pallet) {
	float ballX = ball->getX();
	float ballY = ball->getY();
	float ballRightSide = ball->getRightSide();
	float ballBottom = ball->getBottom();

	float palletX = pallet->getX();
	float palletY = pallet->getY();
	float palletRightSide = pallet->getRightSide();
	float palletBottom = pallet->getBottom();

	float predictedLeftSideOfBall = ballX + ball->getVectorOfMovement().x;
	float predictedRightSideOfBall = ballRightSide + ball->getVectorOfMovement().x;
	float predictedTopOfBall = ballY + ball->getVectorOfMovement().y;
	float predictedBottomOfBall = ballBottom + ball->getVectorOfMovement().y;

	if (predictedRightSideOfBall > palletX && predictedLeftSideOfBall < palletRightSide &&
		predictedBottomOfBall > palletY && predictedTopOfBall < palletBottom)
		return true;
	else
		return false;
}

bool CollisionChecker::isBallInCollisionWithUpperBound(Ball* ball) {
	float ballY = ball->getY();
	float ballVector = ball->getVectorOfMovement().y;
	float predictedYPosition = ballY + ballVector;

	return predictedYPosition <= 0;
}

bool CollisionChecker::isBallInCollisionWithLowerBound(Ball* ball) {
	float ballY = ball->getY();
	float ballHeigth = ball->getHeight();
	float ballVector = ball->getVectorOfMovement().y;
	float predictedYPosition = ballY + ballHeigth + ballVector;

	return predictedYPosition >= 768.F;
}

bool CollisionChecker::isBallOutsideLeft(Ball* ball) {
	float ballX = ball->getX();
	float ballWidth = ball->getWidth();

	return ballX < (-ballWidth);
}

bool CollisionChecker::isBallOutsideRight(Ball* ball) {
	float ballX = ball->getX();
	float ballWidth = ball->getWidth();

	return ballX > 1024.F + ballWidth;
}
