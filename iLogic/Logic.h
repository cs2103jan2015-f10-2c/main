
//Coder : Yu Young Bin
//@author A0116229J

#pragma once

#ifndef LOGIC_H
#define LOGIC_H

#include "..\iStorage\Schedule.h"
#include "..\iStorage\Item.h"
#include "..\iParser\iParser.h"
#include "..\iLogic\ItemVerification.h"
#include "..\iPlanner Log\Log.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <direct.h>
#include <atltime.h>
using namespace std;

//structure return to UI
//return message and display vector
struct MESSAGE_AND_SCHEDULE {
	string message;
	vector<Item> displaySchedule;
};

//structure used for view date
struct START_END_TIME{
	DateTime startTime;
	DateTime endTime;
};

class Logic
{
private:
	Schedule _logicSchedule;
	iParser _logicParser;
	unsigned int _nextItemID;
	unsigned int _scheduleSize;
	string _directoryToBeSaved;
	string _fileNameToBeSaved;
	string _currentSorting;
	string _currentFilter;
	vector<string> _keywordVec;
	START_END_TIME _startEndTime;
	Log _logicLogger;

	//used strings for UI display
	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID_INPUT;
	static const string MESSAGE_INVALID_INPUT_FOR_DELETE;
	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_EDIT;
	static const string COMMAND_UNDO;
	static const string COMMAND_SORT;
	static const string COMMAND_SEARCH;
	static const string COMMAND_VIEW;
	static const string COMMAND_DONE;
	static const string COMMAND_UNDONE;
	static const string COMMAND_SAVE;
	static const string COMMAND_EXIT;
	static const string COMMAND_CLEAR;
	static const string MODIFIER_NAME;
	static const string MODIFIER_START;
	static const string MODIFIER_END;
	static const string MODIFIER_DESCRIPTION;
	static const string MODIFIER_LABEL;
	static const string MODIFIER_PRIORITY;
	static const string MODIFIER_COMPLETION;
	static const string SORT_NAME;
	static const string SORT_DATE;
	static const string SORT_PRIORITY;
	static const string SORT_COMPLETION;
	static const string SORT_LAST_UPDATE;
	static const string FILTER_COMPLETION;
	static const string FILTER_COMPLETION_UNDONE;
	static const string FILTER_KEYWORD;
	static const string FILTER_PRIORITY_HIGH;
	static const string FILTER_PRIORITY_MEDIUM;
	static const string FILTER_PRIORITY_LOW;
	static const string FILTER_LABEL;
	static const string FILTER_ALL;
	static const string FILTER_DATE;

	static const string ACCEPTABLE_PRIORITY_HIGH_1;
	static const string ACCEPTABLE_PRIORITY_HIGH_2;
	static const string ACCEPTABLE_PRIORITY_HIGH_3;
	static const string ACCEPTABLE_PRIORITY_MEDIUM_1;
	static const string ACCEPTABLE_PRIORITY_MEDIUM_2;
	static const string ACCEPTABLE_PRIORITY_MEDIUM_3;
	static const string ACCEPTABLE_PRIORITY_LOW_1;
	static const string ACCEPTABLE_PRIORITY_LOW_2;
	static const string ACCEPTABLE_PRIORITY_LOW_3;

	static const char PRIORITY_HIGH;
	static const char PRIORITY_MEDIUM;
	static const char PRIORITY_LOW;
	static const char PRIORITY_INVALID;


