//	DateTime (Date and Time for all Items)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include <string>
#include <vector>
using namespace std;

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