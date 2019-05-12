#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Projekt2/CollisionChecker.h"
#include "../Projekt2/Ball.h"
#include "../Projekt2/Pallet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CollisionCheckerTests
{
	TEST_CLASS(CollisionCheckerTests)
	{
	public:
		TEST_METHOD(BallOutsideLeftTest) {
			prepareCollisionCheckerAndBall();

			Assert::AreEqual(false, collisionChecker.isBallOutsideLeft(&testBall));

			if (testBall.getVectorOfMovement().x > 0)
				testBall.bounceHorizontally();

			deltaTime = 1000.F;
			testBall.update(deltaTime);

			Assert::AreEqual(true, collisionChecker.isBallOutsideLeft(&testBall));
		}

		TEST_METHOD(BallOutsideRightTest) {
			prepareCollisionCheckerAndBall();

			Assert::AreEqual(false, collisionChecker.isBallOutsideRight(&testBall));

			if (testBall.getVectorOfMovement().x < 0)
				testBall.bounceHorizontally();

			deltaTime = 1000.F;
			testBall.update(deltaTime);

			Assert::AreEqual(true, collisionChecker.isBallOutsideRight(&testBall));
		}

		TEST_METHOD(BallTopBoundariesTest) {
			prepareCollisionCheckerAndBall();

			Assert::AreEqual(false, collisionChecker.isBallInCollisionWithUpperBound(&testBall));

			if (testBall.getVectorOfMovement().y > 0)
				testBall.bounceVertically();

			deltaTime = 1000.F;
			testBall.update(deltaTime);

			Assert::AreEqual(true, collisionChecker.isBallInCollisionWithUpperBound(&testBall));
		}

		TEST_METHOD(BallBottomBoundariesTest) {
			prepareCollisionCheckerAndBall();

			Assert::AreEqual(false, collisionChecker.isBallInCollisionWithLowerBound(&testBall));

			if (testBall.getVectorOfMovement().y < 0)
				testBall.bounceVertically();

			deltaTime = 1000.F;
			testBall.update(deltaTime);

			Assert::AreEqual(true, collisionChecker.isBallInCollisionWithLowerBound(&testBall));
		}

		TEST_METHOD(BallPalletCollisionTest) {
			prepareCollisionCheckerAndBall();

			Assert::AreEqual(false, collisionChecker.isBallInCollisionWithPallet(&testBall, &testPallet));

			if (testBall.getVectorOfMovement().x > 0)
				testBall.bounceHorizontally();

			testBall.update(482.F / 300.F);	// Time needed for the ball to be around the pallet

			testPallet.setPosition(Point{ 0.F, testBall.getY() - 20.F});	// Around middle of the pallet

			Assert::AreEqual(true, collisionChecker.isBallInCollisionWithPallet(&testBall, &testPallet));
		}

	private:
		void prepareCollisionCheckerAndBall() {
			deltaTime = 1.F / 60.F;
			collisionChecker.setDeltaTime(deltaTime);
			testBall.reset();
			testPallet.setPosition(Point{ 0.F, 375.F });
		}

		CollisionChecker collisionChecker;
		Ball testBall;
		Pallet testPallet;
		float deltaTime;

	};
}