#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DateTimeTest
{
	TEST_CLASS(TEST_SET_DATETIME)
	{
	public:

		TEST_METHOD(TestSetYear)
		{
			DateTime dateTime;
			int year = 1994;

			int outputYear = dateTime.setYear(year);

			Assert::AreEqual(year, outputYear);
		}

		TEST_METHOD(TestSetMonth)
		{
			DateTime dateTime;
			int month = 12;

			int outputMonth = dateTime.setMonth(month);

			Assert::AreEqual(month, outputMonth);
		}

		TEST_METHOD(TestSetDay)
		{
			DateTime dateTime;
			int day = 12;

			int outputDay = dateTime.setDay(day);

			Assert::AreEqual(day, outputDay);
		}

		TEST_METHOD(TestSetHour)
		{
			DateTime dateTime;
			int hour = 15;

			int outputHour = dateTime.setHour(hour);

			Assert::AreEqual(hour, outputHour);
		}

		TEST_METHOD(TestSetMinute)
		{
			DateTime dateTime;
			int minute = 15;

			int outputMinute = dateTime.setMinute(minute);

			Assert::AreEqual(minute, outputMinute);
		}

		TEST_METHOD(TestConstructor){
			DateTime dateTime;

			Assert::AreEqual(-1, dateTime.getYear());
			Assert::AreEqual(-1, dateTime.getMonth());
			Assert::AreEqual(-1, dateTime.getDay());
			Assert::AreEqual(-1, dateTime.getHour());
			Assert::AreEqual(-1, dateTime.getMinute());
		}
	};

	TEST_CLASS(TEST_GET_DATETIME)
	{
	public:

		TEST_METHOD(TestGetYear)
		{
			DateTime dateTime;
			int year = 1994;

			dateTime.setYear(year);
			int outputYear = dateTime.getYear();

			Assert::AreEqual(year, outputYear);
		}

		TEST_METHOD(TestGetMonth)
		{
			DateTime dateTime;
			int month = 12;

			dateTime.setMonth(month);
			int outputMonth = dateTime.getMonth();

			Assert::AreEqual(month, outputMonth);
		}

		TEST_METHOD(TestGetDay)
		{
			DateTime dateTime;
			int day = 12;

			dateTime.setDay(day);
			int outputDay = dateTime.getDay();

			Assert::AreEqual(day, outputDay);
		}

		TEST_METHOD(TestGetHour)
		{
			DateTime dateTime;
			int hour = 15;

			dateTime.setHour(hour);
			int outputHour = dateTime.getHour();

			Assert::AreEqual(hour, outputHour);
		}

		TEST_METHOD(TestGetMinute)
		{
			DateTime dateTime;
			int minute = 15;

			dateTime.setMinute(minute);
			int outputMinute = dateTime.getMinute();

			Assert::AreEqual(minute, outputMinute);
		}
	};

	//	Boolean functions tested before classifying them as private functions
	/*	TEST_CLASS(TEST_IS_WITHIN_RANGE)
		{
		public:

		TEST_METHOD(TestIsValidYearRange)
		{
		DateTime dateTime;

		int year = 1994;
		bool outputYear = dateTime.isValidYearRange(year);
		Assert::AreEqual(true, outputYear);

		year = 0;
		outputYear = dateTime.isValidYearRange(year);
		Assert::AreEqual(true, outputYear);

		year = 9999;
		outputYear = dateTime.isValidYearRange(year);
		Assert::AreEqual(true, outputYear);

		//	Boundary Tests
		year = -1;
		outputYear = dateTime.isValidYearRange(year);
		Assert::AreEqual(false, outputYear);

		year = 10000;
		outputYear = dateTime.isValidYearRange(year);
		Assert::AreEqual(false, outputYear);
		}

		TEST_METHOD(TestIsValidMonthRange)
		{
		DateTime dateTime;

		int month = 9;
		bool outputMonth = dateTime.isValidMonthRange(month);
		Assert::AreEqual(true, outputMonth);

		month = 1;
		outputMonth = dateTime.isValidMonthRange(month);
		Assert::AreEqual(true, outputMonth);

		month = 12;
		outputMonth = dateTime.isValidMonthRange(month);
		Assert::AreEqual(true, outputMonth);

		//	Boundary Tests
		month = 0;
		outputMonth = dateTime.isValidMonthRange(month);
		Assert::AreEqual(false, outputMonth);

		month = 13;
		outputMonth = dateTime.isValidMonthRange(month);
		Assert::AreEqual(false, outputMonth);
		}

		TEST_METHOD(TestIsValidDayRange)
		{
		DateTime dateTime;

		int day = 12;
		bool outputDay = dateTime.isValidDayRange(day);
		Assert::AreEqual(true, outputDay);

		day = 1;
		outputDay = dateTime.isValidDayRange(day);
		Assert::AreEqual(true, outputDay);

		day = 31;
		outputDay = dateTime.isValidDayRange(day);
		Assert::AreEqual(true, outputDay);

		//	Boundary Tests
		day = 0;
		outputDay = dateTime.isValidDayRange(day);
		Assert::AreEqual(false, outputDay);

		day = 32;
		outputDay = dateTime.isValidDayRange(day);
		Assert::AreEqual(false, outputDay);
		}

		TEST_METHOD(TestIsValidHourRange)
		{
		DateTime dateTime;

		int hour = 12;
		bool outputHour = dateTime.isValidHourRange(hour);
		Assert::AreEqual(true, outputHour);

		hour = 0;
		outputHour = dateTime.isValidHourRange(hour);
		Assert::AreEqual(true, outputHour);

		hour = 23;
		outputHour = dateTime.isValidHourRange(hour);
		Assert::AreEqual(true, outputHour);

		//	Boundary Tests
		hour = 24;
		outputHour = dateTime.isValidHourRange(hour);
		Assert::AreEqual(false, outputHour);

		hour = -1;
		outputHour = dateTime.isValidHourRange(hour);
		Assert::AreEqual(false, outputHour);
		}

		TEST_METHOD(TestIsValidMinuteRange)
		{
		DateTime dateTime;

		int minute = 12;
		bool outputMinute = dateTime.isValidMinuteRange(minute);
		Assert::AreEqual(true, outputMinute);

		minute = 0;
		outputMinute = dateTime.isValidMinuteRange(minute);
		Assert::AreEqual(true, outputMinute);

		minute = 59;
		outputMinute = dateTime.isValidMinuteRange(minute);
		Assert::AreEqual(true, outputMinute);

		//	Boundary Tests
		minute = -1;
		outputMinute = dateTime.isValidMinuteRange(minute);
		Assert::AreEqual(false, outputMinute);

		minute = 60;
		outputMinute = dateTime.isValidMinuteRange(minute);
		Assert::AreEqual(false, outputMinute);
		}
		<<<<<<< HEAD
		}; */

	TEST_CLASS(TEST_COMPARATORS)
	{
	public:

		TEST_METHOD(TestIsEqual)
		{
			DateTime primary(1994, 12, 12);
			DateTime secondary(1994, 12, 12);
			bool outputEqual = false;
			if (primary == secondary) {
				outputEqual = true;
			}
			else {
				outputEqual = false;
			}
			Assert::AreEqual(true, outputEqual);

			primary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			if (primary == secondary) {
				outputEqual = true;
			}
			else {
				outputEqual = false;
			}
			Assert::AreEqual(false, outputEqual);

			primary.setYear(1994);
			primary.setMonth(12);
			primary.setDay(12);
			primary.setHour(20);
			primary.setMinute(9);
			secondary.setHour(20);
			secondary.setMinute(9);
			if (primary == secondary) {
				outputEqual = true;
			}
			else {
				outputEqual = false;
			}
			Assert::AreEqual(true, outputEqual);

			primary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			if (primary == secondary) {
				outputEqual = true;
			}
			else {
				outputEqual = false;
			}
			Assert::AreEqual(false, outputEqual);
		}

		TEST_METHOD(TestIsNotEqual)
		{
			DateTime primary(1994, 12, 12);
			DateTime secondary(1994, 12, 12);
			bool outputNotEqual;
			if (primary != secondary) {
				outputNotEqual = true;
			}
			else {
				outputNotEqual = false;
			}
			Assert::AreEqual(false, outputNotEqual);

			primary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			if (primary != secondary) {
				outputNotEqual = true;
			}
			else {
				outputNotEqual = false;
			}
			Assert::AreEqual(true, outputNotEqual);

			primary.setYear(1994);
			primary.setMonth(12);
			primary.setDay(12);
			primary.setHour(20);
			primary.setMinute(9);
			secondary.setHour(20);
			secondary.setMinute(9);
			if (primary != secondary) {
				outputNotEqual = true;
			}
			else {
				outputNotEqual = false;
			}
			Assert::AreEqual(false, outputNotEqual);

			primary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			if (primary != secondary) {
				outputNotEqual = true;
			}
			else {
				outputNotEqual = false;
			}
			Assert::AreEqual(true, outputNotEqual);
		}

		TEST_METHOD(TestIsAfter)
		{
			DateTime primary(1994, 12, 12);
			DateTime secondary(1994, 12, 12);
			bool outputEqual = primary.isAfter(secondary);
			Assert::AreEqual(false, outputEqual);

			secondary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			outputEqual = primary.isAfter(secondary);
			Assert::AreEqual(true, outputEqual);

			secondary.setYear(1994);
			primary.setMonth(12);
			primary.setDay(12);
			primary.setHour(20);
			primary.setMinute(9);
			secondary.setHour(20);
			secondary.setMinute(9);
			outputEqual = primary.isAfter(secondary);
			Assert::AreEqual(false, outputEqual);

			secondary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			outputEqual = primary.isAfter(secondary);
			Assert::AreEqual(true, outputEqual);
		}

		TEST_METHOD(TestIsBefore)
		{
			DateTime primary(1994, 12, 12);
			DateTime secondary(1994, 12, 12);
			bool outputEqual = primary.isBefore(secondary);
			Assert::AreEqual(false, outputEqual);

			primary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			outputEqual = primary.isBefore(secondary);
			Assert::AreEqual(true, outputEqual);

			primary.setYear(1994);
			primary.setMonth(12);
			primary.setDay(12);
			primary.setHour(20);
			primary.setMinute(9);
			secondary.setHour(20);
			secondary.setMinute(9);
			outputEqual = primary.isBefore(secondary);
			Assert::AreEqual(false, outputEqual);

			primary.setYear(1992);
			primary.setMonth(9);
			primary.setDay(20);
			outputEqual = primary.isBefore(secondary);
			Assert::AreEqual(true, outputEqual);
		}
	};

	TEST_CLASS(TEST_DISPLAY) {
public:

	TEST_METHOD(TestDisplayDate)
	{
		DateTime dateOnly(1992, 9, 20);
		string outputString = dateOnly.displayDate();
		Assert::AreEqual((string) "1992 09 20", outputString);
	}

	TEST_METHOD(TestDisplayTime)
	{
		DateTime timeOnly;
		timeOnly.setHour(9);
		timeOnly.setMinute(20);
		string outputString = timeOnly.displayTime();
		Assert::AreEqual((string) "09:20", outputString);
	}

	TEST_METHOD(TestDisplayDateTime)
	{
		DateTime dateTime(1994, 12, 12, 20, 9);
		string outputString = dateTime.displayDateTime();
		Assert::AreEqual((string) "1994 12 12 20:09", outputString);

		DateTime dateOnly(1992, 9, 20);
		outputString = dateOnly.displayDateTime();
		Assert::AreEqual((string) "1992 09 20", outputString);

		DateTime timeOnly;
		timeOnly.setHour(9);
		timeOnly.setMinute(20);
		outputString = timeOnly.displayDateTime();
		Assert::AreEqual((string) "09:20", outputString);

		DateTime emptyDateTime;
		outputString = emptyDateTime.displayDateTime();
		Assert::AreEqual((string)"", outputString);
	}
	};
}

