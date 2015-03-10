#ifndef DATETIME_VERIFICATION_H
#define DATETIME_VERIFICATION_H

#include <string>
#include <iostream>
#include "..\iStorage\DateTime.h"
using namespace std;

static const int MIN_YEAR = 0;
static const int MAX_YEAR = 9999;
static const int MIN_MONTH = 1;
static const int MAX_MONTH = 12;
static const int MIN_DAY = 1;
static const int MAX_DAY = 31;
static const string ERROR_INVALID_DATE = "Error: Invalid Date Specified.\n";

static const int MIN_HOUR = 0;
static const int MAX_HOUR = 23;
static const int MIN_MINUTE = 0;
static const int MAX_MINUTE = 59;
static const string ERROR_INVALID_TIME = "Error: Invalid Time Specified.\n";

class DateTimeVerification {
private:
	DateTime dateTimeObjectToVerify;
	void setDateTimeObject(const DateTime dateTimeObject);

	bool isValidYearRange();
	bool isValidMonthRange();
	bool isValidDayRange();
	bool isValidDate();

	bool isValidHourRange();
	bool isValidMinuteRange();
	bool isValidTime();

public:
	bool isValidDateTime();
};

#endif