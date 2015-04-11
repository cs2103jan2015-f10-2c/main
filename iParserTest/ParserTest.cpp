#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {

	TEST_CLASS(iPlannerParserTest) {
private:
	iParser testParser;
public:

	/*TEST_METHOD(parserExecuteAddParsingTest) {
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
		}*/

	/*TEST_METHOD(parserExecuteEditParsing) {
		string testInput = "23 -date 10 Nov 2012, 6:30PM";
		string expectedCommand[] = { "edit", "start" };
		string expectedText[] = { "23", "2012 11 10 18 30" };

		testParser.executeEditParsing(testInput);

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
		string actualCommand = iter->command;
		string actualText = iter->text;
		Assert::AreEqual(expectedCommand[i], actualCommand);
		Assert::AreEqual(expectedText[i], actualText);
		}
		}*/

	TEST_METHOD(parserExecuteCommandAndTextParsingTest) {
		// testText[4] tests for invalid case where blank string is not allowed
		string testCommand[] = { "del", "del", "search", "sort", "view" };
		string testText[] = { "123", "123abc", "abc", " ", "" };
		string expectedCommand[] = { "del", "del", "search", "sort", "invalid" };
		string expectedText[] = { "123", "123abc", "abc", " ", "Invalid input" };

		for (int i = 0; i < 5; i++) {
			testParser.executeCommandAndTextParsing(testCommand[i], testText[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserExecuteCommandParsingTest) {
		// testText[1] and testText[3] tests for invalid commands where there
		// are invalid texts after the commands
		string testCommand[] = { "undo", "undo", "exit", "exit" };
		string testText[] = { "undo", "undo 123", "exit", "exit abc" };
		string expectedCommand[] = { "undo", "invalid", "exit", "invalid" };
		string expectedText[] = { "", "Invalid command", "", "Invalid command" };

		for (int i = 0; i < 4; i++) {
			testParser.executeCommandParsing(testCommand[i], testText[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
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
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserExecuteSearchParsingTest) {
		string testInput = "test";
		string expectedCommand = "search";
		string expectedText = "test";

		testParser.executeSearchParsing(testInput);
	
		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedText, actualText);
		}

		testParser.clearParseInfo();

		string testInputPlus = "test + abc + 123 + @@@";
		string expectedTextPlus[] = { "test", "abc", "123", "@@@" };

		testParser.executeSearchParsing(testInputPlus);

		testList = testParser.getParseInfo();
		i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand, actualCommand);
			Assert::AreEqual(expectedTextPlus[i], actualText);
		}
	}

	TEST_METHOD(parserExecuteRemoveParsingTest) {
		string testText[] = { "date", "start", "end", "description", "desc", "priority", "p" };
		string expectedCommand[] = { "start", "end", "start", "end", "description", "description", "priority", "priority" };
		string expectedText[] = { "-1 -1 -1 -1 -1", "-1 -1 -1 -1 -1", "-1 -1 -1 -1 -1", "-1 -1 -1 -1 -1", "", "", "", "" };

		for (int i = 0; i < 7; i++) {
			testParser.executeRemoveParsing(testText[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}
	}

	TEST_METHOD(parserCheckAndSetTokenisedInformationTest) {
		// testInput[0] is added but not tested as the function starts from index = 1 where the modifiers starts from
		string testInput[] = { "edit 1", "-name testName", "-desc WEAR FORMAL", "-date 12/11/10, 10PM", "-p H" };
		string expectedCommand[] = { "name", "description", "start", "priority" };
		string expectedText[] = { "testName", "WEAR FORMAL", "10 11 12 22 00", "high" };
		vector<string> testVector;

		for (int i = 0; i < 5; i++) {
			testVector.push_back(testInput[i]);
		}

		testParser.checkAndSetTokenisedInformation(testVector, "edit");

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommand[i], actualCommand);
			Assert::AreEqual(expectedText[i], actualText);
		}

		testParser.clearParseInfo();

		string testInputRemove[] = { "edit 2", "-remove date" };
		string expectedCommandRemove[] = { "start", "end" };
		string expectedTextRemove = "-1 -1 -1 -1 -1";

		testVector.clear();
		for (int i = 0; i < 2; i++) {
			testVector.push_back(testInputRemove[i]);
		}

		testParser.checkAndSetTokenisedInformation(testVector, "edit");

		testList = testParser.getParseInfo();
		i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualText = iter->text;
			Assert::AreEqual(expectedCommandRemove[i], actualCommand);
			Assert::AreEqual(expectedTextRemove, actualText);
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
		string testInput = "test -name testName -date te-st -due t-e-s-t -start 10AM -end 10PM -desc test ---label -priority te-descst";
		string expected[] = { "test", "-name testName", "-date te-st", "-due t-e-s-t", "-start 10AM", "-end 10PM", "-desc test ---label", "-priority te-descst" };

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

		testParser.removeConsecutiveWhiteSpace(actual);
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(parserRemoveWhiteSpace) {
		string actual = "   1 2 \t 3 \t 4 5\t\t\t";
		string expected = "12345";

		testParser.removeWhiteSpace(actual);
		Assert::AreEqual(expected, actual);
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
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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
		i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expectedDateTime[i], actualDateTime);
			Assert::AreEqual(expectedCommand[1], actualCommand);
		}
	}

	TEST_METHOD(parserSplitAndSetDateTimeTest) {
		string testDateTime[] = { "10/11/12, 6pm", "2200hr, 10 Nov 12", "8/9, 1pm", "2am, 10/11", "monday, 1pm" };
		string expected[] = { "12 11 10 18 00", "12 11 10 22 00", "-1 9 8 13 00", "-1 11 10 2 00", "-1 -1 monday 13 00" };
		string expectedCommand = "end";

		for (int i = 0; i < 5; i++) {
			testParser.splitAndSetDateTime(testDateTime[i], "end");
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
			string actualCommand = iter->command;
			string actualDateTime = iter->text;
			Assert::AreEqual(expected[i], actualDateTime);
			Assert::AreEqual(expectedCommand, actualCommand);
		}
	}

	TEST_METHOD(parserSplitAndSetStartEndTest) {
		string testDatesForNoComma[] = { "10AM to 1PM", "930AM to 1230PM", "1 Oct to 23 Oct", "1 Oct 2012 - 23 Oct 2015", "mon to wed" };
		string expectedStartForNoComma[] = { "-1 -1 -1 10 00", "-1 -1 -1 9 30", "-1 10 1 -1 -1", "2012 10 1 -1 -1", "-1 -1 monday -1 -1" };
		string expectedEndForNoComma[] = { "-1 -1 -1 13 00", "-1 -1 -1 12 30", "-1 10 23 -1 -1", "2015 10 23 -1 -1", "-1 -1 wednesday -1 -1" };

		string testDatesForOneComma[] = { "10 Nov 12, 10am to 10PM", "930AM - 1130PM, 9/11", "monday, 13:59 - 23:59" };
		string expectedStartForOneComma[] = { "12 11 10 10 00", "-1 11 9 9 30", "-1 -1 monday 13 59" };
		string expectedEndForOneComma[] = { "12 11 10 22 00", "-1 11 9 23 30", "-1 -1 monday 23 59" };

		string testDatesForTwoCommas[] = { "10 Nov 12, 10am to 20 Nov 12, 10PM", "930AM, 11/9 - 130PM, 9/11", "monday, 0300hr to fri, 1559hr" };
		string expectedStartForTwoCommas[] = { "12 11 10 10 00", "-1 9 11 9 30", "-1 -1 monday 03 00" };
		string expectedEndForTwoCommas[] = { "12 11 20 22 00", "-1 11 9 13 30", "-1 -1 friday 15 59" };

		string start = "start";
		string end = "end";

		for (int i = 0; i < 5; i++) {
			testParser.splitAndSetNoCommaStartEndDateTime(testDatesForNoComma[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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

		for (int i = 0; i < 3; i++) {
			testParser.splitAndSetNoCommaStartEndDateTime(testDatesForNoComma[i]);
		}

		testList = testParser.getParseInfo();
		iter;
		i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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

		for (int i = 0; i < 3; i++) {
			testParser.splitAndSetNoCommaStartEndDateTime(testDatesForNoComma[i]);
		}

		testList = testParser.getParseInfo();
		iter;
		i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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
	}

	TEST_METHOD(parserSplitAndSetNoCommaStartEndDateTimeTest) {
		string testDates[] = { "10AM to 1PM", "930AM to 1230PM", "1 Oct to 23 Oct", "1 Oct 2012 - 23 Oct 2015", "mon to wed" };
		string expectedStart[] = { "-1 -1 -1 10 00", "-1 -1 -1 9 30", "-1 10 1 -1 -1", "2012 10 1 -1 -1", "-1 -1 monday -1 -1" };
		string expectedEnd[] = { "-1 -1 -1 13 00", "-1 -1 -1 12 30", "-1 10 23 -1 -1", "2015 10 23 -1 -1", "-1 -1 wednesday -1 -1" };
		string start = "start";
		string end = "end";

		for (int i = 0; i < 5; i++) {
			testParser.splitAndSetNoCommaStartEndDateTime(testDates[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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

	TEST_METHOD(parsersplitAndSetTwoCommaStartEndDateTimeTest) {
		string testDates[] = { "10 Nov 12, 10am to 10PM", "930AM - 1130PM, 9/11", "monday, 13:59 - 23:59" };
		string expectedStart[] = { "12 11 10 10 00", "-1 11 9 9 30", "-1 -1 monday 13 59" };
		string expectedEnd[] = { "12 11 10 22 00", "-1 11 9 23 30", "-1 -1 monday 23 59" };
		string start = "start";
		string end = "end";

		for (int i = 0; i < 3; i++) {
			testParser.splitAndSetOneCommaStartEndDateTime(testDates[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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
		string testDates[] = { "10 Nov 12, 10am to 20 Nov 12, 10PM", "930AM, 11/9 - 130PM, 9/11", "monday, 0300hr to fri, 1559hr" };
		string expectedStart[] = { "12 11 10 10 00", "-1 9 11 9 30", "-1 -1 monday 03 00" };
		string expectedEnd[] = { "12 11 20 22 00", "-1 11 9 13 30", "-1 -1 friday 15 59" };
		string start = "start";
		string end = "end";

		for (int i = 0; i < 3; i++) {
			testParser.splitAndSetTwoCommaStartEndDateTime(testDates[i]);
		}

		list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
		list<COMMAND_AND_TEXT>::iterator iter;
		int i = 0;
		for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
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
		string testDates[] = { "10/ 11/ 12", " 11/12\t", "9 Jan 10", "10 November 12", "15 FEB", "11 Sep", "Monday", "tue", "Jan", "march" };
		string testDatesFalse[] = { "10a/11b/12c", "10 Novmbr 12", "10/test/12", "monday march", "10", "11/12/13/14", "11/12/", "11/", "12/november", "10 11 12 13" };
		string expected[] = { "12 11 10", "-1 12 11", "10 1 9", "12 11 10", "-1 2 15", "-1 9 11", "-1 -1 monday", "-1 -1 tuesday", "-1 1 -1", "-1 3 -1" };
		string expectedFalse = "";

		for (int i = 0; i < 10; i++) {
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
		string testDate[] = { "10/11/12", "10/11" };
		unsigned int numberOfOblique[] = { 2, 1 };
		string expected[] = { "12 11 10", "-1 11 10" };

		for (int i = 0; i < 2; i++) {
			string actual = testParser.splitAndSetObliqueDateInformation(testDate[i], numberOfOblique[i]);
			Assert::AreEqual(expected[i], actual);
		}
	}

	TEST_METHOD(parserSplitAndSetSpaceDateInformationTest) {
		string testDate[] = { "JAN", "10 nOv 2015", "9 OcT", "MoN" };
		unsigned int numberOfSpace[] = { 0, 2, 1, 0 };
		string expected[] = { "-1 1 -1", "2015 11 10", "-1 10 9", "-1 -1 monday" };

		for (int i = 0; i < 4; i++) {
			try {
				string actualOne = testParser.splitAndSetSpaceDateInformation(testDate[i], numberOfSpace[i]);
				Assert::AreEqual(expected[i], actualOne);
			} catch (bool& exception) {
				Assert::IsFalse(exception);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetColonTimeStringTest) {
		string testTime[] = { "10:11", "9:10", "13:30", "23:59" };
		string expectedAM[] = { "10 11", "9 10", "13 30", "23 59" };
		string expectedPM[] = { "22 11", "21 10", "13 30", "23 59" };

		for (int i = 0; i < 4; i++) {
			string testString = testTime[i];

			string actual = testParser.splitAndSetColonTimeString(testString, "");
			string actualPM = testParser.splitAndSetColonTimeString(testString, "pm");
			Assert::AreEqual(expectedAM[i], actual);
			Assert::AreEqual(expectedPM[i], actualPM);

			if (i < 2) {
				string actualAM = testParser.splitAndSetColonTimeString(testString, "am");
				Assert::AreEqual(expectedAM[i], actualAM);
			}
		}
	}

	TEST_METHOD(parserSplitAndSetNoColonTimeStringTest) {
		string testTime[] = { "1011", "0910", "1330", "230", "11", "1" };
		string expectedAM[] = { "10 11", "09 10", "13 30", "2 30", "11 0", "1 0" };
		string expectedPM[] = { "22 11", "21 10", "13 30", "14 30", "23 00", "13 00" };

		for (int i = 0; i < 6; i++) {
			string testString = testTime[i];

			if (i < 2) {
				string actualAM = testParser.splitAndSetNoColonTimeString(testString, "am");
				Assert::AreEqual(expectedAM[i], actualAM);
			}

			if (i < 3) {
				string actual = testParser.splitAndSetNoColonTimeString(testString, "hr");
				Assert::AreEqual(expectedAM[i], actual);
			}

			string actualPM = testParser.splitAndSetNoColonTimeString(testString, "pm");
			Assert::AreEqual(expectedPM[i], actualPM);
		}
	}

	TEST_METHOD(parserIsDaySetDayTest) {
		string testDay[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
		string testDayShortForm[] = { "mon", "tue", "wed", "thur", "fri", "sat", "sun" };
		string testDayFalse[] = { "mondeh", "toosdeh", "weday", "thurs", "frehdeh", "satur", "sundae" };
		string expectedDay[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

		for (int i = 0; i < 7; i++) {
			bool actualBoolean = testParser.isDay(testDay[i]);
			string actualDay = testParser.setDay(testDay[i]);
			Assert::IsTrue(actualBoolean);
			Assert::AreEqual(expectedDay[i], actualDay);
		}

		for (int i = 0; i < 7; i++) {
			bool actualBoolean = testParser.isDay(testDayShortForm[i]);
			string actualDay = testParser.setDay(testDayShortForm[i]);
			Assert::IsTrue(actualBoolean);
			Assert::AreEqual(expectedDay[i], actualDay);
		}

		for (int i = 0; i < 7; i++) {
			string expected = "";
			bool actualBoolean = testParser.isDay(testDayFalse[i]);
			string actualDay = testParser.setDay(testDayFalse[i]);
			Assert::IsFalse(actualBoolean);
			Assert::AreEqual(expected, actualDay);
		}
	}

	TEST_METHOD(parserIsMonthTest) {
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
		string testHour[] = { "1", "6", "11", "12", "18", "23", "09" };
		string expected[] = { "13", "18", "23", "12", "18", "23", "21" };

		for (int i = 0; i < 7; i++) {
			string actual = testParser.addTwelveToHours(testHour[i]);
			Assert::AreEqual(expected[i], actual);
		}
	}

	TEST_METHOD(parserIsAppropriateHourTest) {
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
		string testString[] = { "-NAME", "-DaTe", "-dUe", "-start", "-end", "-Desc", "-dESCRIPTION", "-pRiORiTy" };
		string testStringfalse[] = { "-names", "-descrb", "-123", "-abc", "-", " " };

		for (int i = 0; i < 8; i++) {
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
		string testString = ",one,two,three,four,five,";
		unsigned int expected = 6;

		unsigned int actual = testParser.retrieveCount(testString, ',');
		Assert::AreEqual(expected, actual);
	}

	};
}