#include "DateTimeVerification.h"

bool DateTimeVerification::isValidYearRange(){
	int year = dateTimeObjectToVerify.getYear();
	if (year >= MIN_YEAR && year <= MAX_YEAR) {
		return 1;
	} else {
		return 0;
	}
}

bool DateTimeVerification::isValidMonthRange(){
	int month = dateTimeObjectToVerify.getMonth();
	if (month >= MIN_MONTH && month <= MAX_MONTH) {
		return 1;
	} else {
		return 0;
	}
}

bool DateTimeVerification::isValidDayRange(){
	int day = dateTimeObjectToVerify.getDay();
	if (day >= MIN_DAY && day <= MAX_DAY) {
		return 1;
	} else {
		return 0;
	}
}

bool DateTimeVerification::isValidDate(){
	if (isValidYearRange() && isValidMonthRange() && isValidDayRange()) {
		return 1;
	} else {
		return 0;
	}
}

bool DateTimeVerification::isValidHourRange(){
	int hour = dateTimeObjectToVerify.getHour();
	if (hour >= MIN_HOUR && hour <= MAX_HOUR) {
		return 1;
	} else {
		return 0;
	}
}

bool DateTimeVerification::isValidMinuteRange() {
	int minute = dateTimeObjectToVerify.getMinute();
	if (minute >= MIN_MINUTE && minute <= MAX_MINUTE) {
		return 1;
	} else {
		return 0;
	}
}

bool DateTimeVerification::isValidTime(){
	if (isValidHourRange() && isValidMinuteRange()) {
		return 1;
	} else {
		return 0;
	}
}

DateTimeVerification::DateTimeVerification(DateTime dateTimeObject) {
	dateTimeObjectToVerify = dateTimeObject;
}

bool DateTimeVerification::isValidDateTime() {
	if (isValidDate() && isValidTime()) {
		return 1;
	} else {
		return 0;
	}
}