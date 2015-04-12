#include <assert.h>
#include <exception>
#include "DateTimeVerification.h"

const int DateTimeVerification::DATETIME_VERIFICATION_MIN_YEAR = 0;
const int DateTimeVerification::DATETIME_VERIFICATION_MAX_YEAR = 9999;
const int DateTimeVerification::DATETIME_VERIFICATION_MIN_MONTH = 1;
const int DateTimeVerification::DATETIME_VERIFICATION_MAX_MONTH = 12;
const int DateTimeVerification::DATETIME_VERIFICATION_MIN_DAY = 1;
const int DateTimeVerification::DATETIME_VERIFICATION_MAX_DAY = 31;
const int DateTimeVerification::DATETIME_VERIFICATION_MIN_HOUR = 0;
const int DateTimeVerification::DATETIME_VERIFICATION_MAX_HOUR = 23;
const int DateTimeVerification::DATETIME_VERIFICATION_MIN_MINUTE = 0;
const int DateTimeVerification::DATETIME_VERIFICATION_MAX_MINUTE = 59;
const int DateTimeVerification::DATETIME_VERIFICATION_EMPTYFIELD_DATETIME = -1;
const int DateTimeVerification::DATETIME_VERIFICATION_INT_MINUS_TWO = -2;

const int DateTimeVerification::DATETIME_VERIFICATION_DAY_29 = 29;
const int DateTimeVerification::DATETIME_VERIFICATION_DAY_30 = 30;
const int DateTimeVerification::DATETIME_VERIFICATION_DAY_31 = 31;
const int DateTimeVerification::DATETIME_VERIFICATION_MONTH_FEB = 2;
const int DateTimeVerification::DATETIME_VERIFICATION_MONTH_APR = 4;
const int DateTimeVerification::DATETIME_VERIFICATION_MONTH_JUN = 6;
const int DateTimeVerification::DATETIME_VERIFICATION_MONTH_SEP = 9;
const int DateTimeVerification::DATETIME_VERIFICATION_MONTH_NOV = 11;
const int DateTimeVerification::DATETIME_VERIFICATION_YEAR_4 = 4;
const int DateTimeVerification::DATETIME_VERIFICATION_YEAR_100 = 100;
const int DateTimeVerification::DATETIME_VERIFICATION_YEAR_400 = 400;

const string DateTimeVerification::DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO = "Date/Time value less than -2";

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
	} else {
		return false;
	}
}

bool DateTimeVerification::isValidYearRange() {
	if (_year >= DATETIME_VERIFICATION_MIN_YEAR && _year <= DATETIME_VERIFICATION_MAX_YEAR) {
		return true;
	} else if (_year == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
		return true;
	} else {
		assert(_year > DATETIME_VERIFICATION_MAX_YEAR || _year < DATETIME_VERIFICATION_EMPTYFIELD_DATETIME);
		return false;
	}
}

bool DateTimeVerification::isValidMonthRange() {
	if (_month >= DATETIME_VERIFICATION_MIN_MONTH && _month <= DATETIME_VERIFICATION_MAX_MONTH) {
		return true;
	} else if (_month == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
		return true;
	} else {
		assert(_month > DATETIME_VERIFICATION_MAX_MONTH || _month < DATETIME_VERIFICATION_EMPTYFIELD_DATETIME);
		return false;
	}
}

bool DateTimeVerification::isValidDayRange() {
	if (_day >= DATETIME_VERIFICATION_MIN_DAY && _day <= DATETIME_VERIFICATION_MAX_DAY) {
		return true;
	} else if (_day == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
		return true;
	} else {
		assert(_day > DATETIME_VERIFICATION_MAX_DAY || _day < DATETIME_VERIFICATION_EMPTYFIELD_DATETIME);
		return false;
	}
}

bool DateTimeVerification::isValidHourRange() {
	if (_hour >= DATETIME_VERIFICATION_MIN_HOUR && _hour <= DATETIME_VERIFICATION_MAX_HOUR) {
		return true;
	} else if (_hour == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
		return true;
	} else {
		assert(_hour > DATETIME_VERIFICATION_MAX_HOUR || _hour < DATETIME_VERIFICATION_EMPTYFIELD_DATETIME);
		return false;
	}
}

