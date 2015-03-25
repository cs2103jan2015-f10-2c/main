//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

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
using namespace std;

class Logic
{
private:
	Schedule _logicSchedule;
	unsigned int _nextItemID;
	unsigned int _scheduleSize;
	string _directoryToBeSaved;
	string _fileNameToBeSaved;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID_INPUT;
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

	static const string MESSAGE_SUCCESSFUL;
	static const string MESSAGE_FAILED;
	static const string ADD_TASK_SUCCESSFUL;
	static const string DELETE_TASK_SUCCESSFUL;


public:
	Logic();
	~Logic();
	void printSchedule();
	void printItem(string itemToBePrinted);
	void printAddTaskSuccessful(string itemInformationToBePrinted);
	void printDeleteTaskSuccessful(int lineNumberToBeDeleted);
	void printInvalidInput();

	list<COMMAND_AND_TEXT> getParseInfo(iParser parser, string input);
	//	unsigned int processedLineIndex(ParseInfo parseInfoToBeProcessed);
	string initiateCommandAction(iParser parser, string input);

	//Pre: takes in the parse info given by the parser and execute addTask
	//post:returns Success or Failure message
	string addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed);
	void setItemNameAndIDForNewItem(Item *newItem, list<COMMAND_AND_TEXT> parseInfoToBeProcessed);
	void increaseItemIDAndScheduleSize();

	//Pre: takes in the parse info given by the parser and execute deleteTask
	//post:returns Success or Failure message
	string deleteTask(int lineIndexToBeDeleted);

	//Pre: takes in the parse info given by the parser and execute deleteTask
	//post:returns Success or Failure message
	string editTask(list<COMMAND_AND_TEXT>, unsigned int lineIndexToBeEdited);
	vector<Item> searchTask(string phraseToSearch);
	void modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeprocessed, Item* itemToBeModified);
	void modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified);
	DateTime interpreteDateTime(string infoToBeInterpreted);
	DateTime createDateTime(int DD, int MM, int YYYY, int hh, int mm);


	vector<Item> getSchedule();
	unsigned int getScheduleSize();

	//void assignSaveFolder();
	string changeSavingDirectory(string directoryToBeSaved);
	string changeSavingFileName(string FileNameToBeSaved);
	void assignDirectorySpecifiedByUser(string directoryToBeSaved, string directoryToMake, int truncateDirectory);
	void Logic::assignDefaultDirectory(string directoryToBeSaved, string directoryToMake);
	string getDirectoryAndFileName();
	void saveDirectoryToTextFile();
	string retrieveDirectoryFromTextFile();
	//store saving directory and file name in order to 
	//retrieve directory and filename when the program is rebooted
	int readDataFromFile();
	int writeDataOntoFile();

	// with much love,
	// Chon Beng
	int convertToDigit(string text);

	bool isValidItemInLogic(Item itemToBeChecked);
	bool isFound(int lineIndex, string& phraseToSearch);
	bool isValidLineIndex(unsigned int lineIndexToBeChecked);

};

#endif
