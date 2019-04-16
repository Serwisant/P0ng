#include "CollisionChecker.h"
#include "Ball.h"
#include "Pallet.h"

CollisionChecker::CollisionChecker() : deltaTime(0.F) {

}

void CollisionChecker::setDeltaTime(float dt) {
	deltaTime = dt;
}

bool CollisionChecker::isBallInCollisionWithPallet(Ball* ball, Pallet* pallet) {
	float ballX = ball->getX();
	float ballY = ball->getY();
	float ballRightSide = ball->getRightSide();
	float ballBottom = ball->getBottom();

	float palletX = pallet->getX();
	float palletY = pallet->getY();
	float palletRightSide = pallet->getRightSide();
	float palletBottom = pallet->getBottom();

	float predictedLeftSideOfBall = ballX + (ball->getVectorOfMovement().x * deltaTime);
	float predictedRightSideOfBall = ballRightSide + (ball->getVectorOfMovement().x * deltaTime);
	float predictedTopOfBall = ballY + (ball->getVectorOfMovement().y * deltaTime);
	float predictedBottomOfBall = ballBottom + (ball->getVectorOfMovement().y * deltaTime);

	if (predictedRightSideOfBall > palletX && predictedLeftSideOfBall < palletRightSide &&
		predictedBottomOfBall > palletY && predictedTopOfBall < palletBottom)
		return true;
	else
		return false;
}

bool CollisionChecker::isBallInCollisionWithUpperBound(Ball* ball) {
	float ballY = ball->getY();
	float ballVector = ball->getVectorOfMovement().y * deltaTime;
	float predictedYPosition = ballY + ballVector;

	return predictedYPosition <= 0;
}

bool CollisionChecker::isBallInCollisionWithLowerBound(Ball* ball) {
	float ballBottom = ball->getBottom();
	float ballVector = ball->getVectorOfMovement().y * deltaTime;
	float predictedYPosition = ballBottom + ballVector;

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
