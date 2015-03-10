//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"
using namespace std;

class Schedule
{
private:
	vector <Item> _schedule;

public:
	//	Constructor
	//	Pre:    Nil
	//	Post:	Empty schedule is created without any Item objects
	Schedule();

	//	Destructor
	//	Pre:    Nil
	//	Post:	Schedule is destroyed, along with the items stored in it
	~Schedule();

	//	Retrieves the entire schedule
	//	Pre:	Nil
	//	Post:	Constant reference to the schedule is returned
	const vector<Item>& retrieveSchedule();

	//	Retrieves the size of the schedule
	//	Pre:	Schedule exists
	//	Post:	Returns the number of items within schedule
	unsigned int getSizeOfSchedule();

	//	Retrieves vector index given itemID
	//	Pre:	Valid itemID
	//	Post:	Vector index is returned
	unsigned int findVectorIndexGivenItemID(unsigned int);

	//	Adds an item to the schedule
	//	Pre:	Valid Item object
	//	Post:	Item is added to the schedule; itemID is returned
	unsigned int addItem(Item);

	//	Deletes an item from the schedule
	//	Pre:	Valid itemID
	//	Post:	Deleted item is returned
	Item deleteItem(unsigned int);

	


	//    Sorts the schedule according to date
	//vector<Item>& sortScheduleByDate();

	//    Sorts the schedule according to last updated date
	//vector<Item>& sortScheduleByLastUpdate();

	//    Sorts the schedule according to priority
	//    Post:    Sequence as follows - high, medium, low, none
	//vector<Item>& sortScheduleByPriority();

	//    Returns only items of a certain priority
	//vector<Item>& returnScheduleFilteredByPriority();

	//    Returns only items spanning a certain date
	//vector<Item>& returnScheduleFilteredByDate();

	//    Returns only items with a certain label
	//vector<Item>& returnScheduleFilteredByLabel();

	//    Returns only items that are completed or otherwise
	//vector<Item>& returnScheduleFilteredByCompletion();

};

#endif