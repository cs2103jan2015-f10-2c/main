
//Coder : Yu Young Bin
//@author A0116229J


#include "Logic.h"
#include <exception>


const string Logic::COMMAND_ADD = "add";
const string Logic::COMMAND_DELETE = "delete";
const string Logic::COMMAND_EDIT = "edit";
const string Logic::COMMAND_UNDO = "undo";
const string Logic::COMMAND_SORT = "sort";
const string Logic::COMMAND_SEARCH = "search";
const string Logic::COMMAND_VIEW = "view";
const string Logic::COMMAND_DONE = "done";
const string Logic::COMMAND_UNDONE = "undone";
const string Logic::COMMAND_SAVE = "save";
const string Logic::COMMAND_CLEAR = "clear";
const string Logic::COMMAND_EXIT = "exit";
const string Logic::MODIFIER_NAME = "name";
const string Logic::MODIFIER_START = "start";
const string Logic::MODIFIER_END = "end";
const string Logic::MODIFIER_DESCRIPTION = "description";
const string Logic::MODIFIER_LABEL = "label";
const string Logic::MODIFIER_PRIORITY = "priority";
const string Logic::MODIFIER_COMPLETION = "done";
const string Logic::SORT_NAME = "name";
const string Logic::SORT_DATE = "date";
const string Logic::SORT_PRIORITY = "priority";
const string Logic::SORT_COMPLETION = "done";
const string Logic::SORT_LAST_UPDATE = "update";
const string Logic::FILTER_COMPLETION = "done";
const string Logic::FILTER_COMPLETION_UNDONE = "undone";
const string Logic::FILTER_PRIORITY_HIGH = "high";
const string Logic::FILTER_PRIORITY_MEDIUM = "medium";
const string Logic::FILTER_PRIORITY_LOW = "low";
const string Logic::FILTER_LABEL = "label";
const string Logic::FILTER_ALL = "all";
const string Logic::FILTER_KEYWORD = "keyword";
const string Logic::FILTER_DATE = "date";

const string Logic::ACCEPTABLE_PRIORITY_HIGH_1 = "high";
const string Logic::ACCEPTABLE_PRIORITY_HIGH_2 = "h";
const string Logic::ACCEPTABLE_PRIORITY_HIGH_3 = "H";
const string Logic::ACCEPTABLE_PRIORITY_MEDIUM_1 = "medium";
const string Logic::ACCEPTABLE_PRIORITY_MEDIUM_2 = "M";
const string Logic::ACCEPTABLE_PRIORITY_MEDIUM_3 = "m";
const string Logic::ACCEPTABLE_PRIORITY_LOW_1 = "low";
const string Logic::ACCEPTABLE_PRIORITY_LOW_2 = "L";
const string Logic::ACCEPTABLE_PRIORITY_LOW_3 = "l";

const char Logic:: PRIORITY_HIGH = 'H';
const char Logic::PRIORITY_MEDIUM = 'M';
const char Logic::PRIORITY_LOW = 'L';
const char Logic::PRIORITY_INVALID = 'E';

const string Logic::TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME = "basicinformation.txt";
const string Logic::DEFAULT_FILENAME = "save.txt";
const string Logic::DEFAULT_SORTING = "date";

const string Logic::MESSAGE_TASK = "Task ";
const string Logic::MESSAGE_SUCCESSFUL_ADD = "Task added to schedule : ";
const string Logic::MESSAGE_SUCCESSFUL_DELETE = "Task is deleted from schedule";
const string Logic::MESSAGE_SUCCESSFUL_EDIT = " is edited : ";
const string Logic::MESSAGE_SUCCESSFUL_SORT = "Schedule sorted by : ";
const string Logic::MESSAGE_SUCCESSFUL_VIEW = "Schedule filtered by : ";
const string Logic::MESSAGE_SUCCESSFUL_SAVE = "Save directory changed to : ";
const string Logic::MESSAGE_SUCCESSFUL_UNDO = "Last action reversed";
const string Logic::MESSAGE_SUCCESSFUL_MARK_DONE = " is completed";
const string Logic::MESSAGE_SUCCESSFUL_MARK_UNDONE = " is undone";
const string Logic::MESSAGE_SUCCESSFUL_CHANGE_COMPLETION = "completion changed to : ";
const string Logic::MESSAGE_CLEAR = "Schedule cleared";
const string Logic::MESSAGE_RETRIEVED_FROM_TEXT_FILE = "Retrieved from save file";
const string Logic::MESSAGE_FILE_NOT_EXISTING = "File not existing";
const string Logic::MESSAGE_FAILED_ADD = "Unable to add task : ";
const string Logic::MESSAGE_FAILED_DELETE = "Unable to delete task : ";
const string Logic::MESSAGE_FAILED_EDIT = "Unable to edit task : ";
const string Logic::MESSAGE_FAILED_VIEW = "Unable to filter schedule : invalid filter type";
const string Logic::MESSAGE_FAILED_UNDO = "Unable to undo last action";
const string Logic::MESSAGE_FAILED_SORT = "Unable to change sorting : ";
const string Logic::MESSAGE_INVALID_PRIORITY = "Invalid Priority Type";
const string Logic::MESSAGE_SUCCESS = "Execution success";
const string Logic::MESSAGE_INVALID_SORTTYPE = "Invalid sort type";
const string Logic::MESSAGE_INVALID_INPUT = "Invalid command";
const string Logic::MESSAGE_INVALID_INDEX = "Invalid index";
const string Logic::MESSAGE_INVALID_FILTERTYPE = "Invalid filter type";
const string Logic::MESSAGE_INVALID_MODIFIER = "Invalid modifier";
const string Logic::MESSAGE_INVALID_COMPLETION = "invalid completion";
const string Logic::MESSAGE_TASK_FOUND = "Tasks containing : ";
const string Logic::MESSAGE_NO_TASK_FOUND = "No task can be found";
const string Logic::MESSAGE_UNABLE_TO_UNDO = "ERROR: Undo has reached its limit.";
const string Logic::MESSAGE_LOGIC = "LOGIC::";
const string Logic::MESSAGE_DEFAULT = "default";
const string Logic::MESSAGE_READFILE_COMPLETE = "readfile completed";
const string Logic::MESSAGE_WRITEFILE_COMPLETE = "writefile completed";
const string Logic::EMPTY_STRING = "";
const string Logic::END_OF_FOLDER_NAME = "/";
const string Logic::PLUS = "+";
const string Logic::SPACE_BAR = " ";
const char Logic::CHAR_SPACE_BAR = ' ';
const char Logic::CHAR_TAB = '\t';

