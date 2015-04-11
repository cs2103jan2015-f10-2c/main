//author A0116229J
//Coder : Yu Young Bin

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iLogicTest {
	TEST_CLASS(AddTaskTest) {
public:

	TEST_METHOD(AddTaskTest1) {
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
		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Task added to schedule : Young Bin";
		Assert::AreEqual(expectedMessage, message);
	}

	TEST_METHOD(AddTaskTest2) {
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

		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Task added to schedule : Young Bin";
		Assert::AreEqual(expectedMessage, message);
	}

	TEST_METHOD(AddTaskTest3) {
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

		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Task added to schedule : Young Bin";
		Assert::AreEqual(expectedMessage, message);
	}


	TEST_METHOD(AddTaskTest4) {
		Logic testLogic;
		string testItemName;
		COMMAND_AND_TEXT testCommandAndText;
		list<COMMAND_AND_TEXT> testParseInfo;

		/*add one item with valid start time*/
		testCommandAndText.command = "add";
		testCommandAndText.text = "Young Bin is testing";
		testParseInfo.push_back(testCommandAndText);
		testCommandAndText.command = "start";
		testCommandAndText.text = "1222 12 12 -1 -1";
		testParseInfo.push_back(testCommandAndText);
		testLogic.addTask(testParseInfo);

		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Task added to schedule : Young Bin is testing";
		Assert::AreEqual(expectedMessage, message);

		/*add one item with invalid start time*/
		testCommandAndText.command = "add";
		testCommandAndText.text = "Young Bin is testing second item";
		testParseInfo.push_back(testCommandAndText);
		testCommandAndText.command = "start";
		testCommandAndText.text = "999999 99 992 9999 999";
		testParseInfo.push_back(testCommandAndText);
		string expectedAddMessage = "failed_add";
		string actualAddMessage = testLogic.addTask(testParseInfo);

		message = testLogic.addTask(testParseInfo);
		expectedMessage = "Unable to add task : ";
		Assert::AreEqual(expectedMessage, message);
	}


	TEST_METHOD(AddTaskTest5) {
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

		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Task added to schedule : Young Bin";
		Assert::AreEqual(expectedMessage, message);

	}

	TEST_METHOD(AddTaskTest6) {
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

		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Task added to schedule : Young Bin";
		Assert::AreEqual(expectedMessage, message);
	}

	TEST_METHOD(AddTaskTest7) {
		Logic testLogic;
		string testItemName;
		COMMAND_AND_TEXT testCommandAndText;
		list<COMMAND_AND_TEXT> testParseInfo;

		/*add one item with invalid Start and end time*/
		testCommandAndText.command = "add";
		testCommandAndText.text = "Young Bin";
		testParseInfo.push_back(testCommandAndText);

		testCommandAndText.command = "start";
		testCommandAndText.text = "9999 9999 9999 9999 9999";

		testCommandAndText.command = "end";
		testCommandAndText.text = "9999 9999 9999 9999 9999";
		testParseInfo.push_back(testCommandAndText);

		string message = testLogic.addTask(testParseInfo);
		string expectedMessage = "Unable to add task : ";
		Assert::AreEqual(expectedMessage, message);
	}
	};


	TEST_CLASS(DeleteTaskTest) {
public:

	TEST_METHOD(DeleteTaskTest1) {
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

		testLogic.resetAndGetDisplaySchedule();
		/*Delete the last line , line 5*/
		unsigned int lineIndexToBeDeleted = 5;
		string expectedDeleteMessage1 = "Task is deleted from schedule";
		string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);

		testLogic.resetAndGetDisplaySchedule();
		/*Delete line 5, which does not exist*/
		string expectedDeleteMessage2 = "Unable to delete task : Invalid index";
		string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);

	}

	TEST_METHOD(DeleteTaskTest2) {
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


		testLogic.resetAndGetDisplaySchedule();

		/*Delete the first line*/
		unsigned int lineIndexToBeDeleted = 1;
		string expectedDeleteMessage1 = "Task is deleted from schedule";
		string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);

		testLogic.resetAndGetDisplaySchedule();
		/*Delete the first line*/
		string expectedDeleteMessage2 = "Task is deleted from schedule";
		string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);

	}

	TEST_METHOD(DeleteTaskTest3) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*delete within the boundary*/
		unsigned int lineIndexToBeDeleted = 2;
		string expectedDeleteMessage1 = "Task is deleted from schedule";
		string actualDeleteMessage1 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage1, actualDeleteMessage1);

		testLogic.resetAndGetDisplaySchedule();
		/*delete within the boundary*/
		string expectedDeleteMessage2 = "Task is deleted from schedule";
		string actualDeleteMessage2 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage2, actualDeleteMessage2);

		testLogic.resetAndGetDisplaySchedule();
		/*delete line index greater than schedulesize*/
		lineIndexToBeDeleted = 5;
		string expectedDeleteMessage3 = "Unable to delete task : Invalid index";
		string actualDeleteMessage3 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage3, actualDeleteMessage3);
	}

	TEST_METHOD(DeleteTaskTest4) {
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

		testLogic.resetAndGetDisplaySchedule();
		/*delete line index greater than schedulesize*/
		string expectedDeleteMessage3 = "Unable to delete task : Invalid index";
		string actualDeleteMessage3 = testLogic.deleteTask(lineIndexToBeDeleted);
		Assert::AreEqual(expectedDeleteMessage3, actualDeleteMessage3);
	}
	};

	TEST_CLASS(SortTaskTest) {
public:

	TEST_METHOD(SortTaskByName) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*sort by "name", valid sorting*/
		testLogic.changeCurrentSorting("name");
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

	TEST_METHOD(SortTaskByDate) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*sort by "date", valid sorting*/
		testLogic.changeCurrentSorting("date");
		vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

		string expectedItemName1 = "Young Bin";
		string expectedItemName2 = "TEST";
		string expectedItemName3 = "TEST2";
		string expectedItemName4 = "TEST3";
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

	TEST_METHOD(SortTaskByPriority) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*sort by "priority", valid sorting */
		testLogic.changeCurrentSorting("priority");
		vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();

		string expectedItemName1 = "Young Bin";
		string expectedItemName2 = "TEST";
		string expectedItemName3 = "TEST2";
		string expectedItemName4 = "TEST3";
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

	TEST_METHOD(SortTaskINVALID) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*sort by "INVALIDDDDDDDDD", invalid sorting */
		string expectedMessage = "Unable to change sorting : Invalid sort type";
		string actualMessage = testLogic.changeCurrentSorting("INVALIDDDDDDDDD");
		Assert::AreEqual(expectedMessage, actualMessage);
	}

	};

	TEST_CLASS(EditTaskTest) {
public:
	TEST_METHOD(EditTaskTest1) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*EDIT VALID LINE WITH VALID MODIFIER*/
		testCommandAndText.command = "edit";
		testCommandAndText.text = "1";
		testParseInfo.push_back(testCommandAndText);
		testCommandAndText.command = "description";
		testCommandAndText.text = "TEST DESCRIPTION";
		testParseInfo.push_back(testCommandAndText);
		string message = testLogic.editTask(testParseInfo, 1);

		Assert::AreEqual((string) "Task 1 is edited : description ", message);
		vector<Item> retrievedSchedule = testLogic.getDisplaySchedule();
	}

	TEST_METHOD(EditTaskTest2) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*EDIT VALID LINE WITH INVALID MODIFIER*/
		testCommandAndText.command = "edit";
		testCommandAndText.text = "8";
		testParseInfo.push_back(testCommandAndText);
		testCommandAndText.command = "description";
		testCommandAndText.text = "TESTDESCRIPTION";
		testParseInfo.push_back(testCommandAndText);
		string message = testLogic.editTask(testParseInfo, 8);

		Assert::AreEqual((string) "Unable to edit task : Invalid index", message);
	}
	};

	TEST_CLASS(ChangingSaveDirectoryTest) {
public:

	TEST_METHOD(savingDirectoryTest1)
	{
		Logic testLogic;
		string testDirectory = "c:/Youngbin'sTest/Haha";

		string expectedSavingDirectory = "c:/Youngbin'sTest/Haha";
		string actualSavingDirectory = testLogic.changeSavingDirectory(testDirectory);
		Assert::AreEqual(expectedSavingDirectory, actualSavingDirectory);

	}



	};

	TEST_CLASS(ChangeCompletionTest) {
public:
	TEST_METHOD(MarkDoneTest1) {
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

		testLogic.resetAndGetDisplaySchedule();

		unsigned int lineIndex = 2;
		string expectedMessage = "Task 2 is completed";
		string actualMessage = testLogic.markDone(lineIndex);

		Assert::AreEqual(expectedMessage, actualMessage);

	}


	TEST_METHOD(MarkUndoneTest1) {
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

		testLogic.resetAndGetDisplaySchedule();

		unsigned int lineIndex = 2;
		string expectedMessage = "Task 2 is undone";
		string actualMessage = testLogic.markUndone(lineIndex);

		Assert::AreEqual(expectedMessage, actualMessage);

	}

	TEST_METHOD(MarkDoneUndoneTest1) {
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

		testLogic.resetAndGetDisplaySchedule();


		unsigned int lineIndex = 2;
		string expectedMessage = "Task 2 is completed";
		string actualMessage = testLogic.markDone(lineIndex);
		Assert::AreEqual(expectedMessage, actualMessage);

		expectedMessage = "Task 2 is undone";
		actualMessage = testLogic.markUndone(lineIndex);
		Assert::AreEqual(expectedMessage, actualMessage);
	}

	TEST_METHOD(MarkDoneUndoneTest2) {
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

		testLogic.resetAndGetDisplaySchedule();


		unsigned int lineIndex = 2;
		string expectedMessage = "Task 2 is completed";
		string actualMessage = testLogic.markDone(lineIndex);
		Assert::AreEqual(expectedMessage, actualMessage);

		lineIndex = 3;
		expectedMessage = "Task 3 is undone";
		actualMessage = testLogic.markUndone(lineIndex);
		Assert::AreEqual(expectedMessage, actualMessage);
	}


	};


	TEST_CLASS(UndoTest) {
public:
	TEST_METHOD(UndoTest1) {
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

		testLogic.resetAndGetDisplaySchedule();

		string expectedMessage = "Last action reversed";
		string actualMessage = testLogic.undoPreviousAction();
		Assert::AreEqual(expectedMessage, actualMessage);
		expectedMessage = "Last action reversed";
		actualMessage = testLogic.undoPreviousAction();
		Assert::AreEqual(expectedMessage, actualMessage);
		expectedMessage = "Last action reversed";
		actualMessage = testLogic.undoPreviousAction();
		Assert::AreEqual(expectedMessage, actualMessage);
		expectedMessage = "Last action reversed";
		actualMessage = testLogic.undoPreviousAction();
		Assert::AreEqual(expectedMessage, actualMessage);
		expectedMessage = "Last action reversed";
		actualMessage = testLogic.undoPreviousAction();
		Assert::AreEqual(expectedMessage, actualMessage);
		expectedMessage = "Unable to undo last action";
		actualMessage = testLogic.undoPreviousAction();
		Assert::AreEqual(expectedMessage, actualMessage);
	}
	};

	TEST_CLASS(FilterTest) {
public:
	TEST_METHOD(FilterTest1) {
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

		testLogic.resetAndGetDisplaySchedule();

		/*filter by completion*/
		bool done = true;
		string expectedMessage = "done";
		string actualMessage = testLogic.filterByCompletion(done);
		Assert::AreEqual(expectedMessage, actualMessage);

		done = false;
		expectedMessage = "undone";
		actualMessage = testLogic.filterByCompletion(done);
		Assert::AreEqual(expectedMessage, actualMessage);

		expectedMessage = "all";
		actualMessage = testLogic.removeFilter();

	}
	};


	TEST_CLASS(InitiateCommandActionTest) {
public:
	TEST_METHOD(InitiateCommandActionTest1) {
		Logic testLogic;
		iParser testParser;

		/*Add Item 1*/
		string testInput = "add test item";
		string expectedMessage = "Task added to schedule : test item";
		MESSAGE_AND_SCHEDULE actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Add Item 2*/
		testInput = "add dinner with young bin";
		expectedMessage = "Task added to schedule : dinner with young bin";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Add Item 3*/
		testInput = "add dinner with joon fai";
		expectedMessage = "Task added to schedule : dinner with joon fai";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*delete item*/
		testInput = "Delete 2";
		expectedMessage = "Task is deleted from schedule";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*delete item*/
		testInput = "Delete 4";
		expectedMessage = "Unable to delete task : Invalid index";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*add item*/
		testInput = "add go dinner with sophie -date 23:59";
		expectedMessage = "Task added to schedule : go dinner with sophie";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*edit item*/
		testInput = "edit 1";
		expectedMessage = "Unable to edit task : Invalid command";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*edit item*/
		testInput = "edit 1 -desc HAHA";
		expectedMessage = "Task 1 is edited : description ";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*edit item*/
		testInput = "edit 2 -end 12:34";
		expectedMessage = "Task 2 is edited : end ";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*edit item*/
		testInput = "edit 2 -start 13:34";
		expectedMessage = "Unable to edit task : Start Date/Time is later than End Date/Time ";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*sort schedule*/
		testInput = "sort date";
		expectedMessage = "Schedule sorted by : date";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);
		
		/*sort schedule*/
		testInput = "sort update";
		expectedMessage = "Schedule sorted by : update";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*sort schedule*/
		testInput = "sort priority";
		expectedMessage = "Schedule sorted by : priority";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*sort schedule*/
		testInput = "sort name";
		expectedMessage = "Schedule sorted by : name";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*sort schedule*/
		testInput = "sort werwefsd";
		expectedMessage = "Invalid command";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*filter schedule*/
		testInput = "view done";
		expectedMessage = "Schedule filtered by : done";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*filter schedule*/
		testInput = "view undone";
		expectedMessage = "Schedule filtered by : undone";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*filter schedule*/
		testInput = "view all";
		expectedMessage = "Schedule filtered by : all";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*search task*/
		testInput = "search dinner";
		expectedMessage = "Tasks containing : dinner";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*search task*/
		testInput = "search sophie";
		expectedMessage = "Tasks containing : sophie";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*undo*/
		testInput = "undo";
		expectedMessage = "Last action reversed";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*undo*/
		testInput = "undo 234234";
		expectedMessage = "Invalid command";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*change save file*/
		testInput = "save c:/testFile/testtest";
		expectedMessage = "Save directory changed to : c:/testfile/testtest/save.txt";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Mark done*/
		testInput = "done 1";
		expectedMessage = "Task 1 is completed";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Mark done*/
		testInput = "done 4";
		expectedMessage = "invalid line index";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Mark undone*/
		testInput = "undone 1";
		expectedMessage = "Task 1 is undone";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Mark undone*/
		testInput = "undone 4";
		expectedMessage = "invalid line index";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);

		/*Clear*/
		testInput = "clear";
		expectedMessage = "Schedule cleared";
		actualMessage = testLogic.initiateCommandAction(testParser, testInput);
		Assert::AreEqual(expectedMessage, actualMessage.message);
	}
	};


	TEST_CLASS(TrimTextTest) {
	public:
		TEST_METHOD(TrimTextTest1) {
			string testText[] = { "   add text   ", "\t\t del text \t\t\t", "  exit\t\t", " ", "" };
			string expected[] = { "add text", "del text", "exit", "", "" };

			Logic testLogic;
			for (int i = 0; i < 5; i++) {
				testLogic.trimText(testText[i]);
				string actual = testText[i];
				Assert::AreEqual(expected[i], actual);
			}
		}
	};

	TEST_CLASS(RetrieveBasicInformationTest) {
	public:
		TEST_METHOD(TrimTextTest1) {
			Logic testLogic;
			string expectedMessage = "Retrieved from save file";
			string actualMessage = testLogic.retrieveBasicInformation();
			Assert::AreEqual(expectedMessage, actualMessage);
		}
	};


	TEST_CLASS(ReadFileWriteFileTest) {
	public:
		TEST_METHOD(ReadFileTest1) {
			Logic testLogic;
			string expectedMessage = "readfile completed";
			string actualMessage = testLogic.readDataFromFile().message;
			Assert::AreEqual(expectedMessage, actualMessage);
		}

		TEST_METHOD(WriteFileTest1) {
			Logic testLogic;
			string expectedMessage = "writefile completed";
			string actualMessage = testLogic.writeDataOntoFile();
			Assert::AreEqual(expectedMessage, actualMessage);
		}
	};

	TEST_CLASS(GetScheduleSizeTest) {
	public:
		TEST_METHOD(GetScheduleSizeTest1) {
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

			testLogic.resetAndGetDisplaySchedule();

			unsigned int expectedSize = 5;
			unsigned int actualSize = testLogic.getScheduleSize();
			Assert::AreEqual(expectedSize, actualSize);

			expectedSize = 5;
			actualSize = testLogic.getDisplayScheduleSize();
			Assert::AreEqual(expectedSize, actualSize);
		}
	};


	TEST_CLASS(KeywordVecTest) {
	public:
		TEST_METHOD(ConvertKeywordVecToStringTest1) {
			Logic testLogic;
			string keyword = "hello+hi+test";
		
			testLogic.convertStringToKeywordVec(keyword);
			string actualMessage = testLogic.convertKeywordVecToString();

			Assert::AreEqual(keyword, actualMessage);
		}
	};

}
