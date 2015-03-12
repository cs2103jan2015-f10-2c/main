#ifndef DATETIME_VERIFICATION_H
#define DATETIME_VERIFICATION_H

#include <string>
#include <iostream>
#include "..\iStorage\DateTime.h"
using namespace std;

class DateTimeVerification {
private:
	static const int MIN_YEAR = 0;
	static const int MAX_YEAR = 9999;
	static const int MIN_MONTH = 1;
	static const int MAX_MONTH = 12;
	static const int MIN_DAY = 1;
	static const int MAX_DAY = 31;
	static const int MIN_HOUR = 0;
	static const int MAX_HOUR = 23;
	static const int MIN_MINUTE = 0;
	static const int MAX_MINUTE = 59;
	static const int EMPTYFIELD_DATETIME;

	DateTime _dateTimeObjectToVerify;
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;

	bool isValidYearRange();
	bool isValidMonthRange();
	bool isValidDayRange();

	bool isValidHourRange();
	bool isValidMinuteRange();

	bool hasYear();
	bool hasMonth();
	bool hasDay();
	bool hasHour();
	bool hasMinute();

public:
	DateTimeVerification(DateTime dateTimeObject);

	bool isValidDate();
	bool isValidTime();
	bool isValidDateTime();

};

#endif