const unsigned int Logic::FIRST_INDEX = 0;
const unsigned int Logic::SIZE_ZERO = 0;
const unsigned int Logic::SIZE_INVALID = 1;
const unsigned int Logic::NOT_FOUND = -1;
const unsigned int Logic::EMPTY_TIME_FIELD = -1;
const unsigned int Logic::TIME_FIELD_REMOVED = -2;
const unsigned int Logic::INITIAL_ITEM_ID = 1;
const unsigned int Logic::FIRST_HOUR = 0;
const unsigned int Logic::FIRST_MINUTE = 0;
const unsigned int Logic::FINAL_HOUR = 23;
const unsigned int Logic::FINAL_MINUTE = 59;


char Logic::buffer[300];
const string Logic::SCHEDULE_HEAD = "-------------------------------------------------------------------------------\nSCHEDULE\n-------------------------------------------------------------------------------";
const string Logic::SCHEDULE_END = "-------------------------------------------------------------------------------";
const string Logic::ADD_TASK_SUCCESSFUL = "Task is added to schedule";
const string Logic::DELETE_TASK_SUCCESSFUL = "Task %d is removed from schedule";
const string Logic::EDIT_TASK_SUCCESSFUL = "Task %d is edited from schedule";
const string Logic::SORT_TASK_SUCCESSFUL = "Sorting Changed to : ";
const string Logic::MARK_DONE_SUCCESSFUL = "Task %d is done";
const string Logic::SCHEDULE_RETRIEVED = "Schedule Retrieved";
const string Logic::ADD_TASK_FAILED = "Task cannot be added to schedule";
const string Logic::DELETE_TASK_FAILED = "Task cannot be removed from schedule";
const string Logic::INVALID_LINE_INDEX = "invalid line index";
const string Logic::SORT_TASK_FAILED = "Invalid Sort Method";
const string Logic::EDIT_TASK_FAILED = "Task cannot be edited from schedule";


Logic::Logic() {
	_nextItemID = INITIAL_ITEM_ID;
	//Initialised to 1, failure in add,delete,add function will return an item with ID = 0
	_scheduleSize = SIZE_ZERO;
	//schedule size initialised to 0
	_directoryToBeSaved = EMPTY_STRING;
	//if saving directory is an empty string, the directory is set to default
	_fileNameToBeSaved = DEFAULT_FILENAME;
	//default file name is save.txt
	_currentSorting = DEFAULT_SORTING;
	//default sorting is by date
	_currentFilter = FILTER_ALL;
	//default filter is view all

}


Logic::~Logic() {}


/////////////////////////
////*PRINT FUNCTIONS*////
/////////////////////////

/*All the print functions are for Command line prompt debugging purposes*/

void Logic::printSchedule(vector<Item> retrievedDisplaySchedule){
	cout << endl;
	cout << SCHEDULE_HEAD << endl;
	
	for (unsigned int lineNumber = FIRST_INDEX; lineNumber < retrievedDisplaySchedule.size(); lineNumber++){
		cout << "[Item " << lineNumber + 1 << "]" << endl;
		printItem(retrievedDisplaySchedule[lineNumber]);
		if (lineNumber != retrievedDisplaySchedule.size() - 1) {
			cout << endl;
		}
	}
	cout << SCHEDULE_END << endl;
	cout << endl;
}


void Logic::printItem(Item itemToBePrinted){
	cout << itemToBePrinted.displayItemForUser();
	return;
}


void Logic::printAddTaskSuccessful(string itemInformationToBePrinted){
	sprintf_s(buffer, ADD_TASK_SUCCESSFUL.c_str(), itemInformationToBePrinted);
	cout << buffer << endl;
}


void Logic::printDeleteTaskSuccessful(int lineNumberToBeDeleted){
	sprintf_s(buffer, DELETE_TASK_SUCCESSFUL.c_str(), lineNumberToBeDeleted);
	cout << buffer << endl;
}


void Logic::printEditTaskSuccessful(int lineNumberToBeEdited){
	sprintf_s(buffer, EDIT_TASK_SUCCESSFUL.c_str(), lineNumberToBeEdited);
	cout << buffer << endl;
}


void Logic::printSortTaskSuccessful(){
	cout << SORT_TASK_SUCCESSFUL << _currentSorting << endl;
}


void Logic::printMarkDoneSuccessful(unsigned int lineIndex){
	sprintf_s(buffer, MARK_DONE_SUCCESSFUL.c_str(), lineIndex);
	cout << buffer << endl;
}


void Logic::printAddTaskFailed(ItemVerification verifier){
	cout << ADD_TASK_FAILED << endl;
	return;
}

void Logic::printDeleteTaskFailed(){
	cout << DELETE_TASK_FAILED << endl;
	cout << INVALID_LINE_INDEX << endl;
	return;
}

void Logic::printEditTaskInvalidLineIndex(){
	cout << EDIT_TASK_FAILED << endl;
	cout << INVALID_LINE_INDEX << endl;
	return;
}


void Logic::printUndo(){
	cout << MESSAGE_SUCCESSFUL_UNDO << endl;
}


void Logic::printSortTaskFailed(){
	cout << SORT_TASK_FAILED << endl;
	return;
}
void Logic::printEditTaskInvalidItemParts(ItemVerification verifier){
	cout << EDIT_TASK_FAILED << endl;
	return;
}

void Logic::printInvalidInput(){
	cout << MESSAGE_INVALID_INPUT << endl << endl;
}

void Logic::printInvalidLineIndex(){
	cout << INVALID_LINE_INDEX << endl;
}


