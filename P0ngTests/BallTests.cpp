#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Projekt2/Ball.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BallTests {
	TEST_CLASS(BallTests) {
	public:
		TEST_METHOD(BallMoveTest) {
			prepareTestBall();

			testBall.update(deltaTime);

			float expectedX = initialX + (testBall.getVectorOfMovement().x * deltaTime);
			float expectedY = initialY + (testBall.getVectorOfMovement().y * deltaTime);

			float actualX = testBall.getX();
			float actualY = testBall.getY();

			Assert::AreEqual(expectedX, actualX);
			Assert::AreEqual(expectedY, actualY);
		}

		TEST_METHOD(BallIncreaseSpeedTest) {
			prepareTestBall();
			float ds = 1 / 60;

			testBall.increaseSpeed(ds);
			testBall.update(deltaTime);

			float expectedXMovement = dx > 0 ? dx + ds : dx - ds;
			float expectedYMovement = dy > 0 ? dy + ds : dy - ds;

			float expectedX = initialX + ((expectedXMovement) * deltaTime);
			float expectedY = initialY + ((expectedYMovement) * deltaTime);

			float actualX = testBall.getX();
			float actualY = testBall.getY();

			Assert::AreEqual(expectedX, actualX);
			Assert::AreEqual(expectedY, actualY);
		}

		TEST_METHOD(BallBounceHorizontally) {
			prepareTestBall();

			float expectedX = initialX - (dx * deltaTime);
			float expectedY = initialY + (dy * deltaTime);

			testBall.bounceHorizontally();
			testBall.update(deltaTime);

			float actualX = testBall.getX();
			float actualY = testBall.getY();

			Assert::AreEqual(expectedX, actualX);
			Assert::AreEqual(expectedY, actualY);
		}

		TEST_METHOD(BallBounceVertically) {
			prepareTestBall();

			float expectedX = initialX + (dx * deltaTime);
			float expectedY = initialY - (dy * deltaTime);

			testBall.bounceVertically();
			testBall.update(deltaTime);

			float actualX = testBall.getX();
			float actualY = testBall.getY();

			Assert::AreEqual(expectedX, actualX);
			Assert::AreEqual(expectedY, actualY);
		}

private:
	void prepareTestBall() {
		testBall.reset();

		initialX = testBall.getX();
		initialY = testBall.getY();

		deltaTime = 1.F / 60.F;
		dx = testBall.getVectorOfMovement().x;
		dy = testBall.getVectorOfMovement().y;
	}

	Ball testBall;

	float initialX;
	float initialY;

	float deltaTime;
	float dx;
	float dy;
	};
}