namespace ItemTest
{
	TEST_CLASS(TEST_SET_ITEM)
	{
	public:

		TEST_METHOD(TestSetItemName)
		{
			Item trueStory;

			string itemName("Project Marriage");
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

			dateTime.setHour(20);
			dateTime.setMinute(9);
			outputDateTime = trueStory.setStartTime(dateTime);
			Assert::AreEqual(dateTime.getYear(), outputDateTime.getYear());
			Assert::AreEqual(dateTime.getMonth(), outputDateTime.getMonth());
			Assert::AreEqual(dateTime.getDay(), outputDateTime.getDay());
			Assert::AreEqual(dateTime.getHour(), outputDateTime.getHour());
			Assert::AreEqual(dateTime.getMinute(), outputDateTime.getMinute());

			outputDateTime = trueStory.setStartTime(1992, 9, 20, 12, 12);
			Assert::AreEqual(1992, outputDateTime.getYear());
			Assert::AreEqual(9, outputDateTime.getMonth());
			Assert::AreEqual(20, outputDateTime.getDay());
			Assert::AreEqual(12, outputDateTime.getHour());
			Assert::AreEqual(12, outputDateTime.getMinute());

			outputDateTime = trueStory.setStartTime(1995, 11, 19);
			Assert::AreEqual(1995, outputDateTime.getYear());
			Assert::AreEqual(11, outputDateTime.getMonth());
			Assert::AreEqual(19, outputDateTime.getDay());
			Assert::AreEqual(-1, outputDateTime.getHour());
			Assert::AreEqual(-1, outputDateTime.getMinute());
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

			outputDateTime = trueStory.setEndTime(1992, 9, 20, 12, 12);
			Assert::AreEqual(1992, outputDateTime.getYear());
			Assert::AreEqual(9, outputDateTime.getMonth());
			Assert::AreEqual(20, outputDateTime.getDay());
			Assert::AreEqual(12, outputDateTime.getHour());
			Assert::AreEqual(12, outputDateTime.getMinute());

			outputDateTime = trueStory.setEndTime(1995, 11, 19);
			Assert::AreEqual(1995, outputDateTime.getYear());
			Assert::AreEqual(11, outputDateTime.getMonth());
			Assert::AreEqual(19, outputDateTime.getDay());
			Assert::AreEqual(-1, outputDateTime.getHour());
			Assert::AreEqual(-1, outputDateTime.getMinute());
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

	TEST_CLASS(TEST_GET_ITEM)
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

	TEST_CLASS(TEST_DISPLAY){
public:
	TEST_METHOD(TestDisplayStartTime){
		Item item;

		DateTime dateTime(1994, 12, 12, 20, 9);
		item.setStartTime(dateTime);
		string outputString = item.displayStartTime();
		Assert::AreEqual((string) "1994 12 12 20:09", outputString);

		DateTime dateOnly(1992, 9, 20);
		item.setStartTime(dateOnly);
		outputString = item.displayStartTime();
		Assert::AreEqual((string) "1992 09 20", outputString);

		DateTime timeOnly;
		timeOnly.setHour(9);
		timeOnly.setMinute(20);
		item.setStartTime(timeOnly);
		outputString = item.displayStartTime();
		Assert::AreEqual((string) "09:20", outputString);
	}

	TEST_METHOD(TestDisplayEndTime){
		Item item;

		DateTime dateTime(1994, 12, 12, 20, 9);
		item.setEndTime(dateTime);
		string outputString = item.displayEndTime();
		Assert::AreEqual((string) "1994 12 12 20:09", outputString);

		DateTime dateOnly(1992, 9, 20);
		item.setEndTime(dateOnly);
		outputString = item.displayEndTime();
		Assert::AreEqual((string) "1992 09 20", outputString);

		DateTime timeOnly;
		timeOnly.setHour(9);
		timeOnly.setMinute(20);
		item.setEndTime(timeOnly);
		outputString = item.displayEndTime();
		Assert::AreEqual((string) "09:20", outputString);
	}

	TEST_METHOD(TestDisplayItemForUser){
		Item item;
		ostringstream outputString;

		item.setItemName("Short Jog");
		outputString << "Name:\tShort Jog\n";
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setStartTime(2015, 3, 17, 6, 30);
		outputString << "Start Time:\t2015 03 17 06:30\n";
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setEndTime(2015, 3, 17, 7, 0);
		outputString << "End Time:\t2015 03 17 07:00\n";
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setDescription("4km in 30 minutes");
		outputString << "Description:\t4km in 30 minutes\n";
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setItemID(1992);
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setLabel('P');
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setPriority('H');
		Assert::AreEqual(outputString.str(), item.displayItemForUser());

		item.setCompletion(true);
		Assert::AreEqual(outputString.str(), item.displayItemForUser());
	}

	TEST_METHOD(TestDisplayItemFullDetails){
		Item item;
		ostringstream outputString;

		item.setItemID(1992);
		outputString << "Item ID:\t1992\n";

		item.setItemName("Short Jog");
		outputString << "Name:\tShort Jog\n";

		item.setStartTime(2015, 3, 17, 6, 30);
		outputString << "Start Time:\t2015 03 17 06:30\n";

		item.setEndTime(2015, 3, 17, 7, 0);
		outputString << "End Time:\t2015 03 17 07:00\n";

		item.setDescription("4km in 30 minutes");
		outputString << "Description:\t4km in 30 minutes\n";

		item.setPriority('H');
		outputString << "Priority:\tH\n";

		item.setLabel('P');
		outputString << "Label:\tP\n";

		item.setCompletion(true);
		outputString << "Completed?\ttrue\n";
		Assert::AreEqual(outputString.str(), item.displayItemFullDetails());
	}
	};
}

namespace ScheduleTest
{
	TEST_CLASS(TEST_SCHEDULE)
	{
	public:

		TEST_METHOD(TestRetrieveSchedule)
		{
			Schedule YoungbinLifeEvents;
			vector <Item> YoungbinParallelUniverse;
			Item *marriage = new Item;

			marriage->setItemName("Marriage with Sophie");
			marriage->setDescription("Hope it'll last this time.");
			marriage->setItemID(101);
			marriage->setLabel('M');
			marriage->setPriority('H');
			marriage->setStartTime(2015, 9, 20, 12, 12);

			YoungbinLifeEvents.addItem(marriage);
			YoungbinParallelUniverse = YoungbinLifeEvents.retrieveSchedule();
			Assert::AreEqual(marriage->displayItemFullDetails(), YoungbinParallelUniverse[0].displayItemFullDetails());
			delete marriage;

			marriage = new Item;
			marriage->setItemName("Second Marriage");
			marriage->setDescription("Wife: Victoria Secret model.");
			marriage->setItemID(2103);
			marriage->setLabel('P');
			marriage->setPriority('H');
			marriage->setStartTime(2015, 9, 21, 0, 0);

			YoungbinLifeEvents.addItem(marriage);
			YoungbinParallelUniverse = YoungbinLifeEvents.retrieveSchedule();
			Assert::AreEqual(marriage->displayItemFullDetails(), YoungbinParallelUniverse[1].displayItemFullDetails());
			delete marriage;
		}

		TEST_METHOD(TestGetScheduleSize)
		{
			Schedule YoungbinLifeEvents;
			Item *marriage = new Item;

			marriage->setItemName("Marriage with Sophie");
			marriage->setDescription("Hope it'll last this time.");
			marriage->setItemID(101);
			marriage->setLabel('M');
			marriage->setPriority('H');
			marriage->setStartTime(2015, 9, 20, 12, 12);

			YoungbinLifeEvents.addItem(marriage);
			delete marriage;
			Assert::AreEqual((unsigned int)1, YoungbinLifeEvents.getSizeOfSchedule());

			marriage = new Item;
			marriage->setItemName("Second Marriage");
			marriage->setDescription("Wife: Victoria Secret model.");
			marriage->setItemID(2103);
			marriage->setLabel('P');
			marriage->setPriority('H');
			marriage->setStartTime(2015, 9, 21, 0, 0);

			YoungbinLifeEvents.addItem(marriage);
			delete marriage;
			Assert::AreEqual((unsigned int)2, YoungbinLifeEvents.getSizeOfSchedule());
		}
	};

	TEST_CLASS(TEST_CONVERSION)
	{
		TEST_METHOD(TestFindVectorIndexGivenItemID)
		{
			Schedule premierLeague;
			Item soccerMatch;

			for (int i = 0; i < 10; i++) {
				soccerMatch.setItemID(1000 + i);
				premierLeague.addItem(&soccerMatch);
			}

			for (unsigned int i = 0; i < 10; i++) {
				Assert::AreEqual(i, premierLeague.findVectorIndexGivenItemID(1000 + i));
			}
		}
	};

	/*
	TEST_CLASS(TEST_FILTER)
	{
	public:

	TEST_METHOD(TestFilterByPriority)
	{
	// TODO: Your test code here
	}

	TEST_METHOD(TestFilterByLabel)
	{
	// TODO: Your test code here
	}

	TEST_METHOD(TestFilterByCompletion)
	{
	// TODO: Your test code here
	}

	TEST_METHOD(TestFilterByDate)
	{
	// TODO: Your test code here
	}
	};

	TEST_CLASS(TEST_SORT)
	{
	public:

	TEST_METHOD(TestSortByPriority)
	{
	// TODO: Your test code here
	}

	TEST_METHOD(TestSortByDate)
	{
	// TODO: Your test code here
	}

	TEST_METHOD(TestSortByLastUpdate)
	{
	// TODO: Your test code here
	}
	};

	TEST_CLASS(TEST_ITEMS_IN_SCHEDULE)
	{
	public:

	TEST_METHOD(TestAddItem)
	{
	Schedule projectLife;
	Item item1;
	DateTime dateTime1(2020, 3, 20, 12, 30);

	item1.setItemName("Joon Fai's Marriage");
	item1.setDescription("Wife: Gantian");
	item1.setEndTime(dateTime1);
	item1.setCompletion(false);
	item1.setItemID(12);
	item1.setPriority('H');
	item1.setLabel('P');

	Item item2;
	DateTime dateTime2(2015, 3, 8, 15, 39);

	item2.setItemName("Chon Beng's Date");
	item2.setDescription("Girlfriend: Multiple");
	item2.setEndTime(dateTime2);
	item2.setCompletion(true);
	item2.setItemID(57);
	item2.setPriority('M');
	item2.setLabel('O');

	Item item3;
	DateTime dateTime3(2015, 4, 1, 14, 0);

	item3.setItemName("Andy's lunch");
	item3.setDescription("Lunch: Nasi Lemak");
	item3.setEndTime(dateTime3);
	item3.setCompletion(false);
	item3.setItemID(201);
	item3.setPriority('H');
	item3.setLabel('M');

	projectLife.addItem(item1);
	projectLife.addItem(item2);
	projectLife.addItem(item3);

	Item tempItem1 = projectLife.retrieveSchedule()[0];
	Assert::AreEqual((string) "Joon Fai's Marriage", tempItem1.getItemName());
	Assert::AreEqual((string) "Wife: Gantian", tempItem1.getDescription());
	Assert::AreEqual(dateTime1.getYear(), tempItem1.getEndTime().getYear());
	Assert::AreEqual(dateTime1.getMonth(), tempItem1.getEndTime().getMonth());
	Assert::AreEqual(dateTime1.getDay(), tempItem1.getEndTime().getDay());
	Assert::AreEqual(dateTime1.getHour(), tempItem1.getEndTime().getHour());
	Assert::AreEqual(dateTime1.getMinute(), tempItem1.getEndTime().getMinute());
	Assert::AreEqual(false, tempItem1.getCompletion());
	Assert::AreEqual((unsigned int)12, tempItem1.getItemID());
	Assert::AreEqual('H', tempItem1.getPriority());
	Assert::AreEqual('P', tempItem1.getLabel());

	Item tempItem2 = projectLife.retrieveSchedule()[1];
	Assert::AreEqual((string) "Chon Beng's Date", tempItem2.getItemName());
	Assert::AreEqual((string) "Girlfriend: Multiple", tempItem2.getDescription());
	Assert::AreEqual(dateTime2.getYear(), tempItem2.getEndTime().getYear());
	Assert::AreEqual(dateTime2.getMonth(), tempItem2.getEndTime().getMonth());
	Assert::AreEqual(dateTime2.getDay(), tempItem2.getEndTime().getDay());
	Assert::AreEqual(dateTime2.getHour(), tempItem2.getEndTime().getHour());
	Assert::AreEqual(dateTime2.getMinute(), tempItem2.getEndTime().getMinute());
	Assert::AreEqual(true, tempItem2.getCompletion());
	Assert::AreEqual((unsigned int)57, tempItem2.getItemID());
	Assert::AreEqual('M', tempItem2.getPriority());
	Assert::AreEqual('O', tempItem2.getLabel());

	Item tempItem3 = projectLife.retrieveSchedule()[2];
	Assert::AreEqual((string) "Andy's lunch", tempItem3.getItemName());
	Assert::AreEqual((string) "Lunch: Nasi Lemak", tempItem3.getDescription());
	Assert::AreEqual(dateTime3.getYear(), tempItem3.getEndTime().getYear());
	Assert::AreEqual(dateTime3.getMonth(), tempItem3.getEndTime().getMonth());
	Assert::AreEqual(dateTime3.getDay(), tempItem3.getEndTime().getDay());
	Assert::AreEqual(dateTime3.getHour(), tempItem3.getEndTime().getHour());
	Assert::AreEqual(dateTime3.getMinute(), tempItem3.getEndTime().getMinute());
	Assert::AreEqual(false, tempItem3.getCompletion());
	Assert::AreEqual((unsigned int)201, tempItem3.getItemID());
	Assert::AreEqual('H', tempItem3.getPriority());
	Assert::AreEqual('M', tempItem3.getLabel());
	}

	TEST_METHOD(TestDeleteItem)
	{
	Schedule projectLife;
	Item item1;
	DateTime dateTime1(2020, 3, 20, 12, 30);

	item1.setItemName("Joon Fai's Marriage");
	item1.setDescription("Wife: Gantian");
	item1.setEndTime(dateTime1);
	item1.setCompletion(false);
	item1.setItemID(12);
	item1.setPriority('H');
	item1.setLabel('P');

	Item item2;
	DateTime dateTime2(2015, 3, 8, 15, 39);

	item2.setItemName("Chon Beng's Date");
	item2.setDescription("Girlfriend: Multiple");
	item2.setEndTime(dateTime2);
	item2.setCompletion(true);
	item2.setItemID(57);
	item2.setPriority('M');
	item2.setLabel('O');

	Item item3;
	DateTime dateTime3(2015, 4, 1, 14, 0);

	item3.setItemName("Andy's lunch");
	item3.setDescription("Lunch: Nasi Lemak");
	item3.setEndTime(dateTime3);
	item3.setCompletion(false);
	item3.setItemID(201);
	item3.setPriority('H');
	item3.setLabel('M');

	projectLife.addItem(item1);
	projectLife.addItem(item2);
	projectLife.addItem(item3);

	Item tempItem1 = projectLife.deleteItem(12);
	Assert::AreEqual((string) "Joon Fai's Marriage", tempItem1.getItemName());
	Assert::AreEqual((string) "Wife: Gantian", tempItem1.getDescription());
	Assert::AreEqual(dateTime1.getYear(), tempItem1.getEndTime().getYear());
	Assert::AreEqual(dateTime1.getMonth(), tempItem1.getEndTime().getMonth());
	Assert::AreEqual(dateTime1.getDay(), tempItem1.getEndTime().getDay());
	Assert::AreEqual(dateTime1.getHour(), tempItem1.getEndTime().getHour());
	Assert::AreEqual(dateTime1.getMinute(), tempItem1.getEndTime().getMinute());
	Assert::AreEqual(false, tempItem1.getCompletion());
	Assert::AreEqual((unsigned int)12, tempItem1.getItemID());
	Assert::AreEqual('H', tempItem1.getPriority());
	Assert::AreEqual('P', tempItem1.getLabel());

	Item tempItem2 = projectLife.retrieveSchedule()[0];
	Assert::AreEqual((string) "Chon Beng's Date", tempItem2.getItemName());
	Assert::AreEqual((string) "Girlfriend: Multiple", tempItem2.getDescription());
	Assert::AreEqual(dateTime2.getYear(), tempItem2.getEndTime().getYear());
	Assert::AreEqual(dateTime2.getMonth(), tempItem2.getEndTime().getMonth());
	Assert::AreEqual(dateTime2.getDay(), tempItem2.getEndTime().getDay());
	Assert::AreEqual(dateTime2.getHour(), tempItem2.getEndTime().getHour());
	Assert::AreEqual(dateTime2.getMinute(), tempItem2.getEndTime().getMinute());
	Assert::AreEqual(true, tempItem2.getCompletion());
	Assert::AreEqual((unsigned int)57, tempItem2.getItemID());
	Assert::AreEqual('M', tempItem2.getPriority());
	Assert::AreEqual('O', tempItem2.getLabel());

	Item tempItem3 = projectLife.retrieveSchedule()[1];
	Assert::AreEqual((string) "Andy's lunch", tempItem3.getItemName());
	Assert::AreEqual((string) "Lunch: Nasi Lemak", tempItem3.getDescription());
	Assert::AreEqual(dateTime3.getYear(), tempItem3.getEndTime().getYear());
	Assert::AreEqual(dateTime3.getMonth(), tempItem3.getEndTime().getMonth());
	Assert::AreEqual(dateTime3.getDay(), tempItem3.getEndTime().getDay());
	Assert::AreEqual(dateTime3.getHour(), tempItem3.getEndTime().getHour());
	Assert::AreEqual(dateTime3.getMinute(), tempItem3.getEndTime().getMinute());
	Assert::AreEqual(false, tempItem3.getCompletion());
	Assert::AreEqual((unsigned int)201, tempItem3.getItemID());
	Assert::AreEqual('H', tempItem3.getPriority());
	Assert::AreEqual('M', tempItem3.getLabel());

	projectLife.addItem(item1);

	tempItem3 = projectLife.deleteItem(201);
	Assert::AreEqual((string) "Andy's lunch", tempItem3.getItemName());
	Assert::AreEqual((string) "Lunch: Nasi Lemak", tempItem3.getDescription());
	Assert::AreEqual(dateTime3.getYear(), tempItem3.getEndTime().getYear());
	Assert::AreEqual(dateTime3.getMonth(), tempItem3.getEndTime().getMonth());
	Assert::AreEqual(dateTime3.getDay(), tempItem3.getEndTime().getDay());
	Assert::AreEqual(dateTime3.getHour(), tempItem3.getEndTime().getHour());
	Assert::AreEqual(dateTime3.getMinute(), tempItem3.getEndTime().getMinute());
	Assert::AreEqual(false, tempItem3.getCompletion());
	Assert::AreEqual((unsigned int)201, tempItem3.getItemID());
	Assert::AreEqual('H', tempItem3.getPriority());
	Assert::AreEqual('M', tempItem3.getLabel());

	tempItem2 = projectLife.retrieveSchedule()[0];
	Assert::AreEqual((string) "Chon Beng's Date", tempItem2.getItemName());
	Assert::AreEqual((string) "Girlfriend: Multiple", tempItem2.getDescription());
	Assert::AreEqual(dateTime2.getYear(), tempItem2.getEndTime().getYear());
	Assert::AreEqual(dateTime2.getMonth(), tempItem2.getEndTime().getMonth());
	Assert::AreEqual(dateTime2.getDay(), tempItem2.getEndTime().getDay());
	Assert::AreEqual(dateTime2.getHour(), tempItem2.getEndTime().getHour());
	Assert::AreEqual(dateTime2.getMinute(), tempItem2.getEndTime().getMinute());
	Assert::AreEqual(true, tempItem2.getCompletion());
	Assert::AreEqual((unsigned int)57, tempItem2.getItemID());
	Assert::AreEqual('M', tempItem2.getPriority());
	Assert::AreEqual('O', tempItem2.getLabel());

	tempItem1 = projectLife.retrieveSchedule()[1];
	Assert::AreEqual((string) "Joon Fai's Marriage", tempItem1.getItemName());
	Assert::AreEqual((string) "Wife: Gantian", tempItem1.getDescription());
	Assert::AreEqual(dateTime1.getYear(), tempItem1.getEndTime().getYear());
	Assert::AreEqual(dateTime1.getMonth(), tempItem1.getEndTime().getMonth());
	Assert::AreEqual(dateTime1.getDay(), tempItem1.getEndTime().getDay());
	Assert::AreEqual(dateTime1.getHour(), tempItem1.getEndTime().getHour());
	Assert::AreEqual(dateTime1.getMinute(), tempItem1.getEndTime().getMinute());
	Assert::AreEqual(false, tempItem1.getCompletion());
	Assert::AreEqual((unsigned int)12, tempItem1.getItemID());
	Assert::AreEqual('H', tempItem1.getPriority());
	Assert::AreEqual('P', tempItem1.getLabel());
	}
	};
	*/
}