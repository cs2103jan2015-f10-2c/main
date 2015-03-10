//	DateTime (Date and Time for all Items)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <vector>
using namespace std;

class DateTime
{
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;

public:
	//	Constructor
	//	Pre:	Nil
	//	Post:	DateTime object is created; attributes have no default assigned values
	DateTime();

	//	Overloaded Constructor with YYYY MM DD HH MM
	//	Pre:	Year, Month, Day, Hour, and Minute are valid integers within range
	//	Post:	DateTime object is created; all attributes are assigned accordingly
	DateTime(int, int, int, int, int);

	//	Overloaded Constructor with YYYY MM DD
	//	Pre:	Year, Month, Day are valid integers within range
	//	Post:	DateTime object is created; only YYYY MM DD attributes are assigned
	DateTime(int, int, int);

	//	Destructor
	//	Pre:	Nil
	//	Post:	DateTime object is destroyed
	~DateTime();

	//	Sets the attribute
	//	Pre:	Year ranges from 0 to 9999
	//			Month ranges from 1 to 12
	//			Day ranges from 1 to 31
	//			Hour ranges from 0 to 23
	//			Minute ranges from 0 to 59
	//	Post:	_(attribute) is set, and value is returned
	int setYear(int);
	int setMonth(int);
	int setDay(int);
	int setHour(int);
	int setMinute(int);

	//	Retrieves the attribute
	//	Pre:	Attribute has been previously set
	//	Post:	_(attribute) is returned
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();

	//	Checks if the attribute is in its valid range
	//	Pre:	
	//	Post:	Returns true if (false otherwise):
	//			Year ranges from 0 to 9999
	//			Month ranges from 1 to 12
	//			Day ranges from 1 to 31
	//			Hour ranges from 0 to 23
	//			Minute ranges from 0 to 59
	bool isValidYearRange(int);
	bool isValidMonthRange(int);
	bool isValidDayRange(int);
	bool isValidDate(int, int, int);
	bool isValidHourRange(int);
	bool isValidMinuteRange(int);
};

#endif