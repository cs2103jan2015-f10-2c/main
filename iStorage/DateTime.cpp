//	DateTime (Date and Time for all Items)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "DateTime.h"

const int DateTime::MIN_YEAR = 0;
const int DateTime::MAX_YEAR = 9999;
const int DateTime::MIN_MONTH = 1;
const int DateTime::MAX_MONTH = 12;
const int DateTime::MIN_DAY = 1;
const int DateTime::MAX_DAY = 31;
const int DateTime::MIN_HOUR = 0;
const int DateTime::MAX_HOUR = 23;
const int DateTime::MIN_MINUTE = 0;
const int DateTime::MAX_MINUTE = 59;
const int DateTime::EMPTYFIELD_DATETIME = -1;
const int DateTime::INDICATOR_FAILEDSETATTEMPT = -2;
const char DateTime::DISPLAY_SEPARATOR_DATE = '/';
const char DateTime::DISPLAY_SEPARATOR_TIME = ':';
const char DateTime::DISPLAY_SEPARATOR_DATETIME = ' ';
const char DateTime::DISPLAY_FILLER = '0';

//	Constructor
DateTime::DateTime() {
	_year = EMPTYFIELD_DATETIME;
	_month = EMPTYFIELD_DATETIME;
	_day = EMPTYFIELD_DATETIME;
	_hour = EMPTYFIELD_DATETIME;
	_minute = EMPTYFIELD_DATETIME;
}

//	Overloaded Constructor with YYYY MM DD HH MM
DateTime::DateTime(int year, int month, int day, int hour, int minute) {
	_year = year;
	_month = month;
	_day = day;
	_hour = hour;
	_minute = minute;
}

//	Overloaded Constructor with YYYY MM DD
DateTime::DateTime(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
	_hour = EMPTYFIELD_DATETIME;
	_minute = EMPTYFIELD_DATETIME;
}

//	Destructor
DateTime::~DateTime() {}

//	Sets the year
int DateTime::setYear(int year) {
	if (isValidYearRange(year)) {
		_year = year;
	} else {
		_year = INDICATOR_FAILEDSETATTEMPT;
	}
	return _year;
}

//	Sets the month
int DateTime::setMonth(int month) {
	if (isValidMonthRange(month)) {
		_month = month;
	} else {
		_month = INDICATOR_FAILEDSETATTEMPT;
	}
	return _month;
}

//	Sets the day of the month
int DateTime::setDay(int day) {
	if (isValidDayRange(day)) {
		_day = day;
	} else {
		_day = INDICATOR_FAILEDSETATTEMPT;
	}
	return _day;
}

//	Sets the hour of the day (in 24-hour format)
int DateTime::setHour(int hour) {
	if (isValidHourRange(hour)) {
		_hour = hour;
	} else {
		_hour = INDICATOR_FAILEDSETATTEMPT;
	}
	return _hour;
}

//	Sets the minute of the hour
int DateTime::setMinute(int minute) {
	if (isValidMinuteRange(minute)) {
		_minute = minute;
	} else {
		_minute = INDICATOR_FAILEDSETATTEMPT;
	}
	return _minute;
}

//	Retrieves the year
int DateTime::getYear() {
	return _year;
}

//	Retrieves the month
int DateTime::getMonth() {
	return _month;
}

//	Retrieves the day of the month
int DateTime::getDay() {
	return _day;
}

//	Retrieves the hour of the day (24-hour format)
int DateTime::getHour() {
	return _hour;
}

//	Retrieves the minute
int DateTime::getMinute() {
	return _minute;
}

//	Checks if year ranges from 0 to 9999
bool DateTime::isValidYearRange(int year) {
	if (year >= MIN_YEAR && year <= MAX_YEAR) {
		return true;
	} else {
		return false;
	}
}

//	Checks if month ranges from 1 to 12
bool DateTime::isValidMonthRange(int month) {
	if (month >= MIN_MONTH && month <= MAX_MONTH) {
		return true;
	} else {
		return false;
	}
}

//	Checks if day ranges from 1 to 31
bool DateTime::isValidDayRange(int day) {
	if (day >= MIN_DAY && day <= MAX_DAY) {
		return true;
	} else {
		return false;
	}
}

//	Checks if the entire date is valid (inclusive of year, month, and day)
bool DateTime::isValidDate(int year, int month, int day) {
	if (!isValidYearRange(year) || !isValidMonthRange(month) || !isValidDayRange(day)) {
		return false;
	} else if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) {
		return false;
	} else if ((day == 30) && (month == 2)) {
		return false;
	} else if ((month == 2) && (day == 29) && (year % 4 != 0)) {
		return false;
	} else if ((month == 2) && (day == 29) && (year % 400 == 0)) {
		return true;
	} else if ((month == 2) && (day == 29) && (year % 100 == 0)) {
		return false;
	} else if ((month == 2) && (day == 29) && (year % 4 == 0)) {
		return true;
	}

	return true;
}

//	Checks if hour ranges from 0 to 23
bool DateTime::isValidHourRange(int hour) {
	if (hour >= MIN_HOUR && hour <= MAX_HOUR) {
		return true;
	} else {
		return false;
	}
}

