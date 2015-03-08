#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ItemTest
{
	TEST_CLASS(TEST_SETDATETIME)
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
	};

	TEST_CLASS(TEST_GETDATETIME)
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

	TEST_CLASS(TEST_ISWITHINRANGE)
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
	};
}