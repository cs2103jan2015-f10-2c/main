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

		TEST_METHOD(parserExecuteCommandAndTextParsing) {
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

		TEST_METHOD(parserExecuteCommandParsing) {
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

		TEST_METHOD(parserExecuteModifierAndTextParsing) {
			// testText[4] tests for invalid case where blank string is not allowed
			string testCommand[] = { "item", "desc", "priority", "desc", "priority" };
			string testText[] = { "123", "123abc", "abc", " ", "" };
			string expectedCommand[] = { "item", "desc", "priority", "desc", "invalid" };
			string expectedText[] = { "123", "123abc", "abc", " ", "Invalid input" };

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

		TEST_METHOD(parserCheckAndSetTokenisedInformationTest) {
			// testInput[0] is added but not tested as the function starts from index = 1 where the modifiers starts from
			string testInput[] = { "add abc", "-desc wear formal", "-date 12/11/10, 10PM", "-due 10 Nov, 1059PM", "-priority " };
			string expectedCommand[] = { "description", "start", "end", "invalid" };
			string expectedText[] = { "wear formal", "10 11 12 22 -1", "-1 11 10 22 59", "Invalid input" };
			vector<string> testVector;

			for (int i = 0; i < 5; i++) {
				string input = testInput[i];
				testVector.push_back(input);
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
		}		


		TEST_METHOD(parserTokeniseTextTest) {
			// as hyphen is used as the modifier identifier, cases created tests to see
			//if it recognises the allowed modifiers
			vector<string> testVector;
			string testInput = "test -date te-st -due t-e-s-t -start 10AM -end 10PM -from A to B -desc test ---label -priority te-descst";
			string expected[] = { "test", "-date te-st", "-due t-e-s-t", "-start 10AM", "-end 10PM", "-from A to B", "-desc test --", "-label", "-priority te-descst" };

			testVector = testParser.tokeniseText(testInput);

			for (unsigned int i = 0; i < testVector.size(); i++) {
				string actual = testVector[i];
				Assert::AreEqual(expected[i], actual);
			}
		}

		/*TEST_METHOD(parserRetrieveCommandOrModifierTest) {
			string testInput[] = { "ADD   ", "DeLeTe\t\t\t", "-dAtE   ", "-desc\t\t\t", " ", "" };
			string expected[] = { "add", "delete", "-date", "-desc", "", "" };

			for (int i = 0; i < 6; i++) {
				string actual = testParser.retrieveCommandOrModifier(testInput[i]);
				Assert::AreEqual(expected[i], actual);
			}
		}

		TEST_METHOD(parserTrimTextTest) {
			string stringOne = "   add text   ";
			string stringTwo = "\t\t del text \t\t\t";
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

		TEST_METHOD(parserRemoveFirstStringTokenTest) {
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
		
		TEST_METHOD(parserRemoveConsecutiveWhiteSpace) {
			string actual = "1 2 \t 3 \t 4 5";
			string expected = "1 2 3 4 5"; 
			
			testParser.removeConsecutiveWhiteSpace(actual);
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(parserRemoveWhiteSpace) {
			string actual = "1 2 \t 3 \t 4 5";
			string expected = "12345";

			testParser.removeWhiteSpace(actual);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(parserRemoveCharacterSpace) {
			string actual = "/1//2///3///4//5/";
			string expected = "12345";

			testParser.removeCharacter(actual, '/');
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(parserConvertToLowerCaseTest) {
			string actual = "ABCDEFGHIJKLM123456789NOPQRSTUVWXYZ";
			string expected = "abcdefghijklm123456789nopqrstuvwxyz";

			testParser.convertToLowerCase(actual);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(parserRetrieveFirstStringTokenTest) {
			string stringOne = "add   text";
			string stringTwo = "exit";
			string expectedOne = "add";
			string expectedTwo = "exit";

			string actualOne = testParser.retrieveFirstStringToken(stringOne);
			Assert::AreEqual(expectedOne, actualOne);

			string actualTwo = testParser.retrieveFirstStringToken(stringTwo);
			Assert::AreEqual(expectedTwo, actualTwo);
		}

		TEST_METHOD(parserAreDigitsTest) {
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

		TEST_METHOD(parserIsWhiteSpaceTest) {
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

		TEST_METHOD(parserSetDateTimeTest) {
			string trueTestDateTime[] = { "10 Nov 2012", "10/11/12, 6pm", "10 November 12, 10PM" };
			string expectedDateTime[] = { "2012 11 10 -1 -1", "12 11 10 18 -1", "12 11 10 22 -1" };
			string expectedCommand[] = { "start", "end" };

			string testString = trueTestDateTime[0];
			testParser.setDateTime(testString, "date");
			testString = trueTestDateTime[1];
			testParser.setDateTime(testString, "due");

			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
			list<COMMAND_AND_TEXT>::iterator iter;
			int i = 0;
			for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
				string actualCommand = iter->command;
				string actualDateTime = iter->text;
				Assert::AreEqual(expectedDateTime[i], actualDateTime);
				Assert::AreEqual(expectedCommand[i], actualCommand);
			}
		}
		*/
		TEST_METHOD(parserSplitDateTimeTest) {
			string trueTestDateTime[] = { "10/11/12, 6pm", "10PM, 10 Nov 12" };
			string expectedDateTime[] = { "12 11 10 18 -1", "12 11 10 22 -1" };
			string expectedCommand = "end";

			for (int i = 0; i < 2; i++) {
				string testString = trueTestDateTime[i];
				testParser.splitDateTime(testString, "end");
			}

			list<COMMAND_AND_TEXT> testList = testParser.getParseInfo();
			list<COMMAND_AND_TEXT>::iterator iter;
			int i = 0;
			for (iter = testList.begin(); iter != testList.end(); i++, iter++) {
				string actualCommand = iter->command;
				string actualDateTime = iter->text;
				Assert::AreEqual(expectedDateTime[i], actualDateTime);
				Assert::AreEqual(expectedCommand, actualCommand);
			}
		}
		/*
		TEST_METHOD(parserhasStartEndTest) {
			string trueTestDates[] = { "10/11/12 to 12/11/12", "10 November 12-12 November 2012" };
			unsigned int expectedIndex[] = { 9, 14 };
			unsigned int expectedSize[] = { 2, 1 };

			for (int i = 0; i < 2; i++) {
				string testString = trueTestDates[i];
				unsigned int index = -1;
				unsigned int size = 0;

				bool actual = testParser.hasStartEnd(testString, index, size);
				Assert::IsTrue(actual);
				Assert::AreEqual(expectedIndex[i], index);
				Assert::AreEqual(expectedSize[i], size);
			}
		}

		/*TEST_METHOD(parserSplitAndSetStartEndTest) {
			string testDateTime = "10/11/2012 9pm to 12/11/2012 10pm";
			string testDates[] = { "10/11/2012 to 12/11/2012", "10 November 2012 - 12 November 2012" };
			string testTimes[] = { "9pm to 11pm", "9-11", "10:00 to 11:00", "10:30 - 11:30" };
			string expectedStartDateTime = "10 11 2012 21 -1";
			string expectedEndDateTime = "12 11 2012 22 -1";
			string expectedStartDate = "10 11 2012";
			string expectedEndDate = "12 11 2012";
			string expectedStartTime[] { "21 -1", "9 -1", "10 00", "10 30" };
			string expectedEndTime[] { "23 -1", "11 -1", "11 00", "11 30" };

			for (int i = 0; i < 2; i++) {
				string testString = testDates[i];
				unsigned int index = -1;
				unsigned int size = 0;

				if (testParser.hasStartEnd(testString, index, size)) {
					unsigned int type = -1;
					unsigned int expectedType = 2;

					START_AND_END actual = testParser.splitAndSetStartEnd(testString, index, size, type );
					unsigned int actualType = type;
					Assert::AreEqual(expectedStartDate, actual.start);
					Assert::AreEqual(expectedEndDate, actual.end);
					Assert::AreEqual(expectedType, actualType);
				}
			}

			for (int i = 0; i < 2; i++) {
				string testString = testTimes[i];
				unsigned int index = -1;
				unsigned int size = 0;

				if (testParser.hasStartEnd(testString, index, size)) {
					unsigned int type = -1;
					unsigned int expectedType = 3;

					START_AND_END actual = testParser.splitAndSetStartEnd(testString, index, size, type);
					unsigned int actualType = type;
					Assert::AreEqual(expectedStartTime[i], actual.start);
					Assert::AreEqual(expectedEndTime[i], actual.end);
					Assert::AreEqual(expectedType, actualType);
				}
			}

			unsigned int index = -1;
			unsigned int size = 0;
			if (testParser.hasStartEnd(testDateTime, index, size)) {
				unsigned int type = -1;
				unsigned int expectedType = 1;

				START_AND_END actual = testParser.splitAndSetStartEnd(testDateTime, index, size, type);
				unsigned int actualType = type;
				Assert::AreEqual(expectedStartDateTime, actual.start);
				Assert::AreEqual(expectedEndDateTime, actual.end);
				Assert::AreEqual(expectedType, actualType);
			}
		}*/

		/*
		TEST_METHOD(parserIsValidDateTest) {
			string trueTestDates[] = { "10/11/12", "10 November 12", "10 Nov 12" };
			string falseTestDates[] = { "10a/11b/12c", "10 Novmbr 12", "10/test/12" };
			string expected = { "12 11 10" };

			for (int i = 0; i < 2; i++) {
				string testStringOne = trueTestDates[i];
				string testStringTwo = falseTestDates[i];
				string actualDateOne = "";
				string actualDateTwo = "";
				string expectedFalse = "";
				bool actualOne = testParser.isValidDate(testStringOne, actualDateOne);
				bool actualTwo = testParser.isValidDate(testStringTwo, actualDateTwo);
				Assert::IsTrue(actualOne);
				Assert::AreEqual(expected, actualDateOne);
				Assert::IsFalse(actualTwo);
				Assert::AreEqual(expectedFalse, actualDateTwo);
			}
		}

		TEST_METHOD(parserIsValidTimeTest) {
			string trueTestTimes[] = { "10:59", "10:59PM", "10:59 pm", "1059", "10", "10 pm", "930pm", "1 pm"};
			string falseTestTimes[] = { "10::59", "10a:59b", "10a:59bpm", "1059bpm" };
			string expected[] = { "10 59", "22 59", "22 59", "10 59", "10 -1", "22 -1", "21 30", "13 -1" };

			for (int i = 0; i < 8; i++) {
				string testString = trueTestTimes[i];
				string actualTime = "";
				bool actual = testParser.isValidTime(testString, actualTime);
				Assert::IsTrue(actual);
				Assert::AreEqual(expected[i], actualTime);
			}

			for (int i = 0; i < 4; i++) {
				string testString = falseTestTimes[i];
				string actualTime = "";
				string expectedTime = "";
				bool actual = testParser.isValidTime(testString, actualTime);
				Assert::IsFalse(actual);
				Assert::AreEqual(expectedTime, actualTime);
			}
		}

		TEST_METHOD(parserSplitAndSetObliqueDateInformationTest) {
			string stringOne = "10/11/12";
			string stringTwo = "10/11";
			string expectedOne = "12 11 10";
			string expectedTwo = "-1 11 10";
			
			string actualOne = testParser.splitAndSetObliqueDateInformation(stringOne, 2);
			Assert::AreEqual(expectedOne, actualOne);
			string actualTwo = testParser.splitAndSetObliqueDateInformation(stringTwo, 1);
			Assert::AreEqual(expectedTwo, actualTwo);
		}

		TEST_METHOD(parserSplitAndSetSpaceDateInformationTest) {
			string stringOne = "JAN";
			string stringTwo = "10 nOv 2015";
			string stringThree = "9 OcT";
			string stringFive = "MoN";
			string expectedOne = "-1 1 -1";
			string expectedTwo = "2015 11 10";
			string expectedThree = "-1 10 9";
			string expectedFive = "-1 -1 monday";

			string actualOne = testParser.splitAndSetSpaceDateInformation(stringOne, 0);
			Assert::AreEqual(expectedOne, actualOne);
			string actualTwo = testParser.splitAndSetSpaceDateInformation(stringTwo, 2);
			Assert::AreEqual(expectedTwo, actualTwo);
			string actualThree = testParser.splitAndSetSpaceDateInformation(stringThree, 1);
			Assert::AreEqual(expectedThree, actualThree);
			string actualFive = testParser.splitAndSetSpaceDateInformation(stringFive, 0);
			Assert::AreEqual(expectedFive, actualFive);
		}

		TEST_METHOD(parserSplitAndSetColonTimeStringTest) {
			string testStrings[] = { "10:11", "9:10" };
			string expectedOne[] = { "10 11", "9 10" };
			string expectedTwo[] = { "22 11", "21 10" };

			for (int i = 0; i < 2; i++) {
				string testString = testStrings[i];
				string actualOne = testParser.splitAndSetColonTimeString(testString, "");
				string actualTwo = testParser.splitAndSetColonTimeString(testString, "pm");
				string actualThree = testParser.splitAndSetColonTimeString(testString, "am");
				Assert::AreEqual(expectedOne[i], actualOne);
				Assert::AreEqual(expectedTwo[i], actualTwo);
				Assert::AreEqual(expectedOne[i], actualThree);
			}
		}

		TEST_METHOD(parserSplitAndSetNoColonTimeStringTest) {
			string testStrings[] = { "1011", "910" };
			string expectedOne[] = { "10 11", "9 10" };
			string expectedTwo[] = { "22 11", "21 10" };

			for (int i = 0; i < 2; i++) {
				string testString = testStrings[i];
				string actualOne = testParser.splitAndSetNoColonTimeString(testString, "");
				string actualTwo = testParser.splitAndSetNoColonTimeString(testString, "pm");
				string actualThree = testParser.splitAndSetNoColonTimeString(testString, "am");
				Assert::AreEqual(expectedOne[i], actualOne);
				Assert::AreEqual(expectedTwo[i], actualTwo);
				Assert::AreEqual(expectedOne[i], actualThree);
			}
		}

		TEST_METHOD(parserIsDayTest) {
			string trueTestStringOne[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
			string trueTestStringTwo[] = { "mon", "tue", "wed", "thur", "fri", "sat", "sun" };
			string falseTestString[] = { "mondeh", "toosdeh", "weday", "thurs", "frehdeh", "satur", "sundae" };

			for (unsigned int i = 0; i < 7; i++) {
				unsigned int index = -1;
				bool actualOne = testParser.isDay(trueTestStringOne[i], index);
				bool actualTwo = testParser.isDay(trueTestStringOne[i]);
				Assert::IsTrue(actualOne);
				Assert::IsTrue(actualTwo);
				Assert::AreEqual(index, i);
			}

			for (unsigned int i = 0; i < 7; i++) {
				unsigned int index = -1;
				bool actualOne = testParser.isDay(trueTestStringTwo[i], index);
				bool actualTwo = testParser.isDay(trueTestStringTwo[i]);
				Assert::IsTrue(actualOne);
				Assert::IsTrue(actualTwo);
				Assert::AreEqual(index, i);
			}

			for (unsigned int i = 0; i < 7; i++) {
				unsigned int index = -1;
				unsigned int expected = -1;
				bool actualOne = testParser.isDay(falseTestString[i], index);
				bool actualTwo = testParser.isDay(falseTestString[i]);
				Assert::IsFalse(actualOne);
				Assert::IsFalse(actualTwo);
				Assert::AreEqual(index, expected);
			}
		}

		TEST_METHOD(parserIsMonthTest) {
			string trueTestStringOne[] = { "January", "february", "March", "april", "May", "june",
				"July", "august", "September", "october", "November", "december" };
			string trueTestStringTwo[] = { "JAN", "feb", "MAR", "apr", "MAY", "jun",
				"JUL", "aug", "SEP", "oct", "NOV", "dec" };
			string falseTestString[] = { "janr", "febr", "mach", "aprl", "my", "jn",
				"jool", "augst", "sept", "octbr", "novmbr", "decmbr" };

			for (unsigned int i = 0; i < 12; i++) {
				unsigned int index = -1;
				bool actual = testParser.isMonth(trueTestStringOne[i], index);
				Assert::IsTrue(actual);
				Assert::AreEqual(index, i);
			}

			for (unsigned int i = 0; i < 12; i++) {
				unsigned int index = -1;
				bool actual = testParser.isMonth(trueTestStringTwo[i], index);
				Assert::IsTrue(actual);
				Assert::AreEqual(index, i);
			}

			for (unsigned int i = 0; i < 12; i++) {
				unsigned int index = -1;
				unsigned int expected = -1;
				bool actual = testParser.isMonth(falseTestString[i], index);
				Assert::IsFalse(actual);
				Assert::AreEqual(index, expected);
			}
		}

		TEST_METHOD(parserHasTimePeriodAbbreviationTest) {
			string trueTestStringOne[] = { "1010AM", "1010PM", "1010aM", "1010Pm", "1010am", "1010pm" };
			string falseTestString[] = { "1010", "1010mp", "1010ma", "1010cs" };

			for (unsigned int i = 0; i < 6; i++) {
				bool actual = testParser.hasTimePeriodAbbreviation(trueTestStringOne[i]);
				Assert::IsTrue(actual);
			}

			for (unsigned int i = 0; i < 4; i++) {
				bool actual = testParser.hasTimePeriodAbbreviation(falseTestString[i]);
				Assert::IsFalse(actual);
			}
		}

		TEST_METHOD(parserAddTwelveToHoursTest) {
			string stringOne = "88";
			string stringTwo = "88abc";
			string expectedOne = "100";
			string expectedTwo = "-1";

			string actualOne = testParser.addTwelveToHours(stringOne);
			string actualTwo = testParser.addTwelveToHours(stringTwo);

			Assert::AreEqual(expectedOne, actualOne);
			Assert::AreEqual(expectedTwo, actualTwo);
		}

		TEST_METHOD(parserRetrieveCountTest) {
			string testString = ",one,two,three,four,five,";
			unsigned int expected = 6;

			unsigned int actual = testParser.retrieveCount(testString, ',');
			Assert::AreEqual(expected, actual);
		} */
	}; 
}