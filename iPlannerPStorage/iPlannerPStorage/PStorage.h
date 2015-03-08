//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

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
	int _dayOfTheWeek;

public:
	//	Constructor
	//	Pre:	
	//	Post:	
	DateTime();

	//	Destructor
	//	Pre:	
	//	Post:	
	~DateTime();
	
	//	Sets the attribute
	//	Pre:	Year ranges from 0 to 9999
	//			Month ranges from 1 to 12
	//			Day ranges from 1 to 31
	//			Hour ranges from 0 to 23
	//			Minute ranges from 0 to 59
	//			Day of the week ranges from 1 to 7
	//	Post:	_(attribute) is set, and value is returned
	int setYear (int);
	int setMonth(int);
	int setDay(int);
	int setHour(int);
	int setMinute(int);
	int setDayOfTheWeek(int);

	//	Retrieves the attribute
	//	Pre:	Attribute has been previously set
	//	Post:	_(attribute) is returned
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getDayOfTheWeek();

	//	Checks if the attribute is in its valid range
	//	Pre:	
	//	Post:	Returns true if (false otherwise):
	//			Year ranges from 0 to 9999
	//			Month ranges from 1 to 12
	//			Day ranges from 1 to 31
	//			Hour ranges from 0 to 23
	//			Minute ranges from 0 to 59
	//			Day of the week ranges from 1 to 7
	bool isValidYearRange(int);
	bool isValidMonthRange(int);
	bool isValidDayRange(int);
	bool isValidHourRange(int);
	bool isValidMinuteRange(int);
	bool isValidDayOfTheWeekRange(int);
};
/*
class TimedItem
{
private:
	string _itemName;
	DateTime _startTime;
	DateTime _endTime;
	string _description;
	char _priority;
	char _label;
	bool _isCompleted;

public:
	//	Constructor
	//	Pre:	
	//	Post:	
	TimedItem();

	//	Destructor
	//	Pre:	
	//	Post:	
	~TimedItem();
};

class fullSchedule
{
private:
	vector <TimedItem> _schedule;

public:
	//	Constructor
	//	Pre:	
	//	Post:	
	fullSchedule();

	//	Destructor
	//	Pre:	
	//	Post:	
	~fullSchedule();
};
*/