#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H

class Ball;
class Pallet;

class CollisionChecker {
public:
	CollisionChecker();

	void setDeltaTime(float dt);

	bool isBallInCollisionWithPallet(Ball*, Pallet*);
	bool isBallInCollisionWithUpperBound(Ball*);
	bool isBallInCollisionWithLowerBound(Ball*);
	bool isBallOutsideLeft(Ball*);
	bool isBallOutsideRight(Ball*);

private:
	float deltaTime;
};

#endif