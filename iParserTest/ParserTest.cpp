#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {

	TEST_CLASS(iPlannerParserTest) {
	private:
		iParser testParser;
	public:

	#ifndef TESTPARSER
	#else
		TEST_METHOD(retrieveCommandTest) {
			string stringOne = "ADD text";
			string stringTwo = "del\ttext";
			string stringThree = "exit\t";
			string expectedOne = "add";
			string expectedTwo = "del";
			string expectedThree = "exit";

			string actualOne = testParser.retrieveCommand(stringOne);
			Assert::AreEqual(expectedOne, actualOne);

			string actualTwo = testParser.retrieveCommand(stringTwo);
			Assert::AreEqual(expectedTwo, actualTwo);

			string actualThree = testParser.retrieveCommand(stringThree);
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

		TEST_METHOD(executeEditParsing) {
			string text[3] = { "123 text", "CS2013 text", "123" };
			string expectedCommand[4] = { "edit", "description", "invalid", "invalid" };
			string expectedText[4] = { "123", "text", "Invalid index", "invalid edit" };

			testParser.executeEditParsing(text[0]);
			testParser.executeEditParsing(text[1]);
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

		TEST_METHOD(executeUndoParsingTest) {
			string text[2] = { "undo", "undo 123" };
			string expectedCommand[2] = { "undo", "invalid" };
			string expectedText[2] = { "", "Invalid command" };

			testParser.executeUndoParsing(text[0]);
			testParser.executeUndoParsing(text[1]);
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

		TEST_METHOD(executeExitParsingTest) {
			string text[2] = { "exit", "exit 123" };
			string expectedCommand[2] = { "exit", "invalid" };
			string expectedText[2] = { "", "Invalid command" };

			testParser.executeExitParsing(text[0]);
			testParser.executeExitParsing(text[1]);
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

		TEST_METHOD(trimTextTest) {
			string stringOne = "   add    text   ";
			string stringTwo = "\t\t del \t text \t\t\t";
			string stringThree = "  exit\t\t";
			string expectedOne = "add text";
			string expectedTwo = "del text";
			string expectedThree = "exit";
			string expected = "success";

			string actualOne = testParser.trimText(stringOne);
			string actualTwo = testParser.trimText(stringTwo);
			string actualThree = testParser.trimText(stringThree);

			Assert::AreEqual(expected, actualOne);
			Assert::AreEqual(expected, actualTwo);
			Assert::AreEqual(expected, actualThree);
			Assert::AreEqual(expectedOne, stringOne);
			Assert::AreEqual(expectedTwo, stringTwo);
			Assert::AreEqual(expectedThree, stringThree);
		}

		TEST_METHOD(removeFirstStringTokenTest) {
			string stringOne = "add text";
			string stringTwo = "del text";
			string stringThree = "exit";
			string expectedOne = "text";
			string expectedTwo = "text";
			string expectedThree = "";

			string actualOne = testParser.removeFirstStringToken(stringOne);
			Assert::AreEqual(expectedOne, actualOne);

			string actualTwo = testParser.removeFirstStringToken(stringTwo);
			Assert::AreEqual(expectedTwo, actualTwo);

			string actualThree = testParser.removeFirstStringToken(stringThree);
			Assert::AreEqual(expectedThree, actualThree);
		}
		
		TEST_METHOD(removeConsecutiveWhiteSpace) {
			string actual = "1 2 \t 3 \t 4 5";
			string expected = "1 2 3 4 5"; 
			
			testParser.removeConsecutiveWhiteSpace(actual);
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(convertToLowerCaseTest) {
			string actual = "ABCDEFGHIJKLM123456789NOPQRSTUVWXYZ";
			string expected = "abcdefghijklm123456789nopqrstuvwxyz";

			testParser.convertToLowerCase(actual);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(retrieveFirstStringTokenTest) {
			string stringOne = "add   text";
			string stringTwo = "exit";
			string expectedOne = "add";
			string expectedTwo = "exit";

			string actualOne = testParser.retrieveFirstStringToken(stringOne);
			Assert::AreEqual(expectedOne, actualOne);

			string actualTwo = testParser.retrieveFirstStringToken(stringTwo);
			Assert::AreEqual(expectedTwo, actualTwo);
		}

		TEST_METHOD(areDigitsTest) {
			string stringOne = "123456789";
			string stringTwo = "123a456b789c";
			string stringThree = "123 456 789";

			bool actualOne = testParser.areDigits(stringOne);
			bool actualTwo = testParser.areDigits(stringTwo);
			bool actualThree = testParser.areDigits(stringThree);

			Assert::IsTrue(actualOne);
			Assert::IsFalse(actualTwo);
			Assert::IsFalse(actualThree);
		}

		TEST_METHOD(isWhiteSpaceTest) {
			char characterOne = ' ';
			char characterTwo = '\t';
			char characterThree = '0';

			bool actualOne = testParser.isWhiteSpace(characterOne);
			bool actualTwo = testParser.isWhiteSpace(characterTwo);
			bool actualThree = testParser.isWhiteSpace(characterThree);

			Assert::IsTrue(actualOne);
			Assert::IsTrue(actualTwo);
			Assert::IsFalse(actualThree);
		}
	#endif
	};
}