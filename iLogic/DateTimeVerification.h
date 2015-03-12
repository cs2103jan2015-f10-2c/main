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
	static const int MAX_HOUR ;
	static const int MIN_MINUTE;
	static const int MAX_MINUTE;
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