#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {
	/*
	TEST_CLASS(ParseInfoTest) {
	private:
		ParseInfo testParseInfo;
	public:
		TEST_METHOD(commandTest) {
			string text = "add";
			string actualSet;
			string expectedSet;
			string actualGet;
			string expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.hasMainCommand();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setMainCommand(text);
			expectedSet = "successful execution";
			actualGet = testParseInfo.getMainCommand();
			expectedGet = "add";	
			Assert::AreEqual(expectedSet, actualSet);
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.hasMainCommand();
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

			actualBool = testParseInfo.hasIndex();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setIndex(validIndex);
			expectedSet = "execution sucessful";
			actualGet = testParseInfo.getIndex();
			expectedGet = 1;
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.hasIndex();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setIndex(invalidIndex);
			expectedSet = "execution sucessful";
			actualGet = testParseInfo.getIndex();
			expectedGet = -1;
			Assert::AreEqual(expectedGet, actualGet);
			
			actualBool = testParseInfo.hasIndex();
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

			actualBool = testParseInfo.hasItem();
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

			actualBool = testParseInfo.hasItem();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}
		
		TEST_METHOD(ValidityTest) {
			string actualString;
			string expectedString;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.hasValidInput();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
			
			actualString = testParseInfo.setIsNotValidInput();
			expectedString = "successful execution";
			Assert::AreEqual(expectedString, actualString);

			actualBool = testParseInfo.hasValidInput();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);
		}
	};
	*/
	TEST_CLASS(iPlannerParserTest) {
	private:
		iParser testParser;
	public:
		TEST_METHOD(trimTextTest) {
			string stringOne = "   add text   ";
			string stringTwo = "\t\t del text \t\t\t";
			string stringThree = "  exit\t\t";
			string actualOne = testParser.trimText(stringOne);
			string actualTwo = testParser.trimText(stringTwo);
			string actualThree = testParser.trimText(stringThree);
			string expectedOne = "add text";
			string expectedTwo = "del text";
			string expectedThree = "exit";
			string expected = "success";

			Assert::AreEqual(expected, actualOne);
			Assert::AreEqual(expected, actualTwo);
			Assert::AreEqual(expected, actualThree);
			Assert::AreEqual(expectedOne, stringOne);
			Assert::AreEqual(expectedTwo, stringTwo);
			Assert::AreEqual(expectedThree, stringThree);
		}

		TEST_METHOD(retrieveCommandTest) {
			string stringOne = "add text";
			string stringTwo = "del\ttext";
			string stringThree = "exit\t";
			string expected = "success";
			string expectedCommandOne = "add";
			string expectedCommandTwo = "del";
			string expectedCommandThree = "exit";
			string actual;
			string actualCommand;

			actual = testParser.retrieveCommand(stringOne);
			actualCommand = testParser.getMainCommand();
			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expectedCommandOne, actualCommand);

			actual = testParser.retrieveCommand(stringTwo);
			actualCommand = testParser.getMainCommand();
			Assert::AreEqual(expected, actual);
			Assert::AreEqual(expectedCommandTwo, actualCommand);

			actual = testParser.retrieveCommand(stringThree);
			actualCommand = testParser.getMainCommand();
			Assert::AreEqual(expected, actual);			
			Assert::AreEqual(expectedCommandThree, actualCommand);
		}

		TEST_METHOD(removeCommandTest) {
			string stringOne = "add   text   ";
			string stringTwo = "del\t\t\ttext\t\t\t";
			string stringThree = "exit";
			string expectedOne = "text";
			string expectedTwo = "text";
			string expectedThree = "";

			string actualOne = testParser.removeCommand(stringOne);
			Assert::AreEqual(expectedOne, actualOne);

			string actualTwo = testParser.removeCommand(stringTwo);
			Assert::AreEqual(expectedTwo, actualTwo);

			string actualThree = testParser.removeCommand(stringThree);
			Assert::AreEqual(expectedThree, actualThree);
		}
		
		TEST_METHOD(executeAddParsingTest) {
			string text = "text";
			string expectedCommand = "add";
			string expectedText = "text";
			
			testParser.executeAddParsing(text);
			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();

			list<COMMAND_AND_TEXT>::iterator iter = testList.begin();
			string actualCommand = iter->command;
			string actualText = iter->text;

			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedText, actualText);
		}

		TEST_METHOD(executeDeleteParsingTest) {
			string text[2] = { "123", "abc" };
			string expectedCommand[2] = { "delete", "invalid" };
			string expectedText[2] = { "123", "Invalid index" };
		
			testParser.executeDeleteParsing(text[0]);
			testParser.executeDeleteParsing(text[1]);
			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
			list<COMMAND_AND_TEXT>::iterator iter;
			int index = 0;

			for (iter = testList.begin(); iter != testList.end(); index++, iter++) {
				string actualCommand = iter->command;
				string actualText = iter->text;

				Assert::AreEqual(expectedCommand[index], actualCommand);
				Assert::AreEqual(expectedText[index], actualText);
			}
		}

		TEST_METHOD(isDigitTest) {
			string stringOne = "123456789";
			string stringTwo = "123a456b789c";
			string stringThree = "123 456 789";

			bool actualOne = testParser.isDigit(stringOne);
			bool actualTwo = testParser.isDigit(stringTwo);
			bool actualThree = testParser.isDigit(stringThree);

			Assert::IsTrue(actualOne);
			Assert::IsFalse(actualTwo);
			Assert::IsFalse(actualThree);
		}
	};
}