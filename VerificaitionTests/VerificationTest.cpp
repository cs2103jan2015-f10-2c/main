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

		TEST_METHOD(TestIsValidDate)
		{

		}

	};
}
