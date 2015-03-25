#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iLogicTest {
	TEST_CLASS(AddTaskTest)
	{
	public:

		TEST_METHOD(AddTaskTest1)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getSchedule();

			string expectedItemName1 = "Young Bin";
			unsigned int expectedItemID1 = 1;

			string actualItemName1 = retrievedShedule[0].getItemName();
			unsigned int actualItemID1 = retrievedShedule[0].getItemID();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemID1, actualItemID1);
		}

		TEST_METHOD(AddTaskTest2)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "HAHA";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getSchedule();

			string expectedItemName1 = "Young Bin";
			unsigned int expectedItemID1 = 1;
			string expectedDescription1 = "HAHA";

			string actualItemName1 = retrievedShedule[0].getItemName();
			unsigned int actualItemID1 = retrievedShedule[0].getItemID();
			string actualDescription1 = retrievedShedule[0].getDescription();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemID1, actualItemID1);
			Assert::AreEqual(expectedDescription1, actualDescription1);
		}

		TEST_METHOD(AddTaskTest3)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getSchedule();

			string expectedItemName1 = "Young Bin";
			unsigned int expectedItemID1 = 1;
			int expectedStartYear = 1222;
			int expectedStartMonth = 12;
			int expectedStartDay = 12;
			int expectedStartHour = -1;
			int expectedStartMinute = -1;

			string actualItemName1 = retrievedShedule[0].getItemName();
			unsigned int actualItemID1 = retrievedShedule[0].getItemID();
			int actualStartYear = retrievedShedule[0].getStartTime().getYear();
			int actualStartMonth = retrievedShedule[0].getStartTime().getMonth();
			int actualStartDay = retrievedShedule[0].getStartTime().getDay();
			int actualStartHour = retrievedShedule[0].getStartTime().getHour();
			int actualStartMinute = retrievedShedule[0].getStartTime().getMinute();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemID1, actualItemID1);
			Assert::AreEqual(expectedStartYear, actualStartYear);
			Assert::AreEqual(expectedStartMonth, actualStartMonth);
			Assert::AreEqual(expectedStartDay, actualStartDay);
			Assert::AreEqual(expectedStartHour, actualStartHour);
			Assert::AreEqual(expectedStartMinute, actualStartMinute);
		}

		TEST_METHOD(AddTaskTest4)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getSchedule();

			string expectedItemName1 = "Young Bin";
			unsigned int expectedItemID1 = 1;
			int expectedEndYear = 1222;
			int expectedEndMonth = 12;
			int expectedEndDay = 12;
			int expectedEndHour = -1;
			int expectedEndMinute = -1;

			string actualItemName1 = retrievedShedule[0].getItemName();
			unsigned int actualItemID1 = retrievedShedule[0].getItemID();
			int actualEndYear = retrievedShedule[0].getEndTime().getYear();
			int actualEndMonth = retrievedShedule[0].getEndTime().getMonth();
			int actualEndDay = retrievedShedule[0].getEndTime().getDay();
			int actualEndHour = retrievedShedule[0].getEndTime().getHour();
			int actualEndMinute = retrievedShedule[0].getEndTime().getMinute();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemID1, actualItemID1);
			Assert::AreEqual(expectedEndYear, actualEndYear);
			Assert::AreEqual(expectedEndMonth, actualEndMonth);
			Assert::AreEqual(expectedEndDay, actualEndDay);
			Assert::AreEqual(expectedEndHour, actualEndHour);
			Assert::AreEqual(expectedEndMinute, actualEndMinute);
		}

		TEST_METHOD(AddTaskTest5)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);

			testCommandAndText.command = "start";
			testCommandAndText.text = "1111 12 1 -1 -1";

			testCommandAndText.command = "end";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getSchedule();

			string expectedItemName1 = "Young Bin";
			unsigned int expectedItemID1 = 1;
			int expectedStartYear = 1111;
			int expectedStartMonth = 12;
			int expectedStartDay = 1;
			int expectedStartHour = -1;
			int expectedStartMinute = -1;
			int expectedEndYear = 1222;
			int expectedEndMonth = 12;
			int expectedEndDay = 12;
			int expectedEndHour = -1;
			int expectedEndMinute = -1;


			string actualItemName1 = retrievedShedule[0].getItemName();
			unsigned int actualItemID1 = retrievedShedule[0].getItemID();
			int actualStartYear = retrievedShedule[0].getStartTime().getYear();
			int actualStartMonth = retrievedShedule[0].getStartTime().getMonth();
			int actualStartDay = retrievedShedule[0].getStartTime().getDay();
			int actualStartHour = retrievedShedule[0].getStartTime().getHour();
			int actualStartMinute = retrievedShedule[0].getStartTime().getMinute();
			int actualEndYear = retrievedShedule[0].getEndTime().getYear();
			int actualEndMonth = retrievedShedule[0].getEndTime().getMonth();
			int actualEndDay = retrievedShedule[0].getEndTime().getDay();
			int actualEndHour = retrievedShedule[0].getEndTime().getHour();
			int actualEndMinute = retrievedShedule[0].getEndTime().getMinute();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemID1, actualItemID1);
			Assert::AreEqual(expectedEndYear, actualEndYear);
			Assert::AreEqual(expectedEndMonth, actualEndMonth);
			Assert::AreEqual(expectedEndDay, actualEndDay);
			Assert::AreEqual(expectedEndHour, actualEndHour);
			Assert::AreEqual(expectedEndMinute, actualEndMinute);
		}

	};


	TEST_CLASS(DeleteTaskTest)
	{
	public:

		TEST_METHOD(DeleteTaskTest1)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			int lineIndexToBeDeleted = 1;

			string expectedDeleteMessage = "successful_delete";
			string actualDeleteMessage = testLogic.deleteTask(1);

			Assert::AreEqual(expectedDeleteMessage, actualDeleteMessage);

		}

		TEST_METHOD(DeleteTaskTest2)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);


			unsigned int lineIndexToBeDeleted = 1;
			string expectedDeleteMessage1 = "successful_delete";
			string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);

			string expectedDeleteMessage2 = "successful_delete";
			string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);

		}
		

	};

	TEST_CLASS(SortTaskTest)
	{
	public:

		TEST_METHOD(SortTaskTest1)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);




			testLogic.resetDisplaySchedule();
			testLogic.setCurrentSorting("name");
			testLogic.sortTask();
			vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

			string expectedItemName1 = "TEST";
			string expectedItemName2 = "TEST2";
			string expectedItemName3 = "TEST3";
			string expectedItemName4 = "TEST4";
			string expectedItemName5 = "Young Bin";

			string actualItemName1 = retrievedSchedule[0].getItemName();
			string actualItemName2 = retrievedSchedule[1].getItemName();
			string actualItemName3 = retrievedSchedule[2].getItemName();
			string actualItemName4 = retrievedSchedule[3].getItemName();
			string actualItemName5 = retrievedSchedule[4].getItemName();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemName2, actualItemName2);
			Assert::AreEqual(expectedItemName3, actualItemName3);
			Assert::AreEqual(expectedItemName4, actualItemName4);
			Assert::AreEqual(expectedItemName5, actualItemName5);
		}

	

	};

}
	