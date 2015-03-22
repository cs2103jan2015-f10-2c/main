#ifndef DATETIME_VERIFICATION_H
#define DATETIME_VERIFICATION_H

#include <string>
#include <iostream>
#include "..\iStorage\DateTime.h"
using namespace std;

class DateTimeVerification {

private:

	static const int MIN_YEAR;
	static const int MAX_YEAR;
	static const int MIN_MONTH;
	static const int MAX_MONTH;
	static const int MIN_DAY;
	static const int MAX_DAY;
	static const int MIN_HOUR;
	static const int MAX_HOUR;
	static const int MIN_MINUTE;
	static const int MAX_MINUTE;
	static const int EMPTYFIELD_DATETIME;

	static const int DAY_29;
	static const int DAY_30;
	static const int DAY_31;
	static const int MONTH_FEB;
	static const int MONTH_APR;
	static const int MONTH_JUN;
	static const int MONTH_SEP;
	static const int MONTH_NOV;
	static const int YEAR_4;
	static const int YEAR_100;
	static const int YEAR_400;


	DateTime _dateTimeObjectToVerify;
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;

	/////////////////////////////
	//REMOVE THIS AFTER TESTING//
	////////////////////////////
public:

	// LEVEL 1 of SLAP
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


	// LEVEL 2 of SLAP
	// This group of functions goes on to check if the
	// individual year/month/day values come together as
	// a valid date format.
	// i.e. DD MM YYYY or DD MM -1
	bool hasYearMonthDay();
	bool hasMonthDay();
	bool hasYear();
	bool hasMonth();
	bool hasDay();

	bool hasHourMinute();
	bool hasHour();
	bool hasMinute();

	bool isActualYearMonthDayDate();
	bool isValidTime();

public:

	DateTimeVerification(DateTime dateTimeObject);

	bool isValidDateTime();

};

#endif