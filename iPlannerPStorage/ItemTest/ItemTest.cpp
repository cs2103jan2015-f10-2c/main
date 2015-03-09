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

	TEST_CLASS(TEST_GETITEM)
	{
	public:

		TEST_METHOD(TestGetItemName)
		{
			Item trueStory;

			string itemName("Project Marriage");
			trueStory.setItemName(itemName);
			string outputName = trueStory.getItemName();
			Assert::AreEqual(itemName, outputName);

			itemName = "";
			trueStory.setItemName(itemName);
			outputName = trueStory.getItemName();
			Assert::AreEqual(itemName, outputName);

			itemName = "123456!@#$%^";
			trueStory.setItemName(itemName);
			outputName = trueStory.getItemName();
			Assert::AreEqual(itemName, outputName);
		}

		TEST_METHOD(TestGetDescription)
		{
			Item trueStory;

			string description("Joon Fai and Gantian are going to get married soon.");
			trueStory.setDescription(description);
			string outputDesc = trueStory.getDescription();
			Assert::AreEqual(description, outputDesc);

			description = "";
			trueStory.setDescription(description);
			outputDesc = trueStory.getDescription();
			Assert::AreEqual(description, outputDesc);

			description = "<3 <3 <3";
			trueStory.setDescription(description);
			outputDesc = trueStory.getDescription();
			Assert::AreEqual(description, outputDesc);
		}

		TEST_METHOD(TestGetStartTime)
		{
			Item trueStory;

			DateTime dateTime(1994, 12, 12);
			trueStory.setStartTime(dateTime);
			DateTime outputDateTime = trueStory.getStartTime();
			
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());

			dateTime.setHour(20);
			dateTime.setMinute(9);
			trueStory.setStartTime(dateTime);
			outputDateTime = trueStory.getStartTime();
			
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());
			Assert::AreEqual(dateTime.getHour(), outputDateTime.getHour());
			Assert::AreEqual(dateTime.getMinute(), outputDateTime.getMinute());
		}

		TEST_METHOD(TestGetEndTime)
		{
			Item trueStory;

			DateTime dateTime(1994, 12, 12);
			trueStory.setEndTime(dateTime);
			DateTime outputDateTime = trueStory.getEndTime();

			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());

			dateTime.setHour(20);
			dateTime.setMinute(9);
			trueStory.setEndTime(dateTime);
			outputDateTime = trueStory.getEndTime();

			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());
			Assert::AreEqual(dateTime.getHour(), outputDateTime.getHour());
			Assert::AreEqual(dateTime.getMinute(), outputDateTime.getMinute());
		}

		TEST_METHOD(TestGetItemID)
		{
			Item trueStory;

			unsigned int itemID = 20091992;
			trueStory.setItemID(itemID);
			unsigned int outputID = trueStory.getItemID();
			Assert::AreEqual(itemID, outputID);
		}

		TEST_METHOD(TestGetPriority)
		{
			Item trueStory;

			char priority = 'H';
			trueStory.setPriority(priority);
			char outputPriority = trueStory.getPriority();
			Assert::AreEqual(priority, outputPriority);
		}

		TEST_METHOD(TestGetLabel)
		{
			Item trueStory;

			char label = 'P';
			trueStory.setLabel(label);
			char outputLabel = trueStory.getLabel();
			Assert::AreEqual(label, outputLabel);
		}

		TEST_METHOD(TestGetCompletion)
		{
			Item trueStory;

			bool isCompleted = true;
			trueStory.setCompletion(isCompleted);
			bool outputCompletion = trueStory.getCompletion();
			Assert::AreEqual(isCompleted, outputCompletion);

			isCompleted = false;
			trueStory.setCompletion(isCompleted);
			outputCompletion = trueStory.getCompletion();
			Assert::AreEqual(isCompleted, outputCompletion);
		}
	};
}