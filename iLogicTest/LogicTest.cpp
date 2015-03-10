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

	};
}