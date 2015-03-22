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
			
			Assert::AreEqual(expectedItemName1,actualItemName1);
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

/*		TEST_METHOD(AddTaskTest2)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			string testItemName;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItemName);
			testItem.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItemName);
			unsigned int IdFromSchedule = testLogic.getSchedule()[0].getItemID();
			unsigned int IdFromSchedule2 = testLogic.getSchedule()[1].getItemID();

			Assert::AreEqual(IdFromSchedule, addedItemId);
			Assert::AreEqual(IdFromSchedule2, addedItemId2);
		}
		*/
	};
}
	/*
	TEST_CLASS(DeleteTaskTest)
	{
	public:

		TEST_METHOD(DeleteTaskTest1)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem1;
			Item testItem2;
			Item testItem3;
			Item testItem4;
			Item testItem5;
			string testItemName;
			testItem1.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItemName);
			testItem2.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItemName);
			testItem3.setItemID(35);
			unsigned int addedItemId3 = testLogic.addTask(testItemName);
			testItem4.setItemID(45);
			unsigned int addedItemId4 = testLogic.addTask(testItemName);
			testItem5.setItemID(356);
			unsigned int addedItemId5 = testLogic.addTask(testItemName);

			unsigned int IdFromSchedule = testLogic.getSchedule()[0].getItemID();
			unsigned int IdFromSchedule2 = testLogic.getSchedule()[1].getItemID();
			unsigned int IdFromSchedule3 = testLogic.getSchedule()[2].getItemID();
			unsigned int IdFromSchedule4 = testLogic.getSchedule()[3].getItemID();
			unsigned int IdFromSchedule5 = testLogic.getSchedule()[4].getItemID();
			Assert::AreEqual(IdFromSchedule, addedItemId);
			Assert::AreEqual(IdFromSchedule2, addedItemId2);
			Assert::AreEqual(IdFromSchedule3, addedItemId3);
			Assert::AreEqual(IdFromSchedule4, addedItemId4);
			Assert::AreEqual(IdFromSchedule5, addedItemId5);

			Item deletedItem = testLogic.deleteTask("1");

			Assert::AreEqual(addedItemId, deletedItem.getItemID());
			deletedItem = testLogic.deleteTask("1");
			Assert::AreEqual(addedItemId2, deletedItem.getItemID());

		}

		TEST_METHOD(DeleteTaskTest2)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			string testItemName;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItemName);
			testItem.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItemName);
			testItem.setItemID(35);
			unsigned int addedItemId3 = testLogic.addTask(testItemName);
			testItem.setItemID(45);
			unsigned int addedItemId4 = testLogic.addTask(testItemName);
			testItem.setItemID(356);
			unsigned int addedItemId5 = testLogic.addTask(testItemName);

			unsigned int IdFromSchedule = testLogic.getSchedule()[0].getItemID();
			unsigned int IdFromSchedule2 = testLogic.getSchedule()[1].getItemID();
			unsigned int IdFromSchedule3 = testLogic.getSchedule()[2].getItemID();
			unsigned int IdFromSchedule4 = testLogic.getSchedule()[3].getItemID();
			unsigned int IdFromSchedule5 = testLogic.getSchedule()[4].getItemID();
			Assert::AreEqual(IdFromSchedule, addedItemId);
			Assert::AreEqual(IdFromSchedule2, addedItemId2);
			Assert::AreEqual(IdFromSchedule3, addedItemId3);
			Assert::AreEqual(IdFromSchedule4, addedItemId4);
			Assert::AreEqual(IdFromSchedule5, addedItemId5);

			Item deletedItem = testLogic.deleteTask("2");
			Assert::AreEqual(addedItemId2, deletedItem.getItemID());
			deletedItem = testLogic.deleteTask("3");
			Assert::AreEqual(addedItemId4, deletedItem.getItemID());

		}
	};

	TEST_CLASS(GetItemIDFromLineIndexTest)
	{
	public:

		TEST_METHOD(GetItemIDFromLineIndexTest1)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			string testItemName;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItemName);
			testItem.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItemName);
			testItem.setItemID(35);
			unsigned int addedItemId3 = testLogic.addTask(testItemName);
			testItem.setItemID(45);
			unsigned int addedItemId4 = testLogic.addTask(testItemName);
			testItem.setItemID(356);
			unsigned int addedItemId5 = testLogic.addTask(testItemName);

			unsigned int IdFromSchedule = testLogic.getItemIDFromLineIndex(1);
			unsigned int IdFromSchedule2 = testLogic.getItemIDFromLineIndex(2);
			unsigned int IdFromSchedule3 = testLogic.getItemIDFromLineIndex(3);
			unsigned int IdFromSchedule4 = testLogic.getItemIDFromLineIndex(4);
			unsigned int IdFromSchedule5 = testLogic.getItemIDFromLineIndex(5);


			Assert::AreEqual(IdFromSchedule, addedItemId);
			Assert::AreEqual(IdFromSchedule2, addedItemId2);
			Assert::AreEqual(IdFromSchedule3, addedItemId3);
			Assert::AreEqual(IdFromSchedule4, addedItemId4);
			Assert::AreEqual(IdFromSchedule5, addedItemId5);

		}
	};
}
	/*
	TEST_CLASS(AssignPriorityTest)
	{
	public:

		TEST_METHOD(AssignPriorityTest_AssignToNewItem1)
		{

			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			string testItemName;
			char priorityType = 'h';
			testItem.setItemID(356);
			unsigned int addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			Item itemAfterPriorityAdded = testLogic.assignPriorityToNewTask(priorityType);
			Assert::AreSame(itemAfterPriorityAdded.getPriority(), priorityType);
			Assert::AreEqual(itemAfterPriorityAdded.getItemID(), unsigned int(356));

		}
	};
}
		/*TEST_METHOD(AssignPriorityTest_AssignToexistingItem1)
		{

			Logic testLogic;
			Schedule testSchedule;
			string testItemName;
			char priorityType = 'h';
			unsigned int addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			Item itemAfterPriorityAdded = testLogic.assignPriorityToExistingTask(priorityType, 4);
			Assert::AreEqual(itemAfterPriorityAdded.getPriority(), priorityType);
			Assert::AreEqual(itemAfterPriorityAdded.getItemID(), unsigned int(4));

		}

		TEST_METHOD(AssignPriorityTest_AssignToexistingItem2)
		{

			Logic testLogic;
			Schedule testSchedule;
			string testItemName;
			char priorityType = 'h';
			unsigned int addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			addedItemId = testLogic.addTask(testItemName);
			Item itemAfterPriorityAdded = testLogic.assignPriorityToExistingTask(priorityType, 2);
			Assert::AreEqual(itemAfterPriorityAdded.getPriority(), priorityType);
			Assert::AreEqual(itemAfterPriorityAdded.getItemID(), unsigned int(2));

		}
	};
}
	/*TEST_CLASS(AssignLabelTest)
	{
	public:

		TEST_METHOD(AssignLabelTest_AssignToNewItem1)
		{

			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			char labelType = 'p';
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterLabelAdded = testLogic.assignLabelToNewTask(labelType);
			Assert::AreEqual(itemAfterLabelAdded.getLabel(), labelType);
			Assert::AreEqual(itemAfterLabelAdded.getItemID(), unsigned int(5));

		}

		TEST_METHOD(AssignLabelTest_AssignToexistingItem1)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			char labelType = 'p';
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterLabelAdded = testLogic.assignLabelToExistingTask(labelType, unsigned int(3));
			Assert::AreEqual(itemAfterLabelAdded.getLabel(), labelType);
			Assert::AreEqual(itemAfterLabelAdded.getItemID(), unsigned int(3));

		}
	};

	TEST_CLASS(AssignTimingTest)
	{
	public:

		TEST_METHOD(AssignTimingTest_AssignToNewItem1_StartTime)
		{

			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			DateTime testDateTime(1990, 12, 26);
			string timingType = "start";
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterTimingAdded = testLogic.assignTimingToNewTask(timingType, testDateTime);
			int expectedYear = itemAfterTimingAdded.getStartTime().getYear();
			int expectedMonth = itemAfterTimingAdded.getStartTime().getMonth();
			int expectedDay = itemAfterTimingAdded.getStartTime().getDay();
			unsigned int expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedYear, 1990);
			Assert::AreEqual(expectedMonth, 12);
			Assert::AreEqual(expectedDay, 26);
			Assert::AreEqual(expectedItemID, unsigned int(5));

		}
		TEST_METHOD(AssignTimingTest_AssignToNewItem1_Endtime)
		{

			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			DateTime testDateTime(1990, 12, 26);
			string timingType = "end";
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterTimingAdded = testLogic.assignTimingToNewTask(timingType, testDateTime);
			int expectedYear = itemAfterTimingAdded.getEndTime().getYear();
			int expectedMonth = itemAfterTimingAdded.getEndTime().getMonth();
			int expectedDay = itemAfterTimingAdded.getEndTime().getDay();
			unsigned int expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedYear, 1990);
			Assert::AreEqual(expectedMonth, 12);
			Assert::AreEqual(expectedDay, 26);
			Assert::AreEqual(expectedItemID, unsigned int(5));

		}

		TEST_METHOD(AssignTimingTest_AssignToNewItem1_StartAndEndtime)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			DateTime testDateTime(1990, 12, 26);
			DateTime testDateTime2(2015, 12, 25);
			string timingType = "start";
			string timingType2 = "end";
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterTimingAdded = testLogic.assignTimingToNewTask(timingType, testDateTime);
			int expectedYear = itemAfterTimingAdded.getStartTime().getYear();
			int expectedMonth = itemAfterTimingAdded.getStartTime().getMonth();
			int expectedDay = itemAfterTimingAdded.getStartTime().getDay();
			itemAfterTimingAdded = testLogic.assignTimingToNewTask(timingType2, testDateTime2);
			int expectedYear2 = itemAfterTimingAdded.getEndTime().getYear();
			int expectedMonth2 = itemAfterTimingAdded.getEndTime().getMonth();
			int expectedDay2 = itemAfterTimingAdded.getEndTime().getDay();
			unsigned int expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedYear, 1990);
			Assert::AreEqual(expectedMonth, 12);
			Assert::AreEqual(expectedDay, 26);
			Assert::AreEqual(expectedYear2, 2015);
			Assert::AreEqual(expectedMonth2, 12);
			Assert::AreEqual(expectedDay2, 25);
			Assert::AreEqual(expectedItemID, unsigned int(5));

		}

		TEST_METHOD(AssignTimingTest_AssignToExistingItem1_StartTime)
		{

			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			DateTime testDateTime(1990, 12, 26);
			string timingType = "start";
			unsigned int lineNumberToBeAddedTiming = 3;
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterTimingAdded = testLogic.assignTimingToExistingTask(timingType, testDateTime, lineNumberToBeAddedTiming);
			int expectedYear = itemAfterTimingAdded.getStartTime().getYear();
			int expectedMonth = itemAfterTimingAdded.getStartTime().getMonth();
			int expectedDay = itemAfterTimingAdded.getStartTime().getDay();
			unsigned int expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedYear, 1990);
			Assert::AreEqual(expectedMonth, 12);
			Assert::AreEqual(expectedDay, 26);
			Assert::AreEqual(expectedItemID, unsigned int(3));

		}
		TEST_METHOD(AssignTimingTest_AssignToExistingItem1_Endtime)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			DateTime testDateTime(1990, 12, 26);
			string timingType = "end";
			unsigned int lineNumberToBeAddedTiming = 4;
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterTimingAdded = testLogic.assignTimingToExistingTask(timingType, testDateTime, lineNumberToBeAddedTiming);
			int expectedYear = itemAfterTimingAdded.getEndTime().getYear();
			int expectedMonth = itemAfterTimingAdded.getEndTime().getMonth();
			int expectedDay = itemAfterTimingAdded.getEndTime().getDay();
			unsigned int expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedYear, 1990);
			Assert::AreEqual(expectedMonth, 12);
			Assert::AreEqual(expectedDay, 26);
			Assert::AreEqual(expectedItemID, unsigned int(4));
		}

		TEST_METHOD(AssignTimingTest_AssignToExistingItem1_StartAndEndtime)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			DateTime testDateTime(1990, 12, 26);
			DateTime testDateTime2(2015, 12, 25);
			string timingType = "start";
			string timingType2 = "end";
			unsigned int lineNumberToBeAddedTiming = 2;
			unsigned int addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			addedItemId = testLogic.addTask(testItem);
			Item itemAfterTimingAdded = testLogic.assignTimingToExistingTask(timingType, testDateTime, lineNumberToBeAddedTiming);
			int expectedYear = itemAfterTimingAdded.getStartTime().getYear();
			int expectedMonth = itemAfterTimingAdded.getStartTime().getMonth();
			int expectedDay = itemAfterTimingAdded.getStartTime().getDay();
			unsigned int expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedItemID, unsigned int(2));
			itemAfterTimingAdded = testLogic.assignTimingToExistingTask(timingType2, testDateTime2, lineNumberToBeAddedTiming);
			int expectedYear2 = itemAfterTimingAdded.getEndTime().getYear();
			int expectedMonth2 = itemAfterTimingAdded.getEndTime().getMonth();
			int expectedDay2 = itemAfterTimingAdded.getEndTime().getDay();
			expectedItemID = itemAfterTimingAdded.getItemID();
			Assert::AreEqual(expectedYear, 1990);
			Assert::AreEqual(expectedMonth, 12);
			Assert::AreEqual(expectedDay, 26);
			Assert::AreEqual(expectedYear2, 2015);
			Assert::AreEqual(expectedMonth2, 12);
			Assert::AreEqual(expectedDay2, 25);
			Assert::AreEqual(expectedItemID, unsigned int(2));
		}
	};

	TEST_CLASS(SearchTaskTest)
	{
	public:

		TEST_METHOD(SearchTaskTest1)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			testItem.setItemName("Hello");
			unsigned int addedItemId = testLogic.addTask(testItem);
			testItem.setItemName("Hi");
			addedItemId = testLogic.addTask(testItem);
			testItem.setItemName("Hey");
			addedItemId = testLogic.addTask(testItem);
			testItem.setItemName("sdfw");
			addedItemId = testLogic.addTask(testItem);
			testItem.setItemName("qwerqy");
			addedItemId = testLogic.addTask(testItem);
			testItem.setItemName("ccjh");
			addedItemId = testLogic.addTask(testItem);
			string phraseToBeSearched = "H";
			vector<Item> searchedItems = testLogic.searchTask(phraseToBeSearched);
			string expectedItemName1 = "Hello";
			string expectedItemName2 = "Hi";
			string expectedItemName3 = "Hey";

			Assert::AreEqual(searchedItems[0].getItemName(), expectedItemName1);
			Assert::AreEqual(searchedItems[1].getItemName(), expectedItemName2);
			Assert::AreEqual(searchedItems[2].getItemName(), expectedItemName3);
		}

		TEST_METHOD(SearchTaskTest2)
		{
			Assert::AreEqual("Hi", "Hi");
		}

	};

}

*/