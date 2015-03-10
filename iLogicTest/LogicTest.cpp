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
			Assert::AreEqual(unsigned int(13), addedItemId);
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
			Assert::AreEqual(unsigned int(13), addedItemId);
			Assert::AreEqual(unsigned int(25), addedItemId2);
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
			Item deletedItem = testLogic.deleteTask(0);
			Assert::AreEqual(addedItemId, deletedItem.getItemID());
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
		}

	};
}