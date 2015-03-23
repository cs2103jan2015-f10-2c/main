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
	vector <Item> _displaySchedule;
//	History _scheduleHistory;

	//	Checks if an itemID matches the itemID of an item in a given vector cell
	//	Pre:	Valid itemID, valid vectorIndex
	//	Post:	Returns true if the itemID matches; false otherwise
	bool isMatchingItemID(unsigned int, unsigned int);

	//	Retrieves schedule vector index given item ID
	//	Pre:	Valid itemID
	//	Post:	Schedule vector index is returned
	unsigned int findVectorIndexGivenItemID(unsigned int);

	//	Retrieves item ID given display vector index
	//	Pre:	Display vector is not sorted by the other components
	//	Post:	Returns item ID of the item selected
	unsigned int findItemIDGivenDisplayVectorIndex(unsigned int);

public:
	//	Constructor
	//	Pre:    Nil
	//	Post:	Empty schedule is created without any Item objects
	Schedule();

	//	Destructor
	//	Pre:    Nil
	//	Post:	Schedule is destroyed, along with the items stored in it
	~Schedule();

	//	Retrieves the size of the schedule
	//	Pre:	Nil
	//	Post:	Returns the number of items within _schedule
	unsigned int getSizeOfSchedule();

	//	Retrieves the size of the display schedule
	//	Pre:	Nil
	//	Post:	Returns the number of items within _displaySchedule
	unsigned int getSizeOfDisplaySchedule();

	//	Adds an item to the schedule
	//	Pre:	Valid Item object
	//	Post:	Item is added to the schedule
	//			Full details of the item is returned (string)
	string addItem(Item*);

	//	Retrieves a copy of an existing item in the schedule given Item ID
	//	Pre:	Valid itemID
	//	Post:	Given itemID, a copy of the existing item is returned
	Item retrieveItemGivenItemID(unsigned int);

	//	Retrieves a copy of an existing item in the schedule given the item's display vector index
	//	Pre:	Valid display vector index (display vector not modified before displaying to user)
	//	Post:	Given display vector index, a copy of the existing item is returned
	Item retrieveItemGivenDisplayVectorIndex(unsigned int);

	//	Replaces an existing item in the schedule given Item ID
	//	Pre:	Valid itemID, valid Item object
	//	Post:	Given itemID, replaces existing item with updated item
	string replaceItemGivenItemID(Item*, unsigned int);

	//	Replaces an existing item in the schedule given the item's display vector index
	//	Pre:	Valid display vector index (display vector not modified before displaying to user)
	//	Post:	Given display vector index, replaces existing item with updated item
	string replaceItemGivenDisplayVectorIndex(Item*, unsigned int);
	
	//	Deletes an item from the schedule given Item ID
	//	Pre:	Valid itemID
	//	Post:	Given itemID, item is deleted and details are returned
	string deleteItemGivenItemID(unsigned int);
	
	//	Deletes an item from the schedule given item's display vector index
	//	Pre:	Valid display vector index (display vector not modified before displaying to user)
	//	Post:	Given display vector index, item is deleted and details are returned
	string deleteItemGivenDisplayVectorIndex(unsigned int);

	//	Retrieves the entire schedule
	//	Pre:	Nil
	//	Post:	Constant reference to vector of Item is returned.
	const vector <Item>& retrieveSchedule();





	/*
	//	Sorts the schedule by attribute (date - if any, item name, priority, completion status)
	//	Pre:	Valid date, if any - YYYY MM DD HH:MM or YYYY MM DD
	//			Valid item name (string)
	//			Valid priority, if any - P, O, M
	//			Valid completion status - true, false
	//	Post:	Constant reference to the sorted schedule is returned


	//	Filters the schedule by attribute (priority, label, or completion status)
	//	Pre:	Valid priority - L, M, or H
	//			Valid label - P, O, or M
	//			Valid completion status - true, false
	//	Post:	Constant reference to the filtered schedule is returned
	const vector<Item>& retrieveScheduleFilteredByPriority(char);
	const vector<Item>& retrieveScheduleFilteredByLabel(char);
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

	*/
};

#endif