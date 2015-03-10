#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iLogicTest
{

	TEST_CLASS(AddTaskTest)
	{
	public:

		TEST_METHOD(AddTaskTest1)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItem);
			vector<Item> retrievedSchedule = testLogic.getSchedule();
			unsigned int IdFromSchedule = retrievedSchedule[0].getItemID();
			Assert::AreEqual(addedItemId, IdFromSchedule);
		}

		TEST_METHOD(AddTaskTest2)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItem);
			testItem.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItem);
			unsigned int IdFromSchedule = testLogic.getSchedule()[0].getItemID();
			unsigned int IdFromSchedule2 = testLogic.getSchedule()[1].getItemID();

			Assert::AreEqual(IdFromSchedule, addedItemId);
			Assert::AreEqual(IdFromSchedule2, addedItemId2);
		}

	};

	TEST_CLASS(DeleteTaskTest)
	{
	public:

		TEST_METHOD(DeleteTaskTest1)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItem);
			testItem.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItem);
			testItem.setItemID(35);
			unsigned int addedItemId3 = testLogic.addTask(testItem);
			testItem.setItemID(45);
			unsigned int addedItemId4 = testLogic.addTask(testItem);
			testItem.setItemID(356);
			unsigned int addedItemId5 = testLogic.addTask(testItem);

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
			
			Item deletedItem = testLogic.deleteTask(3);

			Assert::AreEqual(addedItemId3, deletedItem.getItemID());

		}

		TEST_METHOD(DeleteTaskTest2)
		{
			Logic testLogic;
			Schedule testSchedule;
			Item testItem;
			Item testItem2;
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItem);
			testItem2.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItem2);
			Item deletedItem = testLogic.deleteTask(1);
			Assert::AreEqual(addedItemId2, deletedItem.getItemID());
			deletedItem = testLogic.deleteTask(0);
			Assert::AreEqual(addedItemId, deletedItem.getItemID());
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
			testItem.setItemID(13);
			unsigned int addedItemId = testLogic.addTask(testItem);
			testItem.setItemID(25);
			unsigned int addedItemId2 = testLogic.addTask(testItem);
			testItem.setItemID(35);
			unsigned int addedItemId3 = testLogic.addTask(testItem);
			testItem.setItemID(45);
			unsigned int addedItemId4 = testLogic.addTask(testItem);
			testItem.setItemID(356);
			unsigned int addedItemId5 = testLogic.addTask(testItem);

			unsigned int IdFromSchedule = testLogic.getItemIdFromLineIndex(1);
			unsigned int IdFromSchedule2 = testLogic.getItemIdFromLineIndex(2);
			unsigned int IdFromSchedule3 = testLogic.getItemIdFromLineIndex(3);
			unsigned int IdFromSchedule4 = testLogic.getItemIdFromLineIndex(4);
			unsigned int IdFromSchedule5 = testLogic.getItemIdFromLineIndex(5);


			Assert::AreEqual(IdFromSchedule, addedItemId);
			Assert::AreEqual(IdFromSchedule2, addedItemId2);
			Assert::AreEqual(IdFromSchedule3, addedItemId3);
			Assert::AreEqual(IdFromSchedule4, addedItemId4);
			Assert::AreEqual(IdFromSchedule5, addedItemId5);

		}
	};
}