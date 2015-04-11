#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DateTimeTest {
	TEST_CLASS(TEST_SET_DATETIME) {
public:

	TEST_METHOD(TestSetYear) {
		DateTime dateTime;
		int year = 1994;

		int outputYear = dateTime.setYear(year);

		Assert::AreEqual(year, outputYear);
	}

	TEST_METHOD(TestSetMonth) {
		DateTime dateTime;
		int month = 12;

		int outputMonth = dateTime.setMonth(month);

		Assert::AreEqual(month, outputMonth);
	}

	TEST_METHOD(TestSetDay) {
		DateTime dateTime;
		int day = 12;

		int outputDay = dateTime.setDay(day);

		Assert::AreEqual(day, outputDay);
	}

	TEST_METHOD(TestSetHour) {
		DateTime dateTime;
		int hour = 15;

		int outputHour = dateTime.setHour(hour);

		Assert::AreEqual(hour, outputHour);
	}

	TEST_METHOD(TestSetMinute) {
		DateTime dateTime;
		int minute = 15;

		int outputMinute = dateTime.setMinute(minute);

		Assert::AreEqual(minute, outputMinute);
	}

	TEST_METHOD(TestConstructor) {
		DateTime dateTime;

		Assert::AreEqual(-1, dateTime.getYear());
		Assert::AreEqual(-1, dateTime.getMonth());
		Assert::AreEqual(-1, dateTime.getDay());
		Assert::AreEqual(-1, dateTime.getHour());
		Assert::AreEqual(-1, dateTime.getMinute());
	}
	};

	TEST_CLASS(TEST_GET_DATETIME) {
public:

	TEST_METHOD(TestGetYear) {
		DateTime dateTime;
		int year = 1994;

		dateTime.setYear(year);
		int outputYear = dateTime.getYear();

		Assert::AreEqual(year, outputYear);
	}

	TEST_METHOD(TestGetMonth) {
		DateTime dateTime;
		int month = 12;

		dateTime.setMonth(month);
		int outputMonth = dateTime.getMonth();

		Assert::AreEqual(month, outputMonth);
	}

	TEST_METHOD(TestGetDay) {
		DateTime dateTime;
		int day = 12;

		dateTime.setDay(day);
		int outputDay = dateTime.getDay();

		Assert::AreEqual(day, outputDay);
	}

	TEST_METHOD(TestGetHour) {
		DateTime dateTime;
		int hour = 15;

		dateTime.setHour(hour);
		int outputHour = dateTime.getHour();

		Assert::AreEqual(hour, outputHour);
	}

	TEST_METHOD(TestGetMinute) {
		DateTime dateTime;
		int minute = 15;

		dateTime.setMinute(minute);
		int outputMinute = dateTime.getMinute();

		Assert::AreEqual(minute, outputMinute);
	}
	};

	//	Boolean functions tested before classifying them as private functions
	/* TEST_CLASS(TEST_IS_WITHIN_RANGE)
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

		}; */

	TEST_CLASS(TEST_COMPARATORS) {

public:

	TEST_METHOD(TestIsEqual) {
		DateTime primary(1994, 12, 12);
		DateTime secondary(1994, 12, 12);
		bool outputEqual = false;
		if (primary == secondary) {
			outputEqual = true;
		} else {
			outputEqual = false;
		}
		Assert::AreEqual(true, outputEqual);

		primary.setYear(1992);
		primary.setMonth(9);
		primary.setDay(20);
		if (primary == secondary) {
			outputEqual = true;
		} else {
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
		} else {
			outputEqual = false;
		}
		Assert::AreEqual(true, outputEqual);

		primary.setYear(1992);
		primary.setMonth(9);
		primary.setDay(20);
		if (primary == secondary) {
			outputEqual = true;
		} else {
			outputEqual = false;
		}
		Assert::AreEqual(false, outputEqual);
	}

	TEST_METHOD(TestIsNotEqual) {
		DateTime primary(1994, 12, 12);
		DateTime secondary(1994, 12, 12);
		bool outputNotEqual;
		if (primary != secondary) {
			outputNotEqual = true;
		} else {
			outputNotEqual = false;
		}
		Assert::AreEqual(false, outputNotEqual);

		primary.setYear(1992);
		primary.setMonth(9);
		primary.setDay(20);
		if (primary != secondary) {
			outputNotEqual = true;
		} else {
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
		} else {
			outputNotEqual = false;
		}
		Assert::AreEqual(false, outputNotEqual);

		primary.setYear(1992);
		primary.setMonth(9);
		primary.setDay(20);
		if (primary != secondary) {
			outputNotEqual = true;
		} else {
			outputNotEqual = false;
		}
		Assert::AreEqual(true, outputNotEqual);
	}

	TEST_METHOD(TestIsAfter) {
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

	TEST_METHOD(TestIsBefore) {
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

	TEST_METHOD(TestDisplayDate) {
		DateTime dateOnly(1992, 9, 20);
		string outputString = dateOnly.displayDate();
		Assert::AreEqual((string) "1992 09 20", outputString);
	}

	TEST_METHOD(TestDisplayTime) {
		DateTime timeOnly;
		timeOnly.setHour(9);
		timeOnly.setMinute(20);
		string outputString = timeOnly.displayTime();
		Assert::AreEqual((string) "09:20", outputString);
	}

	TEST_METHOD(TestDisplayDateTime) {
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

namespace ItemTest {
	TEST_CLASS(TEST_SET_ITEM) {
public:

	TEST_METHOD(TestSetItemName) {
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

	TEST_METHOD(TestSetDescription) {
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

	TEST_METHOD(TestSetStartTime) {
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

	TEST_METHOD(TestSetEndTime) {
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

	TEST_METHOD(TestSetItemID) {
		Item trueStory;

		unsigned int itemID = 20091992;
		unsigned int outputID = trueStory.setItemID(itemID);
		Assert::AreEqual(itemID, outputID);
	}

	TEST_METHOD(TestSetPriority) {
		Item trueStory;

		char priority = 'H';
		char outputPriority = trueStory.setPriority(priority);
		Assert::AreEqual(priority, outputPriority);
	}

	TEST_METHOD(TestSetLabel) {
		Item trueStory;

		char label = 'P';
		char outputLabel = trueStory.setLabel(label);
		Assert::AreEqual(label, outputLabel);
	}

	TEST_METHOD(TestSetCompletion) {
		Item trueStory;

		bool isCompleted = true;
		bool outputCompletion = trueStory.setCompletion(isCompleted);
		Assert::AreEqual(isCompleted, outputCompletion);

		isCompleted = false;
		outputCompletion = trueStory.setCompletion(isCompleted);
		Assert::AreEqual(isCompleted, outputCompletion);
	}

	TEST_METHOD(ItemTestSetLastUpdate) {
		// Joon Fai
	}

	};

	TEST_CLASS(TEST_GET_ITEM) {
public:

	TEST_METHOD(TestGetItemName) {
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

	TEST_METHOD(TestGetDescription) {
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

	TEST_METHOD(TestGetStartTime) {
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

	TEST_METHOD(TestGetEndTime) {
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

	TEST_METHOD(TestGetItemID) {
		Item trueStory;

		unsigned int itemID = 20091992;
		trueStory.setItemID(itemID);
		unsigned int outputID = trueStory.getItemID();
		Assert::AreEqual(itemID, outputID);
	}

	TEST_METHOD(TestGetPriority) {
		Item trueStory;

		char priority = 'H';
		trueStory.setPriority(priority);
		char outputPriority = trueStory.getPriority();
		Assert::AreEqual(priority, outputPriority);
	}

	TEST_METHOD(TestGetLabel) {
		Item trueStory;

		char label = 'P';
		trueStory.setLabel(label);
		char outputLabel = trueStory.getLabel();
		Assert::AreEqual(label, outputLabel);
	}

	TEST_METHOD(TestGetCompletion) {
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

	TEST_METHOD(ItemTestGetLastUpdate) {
		// Joon Fai
	}

	};

	TEST_CLASS(TEST_DISPLAY) {
public:
	TEST_METHOD(TestDisplayStartTime) {
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

	TEST_METHOD(TestDisplayEndTime) {
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

	TEST_METHOD(TestDisplayItemForUser) {
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

	TEST_METHOD(TestDisplayItemFullDetails) {
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

namespace ScheduleTest {
	TEST_CLASS(TEST_SCHEDULE) {
public:

	TEST_METHOD(TestRetrieveSchedule) {
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

	TEST_METHOD(TestGetScheduleSize) {
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

	TEST_METHOD(TestResetDisplaySchedule) {
		Schedule lohPengKimSchedule;
		int scheduleSize;

		scheduleSize = lohPengKimSchedule.resetDisplaySchedule();
		Assert::AreEqual(0, scheduleSize);

		Item *item1;
		item1 = new Item;
		item1->setItemName(string("Pressure student into lunch with me"));
		item1->setLabel('P');
		item1->setPriority('M');
		item1->setStartTime(2015, 6, 21, 13, 00);

		Item *item2;
		item2 = new Item;
		item2->setItemName(string("Lure student to my house"));
		item2->setDescription(string("sleeping pills are in the 2nd drawer"));
		item2->setLabel('P');
		item2->setPriority('H');
		item2->setStartTime(2015, 6, 27, 19, 00);

		Item *item3;
		item3 = new Item;
		item3->setItemName(string("Raise student's grade to A"));
		item3->setLabel('P');
		item3->setPriority('L');
		item3->setEndTime(2015, 7, 24);

		Item *item4;
		item4 = new Item;
		item4->setItemName(string("Buy fake passport and air ticket to Siberia"));
		item4->setLabel('P');
		item4->setPriority('H');
		item4->setEndTime(2015, 8, 20);

		lohPengKimSchedule.addItem(item1);
		lohPengKimSchedule.addItem(item2);
		lohPengKimSchedule.addItem(item3);
		lohPengKimSchedule.addItem(item4);

		scheduleSize = lohPengKimSchedule.resetDisplaySchedule();
		Assert::AreEqual(4, scheduleSize);

		delete item1;
		delete item2;
		delete item3;
		delete item4;
		item1 = NULL;
		item2 = NULL;
		item3 = NULL;
		item4 = NULL;
	}

	TEST_METHOD(TestGetDisplayScheduleSize) {
		Schedule iseGirlsSchedule1;
		int scheduleSize;

		Item *item1;
		item1 = new Item;
		item1->setItemName(string("Lunch with Loh Peng Kim"));
		item1->setLabel('O');
		item1->setPriority('H');
		item1->setStartTime(2015, 6, 21, 13, 00);

		Item *item2;
		item2 = new Item;
		item2->setItemName(string("Dinner at Loh Peng Kim's house :S"));
		item2->setLabel('O');
		item2->setPriority('H');
		item2->setStartTime(2015, 6, 27, 19, 00);

		Item *item3;
		item3 = new Item;
		item3->setItemName(string("Appointment at abortion clinic"));
		item3->setLabel('P');
		item3->setPriority('H');
		item3->setStartTime(2015, 8, 15, 9, 00);
		item3->setEndTime(2015, 8, 15, 12, 00);

		iseGirlsSchedule1.addItem(item1);
		iseGirlsSchedule1.addItem(item2);
		iseGirlsSchedule1.addItem(item3);

		iseGirlsSchedule1.resetDisplaySchedule();
		scheduleSize = iseGirlsSchedule1.getSizeOfDisplaySchedule();
		Assert::AreEqual(3, scheduleSize);

		iseGirlsSchedule1.deleteItemGivenDisplayVectorIndex(1);
		iseGirlsSchedule1.resetDisplaySchedule();
		scheduleSize = iseGirlsSchedule1.getSizeOfDisplaySchedule();
		Assert::AreEqual(2, scheduleSize);

		delete item1;
		delete item2;
		delete item3;
		item1 = NULL;
		item2 = NULL;
		item3 = NULL;

	}

	TEST_METHOD(ScheduleTestClearDisplaySchedule) {
		Schedule scheduleToTestClearDisplaySchedule;
		vector<Item> displayScheduleCopy;

		Item* item1 = new Item(string("Item #1"));
		item1->setItemID(1);

		Item* item2 = new Item(string("Item #2"));
		item2->setItemID(2);

		Item* item3 = new Item(string("Item #3"));
		item3->setItemID(3);

		Item* item4 = new Item(string("Item #4"));
		item4->setItemID(4);

		scheduleToTestClearDisplaySchedule.addItem(item1);
		scheduleToTestClearDisplaySchedule.addItem(item2);
		scheduleToTestClearDisplaySchedule.addItem(item3);
		scheduleToTestClearDisplaySchedule.addItem(item4);

		scheduleToTestClearDisplaySchedule.resetDisplaySchedule();
		displayScheduleCopy = scheduleToTestClearDisplaySchedule.retrieveDisplaySchedule();
		Assert::AreEqual(4, int(displayScheduleCopy.size()));

		scheduleToTestClearDisplaySchedule.clearDisplaySchedule();
		displayScheduleCopy = scheduleToTestClearDisplaySchedule.retrieveDisplaySchedule();
		Assert::AreEqual(0, int(displayScheduleCopy.size()));
	
		delete item1;
		delete item2;
		delete item3;
		delete item4;

		item1 = NULL;
		item2 - NULL;
		item3 = NULL;
		item4 = NULL;
	}

	};

	TEST_CLASS(TEST_CONVERSION) {
public:
	TEST_METHOD(TestFindVectorIndexGivenItemID) {
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

	TEST_METHOD(TestFindItemIDGivenDisplayVectorIndex) {

	}
	};

	TEST_CLASS(TEST_ITEMS_IN_SCHEDULE) {
public:

	TEST_METHOD(TestAddItem) {
		Schedule projectLife;
		Item *item1 = new Item;
		DateTime dateTime1(2020, 3, 20, 12, 30);

		item1->setItemName("Joon Fai's Marriage");
		item1->setDescription("Wife: Gantian");
		item1->setEndTime(dateTime1);
		item1->setCompletion(false);
		item1->setItemID(12);
		item1->setPriority('H');
		item1->setLabel('P');

		Item *item2 = new Item;
		DateTime dateTime2(2015, 3, 8, 15, 39);

		item2->setItemName("Chon Beng's Date");
		item2->setDescription("Girlfriend: Multiple");
		item2->setEndTime(dateTime2);
		item2->setCompletion(true);
		item2->setItemID(57);
		item2->setPriority('M');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime3(2015, 4, 1, 14, 0);

		item3->setItemName("Andy's lunch");
		item3->setDescription("Lunch: Nasi Lemak");
		item3->setEndTime(dateTime3);
		item3->setCompletion(false);
		item3->setItemID(201);
		item3->setPriority('H');
		item3->setLabel('M');

		string tempItem1 = projectLife.addItem(item1);
		string tempItem2 = projectLife.addItem(item2);
		string tempItem3 = projectLife.addItem(item3);

		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1);
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2);
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem3);

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(TestDeleteItemGivenItemID) {
		Schedule projectLife;
		Item *item1 = new Item;
		DateTime dateTime1(2020, 3, 20, 12, 30);

		item1->setItemName("Joon Fai's Marriage");
		item1->setDescription("Wife: Gantian");
		item1->setEndTime(dateTime1);
		item1->setCompletion(false);
		item1->setItemID(12);
		item1->setPriority('H');
		item1->setLabel('P');

		Item *item2 = new Item;
		DateTime dateTime2(2015, 3, 8, 15, 39);

		item2->setItemName("Chon Beng's Date");
		item2->setDescription("Girlfriend: Multiple");
		item2->setEndTime(dateTime2);
		item2->setCompletion(true);
		item2->setItemID(57);
		item2->setPriority('M');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime3(2015, 4, 1, 14, 0);

		item3->setItemName("Andy's lunch");
		item3->setDescription("Lunch: Nasi Lemak");
		item3->setEndTime(dateTime3);
		item3->setCompletion(false);
		item3->setItemID(201);
		item3->setPriority('H');
		item3->setLabel('M');

		projectLife.addItem(item1);
		projectLife.addItem(item2);
		projectLife.addItem(item3);

		Item tempItem;

		string tempItem1 = projectLife.deleteItemGivenItemID(12);
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1);

		tempItem = projectLife.retrieveSchedule()[0];
		string tempItem2 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2);

		tempItem = projectLife.retrieveSchedule()[1];
		string tempItem3 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem3);

		projectLife.addItem(item1);

		tempItem3 = projectLife.deleteItemGivenItemID(201);
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem3);

		tempItem = projectLife.retrieveSchedule()[0];
		tempItem2 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2);

		tempItem = projectLife.retrieveSchedule()[1];
		tempItem1 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1);

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(TestRetrieveItemGivenItemID) {
		Schedule projectLife;
		Item *item1 = new Item;
		DateTime dateTime1(2020, 3, 20, 12, 30);

		item1->setItemName("Joon Fai's Marriage");
		item1->setDescription("Wife: Gantian");
		item1->setEndTime(dateTime1);
		item1->setCompletion(false);
		item1->setItemID(8888);
		item1->setPriority('H');
		item1->setLabel('P');

		Item *item2 = new Item;
		DateTime dateTime2(2015, 3, 8, 15, 39);

		item2->setItemName("Chon Beng's Date");
		item2->setDescription("Girlfriend: Multiple");
		item2->setEndTime(dateTime2);
		item2->setCompletion(true);
		item2->setItemID(6969);
		item2->setPriority('M');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime3(2015, 4, 1, 14, 0);

		item3->setItemName("Andy's lunch");
		item3->setDescription("Lunch: Nasi Lemak");
		item3->setEndTime(dateTime3);
		item3->setCompletion(false);
		item3->setItemID(10101);
		item3->setPriority('H');
		item3->setLabel('M');

		projectLife.addItem(item1);
		projectLife.addItem(item2);
		projectLife.addItem(item3);

		Item tempItem = projectLife.retrieveItemGivenItemID(8888);
		string tempItem1 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1);

		tempItem = projectLife.retrieveItemGivenItemID(6969);
		string tempItem2 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2);

		tempItem = projectLife.retrieveItemGivenItemID(10101);
		string tempItem3 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem3);

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(TestReplaceItemGivenItemID) {
		Schedule projectLife;
		Item *item1 = new Item;
		DateTime dateTime1(2020, 3, 20, 12, 30);

		item1->setItemName("Joon Fai's Marriage");
		item1->setDescription("Wife: Gantian");
		item1->setEndTime(dateTime1);
		item1->setCompletion(false);
		item1->setItemID(8888);
		item1->setPriority('H');
		item1->setLabel('P');

		Item *item2 = new Item;
		DateTime dateTime2(2015, 3, 8, 15, 39);

		item2->setItemName("Chon Beng's Date");
		item2->setDescription("Girlfriend: Multiple");
		item2->setEndTime(dateTime2);
		item2->setCompletion(true);
		item2->setItemID(6969);
		item2->setPriority('M');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime3(2015, 4, 1, 14, 0);

		item3->setItemName("Andy's lunch");
		item3->setDescription("Lunch: Nasi Lemak");
		item3->setEndTime(dateTime3);
		item3->setCompletion(false);
		item3->setItemID(10101);
		item3->setPriority('H');
		item3->setLabel('M');

		projectLife.addItem(item1);
		projectLife.addItem(item2);

		vector<Item> parallelUniverse = projectLife.retrieveSchedule();

		Item tempItem = projectLife.retrieveItemGivenItemID(8888);
		string tempItem1 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1);
		Assert::AreEqual(item1->displayItemFullDetails(), parallelUniverse[0].displayItemFullDetails());

		tempItem = projectLife.retrieveItemGivenItemID(6969);
		string tempItem2 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2);
		Assert::AreEqual(item2->displayItemFullDetails(), parallelUniverse[1].displayItemFullDetails());

		string tempItem3 = projectLife.replaceItemGivenItemID(item3, 8888);
		parallelUniverse = projectLife.retrieveSchedule();
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem3);
		Assert::AreEqual(item3->displayItemFullDetails(), parallelUniverse[0].displayItemFullDetails());

		tempItem1 = projectLife.replaceItemGivenItemID(item1, 6969);
		parallelUniverse = projectLife.retrieveSchedule();
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1);
		Assert::AreEqual(item1->displayItemFullDetails(), parallelUniverse[1].displayItemFullDetails());

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(TestRetrieveItemGivenDisplayVectorIndex) {
		Schedule projectLife;

		Item *item1 = new Item;
		DateTime dateTime1(2015, 3, 20, 12, 30);
		DateTime dateTime2(2015, 4, 20, 12, 30);

		item1->setItemName("CS Project");
		item1->setDescription("V0.1");
		item1->setStartTime(dateTime1);
		item1->setEndTime(dateTime2);
		item1->setCompletion(true);
		item1->setItemID(12);
		item1->setPriority('L');
		item1->setLabel('O');

		Item *item2 = new Item;
		DateTime dateTime3(2015, 4, 27, 12, 30);

		item2->setItemName("CS Project");
		item2->setDescription("V0.2");
		item2->setStartTime(dateTime1);
		item2->setEndTime(dateTime3);
		item2->setCompletion(false);
		item2->setItemID(21);
		item2->setPriority('H');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime4(2015, 4, 1, 14, 0);

		item3->setItemName("CS Project");
		item3->setDescription("V0.3");
		item3->setEndTime(dateTime4);
		item3->setCompletion(false);
		item3->setItemID(201);
		item3->setPriority('M');
		item3->setLabel('P');

		projectLife.addItem(item1);
		projectLife.addItem(item2);
		projectLife.addItem(item3);

		projectLife.resetDisplaySchedule();
		vector <Item> displaySchedule = projectLife.retrieveDisplaySchedule();

		Item tempItem1 = projectLife.retrieveItemGivenDisplayVectorIndex(1);
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem1.displayItemFullDetails());

		Item tempItem2 = projectLife.retrieveItemGivenDisplayVectorIndex(2);
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2.displayItemFullDetails());

		Item tempItem3 = projectLife.retrieveItemGivenDisplayVectorIndex(3);
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem3.displayItemFullDetails());

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(TestReplaceItemGivenDisplayVectorIndex) {
		Schedule projectLife;
		Item *item1 = new Item;
		DateTime dateTime1(2015, 3, 20, 12, 30);
		DateTime dateTime2(2015, 4, 20, 12, 30);

		item1->setItemName("CS Project");
		item1->setDescription("V0.1");
		item1->setStartTime(dateTime1);
		item1->setEndTime(dateTime2);
		item1->setCompletion(true);
		item1->setItemID(12);
		item1->setPriority('L');
		item1->setLabel('O');

		Item *item2 = new Item;
		DateTime dateTime3(2015, 4, 27, 12, 30);

		item2->setItemName("CS Project");
		item2->setDescription("V0.2");
		item2->setStartTime(dateTime1);
		item2->setEndTime(dateTime3);
		item2->setCompletion(false);
		item2->setItemID(21);
		item2->setPriority('H');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime4(2015, 4, 1, 14, 0);

		item3->setItemName("CS Project");
		item3->setDescription("V0.3");
		item3->setEndTime(dateTime4);
		item3->setCompletion(false);
		item3->setItemID(201);
		item3->setPriority('M');
		item3->setLabel('P');

		projectLife.addItem(item1);
		projectLife.addItem(item2);
		projectLife.addItem(item3);

		projectLife.resetDisplaySchedule();

		vector<Item> tempItemVector = projectLife.retrieveDisplaySchedule();

		unsigned int index = projectLife.findVectorIndexGivenItemID(item3->getItemID());

		Item tempItem = projectLife.retrieveItemGivenItemID(item3->getItemID());
		string tempItem1 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item3->displayItemFullDetails(), tempItem1);
		Assert::AreEqual(item3->displayItemFullDetails(), tempItemVector[2].displayItemFullDetails());

		unsigned int index2 = projectLife.findVectorIndexGivenItemID(item2->getItemID());
		tempItem = projectLife.retrieveItemGivenItemID(item2->getItemID());
		string tempItem2 = tempItem.displayItemFullDetails();
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem2);
		Assert::AreEqual(item2->displayItemFullDetails(), tempItemVector[1].displayItemFullDetails());

		string tempItem3 = projectLife.replaceItemGivenDisplayVectorIndex(item1, index);
		tempItemVector = projectLife.retrieveSchedule();
		Assert::AreEqual(item1->displayItemFullDetails(), tempItem3);
		Assert::AreEqual(item1->displayItemFullDetails(), tempItemVector[0].displayItemFullDetails());

		tempItem1 = projectLife.replaceItemGivenDisplayVectorIndex(item2, index2);
		tempItemVector = projectLife.retrieveSchedule();
		Assert::AreEqual(item2->displayItemFullDetails(), tempItem1);
		Assert::AreEqual(item2->displayItemFullDetails(), tempItemVector[0].displayItemFullDetails());

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(TestDeleteItemGivenDisplayVectorIndex) {
		Schedule projectLife;
		Item *item1 = new Item;
		DateTime dateTime1(2015, 3, 20, 12, 30);
		DateTime dateTime2(2015, 4, 20, 12, 30);

		item1->setItemName("CS Project");
		item1->setDescription("V0.1");
		item1->setStartTime(dateTime1);
		item1->setEndTime(dateTime2);
		item1->setCompletion(true);
		item1->setItemID(12);
		item1->setPriority('L');
		item1->setLabel('O');

		Item *item2 = new Item;
		DateTime dateTime3(2015, 4, 27, 12, 30);

		item2->setItemName("CS Project");
		item2->setDescription("V0.2");
		item2->setStartTime(dateTime1);
		item2->setEndTime(dateTime3);
		item2->setCompletion(false);
		item2->setItemID(21);
		item2->setPriority('H');
		item2->setLabel('O');

		Item *item3 = new Item;
		DateTime dateTime4(2015, 4, 1, 14, 0);

		item3->setItemName("CS Project");
		item3->setDescription("V0.3");
		item3->setEndTime(dateTime4);
		item3->setCompletion(false);
		item3->setItemID(201);
		item3->setPriority('M');
		item3->setLabel('P');

		projectLife.addItem(item1);
		projectLife.addItem(item2);
		projectLife.addItem(item3);

		projectLife.resetDisplaySchedule();

		string tempString = projectLife.deleteItemGivenDisplayVectorIndex(1);
		Assert::AreEqual(item1->displayItemFullDetails(), tempString);
		projectLife.addItem(item1);
		projectLife.resetDisplaySchedule();

		tempString = projectLife.deleteItemGivenDisplayVectorIndex(2);
		Assert::AreEqual(item3->displayItemFullDetails(), tempString);
		projectLife.addItem(item3);
		projectLife.resetDisplaySchedule();

		tempString = projectLife.deleteItemGivenDisplayVectorIndex(1);
		Assert::AreEqual(item2->displayItemFullDetails(), tempString);
		projectLife.addItem(item2);
		projectLife.resetDisplaySchedule();

		delete item1;
		delete item2;
		delete item3;
	}

	TEST_METHOD(ScheduleTestIsRelevantDateTime) {
		Schedule relevantDateTimeSchedule;
		bool isRelevantDateTimeAccordingToSchedule;

		Item *noDateTimeItem1 = new Item(string("This is no-DateTime Item #1"));
		noDateTimeItem1->setItemID(1);

		Item *itemWithStartTime1 = new Item(string("This is Item w/ Start Time #1"));
		itemWithStartTime1->setItemID(3);
		itemWithStartTime1->setStartTime(2005, 1, 25, 19, 0);

		Item *itemWithStartTime2 = new Item(string("This is Item w/ Start Time #2"));
		itemWithStartTime2->setItemID(4);
		itemWithStartTime2->setStartTime(2016, 1, 1);

		Item *itemWithEndTime1 = new Item(string("This is Item w/ End Time #1"));
		itemWithEndTime1->setItemID(6);
		itemWithEndTime1->setEndTime(2000, 11, 17, 8, 15);

		Item *itemWithEndTime2 = new Item(string("This is Item w/ End Time #2"));
		itemWithEndTime2->setItemID(7);
		itemWithEndTime2->setEndTime(2020, 1, 19, 20, 15);

		Item *itemWithEndTime3 = new Item(string("This is Item w/ End Time #3"));
		itemWithEndTime3->setItemID(8);
		itemWithEndTime3->setEndTime(2014, 11, 30);

		Item *itemWithEndTime4 = new Item(string("This is Item w/ End Time #4"));
		itemWithEndTime4->setItemID(9);
		itemWithEndTime4->setEndTime(2050, 5, 2, 18, 18);

		Item *itemWithStartAndEndTime1 = new Item(string("This is Item w/ Start & End Time #1 with Start and End in range"));
		itemWithStartAndEndTime1->setItemID(10);
		itemWithStartAndEndTime1->setStartTime(2017, 12, 18, 9, 0);
		itemWithStartAndEndTime1->setEndTime(2018, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime2 = new Item(string("This is Item w/ Start & End Time #2 with Start in range, End out of range"));
		itemWithStartAndEndTime2->setItemID(11);
		itemWithStartAndEndTime2->setStartTime(2007, 12, 8);
		itemWithStartAndEndTime2->setEndTime(2098, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime3 = new Item(string("This is Item w/ Start & End Time #3 with Start out of range, End in range"));
		itemWithStartAndEndTime3->setItemID(12);
		itemWithStartAndEndTime3->setStartTime(1990, 12, 18, 9, 0);
		itemWithStartAndEndTime3->setEndTime(2018, 11, 21);

		Item *itemWithStartAndEndTime4 = new Item(string("This is Item w/ Start & End Time #4 with Start and End OUT of range"));
		itemWithStartAndEndTime4->setItemID(13);
		itemWithStartAndEndTime4->setStartTime(3000, 12, 18, 9, 0);
		itemWithStartAndEndTime4->setEndTime(3012, 11, 21, 7, 0);

		DateTime dateTime1(2000, 1, 1, 0, 0);
		DateTime dateTime2(2016, 12, 30, 23, 59);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(noDateTimeItem1->getStartTime(), noDateTimeItem1->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(false, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithStartTime1->getStartTime(), itemWithStartTime1->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(true, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithStartTime2->getStartTime(), itemWithStartTime1->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(true, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithEndTime1->getStartTime(), itemWithEndTime1->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(true, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithEndTime2->getStartTime(), itemWithEndTime2->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(false, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithEndTime3->getStartTime(), itemWithEndTime3->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(true, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithStartAndEndTime1->getStartTime(), itemWithStartAndEndTime1->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(false, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithStartAndEndTime2->getStartTime(), itemWithStartAndEndTime2->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(true, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithStartAndEndTime3->getStartTime(), itemWithStartAndEndTime3->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(true, isRelevantDateTimeAccordingToSchedule);

		isRelevantDateTimeAccordingToSchedule = relevantDateTimeSchedule.isRelevantDateTime(itemWithStartAndEndTime4->getStartTime(), itemWithStartAndEndTime4->getEndTime(), dateTime1, dateTime2);
		Assert::AreEqual(false, isRelevantDateTimeAccordingToSchedule);

		delete noDateTimeItem1;
		delete itemWithEndTime1;
		delete itemWithEndTime2;
		delete itemWithEndTime3;
		delete itemWithEndTime4;
		delete itemWithStartTime1;
		delete itemWithStartTime2;
		delete itemWithStartAndEndTime1;
		delete itemWithStartAndEndTime2;
		delete itemWithStartAndEndTime3;
		delete itemWithStartAndEndTime4;

		noDateTimeItem1 = NULL;
		itemWithEndTime1 = NULL;
		itemWithEndTime2 = NULL;
		itemWithEndTime3 = NULL;
		itemWithEndTime4 = NULL;
		itemWithStartTime1 = NULL;
		itemWithStartTime2 = NULL;
		itemWithStartAndEndTime1 = NULL;
		itemWithStartAndEndTime2 = NULL;
		itemWithStartAndEndTime3 = NULL;
		itemWithStartAndEndTime4 = NULL;
	}

	};

	TEST_CLASS(TEST_FILTER) {
public:

	// Not done since label funcitonality is not implemented
	TEST_METHOD(ScheduleTestFilterDisplayScheduleByLabel) {
		// TODO: Your test code here
	}

	TEST_METHOD(ScheduleTestFilterDisplayScheduleByPriority) {
		Schedule prioritySchedule;
		bool isSamePriorityAsDefinedByUser;

		Item *highPriorityItem1 = new Item(string("This is High #1"));
		highPriorityItem1->setItemID(1);
		highPriorityItem1->setPriority('H');

		Item *highPriorityItem2 = new Item(string("This is High #2"));
		highPriorityItem2->setItemID(2);
		highPriorityItem2->setPriority('H');

		Item *highPriorityItem3 = new Item(string("This is High #3"));
		highPriorityItem3->setItemID(3);
		highPriorityItem3->setPriority('H');

		Item *highPriorityItem4 = new Item(string("This is High #4"));
		highPriorityItem4->setItemID(4);
		highPriorityItem4->setPriority('H');

		Item *medPriorityItem1 = new Item(string("This is Medium #1"));
		medPriorityItem1->setItemID(5);
		medPriorityItem1->setPriority('M');

		Item *medPriorityItem2 = new Item(string("This is Medium #2"));
		medPriorityItem2->setItemID(6);
		medPriorityItem2->setPriority('M');

		Item *lowPriorityItem1 = new Item(string("This is Low #1"));
		lowPriorityItem1->setItemID(7);
		lowPriorityItem1->setPriority('L');

		Item *lowPriorityItem2 = new Item(string("This is Low #2"));
		lowPriorityItem2->setItemID(8);
		lowPriorityItem2->setPriority('L');

		Item *lowPriorityItem3 = new Item(string("This is Low #3"));
		lowPriorityItem3->setItemID(9);
		lowPriorityItem3->setPriority('L');

		Item *lowPriorityItem4 = new Item(string("This is Low #4"));
		lowPriorityItem4->setItemID(10);
		lowPriorityItem4->setPriority('L');

		Item *lowPriorityItem5 = new Item(string("This is Low #5"));
		lowPriorityItem5->setItemID(11);
		lowPriorityItem5->setPriority('L');

		prioritySchedule.addItem(highPriorityItem1);
		prioritySchedule.addItem(highPriorityItem2);
		prioritySchedule.addItem(highPriorityItem3);
		prioritySchedule.addItem(highPriorityItem4);
		prioritySchedule.addItem(medPriorityItem1);
		prioritySchedule.addItem(medPriorityItem2);
		prioritySchedule.addItem(lowPriorityItem1);
		prioritySchedule.addItem(lowPriorityItem2);
		prioritySchedule.addItem(lowPriorityItem3);
		prioritySchedule.addItem(lowPriorityItem4);
		prioritySchedule.addItem(lowPriorityItem5);

		prioritySchedule.resetDisplaySchedule();
		Assert::AreEqual(11, int(prioritySchedule.getSizeOfDisplaySchedule()));

		isSamePriorityAsDefinedByUser = prioritySchedule.filterDisplayScheduleByPriority(1, 'H');
		Assert::AreEqual(false, isSamePriorityAsDefinedByUser);
		Assert::AreEqual(11, int(prioritySchedule.getSizeOfDisplaySchedule()));

		prioritySchedule.resetDisplaySchedule();
		isSamePriorityAsDefinedByUser = prioritySchedule.filterDisplayScheduleByPriority(5, 'H');
		Assert::AreEqual(true, isSamePriorityAsDefinedByUser);
		Assert::AreEqual(10, int(prioritySchedule.getSizeOfDisplaySchedule()));

		prioritySchedule.resetDisplaySchedule();
		Assert::AreEqual(11, int(prioritySchedule.getSizeOfDisplaySchedule()));
		isSamePriorityAsDefinedByUser = prioritySchedule.filterDisplayScheduleByPriority(4, 'M');
		Assert::AreEqual(false, isSamePriorityAsDefinedByUser);
		Assert::AreEqual(11, int(prioritySchedule.getSizeOfDisplaySchedule()));
		isSamePriorityAsDefinedByUser = prioritySchedule.filterDisplayScheduleByPriority(10, 'M');
		Assert::AreEqual(true, isSamePriorityAsDefinedByUser);
		Assert::AreEqual(10, int(prioritySchedule.getSizeOfDisplaySchedule()));

		delete highPriorityItem1;
		delete highPriorityItem2;
		delete highPriorityItem3;
		delete highPriorityItem4;
		delete medPriorityItem1;
		delete medPriorityItem2;
		delete lowPriorityItem1;
		delete lowPriorityItem2;
		delete lowPriorityItem3;
		delete lowPriorityItem4;
		delete lowPriorityItem5;

		highPriorityItem1 = NULL;
		highPriorityItem2 = NULL;
		highPriorityItem3 = NULL;
		highPriorityItem4 = NULL;
		medPriorityItem1 = NULL;
		medPriorityItem2 = NULL;
		lowPriorityItem1 = NULL;
		lowPriorityItem2 = NULL;
		lowPriorityItem3 = NULL;
		lowPriorityItem4 = NULL;
		lowPriorityItem5 = NULL;
	}

	TEST_METHOD(ScheduleTestFilterDisplayScheduleByCompletion) {
		Schedule completionTestSchedule;
		bool isSameCompletionAsSpecifiedByUser;

		Item *completedItem1 = new Item(string("This is Completed #1"));
		completedItem1->setItemID(1);
		completedItem1->setCompletion(true);

		Item *completedItem2 = new Item(string("This is Completed #2"));
		completedItem2->setItemID(2);
		completedItem2->setCompletion(true);

		Item *completedItem3 = new Item(string("This is Completed #3"));
		completedItem3->setItemID(3);
		completedItem3->setCompletion(true);

		Item *completedItem4 = new Item(string("This is Completed #4"));
		completedItem4->setItemID(4);
		completedItem4->setCompletion(true);

		Item *uncompletedItem1 = new Item(string("This is Uncompleted #1"));
		uncompletedItem1->setItemID(5);
		uncompletedItem1->setCompletion(false);

		Item *uncompletedItem2 = new Item(string("This is Uncompleted #2"));
		uncompletedItem2->setItemID(6);
		uncompletedItem2->setCompletion(false);

		completionTestSchedule.addItem(completedItem1);
		completionTestSchedule.addItem(completedItem2);
		completionTestSchedule.addItem(completedItem3);
		completionTestSchedule.addItem(completedItem4);
		completionTestSchedule.addItem(uncompletedItem1);
		completionTestSchedule.addItem(uncompletedItem2);

		completionTestSchedule.resetDisplaySchedule();
		Assert::AreEqual(6, int(completionTestSchedule.getSizeOfDisplaySchedule()));

		isSameCompletionAsSpecifiedByUser = completionTestSchedule.filterDisplayScheduleByCompletion(0, false);
		Assert::AreEqual(true, isSameCompletionAsSpecifiedByUser);
		Assert::AreEqual(5, int(completionTestSchedule.getSizeOfDisplaySchedule()));

		completionTestSchedule.resetDisplaySchedule();
		Assert::AreEqual(6, int(completionTestSchedule.getSizeOfDisplaySchedule()));

		isSameCompletionAsSpecifiedByUser = completionTestSchedule.filterDisplayScheduleByCompletion(5, false);
		Assert::AreEqual(false, isSameCompletionAsSpecifiedByUser);
		Assert::AreEqual(6, int(completionTestSchedule.getSizeOfDisplaySchedule()));
		isSameCompletionAsSpecifiedByUser = completionTestSchedule.filterDisplayScheduleByCompletion(3, true);
		Assert::AreEqual(false, isSameCompletionAsSpecifiedByUser);
		Assert::AreEqual(6, int(completionTestSchedule.getSizeOfDisplaySchedule()));
		isSameCompletionAsSpecifiedByUser = completionTestSchedule.filterDisplayScheduleByCompletion(2, false);
		Assert::AreEqual(true, isSameCompletionAsSpecifiedByUser);
		Assert::AreEqual(5, int(completionTestSchedule.getSizeOfDisplaySchedule()));

		delete completedItem1;
		delete completedItem2;
		delete completedItem3;
		delete completedItem4;
		delete uncompletedItem1;
		delete uncompletedItem2;

		completedItem1 = NULL;
		completedItem2 = NULL;
		completedItem3 = NULL;
		completedItem4 = NULL;
		uncompletedItem1 = NULL;
		uncompletedItem2 = NULL;
	}

	TEST_METHOD(ScheduleTestFilterDisplayScheduleByDateTime) {
		Schedule dateTimeSchedule;
		bool isRelevantDateTime;

		Item *noDateTimeItem1 = new Item(string("This is no-DateTime Item #1"));
		noDateTimeItem1->setItemID(1);

		Item *noDateTimeItem2 = new Item(string("This is no-DateTime Item #2"));
		noDateTimeItem2->setItemID(2);

		Item *itemWithStartTime1 = new Item(string("This is Item w/ Start Time #1"));
		itemWithStartTime1->setItemID(3);
		itemWithStartTime1->setStartTime(2009, 1, 25, 19, 0);

		Item *itemWithStartTime2 = new Item(string("This is Item w/ Start Time #2"));
		itemWithStartTime2->setItemID(4);
		itemWithStartTime2->setStartTime(2015, 11, 2, 7, 0);

		Item *itemWithStartTime3 = new Item(string("This is Item w/ Start Time #3"));
		itemWithStartTime3->setItemID(5);
		itemWithStartTime3->setStartTime(2014, 4, 17);

		Item *itemWithEndTime1 = new Item(string("This is Item w/ End Time #1"));
		itemWithEndTime1->setItemID(6);
		itemWithEndTime1->setEndTime(2008, 11, 17, 8, 15);

		Item *itemWithEndTime2 = new Item(string("This is Item w/ End Time #2"));
		itemWithEndTime2->setItemID(7);
		itemWithEndTime2->setEndTime(2099, 1, 19, 20, 15);

		Item *itemWithEndTime3 = new Item(string("This is Item w/ End Time #3"));
		itemWithEndTime3->setItemID(8);
		itemWithEndTime3->setEndTime(2008, 11, 30);

		Item *itemWithEndTime4 = new Item(string("This is Item w/ End Time #4"));
		itemWithEndTime4->setItemID(9);
		itemWithEndTime4->setEndTime(2014, 5, 2, 18, 18);

		Item *itemWithStartAndEndTime1 = new Item(string("This is Item w/ Start & End Time #1 with Start and End in range"));
		itemWithStartAndEndTime1->setItemID(10);
		itemWithStartAndEndTime1->setStartTime(2017, 12, 18, 9, 0);
		itemWithStartAndEndTime1->setEndTime(2018, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime2 = new Item(string("This is Item w/ Start & End Time #2 with Start in range, End out of range"));
		itemWithStartAndEndTime2->setItemID(11);
		itemWithStartAndEndTime2->setStartTime(2017, 12, 18, 9, 0);
		itemWithStartAndEndTime2->setEndTime(2098, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime3 = new Item(string("This is Item w/ Start & End Time #3 with Start out of range, End in range"));
		itemWithStartAndEndTime3->setItemID(12);
		itemWithStartAndEndTime3->setStartTime(1990, 12, 18, 9, 0);
		itemWithStartAndEndTime3->setEndTime(2018, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime4 = new Item(string("This is Item w/ Start & End Time #4 with Start and End OUT of range"));
		itemWithStartAndEndTime4->setItemID(13);
		itemWithStartAndEndTime4->setStartTime(3000, 12, 18, 9, 0);
		itemWithStartAndEndTime4->setEndTime(3012, 11, 21, 7, 0);

		dateTimeSchedule.addItem(noDateTimeItem1);
		dateTimeSchedule.addItem(noDateTimeItem2);
		dateTimeSchedule.addItem(itemWithStartTime1);
		dateTimeSchedule.addItem(itemWithStartTime2);
		dateTimeSchedule.addItem(itemWithStartTime3);
		dateTimeSchedule.addItem(itemWithEndTime1);
		dateTimeSchedule.addItem(itemWithEndTime2);
		dateTimeSchedule.addItem(itemWithEndTime3);
		dateTimeSchedule.addItem(itemWithEndTime4);
		dateTimeSchedule.addItem(itemWithStartAndEndTime1);
		dateTimeSchedule.addItem(itemWithStartAndEndTime2);
		dateTimeSchedule.addItem(itemWithStartAndEndTime3);
		dateTimeSchedule.addItem(itemWithStartAndEndTime4);

		dateTimeSchedule.resetDisplaySchedule();
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));
		isRelevantDateTime = dateTimeSchedule.filterDisplayScheduleByDateTime(0, DateTime(2000, 1, 1, 0, 0), DateTime(2020, 12, 30, 23, 59));
		Assert::AreEqual(true, isRelevantDateTime);
		Assert::AreEqual(12, int(dateTimeSchedule.getSizeOfDisplaySchedule()));

		dateTimeSchedule.resetDisplaySchedule();
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));
		isRelevantDateTime = dateTimeSchedule.filterDisplayScheduleByDateTime(2, DateTime(2000, 1, 1, 0, 0), DateTime(2020, 12, 30, 23, 59));
		Assert::AreEqual(false, isRelevantDateTime);
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));

		dateTimeSchedule.resetDisplaySchedule();
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));
		isRelevantDateTime = dateTimeSchedule.filterDisplayScheduleByDateTime(6, DateTime(2000, 1, 1, 0, 0), DateTime(2020, 12, 30, 23, 59));
		Assert::AreEqual(true, isRelevantDateTime);
		Assert::AreEqual(12, int(dateTimeSchedule.getSizeOfDisplaySchedule()));

		dateTimeSchedule.resetDisplaySchedule();
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));
		isRelevantDateTime = dateTimeSchedule.filterDisplayScheduleByDateTime(9, DateTime(2000, 1, 1, 0, 0), DateTime(2020, 12, 30, 23, 59));
		Assert::AreEqual(false, isRelevantDateTime);
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));
		isRelevantDateTime = dateTimeSchedule.filterDisplayScheduleByDateTime(10, DateTime(2000, 1, 1, 0, 0), DateTime(2020, 12, 30, 23, 59));
		Assert::AreEqual(false, isRelevantDateTime);
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));
		isRelevantDateTime = dateTimeSchedule.filterDisplayScheduleByDateTime(12, DateTime(2000, 1, 1, 0, 0), DateTime(2020, 12, 30, 23, 59));
		Assert::AreEqual(true, isRelevantDateTime);
		Assert::AreEqual(12, int(dateTimeSchedule.getSizeOfDisplaySchedule()));

		delete noDateTimeItem1;
		delete noDateTimeItem2;
		delete itemWithEndTime1;
		delete itemWithEndTime2;
		delete itemWithEndTime3;
		delete itemWithEndTime4;
		delete itemWithStartTime1;
		delete itemWithStartTime2;
		delete itemWithStartTime3;
		delete itemWithStartAndEndTime1;
		delete itemWithStartAndEndTime2;
		delete itemWithStartAndEndTime3;
		delete itemWithStartAndEndTime4;

		noDateTimeItem1 = NULL;
		noDateTimeItem2 = NULL;
		itemWithEndTime1 = NULL;
		itemWithEndTime2 = NULL;
		itemWithEndTime3 = NULL;
		itemWithEndTime4 = NULL;
		itemWithStartTime1 = NULL;
		itemWithStartTime2 = NULL;
		itemWithStartTime3 = NULL;
		itemWithStartAndEndTime1 = NULL;
		itemWithStartAndEndTime2 = NULL;
		itemWithStartAndEndTime3 = NULL;
		itemWithStartAndEndTime4 = NULL;
	}

	TEST_METHOD(ScheduleTestFilterDisplayScheduleByKeyword) {
		Schedule keywordSchedule;
		bool hasKeyword;

		Item *withKeyword1 = new Item(string("Has keyword wahlau eh"));
		withKeyword1->setItemID(1);

		Item *withKeyword2 = new Item(string("Has keyword in description"));
		withKeyword2->setItemID(2);
		withKeyword2->setDescription(string("the keyword wahLau eH is here"));

		Item* withoutKeyword1 = new Item(string("No keyword in here wah eh"));
		withoutKeyword1->setItemID(3);

		Item* withoutKeyword2 = new Item(string("No sign of keyword here either"));
		withoutKeyword2->setItemID(4);
		withoutKeyword2->setDescription(string("wahskdjlaw eh"));

		keywordSchedule.addItem(withKeyword1);
		keywordSchedule.addItem(withKeyword2);
		keywordSchedule.addItem(withoutKeyword1);
		keywordSchedule.addItem(withoutKeyword2);

		keywordSchedule.resetDisplaySchedule();
		Assert::AreEqual(4, int(keywordSchedule.getSizeOfDisplaySchedule()));
		hasKeyword = keywordSchedule.filterDisplayScheduleByKeyword(0, string("wahlau eh"));
		Assert::AreEqual(4, int(keywordSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(false, hasKeyword);
		hasKeyword = keywordSchedule.filterDisplayScheduleByKeyword(1, string("wahlau eh"));
		Assert::AreEqual(4, int(keywordSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(false, hasKeyword);
		hasKeyword = keywordSchedule.filterDisplayScheduleByKeyword(2, string("wahlau eh"));
		Assert::AreEqual(3, int(keywordSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(true, hasKeyword);
		hasKeyword = keywordSchedule.filterDisplayScheduleByKeyword(2, string("wahlau eh"));
		Assert::AreEqual(2, int(keywordSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(true, hasKeyword);

		delete withKeyword1;
		delete withKeyword2;
		delete withoutKeyword1;
		delete withoutKeyword2;

		withKeyword1 = NULL;
		withKeyword2 = NULL;
		withoutKeyword1 = NULL;
		withoutKeyword2 = NULL;
	}

	// Not done since label funcitonality is not implemented
	TEST_METHOD(ScheduleTestRetrieveDisplayScheduleFilteredByLabel) {
		//
	}

	TEST_METHOD(ScheduleTestRetrieveDisplayScheduleFilteredByPriority) {
		Schedule prioritySchedule;
		vector<Item> filteredVectorByPriority;

		Item *highPriorityItem1 = new Item(string("This is High #1"));
		highPriorityItem1->setItemID(1);
		highPriorityItem1->setPriority('H');

		Item *highPriorityItem2 = new Item(string("This is High #2"));
		highPriorityItem2->setItemID(2);
		highPriorityItem2->setPriority('H');

		Item *highPriorityItem3 = new Item(string("This is High #3"));
		highPriorityItem3->setItemID(3);
		highPriorityItem3->setPriority('H');

		Item *highPriorityItem4 = new Item(string("This is High #4"));
		highPriorityItem4->setItemID(4);
		highPriorityItem4->setPriority('H');

		Item *medPriorityItem1 = new Item(string("This is Medium #1"));
		medPriorityItem1->setItemID(5);
		medPriorityItem1->setPriority('M');

		Item *medPriorityItem2 = new Item(string("This is Medium #2"));
		medPriorityItem2->setItemID(6);
		medPriorityItem2->setPriority('M');

		Item *lowPriorityItem1 = new Item(string("This is Low #1"));
		lowPriorityItem1->setItemID(7);
		lowPriorityItem1->setPriority('L');

		Item *lowPriorityItem2 = new Item(string("This is Low #2"));
		lowPriorityItem2->setItemID(8);
		lowPriorityItem2->setPriority('L');

		Item *lowPriorityItem3 = new Item(string("This is Low #3"));
		lowPriorityItem3->setItemID(9);
		lowPriorityItem3->setPriority('L');

		Item *lowPriorityItem4 = new Item(string("This is Low #4"));
		lowPriorityItem4->setItemID(10);
		lowPriorityItem4->setPriority('L');

		Item *lowPriorityItem5 = new Item(string("This is Low #5"));
		lowPriorityItem5->setItemID(11);
		lowPriorityItem5->setPriority('L');

		prioritySchedule.addItem(highPriorityItem1);
		prioritySchedule.addItem(highPriorityItem2);
		prioritySchedule.addItem(highPriorityItem3);
		prioritySchedule.addItem(highPriorityItem4);
		prioritySchedule.addItem(medPriorityItem1);
		prioritySchedule.addItem(medPriorityItem2);
		prioritySchedule.addItem(lowPriorityItem1);
		prioritySchedule.addItem(lowPriorityItem2);
		prioritySchedule.addItem(lowPriorityItem3);
		prioritySchedule.addItem(lowPriorityItem4);
		prioritySchedule.addItem(lowPriorityItem5);

		prioritySchedule.resetDisplaySchedule();
		filteredVectorByPriority = prioritySchedule.retrieveDisplayScheduleFilteredByPriority('H');
		Assert::AreEqual(4, int(filteredVectorByPriority.size()));

		prioritySchedule.resetDisplaySchedule();
		filteredVectorByPriority = prioritySchedule.retrieveDisplayScheduleFilteredByPriority('L');
		Assert::AreEqual(5, int(filteredVectorByPriority.size()));

		prioritySchedule.resetDisplaySchedule();
		filteredVectorByPriority = prioritySchedule.retrieveDisplayScheduleFilteredByPriority('M');
		Assert::AreEqual(2, int(filteredVectorByPriority.size()));

		delete highPriorityItem1;
		delete highPriorityItem2;
		delete highPriorityItem3;
		delete highPriorityItem4;
		delete medPriorityItem1;
		delete medPriorityItem2;
		delete lowPriorityItem1;
		delete lowPriorityItem2;
		delete lowPriorityItem3;
		delete lowPriorityItem4;
		delete lowPriorityItem5;

		highPriorityItem1 = NULL;
		highPriorityItem2 = NULL;
		highPriorityItem3 = NULL;
		highPriorityItem4 = NULL;
		medPriorityItem1 = NULL;
		medPriorityItem2 = NULL;
		lowPriorityItem1 = NULL;
		lowPriorityItem2 = NULL;
		lowPriorityItem3 = NULL;
		lowPriorityItem4 = NULL;
		lowPriorityItem5 = NULL;
	}

	TEST_METHOD(ScheduleTestRetrieveDisplayScheduleFilteredByCompletion) {
		Schedule completionTestSchedule;
		vector<Item> filteredVectorByCompletion;

		Item *completedItem1 = new Item(string("This is Completed #1"));
		completedItem1->setItemID(1);
		completedItem1->setCompletion(true);

		Item *completedItem2 = new Item(string("This is Completed #2"));
		completedItem2->setItemID(2);
		completedItem2->setCompletion(true);

		Item *completedItem3 = new Item(string("This is Completed #3"));
		completedItem3->setItemID(3);
		completedItem3->setCompletion(true);

		Item *completedItem4 = new Item(string("This is Completed #4"));
		completedItem4->setItemID(4);
		completedItem4->setCompletion(true);

		Item *uncompletedItem1 = new Item(string("This is Uncompleted #1"));
		uncompletedItem1->setItemID(5);
		uncompletedItem1->setCompletion(false);

		Item *uncompletedItem2 = new Item(string("This is Uncompleted #2"));
		uncompletedItem2->setItemID(6);
		uncompletedItem2->setCompletion(false);

		completionTestSchedule.addItem(completedItem1);
		completionTestSchedule.addItem(completedItem2);
		completionTestSchedule.addItem(completedItem3);
		completionTestSchedule.addItem(completedItem4);
		completionTestSchedule.addItem(uncompletedItem1);
		completionTestSchedule.addItem(uncompletedItem2);

		filteredVectorByCompletion = completionTestSchedule.retrieveDisplayScheduleFilteredByCompletion(true);
		Assert::AreEqual(0, int(filteredVectorByCompletion.size()));

		completionTestSchedule.resetDisplaySchedule();
		Assert::AreEqual(6, int(completionTestSchedule.getSizeOfDisplaySchedule()));

		filteredVectorByCompletion = completionTestSchedule.retrieveDisplayScheduleFilteredByCompletion(true);
		Assert::AreEqual(4, int(filteredVectorByCompletion.size()));

		completionTestSchedule.resetDisplaySchedule();
		filteredVectorByCompletion = completionTestSchedule.retrieveDisplayScheduleFilteredByCompletion(false);
		Assert::AreEqual(2, int(filteredVectorByCompletion.size()));

		delete completedItem1;
		delete completedItem2;
		delete completedItem3;
		delete completedItem4;
		delete uncompletedItem1;
		delete uncompletedItem2;

		completedItem1 = NULL;
		completedItem2 = NULL;
		completedItem3 = NULL;
		completedItem4 = NULL;
		uncompletedItem1 = NULL;
		uncompletedItem2 = NULL;
	}

	TEST_METHOD(ScheduleTestRetrieveDisplayScheduleFilteredByDateTime) {
		Schedule dateTimeSchedule;
		vector<Item> filteredVectorByDateTime;

		Item *noDateTimeItem1 = new Item(string("This is no-DateTime Item #1"));
		noDateTimeItem1->setItemID(1);

		Item *noDateTimeItem2 = new Item(string("This is no-DateTime Item #2"));
		noDateTimeItem2->setItemID(2);

		Item *itemWithStartTime1 = new Item(string("This is Item w/ Start Time #1"));
		itemWithStartTime1->setItemID(3);
		itemWithStartTime1->setStartTime(2005, 1, 25, 19, 0);

		Item *itemWithStartTime2 = new Item(string("This is Item w/ Start Time #2"));
		itemWithStartTime2->setItemID(4);
		itemWithStartTime2->setStartTime(2010, 11, 2, 7, 0);

		Item *itemWithStartTime3 = new Item(string("This is Item w/ Start Time #3"));
		itemWithStartTime3->setItemID(5);
		itemWithStartTime3->setStartTime(2015, 4, 17);

		Item *itemWithEndTime1 = new Item(string("This is Item w/ End Time #1"));
		itemWithEndTime1->setItemID(6);
		itemWithEndTime1->setEndTime(2000, 11, 17, 8, 15);

		Item *itemWithEndTime2 = new Item(string("This is Item w/ End Time #2"));
		itemWithEndTime2->setItemID(7);
		itemWithEndTime2->setEndTime(2020, 1, 19, 20, 15);

		Item *itemWithEndTime3 = new Item(string("This is Item w/ End Time #3"));
		itemWithEndTime3->setItemID(8);
		itemWithEndTime3->setEndTime(2025, 11, 30);

		Item *itemWithEndTime4 = new Item(string("This is Item w/ End Time #4"));
		itemWithEndTime4->setItemID(9);
		itemWithEndTime4->setEndTime(2050, 5, 2, 18, 18);

		Item *itemWithStartAndEndTime1 = new Item(string("This is Item w/ Start & End Time #1 with Start and End in range"));
		itemWithStartAndEndTime1->setItemID(10);
		itemWithStartAndEndTime1->setStartTime(2017, 12, 18, 9, 0);
		itemWithStartAndEndTime1->setEndTime(2018, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime2 = new Item(string("This is Item w/ Start & End Time #2 with Start in range, End out of range"));
		itemWithStartAndEndTime2->setItemID(11);
		itemWithStartAndEndTime2->setStartTime(2017, 12, 18, 9, 0);
		itemWithStartAndEndTime2->setEndTime(2098, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime3 = new Item(string("This is Item w/ Start & End Time #3 with Start out of range, End in range"));
		itemWithStartAndEndTime3->setItemID(12);
		itemWithStartAndEndTime3->setStartTime(1990, 12, 18, 9, 0);
		itemWithStartAndEndTime3->setEndTime(2018, 11, 21, 7, 0);

		Item *itemWithStartAndEndTime4 = new Item(string("This is Item w/ Start & End Time #4 with Start and End OUT of range"));
		itemWithStartAndEndTime4->setItemID(13);
		itemWithStartAndEndTime4->setStartTime(3000, 12, 18, 9, 0);
		itemWithStartAndEndTime4->setEndTime(3012, 11, 21, 7, 0);

		dateTimeSchedule.addItem(noDateTimeItem1);
		dateTimeSchedule.addItem(noDateTimeItem2);
		dateTimeSchedule.addItem(itemWithStartTime1);
		dateTimeSchedule.addItem(itemWithStartTime2);
		dateTimeSchedule.addItem(itemWithStartTime3);
		dateTimeSchedule.addItem(itemWithEndTime1);
		dateTimeSchedule.addItem(itemWithEndTime2);
		dateTimeSchedule.addItem(itemWithEndTime3);
		dateTimeSchedule.addItem(itemWithEndTime4);
		dateTimeSchedule.addItem(itemWithStartAndEndTime1);
		dateTimeSchedule.addItem(itemWithStartAndEndTime2);
		dateTimeSchedule.addItem(itemWithStartAndEndTime3);
		dateTimeSchedule.addItem(itemWithStartAndEndTime4);

		dateTimeSchedule.resetDisplaySchedule();
		Assert::AreEqual(13, int(dateTimeSchedule.getSizeOfDisplaySchedule()));

		filteredVectorByDateTime = dateTimeSchedule.retrieveDisplayScheduleFilteredByDateTime(DateTime(2000, 1, 1, 0, 0), DateTime(2010, 12, 30, 23, 59));
		Assert::AreEqual(4, int(filteredVectorByDateTime.size()));
		Assert::AreEqual(3, int(filteredVectorByDateTime[0].getItemID()));
		Assert::AreEqual(4, int(filteredVectorByDateTime[1].getItemID()));
		Assert::AreEqual(6, int(filteredVectorByDateTime[2].getItemID()));
		Assert::AreEqual(12, int(filteredVectorByDateTime[3].getItemID()));

		// Boundary Case: itemWithStartTime3 starts on 2015/4/17 -1:-1, is not within range
		dateTimeSchedule.resetDisplaySchedule();
		filteredVectorByDateTime = dateTimeSchedule.retrieveDisplayScheduleFilteredByDateTime(DateTime(2015, 4, 17, 0, 0), DateTime(2017, 12, 18, 9, 0));
		Assert::AreEqual(3, int(filteredVectorByDateTime.size()));
		Assert::AreEqual(10, int(filteredVectorByDateTime[0].getItemID()));
		Assert::AreEqual(11, int(filteredVectorByDateTime[1].getItemID()));
		Assert::AreEqual(12, int(filteredVectorByDateTime[2].getItemID()));

		dateTimeSchedule.resetDisplaySchedule();
		filteredVectorByDateTime = dateTimeSchedule.retrieveDisplayScheduleFilteredByDateTime(DateTime(2050, 5, 2, 18, 18), DateTime(3013, 12, 30, 23, 59));
		Assert::AreEqual(3, int(filteredVectorByDateTime.size()));
		Assert::AreEqual(9, int(filteredVectorByDateTime[0].getItemID()));
		Assert::AreEqual(11, int(filteredVectorByDateTime[1].getItemID()));
		Assert::AreEqual(13, int(filteredVectorByDateTime[2].getItemID()));

		delete noDateTimeItem1;
		delete noDateTimeItem2;
		delete itemWithEndTime1;
		delete itemWithEndTime2;
		delete itemWithEndTime3;
		delete itemWithEndTime4;
		delete itemWithStartTime1;
		delete itemWithStartTime2;
		delete itemWithStartTime3;
		delete itemWithStartAndEndTime1;
		delete itemWithStartAndEndTime2;
		delete itemWithStartAndEndTime3;
		delete itemWithStartAndEndTime4;

		noDateTimeItem1 = NULL;
		noDateTimeItem2 = NULL;
		itemWithEndTime1 = NULL;
		itemWithEndTime2 = NULL;
		itemWithEndTime3 = NULL;
		itemWithEndTime4 = NULL;
		itemWithStartTime1 = NULL;
		itemWithStartTime2 = NULL;
		itemWithStartTime3 = NULL;
		itemWithStartAndEndTime1 = NULL;
		itemWithStartAndEndTime2 = NULL;
		itemWithStartAndEndTime3 = NULL;
		itemWithStartAndEndTime4 = NULL;
	}

	TEST_METHOD(ScheduleTestRetrieveDisplayScheduleFilteredByKeyword) {
		Schedule keywordSchedule;
		vector<Item> filteredVectorByKeyword;

		Item *withKeyword1 = new Item(string("Has keyword wahlau eh"));
		withKeyword1->setItemID(1);

		Item *withKeyword2 = new Item(string("Has keyword in description"));
		withKeyword2->setItemID(2);
		withKeyword2->setDescription(string("the keyword wahLau eH is here"));

		Item *withKeyword3 = new Item(string("Has keyword in description"));
		withKeyword3->setItemID(3);
		withKeyword3->setDescription(string("HAHAHAHAHEHEHEWWWWAHLAU EHHHHHHHHH"));

		Item* withoutKeyword1 = new Item(string("No keyword in here wah eh"));
		withoutKeyword1->setItemID(4);

		Item* withoutKeyword2 = new Item(string("No sign of keyword here either"));
		withoutKeyword2->setItemID(5);
		withoutKeyword2->setDescription(string("whaskdjlaw eh"));

		keywordSchedule.addItem(withKeyword1);
		keywordSchedule.addItem(withKeyword2);
		keywordSchedule.addItem(withKeyword3);
		keywordSchedule.addItem(withoutKeyword1);
		keywordSchedule.addItem(withoutKeyword2);

		keywordSchedule.resetDisplaySchedule();
		Assert::AreEqual(5, int(keywordSchedule.getSizeOfDisplaySchedule()));

		filteredVectorByKeyword = keywordSchedule.retrieveDisplayScheduleFilteredByKeyword(string("wahlau eh"));
		Assert::AreEqual(3, int(filteredVectorByKeyword.size()));
		Assert::AreEqual(1, int(filteredVectorByKeyword[0].getItemID()));
		Assert::AreEqual(2, int(filteredVectorByKeyword[1].getItemID()));
		Assert::AreEqual(3, int(filteredVectorByKeyword[2].getItemID()));

		keywordSchedule.resetDisplaySchedule();
		filteredVectorByKeyword = keywordSchedule.retrieveDisplayScheduleFilteredByKeyword(string("Ha"));
		Assert::AreEqual(4, int(filteredVectorByKeyword.size()));
		Assert::AreEqual(1, int(filteredVectorByKeyword[0].getItemID()));
		Assert::AreEqual(2, int(filteredVectorByKeyword[1].getItemID()));
		Assert::AreEqual(3, int(filteredVectorByKeyword[2].getItemID()));
		Assert::AreEqual(5, int(filteredVectorByKeyword[3].getItemID()));

		delete withKeyword1;
		delete withKeyword2;
		delete withKeyword3;
		delete withoutKeyword1;
		delete withoutKeyword2;

		withKeyword1 = NULL;
		withKeyword2 = NULL;
		withKeyword3 = NULL;
		withoutKeyword1 = NULL;
		withoutKeyword2 = NULL;
	}

	};

	TEST_CLASS(TEST_SORT) {
public:
	TEST_METHOD(TestSortByPriority) {
		Schedule wonderDiet;
		vector<Item> displaySchedule;

		Item *day1 = new Item(string("Eat nothing but bananas"));
		day1->setItemID(1);
		day1->setDescription(string("This is not going to end well"));
		day1->setLabel('M');
		day1->setPriority('H');
		day1->setStartTime(2015, 4, 2);

		Item *day2 = new Item(string("Eat nothing but jackfruit"));
		day2->setItemID(2);
		day2->setDescription(string("I don't feel too good now..."));
		day2->setLabel('M');
		day2->setPriority('L');
		day2->setStartTime(2015, 4, 3);

		Item *day3 = new Item(string("Buy more toilet paper!"));
		day3->setItemID(3);
		day3->setDescription(string("I can't even sit properly"));
		day3->setLabel('O');
		day3->setPriority('H');
		day3->setStartTime(2015, 4, 4);

		Item *day4 = new Item(string("Take MC, eat hemorrhoid medication"));
		day4->setItemID(4);
		day4->setLabel('P');
		day4->setPriority('M');
		day4->setStartTime(2015, 4, 6);

		Item *day5 = new Item(string("Colon cleansing appointment"));
		day5->setItemID(5);
		day5->setDescription(string("What did I do to myself"));
		day5->setLabel('O');
		day5->setPriority('L');
		day5->setStartTime(2015, 4, 7);

		Item *day6 = new Item(string("BBQ Buffet"));
		day6->setItemID(6);
		day6->setDescription(string("Meat is love, meat is life"));
		day6->setLabel('O');
		day6->setPriority('H');
		day6->setStartTime(2015, 4, 8);

		wonderDiet.addItem(day1);
		wonderDiet.addItem(day2);
		wonderDiet.addItem(day3);
		wonderDiet.addItem(day4);
		wonderDiet.addItem(day5);
		wonderDiet.addItem(day6);

		wonderDiet.resetDisplaySchedule();
		wonderDiet.retrieveDisplayScheduleByDate();
		displaySchedule = wonderDiet.retrieveDisplayScheduleByPriority();

		Assert::AreEqual(6, int(displaySchedule.size()));
		Assert::AreEqual(1, int(displaySchedule[0].getItemID()));
		Assert::AreEqual(3, int(displaySchedule[1].getItemID()));
		Assert::AreEqual(6, int(displaySchedule[2].getItemID()));
		Assert::AreEqual(4, int(displaySchedule[3].getItemID()));
		Assert::AreEqual(2, int(displaySchedule[4].getItemID()));
		Assert::AreEqual(5, int(displaySchedule[5].getItemID()));


		delete day1;
		delete day2;
		delete day3;
		delete day4;
		delete day5;
		delete day6;

		day1 = NULL;
		day2 = NULL;
		day3 = NULL;
		day4 = NULL;
		day5 = NULL;
		day6 = NULL;

	}

	TEST_METHOD(TestSortByCompletion) {
		Schedule mosquitoSchedule;
		vector<Item> displaySchedule;

		Item *day1 = new Item(string("I'm just a larvae"));
		day1->setItemID(1);
		day1->setDescription(string("squirm squirm"));
		day1->setLabel('M');
		day1->setCompletion(false);
		day1->setStartTime(2015, 4, 2);

		Item *day2 = new Item(string("I'm a pupae"));
		day2->setItemID(2);
		day2->setDescription(string("wriggle wriggle"));
		day2->setLabel('M');
		day2->setCompletion(false);
		day2->setStartTime(2015, 4, 3);

		Item *day3 = new Item(string("I'm an adult mosquito now, beeeches"));
		day3->setItemID(3);
		day3->setDescription(string("bzz bzzzz"));
		day3->setLabel('O');
		day3->setCompletion(true);
		day3->setStartTime(2015, 4, 4);

		Item *day4 = new Item(string("Suck some blood"));
		day4->setItemID(4);
		day4->setLabel('P');
		day4->setCompletion(false);
		day4->setStartTime(2015, 4, 6);

		Item *day5 = new Item(string("Suck some more blood"));
		day5->setItemID(5);
		day5->setDescription(string("blood is delish"));
		day5->setLabel('O');
		day5->setCompletion(false);
		day5->setStartTime(2015, 4, 7);

		Item *day6 = new Item(string("Procreate"));
		day6->setItemID(6);
		day6->setDescription(string("Must have babies"));
		day6->setLabel('O');
		day6->setCompletion(true);
		day6->setStartTime(2015, 4, 8);

		mosquitoSchedule.addItem(day1);
		mosquitoSchedule.addItem(day2);
		mosquitoSchedule.addItem(day3);
		mosquitoSchedule.addItem(day4);
		mosquitoSchedule.addItem(day5);
		mosquitoSchedule.addItem(day6);

		mosquitoSchedule.resetDisplaySchedule();
		displaySchedule = mosquitoSchedule.retrieveDisplayScheduleByCompletionStatus();

		Assert::AreEqual(6, int(displaySchedule.size()));

		Assert::AreEqual(1, int(displaySchedule[0].getItemID()));
		Assert::AreEqual(2, int(displaySchedule[1].getItemID()));
		Assert::AreEqual(4, int(displaySchedule[2].getItemID()));
		Assert::AreEqual(5, int(displaySchedule[3].getItemID()));
		Assert::AreEqual(3, int(displaySchedule[4].getItemID()));
		Assert::AreEqual(6, int(displaySchedule[5].getItemID()));

		delete day1;
		delete day2;
		delete day3;
		delete day4;
		delete day5;
		delete day6;

		day1 = NULL;
		day2 = NULL;
		day3 = NULL;
		day4 = NULL;
		day5 = NULL;
		day6 = NULL;

	}

	TEST_METHOD(TestSortByDateCase1) {
		Schedule sem2ExamSchedule;
		vector<Item> expectedSchedule;
		vector<Item> retrievedSchedule;

		Item *item1;
		item1 = new Item;
		item1->setItemName(string("IE2100 Exam"));
		item1->setStartTime(2015, 4, 24, 13, 00);
		item1->setEndTime(2015, 4, 24, 15, 00);
		item1->setLabel('O');

		Item *item2;
		item2 = new Item;
		item2->setItemName(string("IE2130 Exam"));
		item2->setStartTime(2015, 4, 27, 8, 00);
		item2->setEndTime(2015, 4, 27, 10, 00);
		item2->setLabel('O');

		Item *item3;
		item3 = new Item;
		item3->setItemName(string("IE2150 Exam"));
		item3->setStartTime(2015, 4, 21, 13, 00);
		item3->setEndTime(2015, 4, 21, 15, 00);
		item3->setLabel('O');

		sem2ExamSchedule.addItem(item1);
		sem2ExamSchedule.addItem(item2);
		sem2ExamSchedule.addItem(item3);

		expectedSchedule.push_back(*item1);
		expectedSchedule.push_back(*item2);
		expectedSchedule.push_back(*item3);
		sem2ExamSchedule.resetDisplaySchedule();
		retrievedSchedule = sem2ExamSchedule.retrieveDisplaySchedule();
		Assert::AreEqual(expectedSchedule.size(), retrievedSchedule.size());
		Assert::AreEqual(expectedSchedule[0].getItemName(), retrievedSchedule[0].getItemName());
		Assert::AreEqual(expectedSchedule[1].getItemName(), retrievedSchedule[1].getItemName());
		Assert::AreEqual(expectedSchedule[2].getItemName(), retrievedSchedule[2].getItemName());

		expectedSchedule.clear();

		expectedSchedule.push_back(*item3);
		expectedSchedule.push_back(*item1);
		expectedSchedule.push_back(*item2);
		sem2ExamSchedule.resetDisplaySchedule();
		retrievedSchedule = sem2ExamSchedule.retrieveDisplayScheduleByDate();
		Assert::AreEqual(expectedSchedule.size(), retrievedSchedule.size());
		Assert::AreEqual(expectedSchedule[0].getItemName(), retrievedSchedule[0].getItemName());
		Assert::AreEqual(expectedSchedule[1].getItemName(), retrievedSchedule[1].getItemName());
		Assert::AreEqual(expectedSchedule[2].getItemName(), retrievedSchedule[2].getItemName());

		delete item1;
		delete item2;
		delete item3;
		item1 = NULL;
		item2 = NULL;
		item3 = NULL;
	}

	TEST_METHOD(TestSortByDateCase2) {
		Schedule gymSchedule;
		vector<Item> expectedSchedule;
		vector<Item> retrievedSchedule;

		Item *item1;
		item1 = new Item;
		item1->setItemName(string("Back Day"));
		item1->setStartTime(2015, 4, 24);
		item1->setLabel('P');

		Item *item2;
		item2 = new Item;
		item2->setItemName(string("Run and Swim (cardio)"));
		item2->setStartTime(2015, 4, 19, 8, 00);
		item2->setEndTime(2015, 4, 19, 11, 00);
		item2->setLabel('P');

		Item *item3;
		item3 = new Item;
		item3->setItemName(string("Run below 8 minutes for 2.4km"));
		item3->setEndTime(2015, 4, 22, 10, 00);
		item3->setLabel('O');

		gymSchedule.addItem(item1);
		gymSchedule.addItem(item2);
		gymSchedule.addItem(item3);

		expectedSchedule.push_back(*item1);
		expectedSchedule.push_back(*item2);
		expectedSchedule.push_back(*item3);
		gymSchedule.resetDisplaySchedule();
		retrievedSchedule = gymSchedule.retrieveDisplaySchedule();
		Assert::AreEqual(expectedSchedule.size(), retrievedSchedule.size());
		Assert::AreEqual(expectedSchedule[0].getItemName(), retrievedSchedule[0].getItemName());
		Assert::AreEqual(expectedSchedule[1].getItemName(), retrievedSchedule[1].getItemName());
		Assert::AreEqual(expectedSchedule[2].getItemName(), retrievedSchedule[2].getItemName());

		expectedSchedule.clear();

		expectedSchedule.push_back(*item2);
		expectedSchedule.push_back(*item3);
		expectedSchedule.push_back(*item1);
		gymSchedule.resetDisplaySchedule();
		retrievedSchedule = gymSchedule.retrieveDisplayScheduleByDate();
		Assert::AreEqual(expectedSchedule.size(), retrievedSchedule.size());
		Assert::AreEqual(expectedSchedule[0].getItemName(), retrievedSchedule[0].getItemName());
		Assert::AreEqual(expectedSchedule[1].getItemName(), retrievedSchedule[1].getItemName());
		Assert::AreEqual(expectedSchedule[2].getItemName(), retrievedSchedule[2].getItemName());

		delete item1;
		delete item2;
		delete item3;
		item1 = NULL;
		item2 = NULL;
		item3 = NULL;
	}

	TEST_METHOD(TestSortByName) {
		Schedule fishermanSchedule;
		vector<Item> expectedSchedule;
		vector<Item> retrievedSchedule;

		Item *item1;
		item1 = new Item;
		item1->setItemName(string("Ikan Bilis (1000 kgs)"));
		item1->setEndTime(2015, 2, 24);
		item1->setLabel('O');

		Item *item2;
		item2 = new Item;
		item2->setItemName(string("golden Promfret la deyyyy"));
		item2->setEndTime(2015, 6, 19);
		item2->setLabel('O');

		Item *item3;
		item3 = new Item;
		item3->setItemName(string("Ikan Petai"));
		item3->setDescription(string("boss want at least 6kg per piece"));
		item3->setEndTime(2015, 4, 21);
		item3->setLabel('O');

		Item *item4;
		item4 = new Item;
		item4->setItemName(string("Red Snapper/ Red Goby"));
		item4->setEndTime(2015, 5, 29);
		item4->setLabel('O');

		fishermanSchedule.addItem(item1);
		fishermanSchedule.addItem(item2);
		fishermanSchedule.addItem(item3);
		fishermanSchedule.addItem(item4);

		expectedSchedule.push_back(*item1);
		expectedSchedule.push_back(*item2);
		expectedSchedule.push_back(*item3);
		expectedSchedule.push_back(*item4);
		fishermanSchedule.resetDisplaySchedule();
		retrievedSchedule = fishermanSchedule.retrieveDisplaySchedule();
		Assert::AreEqual(expectedSchedule.size(), retrievedSchedule.size());
		Assert::AreEqual(expectedSchedule[0].getItemName(), retrievedSchedule[0].getItemName());
		Assert::AreEqual(expectedSchedule[1].getItemName(), retrievedSchedule[1].getItemName());
		Assert::AreEqual(expectedSchedule[2].getItemName(), retrievedSchedule[2].getItemName());
		Assert::AreEqual(expectedSchedule[3].getItemName(), retrievedSchedule[3].getItemName());

		expectedSchedule.clear();
		expectedSchedule.push_back(*item2);
		expectedSchedule.push_back(*item1);
		expectedSchedule.push_back(*item3);
		expectedSchedule.push_back(*item4);
		fishermanSchedule.resetDisplaySchedule();
		retrievedSchedule = fishermanSchedule.retrieveDisplayScheduleByItemName();
		Assert::AreEqual(expectedSchedule.size(), retrievedSchedule.size());
		Assert::AreEqual(expectedSchedule[0].getItemName(), retrievedSchedule[0].getItemName());
		Assert::AreEqual(expectedSchedule[1].getItemName(), retrievedSchedule[1].getItemName());
		Assert::AreEqual(expectedSchedule[2].getItemName(), retrievedSchedule[2].getItemName());
		Assert::AreEqual(expectedSchedule[3].getItemName(), retrievedSchedule[3].getItemName());

		delete item1;
		delete item2;
		delete item3;
		delete item4;
		item1 = NULL;
		item2 = NULL;
		item3 = NULL;
		item4 = NULL;
	}

	TEST_METHOD(TestSortByLastUpdate) {
		Schedule scheduleSortedByUpdate;
		vector<Item> sortedVector;

		Item *item4 = new Item(string("This is Item #4"));
		item4->setItemID(4);
		item4->setDescription(string("before editing"));

		int time1 = time(0);
		int time2 = time(0);
		while (time2 - time1 < 2) {
			time2 = time(0);
		}

		Item *item2 = new Item(string("This is Item #2"));
		item2->setItemID(2);
		item2->setDescription(string("before editing"));

		time1 = time(0);
		time2 = time(0);
		while (time2 - time1 < 2) {
			time2 = time(0);
		}

		Item *item1 = new Item(string("This is Item #1"));
		item1->setItemID(1);
		item1->setDescription(string("before editing"));

		time1 = time(0);
		time2 = time(0);
		while (time2 - time1 < 2) {
			time2 = time(0);
		}

		Item *item3 = new Item(string("This is Item #3"));
		item3->setItemID(3);
		item3->setDescription(string("before editing"));

		scheduleSortedByUpdate.addItem(item1);
		scheduleSortedByUpdate.addItem(item2);
		scheduleSortedByUpdate.addItem(item3);
		scheduleSortedByUpdate.addItem(item4);

		scheduleSortedByUpdate.resetDisplaySchedule();
		Assert::AreEqual(4, int(scheduleSortedByUpdate.getSizeOfSchedule()));

		sortedVector = scheduleSortedByUpdate.retrieveDisplayScheduleByLastUpdate();
		Assert::AreEqual(item3->getItemID(), sortedVector[0].getItemID());
		Assert::AreEqual(item1->getItemID(), sortedVector[1].getItemID());
		Assert::AreEqual(item2->getItemID(), sortedVector[2].getItemID());
		Assert::AreEqual(item4->getItemID(), sortedVector[3].getItemID());
	}

	};

	TEST_CLASS(TEST_UNDO) {
public:
	TEST_METHOD(ScheduleTestUndoLastCommand) {
		Schedule testSchedule;
		string confirmationFromSchedule;
		Item *item1 = new Item(string("Item number 1 in schedule!"));
		item1->setItemID(1);
		Item *item2 = new Item(string("Item number 2 in schedule!"));
		item2->setItemID(2);
		Item *item3 = new Item(string("Item number 3 in schedule!"));
		item3->setItemID(3);
		Item *item4 = new Item(string("Item number 4 in schedule!"));
		item4->setItemID(4);

		Assert::AreEqual(0, int(testSchedule.getSizeOfSchedule()));
		Assert::AreEqual(0, int(testSchedule.getSizeOfDisplaySchedule()));

		// Testing undoing of Add
		testSchedule.addItem(item1);
		testSchedule.addItem(item2);

		Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));

		confirmationFromSchedule = testSchedule.undoLastCommand();
		Assert::AreEqual(string("ADD") + item2->displayItemFullDetails(), confirmationFromSchedule);

		Assert::AreEqual(1, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(1, int(testSchedule.getSizeOfDisplaySchedule()));

		confirmationFromSchedule = testSchedule.undoLastCommand();
		Assert::AreEqual(string("ADD") + item1->displayItemFullDetails(), confirmationFromSchedule);

		Assert::AreEqual(0, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(0, int(testSchedule.getSizeOfDisplaySchedule()));

		// Testing undoing when no available commands to undo
		confirmationFromSchedule = testSchedule.undoLastCommand();
		Assert::AreEqual(string("ERROR: Undo has reached its limit."), confirmationFromSchedule);

		// Testing undoing of Delete
		testSchedule.addItem(item3);
		testSchedule.addItem(item1);
		testSchedule.addItem(item2);

		Assert::AreEqual(3, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(3, int(testSchedule.getSizeOfDisplaySchedule()));

		testSchedule.deleteItemGivenDisplayVectorIndex(2);
		Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(item3->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());
		Assert::AreEqual(item2->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemName());

		confirmationFromSchedule = testSchedule.undoLastCommand();
		Assert::AreEqual(string("DELETE") + item1->displayItemFullDetails(), confirmationFromSchedule);
		Assert::AreEqual(3, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(3, int(testSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(item3->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());
		Assert::AreEqual(item2->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemName());
		Assert::AreEqual(item1->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(3).getItemName());

		confirmationFromSchedule = testSchedule.undoLastCommand();
		Assert::AreEqual(string("ADD") + item2->displayItemFullDetails(), confirmationFromSchedule);
		Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(item3->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());
		Assert::AreEqual(item1->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemName());

		// Testing undoing of Edit
		Item *itemToReplace = new Item(string("This is the Item to replace the edited Item"));
		itemToReplace->setItemID(3);

		testSchedule.addItem(item2);
		testSchedule.addItem(item4);

		Assert::AreEqual(4, int(testSchedule.getSizeOfSchedule()));
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(4, int(testSchedule.getSizeOfDisplaySchedule()));

		Assert::AreEqual(item3->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());
		testSchedule.replaceItemGivenDisplayVectorIndex(itemToReplace, 1);
		testSchedule.resetDisplaySchedule();	// <<< This step is very important
		Assert::AreEqual(4, int(testSchedule.getSizeOfSchedule()));
		Assert::AreEqual(4, int(testSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(itemToReplace->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());
		Assert::AreEqual(item1->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemName());
		Assert::AreEqual(item2->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(3).getItemName());
		Assert::AreEqual(item4->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(4).getItemName());
		Assert::AreEqual(itemToReplace->getItemID(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemID());
		Assert::AreEqual(item1->getItemID(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemID());
		Assert::AreEqual(item2->getItemID(), testSchedule.retrieveItemGivenDisplayVectorIndex(3).getItemID());
		Assert::AreEqual(item4->getItemID(), testSchedule.retrieveItemGivenDisplayVectorIndex(4).getItemID());

		confirmationFromSchedule = testSchedule.undoLastCommand();
		Assert::AreEqual(string("REPLACE") + item3->displayItemFullDetails(), confirmationFromSchedule);
		testSchedule.resetDisplaySchedule();	// <<< This step is very important
		Assert::AreEqual(item3->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());
		Assert::AreEqual(item1->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemName());
		Assert::AreEqual(item2->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(3).getItemName());
		Assert::AreEqual(item4->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(4).getItemName());

		testSchedule.clearDisplaySchedule();
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(0, int(testSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(0, int(testSchedule.getSizeOfSchedule()));

		confirmationFromSchedule = testSchedule.undoLastCommand();
		testSchedule.resetDisplaySchedule();
		Assert::AreEqual(string("4"), confirmationFromSchedule);
		Assert::AreEqual(4, int(testSchedule.getSizeOfDisplaySchedule()));
		Assert::AreEqual(4, int(testSchedule.getSizeOfSchedule()));

		delete item1;
		delete item2;
		delete item3;
		delete item4;
		delete itemToReplace;
		item1 = NULL;
		item2 = NULL;
		item3 = NULL;
		item4 = NULL;
		itemToReplace = NULL;
	}

	/* Muted because functions passed test and moved back to private
	TEST_METHOD(ScheduleTestUndoAdd) {
	Schedule testSchedule;
	Item *item1 = new Item(string("Item number 1 in schedule!"));
	item1->setItemID(1);
	Item *item2 = new Item(string("Item number 2 in schedule!"));
	item2->setItemID(2);

	Assert::AreEqual(0, int(testSchedule.getSizeOfSchedule()));
	Assert::AreEqual(0, int(testSchedule.getSizeOfDisplaySchedule()));

	testSchedule.addItem(item1);
	testSchedule.addItem(item2);

	Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
	testSchedule.resetDisplaySchedule();
	Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));

	testSchedule.undoAdd(*item2);

	Assert::AreEqual(1, int(testSchedule.getSizeOfSchedule()));
	testSchedule.resetDisplaySchedule();
	Assert::AreEqual(1, int(testSchedule.getSizeOfDisplaySchedule()));
	Assert::AreEqual(item1->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());

	delete item1;
	delete item2;
	item1 = NULL;
	item2 = NULL;
	}

	TEST_METHOD(ScheduleTestUndoReplace) {
	Schedule testSchedule;
	Item *item1 = new Item(string("Item number 1 in schedule!"));
	item1->setItemID(1);
	Item *item2 = new Item(string("Item number 2 in schedule!"));
	item2->setItemID(2);
	Item *itemToReplaceWith = new Item(string("This is the replaced Item"));
	itemToReplaceWith->setItemID(2);
	Item replacedItemRetrievedFromSchedule;

	Assert::AreEqual(0, int(testSchedule.getSizeOfSchedule()));

	testSchedule.addItem(item1);
	testSchedule.addItem(item2);

	Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
	Assert::AreEqual(0, int(testSchedule.getSizeOfDisplaySchedule()));

	testSchedule.resetDisplaySchedule();
	Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));

	testSchedule.replaceItemGivenDisplayVectorIndex(itemToReplaceWith, 2);
	testSchedule.resetDisplaySchedule();
	replacedItemRetrievedFromSchedule = testSchedule.retrieveItemGivenDisplayVectorIndex(2);
	Assert::AreEqual(itemToReplaceWith->getItemName(), replacedItemRetrievedFromSchedule.getItemName());

	testSchedule.undoReplace(*item2);
	testSchedule.resetDisplaySchedule();
	replacedItemRetrievedFromSchedule = testSchedule.retrieveItemGivenDisplayVectorIndex(2);
	Assert::AreEqual(item2->getItemName(), replacedItemRetrievedFromSchedule.getItemName());

	delete item1;
	delete item2;
	delete itemToReplaceWith;
	item1 = NULL;
	item2 = NULL;
	itemToReplaceWith = NULL;
	}

	TEST_METHOD(ScheduleTestUndoDelete) {
	Schedule testSchedule;
	Item *item1 = new Item(string("Item number 1 in schedule!"));
	item1->setItemID(1);
	Item *item2 = new Item(string("Item number 2 in schedule!"));
	item2->setItemID(2);

	Assert::AreEqual(0, int(testSchedule.getSizeOfSchedule()));

	testSchedule.addItem(item1);
	testSchedule.addItem(item2);

	Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
	Assert::AreEqual(0, int(testSchedule.getSizeOfDisplaySchedule()));

	testSchedule.resetDisplaySchedule();
	Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));

	testSchedule.deleteItemGivenDisplayVectorIndex(2);

	Assert::AreEqual(1, int(testSchedule.getSizeOfSchedule()));
	testSchedule.resetDisplaySchedule();
	Assert::AreEqual(1, int(testSchedule.getSizeOfDisplaySchedule()));
	Assert::AreEqual(item1->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(1).getItemName());

	testSchedule.undoDelete(*item2);

	Assert::AreEqual(2, int(testSchedule.getSizeOfSchedule()));
	testSchedule.resetDisplaySchedule();
	Assert::AreEqual(2, int(testSchedule.getSizeOfDisplaySchedule()));
	Assert::AreEqual(item2->getItemName(), testSchedule.retrieveItemGivenDisplayVectorIndex(2).getItemName());

	delete item1;
	delete item2;
	item1 = NULL;
	item2 = NULL;
	}

	*/

	};
}

namespace HistoryTest {
	TEST_CLASS(TEST_HISTORY) {
public:
	/* Tests muted because functions passed test and returned to private.
	TEST_METHOD(HistoryTestIsNormalHistoryCommand) {
	History testHistory;
	bool isValidHistoryCmd;

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("ADD"));
	Assert::AreEqual(true, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("DELETE"));
	Assert::AreEqual(true, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("REPLACE"));
	Assert::AreEqual(true, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("Add"));
	Assert::AreEqual(false, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("Delete"));
	Assert::AreEqual(false, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("Replace"));
	Assert::AreEqual(false, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("whattt"));
	Assert::AreEqual(false, isValidHistoryCmd);

	isValidHistoryCmd = testHistory.isNormalHistoryCommand(string("ADDD"));
	Assert::AreEqual(false, isValidHistoryCmd);
	}

	TEST_METHOD(HistoryTestIsClearCommand) {
	History testHistory;
	bool isClearCmd;

	isClearCmd = testHistory.isClearCommand(string("CLEAR"));
	Assert::AreEqual(true, isClearCmd);

	isClearCmd = testHistory.isClearCommand(string("Clear"));
	Assert::AreEqual(false, isClearCmd);

	isClearCmd = testHistory.isClearCommand(string("ADD"));
	Assert::AreEqual(false, isClearCmd);
	}

	TEST_METHOD(HistoryTestIsValidUndoCall) {
	History testHistory;
	bool isValidCallForUndo;

	isValidCallForUndo = testHistory.isValidUndoCall();
	Assert::AreEqual(false, isValidCallForUndo);

	string command1 = "ADD";
	Item item1(string("This is the first item"));
	testHistory.addCommand(command1, item1);

	isValidCallForUndo = testHistory.isValidUndoCall();
	Assert::AreEqual(true, isValidCallForUndo);
	}

	*/

	TEST_METHOD(HistoryTestAddCommand) {
		History testHistory;
		string returnMessage;

		string command1 = "ADD";
		Item item1(string("This is the first item"));

		string command2 = "DELETE";
		Item item2(string("This is the second item"));

		string command3 = "REPLACE";
		Item item3(string("This is the third item"));

		string command4 = "ADDD";
		Item item4(string("This is the fourth item"));

		string command5 = "SIT";
		Item item5(string("This is the fifth item"));

		returnMessage = testHistory.addCommand(command1, item1);
		Assert::AreEqual(command1 + item1.displayItemFullDetails(), returnMessage);

		returnMessage = testHistory.addCommand(command2, item2);
		Assert::AreEqual(command2 + item2.displayItemFullDetails(), returnMessage);

		returnMessage = testHistory.addCommand(command3, item3);
		Assert::AreEqual(command3 + item3.displayItemFullDetails(), returnMessage);

		returnMessage = testHistory.addCommand(command4, item4);
		Assert::AreEqual(string("ERROR: Command and Item were not recorded."), returnMessage);

		returnMessage = testHistory.addCommand(command5, item5);
		Assert::AreEqual(string("ERROR: Command and Item were not recorded."), returnMessage);
	}

	TEST_METHOD(HistoryTestAddClearCommand) {
		History testHistory;
		string returnMessage;
		vector<Item> clearedSchedule;
		Item* item1 = new Item(string("helloworld"));

		clearedSchedule.push_back(*item1);
		returnMessage = testHistory.addClearCommand(clearedSchedule);
		Assert::AreEqual(string("CLEAR"), returnMessage);
	}

	TEST_METHOD(HistoryTestUndoLastCommand) {
		History testHistory;
		string returnMessage;
		string commandFromHistory;
		Item latestItemFromHistory;
		vector <Item> clearedSchedule;
		vector <Item> latestClearedScheduleFromHistory;

		returnMessage = testHistory.undoLastCommand(commandFromHistory, latestItemFromHistory, latestClearedScheduleFromHistory);
		Assert::AreEqual(string("ERROR: Undo has reached its limit."), returnMessage);

		string command1 = "ADD";
		Item item1(string("What's up with it, vanilla face?"));
		testHistory.addCommand(command1, item1);
		returnMessage = testHistory.undoLastCommand(commandFromHistory, latestItemFromHistory, latestClearedScheduleFromHistory);
		Assert::AreEqual(command1 + "\n" + item1.displayItemFullDetails(), returnMessage);

		testHistory.addCommand(command1, item1);
		clearedSchedule.push_back(item1);
		testHistory.addClearCommand(clearedSchedule);
		returnMessage = testHistory.undoLastCommand(commandFromHistory, latestItemFromHistory, latestClearedScheduleFromHistory);
		Assert::AreEqual(clearedSchedule[0].getItemName(), latestClearedScheduleFromHistory[0].getItemName());
	}

	};
}