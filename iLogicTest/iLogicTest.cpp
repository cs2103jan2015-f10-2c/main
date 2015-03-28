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

			/*Add one item with valid name and priority*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getDisplaySchedule();

			string expectedItemName1 = "Young Bin";
			unsigned int expectedItemID1 = 1;
			char expectedItemPriority1 = 'M';

			string actualItemName1 = retrievedShedule[0].getItemName();
			unsigned int actualItemID1 = retrievedShedule[0].getItemID();
			char actualItemPriority1 = retrievedShedule[0].getPriority();

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemID1, actualItemID1);
			Assert::AreEqual(expectedItemPriority1, actualItemPriority1);
		}

		TEST_METHOD(AddTaskTest2)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add one item with valid name and description*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "HAHA";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getDisplaySchedule();

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

			/*add one item with valid start time*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getDisplaySchedule();

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

			/*add one item with valid start time*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);

			/*add one item with invalid start time*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "999999 99 992 9999 999";
			testParseInfo.push_back(testCommandAndText);
			string expectedAddMessage = "failed_add";
			string actualAddMessage = testLogic.addTask(testParseInfo);

			vector<Item>retrievedShedule = testLogic.getDisplaySchedule();

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
			Assert::AreEqual(expectedAddMessage, actualAddMessage);

		}


		TEST_METHOD(AddTaskTest5)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*add one item with valid end time,desc but invalid priority*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "desc";
			testCommandAndText.text = "test description";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "YYYYYYY";
			testParseInfo.push_back(testCommandAndText);

			string actualAddMessage = testLogic.addTask(testParseInfo);
			string expectedAddMessage = "failed_add";

			vector<Item>retrievedShedule = testLogic.getDisplaySchedule();

			Assert::AreEqual(expectedAddMessage, actualAddMessage);
		}

		TEST_METHOD(AddTaskTest6)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*add one item with valid Start and end time*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);

			testCommandAndText.command = "start";
			testCommandAndText.text = "1111 12 1 -1 -1";

			testCommandAndText.command = "end";
			testCommandAndText.text = "1222 12 12 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			string actualAddMessage = testLogic.addTask(testParseInfo);
			string expectedAddMessage = "successful_add";

			vector<Item>retrievedShedule = testLogic.getDisplaySchedule();

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

			Assert::AreEqual(expectedAddMessage, actualAddMessage);
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

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Delete the last line , line 5*/
			unsigned int lineIndexToBeDeleted = 5;
			string expectedDeleteMessage1 = "successful_delete";
			string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);

			/*Delete line 5, which does not exist*/
			string expectedDeleteMessage2 = "failed_delete";
			string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);

		}

		TEST_METHOD(DeleteTaskTest2)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Delete the first line*/
			unsigned int lineIndexToBeDeleted = 1;
			string expectedDeleteMessage1 = "successful_delete";
			string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);

			/*Delete the first line*/
			string expectedDeleteMessage2 = "successful_delete";
			string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);

		}

		TEST_METHOD(DeleteTaskTest3)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*delete within the boundary*/
			unsigned int lineIndexToBeDeleted = 1;
			string expectedDeleteMessage1 = "successful_delete";
			string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);
			/*delete within the boundary*/
			string expectedDeleteMessage2 = "successful_delete";
			string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);
			/*delete line index greater than schedulesize*/
			lineIndexToBeDeleted = 5;
			string expectedDeleteMessage3 = "failed_delete";
			string actualDeleteMessage3 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage3, actualDeleteMessage3);
		}

		TEST_METHOD(DeleteTaskTest4)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();


			unsigned int lineIndexToBeDeleted = 17;

			/*delete line index greater than schedulesize*/
			string expectedDeleteMessage3 = "failed_delete";
			string actualDeleteMessage3 = testLogic.deleteTask(lineIndexToBeDeleted);
			Assert::AreEqual(expectedDeleteMessage3, actualDeleteMessage3);
		}
	};

	TEST_CLASS(SortTaskTest)
	{
	public:

		TEST_METHOD(SortTaskByName)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();


			/*sort by "name", valid sorting*/
			testLogic.setCurrentSorting("name");
			string message = testLogic.sortTask();
			Assert::AreEqual((string) "successful_sort", message);
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

		TEST_METHOD(SortTaskByDate)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*sort by "date", valid sorting*/
			testLogic.setCurrentSorting("date");
			string message = testLogic.sortTask();
			Assert::AreEqual((string) "successful_sort", message);
			vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

			string expectedItemName1 = "Young Bin";
			string expectedItemName2 = "TEST4";
			string expectedItemName3 = "TEST";
			string expectedItemName4 = "TEST2";
			string expectedItemName5 = "TEST3";

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

		TEST_METHOD(SortTaskByPriority)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "H";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "L";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "H";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*sort by "priority", valid sorting */
			testLogic.setCurrentSorting("priority");
			string message = testLogic.sortTask();
			Assert::AreEqual((string) "successful_sort", message);
			vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

			string expectedItemName1 = "Young Bin";
			string expectedItemName2 =  "TEST";
			string expectedItemName3 = "TEST2";
			string expectedItemName4 =  "TEST3";
			string expectedItemName5 = "TEST4";

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

	TEST_CLASS(EditTaskTest)
	{
	public:
		TEST_METHOD(EditTaskTest1)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "H";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "L";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "H";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*EDIT VALID LINE WITH VALID MODIFIER*/
			testCommandAndText.command = "edit";
			testCommandAndText.text = "1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "TEST DESCRIPTION";
			testParseInfo.push_back(testCommandAndText);
			string message = testLogic.editTask(testParseInfo, 1);
			
			Assert::AreEqual((string) "successful_edit", message);
			vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

			string expectedItemName1 = "Young Bin";
			char expectedItemPriority = 'H';
			string expectedDescription = "TEST DESCRIPTION";
			
			string actualItemName1 = retrievedSchedule[0].getItemName();
			char actualItemPriority = retrievedSchedule[0].getPriority();
			string actualItemDescription = retrievedSchedule[0].getDescription();
		

			Assert::AreEqual(expectedItemName1, actualItemName1);
			Assert::AreEqual(expectedItemPriority, actualItemPriority);
			Assert::AreEqual(expectedDescription, actualItemDescription);

		}

		TEST_METHOD(EditTaskTest2)
		{
			Logic testLogic;
			string testItemName;
			COMMAND_AND_TEXT testCommandAndText;
			list<COMMAND_AND_TEXT> testParseInfo;

			/*Add Item 1*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "Young Bin";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "H";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 2*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1222 12 12 12 12";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 3*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST2";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "end";
			testCommandAndText.text = "1333 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "M";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 4*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST3";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "start";
			testCommandAndText.text = "1344 11 11 -1 -1";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "L";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*Add Item 5*/
			testCommandAndText.command = "add";
			testCommandAndText.text = "TEST4";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "UNITTESTING";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "priority";
			testCommandAndText.text = "H";
			testParseInfo.push_back(testCommandAndText);
			testLogic.addTask(testParseInfo);
			testParseInfo.clear();

			/*EDIT VALID LINE WITH INVALID MODIFIER*/
			testCommandAndText.command = "edit";
			testCommandAndText.text = "8";
			testParseInfo.push_back(testCommandAndText);
			testCommandAndText.command = "description";
			testCommandAndText.text = "TESTDESCRIPTION";
			testParseInfo.push_back(testCommandAndText);
			string message = testLogic.editTask(testParseInfo, 8);

			Assert::AreEqual((string) "invalid input", message);
			vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

		}
	};

	TEST_CLASS(ChangingSaveDirectoryTest)
	{
	public:
		/*
		TEST_METHOD(savingDirectoryTest1)
		{
		string testDirectory = "c:/Hello/Haha";
		string testSaveFile = "save.txt";

		string expectedSavingDirectory = "c:/Hello/Haha/save.txt";
		string actualSavingDirectory =
		}
		*/


	};

}
