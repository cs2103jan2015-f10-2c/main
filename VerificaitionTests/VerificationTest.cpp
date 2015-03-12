#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VerificaitionTests
{		
	TEST_CLASS(DateTimeVerificationTest)
	{
	public:
		
		TEST_METHOD(TestIsValidDate)
		{
			DateTime dateTimeObject;
			bool isValid;

			dateTimeObject.setYear(2014);
			dateTimeObject.setMonth(10);
			dateTimeObject.setDay(10);
			DateTimeVerification verify(dateTimeObject);

			isValid = verify.isValidDate();
			Assert::AreEqual(true, isValid);

			dateTimeObject.setYear(10000);
			dateTimeObject.setMonth(10);
			dateTimeObject.setDay(10);
			DateTimeVerification verify2(dateTimeObject);

			isValid = verify2.isValidDate();
			Assert::AreEqual(false, isValid);

			dateTimeObject.setYear(2014);
			dateTimeObject.setMonth(-2);
			dateTimeObject.setDay(10);
			DateTimeVerification verify3(dateTimeObject);

			isValid = verify3.isValidDate();
			Assert::AreEqual(false, isValid);
		}
		
		TEST_METHOD(TestIsValidTime)
		{
			DateTime dateTimeObject;
			bool isValid;

			dateTimeObject.setHour(16);
			dateTimeObject.setMinute(10);
			DateTimeVerification verify(dateTimeObject);

			isValid = verify.isValidTime();
			Assert::AreEqual(true, isValid);

			dateTimeObject.setHour(00);
			dateTimeObject.setMinute(00);
			DateTimeVerification verify2(dateTimeObject);

			isValid = verify2.isValidTime();
			Assert::AreEqual(true, isValid);

			dateTimeObject.setHour(25);
			dateTimeObject.setMinute(10);
			DateTimeVerification verify3(dateTimeObject);

			isValid = verify3.isValidTime();
			Assert::AreEqual(false, isValid);
		}

		TEST_METHOD(TestIsValidDateTime)
		{
			DateTime dateTimeObject;
			bool isValid;

			dateTimeObject.setYear(2014);
			dateTimeObject.setMonth(10);
			dateTimeObject.setDay(10);
			dateTimeObject.setHour(17);
			dateTimeObject.setMinute(00);
			DateTimeVerification verify(dateTimeObject);

			isValid = verify.isValidDateTime();
			Assert::AreEqual(true, isValid);

			dateTimeObject.setYear(2014);
			dateTimeObject.setMonth(-9);
			dateTimeObject.setDay(10);
			dateTimeObject.setHour(17);
			dateTimeObject.setMinute(00);
			DateTimeVerification verify2(dateTimeObject);

			isValid = verify2.isValidDateTime();
			Assert::AreEqual(false, isValid);
		}

	};


	TEST_CLASS(ItemVerificationTest)
	{
	public:

		TEST_METHOD(TestIsValidItem)
		{
			DateTime startTime(2014,03,10,17,00);
			DateTime endTime(2014,10,15,0,01);
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
			Assert::AreEqual(true, isValid);
			
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
