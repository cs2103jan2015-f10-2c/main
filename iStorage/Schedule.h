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

	//	Checks how an item compares with another according to the item's attribute
	//			isEarlierThan uses start time, if any, else uses end time, if any
	//			isAlphabeticallySmallerThan uses the items' item name, regardless of case
	//	Pre:	Valid Item objects
	//	Post:	Returns if the left Item is earlier than the right one; false otherwise
	static bool isEarlierThan(Item, Item);
	static bool isAlphabeticallySmallerThan(Item, Item);

	//	Convert entire string to lowercase
	//	Pre:	Valid string
	//	Post:	All uppercased characters are converted to lowercase
	static string lowerAllCase(const string& unconvertedString);

public:
	//	Constructor
	//	Pre:    Nil
	//	Post:	Empty schedule is created without any Item objects
	Schedule();

	//	Destructor
	//	Pre:    Nil
	//	Post:	Schedule is destroyed, along with the items stored in it
	~Schedule();

	//	Retrieves the size of the schedule/display schedule
	//	Pre:	Nil
	//	Post:	Returns the number of items within _schedule or _displaySchedule respectively
	unsigned int getSizeOfSchedule();
	unsigned int getSizeOfDisplaySchedule();

	//	Retrieves schedule vector index given item ID
	//	Pre:	Valid itemID
	//	Post:	Schedule vector index is returned
	unsigned int findVectorIndexGivenItemID(unsigned int);

	//	Retrieves item ID given display vector index
	//	Pre:	Display vector is not sorted by the other components
	//	Post:	Returns item ID of the item selected
	unsigned int findItemIDGivenDisplayVectorIndex(unsigned int);

	//	Adds an item to the schedule
	//	Pre:	Valid Item object
	//	Post:	Item is added to the schedule
	//			Full details of the item is returned (string)
	string addItem(Item*);

	//	Given Item ID, retrieves a copy of/replaces/deletes an existing item in the schedule
	//	Pre:	Valid Item ID, valid Item object (for replacement)
	//	Post:	Given Item ID, a copy of the existing item is returned (for retrieval)
	//			Given Item ID, a string of the item's full details is returned
	Item retrieveItemGivenItemID(unsigned int);
	string replaceItemGivenItemID(Item*, unsigned int);
	string deleteItemGivenItemID(unsigned int);

	//	Given display vector index, retrieves a copy of/replaces/deletes an existing item in the schedule
	//	Pre:	Valid display vector index, valid Item object (for replacement)
	//	Post:	Given display vector index, a copy of the existing item is returned (for retrieval)
	//			Given display vector index, a string of the item's full details is returned
	Item retrieveItemGivenDisplayVectorIndex(unsigned int);
	string replaceItemGivenDisplayVectorIndex(Item*, unsigned int);
	string deleteItemGivenDisplayVectorIndex(unsigned int);

	//	Retrieves the entire schedule/display schedule
	//	Pre:	Nil
	//	Post:	Constant reference to vector of Item is returned.
	const vector <Item>& retrieveSchedule();
	const vector <Item>& retrieveDisplaySchedule();

	//	Sorts the schedule by attribute (date - if any, item name, priority, completion status)
	//	Pre:	Valid date, if any - YYYY MM DD HH:MM or YYYY MM DD
	//			Valid item name (string)
	//			Valid priority, if any - P, O, M
	//			Valid completion status - true, false
	//	Post:	Constant reference to the sorted schedule is returned
	const vector<Item>& retrieveDisplayScheduleByDate();
	const vector<Item>& retrieveDisplayScheduleByItemName();
	const vector<Item>& retrieveDisplayScheduleByPriority();
	const vector<Item>& retrieveDisplayScheduleByCompletionStatus();
	const vector<Item>& retrieveDisplayScheduleByLastUpdate();

	/*
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

		*/
};

#endif