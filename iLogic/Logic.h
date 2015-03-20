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
	static const string COMMAND_EXIT;
	static const string MODIFIER_START;
	static const string MODIFIER_END;
	static const string MODIFIER_DESCRIPTION;
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

	static const string ADD_TASK_SUCCESSFUL;
	static const string DELETE_TASK_SUCCESSFUL;

public:
	Logic();
	~Logic();
	void printSchedule();
	void printItem(string itemToBePrinted);
	void printAddTaskSuccessful(string itemInformationToBePrinted);
	void printDeleteTaskSuccessful(int lineNumberToBeDeleted);

	list<COMMAND_AND_TEXT> getParseInfo(iParser parser, string input);
	COMMAND_AND_TEXT getSecondLastParseInfo(iParser parser, string input);
	string getCommand(COMMAND_AND_TEXT parseInfoToBeProcessed);
	string getText(COMMAND_AND_TEXT parseInfoToBeProcessed);
//	unsigned int processedLineIndex(ParseInfo parseInfoToBeProcessed);
	void initiateCommandAction(iParser parser, string input);
	
	unsigned int addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed);
	int deleteTask(int lineIndexToBeDeleted);
	int editTask(list<COMMAND_AND_TEXT>, unsigned int lineIndexToBeEdited);
	unsigned int getItemIDFromLineIndex(unsigned int lineIndex);
	Item getItemFromLineIndex(unsigned int lineIndex);
	vector<Item> searchTask(string phraseToSearch);
	void modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeprocessed, Item* itemToBeModified);
	void modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified);
	
	Item assignDescription(Item item, string descriptionToBeAdded);
	Item assignDescriptionToNewTask(Item item, string descriptionToBeAdded);
	Item assignDescriptionToExistingTask(string descriptionToBeAdded, unsigned int lineIndex);
	Item assignTiming(Item item, string timingType, DateTime datetime);
	Item assignTimingToNewTask(string timingType, DateTime datetime);
	Item assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex);
	Item assignPriority(Item item, char priorityType);
	Item assignPriorityToNewTask(char priorityType);
	Item assignPriorityToExistingTask(char priorityType, unsigned int lineIndex);
	Item assignLabel(Item item, char labelType);
	Item assignLabelToNewTask(char labelType);
	Item assignLabelToExistingTask(char labelType, unsigned int lineIndex);
	
	vector<Item> getSchedule();
	unsigned int getScheduleSize();

	//void assignSaveFolder();
	string changeSavingDirectory(string directoryToBeSaved);
	string changeSavingFileName(string FileNameToBeSaved);
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
