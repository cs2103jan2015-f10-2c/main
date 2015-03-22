#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VerificationTests
{
	TEST_CLASS(DateTimeVerificationTest)
	{
	public:

		TEST_METHOD(TestIsValidDateTimeValues)
		{
			bool isValid;

			DateTime dateTimeObject(1992, 11, 18, 00, 00);
			DateTimeVerification verify(dateTimeObject);
			isValid = verify.isValidDateTimeValues();
			Assert::AreEqual(true, isValid);

			DateTime dateTimeObject2(900000, 11, 18, 00, 00);
			DateTimeVerification verify2(dateTimeObject2);

			isValid = verify2.isValidDateTimeValues();
			Assert::AreEqual(false, isValid);
		}

		TEST_METHOD(TestHasYearMonthDay)
		{
			bool hasYMD;

			DateTime dateTimeObject(1992, 11, 18, 00, 00);
			DateTimeVerification verify(dateTimeObject);
			hasYMD = verify.hasYearMonthDay();
			Assert::AreEqual(true, hasYMD);

			DateTime dateTimeObject2(1992, 11, 18, -1, -1);
			DateTimeVerification verify2(dateTimeObject2);
			hasYMD = verify2.hasYearMonthDay();
			Assert::AreEqual(true, hasYMD);

			DateTime dateTimeObject3(-1, 11, 18, 111, -1);
			DateTimeVerification verify3(dateTimeObject3);
			hasYMD = verify3.hasYearMonthDay();
			Assert::AreEqual(false, hasYMD);

			// hasYearMonthDay() does not check for validity
			// of _hour and _minute
			DateTime dateTimeObject4(1992, 11, 18, -1, 30);
			DateTimeVerification verify4(dateTimeObject4);
			hasYMD = verify4.hasYearMonthDay();
			Assert::AreEqual(true, hasYMD);
		}

		TEST_METHOD(TestHasMonthDay)
		{
			bool hasMD;
			
			DateTime dateTimeObject(-1, 11, 18, 00, 00);
			DateTimeVerification verify(dateTimeObject);
			hasMD = verify.hasMonthDay();
			Assert::AreEqual(true, hasMD);
			 
			DateTime dateTimeObject2(-1, 11, 18, -1, -1);
			DateTimeVerification verify2(dateTimeObject2);
			hasMD = verify2.hasMonthDay();
			Assert::AreEqual(true, hasMD);
			
			DateTime dateTimeObject3(-1, 11, 18, -1, -1);
			DateTimeVerification verify3(dateTimeObject3);
			hasMD = verify3.hasMonthDay();
			Assert::AreEqual(true, hasMD);
			
			// hasMonthDay() assumes _year is EMPTYFIELD_DATETIME
			// and does not check _year's validity
			DateTime dateTimeObject4(23, 11, 18, -1, 30);
			DateTimeVerification verify4(dateTimeObject4);
			hasMD = verify4.hasYearMonthDay();
			Assert::AreEqual(true, hasMD);

			// hasMonthDay() does not check for validity of
			// _hour and _minute
			DateTime dateTimeObject5(-1, 30, 18, 30, 30);
			DateTimeVerification verify5(dateTimeObject5);
			hasMD = verify5.hasYearMonthDay();
			Assert::AreEqual(false, hasMD);
			
		}

		TEST_METHOD(TestIsActualYearMonthDate)
		{
			bool isActualYMD;

			DateTime dateTimeObject(1992, 11, 18);
			DateTimeVerification verify(dateTimeObject);
			isActualYMD = verify.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			DateTime dateTimeObject2(9999, 11, 18);
			DateTimeVerification verify2(dateTimeObject2);
			isActualYMD = verify2.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			DateTime dateTimeObject3(1992, 11, 18, -1, -1);
			DateTimeVerification verify3(dateTimeObject3);
			isActualYMD = verify3.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			// isActualYearMonthDate() does not check for
			// validity of _hour and _minute
			DateTime dateTimeObject4(1992, 11, 18, 100, 100);
			DateTimeVerification verify4(dateTimeObject4);
			isActualYMD = verify4.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			DateTime dateTimeObject5(2015, 2, 30);
			DateTimeVerification verify5(dateTimeObject5);
			isActualYMD = verify5.isActualYearMonthDayDate();
			Assert::AreEqual(false, isActualYMD);

			DateTime dateTimeObject6(2015, 2, 29);
			DateTimeVerification verify6(dateTimeObject6);
			isActualYMD = verify6.isActualYearMonthDayDate();
			Assert::AreEqual(false, isActualYMD);

			DateTime dateTimeObject7(2000, 2, 30);
			DateTimeVerification verify7(dateTimeObject7);
			isActualYMD = verify7.isActualYearMonthDayDate();
			Assert::AreEqual(false, isActualYMD);

			DateTime dateTimeObject8(2000, 2, 29);
			DateTimeVerification verify8(dateTimeObject8);
			isActualYMD = verify8.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			DateTime dateTimeObject9(2015, 12, 31);
			DateTimeVerification verify9(dateTimeObject9);
			isActualYMD = verify9.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			DateTime dateTimeObject10(2016, 4, 31);
			DateTimeVerification verify10(dateTimeObject10);
			isActualYMD = verify10.isActualYearMonthDayDate();
			Assert::AreEqual(false, isActualYMD);

			DateTime dateTimeObject11(2016, 4, 30);
			DateTimeVerification verify11(dateTimeObject11);
			isActualYMD = verify11.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);
		}

		TEST_METHOD(TestIsValidTime)
		{
			DateTime dateTimeObject;
			bool isValidTime;

			dateTimeObject.setHour(16);
			dateTimeObject.setMinute(10);
			DateTimeVerification verify(dateTimeObject);
			
			isValidTime = verify.isValidTime();
			Assert::AreEqual(true, isValidTime);
			
			dateTimeObject.setHour(00);
			dateTimeObject.setMinute(00);
			DateTimeVerification verify2(dateTimeObject);
			
			isValidTime = verify2.isValidTime();
			Assert::AreEqual(true, isValidTime);
			
			DateTime dateTimeObject2;
			dateTimeObject2.setHour(29);
			dateTimeObject2.setMinute(10);
			DateTimeVerification verify3(dateTimeObject2);

			isValidTime = verify3.isValidTime();
			Assert::AreEqual(false, isValidTime);
			
		}

		TEST_METHOD(TestIsValidDateTime)
		{
			bool isValidDateTime;

			DateTime dateTimeObject(1992, 11, 18, 10, 00);
			DateTimeVerification verify(dateTimeObject);
			isValidDateTime = verify.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);
			
			DateTime dateTimeObject2(1992, 11, 18, 24, 00);
			DateTimeVerification verify2(dateTimeObject2);
			isValidDateTime = verify2.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);
			
			DateTime dateTimeObject3(1992, 11, 18, -1, -1);
			DateTimeVerification verify3(dateTimeObject3);
			isValidDateTime = verify3.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);
			
			DateTime dateTimeObject4(1992, 11, 18, 20, -1);
			DateTimeVerification verify4(dateTimeObject4);
			isValidDateTime = verify4.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);
			
			DateTime dateTimeObject5(1992, 11, 18, -1, 10);
			DateTimeVerification verify5(dateTimeObject5);
			isValidDateTime = verify5.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);
			
			DateTime dateTimeObject6(99999, 11, 18, 10, 00);
			DateTimeVerification verify6(dateTimeObject6);
			isValidDateTime = verify6.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);
			
			/* These tests are FALSE for V0.2 because dates without year are not accepted
			DateTime dateTimeObject7(-1, 11, 18, 10, 00);
			DateTimeVerification verify7(dateTimeObject7);
			isValidDateTime = verify7.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);
			
			DateTime dateTimeObject8(-1, 11, 18, -1, -1);
			DateTimeVerification verify8(dateTimeObject8);
			isValidDateTime = verify8.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);
			*/
			
			DateTime dateTimeObject9(1992, -1, 18, 10, 00);
			DateTimeVerification verify9(dateTimeObject9);
			isValidDateTime = verify9.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);
			
			DateTime dateTimeObject10(1992, 11, 40, -1, -1);
			DateTimeVerification verify10(dateTimeObject10);
			isValidDateTime = verify10.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);

			DateTime dateTimeObject11(2000, 2, 29, 10, 00);
			DateTimeVerification verify11(dateTimeObject11);
			isValidDateTime = verify11.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);

			DateTime dateTimeObject12(2001, 2, 29, 10, 00);
			DateTimeVerification verify12(dateTimeObject12);
			isValidDateTime = verify12.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);

			DateTime dateTimeObject13(2000, 2, 29, -1, -1);
			DateTimeVerification verify13(dateTimeObject13);
			isValidDateTime = verify13.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);
		}

	};


	TEST_CLASS(ItemVerificationTest)
	{
	public:

		TEST_METHOD(TestIsValidName)
		{
			bool isValidName;

			Item item;
			ItemVerification verify(item, 100);
			isValidName = verify.isValidName();
			Assert::AreEqual(false, isValidName);

			Item item2(string("Attend One Direction concert!!"));
			ItemVerification verify2(item2, 100);
			isValidName = verify2.isValidName();
			Assert::AreEqual(true, isValidName);
		}

		TEST_METHOD(TestIsValidStartDateTime)
		{
			bool isValidStartDateTime;

			Item item;
			DateTime startTime1(2014, 03, 10, 17, 00);
			item.setStartTime(startTime1);
			ItemVerification verify(item, 100);
			isValidStartDateTime = verify.isValidStartDateTime();
			Assert::AreEqual(true, isValidStartDateTime);
			
			Item item2;
			DateTime startTime2(2014, 03, 10);
			item2.setStartTime(startTime2);
			ItemVerification verify2(item2, 100);
			isValidStartDateTime = verify2.isValidStartDateTime();
			Assert::AreEqual(true, isValidStartDateTime);
			
			Item item3;
			DateTime startTime3(99999, 03, 10, 17, 00);
			item3.setStartTime(startTime3);
			ItemVerification verify3(item3, 100);
			isValidStartDateTime = verify3.isValidStartDateTime();
			Assert::AreEqual(false, isValidStartDateTime);
			
			Item item4;
			DateTime startTime4(2000, 2, 30, 17, 00);
			item4.setStartTime(startTime4);
			ItemVerification verify4(item4, 100);
			isValidStartDateTime = verify4.isValidStartDateTime();
			Assert::AreEqual(false, isValidStartDateTime);
			
			Item item5;
			DateTime startTime5(2000, 2, 29, 17, 00);
			item5.setStartTime(startTime5);
			ItemVerification verify5(item5, 100);
			isValidStartDateTime = verify5.isValidStartDateTime();
			Assert::AreEqual(true, isValidStartDateTime);
			
		}

		TEST_METHOD(TestIsValidEndDateTime)
		{
			bool isValidEndDateTime;

			Item item;
			DateTime endTime1(2014, 03, 10, 17, 00);
			item.setEndTime(endTime1);
			ItemVerification verify(item, 100);
			isValidEndDateTime = verify.isValidEndDateTime();
			Assert::AreEqual(true, isValidEndDateTime);
			
			Item item2;
			DateTime endTime2(2014, 03, 10);
			item2.setEndTime(endTime2);
			ItemVerification verify2(item2, 100);
			isValidEndDateTime = verify2.isValidEndDateTime();
			Assert::AreEqual(true, isValidEndDateTime);

			Item item3;
			DateTime endTime3(99999, 03, 10, 17, 00);
			item3.setEndTime(endTime3);
			ItemVerification verify3(item3, 100);
			isValidEndDateTime = verify3.isValidEndDateTime();
			Assert::AreEqual(false, isValidEndDateTime);

			Item item4;
			DateTime endTime4(2000, 2, 30, 17, 00);
			item4.setEndTime(endTime4);
			ItemVerification verify4(item4, 100);
			isValidEndDateTime = verify4.isValidEndDateTime();
			Assert::AreEqual(false, isValidEndDateTime);

			Item item5;
			DateTime endTime5(2000, 2, 29, 17, 00);
			item5.setEndTime(endTime5);
			ItemVerification verify5(item5, 100);
			isValidEndDateTime = verify5.isValidEndDateTime();
			Assert::AreEqual(true, isValidEndDateTime);
			
		}

		TEST_METHOD(TestIsValidTimeFrame)
		{
			bool isValidTimeFrame;
			
			DateTime startTime1(2014, 03, 10, 17, 00);
			DateTime endTime1(2014, 10, 15, 0, 01);
			Item item1;
			item1.setStartTime(startTime1);
			item1.setEndTime(endTime1);
			ItemVerification verify1(item1, 100);
			isValidTimeFrame = verify1.isValidTimeFrame();
			Assert::AreEqual(true, isValidTimeFrame);
			
			DateTime startTime2(2014, 03, 10, -1, -1);
			DateTime endTime2(2014, 03, 15, 0, 01);
			Item item2;
			item2.setStartTime(startTime2);
			item2.setEndTime(endTime2);
			ItemVerification verify2(item2, 100);
			isValidTimeFrame = verify2.isValidTimeFrame();
			Assert::AreEqual(true, isValidTimeFrame);
			
			DateTime startTime3(2014, 03, 10, -1, -1);
			DateTime endTime3(2014, 03, 10, 10, 30);
			Item item3;
			item3.setStartTime(startTime3);
			item3.setEndTime(endTime3);
			ItemVerification verify3(item3, 100);
			isValidTimeFrame = verify3.isValidTimeFrame();
			Assert::AreEqual(true, isValidTimeFrame);
			
			DateTime startTime4(2014, 03, 10, 10, 30);
			DateTime endTime4(2014, 03, 10, -1, -1);
			Item item4;
			item4.setStartTime(startTime4);
			item4.setEndTime(endTime4);
			ItemVerification verify4(item4, 100);
			isValidTimeFrame = verify4.isValidTimeFrame();
			Assert::AreEqual(true, isValidTimeFrame);
			
			DateTime startTime5(2014, 03, 10, 10, 30);
			DateTime endTime5(2014, 03, 10, 10, 30);
			Item item5;
			item5.setStartTime(startTime5);
			item5.setEndTime(endTime5);
			ItemVerification verify5(item5, 100);
			isValidTimeFrame = verify5.isValidTimeFrame();
			Assert::AreEqual(false, isValidTimeFrame);
			
			DateTime startTime6(2014, 03, 15, -1, -1);
			DateTime endTime6(2014, 03, 10, 10, 30);
			Item item6;
			item6.setStartTime(startTime6);
			item6.setEndTime(endTime6);
			ItemVerification verify6(item6, 100);
			isValidTimeFrame = verify6.isValidTimeFrame();
			Assert::AreEqual(false, isValidTimeFrame);
			
			DateTime startTime7(2014, 03, 15, 10, 00);
			DateTime endTime7(2014, 03, 10, 10, 30);
			Item item7;
			item7.setStartTime(startTime7);
			item7.setEndTime(endTime7);
			ItemVerification verify7(item7, 100);
			isValidTimeFrame = verify7.isValidTimeFrame();
			Assert::AreEqual(false, isValidTimeFrame);
			
			DateTime startTime8(2014, 03, 15, -1, -1);
			DateTime endTime8(2014, 03, 10, -1, -1);
			Item item8;
			item8.setStartTime(startTime8);
			item8.setEndTime(endTime8);
			ItemVerification verify8(item8, 100);
			isValidTimeFrame = verify8.isValidTimeFrame();
			Assert::AreEqual(false, isValidTimeFrame);
			
			DateTime startTime9(2014, 03, 15, 10, 00);
			DateTime endTime9(2014, 03, 10, -1, -1);
			Item item9;
			item9.setStartTime(startTime9);
			item9.setEndTime(endTime9);
			ItemVerification verify9(item9, 100);
			isValidTimeFrame = verify9.isValidTimeFrame();
			Assert::AreEqual(false, isValidTimeFrame);
			/**/
		}

		TEST_METHOD(TestIsValidItem)
		{
			DateTime startTime(2014, 03, 10, 17, 00);
			DateTime endTime(2014, 10, 15, 0, 01);
			Item item;
			bool isValid;

			item.setItemName("Buy yellow crayons from Borders.");
			item.setDescription("only buy from Crayola!!");
			item.setStartTime(startTime);
			item.setEndTime(endTime);
			item.setItemID(91823);
			item.setPriority('H');
			item.setLabel('P');
			ItemVerification verify(item, 800000);

			isValid = verify.isValidItem();
			Assert::AreEqual(true, isValid);

			ItemVerification verify2(item, 91822);

			isValid = verify2.isValidItem();
			Assert::AreEqual(false, isValid);

			item.setItemName("");
			ItemVerification verify3(item, 800000);

			isValid = verify3.isValidItem();
			Assert::AreEqual(false, isValid);

			item.setItemName("Hunt wild dogs in the prairie.");
			item.setPriority('t');
			ItemVerification verify4(item, 800000);

			isValid = verify4.isValidItem();
			Assert::AreEqual(false, isValid);

		}

	};

}