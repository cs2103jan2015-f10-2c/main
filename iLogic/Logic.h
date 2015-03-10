//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

#pragma once

#ifndef LOGIC_H
#define LOGIC_H

#include "..\iStorage\Schedule.h"
#include "..\iStorage\Item.h"
#include "..\iParser\iParser.h"
#include "..\iParser\UserCommand.h"
#include "..\iLogic\ItemVerification.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Logic
{
private:
	Schedule _logicSchedule;
	unsigned int _nextItemID;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID_INPUT;
	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_EDIT;
	static const string COMMAND_EXIT;
	static const int ZERO_INDEX = 0;

public:
	Logic();
	~Logic();

	/*
	// interactions with Parser
	// Coded by Ng Chon Beng ====================================================
	string executeLogic();
	
	string executeCommand(list<userCommand> userCommandList); // do unit test
	string executeFunction(userCommand userCommand);
	
	bool notExit(string userInput); // do unit test
	bool isValidInput(userCommand userCommand); // do unit test
	bool isBlank(string text);
	bool isDigit(string text);

	bool isAdd(string command);
	bool isDelete(string command);
	bool isEdit(string command);

	string showUserInput(list<userCommand> userCommandList); // do unit test
	string showToUser(string text);
	// end of Ng Chon Beng's code ===============================================
	*/

	unsigned int addTask(Item itemToBeAdded);
	unsigned int addTaskForEdition(Item itemToBeAdded);
	//addTask && addTaskForEdition works the same
	//except that addTask increments the _nextItemID and addTaskForEdition doesn't
	//addTask is for pure addition, and addTaskForEdition is used when editing 
	//( e.g. delete and add back the edited Item)

	bool isValidItem(Item itemToBeChecked);
	Item deleteTask(unsigned int lineIndexToBeDeleted);
	unsigned int getItemIdFromLineIndex(int lineIndex);
	bool isValidLineIndex(unsigned int lineIndexToBeChecked);
	vector<Item> getSchedule();
	unsigned int getScheduleSize();

	Item deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded);

	Item assignTiming(Item item, string timingType, DateTime datetime);
	Item assignTimingToNewTask(string timingType, DateTime datetime);
	Item assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex);
	Item assignPriority(Item item, char priorityType);
	Item assignPriorityToNewTask(char priorityType);
	Item assignPriorityToExistingTask(char priorityType, unsigned int lineIndex);
	Item assignLabel(Item item, char labelType);
	Item assignLabelToNewTask(char labelType);
	Item assignLabelToExistingTask(char labelType, unsigned int lineIndex);
	/*
	void readUserInput();
	void showUserInput(list<userCommand> userCommandList);
	
	int editTask(string partToEdit, unsigned int lineIndexToBeEdited);
	
	
	int searchTask(string phraseToSearch);
	bool isFound(int lineIndex, string& phraseToSearch);
	int sortTask();
	int changeView();
	int showHelpMenu();

	void assignSaveFolder();*/
	int readDataFromFile(char * fileName);
	int writeDataOntoFile(char * fileName, vector<Item> itemVector);
	/*
	
	
	
	void printItem(Item item);
	void printItemVector(vector<Item> itemVector);

	Item getItem(unsigned int itemID);

	
	DateTime setDateTime(int year, int month, int day, int hour, int minute);
	DateTime setDateTime(int year, int month, int day);
	Item setItem(string itemName, DateTime startTime, DateTime endTime, string description, char priority, char label, bool isCompleted);
	*/
};

#endif
