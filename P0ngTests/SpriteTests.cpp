#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Projekt2/Sprite.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpriteTests
{		
	TEST_CLASS(SpriteTests)
	{
	public:
		TEST_METHOD(SpritePositionTest) {
			prepareTestSprite();

			float xPos = 150.F;
			float yPos = 150.F;

			testSprite.setPosition(Point{ xPos, yPos });

			float actualX = testSprite.getX();
			float actualY = testSprite.getY();

			Assert::AreEqual(xPos, actualX);
			Assert::AreEqual(yPos, actualY);
		}

		TEST_METHOD(SpriteMoveTest) {
			prepareTestSprite();

			float dx = 10.F;
			float dy = 10.F;

			testSprite.move(dx, dy);

			float expectedX = xPos + dx;
			float expectedY = yPos + dy;

			float actualX = testSprite.getX();
			float actualY = testSprite.getY();

			Assert::AreEqual(expectedX, actualX);
			Assert::AreEqual(expectedY, actualY);
		}

		TEST_METHOD(SpriteSizeTest) {
			prepareTestSprite();
			
			float width = 100.F;
			float height = 100.F;
			
			testSprite.setSize(Size{ width, height });

			float actualWidth = testSprite.getWidth();
			float actualHeight = testSprite.getHeight();

			Assert::AreEqual(width, actualWidth);
			Assert::AreEqual(height, actualHeight);
		}

		TEST_METHOD(SpriteBoundariesTest) {
			prepareTestSprite();

			float width = 50.F;
			float height = 50.F;

			testSprite.setSize(Size{ width, height });

			float expectedRightSize = xPos + width;
			float expectedBottom = yPos + height;

			float actualRightSize = testSprite.getRightSide();
			float actualBottom = testSprite.getBottom();

			Assert::AreEqual(expectedRightSize, actualRightSize);
			Assert::AreEqual(expectedBottom, actualBottom);
		}

	private:
		void prepareTestSprite() {
			xPos = 100.F;
			yPos = 100.F;

			testSprite.setPosition(Point{ xPos, yPos });
		}

		Sprite testSprite;
		float xPos;
		float yPos;
	};


}