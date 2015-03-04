//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include <string>
#include <vector>
using namespace std;

class DateTime
{
private:
	enum _dayOfTheWeek { monday, tuesday, wednesday, thursday, friday, saturday, sunday };
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