void Logic::printInvalidViewOption(){
	cout << MESSAGE_INVALID_FILTERTYPE << endl;
}


void Logic::printViewChanged(){
	cout << MESSAGE_SUCCESSFUL_VIEW << _currentFilter << endl;
}

void Logic::printChangeSavingDirectorySuccessful(){
	cout << MESSAGE_SUCCESSFUL_SAVE << _directoryToBeSaved << endl;
}



////////////////////////
////*MAIN FUNCTIONS*////
////////////////////////


MESSAGE_AND_SCHEDULE Logic::initiateCommandAction(string input) {
	list<COMMAND_AND_TEXT> parseInfoToBeProcessed = getParseInfo(_logicParser, input);
	assert(parseInfoToBeProcessed.size() > SIZE_ZERO);

	string command = parseInfoToBeProcessed.begin()->command;
	string itemInformation = parseInfoToBeProcessed.begin()->text;
	string returnMessage;
	MESSAGE_AND_SCHEDULE userDisplayInformation;
	list<COMMAND_AND_TEXT>::iterator iter;

	try{
		if (command == COMMAND_ADD) {
			returnMessage = addTask(parseInfoToBeProcessed);
		} else if (command == COMMAND_DELETE) {
			unsigned int lineIndexToBeDeleted = convertToDigit(itemInformation);
			returnMessage = deleteTask(lineIndexToBeDeleted);
		} else if (command == COMMAND_EDIT){
			unsigned int lineIndexToBeEdited = convertToDigit(itemInformation);
			returnMessage = editTask(parseInfoToBeProcessed, lineIndexToBeEdited);
		} else if (command == COMMAND_UNDO){
			returnMessage = undoPreviousAction();
		} else if (command == COMMAND_SORT){
			returnMessage = changeCurrentSorting(itemInformation);
		} else if (command == COMMAND_SEARCH){
			returnMessage = modifyKeywordVec(itemInformation);
		} else if (command == COMMAND_VIEW){
			clearKeyWordVec();
			returnMessage = filterTask(itemInformation);
		} else if (command == COMMAND_SAVE){
			changeSavingDirectory(itemInformation);
			returnMessage = MESSAGE_SUCCESSFUL_SAVE + getDirectoryAndFileName();
		} else if (command == COMMAND_CLEAR){
			_logicSchedule.clearDisplaySchedule();
			returnMessage = MESSAGE_CLEAR;
		} else if (command == COMMAND_EXIT){
			saveBasicInformationToTextFile();
			exit(0);
		} else if (command == COMMAND_DONE){
			unsigned int lineIndex = convertToDigit(itemInformation);
			returnMessage = markDone(lineIndex);
		} else if (command == COMMAND_UNDONE){
			unsigned int lineIndex = convertToDigit(itemInformation);
			returnMessage = markUndone(lineIndex);
		} else {
			printInvalidInput();
			returnMessage = MESSAGE_INVALID_INPUT;
			throw MESSAGE_LOGIC + MESSAGE_INVALID_INPUT;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}

	userDisplayInformation = returnUserDisplayInformation(returnMessage);
	return userDisplayInformation;
}


MESSAGE_AND_SCHEDULE Logic::returnUserDisplayInformation(string returnMessage){
	resetAndGetDisplaySchedule();

	vector<Item> displayVector = sortTask();
	MESSAGE_AND_SCHEDULE userDisplayInformation;
	userDisplayInformation.message = returnMessage;
	userDisplayInformation.displaySchedule = displayVector;
	writeDataOntoFile();
	return userDisplayInformation;
}


list<COMMAND_AND_TEXT> Logic::getParseInfo(iParser parser, string input){
	parser.parse(input);
	return parser.getParseInfo();
}


////////////////////////////////////
////*ADD TASK RELATED FUNCTIONS*////
////////////////////////////////////


string Logic::addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed){
	assert(parseInfoToBeProcessed.size() > SIZE_ZERO);
	Item *newItemToBeAdded;
	newItemToBeAdded = new Item;

	setItemNameAndIDForNewItem(newItemToBeAdded, parseInfoToBeProcessed);
	modifyItem(parseInfoToBeProcessed, newItemToBeAdded);

	ItemVerification verifier(*newItemToBeAdded, _nextItemID);
	try{
		if (verifier.isValidItem()) {
			string returnMessage = addItemToSchedule(newItemToBeAdded);
			return returnMessage;
		} else{
			throw MESSAGE_LOGIC + MESSAGE_FAILED_ADD;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		
	}

	string errorList = getErrorList(verifier);

	_logicLogger.writeToLogFile(MESSAGE_LOGIC + MESSAGE_FAILED_ADD + errorList);

	removeItemPointer(newItemToBeAdded);

	return MESSAGE_FAILED_ADD + errorList;
}


string Logic::addItemToSchedule(Item* newItemToBeAdded){
	string addCompleted = _logicSchedule.addItem(newItemToBeAdded);
	string returnMessage = MESSAGE_SUCCESSFUL_ADD + newItemToBeAdded->getItemName();
	increaseItemID();
	printAddTaskSuccessful(addCompleted);
	removeItemPointer(newItemToBeAdded);
	return returnMessage;
}


void Logic::setItemNameAndIDForNewItem(Item *newItem, list<COMMAND_AND_TEXT> parseInfoToBeProcessed){
	assert(parseInfoToBeProcessed.size() > SIZE_ZERO);
	newItem->setItemName(parseInfoToBeProcessed.begin()->text);
	newItem->setItemID(_nextItemID);
}


unsigned int Logic::increaseItemID(){
	assert(_nextItemID >= SIZE_ZERO);
	_nextItemID++;
	return _nextItemID;
}


void Logic::removeItemPointer(Item* itemPointer){
	assert(itemPointer != NULL);
	itemPointer = NULL;
	delete itemPointer;
}





///////////////////////////////////////
////*DELETE TASK RELATED FUNCTIONS*////
///////////////////////////////////////


string Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	try{
		if (isValidLineIndex(lineIndexToBeDeleted)){
			string displayMessage = deleteItemFromSchedule(lineIndexToBeDeleted);
			return displayMessage;
		} else{
			printDeleteTaskFailed();
			throw MESSAGE_LOGIC + INVALID_LINE_INDEX;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return  MESSAGE_FAILED_DELETE + MESSAGE_INVALID_INDEX;
}


string Logic::deleteItemFromSchedule(unsigned int lineIndexToBeDeleted){
	assert(lineIndexToBeDeleted > SIZE_ZERO);
	_logicSchedule.deleteItemGivenDisplayVectorIndex(lineIndexToBeDeleted);
	printDeleteTaskSuccessful(lineIndexToBeDeleted);
	return MESSAGE_SUCCESSFUL_DELETE;
}


int Logic::convertToDigit(string text) {
	int digit;
	istringstream convert(text);
	convert >> digit;
	return digit;
}

string Logic::undoPreviousAction(){
	string message = _logicSchedule.undoLastCommand();
	try{
		if (message != MESSAGE_UNABLE_TO_UNDO){
			return MESSAGE_SUCCESSFUL_UNDO;
		} else{
			throw MESSAGE_LOGIC + MESSAGE_UNABLE_TO_UNDO;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return MESSAGE_FAILED_UNDO;
}


/////////////////////////////////////
////*EDIT TASK RELATED FUNCTIONS*////
/////////////////////////////////////


string Logic::editTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, unsigned int lineIndexToBeEdited){
	assert(parseInfoToBeProcessed.size() > SIZE_ZERO);
	try{
		if (parseInfoToBeProcessed.size() == SIZE_INVALID){
			return MESSAGE_FAILED_EDIT + MESSAGE_INVALID_INPUT;
		} else if (isValidLineIndex(lineIndexToBeEdited)){

			Item *editedItemToBeReplaced;
			editedItemToBeReplaced = new Item;
			*editedItemToBeReplaced = _logicSchedule.retrieveItemGivenDisplayVectorIndex(lineIndexToBeEdited);
			string modifiedParts = modifyItem(parseInfoToBeProcessed, editedItemToBeReplaced);

			ItemVerification verifier(*editedItemToBeReplaced, editedItemToBeReplaced->getItemID());
			if (verifier.isValidItem()){
				replaceItemInSchedule(editedItemToBeReplaced, lineIndexToBeEdited);
				return MESSAGE_TASK + to_string(lineIndexToBeEdited) + MESSAGE_SUCCESSFUL_EDIT + modifiedParts;
			} else{
				string errorList = getErrorList(verifier);
				removeItemPointer(editedItemToBeReplaced);
				printEditTaskInvalidItemParts(verifier);
				return MESSAGE_FAILED_EDIT + errorList;
			}

		} else{
			printEditTaskInvalidLineIndex();
			throw MESSAGE_LOGIC + MESSAGE_FAILED_EDIT + MESSAGE_INVALID_INDEX;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return MESSAGE_FAILED_EDIT + MESSAGE_INVALID_INDEX;
}


string Logic::replaceItemInSchedule(Item* editedItemToBeReplaced, unsigned int lineIndexToBeEdited){
	assert(lineIndexToBeEdited > SIZE_ZERO);
	_logicSchedule.replaceItemGivenDisplayVectorIndex(editedItemToBeReplaced, lineIndexToBeEdited);
	removeItemPointer(editedItemToBeReplaced);
	return MESSAGE_SUCCESSFUL_EDIT;
}


string Logic::modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, Item* itemToBeModified){
	assert(parseInfoToBeProcessed.size() > SIZE_ZERO);
	list<COMMAND_AND_TEXT>::iterator iter;
	string modifiedItemParts = EMPTY_STRING;
	for (iter = ++parseInfoToBeProcessed.begin(); iter != parseInfoToBeProcessed.end(); ++iter){
		modifyItemParts(iter, itemToBeModified, modifiedItemParts);
	}
	return modifiedItemParts;
}


string Logic::modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified, string& modifiedItemPartsForDisplay){
	string modifier = iter->command;
	assert(modifier != EMPTY_STRING);
	modifiedItemPartsForDisplay = modifiedItemPartsForDisplay + modifier + SPACE_BAR;
	try{
		if (modifier == MODIFIER_NAME){
			itemToBeModified->setItemName(iter->text);
		} else if (modifier == MODIFIER_DESCRIPTION){
			string descriptionToBeAdded = iter->text;
			itemToBeModified->setDescription(descriptionToBeAdded);
		} else if (modifier == MODIFIER_START){
			DateTime startTimeToBeModified = itemToBeModified->getStartTime();
			itemToBeModified->setStartTime(interpreteDateTime(iter->text, itemToBeModified->getStartTime()));
		} else if (modifier == MODIFIER_END){
			itemToBeModified->setEndTime(interpreteDateTime(iter->text, itemToBeModified->getEndTime()));
		} else if (modifier == MODIFIER_LABEL){
			char labelToBeModified = iter->text[FIRST_INDEX];
			itemToBeModified->setLabel(labelToBeModified);
		} else if (modifier == MODIFIER_PRIORITY){
			char priorityToBeModified = checkPriority(iter->text);
			itemToBeModified->setPriority(priorityToBeModified);
		} else if (modifier == MODIFIER_COMPLETION){
			bool done = true;
			itemToBeModified->setCompletion(done);
		} else{
			throw MESSAGE_LOGIC + MESSAGE_INVALID_MODIFIER;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return modifiedItemPartsForDisplay;
}


char Logic::checkPriority(string priorityToBeModified){
	try{
		if (priorityToBeModified == ACCEPTABLE_PRIORITY_HIGH_1 || priorityToBeModified == ACCEPTABLE_PRIORITY_HIGH_2 || priorityToBeModified == ACCEPTABLE_PRIORITY_HIGH_3){
			return PRIORITY_HIGH;
		} else if (priorityToBeModified == ACCEPTABLE_PRIORITY_MEDIUM_1 || priorityToBeModified == ACCEPTABLE_PRIORITY_MEDIUM_2 || priorityToBeModified == ACCEPTABLE_PRIORITY_MEDIUM_3){
			return PRIORITY_MEDIUM;
		} else if (priorityToBeModified == ACCEPTABLE_PRIORITY_LOW_1 || priorityToBeModified == ACCEPTABLE_PRIORITY_LOW_2 || priorityToBeModified == ACCEPTABLE_PRIORITY_LOW_3){
			return PRIORITY_LOW;
		} else{
			throw MESSAGE_LOGIC + MESSAGE_INVALID_PRIORITY;
		}
	}
	catch (string errorMessage) {
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return PRIORITY_INVALID;
}


DateTime Logic::interpreteDateTime(string infoToBeInterpreted, DateTime existingTimeSetting){
	istringstream inputTime(infoToBeInterpreted);
	int YYYY, MM, DD, hh, mm;
	int YYYY2, MM2, DD2, hh2, mm2;

	YYYY = existingTimeSetting.getYear();
	MM = existingTimeSetting.getMonth();
	DD = existingTimeSetting.getDay();
	hh = existingTimeSetting.getHour();
	mm = existingTimeSetting.getMinute();

	inputTime >> YYYY2 >> MM2 >> DD2 >> hh2 >> mm2;

	//if new time input is user defined, make appropriate changes
	if (YYYY2 != EMPTY_TIME_FIELD){
		YYYY = YYYY2;
	}
	if (MM2 != EMPTY_TIME_FIELD){
		MM = MM2;
	}
	if (DD2 != EMPTY_TIME_FIELD){
		DD = DD2;
	}
	if (hh2 != EMPTY_TIME_FIELD){
		hh = hh2;
	}
	if (mm2 != EMPTY_TIME_FIELD){
		mm = mm2;
	}

	//when user did not specified any dates, set current date
	if (YYYY == EMPTY_TIME_FIELD && YYYY2 == EMPTY_TIME_FIELD && MM == EMPTY_TIME_FIELD && MM2 == EMPTY_TIME_FIELD && DD == EMPTY_TIME_FIELD && DD2 == EMPTY_TIME_FIELD){
		YYYY = getCurrentTime().getYear();
		MM = getCurrentTime().getMonth();
		DD = getCurrentTime().getDay();
	}

	//if user did not specify year, set current year
	if (YYYY == EMPTY_TIME_FIELD && YYYY2 == EMPTY_TIME_FIELD){
		YYYY = getCurrentTime().getYear();
	}
	
	//if user wants to remove the datetime
	if (YYYY2 == TIME_FIELD_REMOVED && MM2 == TIME_FIELD_REMOVED && DD2 == TIME_FIELD_REMOVED && hh2 == TIME_FIELD_REMOVED && mm2 == TIME_FIELD_REMOVED){
		YYYY = EMPTY_TIME_FIELD;
		MM = EMPTY_TIME_FIELD;
		DD = EMPTY_TIME_FIELD;
		hh = EMPTY_TIME_FIELD;
		mm = EMPTY_TIME_FIELD;
	}

	DateTime interpretedDateTime(YYYY, MM, DD, hh, mm);
	return interpretedDateTime;
}


DateTime Logic::getCurrentTime(){
	CTime t = CTime::GetCurrentTime();
	int currentDay = t.GetDay();
	int currentMonth = t.GetMonth();
	int currentYear = t.GetYear();
	int currentHour = t.GetHour();
	int currentMinute = t.GetMinute();
	DateTime currentDateTime(currentYear, currentMonth, currentDay, currentHour, currentMinute);
	return currentDateTime;
}


string Logic::markDone(unsigned int lineIndex){
	try{
		if (isValidLineIndex(lineIndex)){
			changeCompletion(lineIndex, COMMAND_DONE);
			return MESSAGE_TASK + to_string(lineIndex) + MESSAGE_SUCCESSFUL_MARK_DONE;
		} else{
			printInvalidLineIndex();
			throw MESSAGE_LOGIC + INVALID_LINE_INDEX;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return INVALID_LINE_INDEX;
}

string Logic::markUndone(unsigned int lineIndex){
	try{
		if (isValidLineIndex(lineIndex)){
			changeCompletion(lineIndex, COMMAND_UNDONE);
			return MESSAGE_TASK + to_string(lineIndex) + MESSAGE_SUCCESSFUL_MARK_UNDONE;
		} else{
			printInvalidLineIndex();
			throw MESSAGE_LOGIC + INVALID_LINE_INDEX;

		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return INVALID_LINE_INDEX;
}

string Logic::changeCompletion(unsigned int lineIndex, string completion){
	assert(lineIndex > SIZE_ZERO);
	Item* retrievedItem;
	retrievedItem = new Item;
	*retrievedItem = _logicSchedule.retrieveItemGivenDisplayVectorIndex(lineIndex);

	bool done;
	try{
		if (completion == COMMAND_DONE){
			done = true;
		} else if (completion == COMMAND_UNDONE){
			done = false;
		} else{
			throw MESSAGE_LOGIC + MESSAGE_INVALID_COMPLETION;

		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
		return MESSAGE_INVALID_COMPLETION;
	}

	retrievedItem->setCompletion(done);
	_logicSchedule.replaceItemGivenDisplayVectorIndex(retrievedItem, lineIndex);
	removeItemPointer(retrievedItem);
	return MESSAGE_SUCCESSFUL_CHANGE_COMPLETION + completion;
}


/////////////////////////////////////
////*SORT TASK RELATED FUNCTIONS*////
/////////////////////////////////////


vector<Item> Logic::sortTask(){
	vector<Item> sortedDisplaySchedule;
	if (_currentFilter == FILTER_ALL){
		sortedDisplaySchedule = resetAndGetDisplaySchedule();
	} else{
		sortedDisplaySchedule = getDisplaySchedule();
	}
	try{
		if (_currentSorting == SORT_NAME){
			sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByItemName();
		} else if (_currentSorting == SORT_PRIORITY){
			sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByPriority();
		} else if (_currentSorting == SORT_COMPLETION){
			sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByCompletionStatus();
		} else if (_currentSorting == SORT_DATE){
			sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByDate();
		} else if (_currentSorting == SORT_LAST_UPDATE){
			sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByLastUpdate();
		} else{
			throw MESSAGE_LOGIC + MESSAGE_INVALID_SORTTYPE;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	printSchedule(sortedDisplaySchedule);
	return sortedDisplaySchedule;
}


string Logic::changeCurrentSorting(string sortingMethod){
	try{
		if (isValidSortingMethod(sortingMethod)){
			changeCurrentSortingAsUserSpecified(sortingMethod);
			return MESSAGE_SUCCESSFUL_SORT + _currentSorting;
		} else {
			printSortTaskFailed();
			throw MESSAGE_LOGIC + MESSAGE_FAILED_SORT + MESSAGE_INVALID_SORTTYPE;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return MESSAGE_FAILED_SORT + MESSAGE_INVALID_SORTTYPE;
}


string Logic::changeCurrentSortingAsUserSpecified(string sortingMethod){
	_currentSorting = sortingMethod;
	printSortTaskSuccessful();
	return MESSAGE_SUCCESSFUL_SORT;
}


//////////////////////////////////
////*FILTER RELATED FUNCTIONS*////
//////////////////////////////////


string Logic::filterTask(string filterToBeImplemented){
	istringstream iss(filterToBeImplemented);
	string filterType;

	iss >> filterType;
	if (filterType == FILTER_COMPLETION){
		bool completion = true;
		filterByCompletion(completion);
	} else if (filterType == FILTER_COMPLETION_UNDONE){
		bool completion = false;
		filterByCompletion(completion);
	} else if (filterType == FILTER_PRIORITY_HIGH || filterType == FILTER_PRIORITY_MEDIUM || filterType == FILTER_PRIORITY_LOW){
		char priorityType = stringConvertToPriorityChar(filterType);
		string returnMessage = filterByPriority(priorityType);
		if (returnMessage == MESSAGE_INVALID_PRIORITY){
			return MESSAGE_FAILED_VIEW + MESSAGE_INVALID_PRIORITY;
		}
	} else if (filterType == FILTER_ALL){
		removeFilter();
	} else if (filterType == FILTER_KEYWORD){
		searchTask();
	} else if (filterType == FILTER_DATE){
		_startEndTime = getStartEndTime(filterToBeImplemented);
		_currentFilter = filterToBeImplemented;
		filterByDate(_startEndTime);
		return MESSAGE_SUCCESSFUL_VIEW + FILTER_DATE;
	} else{
		printInvalidViewOption();
		return MESSAGE_FAILED_VIEW + MESSAGE_INVALID_FILTERTYPE;
	}
	printViewChanged();
	return MESSAGE_SUCCESSFUL_VIEW + _currentFilter;
}

string Logic::filterByDate(START_END_TIME startEndTime){
	_logicSchedule.retrieveDisplayScheduleFilteredByDateTime(_startEndTime.startTime, _startEndTime.endTime);
	return FILTER_DATE;
}

START_END_TIME Logic::getStartEndTime(string infoToBeInterpreted){
	string junk;
	int YYYY, MM, DD, hh, mm;
	istringstream iss(infoToBeInterpreted);
	iss >> junk;
	iss >> YYYY >> MM >> DD >> hh >> mm;
	DateTime startTime = interpretStartEndTime(MODIFIER_START, YYYY, MM, DD, hh, mm);
	iss >> YYYY >> MM >> DD >> hh >> mm;
	DateTime endTime = interpretStartEndTime(MODIFIER_END, YYYY, MM, DD, hh, mm);
	_startEndTime.startTime = startTime;
	_startEndTime.endTime = endTime;
	return _startEndTime;
}

DateTime Logic::interpretStartEndTime(string identifier, int YYYY, int MM, int DD, int hh, int mm){
	if (YYYY == EMPTY_TIME_FIELD){
		YYYY = getCurrentTime().getYear();
	}
	if (MM == EMPTY_TIME_FIELD) {
		MM = getCurrentTime().getMonth();
	}
	if (DD == EMPTY_TIME_FIELD){
		DD = getCurrentTime().getDay();
	}
	if (identifier == MODIFIER_END && hh == EMPTY_TIME_FIELD && mm == EMPTY_TIME_FIELD){
		hh = FINAL_HOUR;
			mm = FINAL_MINUTE;
	}
	cout << YYYY << SPACE_BAR << MM << SPACE_BAR << DD << SPACE_BAR << hh << SPACE_BAR << mm << endl;
	DateTime startEndTime(YYYY, MM, DD, hh, mm);
	return startEndTime;
}

void Logic::clearKeyWordVec(){
	_keywordVec.clear();
	return;
}


string Logic::filterByCompletion(bool completion){
	_logicSchedule.retrieveDisplayScheduleFilteredByCompletion(completion);
	try {
		if (completion == true){
			_currentFilter = FILTER_COMPLETION;
		} else if (completion == false){
			_currentFilter = FILTER_COMPLETION_UNDONE;
		} else{
			throw MESSAGE_LOGIC + MESSAGE_INVALID_COMPLETION;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}

	return _currentFilter;
}

char Logic::stringConvertToPriorityChar(string priority){
	_currentFilter = priority;
	try{
		if (priority == FILTER_PRIORITY_HIGH){
			return PRIORITY_HIGH;
		} else if (priority == FILTER_PRIORITY_MEDIUM){
			return PRIORITY_MEDIUM;
		} else if (priority == FILTER_PRIORITY_LOW){
			return PRIORITY_LOW;
		} else {
			throw MESSAGE_LOGIC+ MESSAGE_INVALID_PRIORITY;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return PRIORITY_INVALID;

}

string Logic::filterByPriority(char priority){
	try{
		if (priority != PRIORITY_INVALID){
			_logicSchedule.retrieveDisplayScheduleFilteredByPriority(priority);
			return _currentFilter;
		} else {
			throw MESSAGE_LOGIC + MESSAGE_INVALID_PRIORITY;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return MESSAGE_INVALID_PRIORITY;
}


string Logic::removeFilter(){
	_currentFilter = FILTER_ALL;
	return _currentFilter;
}


string Logic::modifyKeywordVec(string keyWord){
	convertStringToKeywordVec(keyWord);
	_currentFilter = FILTER_KEYWORD;
	return MESSAGE_TASK_FOUND + keyWord;
}


string Logic::searchTask(){
	for (int lineIndex = SIZE_ZERO; lineIndex < _keywordVec.size(); lineIndex++){
		_logicSchedule.retrieveDisplayScheduleFilteredByKeyword(_keywordVec[lineIndex]);
	}
	try{
		if (getDisplayScheduleSize() == SIZE_ZERO){
			return MESSAGE_NO_TASK_FOUND;
		} else if (getDisplayScheduleSize() > SIZE_ZERO){
			_currentFilter = FILTER_KEYWORD;
			return MESSAGE_TASK_FOUND;
		} else {
			throw MESSAGE_LOGIC + MESSAGE_INVALID_INPUT;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return MESSAGE_INVALID_INPUT;
}

string Logic::trimText(string& text) {
	text = trimFront(text);
	text = trimBack(text);
	return MESSAGE_SUCCESS;
}

string Logic::trimFront(string text) {
	unsigned int startIndex = FIRST_INDEX;

	while (startIndex < text.length() && (text[startIndex] == CHAR_SPACE_BAR || text[startIndex] == CHAR_TAB)) {
		startIndex++;
	}
	return text.substr(startIndex);
}

string Logic::trimBack(string text) {
	unsigned int endIndex = text.length();

	while (endIndex > 0 && (text[endIndex - 1] == CHAR_SPACE_BAR || text[endIndex - 1] == CHAR_TAB)) {
		endIndex--;
	}

	return text.substr(FIRST_INDEX, endIndex);
}

/////////////////////////////////////
////*SAVE FILE RELATED FUNCTIONS*////
/////////////////////////////////////


string Logic::changeSavingDirectory(string userInputDirectory){
	string directoryToMake = EMPTY_STRING;
	int truncatePosition;
	if (userInputDirectory == MESSAGE_DEFAULT){
		userInputDirectory = EMPTY_STRING;
	}

	while (userInputDirectory != EMPTY_STRING){
		truncatePosition = userInputDirectory.find_first_of(END_OF_FOLDER_NAME);
		if (truncatePosition != NOT_FOUND){
			directoryToMake = directoryToMake + assignOneFolderToMake(truncatePosition, userInputDirectory);
			userInputDirectory = truncateUserInputDirectory(truncatePosition, userInputDirectory);
		} else{
			directoryToMake = assignLastFolderToMake(userInputDirectory, directoryToMake);
			userInputDirectory = EMPTY_STRING;
		}
		_mkdir(directoryToMake.c_str());
	}
	_directoryToBeSaved = directoryToMake;
	saveBasicInformationToTextFile();
	printChangeSavingDirectorySuccessful();
	return directoryToMake;
}


string Logic::assignOneFolderToMake(int truncatePosition, string userInputDirectory){
	return userInputDirectory.substr(FIRST_INDEX, truncatePosition + 1);
}


string Logic::assignLastFolderToMake(string userInputDirectory, string directoryToMake){
	return  directoryToMake + userInputDirectory;
}


string Logic::truncateUserInputDirectory(int truncatePosition, string userInputDirectory){
	return userInputDirectory.substr(truncatePosition + 1);
}




void Logic::saveBasicInformationToTextFile(){
	ofstream writeFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	writeFile << _directoryToBeSaved << endl;
	writeFile << _fileNameToBeSaved << endl;
	writeFile << getScheduleSize() << endl;
	writeFile << _nextItemID << endl;
}


string Logic::convertKeywordVecToString(){
	string keywordString = EMPTY_STRING;
	if (_keywordVec.size() != 0){
		for (int i = 0; i < _keywordVec.size(); i++){
			if (i != _keywordVec.size() - 1){
				keywordString = keywordString + _keywordVec[i] + PLUS;
			} else{
				keywordString = keywordString + _keywordVec[i];
			}
		}
	}
	return keywordString;
}

void Logic::convertStringToKeywordVec(string keywordString){
	while (keywordString != EMPTY_STRING){
		int breakPoint = keywordString.find_first_of(PLUS);
		if (breakPoint != NOT_FOUND){
			string tokenisedKeyword = keywordString.substr(FIRST_INDEX, breakPoint);
			trimText(tokenisedKeyword);
			_keywordVec.push_back(tokenisedKeyword);
			keywordString = keywordString.substr(breakPoint + 1);
		} else{
			_keywordVec.push_back(keywordString);
			break;
		}
	}
}

string Logic::getDirectoryAndFileName(){
	if (_directoryToBeSaved == EMPTY_STRING){
		if (_fileNameToBeSaved == EMPTY_STRING){
			_fileNameToBeSaved == DEFAULT_FILENAME;
		}
		return _fileNameToBeSaved;
	} else{
		return _directoryToBeSaved + END_OF_FOLDER_NAME + _fileNameToBeSaved;
	}
}


string Logic::retrieveBasicInformation(){
	try{
		if (isExistingFileInDirectory(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME)){
			retrieveBasicInformationFromTextFile();
			return MESSAGE_RETRIEVED_FROM_TEXT_FILE;
		} else {
			//new user or basicinformation textfile is corrupted
			createNewTextFile();
			throw MESSAGE_LOGIC + MESSAGE_FILE_NOT_EXISTING;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
		_logicLogger.writeToLogFile(errorMessage);
	}
	return MESSAGE_FILE_NOT_EXISTING;
}


string Logic::retrieveBasicInformationFromTextFile(){
	ifstream readFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	getline(readFile, _directoryToBeSaved);
	getline(readFile, _fileNameToBeSaved);
	readFile >> _scheduleSize;
	readFile >> _nextItemID;

	cout << _directoryToBeSaved + END_OF_FOLDER_NAME + _fileNameToBeSaved << endl;

	if (_directoryToBeSaved == EMPTY_STRING){
		if (_fileNameToBeSaved == EMPTY_STRING){
			_fileNameToBeSaved == DEFAULT_FILENAME;
		}
		return _fileNameToBeSaved;
	} else{
		return _directoryToBeSaved + END_OF_FOLDER_NAME + _fileNameToBeSaved;
	}
}


string Logic::createNewTextFile(){
	saveBasicInformationToTextFile();
	return _directoryToBeSaved;
}


string Logic::changeSavingFileName(string FileNameToBeSaved){
	_fileNameToBeSaved = FileNameToBeSaved;
	saveBasicInformationToTextFile();
	return FileNameToBeSaved;
}


string Logic::readDataFromFile() {
	if (isExistingFileInDirectory(getDirectoryAndFileName())){
		ifstream readFile(getDirectoryAndFileName());
		for (unsigned int lineNumber = SIZE_ZERO; lineNumber < _scheduleSize; lineNumber++){

			string itemName;
			string description;
			string itemID;
			string junk;
			char priority;
			char label;
			int DD;
			int MM;
			int YYYY;
			int hh;
			int mm;
			unsigned int ID;
			int completionIndicator;
			bool completion = false;
			getline(readFile, itemName);
			getline(readFile, itemID);
			ID = convertToDigit(itemID);
			readFile >> YYYY;
			readFile >> MM;
			readFile >> DD;
			readFile >> hh;
			readFile >> mm;
			DateTime startTime(YYYY, MM, DD, hh, mm);
			readFile >> YYYY;
			readFile >> MM;
			readFile >> DD;
			readFile >> hh;
			readFile >> mm;
			DateTime EndTime(YYYY, MM, DD, hh, mm);
			getline(readFile, junk);
			getline(readFile, description);
			readFile >> priority;
			readFile >> label;
			readFile >> completionIndicator;
			if (completionIndicator != SIZE_ZERO){
				completion = true;
			}
			getline(readFile, junk);
			Item *item;
			item = new Item;
			item->setItemName(itemName);
			item->setItemID(ID);
			item->setStartTime(startTime);
			item->setEndTime(EndTime);
			item->setDescription(description);
			item->setPriority(priority);
			item->setLabel(label);
			item->setCompletion(completion);
			_logicSchedule.addItem(item);
			removeItemPointer(item);
		}
	} else{
		ofstream writeFile(getDirectoryAndFileName());
	}
	_logicSchedule.resetHistory();
	cout << SCHEDULE_RETRIEVED << endl;
	resetAndGetDisplaySchedule();
	sortTask();
	
	return MESSAGE_READFILE_COMPLETE;
}


string Logic::writeDataOntoFile(){
	ofstream writeFile(getDirectoryAndFileName());
	vector<Item> retrievedSchedule = getSchedule();
	for (unsigned int lineNumber = 0; lineNumber < _logicSchedule.getSizeOfSchedule(); lineNumber++){
		Item itemToStore = retrievedSchedule[lineNumber];
		writeFile << itemToStore.getItemName() << endl;
		writeFile << itemToStore.getItemID() << endl;
		writeFile << itemToStore.getStartTime().getYear() << endl;
		writeFile << itemToStore.getStartTime().getMonth() << endl;
		writeFile << itemToStore.getStartTime().getDay() << endl;
		writeFile << itemToStore.getStartTime().getHour() << endl;
		writeFile << itemToStore.getStartTime().getMinute() << endl;
		writeFile << itemToStore.getEndTime().getYear() << endl;
		writeFile << itemToStore.getEndTime().getMonth() << endl;
		writeFile << itemToStore.getEndTime().getDay() << endl;
		writeFile << itemToStore.getEndTime().getHour() << endl;
		writeFile << itemToStore.getEndTime().getMinute() << endl;
		writeFile << itemToStore.getDescription() << endl;
		writeFile << itemToStore.getPriority() << endl;
		writeFile << itemToStore.getLabel() << endl;
		writeFile << itemToStore.getCompletion() << endl;
	}
	saveBasicInformationToTextFile();
	return MESSAGE_WRITEFILE_COMPLETE;
}



/////////////////
////*GETTERS*////
/////////////////


vector<Item> Logic::getSchedule(){
	return _logicSchedule.retrieveSchedule();
}


vector<Item> Logic::resetDisplaySchedule(){
	_logicSchedule.resetDisplaySchedule();
	return getDisplaySchedule();
}


vector<Item> Logic::getDisplaySchedule(){
	return _logicSchedule.retrieveDisplaySchedule();
}


vector<Item> Logic::resetAndGetDisplaySchedule(){
	resetDisplaySchedule();
	filterTask(_currentFilter);
	return getDisplaySchedule();
}


unsigned int Logic::getScheduleSize(){
	_scheduleSize = _logicSchedule.getSizeOfSchedule();
	return _scheduleSize;
}


unsigned int Logic::getDisplayScheduleSize(){
	return _logicSchedule.getSizeOfDisplaySchedule();
}


string Logic::getErrorList(ItemVerification verifier){

	list<string> errorList = verifier.getItemVerificationErrors();
	list<string>::iterator iter;
	string errorString = EMPTY_STRING;
	for (iter = errorList.begin(); iter != errorList.end(); ++iter){
		errorString = errorString + *iter + SPACE_BAR;
	}
	return errorString;
}


///////////////////////////
////*BOOLEAN FUNCTIONS*////
///////////////////////////


bool Logic::isExistingFileInDirectory(string directoryAndFileName) {
	ifstream infile(directoryAndFileName);
	return infile.good();
}


bool Logic::isValidSortingMethod(string itemInformation){
	if (itemInformation == SORT_NAME || itemInformation == SORT_COMPLETION || itemInformation == SORT_DATE ||
		itemInformation == SORT_LAST_UPDATE || itemInformation == SORT_PRIORITY){
		return true;
	} else{
		return false;
	}
}


bool Logic::isValidLineIndex(unsigned int lineIndexToBeChecked){
	if (getDisplayScheduleSize() >= lineIndexToBeChecked && lineIndexToBeChecked > SIZE_ZERO){
		return true;
	} else{
		return false;
	}
}


