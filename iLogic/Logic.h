//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J

#pragma once

#ifndef LOGIC_H
#define LOGIC_H

#include "..\iStorage\Schedule.h"
#include "..\iStorage\Item.h"
#include "..\iParser\iParser.h"
#include "..\iLogic\ItemVerification.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <direct.h>
#include <atltime.h>
using namespace std;

class Logic
{
private:
	Schedule _logicSchedule;
	unsigned int _nextItemID;
	unsigned int _scheduleSize;
	string _directoryToBeSaved;
	string _fileNameToBeSaved;
	string _currentSorting;

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
	static const string COMMAND_SAVE;
	static const string COMMAND_EXIT;
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
	static const string FILTER_PRIORITY;
	static const string FILTER_LABEL;

	static const int ZERO_INDEX = 0;
	static const unsigned int DEFAULT_ITEM_ID = 0;

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

	static const string MESSAGE_SUCCESSFUL_ADD;
	static const string MESSAGE_SUCCESSFUL_DELETE;
	static const string MESSAGE_SUCCESSFUL_EDIT;
	static const string MESSAGE_SUCCESSFUL_SORT;
	static const string MESSAGE_SUCCESSFUL_VIEW;
	static const string MESSAGE_SUCCESSFUL_SAVE;
	static const string MESSAGE_SUCCESSFUL_UNDO;
	static const string MESSAGE_SUCCESSFUL_MARK_DONE;

	static const string MESSAGE_FAILED_ADD;
	static const string MESSAGE_FAILED_DELETE;
	static const string MESSAGE_FAILED_EDIT;
	static const string MESSAGE_FAILED_VIEW;
	static const string MESSAGE_FAILED_SAVE;
	static const string MESSAGE_FAILED_UNDO;
	static const string MESSAGE_FAILED_SORT;

	static const string ADD_TASK_SUCCESSFUL;
	static const string DELETE_TASK_SUCCESSFUL;
	static const string EDIT_TASK_SUCCESSFUL;	
	static const string SORT_TASK_SUCCESSFUL;
	static const string MARK_DONE_SUCCESSFUL;

	static const string ADD_TASK_FAILED;
	static const string DELETE_TASK_FAILED;
	static const string EDIT_TASK_FAILED;
	static const string INVALID_LINE_INDEX;
	static const string SORT_TASK_FAILED;




public:
	Logic();
	~Logic();


	//Prints various messages necessary to show to user
	//Print Schedule displays all the items that are added and fit user's request
	void printSchedule(vector<Item> retrievedDisplaySchedule);
	void printItem(Item itemToBePrinted);
	void printAddTaskSuccessful(string itemInformationToBePrinted);
	void printDeleteTaskSuccessful(int lineNumberToBeDeleted);
	void printEditTaskSuccessful(int lineNumberToBeEdited);
	void printSortTaskSuccessful();
	void printMarkDoneSuccessful(unsigned int lineIndex);


	void printAddTaskFailed(ItemVerification verifier);
	void printDeleteTaskFailed();
	void printEditTaskInvalidLineIndex();
	void printEditTaskInvalidItemParts(ItemVerification verifier);
	void printInvalidInput();
	void printSortTaskFailed();
	void printInvalidLineIndex();

	list<COMMAND_AND_TEXT> getParseInfo(iParser parser, string input);
	
	
	//takes in a parser to interpret the user input and initiate the action according to the command
	//specified by the user
	//Pre : takes in a parser, and a whole line of user input
	//Post : returns a message whether each command was executed successfully
	string initiateCommandAction(iParser parser, string input);


