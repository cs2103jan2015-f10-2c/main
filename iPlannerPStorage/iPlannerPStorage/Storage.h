//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include <string>
#include <vector>
#include <algorithm>
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
	unsigned int addItem(Item);

	//	Deletes an item from the schedule
	Item deleteItem(unsigned int);

	//  getter for schedule
	vector<Item> getSchedule();

	//	Sorts the schedule according to date
	vector<Item>& sortScheduleByDate();

	//	Sorts the schedule according to last updated date
	vector<Item>& sortScheduleByLastUpdate();

	//	Sorts the schedule according to priority
	//	Post:	Sequence as follows - high, medium, low, none
	vector<Item>& sortScheduleByPriority();

	//	Returns only items of a certain priority
	vector<Item>& returnScheduleFilteredByPriority();

	//	Returns only items spanning a certain date
	vector<Item>& returnScheduleFilteredByDate();

	//	Returns only items with a certain label
	vector<Item>& returnScheduleFilteredByLabel();

	//	Returns only items that are completed or otherwise
	vector<Item>& returnScheduleFilteredByCompletion();
};