//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include "PStorage.h"

//	Constructor
DateTime::DateTime() { }

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

//	Sets the day of the week
int DateTime::setDayOfTheWeek(int DayOfTheWeek) {
	_dayOfTheWeek = DayOfTheWeek;
	return _dayOfTheWeek;
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

//	Returns the day of the week
int DateTime::getDayOfTheWeek() {
	return _dayOfTheWeek;
}