//	Item (Tasks, Deadlines, Events)
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

class Item
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
	Item();

	//	Destructor
	//	Pre:
	//	Post:
	~Item();

	//	Sets the attribute
	//	Pre:	ItemName is a string
	//			Start Time and End Time are DateTime objects
	//			Description is a string
	//			Priority is a character - L, M, or H
	//			Label is a character - P, O, or M
	//			Completion is a boolean value - true if item is completed
	//	Post:	_(attribute) is set, and value is returned
	string setItemName(string);
	DateTime setStartTime(DateTime);
	DateTime setEndTime(DateTime);
	string setDescription(string);
	char setPriority(char);
	char setLabel(char);
	bool setCompletion(bool);

	//	Sets the attribute
	//	Pre:	Attribute has been previously set.
	//	Post:	_(attribute) is returned
	string getItemName(string);
	DateTime getStartTime(DateTime);
	DateTime getEndTime(DateTime);
	string getDescription(string);
	char getPriority(char);
	char getLabel(char);
	bool getCompletion(bool);
};