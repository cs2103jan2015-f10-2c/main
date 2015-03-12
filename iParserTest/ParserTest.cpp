#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace iPlannerParserTest {

	TEST_CLASS(ParseInfoTest) {
	private:
		ParseInfo testParseInfo;
	public:
		TEST_METHOD(commandTest) {
			string text = "add";
			string actualSet;
			string expectedSet;
			string actualGet;
			string expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.hasMainCommand();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setMainCommand(text);
			expectedSet = "successful execution";
			actualGet = testParseInfo.getMainCommand();
			expectedGet = "add";	
			Assert::AreEqual(expectedSet, actualSet);
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.hasMainCommand();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}

		TEST_METHOD(IndexTest) {
			unsigned int validIndex = 1;
			unsigned int invalidIndex = -1;
			string actualSet;
			string expectedSet;
			int actualGet;
			int expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.hasIndex();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setIndex(validIndex);
			expectedSet = "execution sucessful";
			actualGet = testParseInfo.getIndex();
			expectedGet = 1;
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.hasIndex();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);

			actualSet = testParseInfo.setIndex(invalidIndex);
			expectedSet = "execution sucessful";
			actualGet = testParseInfo.getIndex();
			expectedGet = -1;
			Assert::AreEqual(expectedGet, actualGet);
			
			actualBool = testParseInfo.hasIndex();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}
		
		TEST_METHOD(itemTest) {
			string text = "itemName";
			Item testItem;
			string actualSet;
			string expectedSet;
			string actualGet;
			string expectedGet;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.hasItem();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);

			testItem.setItemName(text);
			actualSet = testParseInfo.setItem(testItem);
			expectedSet = "successful execution";
			Assert::AreEqual(expectedSet, actualSet);

			testItem = testParseInfo.getItem();
			actualGet = testItem.getItemName();
			expectedGet = "itemName";
			Assert::AreEqual(expectedGet, actualGet);

			actualBool = testParseInfo.hasItem();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
		}
		
		TEST_METHOD(ValidityTest) {
			string actualString;
			string expectedString;
			bool actualBool;
			bool expectedBool;

			actualBool = testParseInfo.hasValidInput();
			expectedBool = true;
			Assert::AreEqual(expectedBool, actualBool);
			
			actualString = testParseInfo.setIsNotValidInput();
			expectedString = "successful execution";
			Assert::AreEqual(expectedString, actualString);

			actualBool = testParseInfo.hasValidInput();
			expectedBool = false;
			Assert::AreEqual(expectedBool, actualBool);
		}
	};
	
	TEST_CLASS(iPlannerParserTest) {
	private:
		iParser testParser;
		ParseInfo testParseInfo;
	public:
		TEST_METHOD(isValidLengthTest) {
			//string text = "testing";
			//string actualString;
			//string expectedString;
			//bool actualBool;
			//bool expectedBool;

			//actualBool = testParser.isValidLength(text);
			//expectedBool = true;
			//Assert::AreEqual(expectedBool, actualBool);
		}
	};
}