	static char buffer[300];
	static const string ASSIGNED_PRIORITY;
	static const string ASSIGNED_LABEL;
	static const string ASSIGNED_START_TIME;
	static const string ASSIGNED_END_TIME;
	static const string ASSIGNED_NAME;
	static const string ASSIGNED_DESCRIPTION;
	static const string TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME;
	static const string DEFAULT_FILENAME;
	static const string DEFAULT_SORTING;
	static const string MESSAGE_TASK;
	static const string MESSAGE_SUCCESSFUL_ADD;
	static const string MESSAGE_SUCCESSFUL_DELETE;
	static const string MESSAGE_SUCCESSFUL_EDIT;
	static const string MESSAGE_SUCCESSFUL_SORT;
	static const string MESSAGE_SUCCESSFUL_VIEW;
	static const string MESSAGE_SUCCESSFUL_SAVE;
	static const string MESSAGE_SUCCESSFUL_UNDO;
	static const string MESSAGE_SUCCESSFUL_MARK_DONE;
	static const string MESSAGE_SUCCESSFUL_MARK_UNDONE;
	static const string MESSAGE_SUCCESSFUL_CHANGE_COMPLETION;
	static const string MESSAGE_CLEAR;
	static const string MESSAGE_RETRIEVED_FROM_TEXT_FILE;
	static const string MESSAGE_FILE_NOT_EXISTING;
	static const string MESSAGE_FAILED_ADD;
	static const string MESSAGE_FAILED_DELETE;
	static const string MESSAGE_FAILED_EDIT;
	static const string MESSAGE_FAILED_VIEW;
	static const string MESSAGE_FAILED_SAVE;
	static const string MESSAGE_FAILED_UNDO;
	static const string MESSAGE_FAILED_SORT;
	static const string MESSAGE_INVALID_INDEX;
	static const string MESSAGE_INVALID_PRIORITY;
	static const string MESSAGE_INVALID_SORTTYPE;
	static const string MESSAGE_INVALID_FILTERTYPE;
	static const string MESSAGE_INVALID_MODIFIER;
	static const string MESSAGE_INVALID_COMPLETION;
	static const string MESSAGE_NO_TASK_FOUND;
	static const string MESSAGE_TASK_FOUND;
	static const string MESSAGE_UNABLE_TO_UNDO;
	static const string MESSAGE_READFILE_COMPLETE;
	static const string MESSAGE_WRITEFILE_COMPLETE;
	static const string MESSAGE_LOGIC;
	static const string MESSAGE_DEFAULT;
	static const string END_OF_FOLDER_NAME;
	static const string PLUS;
	static const string EMPTY_STRING;
	static const string SPACE_BAR;
	static const char CHAR_SPACE_BAR;
	static const char CHAR_TAB;

	//used to avoid using magic numbers
	static const unsigned int FIRST_INDEX;
	static const unsigned int SIZE_ZERO;
	static const unsigned int SIZE_INVALID;
	static const unsigned int NOT_FOUND;
	static const unsigned int EMPTY_TIME_FIELD;
	static const unsigned int TIME_FIELD_REMOVED;
	static const unsigned int INITIAL_ITEM_ID;
	static const unsigned int FIRST_HOUR;
	static const unsigned int FIRST_MINUTE;
	static const unsigned int FINAL_HOUR;
	static const unsigned int FINAL_MINUTE;
	static const int ZERO_INDEX;
	static const unsigned int DEFAULT_ITEM_ID;


	//Strings used for CLI prints
	static const string SCHEDULE_HEAD;
	static const string SCHEDULE_END;
	static const string ADD_TASK_SUCCESSFUL;
	static const string DELETE_TASK_SUCCESSFUL;
	static const string EDIT_TASK_SUCCESSFUL;
	static const string SORT_TASK_SUCCESSFUL;
	static const string MARK_DONE_SUCCESSFUL;
	static const string SCHEDULE_RETRIEVED;
	static const string ADD_TASK_FAILED;
	static const string DELETE_TASK_FAILED;
	static const string EDIT_TASK_FAILED;
	static const string INVALID_LINE_INDEX;
	static const string SORT_TASK_FAILED;




public:
	Logic();
	~Logic();


	/////////////////////////
	////*PRINT FUNCTIONS*////
	/////////////////////////

	//Print functions are used for command line interface
	//for debugging purpose
	//for a better visualisation of UI 
	void printSchedule(vector<Item> retrievedDisplaySchedule);
	void printItem(Item itemToBePrinted);
	void printAddTaskSuccessful(string itemInformationToBePrinted);
	void printDeleteTaskSuccessful(int lineNumberToBeDeleted);
	void printEditTaskSuccessful(int lineNumberToBeEdited);
	void printSortTaskSuccessful();
	void printMarkDoneSuccessful(unsigned int lineIndex);
	void printViewChanged();
	void printUndo();
	void printAddTaskFailed(ItemVerification verifier);
	void printDeleteTaskFailed();
	void printEditTaskInvalidLineIndex();
	void printEditTaskInvalidItemParts(ItemVerification verifier);
	void printInvalidInput();
	void printSortTaskFailed();
	void printInvalidLineIndex();
	void printInvalidViewOption();
	void printChangeSavingDirectorySuccessful();



	////////////////////////
	////*MAIN FUNCTIONS*////
	////////////////////////


	//takes in the user input and initiate the action according to the command
	//specified by the user
	//Pre : takes in a whole line of user input
	//Post : returns a message whether each command was executed successfully and the display vector to pass to UI
	MESSAGE_AND_SCHEDULE initiateCommandAction(string input);


	//create a structure that consists of message of success or failure of each command
	//and display vector
	//pre : takes in a string of message 
	//post : returns a MESSAGE_AND_SCHEDULE object created
	MESSAGE_AND_SCHEDULE Logic::returnUserDisplayInformation(string returnMessage);


	//calls for parser and get parsed info of the user input
	//pre : takes in parser and a line of user input
	//post : returns a list of command and text of the user input
	list<COMMAND_AND_TEXT> getParseInfo(iParser parser, string input);



