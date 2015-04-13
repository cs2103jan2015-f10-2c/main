//@author A0111238U
//	ParserTest
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng

/*
===================================================================================================
NOTES
- Parser test methods muted as parser functions are all private except for parse which is called
  by Logic
- To execute unit testing for parser test methods, change private functions in parser.h to public
- TEST COVERAGE: 94:58%
===================================================================================================
*/

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {

	TEST_CLASS(iPlannerParserTest) {
private:
	iParser testParser;
public:

	TEST_METHOD(parserExecuteParsingTest) {
		string testInput[] = { "add item1 -date 1 feb 2015, 2pm to 11 dec 2015, 3pm -DESC testDesc -p H",
			"Delete 123",
			"Clear",
			"edit 2 -remove priority",
			"edit 3 -remove date",
			"edit 4 -remove desc",
			"edit 5 -name testName",
			"UnDo",
			"sort date",
			"sort name",
			"sort p",
			"sort done",
			"sort update",
			"search testSearch",
			"view All",
			"view DONE",
			"view Undone",
			"view H",
			"view Med",
			"view LOW",
			"view 12 nov to 13 dec",
			"view 12 nov",
			"save C:\Folder1",
			"done 1",
			"undone 2",
			"exit" };
		string expectedCommand[][5] = { { "add", "start", "end", "description", "priority" },
		{ "delete" },
		{ "clear" },
		{ "edit", "priority" },
		{ "edit", "start", "end" },
		{ "edit", "description" },
		{ "edit", "name" },
		{ "undo" },
		{ "sort" },
		{ "sort" },
		{ "sort" },
		{ "sort" },
		{ "sort" },
		{ "search" },
		{ "view" },
		{ "view" },
		{ "view" },
		{ "view" },
		{ "view" },
		{ "view" },
		{ "view" },
		{ "view" },
		{ "save" },
		{ "done" },
		{ "undone" },
		{ "exit" } };
		string expectedText[][5] = { { "item1", "2015 2 1 14 00", "2015 12 11 15 00", "testDesc", "high" },
		{ "123" },
		{ "" },
		{ "2", "" },
		{ "3", "-2 -2 -2 -2 -2", "-2 -2 -2 -2 -2" },
		{ "4", "" },
		{ "5", "testName" },
		{ "" },
		{ "date" },
		{ "name" },
		{ "priority" },
		{ "done" },
		{ "update" },
		{ "testSearch" },
		{ "all" },
		{ "done" },
		{ "undone" },
		{ "high" },
		{ "medium" },
		{ "low" },
		{ "date -1 11 12 -1 -1 -1 12 13 -1 -1" },
		{ "date -1 11 12 -1 -1 -1 11 12 -1 -1" },
		{"C:\Folder1"},
		{ "1" },
		{"2"},
		{""} };

		for (int i = 0; i < 7; i++) {
			testParser.executeParsing(testInput[i]);

			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
			list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

			for (int j = 0; iter != testList.end(); j++, iter++) {
				string actualCommand = iter->command;
				string actualText = iter->text;
				Assert::AreEqual(expectedCommand[i][j], actualCommand);
				Assert::AreEqual(expectedText[i][j], actualText);
			}

			testParser.clearParseInfo();
		}
	}

	TEST_METHOD(parserExecuteAddParsingTest) {
		string testInput[] = { "item1 -date 10 Nov 2015, 2359hr -DESC testDesc -p H",
			"item2 -date 1/2/2015 to 2/3/2015",
			"item3 -Due 1234hr, 12 nov",
			"item4 -start 12 nov, 1234pm",
			"item5 -END 12pm",
			"item6 -remove date",
			"item7 -NaMe testName",
			"item8 -date 10 nov -due 11 dec",
			"item9 -date 10 nov -start 11 DEC",
			"item10 -date 10 nov -end 11 Dec",
			"item11 -due 10 nov -start 11 dec",
			"item12 -due 10 nov -end 11 Dec",
			"item13 -p H -priority Low",
			"item14 -desc testDescOne -description testDescTwo" };
		string expectedCommand[][4] = { { "add", "start", "description", "priority" },
		{ "add", "start", "end" },
		{ "add", "end" },
		{ "add", "start" },
		{ "add", "end" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" } };
		string expectedText[][4] = { { "item1", "2015 11 10 23 59", "testDesc", "high" },
		{ "item2", "2015 2 1 -1 -1", "2015 3 2 -1 -1" },
		{ "item3", "-1 11 12 12 34" },
		{ "item4", "-1 11 12 12 34" },
		{ "item5", "-1 -1 -1 12 00" },
		{ "Unable to use \'remove\' modifier when using \'add\' command" },
		{ "Unable to use \'name\' modifier when using \'add\' command" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use \'priority\' modifier more than once" },
		{ "Unable to use \'description\' modifier more than once" } };

		for (int i = 0; i < 14; i++) {
			testParser.executeAddParsing(testInput[i]);

			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
			list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

			for (int j = 0; iter != testList.end(); j++, iter++) {
				string actualCommand = iter->command;
				string actualText = iter->text;
				Assert::AreEqual(expectedCommand[i][j], actualCommand);
				Assert::AreEqual(expectedText[i][j], actualText);
			}

			testParser.clearParseInfo();
		}
	}

	TEST_METHOD(parserExecuteEditParsing) {
		string testInput[] = { "1 -name testName -date 10 Nov 2015, 2359hr -Desc testDesc -p H",
			"2 -REMOVE date",
			"3 -date 1/2/2015 to 2/3/2015",
			"4 -Start 12 nov, 1234pm",
			"5 -end 12pm",
			"6 -remove date -rmv desc",
			"7 -name testNameOne -name TestNameTwo",
			"8 -date 10 nov -due 11 dec",
			"9 -date 10 nov -start 11 DEC",
			"10 -date 10 nov -end 11 Dec",
			"11 -due 10 nov -start 11 dec",
			"12 -due 10 nov -end 11 Dec",
			"13 -p H -priority Low",
			"14 -desc testDescOne -description testDescTwo" };
		string expectedCommand[][5] = { { "edit", "name", "start", "description", "priority" },
		{ "edit", "start", "end" },
		{ "edit", "start", "end" },
		{ "edit", "start" },
		{ "edit", "end" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" },
		{ "invalid" } };
		string expectedText[][5] = { { "1", "testName", "2015 11 10 23 59", "testDesc", "high" },
		{ "2", "-2 -2 -2 -2 -2", "-2 -2 -2 -2 -2" },
		{ "3", "2015 2 1 -1 -1", "2015 3 2 -1 -1" },
		{ "4", "-1 11 12 12 34" },
		{ "5", "-1 -1 -1 12 00" },
		{ "Unable to use \'remove\' modifier more than once" },
		{ "Unable to use \'name\' modifier more than once" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use multiple date time modifiers" },
		{ "Unable to use \'priority\' modifier more than once" },
		{ "Unable to use \'description\' modifier more than once" } };

		for (int i = 0; i < 12; i++) {
			testParser.executeEditParsing(testInput[i]);

			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
			list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

			for (int j = 0; iter != testList.end(); j++, iter++) {
				string actualCommand = iter->command;
				string actualText = iter->text;
				Assert::AreEqual(expectedCommand[i][j], actualCommand);
				Assert::AreEqual(expectedText[i][j], actualText);
			}

			testParser.clearParseInfo();
		}
	}

	TEST_METHOD(parserExecuteSortParsingTest) {
		// testInput tests for all recognised cases
		string testInput[] = { "date", "NAME", "Priority", "p", "done", "UPDATE" };
		string expectedCommand = "sort";
		string expectedText[] = { "date", "name", "priority", "priority", "done", "update" };

		for (int i = 0; i < 6; i++) {
			testParser.executeSortParsing(testInput[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}

		testParser.clearParseInfo();

		// testInput tests for other cases which will fail
		string testInputFalse[] = { "test", " ", "" };
		string expectedCommandFalse = "invalid";
		string expectedTextFalse = "Invalid sort";

		for (int i = 0; i < 3; i++) {
			testParser.executeSortParsing(testInputFalse[i]);
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommandFalse, actualCommand);
			Assert::AreEqual(expectedTextFalse, actualText);
		}
	}

	TEST_METHOD(parserExecuteViewParsingTest) {
		// testInput tests for all recognised cases
		string testInput[] = { "all", "DONE", "Undone", "12 nov to 13 dec", "12 nov" };
		string expectedCommand = "view";
		string expectedText[] = { "all", "done", "undone", "date -1 11 12 -1 -1 -1 12 13 -1 -1", "date -1 11 12 -1 -1 -1 11 12 -1 -1" };

		for (int i = 0; i < 5; i++) {
			testParser.executeViewParsing(testInput[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();
		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}

		testParser.clearParseInfo();

		// testInput tests for other cases which will fail
		string testInputFalse[] = { "test", " ", "" };
		string expectedCommandFalse = "invalid";
		string expectedTextFalse = "Invalid view";

		for (int i = 0; i < 3; i++) {
			testParser.executeViewParsing(testInputFalse[i]);
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommandFalse, actualCommand);
			Assert::AreEqual(expectedTextFalse, actualText);
		}
	}

	TEST_METHOD(parserExecuteCommandAndTextParsingTest) {
		// testText[4] tests for invalid case where blank string is not allowed
		string testCommand[] = { "delete", "del", "search", "save", "done" };
		string testText[] = { "123", "123ABC", "abc", " ", "" };
		string expectedCommand[] = { "delete", "del", "search", "save", "invalid" };
		string expectedText[] = { "123", "123abc", "abc", " ", "Invalid input" };

		for (int i = 0; i < 5; i++) {
			testParser.executeCommandAndTextParsing(testCommand[i], testText[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserExecuteSingularCommandParsingTest) {
		// testText[1], testText[3] and testText[5] tests for invalid commands where there
		// are invalid texts after the commands
		string testCommand[] = { "undo", "undo", "clear", "clear", "exit", "exit" };
		string testText[] = { "undo", "undo 123", "clear", "clear 123ABC", "exit", "exit abc" };
		string expectedCommand[] = { "undo", "invalid", "clear", "invalid", "exit", "invalid" };
		string expectedText[] = { "", "Invalid command", "", "Invalid command", "", "Invalid command" };

		for (int i = 0; i < 6; i++) {
			testParser.executeSingularCommandParsing(testCommand[i], testText[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserCheckAndSetTokenisedInformationTest) {
		// testInput[0] is added but not tested as the function starts from index = 1 where the modifiers starts
		string testInput[] = { "edit 1", "-name testName", "-desc WEAR FORMAL", "-date 12/11/10, 10PM", "-p H" };
		string expectedCommand[] = { "name", "description", "start", "priority" };
		string expectedText[] = { "testName", "WEAR FORMAL", "10 11 12 22 00", "high" };
		vector<string> testVector;

		for (int i = 0; i < 5; i++) {
			testVector.push_back(testInput[i]);
		}

		testParser.checkAndSetTokenisedInformation(testVector, "edit");

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}

		testParser.clearParseInfo();

		// test for remove modifier
		string testInputRemove[] = { "edit 2", "-remove date" };
		string expectedCommandRemove[] = { "start", "end" };
		string expectedTextRemove = "-2 -2 -2 -2 -2";

		testVector.clear();
		for (int i = 0; i < 2; i++) {
			testVector.push_back(testInputRemove[i]);
		}

		testParser.checkAndSetTokenisedInformation(testVector, "edit");

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommandRemove[i], actualCommand);
			Assert::AreEqual(expectedTextRemove, actualText);
		}

		testParser.clearParseInfo();

		// test for false inputs for edit and add
		string testInputFalse[][3] = { { "edit 1", "-name test", "-name case" },
		{ "edit 2", "-start 10 Nov", "-end 11 Nov" },
		{ "edit 3", "-due 10 Nov", "-date 11 Nov" },
		{ "edit 4", "-description test", "-desc case" },
		{ "edit 5", "-priority H", "-p L" },
		{ "edit 6", "-remove 1", "-remove 2" } };
		string expectedTextFalse[] = { "Unable to use \'name\' modifier more than once",
			"Unable to use multiple date time modifiers",
			"Unable to use multiple date time modifiers",
			"Unable to use \'description\' modifier more than once",
			"Unable to use \'priority\' modifier more than once",
			"Unable to use \'remove\' modifier more than once" };

		for (int i = 0; i < 5; i++) {
			testParser.clearParseInfo();
			testVector.clear();
			for (int j = 0; j < 3; j++) {
				testVector.push_back(testInputFalse[i][j]);
			}

			try {
				testParser.checkAndSetTokenisedInformation(testVector, "edit");
			} catch (string& actualText) {
				Assert::AreEqual(expectedTextFalse[i], actualText);
			}
		}

		testParser.clearParseInfo();

		// test for false inputs for edit and add
		string testInputFalseAdd[][2] = { { "add 1", "-name test" },
		{ "add 2", "-start 10 Nov" } };
		string expectedTextFalseAdd[] = { "Unable to use \'name\' modifier when using \'add\' command",
			"Unable to use \'remove\' modifier when using \'add\' command" };

		for (int i = 0; i < 2; i++) {
			testParser.clearParseInfo();
			testVector.clear();
			for (int j = 0; j < 2; j++) {
				testVector.push_back(testInputFalseAdd[i][j]);
			}

			try {
				testParser.checkAndSetTokenisedInformation(testVector, "add");
			} catch (string& actualText) {
				Assert::AreEqual(expectedTextFalseAdd[i], actualText);
			}
		}
	}

	TEST_METHOD(parserExecuteModifierAndTextParsingTest) {
		// testText[4] tests for invalid case where blank string is not allowed
		string testCommand[] = { "name", "desc", "priority", "desc", "priority" };
		string testText[] = { "123", "123abc", "abc", "@@@", "high" };
		string expectedCommand[] = { "name", "desc", "priority", "desc", "priority" };
		string expectedText[] = { "123", "123abc", "abc", "@@@", "high" };

		for (int i = 0; i < 5; i++) {
			testParser.executeModifierAndTextParsing(testCommand[i], testText[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserExecuteDateTimeParsingTest) {
		string testInput[] = { "10/11/2015", "2 Mar 2015", "10/11, 1PM", "2 Mar, 12:30", "10/11 to 11/12", "2 Mar 2015, 11am - 3 Apr 2015, 11pm" };
		string expectedCommand[] = { "start", "start", "start", "start", "start", "end", "start", "end" };
		string expectedText[] = { "2015 11 10 -1 -1", "2015 3 2 -1 -1", "-1 11 10 13 00", "-1 3 2 12 30", "-1 11 10 -1 -1", "-1 12 11 -1 -1", "2015 3 2 11 00", "2015 4 3 23 00" };

		for (int i = 0; i < 6; i++) {
			testParser.executeDateTimeParsing(testInput[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserExecutePriorityParsingTest) {
		// test cases after testText[6] are false cases and will throw exceptions
		string testText[] = { "high", "h", "MEDIUM", "MED", "M", "Low", "L", "test", " ", "" };
		string expectedCommand = "priority";
		string expectedText[] = { "high", "high", "medium", "medium", "medium", "low", "low" };
		string expectedTextFalse = "Invalid priority";

		for (int i = 0; i < 10; i++) {
			try {
				testParser.executePriorityParsing(testText[i]);
			} catch (string& exceptionMessage) {
				Assert::AreEqual(expectedTextFalse, exceptionMessage);
			}
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserExecuteRemoveParsingTest) {
		string testInput[] = { "date", "START", "End", "description", "DESC", "Priority", "p", "test", " " };
		string expectedCommand[] = { "start", "end", "start", "end", "description", "description", "priority", "priority" };
		string expectedText[] = { "-2 -2 -2 -2 -2", "-2 -2 -2 -2 -2", "-2 -2 -2 -2 -2", "-2 -2 -2 -2 -2", "", "", "", "" };

		for (int i = 0; i < 9; i++) {
			try {
				testParser.executeRemoveParsing(testInput[i]);
			} catch (string& exceptionMessage) {
				string expected = "Invalid remove";
				Assert::AreEqual(expected, exceptionMessage);
			}
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserRetrieveCommandOrModifierTest) {
		string testInput[] = { "ADD   ", "DeLeTe\t\t\t", "-dAtE   ", "-desc\t\t\t", " ", "" };
		string expected[] = { "add", "delete", "-date", "-desc", "", "" };

		for (int i = 0; i < 6; i++) {
			string actual = testParser.retrieveCommandOrModifier(testInput[i]);
			Assert::AreEqual(expected[i], actual);
		}
	}

	TEST_METHOD(parserTokeniseTextTest) {
		// as hyphen is used as the modifier identifier, cases created tests to see
		//if it recognises the allowed modifiers
		vector<string> testVector;
		string testInput = "test -name testName -date te-st -due t-e-s-t -start 10AM -end 10PM -desc test ---label -priority te-descst -remove date -rmv desc";
		string expected[] = { "test", "-name testName", "-date te-st", "-due t-e-s-t", "-start 10AM", "-end 10PM", "-desc test ---label", "-priority te-descst", "-remove date", "-rmv desc" };

		testVector = testParser.tokeniseText(testInput);

		for (unsigned int i = 0; i < testVector.size(); i++) {
			string actual = testVector[i];
			Assert::AreEqual(expected[i], actual);
		}

		vector<string> testVectorWhiteSpace;
		string testWhiteSpace = " ";
		string expectedWS = "";

		testVectorWhiteSpace = testParser.tokeniseText(testWhiteSpace);

		for (unsigned int i = 0; i < testVectorWhiteSpace.size(); i++) {
			string actual = testVectorWhiteSpace[i];
			Assert::AreEqual(expectedWS, actual);
		}
	}

	TEST_METHOD(parserRemoveFirstStringTokenTest) {
		// testCases after testInput[1] will return blank as there is no text beyong first string, if any
		string testInput[] = { "add text", "del text", "exit", " ", "" };
		string expected[] = { "text", "text", "", "", "" };

		for (int i = 0; i < 5; i++) {
			string actual = testParser.removeFirstStringToken(testInput[i]);
			Assert::AreEqual(expected[i], actual);
		}
	}

	TEST_METHOD(parserRemoveConsecutiveWhiteSpace) {
		string actual = "   1 2 \t 3 \t 4 5\t\t\t";
		string expected = " 1 2 3 4 5\t";
		string actualWhiteSpace = "  \t\t  ";
		string expectedWhiteSpace = " ";
		string actualBlank = "";
		string expectedBlank = "";

		testParser.removeConsecutiveWhiteSpace(actual);
		Assert::AreEqual(expected, actual);
		testParser.removeConsecutiveWhiteSpace(actualWhiteSpace);
		Assert::AreEqual(expectedWhiteSpace, actualWhiteSpace);
		testParser.removeConsecutiveWhiteSpace(actualBlank);
		Assert::AreEqual(expectedBlank, actualBlank);
	}

	TEST_METHOD(parserRemoveWhiteSpace) {
		string actual = "   1 2 \t 3 \t 4 5\t\t\t";
		string expected = "12345";
		string actualWhiteSpace = "  \t\t  ";
		string expectedWhiteSpace = "";

		testParser.removeWhiteSpace(actual);
		Assert::AreEqual(expected, actual);
		testParser.removeWhiteSpace(actualWhiteSpace);
		Assert::AreEqual(expectedWhiteSpace, actualWhiteSpace);
	}

	TEST_METHOD(parserConvertToLowerCaseTest) {
		string actual = "ABCDEFGHIJKLM123456789NOPQRSTUVWXYZ";
		string expected = "abcdefghijklm123456789nopqrstuvwxyz";

		testParser.convertToLowerCase(actual);
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(parserTrimTextTest) {
		string testText[] = { "   add text   ", "\t\t del text \t\t\t", "  exit\t\t", " ", "" };
		string expected[] = { "add text", "del text", "exit", "", "" };

		for (int i = 0; i < 5; i++) {
			testParser.trimText(testText[i]);
			string actual = testText[i];
			Assert::AreEqual(expected[i], actual);
		}
	}

	TEST_METHOD(parserHasStartEndTest) {
		string testDateTime[] = { "10/11/12 to 12/11/12", "10 November 12-12 November 2012", "10 Nov 2012, 12Pm", "1030, 11 Sep 2015" };

		for (int i = 0; i < 4; i++) {
			bool actual = testParser.hasStartEndDateTime(testDateTime[i]);
			if (i < 2) {
				Assert::IsTrue(actual);
			} else {
				Assert::IsFalse(actual);
			}
		}
	}

	TEST_METHOD(parserSetDateTimeTest) {
		string testDateTime[] = { "10/11/12, 10:30PM", "10 November 12, 900AM", "23 Mar, 23:59 PM", "11 Sep, 130PM", "1030hr, 10/11/12", "930PM, 10 Dec 2015", "1pm" };
		string expectedDateTime[] = { "12 11 10 22 30", "12 11 10 9 00", "-1 3 23 23 59", "-1 9 11 13 30", "12 11 10 10 30", "2015 12 10 21 30", "-1 -1 -1 13 00" };
		string expectedCommand[] = { "start", "end" };

		for (int i = 0; i < 7; i++) {
			testParser.setDateTime(testDateTime[i], "date");
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expectedDateTime[i], actualDateTime);
			Assert::AreEqual(expectedCommand[0], actualCommand);
		}

		testParser.clearParseInfo();

		for (int i = 0; i < 7; i++) {
			testParser.setDateTime(testDateTime[i], "due");
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expectedDateTime[i], actualDateTime);
			Assert::AreEqual(expectedCommand[1], actualCommand);
		}

		testParser.clearParseInfo();

		for (int i = 0; i < 7; i++) {
			testParser.setDateTime(testDateTime[i], "start");
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expectedDateTime[i], actualDateTime);
			Assert::AreEqual(expectedCommand[0], actualCommand);
		}

		testParser.clearParseInfo();

		for (int i = 0; i < 7; i++) {
			testParser.setDateTime(testDateTime[i], "end");
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expectedDateTime[i], actualDateTime);
			Assert::AreEqual(expectedCommand[1], actualCommand);
		}
	}

	TEST_METHOD(parserSplitAndSetDateTimeTest) {
		string testDateTime[] = { "10/11/12, 6pm", "2200hr, 10 Nov 12", "8/9, 1pm", "2am, 10/11" };
		string expected[] = { "12 11 10 18 00", "12 11 10 22 00", "-1 9 8 13 00", "-1 11 10 2 00", "-1 -1 monday 13 00" };
		string expectedCommand = "end";

		for (int i = 0; i < 4; i++) {
			testParser.splitAndSetDateTime(testDateTime[i], "end");
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expected[i], actualDateTime);
			Assert::AreEqual(expectedCommand, actualCommand);
		}
	}

	TEST_METHOD(parserSplitAndSetStartEndDateTimeTest) {
		string testDatesForNoComma[] = { "10AM to 1PM", "930AM to 1230PM", "1 Oct to 23 Oct", "1 Oct 2012 - 23 Oct 2015" };
		string expectedStartForNoComma[] = { "-1 -1 -1 10 00", "-1 -1 -1 9 30", "-1 10 1 -1 -1", "2012 10 1 -1 -1" };
		string expectedEndForNoComma[] = { "-1 -1 -1 13 00", "-1 -1 -1 12 30", "-1 10 23 -1 -1", "2015 10 23 -1 -1" };

		string testDatesForOneComma[] = { "10 Nov 12, 10am to 10PM", "930AM - 1130PM, 9/11" };
		string expectedStartForOneComma[] = { "12 11 10 10 00", "-1 11 9 9 30" };
		string expectedEndForOneComma[] = { "12 11 10 22 00", "-1 11 9 23 30" };

		string testDatesForTwoCommas[] = { "10 Nov 12, 10am to 20 Nov 12, 10PM", "930AM, 11/9 - 130PM, 9/11" };
		string expectedStartForTwoCommas[] = { "12 11 10 10 00", "-1 9 11 9 30" };
		string expectedEndForTwoCommas[] = { "12 11 20 22 00", "-1 11 9 13 30" };

		string start = "start";
		string end = "end";

		for (int i = 0; i < 4; i++) {
			testParser.splitAndSetStartEndDateTime(testDatesForNoComma[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;

			if (i % 2 == 0) {
				Assert::AreEqual(start, actualCommand);
				Assert::AreEqual(expectedStartForNoComma[i / 2], actualText);
			} else {
				Assert::AreEqual(end, actualCommand);
				Assert::AreEqual(expectedEndForNoComma[i / 2], actualText);
			}
		}

		testParser.clearParseInfo();

		for (int i = 0; i < 2; i++) {
			testParser.splitAndSetStartEndDateTime(testDatesForOneComma[i]);
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;

			if (i % 2 == 0) {
				Assert::AreEqual(start, actualCommand);
				Assert::AreEqual(expectedStartForOneComma[i / 2], actualText);
			} else {
				Assert::AreEqual(end, actualCommand);
				Assert::AreEqual(expectedEndForOneComma[i / 2], actualText);
			}
		}

		testParser.clearParseInfo();

		for (int i = 0; i < 2; i++) {
			testParser.splitAndSetStartEndDateTime(testDatesForTwoCommas[i]);
		}

		testList = testParser.getParseInfo();
		iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;

			if (i % 2 == 0) {
				Assert::AreEqual(start, actualCommand);
				Assert::AreEqual(expectedStartForTwoCommas[i / 2], actualText);
			} else {
				Assert::AreEqual(end, actualCommand);
				Assert::AreEqual(expectedEndForTwoCommas[i / 2], actualText);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetViewDateRangeTest) {
		string testDateRange[] = { "10 Apr to 10 May", "abc to def" };
		string expectedCommand = "view";
		string expectedText[] = { "date -1 4 10 -1 -1 -1 5 10 -1 -1", "date -1 4 10 -1 -1 -1 4 10 -1 -1" };

		for (int i = 0; i < 1; i++) {
			try {
				testParser.splitAndSetViewDateRange(testDateRange[i]);
			} catch (string& exceptionMessage) {
				string expected = "Invalid date time";
				Assert::AreEqual(expected, exceptionMessage);
			}
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserSplitAndSetNoCommaStartEndDateTimeTest) {
		string testDates[] = { "10AM to 1PM", "930AM to 1230PM", "1 Oct to 23 Oct", "1 Oct 2012 - 23 Oct 2015" };
		string expectedStart[] = { "-1 -1 -1 10 00", "-1 -1 -1 9 30", "-1 10 1 -1 -1", "2012 10 1 -1 -1" };
		string expectedEnd[] = { "-1 -1 -1 13 00", "-1 -1 -1 12 30", "-1 10 23 -1 -1", "2015 10 23 -1 -1" };
		string start = "start";
		string end = "end";

		for (int i = 0; i < 4; i++) {
			testParser.splitAndSetNoCommaStartEndDateTime(testDates[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;

			if (i % 2 == 0) {
				Assert::AreEqual(start, actualCommand);
				Assert::AreEqual(expectedStart[i / 2], actualText);
			} else {
				Assert::AreEqual(end, actualCommand);
				Assert::AreEqual(expectedEnd[i / 2], actualText);
			}
		}
	}

	TEST_METHOD(parsersplitAndSetOneCommaStartEndDateTimeTest) {
		string testDates[] = { "10 Nov 12, 10am to 10PM", "930AM - 1130PM, 9/11" };
		string expectedStart[] = { "12 11 10 10 00", "-1 11 9 9 30" };
		string expectedEnd[] = { "12 11 10 22 00", "-1 11 9 23 30" };
		string start = "start";
		string end = "end";

		for (int i = 0; i < 2; i++) {
			testParser.splitAndSetOneCommaStartEndDateTime(testDates[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;

			if (i % 2 == 0) {
				Assert::AreEqual(start, actualCommand);
				Assert::AreEqual(expectedStart[i / 2], actualText);
			} else {
				Assert::AreEqual(end, actualCommand);
				Assert::AreEqual(expectedEnd[i / 2], actualText);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetTwoCommaStartEndDateTimeTest) {
		string testDates[] = { "10 Nov 12, 10am to 20 Nov 12, 10PM", "930AM, 11/9 - 130PM, 9/11" };
		string expectedStart[] = { "12 11 10 10 00", "-1 9 11 9 30" };
		string expectedEnd[] = { "12 11 20 22 00", "-1 11 9 13 30" };
		string start = "start";
		string end = "end";

		for (int i = 0; i < 2; i++) {
			testParser.splitAndSetTwoCommaStartEndDateTime(testDates[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter = testList.begin();

		for (int i = 0; iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;

			if (i % 2 == 0) {
				Assert::AreEqual(start, actualCommand);
				Assert::AreEqual(expectedStart[i / 2], actualText);
			} else {
				Assert::AreEqual(end, actualCommand);
				Assert::AreEqual(expectedEnd[i / 2], actualText);
			}
		}
	}

	TEST_METHOD(parserIsValidDateTest) {
		string testDates[] = { "10/ 11/ 12", " 11/12\t", "9 Jan 10", "10 November 12", "15 FEB", "11 Sep" };
		string testDatesFalse[] = { "10a/11b/12c", "10 Novmbr 12", "10/test/12", "monday march", "10", "11/12/13/14", "11/12/", "11/" };
		string expected[] = { "12 11 10", "-1 12 11", "10 1 9", "12 11 10", "-1 2 15", "-1 9 11", "-1 -1 monday", "-1 -1 tuesday" };
		string expectedFalse = "";

		for (int i = 0; i < 6; i++) {
			string actualDateTrue = "";
			string actualDateFalse = "";
			bool actualTrue = testParser.isValidDate(testDates[i], actualDateTrue);
			bool actualFalse = testParser.isValidDate(testDatesFalse[i], actualDateFalse);
			Assert::IsTrue(actualTrue);
			Assert::AreEqual(expected[i], actualDateTrue);
			Assert::IsFalse(actualFalse);
			Assert::AreEqual(expectedFalse, actualDateFalse);
		}
	}

	TEST_METHOD(parserIsValidTimeTest) {
		string testTimes[] = { "00 : 59", "10:59PM", "10:59 pm", "1059AM", "930 am", "10 pm", "930pm", "1 pm" };
		string testTimesFalse[] = { "10::59", "10a:59b", "10a:59bpm", "1059bpm", "1", "10", "12345", "030" };
		string expected[] = { "00 59", "22 59", "22 59", "10 59", "9 30", "22 00", "21 30", "13 00" };
		string expectedFalse = "";

		for (int i = 0; i < 8; i++) {
			string actualTimeTrue = "";
			string actualTimeFalse = "";
			bool actualTrue = testParser.isValidTime(testTimes[i], actualTimeTrue);
			bool actualFalse = testParser.isValidTime(testTimesFalse[i], actualTimeFalse);
			Assert::IsTrue(actualTrue);
			Assert::AreEqual(expected[i], actualTimeTrue);
			Assert::IsFalse(actualFalse);
			Assert::AreEqual(expectedFalse, actualTimeFalse);
		}
	}

	TEST_METHOD(parserSplitAndSetObliqueDateInformationTest) {
		// test cases after testDate[1] are false as either there are alphabets or invalid date input
		string testDate[] = { "10/11/12", "10/11", "10/", "10/11/", "ab/11/2015", "10/ab/2015", "10/11/ab", "10//", "//10" };
		unsigned int numberOfOblique[] = { 2, 1, 1, 2, 2, 2, 2, 2, 2, 2 };
		string expected[] = { "12 11 10", "-1 11 10" };

		for (int i = 0; i < 9; i++) {
			try {
				string actual = testParser.splitAndSetObliqueDateInformation(testDate[i], numberOfOblique[i]);
				Assert::AreEqual(expected[i], actual);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetSpaceDateInformationTest) {
		// test cases after testDate[1] are false as either there are invalid strings or invalid date input
		string testDate[] = { "10 nOv 2015", "9 OcT", "12 abc", "abc apr", "abc mar 2015", "12 12 12", "12 mar abc" };
		unsigned int numberOfSpace[] = { 2, 2, 1, 1, 2, 2, 2, };
		string expected[] = { "2015 11 10", "-1 10 9", "-1 -1 monday" };

		for (int i = 0; i < 7; i++) {
			try {
				string actualOne = testParser.splitAndSetSpaceDateInformation(testDate[i], numberOfSpace[i]);
				Assert::AreEqual(expected[i], actualOne);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetTimeStringTest) {
		string testTimeColonAM[] = { "10:11", "09:10", "2:30", "11:59", "11", "1" };
		string testTimeColonPM[] = { "10:11", "09:10", "13:30", "2:30", "11", "1" };
		string testTimeColonHR[] = { "10:11", "09:10", "13:30", "02:30", "23:59", "00:00" };
		string testTimeSpaceAM[] = { "1011", "0910", "230", "1159", "11", "1" };
		string testTimeSpacePM[] = { "1011", "0910", "1330", "230", "11", "1" };
		string testTimeSpaceHR[] = { "1011", "0910", "1330", "0230", "2359", "0000" };
		string expectedAM[] = { "10 11", "09 10", "2 30", "11 59", "11 00", "1 00" };
		string expectedPM[] = { "22 11", "21 10", "13 30", "14 30", "23 00", "13 00" };
		string expectedHR[] = { "10 11", "09 10", "13 30", "02 30", "23 59", "00 00" };

		for (int i = 0; i < 1; i++) {
			string actualColonAM = testParser.splitAndSetTimeString(testTimeColonAM[i], "am");
			string actualColonPM = testParser.splitAndSetTimeString(testTimeColonPM[i], "pm");
			string actualColonHR = testParser.splitAndSetTimeString(testTimeColonHR[i], "hr");
			string actualSpaceAM = testParser.splitAndSetTimeString(testTimeSpaceAM[i], "am");
			string actualSpacePM = testParser.splitAndSetTimeString(testTimeSpacePM[i], "pm");
			string actualSpaceHR = testParser.splitAndSetTimeString(testTimeSpaceHR[i], "hr");
			Assert::AreEqual(expectedAM[i], actualColonAM);
			Assert::AreEqual(expectedPM[i], actualColonPM);
			Assert::AreEqual(expectedAM[i], actualColonHR);
			Assert::AreEqual(expectedAM[i], actualSpaceAM);
			Assert::AreEqual(expectedPM[i], actualSpacePM);
			Assert::AreEqual(expectedAM[i], actualSpaceHR);
		}
	}

	TEST_METHOD(parserSplitAndSetColonTimeStringTest) {
		string testTime[] = { "10:11", "9:10", "13:30", "23:59" };
		string expectedAM[] = { "10 11", "9 10" };
		string expectedPM[] = { "22 11", "21 10", "13 30", "23 59" };
		string expectedHR[] = { "10 11", "9 10", "13 30", "23 59" };

		for (int i = 0; i < 1; i++) {
			string testString = testTime[i];

			string actual = testParser.splitAndSetColonTimeString(testString, "");
			string actualPM = testParser.splitAndSetColonTimeString(testString, "pm");
			string actualHR = testParser.splitAndSetColonTimeString(testString, "hr");
			Assert::AreEqual(expectedAM[i], actual);
			Assert::AreEqual(expectedPM[i], actualPM);
			Assert::AreEqual(expectedAM[i], actualHR);

			if (i < 2) {
				string actualAM = testParser.splitAndSetColonTimeString(testString, "am");
				Assert::AreEqual(expectedAM[i], actualAM);
			}
		}

		string testTimeFalse[] = { "1:1", "12:1", "123:23", "ab:cd", "123:123" };

		for (int i = 0; i < 5; i++) {
			try {
				string actual = testParser.splitAndSetColonTimeString(testTimeFalse[i], "");
				// this is done to check that all exceptions are thrown
				string expected = "";
				Assert::AreEqual(expected, actual);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetNoColonTimeStringTest) {
		string testTimeAM[] = { "1011", "0910", "230", "1159", "11", "1" };
		string testTimePM[] = { "1011", "0910", "1330", "230", "11", "1" };
		string testTimeHR[] = { "1011", "0910", "1330", "0230", "2359", "0000" };
		string expectedAM[] = { "10 11", "09 10", "2 30", "11 59", "11 00", "1 00" };
		string expectedPM[] = { "22 11", "21 10", "13 30", "14 30", "23 00", "13 00" };
		string expectedHR[] = { "10 11", "09 10", "13 30", "02 30", "23 59", "00 00" };

		for (int i = 0; i < 6; i++) {
			string actualAM = testParser.splitAndSetNoColonTimeString(testTimeAM[i], "am");
			Assert::AreEqual(expectedAM[i], actualAM);
			string actualPM = testParser.splitAndSetNoColonTimeString(testTimePM[i], "pm");
			Assert::AreEqual(expectedPM[i], actualPM);
			string actualHR = testParser.splitAndSetNoColonTimeString(testTimeHR[i], "hr");
			Assert::AreEqual(expectedHR[i], actualHR);
		}

		string testTimeAMFail[] = { "2359", "abcd", "12345", "a" };
		string testTimePMFail[] = { "0", "0030", "abcd", "12345" };
		string testTimeHRFail[] = { "1", "12", "123", "12345" };

		for (int i = 0; i < 4; i++) {
			try {
				string actualAM = testParser.splitAndSetNoColonTimeString(testTimeAMFail[i], "am");
				// this is done to check that all exceptions are thrown
				string expected = "";
				Assert::AreEqual(expected, actualAM);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}

			try {
				string actualPM = testParser.splitAndSetNoColonTimeString(testTimePMFail[i], "pm");
				// this is done to check that all exceptions are thrown
				string expected = "";
				Assert::AreEqual(expected, actualPM);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}

			try {
				string actualHR = testParser.splitAndSetNoColonTimeString(testTimeHRFail[i], "hr");
				// this is done to check that all exceptions are thrown
				string expected = "";
				Assert::AreEqual(expected, actualHR);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}

			try {
				string actualHR = testParser.splitAndSetNoColonTimeString(testTimeHRFail[i], "");
				// this is done to check that all exceptions are thrown
				string expected = "";
				Assert::AreEqual(expected, actualHR);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}
		}
	}

	TEST_METHOD(parserIsMonthAndSetMonthTest) {
		string testMonth[] = { "January", "february", "March", "april", "May", "june",
			"July", "august", "September", "october", "November", "december" };
		string testMonthShortForm[] = { "JAN", "feb", "MAR", "apr", "MAY", "jun",
			"JUL", "aug", "SEP", "oct", "NOV", "dec" };
		string testMonthFalse[] = { "janr", "febr", "mach", "aprl", "my", "jn",
			"jool", "augst", "sept", "octbr", "novmbr", "decmbr" };
		string expectedMonth[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };

		for (int i = 0; i < 12; i++) {
			bool actualBoolean = testParser.isMonth(testMonth[i]);
			string actualMonth = testParser.setMonth(testMonth[i]);
			Assert::IsTrue(actualBoolean);
			Assert::AreEqual(expectedMonth[i], actualMonth);
		}

		for (int i = 0; i < 12; i++) {
			bool actualBoolean = testParser.isMonth(testMonthShortForm[i]);
			string actualMonth = testParser.setMonth(testMonthShortForm[i]);
			Assert::IsTrue(actualBoolean);
			Assert::AreEqual(expectedMonth[i], actualMonth);
		}

		for (int i = 0; i < 12; i++) {
			string expected = "";
			bool actualBoolean = testParser.isMonth(testMonthFalse[i]);
			string actualMonth = testParser.setMonth(testMonthFalse[i]);
			Assert::IsFalse(actualBoolean);
			Assert::AreEqual(expected, actualMonth);
		}
	}

	TEST_METHOD(parserHasTimePeriodSuffixTest) {
		string testTime[] = { "1010AM", "1010PM", "1010aM", "1010Pm", "1010am", "1010pm" };
		string testTimeFalse[] = { "1010", "1010mp", "1010ma", "1010cs", "PM", "AM" };

		for (int i = 0; i < 6; i++) {
			bool actual = testParser.hasTimePeriodSuffix(testTime[i]);
			Assert::IsTrue(actual);
		}

		for (int i = 0; i < 6; i++) {
			bool actual = testParser.hasTimePeriodSuffix(testTimeFalse[i]);
			Assert::IsFalse(actual);
		}
	}

	TEST_METHOD(parserAddTwelveToHoursTest) {
		// test cases after testHour[6] are false as hour is either 0 or non-digit
		string testHour[] = { "1", "6", "11", "12", "18", "23", "09", "0", "abc", "@@@" };
		string expected[] = { "13", "18", "23", "12", "18", "23", "21" };

		for (int i = 0; i < 10; i++) {
			try {
				string actual = testParser.addTwelveToHours(testHour[i]);
				Assert::AreEqual(expected[i], actual);
			} catch (bool& exception) {
				bool expected = false;
				Assert::IsFalse(exception);
			}
		}
	}

	TEST_METHOD(parserIsAppropriateAMHourTest) {
		// test cases after testHour[4] are false as it is not within the acceptable range for hours in AM
		string testHour[] = { "1", "6", "11", "06", "12", "18", "23" };

		for (int i = 0; i < 7; i++) {
			bool actual = testParser.isAppropriateAMHour(testHour[i]);
			if (i < 5) {
				Assert::IsTrue(actual);
			} else {
				Assert::IsFalse(actual);
			}
		}
	}

	TEST_METHOD(parserIsAppropriateTimeTest) {
		// testCases after index 6 are false as one of the strings are violated
		// [7] and [8] have alphabetical strings, [9] and [10] have non-2-digit string, and [11] has 2359 set as AM
		string testHour[] = { "1", "6", "11", "12", "18", "23", "09", "abc", "10", "123", "10", "23" };
		string testMinute[] = { "00", "10", "20", "30", "40", "50", "59", "00", "abc", "00", "123", "59" };
		string testSuffix[] = { "pm", "am", "pm", "am", "pm", "pm", "pm", "pm", "pm", "pm", "pm", "am" };

		for (int i = 0; i < 12; i++) {
			bool actual = testParser.isAppropriateTime(testHour[i], testMinute[i], testSuffix[i]);
			if (i < 7) {
				Assert::IsTrue(actual);
			} else {
				Assert::IsFalse(actual);
			}
		}
	}

	TEST_METHOD(parserHasNoDayButHasTimeTest) {
		// testDateTimeString[2] is true as it has no date (3rd set of string) and has time (last 2 set of string)
		string testDateTimeString[] = { "-1 -1 monday 23 59", "2015 10 10 23 59", "2015 10 -1 23 59" };

		for (int i = 0; i < 3; i++) {
			bool actual = testParser.hasNoDayButHasTime(testDateTimeString[i]);
			if (i < 2) {
				Assert::IsFalse(actual);
			} else {
				Assert::IsTrue(actual);
			}
		}
	}

	TEST_METHOD(parserIsModifierTest) {
		string testString[] = { "-NAME", "-DaTe", "-dUe", "-start", "-end", "-Desc", "-dESCRIPTION", "-pRiORiTy", "-P", "-remove", "-RmV" };
		string testStringfalse[] = { "-names", "-descrb", "-123", "-abc", "-", " " };

		for (int i = 0; i < 11; i++) {
			bool actual = testParser.isModifier(testString[i]);
			Assert::IsTrue(actual);
		}

		for (int i = 0; i < 6; i++) {
			bool actualFalse = testParser.areDigits(testStringfalse[i]);
			Assert::IsFalse(actualFalse);
		}

	}

	TEST_METHOD(parserAreDigitsTest) {
		string testString = "123456789";
		string testStringfalse[] = { "123a456b789c", "123 456 789", " " };

		bool actual = testParser.areDigits(testString);
		Assert::IsTrue(actual);

		for (int i = 0; i < 3; i++) {
			bool actualFalse = testParser.areDigits(testStringfalse[i]);
			Assert::IsFalse(actualFalse);
		}

	}

	TEST_METHOD(parserIsWhiteSpaceTest) {
		char testChar[] = { ' ', '\t' };
		char testCharFalse[] = { 'a', '1', '/' };

		for (int i = 0; i < 2; i++) {
			bool actual = testParser.isWhiteSpace(testChar[i]);
			Assert::IsTrue(actual);
		}

		for (int i = 0; i < 3; i++) {
			bool actual = testParser.isWhiteSpace(testCharFalse[i]);
			Assert::IsFalse(actual);
		}
	}

	TEST_METHOD(parserRetrieveCountTest) {
		string testString[] = { ",one,two,three,four,five,", "   " };
		unsigned int expected[] = { 6, 0 };

		for (int i = 0; i < 2; i++) {
			unsigned int actual = testParser.retrieveCount(testString[i], ',');
			Assert::AreEqual(expected[i], actual);
		}
	}

	};
}