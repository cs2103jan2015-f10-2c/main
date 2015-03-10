#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {
	TEST_CLASS(iPlannerParserTest) {

private:
	iParser testParser;
	userCommand testUserCommand;
	
public:
	/*
	// Unit testing for UserCommand Class
	TEST_METHOD(findIndexUserCommandTest) {
		string text = "::add submit CE";
		string stringToFind = "submit";
		int actual;
		int expected;

		actual = testUserCommand.findIndex(text, stringToFind);
		expected = 6;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(getSubstringUserCommandTest) {
		string text = "::add submit CE";
		int start = 2;
		int end = 5;
		string actual;
		string expected;

		actual = testUserCommand.getSubstring(text, start, end);
		expected = "add";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(setAndGetCommandTest) {
		string text = "::add submit CE";
		string actual;
		string expected;

		testUserCommand.setCommand(text);

		actual = testUserCommand.getCommand();
		expected = "add";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(setAndGetTextTest) {
		string text = "::add submit CE";
		string actual;
		string expected;

		testUserCommand.setText(text);

		actual = testUserCommand.getText();
		expected = "submit CE";

		Assert::AreEqual(expected, actual);
	}

	// Unit testing for iPlannerParser class
	TEST_METHOD(findIndexParserTest) {
		string text = "test :: test";
		string stringToFind = "::";
		int start = 0;
		int actual;
		int expected;

		actual = testParser.getFindIndex(text, stringToFind, start);
		expected = 5;

		Assert::AreEqual(expected, actual);
	}
	

	TEST_METHOD(findSubstringParserTest) {
		string text = "test :: test";
		int start = 5;
		int end = 7;
		string actual;
		string expected;

		actual = testParser.getGetSubstring(text, start, end);
		expected = "::";

		Assert::AreEqual(actual, expected);
	}
	*/
	};
}