bool DateTimeVerification::isValidMinuteRange() {
	if (_minute >= DATETIME_VERIFICATION_MIN_MINUTE && _minute <= DATETIME_VERIFICATION_MAX_MINUTE) {
		return true;
	} else if (_minute == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
		return true;
	} else {
		assert(_minute > DATETIME_VERIFICATION_MAX_HOUR || _minute < DATETIME_VERIFICATION_EMPTYFIELD_DATETIME);
		return false;
	}
}

bool DateTimeVerification::hasYearMonthDay() {
	if (hasYear() && hasMonth() && hasDay()) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::hasMonthDay() {
	if (!hasYear() && hasMonth() && hasDay()) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::hasYear() {
	try {
		if (!isValidYearRange()) {
			return false;
		} else if (_year == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
			return false;
		} else if (_year <DATETIME_VERIFICATION_INT_MINUS_TWO) {
			throw DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;
		} else {
			return true;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
}

bool DateTimeVerification::hasMonth() {
	try {
		if (!isValidMonthRange()) {
			return false;
		} else if (_month == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
			return false;
		} else if (_month <DATETIME_VERIFICATION_INT_MINUS_TWO) {
			throw DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;
		} else {
			return true;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
}

bool DateTimeVerification::hasDay() {
	try {
		if (!isValidDayRange()) {
			return false;
		} else if (_day == DATETIME_VERIFICATION_EMPTYFIELD_DATETIME) {
			return false;
		} else if (_day <DATETIME_VERIFICATION_INT_MINUS_TWO) {
			throw DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;
		} else {
			return true;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
}

bool DateTimeVerification::hasHourMinute() {
	try {
		if (hasHour() && hasMinute()) {
			return true;
		} else if (_hour < DATETIME_VERIFICATION_INT_MINUS_TWO || _minute < DATETIME_VERIFICATION_INT_MINUS_TWO) {
			throw DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;
		} else {
			return false;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
}

bool DateTimeVerification::hasHour() {
	try {
		if (_hour >= DATETIME_VERIFICATION_MIN_HOUR && _hour <= DATETIME_VERIFICATION_MAX_HOUR) {
			return true;
		} else if (_hour < DATETIME_VERIFICATION_INT_MINUS_TWO) {
			throw DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;
		} else {
			return false;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
}

bool DateTimeVerification::hasMinute() {
	try {
		if (_minute >= DATETIME_VERIFICATION_MIN_MINUTE && _minute <= DATETIME_VERIFICATION_MAX_MINUTE) {
			return true;
		} else if (_minute < DATETIME_VERIFICATION_INT_MINUS_TWO) {
			throw DATETIME_VERIFICATION_EXCEPTION_LESS_THAN_MINUS_TWO;
		} else {
			return false;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
}


bool DateTimeVerification::isValidTime() {
	if (hasHour() && hasMinute()) {
		return true;
	} else if (!hasHour() && !hasMinute()) {
		return true;
	} else {
		return false;
	}
}

bool DateTimeVerification::isActualYearMonthDayDate() {
	if ((_day == DATETIME_VERIFICATION_DAY_31) && (_month == DATETIME_VERIFICATION_MONTH_FEB || _month == DATETIME_VERIFICATION_MONTH_APR || _month == DATETIME_VERIFICATION_MONTH_JUN || _month == DATETIME_VERIFICATION_MONTH_SEP || _month == DATETIME_VERIFICATION_MONTH_NOV)) {
		return false;
	} else if ((_day == DATETIME_VERIFICATION_DAY_30) && (_month == DATETIME_VERIFICATION_MONTH_FEB)) {
		return false;
	} else if ((_month == DATETIME_VERIFICATION_MONTH_FEB) && (_day == DATETIME_VERIFICATION_DAY_29) && (_year % DATETIME_VERIFICATION_YEAR_4 != 0)) {
		return false;
	} else if ((_month == DATETIME_VERIFICATION_MONTH_FEB) && (_day == DATETIME_VERIFICATION_DAY_29) && (_year % DATETIME_VERIFICATION_YEAR_400 == 0)) {
		return true;
	} else if ((_month == DATETIME_VERIFICATION_MONTH_FEB) && (_day == DATETIME_VERIFICATION_DAY_29) && (_year % DATETIME_VERIFICATION_YEAR_100 == 0)) {
		return false;
	} else if ((_month == DATETIME_VERIFICATION_MONTH_FEB) && (_day == DATETIME_VERIFICATION_DAY_29) && (_year % DATETIME_VERIFICATION_YEAR_4 == 0)) {
		return true;
	} else {
		return true;
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
		} else {
			return false;
		}
	} else {
		return false;
	}
}