	////////////////////////////////////
	////*ADD TASK RELATED FUNCTIONS*////
	////////////////////////////////////


	//add new Item in the Schedule, add task sets ItemID, which is a fixed number assigned to each Item
	//for identification purpose
	//Pre: takes in the parse info given by the parser and execute addTask
	//post:returns Success or Failure message
	string addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed);


	//adds Item to schedule once the item is valid
	//Pre : takes in valid item to be added to storage
	//post : returns a message of successful addition
	string Logic::addItemToSchedule(Item* newItemToBeAdded);


	//set an item name and id for a new item created
	//Pre : takes in the item pointer that ID and name should be assigned and the name that user specified
	//Post : none
	void setItemNameAndIDForNewItem(Item *newItem, list<COMMAND_AND_TEXT> parseInfoToBeProcessed);


	//ItemID starts from 1, everytime when addTask is called, nextItemID increases by 1
	//Pre: None
	//Post : returns nextItemID
	unsigned int increaseItemID();


	//remove pointer object in order to prevent memory leakage
	//pre : takes in an item pointer
	//post : none
	void removeItemPointer(Item* itemPointer);



	///////////////////////////////////////
	////*DELETE TASK RELATED FUNCTIONS*////
	///////////////////////////////////////


	//Delete Item from the schedule, given a valid line index to be deleted is provided
	//Pre: takes in the parse info given by the parser and execute deleteTask
	//post:returns Success or Failure message
	string deleteTask(unsigned int lineIndexToBeDeleted);


	//takes in valid line number and execute deletion from the schedule
	//pre : takes in the valid line index
	//post : returns a message delete successful
	string deleteItemFromSchedule(unsigned int lineIndexToBeDeleted);


	//converts a string into an int
	//pre : takes in a string
	//post : returns an int
	int convertToDigit(string text);


	//Undo previous action
	//pre : none
	//post : returns a message whether undo is executed successfully
	string undoPreviousAction();


	/////////////////////////////////////
	////*EDIT TASK RELATED FUNCTIONS*////
	/////////////////////////////////////


	//modify the item, if valid line index and parse info are passed.
	//Pre: takes in the lineIndex and the parse info given by the parser and execute editTask
	//post: returns Success or Failure message
	string editTask(list<COMMAND_AND_TEXT>, unsigned int lineIndexToBeEdited);


	//if Item to be modified is valid and line index is valid, replace the item from the schedule
	//pre : takes in valid item pointer, and valid line index
	//post : returns message edit successful
	string replaceItemInSchedule(Item* editedItemToBeReplaced, unsigned int lineIndexToBeEdited);


	//modifies an item, specified by the parse info
	//Pre: takes in an item to be modified, and a parse info list to execute the modification
	//Post : returns the string of itemparts that is modified
	string modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeprocessed, Item* itemToBeModified);


	//modifies each part of the item, specified by the parse info
	//Pre : takes in the iterator of the Command and text list, and the item pointer to be modified
	//post : returns the part that is modified
	string modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified, string& modifiedItemPartsForDisplay);


	//changes completion of the specified line index if line index given is valid
	//pre : takes in line index
	//post : returns a message whether mark done is successful or not
	string markDone(unsigned int lineIndex);
	string markUndone(unsigned int lineIndex);

	//valid line index given, changes the completion of the item to done
	//pre : takes in valid line index
	//post : returns a message of successful change
	string changeCompletion(unsigned int lineIndex, string completion);

	//Parser returns a whole string of dateTime data
	//interpreteDateTime switches the stringed input into 5 integers
	//and createDateTime create a DateTime object based on the 5 integers given
	//Pre : takes in a string, usually the text part of the COMMAND_AND_TEXT parsed by the parser
	//Post : returns a dateTime object created
	DateTime interpreteDateTime(string infoToBeInterpreted, DateTime existingTimeSetting);
	DateTime createDateTime(int DD, int MM, int YYYY, int hh, int mm);


	//gets current time and convert it to a DateTime object
	//pre : none
	//post : dateTime object of the current time
	DateTime getCurrentTime();


	//checks whether priority specified by the user is valid
	//pre : takes in a string of text input by the user
	//post : interprets and returns a priority charactor (H,M,L) 
	char checkPriority(string priorityToBeModified);




	/////////////////////////////////////
	////*SORT TASK RELATED FUNCTIONS*////
	/////////////////////////////////////


	//sorting can be done by - last update, name, priority, date, completion
	//sorting method is stored in _currentSorting
	//Pre: none
	//Post: returns the Display vector of Items
	vector<Item> sortTask();


	//changes current Sorting method if sorting method specified by the user is valid.
	//display schedule will be sorted according to the current sorting method
	//everytime a command is executed.
	//Pre : takes in a string that consists of sorting method to be changed
	//post : returns current sorting method
	string changeCurrentSorting(string sortingMethod);


	//valid sorting method is specified and changes current Sorting method
	//Pre : takes in a string that consists of sorting method to be changed
	//post : returns current sorting method
	string changeCurrentSortingAsUserSpecified(string sortingMethod);



	//////////////////////////////////
	////*FILTER RELATED FUNCTIONS*////
	//////////////////////////////////


	//changes the filter of the display vector as specified by the user
	//Available filters : completion, priority, no filter
	//pre : takes in a string of filter
	//post : returns a message whether filter is successfully implemented
	string filterTask(string filterToBeImplemented);
	string filterByCompletion(bool completion);
	string filterByPriority(char priority);
	string filterByDate(START_END_TIME);
	string removeFilter();


	//searches for a keyword from item name and item description of all the items in the schedule
	//pre : takes in a key word to search
	//post : returns whether item(s) can be found
	string modifyKeywordVec(string keyWord);
	string searchTask();
	void clearKeyWordVec();

	//convert a string to a priority charactor (H,M,L)
	//Pre: takes in a string that contains information on priority
	//post: returns a priority charactor(H,M,L) Invalid priority (E)
	char stringConvertToPriorityChar(string priority);


	//takes in a string and trims the empty space front and back of it
	//Pre : takes in a string
	//Post : trimmed string
	string trimText(string& text);
	string trimBack(string text);
	string trimFront(string text);


	/////////////////
	////*GETTERS*////
	/////////////////


	//Initiate the update on the display schedule in storage
	//and get or print the display schedule
	//Pre : none
	//Post : returns display schedule
	vector<Item> resetDisplaySchedule();
	vector<Item> resetAndGetDisplaySchedule();


	//does not reset but retrieves current state of the display schedule (for the filtered view)
	//pre : none
	//post : returns display schedule
	vector<Item> getDisplaySchedule();


	//retrieves the schedule(only used for saving purpose)
	//pre : none
	//post : returns schedule
	vector<Item> getSchedule();


	//retrieves display schedule/ schedule size
	//Pre : none
	//Post : returns size of the schedule
	unsigned int getScheduleSize();
	unsigned int getDisplayScheduleSize();


	//get a list of errors that user made
	//pre : takes in the verifier to check
	//post : returns a  string that contains error lists
	string getErrorList(ItemVerification verifier);


	//gets start and end time for the view date option
	//takes in 10 integers and turn them into a start_END_TIME structure
	//Pre : Takes in a string containing 10 integers
	//Post : returns a START_END_TIME structure
	START_END_TIME getStartEndTime(string infoToBeInterpreted);
	DateTime interpretStartEndTime(string identifier, int YYYY, int MM, int DD, int hh, int mm);


	/////////////////////////////////////
	////*SAVE FILE RELATED FUNCTIONS*////
	/////////////////////////////////////


	//changes directory and name of the saving text file
	//Pre : takes in directory and file name specified by the user
	//post : returns directory and file name
	string changeSavingDirectory(string directoryToBeSaved);
	string changeSavingFileName(string FileNameToBeSaved);


	//makes folder and truncate the directory 
	//pre : takes in the directory to make and truncate when '/' is found.
	//		truncate the string and make folder 
	//post : return the truncated directory
	string assignOneFolderToMake(int truncatePosition, string userInputDirectory);
	string assignLastFolderToMake(string userInputDirectory, string directoryToMake);
	string truncateUserInputDirectory(int truncatePosition, string userInputDirectory);


	//retrieves the directory and filename of the save file
	//pre : none
	//post : returns directory + filename
	string getDirectoryAndFileName();
	string convertKeywordVecToString();
	void convertStringToKeywordVec(string keywordString);


	//save basic information in to basicinformation.txt file
	//basic information include :
	//directory, filename, schedulesize, sorting method, last item id used, filter
	//pre : none
	//post : none
	void saveBasicInformationToTextFile();


	//retrieves basic information if basicinformation.txt file exists
	//create new basicinformation.txt file for a new user or file is corrupted or accidentally deleted
	//pre : none
	//post : returns a message to indicate whether textfile exists
	string retrieveBasicInformation();
	string retrieveBasicInformationFromTextFile();
	string createNewTextFile();


	//store schedule and retrieve schedule from text file
	//pre : none
	//post : none
	string readDataFromFile();
	string writeDataOntoFile();



	///////////////////////////
	////*BOOLEAN FUNCTIONS*////
	///////////////////////////


	//boolean functions to check the validity of each components
	//pre : takes in appropriate parameters
	//post : true or false
	bool isValidSortingMethod(string itemInformation);
	bool isValidLineIndex(unsigned int lineIndexToBeChecked);
	bool isExistingFileInDirectory(string directoryAndFileName);
	bool isEmptyStartAndEndTime();

};

#endif
