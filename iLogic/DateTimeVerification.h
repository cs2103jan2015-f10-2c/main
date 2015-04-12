#ifndef DATETIME_VERIFICATION_H
#define DATETIME_VERIFICATION_H

#include <string>
#include <iostream>
#include "..\iStorage\DateTime.h"
#include "..\iPlanner Log\Log.h"
using namespace std;

class DateTimeVerification {

private:

	static const int DATETIME_VERIFICATION_MIN_YEAR;
	static const int DATETIME_VERIFICATION_MAX_YEAR;
	static const int DATETIME_VERIFICATION_MIN_MONTH;
	static const int DATETIME_VERIFICATION_MAX_MONTH;
	static const int DATETIME_VERIFICATION_MIN_DAY;
	static const int DATETIME_VERIFICATION_MAX_DAY;
	static const int DATETIME_VERIFICATION_MIN_HOUR;
	static const int DATETIME_VERIFICATION_MAX_HOUR;
	static const int DATETIME_VERIFICATION_MIN_MINUTE;
	static const int DATETIME_VERIFICATION_MAX_MINUTE;
	static const int DATETIME_VERIFICATION_EMPTYFIELD_DATETIME;
	static const int DATETIME_VERIFICATION_INT_MINUS_TWO;

	static const int DATETIME_VERIFICATION_DAY_29;
	static const int DATETIME_VERIFICATION_DAY_30;
	static const int DATETIME_VERIFICATION_DAY_31;
	static const int DATETIME_VERIFICATION_MONTH_FEB;
	static const int DATETIME_VERIFICATION_MONTH_APR;
	static const int DATETIME_VERIFICATION_MONTH_JUN;
	static const int DATETIME_VERIFICATION_MONTH_SEP;
	static const int DATETIME_VERIFICATION_MONTH_NOV;
	static const int DATETIME_VERIFICATION_YEAR_4;
	static const int DATETIME_VERIFICATION_YEAR_100;
	static const int DATETIME_VERIFICATION_YEAR_400;

	static const string DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;

	Log _dateTimeVerificationLogger;
	DateTime _dateTimeObjectToVerify;
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;

	////////////////////////////////////////
	//CHANGE BACK TO PRIVATE AFTER TESTING//
	////////////////////////////////////////
public:

	////////////////////////////
	////// LEVEL 1 of SLAP /////
	////////////////////////////

	// This group of functions only check for VALIDITY of
	// INDIVIDUAL year/month/day/hour/minute values.
	// They do not check whether the values come together
	// to give a "correct" DateTime object.
	bool isValidDateTimeValues();
	bool isValidYearRange();
	bool isValidMonthRange();
	bool isValidDayRange();
	bool isValidHourRange();
	bool isValidMinuteRange();


	////////////////////////////
	////// LEVEL 2 of SLAP /////
	////////////////////////////

	// This group of functions checks if the
	// individual year/month/day values come
	// together as a valid date format.
	// i.e. DD MM YYYY or DD MM -1
	bool hasYearMonthDay();
	bool hasMonthDay();
	bool hasYear();
	bool hasMonth();
	bool hasDay();

	// This group of functions checks if the
	// individual year/month/day values come
	// together as a valid time format.
	// i.e. HH MM or -1 -1
	bool hasHourMinute();
	bool hasHour();
	bool hasMinute();
	bool isValidTime();

	// Checks if the date (YYYY MM DD) is an actual
	// Gregorian calendar date
	//	Pre: Date is in YYYY MM DD format. Date that is in
	//	-1 MM DD format will not be processed by thos method.
	bool isActualYearMonthDayDate();



public:

	// Constructor
	DateTimeVerification(DateTime dateTimeObject);


	// Does comprehensive checks to the given DateTme object
	// to determine if it satisfies a valid iPlanner calendar
	// format and is an actual calendar date. Valid formats are: 
	//		YYYY DD MM HH MM
	//		YYYY DD MM -1 -1
	//		-1	 DD MM HH MM
	//		-1	 DD MM -1 -1
	bool isValidDateTime();

};

#endif