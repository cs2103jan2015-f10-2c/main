//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include <string>
#include <vector>
#include "..\Item\Item.h"
using namespace std;

class Schedule
{
private:
	vector <Item> _schedule;

public:
	//	Constructor
	//	Pre:	Nil
	//	Post:	Empty schedule is created without any Item objects
	Schedule();

	//	Destructor
	//	Pre:	Nil
	//	Post:	Schedule is destroyed, along with the items stored in it
	~Schedule();

	//	Adds an item to the schedule

	//	Deletes an item from the schedule

	//	Sorts the schedule according to date

	//	Sorts the schedule according to last updated date

	//	Sorts the schedule according to priority
	//	Post:	Sequence as follows - high, medium, low, none

	//
};