//	Checks if minute ranges from 0 to 59
bool DateTime::isValidMinuteRange(int minute) {
	if (minute >= MIN_MINUTE && minute <= MAX_MINUTE) {
		return true;
	} else {
		return false;
	}
}

//	Checks if entire time is valid
bool DateTime::isValidTime(int hour, int minute) {
	return (isValidHourRange(hour) && isValidMinuteRange(minute));
}

//	Checks if two DateTime objects are identical
bool DateTime::operator== (DateTime secondaryDateTime) {
	bool sameYear = (_year == secondaryDateTime.getYear());
	bool sameMonth = (_month == secondaryDateTime.getMonth());
	bool sameDay = (_day == secondaryDateTime.getDay());
	bool sameHour = (_hour == secondaryDateTime.getHour());
	bool sameMinute = (_minute == secondaryDateTime.getMinute());

	return (sameYear && sameMonth && sameDay && sameHour && sameMinute);
}

//	Checks if two DateTime objects are not identical
bool DateTime::operator!= (DateTime secondaryDateTime) {
	bool differentYear = (_year != secondaryDateTime.getYear());
	bool differentMonth = (_month != secondaryDateTime.getMonth());
	bool differentDay = (_day != secondaryDateTime.getDay());
	bool differentHour = (_hour != secondaryDateTime.getHour());
	bool differentMinute = (_minute != secondaryDateTime.getMinute());

	return (differentYear || differentMonth || differentDay || differentHour || differentMinute);
}

//	Checks if current DateTime object is after another
bool DateTime::isAfter(DateTime secondaryDateTime) {
	if (_year != secondaryDateTime.getYear()) {
		return (_year > secondaryDateTime.getYear());
	} else if (_month != secondaryDateTime.getMonth()) {
		return (_month > secondaryDateTime.getMonth());
	} else if (_day != secondaryDateTime.getDay()) {
		return (_day > secondaryDateTime.getDay());
	} else if (_hour != secondaryDateTime.getHour()) {
		return (_hour > secondaryDateTime.getHour());
	} else if (_minute != secondaryDateTime.getMinute()) {
		return (_minute > secondaryDateTime.getMinute());
	} else {
		return false;
	}
}

//	Checks if current DateTime object is before another
bool DateTime::isBefore(DateTime secondaryDateTime) {
	if (_year != secondaryDateTime.getYear()) {
		return (_year < secondaryDateTime.getYear());
	} else if (_month != secondaryDateTime.getMonth()) {
		return (_month < secondaryDateTime.getMonth());
	} else if (_day != secondaryDateTime.getDay()) {
		return (_day < secondaryDateTime.getDay());
	} else if (_hour != secondaryDateTime.getHour()) {
		return (_hour < secondaryDateTime.getHour());
	} else if (_minute != secondaryDateTime.getMinute()) {
		return (_minute < secondaryDateTime.getMinute());
	} else {
		return false;
	}
}

//	Returns string with YYYY MM DD
string DateTime::displayDate() {
	ostringstream displayOutput;

	displayOutput
		<< setw(4) << _year
		<< DISPLAY_SEPARATOR_DATE << setfill(DISPLAY_FILLER) << setw(2) << _month
		<< DISPLAY_SEPARATOR_DATE << setfill(DISPLAY_FILLER) << setw(2) << _day;

	return displayOutput.str();
}

//	Returns string with HH:MM
string DateTime::displayTime() {
	ostringstream displayOutput;

	displayOutput
		<< setfill(DISPLAY_FILLER) << setw(2) << _hour
		<< DISPLAY_SEPARATOR_TIME << setfill(DISPLAY_FILLER) << setw(2) << _minute;

	return displayOutput.str();
}

//	Returns date in YYYY MM DD, time in HH:MM, and both in YYYY MM DD HH:MM
string DateTime::displayDateTime() {
	ostringstream displayOutput;

	if (isValidDate(_year, _month, _day)) {
		displayOutput << displayDate();

		if (isValidTime(_hour, _minute)) {
			displayOutput << DISPLAY_SEPARATOR_DATETIME;
			displayOutput << displayTime();
		}
	} else if (isValidTime(_hour, _minute)) {
		displayOutput << displayTime();
	}

	return displayOutput.str();
}

//	Returns string with DD/MM/YYYY
string DateTime::displayDateForUser() {
	ostringstream displayOutput;

	displayOutput
		<< setw(2) << _day
		<< DISPLAY_SEPARATOR_DATE << setfill(DISPLAY_FILLER) << setw(2) << _month
		<< DISPLAY_SEPARATOR_DATE << setfill(DISPLAY_FILLER) << setw(4) << _year;

	return displayOutput.str();
}

//	Returns date in DD/MM/YYYY, time in HH:MM, and both in DD/MM/YYYY HH:MM
string DateTime::displayDateTimeForUser() {
	ostringstream displayOutput;

	if (isValidDate(_year, _month, _day)) {
		displayOutput << displayDateForUser();

		if (isValidTime(_hour, _minute)) {
			displayOutput << DISPLAY_SEPARATOR_DATETIME;
			displayOutput << displayTime();
		}
	} else if (isValidTime(_hour, _minute)) {
		displayOutput << displayTime();
	}

	return displayOutput.str();
}