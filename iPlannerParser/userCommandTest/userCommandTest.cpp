#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace userCommandTest {
	TEST_CLASS(userCommandTest) {
	
	private:	
		userCommand testUserCommand;

	public:

		TEST_METHOD(findIndexTest) {
			string text = "::add submit CE";
			string stringToFind = "submit";
			int actualIndex;
			int expectedIndex;

			actualIndex = testUserCommand.findIndex(text, stringToFind);
			expectedIndex = 6;

			Assert::AreEqual(expectedIndex, actualIndex); 
		}

		TEST_METHOD(getSubstringTest) {
			string text = "::add submit CE";
			int start = 2;
			int end = 5;
			string actualString;
			string expectedString;

			actualString = testUserCommand.getSubstring(text, start, end);
			expectedString = "add";

			Assert::AreEqual(expectedString, actualString); 
		}

		TEST_METHOD(setAndGetCommandTest) {
			string text = "::add submit CE";
			string actualString;
			string expectedString;

			testUserCommand.setCommand(text);
			
			actualString = testUserCommand.getCommand();
			expectedString = "add";

			Assert::AreEqual(expectedString, actualString); 
		}

		TEST_METHOD(setAndGetTextTest) {
			string text = "::add submit CE";
			string actualString;
			string expectedString;

			testUserCommand.setText(text);
			
			actualString = testUserCommand.getText();
			expectedString = "submit CE";

			Assert::AreEqual(expectedString, actualString); 
		}

	};
}