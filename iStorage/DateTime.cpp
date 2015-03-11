//	DateTime (Date and Time for all Items)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "DateTime.h"

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

//	Constructor
DateTime::DateTime() { }

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
}

//	Destructor
DateTime::~DateTime() { }

//	Sets the year
int DateTime::setYear(int year) {
	_year = year;
	return _year;
}

//	Sets the month
int DateTime::setMonth(int month) {
	_month = month;
	return _month;
}

//	Sets the day of the month
int DateTime::setDay(int day) {
	_day = day;
	return _day;
}

//	Sets the hour of the day (in 24-hour format)
int DateTime::setHour(int hour) {
	_hour = hour;
	return _hour;
}

//	Sets the minute of the hour
int DateTime::setMinute(int minute) {
	_minute = minute;
	return _minute;
}

//	Retrieves the year
int DateTime::getYear() {
	return _year;
}

//	Returns the month
int DateTime::getMonth() {
	return _month;
}

//	Returns the day of the month
int DateTime::getDay() {
	return _day;
}

//	Returns the hour of the day (24-hour format)
int DateTime::getHour() {
	return _hour;
}

//	Returns the minute
int DateTime::getMinute() {
	return _minute;
}

//	Checks if year ranges from 0 to 9999
bool DateTime::isValidYearRange(int year) {
	if (year >= MIN_YEAR && year <= MAX_YEAR) {
		return true;
	}
	else {
		return false;
	}
}

//	Checks if month ranges from 1 to 12
bool DateTime::isValidMonthRange(int month) {
	if (month >= MIN_MONTH && month <= MAX_MONTH) {
		return true;
	}
	else {
		return false;
	}
}

//	Checks if day ranges from 1 to 31
bool DateTime::isValidDayRange(int day) {
	if (day >= MIN_DAY && day <= MAX_DAY) {
		return true;
	}
	else {
		return false;
	}
}

//	Checks if the entire date is valid (inclusive of year, month, and day)
bool DateTime::isValidDate(int year, int month, int day) {
	return 0;
}

//	Checks if hour ranges from 0 to 23
bool DateTime::isValidHourRange(int hour) {
	if (hour >= MIN_HOUR && hour <= MAX_HOUR) {
		return true;
	}
	else {
		return false;
	}
}

//	Checks if minute ranges from 0 to 59
bool DateTime::isValidMinuteRange(int minute) {
	if (minute >= MIN_MINUTE && minute <= MAX_MINUTE) {
		return true;
	}
	else {
		return false;
	}
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
	}
	else if (_month != secondaryDateTime.getMonth()){
		return (_month > secondaryDateTime.getMonth());
	}
	else if (_day != secondaryDateTime.getDay()) {
		return (_day > secondaryDateTime.getDay());
	}
	else if (_hour != secondaryDateTime.getHour()) {
		return (_hour > secondaryDateTime.getHour());
}
	else if (_minute != secondaryDateTime.getMinute()) {
		return (_minute > secondaryDateTime.getMinute());
	}
	else {
		return false;
	}
}

//	Checks if current DateTime object is before another
bool DateTime::isBefore(DateTime secondaryDateTime) {
	if (_year != secondaryDateTime.getYear()) {
		return (_year < secondaryDateTime.getYear());
	}
	else if (_month != secondaryDateTime.getMonth()){
		return (_month < secondaryDateTime.getMonth());
	}
	else if (_day != secondaryDateTime.getDay()) {
		return (_day < secondaryDateTime.getDay());
	}
	else if (_hour != secondaryDateTime.getHour()) {
		return (_hour < secondaryDateTime.getHour());
	}
	else if (_minute != secondaryDateTime.getMinute()) {
		return (_minute < secondaryDateTime.getMinute());
	}
	else {
		return false;
	}
}

string DateTime::displayDateTime() {
	ostringstream output;

	output << _day << " "
		<< _month << " "
		<< _year << " "
		<< _hour << ":"
		<< _minute;

	return output.str();
}