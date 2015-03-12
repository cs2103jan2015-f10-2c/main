#include "DateTimeVerification.h"

const int DateTimeVerification::MIN_YEAR = 0;
const int DateTimeVerification::MAX_YEAR = 9999;
const int DateTimeVerification::MIN_MONTH= 1;
const int DateTimeVerification::MAX_MONTH = 12;
const int DateTimeVerification::MIN_DAY = 1;
const int DateTimeVerification::MAX_DAY = 31;
const int DateTimeVerification::MIN_HOUR = 0;
const int DateTimeVerification::MAX_HOUR = 23;
const int DateTimeVerification::MIN_MINUTE = 0;
const int DateTimeVerification::MAX_MINUTE = 59;
const int DateTimeVerification::EMPTYFIELD_DATETIME = -1;

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