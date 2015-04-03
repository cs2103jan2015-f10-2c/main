#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VerificationTests
{
	TEST_CLASS(DateTimeVerificationTest)
	{
	public:

		TEST_METHOD(VerificationTestIsValidDateTimeValues)
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

		TEST_METHOD(VerificationTestHasYearMonthDay)
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

		TEST_METHOD(VerificationTestHasMonthDay)
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

		TEST_METHOD(VerificationTestIsActualYearMonthDate)
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

			// Boundary Test - 30/2/2000 does not exist
			DateTime dateTimeObject7(2000, 2, 30);
			DateTimeVerification verify7(dateTimeObject7);
			isActualYMD = verify7.isActualYearMonthDayDate();
			Assert::AreEqual(false, isActualYMD);

			// Boundary Test - 29/2/2000 exists
			DateTime dateTimeObject8(2000, 2, 29);
			DateTimeVerification verify8(dateTimeObject8);
			isActualYMD = verify8.isActualYearMonthDayDate();
			Assert::AreEqual(true, isActualYMD);

			// Boundary Test - 31/12/2015 exists
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

		TEST_METHOD(VerificationTestIsValidTime)
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

		TEST_METHOD(VerificationTestIsValidDateTime)
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

			DateTime dateTimeObject14(-1, -1, 29, -1, -1);
			DateTimeVerification verify14(dateTimeObject14);
			isValidDateTime = verify14.isValidDateTime();
			Assert::AreEqual(false, isValidDateTime);

			DateTime dateTimeObject15(-1, -1, -1, -1, -1);
			DateTimeVerification verify15(dateTimeObject15);
			isValidDateTime = verify15.isValidDateTime();
			Assert::AreEqual(true, isValidDateTime);
		}

	};


	TEST_CLASS(ItemVerificationTest)
	{
	public:

		TEST_METHOD(VerificationTestIsValidName)
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

		TEST_METHOD(VerificationTestIsValidStartDateTime)
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

		TEST_METHOD(VerificationTestIsValidEndDateTime)
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

		TEST_METHOD(VerificationTestIsValidTimeFrame)
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
		}

		TEST_METHOD(VerificationTestIsValidItem)
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

			DateTime startTime2(-1, -1, -1, -1, -1);
			DateTime endTime2(2015, 02, 14, -1, -1);
			Item item2(string("Hello Boss"));
			item2.setStartTime(startTime2);
			item2.setEndTime(endTime2);
			item2.setItemID(1001);
			ItemVerification verify5(item2,1002);
			isValid = verify5.isValidItem();
			Assert::AreEqual(true, isValid);

			DateTime startTime3(-1, -1, -1, -1, -1);
			DateTime endTime3(-1, -1, -1, -1, -1);
			Item item3(string("Hello Boss"));
			item3.setStartTime(startTime3);
			item3.setEndTime(endTime3);
			item3.setItemID(1001);
			ItemVerification verify6(item3, 1002);
			isValid = verify6.isValidItem();
			Assert::AreEqual(true, isValid);

			DateTime startTime4(-1, -1, -1, -1, -1);
			DateTime endTime4(-1, -1, -1, -1, -1);
			Item item4;
			item4.setStartTime(startTime4);
			item4.setEndTime(endTime4);
			item4.setItemID(1001);
			ItemVerification verify7(item4, 1002);
			isValid = verify7.isValidItem();
			Assert::AreEqual(false, isValid);

			DateTime startTime5(2014, 8, 11, -1, -1);
			DateTime endTime5(2014, 6, 12, 13, 14);
			Item item5("Dogface bones");
			item5.setStartTime(startTime5);
			item5.setEndTime(endTime5);
			item5.setItemID(20);
			item5.setPriority('L');
			ItemVerification verify8(item5, 20);
			isValid = verify8.isValidItem();
			Assert::AreEqual(false, isValid);
		}

		TEST_METHOD(VerificationTestGetItemVerificationErrors)
		{
			int numberOfErrors =  0;
			list<string> errorList;

			Item item1(string("Engin Run 1999"));
			item1.setPriority('X');	//ERROR
			item1.setLabel('X');	//ERROR
			item1.setStartTime(1999, 2, 29);	//ERROR
			ItemVerification verify1(item1, 100);
			verify1.isValidItem();
			errorList = verify1.getItemVerificationErrors();
			numberOfErrors = errorList.size();
			Assert::AreEqual(3, numberOfErrors);

			Item item2(string(""));	//ERROR
			item2.setPriority('H');
			item2.setLabel('E');
			item2.setStartTime(2000, 2, 29);
			item2.setEndTime(2000, 2, 20);	// ERROR invalid time frame
			ItemVerification verify2(item2, 100);
			verify2.isValidItem();
			errorList = verify2.getItemVerificationErrors();
			numberOfErrors = errorList.size();
			Assert::AreEqual(2, numberOfErrors);

			Item item3(string("ISE FYP submission deadline"));
			item3.setPriority('H');
			item3.setLabel('O');
			item3.setEndTime(2001, 11, 31);	//ERROR
			ItemVerification verify3(item3, 100);
			verify3.isValidItem();
			errorList = verify3.getItemVerificationErrors();
			numberOfErrors = errorList.size();
			Assert::AreEqual(1, numberOfErrors);
		}


	};

}