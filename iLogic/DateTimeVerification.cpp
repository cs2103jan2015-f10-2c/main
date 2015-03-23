#include "DateTimeVerification.h"

const int DateTimeVerification::MIN_YEAR = 0;
const int DateTimeVerification::MAX_YEAR = 9999;
const int DateTimeVerification::MIN_MONTH = 1;
const int DateTimeVerification::MAX_MONTH = 12;
const int DateTimeVerification::MIN_DAY = 1;
const int DateTimeVerification::MAX_DAY = 31;
const int DateTimeVerification::MIN_HOUR = 0;
const int DateTimeVerification::MAX_HOUR = 23;
const int DateTimeVerification::MIN_MINUTE = 0;
const int DateTimeVerification::MAX_MINUTE = 59;
const int DateTimeVerification::EMPTYFIELD_DATETIME = -1;

const int DateTimeVerification::DAY_29 = 29;
const int DateTimeVerification::DAY_30 = 30;
const int DateTimeVerification::DAY_31 = 31;
const int DateTimeVerification::MONTH_FEB = 2;
const int DateTimeVerification::MONTH_APR = 4;
const int DateTimeVerification::MONTH_JUN = 6;
const int DateTimeVerification::MONTH_SEP = 9;
const int DateTimeVerification::MONTH_NOV = 11;
const int DateTimeVerification::YEAR_4 = 4;
const int DateTimeVerification::YEAR_100 = 100;
const int DateTimeVerification::YEAR_400 = 400;

DateTimeVerification::DateTimeVerification(DateTime dateTimeObject) {
	_dateTimeObjectToVerify = dateTimeObject;
	_year = _dateTimeObjectToVerify.getYear();
	_month = _dateTimeObjectToVerify.getMonth();
	_day = _dateTimeObjectToVerify.getDay();
	_hour = _dateTimeObjectToVerify.getHour();
	_minute = _dateTimeObjectToVerify.getMinute();
}

bool DateTimeVerification::isValidDateTimeValues() {
	if (isValidYearRange() &&
		isValidMonthRange() &&
		isValidDayRange() &&
		isValidHourRange() &&
		isValidMinuteRange()) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::isValidYearRange(){
	if (_year >= MIN_YEAR && _year <= MAX_YEAR) {
		return true;
	}
	else if (_year == EMPTYFIELD_DATETIME) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::isValidMonthRange(){
	if (_month >= MIN_MONTH && _month <= MAX_MONTH) {
		return true;
	}
	else if (_month == EMPTYFIELD_DATETIME) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::isValidDayRange(){
	if (_day >= MIN_DAY && _day <= MAX_DAY) {
		return true;
	}
	else if (_day == EMPTYFIELD_DATETIME) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::isValidHourRange(){
	if (_hour >= MIN_HOUR && _hour <= MAX_HOUR) {
		return true;
	}
	else if (_hour == EMPTYFIELD_DATETIME) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::isValidMinuteRange() {
	if (_minute >= MIN_MINUTE && _minute <= MAX_MINUTE) {
		return true;
	}
	else if (_minute == EMPTYFIELD_DATETIME) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::hasYearMonthDay() {
	if (hasYear() && hasMonth() && hasDay()) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::hasMonthDay() {
	if (!hasYear() && hasMonth() && hasDay()) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::hasYear() {
	if (!isValidYearRange()) {
		return false;
	}
	else if (_year == EMPTYFIELD_DATETIME) {
		return false;
	}
	else {
		return true;
	}
}

bool DateTimeVerification::hasMonth() {
	if (!isValidMonthRange()) {
		return false;
	}
	else if (_month == EMPTYFIELD_DATETIME) {
		return false;
	}
	else {
		return true;
	}
}

bool DateTimeVerification::hasDay() {
	if (!isValidDayRange()) {
		return false;
	}
	else if (_day == EMPTYFIELD_DATETIME) {
		return false;
	}
	else {
		return true;
	}
}

bool DateTimeVerification::hasHourMinute() {
	if (hasHour() && hasMinute()) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::hasHour() {
	if (_hour >= MIN_HOUR && _hour <= MAX_HOUR) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::hasMinute() {
	if (_minute >= MIN_MINUTE && _minute <= MAX_MINUTE) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTimeVerification::isActualYearMonthDayDate() {
	if ((_day == DAY_31) && (_month == MONTH_FEB || _month == MONTH_APR || _month == MONTH_JUN || _month == MONTH_SEP || _month == MONTH_NOV)) {
		return false;
	}
	else if ((_day == DAY_30) && (_month == MONTH_FEB)) {
		return false;
	}
	else if ((_month == MONTH_FEB) && (_day == DAY_29) && (_year % YEAR_4 != 0)){
		return false;
	}
	else if ((_month == MONTH_FEB) && (_day == DAY_29) && (_year % YEAR_400 == 0)) {
		return true;
	}
	else if ((_month == MONTH_FEB) && (_day == DAY_29) && (_year % YEAR_100 == 0)) {
		return false;
	}
	else if ((_month == MONTH_FEB) && (_day == DAY_29) && (_year % YEAR_4 == 0)){
		return true;
	}
	else {
		return true;
	}
}


bool DateTimeVerification::isValidTime(){
	if (hasHour() && hasMinute()) {
		return true;
	}
	else if (!hasHour() && !hasMinute()) {
		return true;
	}
	else {
		return false;
	}
}

////					   ////
////PUBLIC FUNCTIONS BELOW ////
////					   ////


bool DateTimeVerification::isValidDateTime() {
	if (isValidDateTimeValues()) {
		if (hasYearMonthDay() && isActualYearMonthDayDate() && isValidTime()) {
			return true;
		} else if (!hasYear() && !hasMonth() && !hasDay() && !hasHour() && !hasMinute()) {
			return true;
		}
//		else if (hasMonthDay() && isValidTime()) {
//			return true;
//		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}