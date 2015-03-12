#include "DateTimeVerification.h"

const int MIN_YEAR;
const int MAX_YEAR;
const int MIN_MONTH;
const int MAX_MONTH;
const int MIN_DAY;
const int MAX_DAY;

const int MIN_HOUR;
const int MAX_HOUR;
const int MIN_MINUTE;
const int MAX_MINUTE;
const int EMPTYFIELD_DATETIME;

DateTimeVerification::DateTimeVerification(DateTime dateTimeObject) {
	_dateTimeObjectToVerify = dateTimeObject;
	_year = _dateTimeObjectToVerify.getYear();
	_month = _dateTimeObjectToVerify.getMonth();
	_day = _dateTimeObjectToVerify.getDay();
	_hour = _dateTimeObjectToVerify.getHour();
	_minute = _dateTimeObjectToVerify.getMinute();
}

bool DateTimeVerification::isValidYearRange(){
	if (_year >= MIN_YEAR && _year <= MAX_YEAR) {
		return true;
	} else if (_year == EMPTYFIELD_DATETIME) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidMonthRange(){
	if (_month >= MIN_MONTH && _month <= MAX_MONTH) {
		return true;
	} else if (_month == EMPTYFIELD_DATETIME) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidDayRange(){
	if (_day >= MIN_DAY && _day <= MAX_DAY) {
		return true;
	} else if (_day == EMPTYFIELD_DATETIME) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidHourRange(){
	if (_hour >= MIN_HOUR && _hour <= MAX_HOUR) {
		return true;
	} else if (_hour == EMPTYFIELD_DATETIME) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidMinuteRange() {
	if (_minute >= MIN_MINUTE && _minute <= MAX_MINUTE) {
		return true;
	} else if (_minute == EMPTYFIELD_DATETIME) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::hasYear() {
	if (isValidYearRange() && _year == -1) {
		return false;
	} else { 
		return true; 
	}
}

bool DateTimeVerification::hasMonth() {
	if (isValidMonthRange() && _month == -1) {
		return false;
	} else { 
		return true; 
	}
}

bool DateTimeVerification::hasDay() {
	if (isValidDayRange() && _day == -1) {
		return false;
	} else { 
		return true; 
	}
}

bool DateTimeVerification::hasHour() {
	if (isValidHourRange() && _hour == -1) {
		return false;
	} else {
		return true;
	}
}

bool DateTimeVerification::hasMinute() {
	if (isValidMinuteRange() && _minute == -1) {
		return false;
	} else { 
		return true; 
	}
}

////					   ////
////PUBLIC FUNCTIONS BELOW ////
////					   ////

bool DateTimeVerification::isValidDate(){
	if (isValidYearRange() && hasMonth() && hasDay()) {
		return true;
	}
	else if (_year == -1 && _month == -1 && _day == -1) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidTime(){
	if (hasHour() && isValidMinuteRange()) {
		return true;
	} else if (_hour == -1 && _minute == -1) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidDateTime() {
	if (isValidDate() && isValidTime()) {
		return true;
	} else {
		return false;
	}
}