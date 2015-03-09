#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ItemTest
{		
	TEST_CLASS(TEST_SETITEM)
	{
	public:
		
		TEST_METHOD(TestSetItemName)
		{
			Item trueStory;
			
			string itemName ("Project Marriage");
			string outputName = trueStory.setItemName(itemName);
			Assert::AreEqual(itemName, outputName);

			itemName = "";
			outputName = trueStory.setItemName(itemName);
			Assert::AreEqual(itemName, outputName);

			itemName = "123456!@#$%^";
			outputName = trueStory.setItemName(itemName);
			Assert::AreEqual(itemName, outputName);
		}

		TEST_METHOD(TestSetDescription)
		{
			Item trueStory;

			string description("Joon Fai and Gantian are going to get married soon.");
			string outputDesc = trueStory.setDescription(description);
			Assert::AreEqual(description, outputDesc);

			description = "";
			outputDesc = trueStory.setDescription(description);
			Assert::AreEqual(description, outputDesc);

			description = "<3 <3 <3";
			outputDesc = trueStory.setDescription(description);
			Assert::AreEqual(description, outputDesc);
		}

		TEST_METHOD(TestSetStartTime)
		{
			Item trueStory;
			
			DateTime dateTime(1994, 12, 12);
			DateTime outputDateTime = trueStory.setStartTime(dateTime);
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());

			dateTime.setHour (20);
			dateTime.setMinute(9);
			outputDateTime = trueStory.setStartTime(dateTime);
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());
			Assert::AreEqual(dateTime.getHour(), outputDateTime.getHour());
			Assert::AreEqual(dateTime.getMinute(), outputDateTime.getMinute());
		}

		TEST_METHOD(TestSetEndTime)
		{
			Item trueStory;

			DateTime dateTime(1994, 12, 12);
			DateTime outputDateTime = trueStory.setEndTime(dateTime);
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());

			dateTime.setHour(20);
			dateTime.setMinute(9);
			outputDateTime = trueStory.setEndTime(dateTime);
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());
			Assert::AreEqual(dateTime.getHour(), outputDateTime.getHour());
			Assert::AreEqual(dateTime.getMinute(), outputDateTime.getMinute());
		}

		TEST_METHOD(TestSetItemID)
		{
			Item trueStory;

			unsigned int itemID = 20091992;
			unsigned int outputID = trueStory.setItemID(itemID);
			Assert::AreEqual(itemID, outputID);
		}

		TEST_METHOD(TestSetPriority)
		{
			Item trueStory;

			char priority = 'H';
			char outputPriority = trueStory.setPriority(priority);
			Assert::AreEqual(priority, outputPriority);
		}

		TEST_METHOD(TestSetLabel)
		{
			Item trueStory;

			char label = 'P';
			char outputLabel = trueStory.setLabel(label);
			Assert::AreEqual(label, outputLabel);
		}

		TEST_METHOD(TestSetCompletion)
		{
			Item trueStory;

			bool isCompleted = true;
			bool outputCompletion = trueStory.setCompletion(isCompleted);
			Assert::AreEqual(isCompleted, outputCompletion);

			isCompleted = false;
			outputCompletion = trueStory.setCompletion(isCompleted);
			Assert::AreEqual(isCompleted, outputCompletion);
		}
	};
}