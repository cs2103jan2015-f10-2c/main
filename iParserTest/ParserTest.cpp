#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {
	TEST_CLASS(iPlannerParserTest) {

private:
	iParser testParser;
	userCommand testUserCommand;

public:
	// Unit testing for UserCommand Class
	TEST_METHOD(findIndexUserCommandTest) {
		string text = "::add submit CE";
		string stringToFind = "submit";
		int actualIndex;
		int expectedIndex;

		actualIndex = testUserCommand.findIndex(text, stringToFind);
		expectedIndex = 6;

		Assert::AreEqual(expectedIndex, actualIndex);
	}

	TEST_METHOD(getSubstringUserCommandTest) {
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

	// Unit testing for iPlannerParser class
	TEST_METHOD(findIndexParserTest) {
		string text = "test :: test";
		string stringToFind = "::";
		int start = 0;
		int actualIndex;
		int expectedIndex;

		actualIndex = testParser.getFindIndex(text, stringToFind, start);
		expectedIndex = 5;

		Assert::AreEqual(expectedIndex, actualIndex);
	}

	TEST_METHOD(findSubstringParserTest) {
		string text = "test :: test";
		int start = 5;
		int end = 7;
		string actualString;
		string expectedString;

		actualString = testParser.getGetSubstring(text, start, end);
		expectedString = "::";

		Assert::AreEqual(actualString, expectedString);
	}
	};
}