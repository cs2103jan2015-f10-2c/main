#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {

	TEST_CLASS(ParseInfoTest) {
	private:
		iParser testParser;
		ParseInfo testParseInfo;
	public:

		// Unit testing for ParseInfo Class
		TEST_METHOD(commandTest) {
			string text = "add";
			string actualSet;
			string expectedSet;
			string actualGet;
			string expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.getHasMainCommand();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setMainCommand(text);
			expectedSet = "successful execution";
			actualGet = testParseInfo.getMainCommand();
			expectedGet = "add";	
			Assert::AreEqual(expectedSet, actualSet);
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.getHasMainCommand();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}

		TEST_METHOD(IndexTest) {
			unsigned int validIndex = 1;
			unsigned int invalidIndex = -1;
			string actualSet;
			string expectedSet;
			int actualGet;
			int expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.getHasIndex();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setIndex(validIndex);
			expectedSet = "execution sucessful";
			actualGet = testParseInfo.getIndex();
			expectedGet = 1;
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.getHasIndex();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setIndex(invalidIndex);
			expectedSet = "execution sucessful";
			actualGet = testParseInfo.getIndex();
			expectedGet = -1;
			Assert::AreEqual(expectedGet, actualGet);
			
			actualBool = testParseInfo.getHasIndex();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}
		
		TEST_METHOD(itemTest) {
			string text = "itemName";
			Item testItem;
			string actualSet;
			string expectedSet;
			string actualGet;
			string expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.getHasItem();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			testItem.setItemName(text);
			actualSet = testParseInfo.setItem(testItem);
			expectedSet = "successful execution";
			Assert::AreEqual(expectedSet, actualSet);

			testItem = testParseInfo.getItem();
			actualGet = testItem.getItemName();
			expectedGet = "itemName";
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.getHasItem();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}
		
		TEST_METHOD(TokensTest) {
			list<COMMAND_AND_TEXT> testList;
			COMMAND_AND_TEXT testStruct;
			string actualSet;
			string expectedSet;
			string actualGetCommand;
			string expectedGetCommand;
			string actualGetText;
			string expectedGetText;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.getHasTokens();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			testStruct.command = "add";
			testStruct.text = "do CS2103";
			actualSet = testParseInfo.setTokens(testStruct);
			expectedSet = "successful execution";
			Assert::AreEqual(expectedSet, actualSet);

			testList = testParseInfo.getTokens();
			list<COMMAND_AND_TEXT>::iterator iter;
			iter = testList.begin();
			actualGetCommand = iter->command;
			actualGetText = iter->text;
			expectedGetCommand = "add";
			expectedGetText = "do CS2103";
			Assert::AreEqual(expectedGetCommand, actualGetCommand);
			Assert::AreEqual(expectedGetText, actualGetText);

			actualBool = testParseInfo.getHasTokens();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}

		TEST_METHOD(ValidityTest) {
			string actual;
			string expected;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.getIsValidInput();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
			
			actual = testParseInfo.setIsNotValidInput();
			expected = "successful execution";
			Assert::AreEqual(expected, actual);

			actualBool = testParseInfo.getIsValidInput();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);
		}
	};
	/*
	TEST_CLASS(ParseInfoTest) {
	private:
		iParser testParser;
		ParseInfo testParseInfo;
	public:
		// Unit testing for iParser class
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
	};
	*/
}