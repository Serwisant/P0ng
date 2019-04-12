#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H

class Ball;
class Pallet;

class CollisionChecker {
public:
	bool checkBallWithPalletCollision(Ball*, Pallet*);
	void checkBallWithUpperBoundCollision(Ball*);
	void checkBallWithLowerBoundCollision(Ball*);
	bool isBallOutsideLeft(Ball*);
	bool isBallOutsideRight(Ball*);
};

#endif