	//add new Item in the Schedule, add task sets ItemID, which is a fixed number assigned to each Item
	//for identification purpose
	//Pre: takes in the parse info given by the parser and execute addTask
	//post:returns Success or Failure message
	string addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed);
	void setItemNameAndIDForNewItem(Item *newItem, list<COMMAND_AND_TEXT> parseInfoToBeProcessed);
	

	//ItemID starts from 1, everytime when addTask is called, nextItemID increases by 1
	//Pre: None
	//Post : returns nextItemID
	unsigned int increaseItemID();


	//Delete Item from the schedule, given a valid line index to be deleted is provided
	//Pre: takes in the parse info given by the parser and execute deleteTask
	//post:returns Success or Failure message
	string deleteTask(unsigned int lineIndexToBeDeleted);


	//modify the item, if valid line index and parse info are passed.
	//Pre: takes in the lineIndex and the parse info given by the parser and execute editTask
	//post: returns Success or Failure message
	string editTask(list<COMMAND_AND_TEXT>, unsigned int lineIndexToBeEdited);
	

	//sort display schedule according to _currentSort method;
	//sorting can be done by - last update, name, priority, date, completion
	//Pre: none
	//Post: returns the string of _currentSort
	string sortTask();


	string filterTask(string filterToBeImplemented);

	//modifies an item, specified by the parse info
	//Pre: takes in an item to be modified, and a parse info list to execute the modification
	//Post : None
	void modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeprocessed, Item* itemToBeModified);
	void modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified);
	
	string markDone(unsigned int lineIndex);

	//Parser returns a whole string of dateTime data
	//interpreteDateTime switches the stringed input into 5 integers
	//and createDateTime create a DateTime object based on the 5 integers given
	//Pre : takes in a string, usually the text part of the COMMAND_AND_TEXT parsed by the parser
	//Post : returns a dateTime object created
	DateTime interpreteDateTime(string infoToBeInterpreted);
	DateTime createDateTime(int DD, int MM, int YYYY, int hh, int mm);
	DateTime getCurrentTime();
	
	char checkPriority(string priorityToBeModified);
	//Initiate the update on the display schedule in storage
	//and get or print the display schedule
	//Pre : none
	//Post : returns display schedule
	vector<Item> resetDisplaySchedule();
	vector<Item> getDisplaySchedule();
	vector<Item> resetAndGetDisplaySchedule();
	vector<Item> resetAndPrintSchedule();


	//retrieves display schedule size
	//Pre : none
	//Post : returns size of the schedule
	unsigned int getScheduleSize();
	vector<Item> getSchedule();
	
	//changes current Sorting method. display schedule will be sorted according to the current sorting method
	//everytime a command is executed.
	//Pre : takes in a string that consists of sorting method to be changed
	//post : returns current sorting method
	string changeCurrentSorting(string itemInformation);
	
	
	//changes directory of the saving text file
	//Pre : 
	string changeSavingDirectory(string directoryToBeSaved);
	string changeSavingFileName(string FileNameToBeSaved);
	string assignOneFolderToMake(int truncatePosition, string userInputDirectory);
	string assignLastFolderToMake(string userInputDirectory, string directoryToMake);
	string truncateUserInputDirectory(int truncatePosition, string userInputDirectory);
	string getDirectoryAndFileName();
	void saveDirectoryToTextFile();
	string retrieveDirectoryFromTextFile();
	void printChangeSavingDirectorySuccessful();
	bool isExistingFileInDirectory(string directoryAndFileName);
	

	//store saving directory and file name in order to 
	//retrieve directory and filename when the program is rebooted
	int readDataFromFile();
	int writeDataOntoFile();


	// with much love,
	// Chon Beng
	int convertToDigit(string text);

	bool isValidSortingMethod(string itemInformation);
	bool isValidItemInLogic(Item itemToBeChecked);
	bool isFound(int lineIndex, string& phraseToSearch);
	bool isValidLineIndex(unsigned int lineIndexToBeChecked);
	list<string> getErrorList(ItemVerification verifier);
	list<string> printErrorList(ItemVerification verifier);


	//sets current sorting for unit testing purpose
	//Pre : takes in a string to set to current sorting
	//Post : returns current sorting
	string setCurrentSorting(string currentSorting);

	void thingsToDoAfterEveryExecution();
};

#endif
