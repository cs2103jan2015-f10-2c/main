//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"
//	#include "History.h"
using namespace std;

class Schedule
{
private:
	vector <Item> _schedule;
	vector <Item> _filteredSchedule;
//	History _scheduleHistory;

	//	Checks if an itemID matches the itemID of an item in a given vector cell
	//	Pre:	Valid itemID, valid vectorIndex
	//	Post:	Returns true if the itemID matches; false otherwise
	bool isMatchingItemID(unsigned int, unsigned int);

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
	//	Post:	Constant reference to vector of Item is returned.
	const vector <Item>& retrieveSchedule();

	//	Retrieves the size of the schedule
	//	Pre:	Nil
	//	Post:	Returns the number of items within _schedule
	unsigned int getSizeOfSchedule();

	//	Retrieves vector index given itemID
	//	Pre:	Valid itemID
	//	Post:	Vector index is returned
	unsigned int findVectorIndexGivenItemID(unsigned int);

	//	Adds an item to the schedule
	//	Pre:	Valid Item object
	//	Post:	Item is added to the schedule; full details of the item is returned (string)
	string addItem(Item*);

	//	Retrieves a copy of an existing item in the schedule
	//	Pre:	Valid itemID
	//	Post:	Returns a copy of the existing item
	Item retrieveItem(unsigned int);

	//	Edits an existing item in the schedule
	//	Pre:	Valid itemID, valid Item object
	//	Post:	Given itemID, replaces existing item with updated item
	string replaceItem(Item*, unsigned int);

	//	Deletes an item from the schedule
	//	Pre:	Valid itemID
	//	Post:	Deleted item is returned
	string deleteItem(unsigned int);

	//	Filters the schedule by Priority
	//	Pre:	Valid priority - L, M, or H
	//	Post:	Constant reference to the filtered schedule is returned
	const vector<Item>& retrieveScheduleFilteredByPriority(char);

	//	Filters the schedule by Label
	//	Pre:	Valid priority - P, O, or M
	//	Post:	Constant reference to the filtered schedule is returned
	const vector<Item>& retrieveScheduleFilteredByLabel(char);

	//	Filters the schedule by Completion Status
	//	Pre:	Valid completion status - true, false
	//	Post:	Constant reference to the filtered schedule is returned
	const vector<Item>& retrieveScheduleFilteredByCompletion(bool);

	//    Returns only items spanning a certain date
	//vector<Item>& returnScheduleFilteredByDate();
	
	//    Sorts the schedule according to date
	//vector<Item>& sortScheduleByDate();

	//    Sorts the schedule according to last updated date
	//vector<Item>& sortScheduleByLastUpdate();

	//    Sorts the schedule according to priority
	//    Post:    Sequence as follows - high, medium, low, none
	//vector<Item>& sortScheduleByPriority();
};

#endif