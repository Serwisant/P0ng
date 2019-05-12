#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Projekt2/Pallet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PalletTests
{
	TEST_CLASS(PalletTests)
	{
	public:
		TEST_METHOD(PalletMoveTest) {
			preparePallet();

			float dy = -100.F;

			testPallet.movePallet(dy);
			testPallet.update(deltaTime);
			
			float expectedY = posY + (dy * deltaTime);

			float actualY = testPallet.getY();

			Assert::AreEqual(expectedY, actualY);
		}

		TEST_METHOD(PalletMoveUpBoundariesTest) {
			preparePallet();

			float dy = -100000.F;

			testPallet.movePallet(dy);
			testPallet.update(deltaTime);

			float expectedY = 0;

			float actualY = testPallet.getY();

			Assert::AreEqual(expectedY, actualY);
		}

		TEST_METHOD(PalletMoveDownBoundariesTest) {
			preparePallet();

			float dy = 100000.F;

			testPallet.movePallet(dy);
			testPallet.update(deltaTime);

			float expectedY = 768.F;

			float actualY = testPallet.getBottom();

			Assert::AreEqual(expectedY, actualY);
		}

	private:
		void preparePallet() {
			testPallet.setPosition({ 0, 334.F });

			posY = testPallet.getY();
			deltaTime = 1.F / 60.F;
		}

		Pallet testPallet;

		float posY;
		float deltaTime;
	};
}