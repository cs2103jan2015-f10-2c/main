//author A0116229J
//Coder : Yu Young Bin


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

const string  Logic::MESSAGE_READFILE_COMPLETE = "readfile completed";
const string Logic::MESSAGE_WRITEFILE_COMPLETE = "writefile completed";

char Logic::buffer[300];
const string Logic::ADD_TASK_SUCCESSFUL = "Task is added to schedule";
const string Logic::DELETE_TASK_SUCCESSFUL = "Task %d is removed from schedule";
const string Logic::EDIT_TASK_SUCCESSFUL = "Task %d is edited from schedule";
const string Logic::SORT_TASK_SUCCESSFUL = "Sorting Changed to : ";
const string Logic::MARK_DONE_SUCCESSFUL = "Task %d is done";

const string Logic::ADD_TASK_FAILED = "Task cannot be added to schedule";
const string Logic::DELETE_TASK_FAILED = "Task cannot be removed from schedule";
const string Logic::INVALID_LINE_INDEX = "invalid line index";
const string Logic::SORT_TASK_FAILED = "Invalid Sort Method";
const string Logic::EDIT_TASK_FAILED = "Task cannot be edited from schedule";


Logic::Logic() {
	_nextItemID = 1;
	//failure in add,delete,add function will return an item with ID = 0
	_scheduleSize = 0;
	//schedule size initialised to 0
	_directoryToBeSaved = "";
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
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "SCHEDULE" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (unsigned int lineNumber = 0; lineNumber < retrievedDisplaySchedule.size(); lineNumber++){
		cout << "[Item " << lineNumber + 1 << "]" << endl;
		printItem(retrievedDisplaySchedule[lineNumber]);
		if (lineNumber != retrievedDisplaySchedule.size() - 1) {
			cout << endl;
		}
	}
	cout << "-------------------------------------------------------------------------------" << endl;
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
	cout << "Undo Previous command" << endl;
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
	cout << "Error: " << MESSAGE_INVALID_INPUT << endl << endl;
}

void Logic::printInvalidLineIndex(){
	cout << INVALID_LINE_INDEX << endl;
}


void Logic::printInvalidViewOption(){
	cout << "Invalid view option" << endl;
}


void Logic::printViewChanged(){
	cout << "Filter : " << _currentFilter << endl;
}




////////////////////////
////*MAIN FUNCTIONS*////
////////////////////////


MESSAGE_AND_SCHEDULE Logic::initiateCommandAction(string input) {
	list<COMMAND_AND_TEXT> parseInfoToBeProcessed = getParseInfo(_logicParser, input);
	assert(parseInfoToBeProcessed.size() > 0);

	string command = parseInfoToBeProcessed.begin()->command;
	string itemInformation = parseInfoToBeProcessed.begin()->text;
	string returnMessage;
	MESSAGE_AND_SCHEDULE userDisplayInformation;
	list<COMMAND_AND_TEXT>::iterator iter;
	/*For debugging purpose on CLI*/
	for (iter = parseInfoToBeProcessed.begin(); iter != parseInfoToBeProcessed.end(); ++iter){
		cout << "COMMAND : " << iter->command << endl;
		cout << "TEXT : " << iter->text << endl;
	}
	/*Debugging Ends*/
	if (command == COMMAND_ADD) {
		returnMessage = addTask(parseInfoToBeProcessed);
	} else if (command == COMMAND_DELETE) {
		unsigned int lineIndexToBeDeleted = convertToDigit(itemInformation);
		cout << "LINEINDEX : " << lineIndexToBeDeleted << endl;
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
	}
	string loggerString = command + " : " + returnMessage;
	_logicLogger.writeToLogFile(loggerString);
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
			throw MESSAGE_FAILED_ADD;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}
	string errorList = getErrorList(verifier);
	cout << "errorList : " << errorList << endl;
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
	newItem->setItemName(parseInfoToBeProcessed.begin()->text);
	newItem->setItemID(_nextItemID);
}


unsigned int Logic::increaseItemID(){
	assert(_nextItemID >= 0);
	_nextItemID++;
	return _nextItemID;
}


void Logic::removeItemPointer(Item* itemPointer){
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
			throw INVALID_LINE_INDEX;
		}
	}
	catch (string errorMessage2){
		cerr << errorMessage2 << endl;
	}
	return  MESSAGE_FAILED_DELETE + MESSAGE_INVALID_INDEX;
}


string Logic::deleteItemFromSchedule(unsigned int lineIndexToBeDeleted){
	assert(lineIndexToBeDeleted > 0);
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
			throw MESSAGE_UNABLE_TO_UNDO;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}
	return MESSAGE_FAILED_UNDO;
}

/////////////////////////////////////
////*EDIT TASK RELATED FUNCTIONS*////
/////////////////////////////////////


string Logic::editTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, unsigned int lineIndexToBeEdited){
	assert(parseInfoToBeProcessed.size() > 0);
	if (parseInfoToBeProcessed.size() == 1){
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
		return MESSAGE_FAILED_EDIT + MESSAGE_INVALID_INDEX;
	}
}


string Logic::replaceItemInSchedule(Item* editedItemToBeReplaced, unsigned int lineIndexToBeEdited){
	assert(lineIndexToBeEdited > 0);
	_logicSchedule.replaceItemGivenDisplayVectorIndex(editedItemToBeReplaced, lineIndexToBeEdited);
	removeItemPointer(editedItemToBeReplaced);
	return MESSAGE_SUCCESSFUL_EDIT;
}


string Logic::modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, Item* itemToBeModified){
	assert(parseInfoToBeProcessed.size() > 0);
	list<COMMAND_AND_TEXT>::iterator iter;
	string modifiedItemParts = "";
	for (iter = ++parseInfoToBeProcessed.begin(); iter != parseInfoToBeProcessed.end(); ++iter){
		modifyItemParts(iter, itemToBeModified, modifiedItemParts);
	}
	return modifiedItemParts;
}


string Logic::modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified, string& modifiedItemPartsForDisplay){
	string modifier = iter->command;
	assert(modifier != "");
	modifiedItemPartsForDisplay = modifiedItemPartsForDisplay + modifier + " ";
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
			char labelToBeModified = iter->text[0];
			itemToBeModified->setLabel(labelToBeModified);
		} else if (modifier == MODIFIER_PRIORITY){
			char priorityToBeModified = checkPriority(iter->text);
			itemToBeModified->setPriority(priorityToBeModified);
		} else if (modifier == MODIFIER_COMPLETION){
			bool done = true;
			itemToBeModified->setCompletion(done);
		} else{
			throw MESSAGE_INVALID_MODIFIER;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}
	return modifiedItemPartsForDisplay;
}


char Logic::checkPriority(string priorityToBeModified){
	try{
		if (priorityToBeModified == "high" || priorityToBeModified == "h" || priorityToBeModified == "H"){
			return 'H';
		} else if (priorityToBeModified == "medium" || priorityToBeModified == "m" || priorityToBeModified == "M"){
			return 'M';
		} else if (priorityToBeModified == "low" || priorityToBeModified == "l" || priorityToBeModified == "L"){
			return 'L';
		} else{
			throw MESSAGE_INVALID_PRIORITY;
		}
	}
	catch (string errorMessage) {
		cerr << errorMessage << endl;
	}
	return 'E';
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
	if (YYYY2 != -1){
		YYYY = YYYY2;
	}
	if (MM2 != -1){
		MM = MM2;
	}
	if (DD2 != -1){
		DD = DD2;
	}
	if (hh2 != -1){
		hh = hh2;
	}
	if (mm2 != -1){
		mm = mm2;
	}

	//when user did not specified any dates, set current date
	if (YYYY == -1 && YYYY2 == -1 && MM == -1 && MM2 == -1 && DD == -1 && DD2 == -1){
		YYYY = getCurrentTime().getYear();
		MM = getCurrentTime().getMonth();
		DD = getCurrentTime().getDay();
	}

	//if user did not specify year, set current year
	if (YYYY == -1 && YYYY2 == -1){
		YYYY = getCurrentTime().getYear();
	}

	//if user wants to remove the datetime
	if (YYYY2 == -2 && MM2 == -2 && DD2 == -2 && hh2 == -2 && mm2 == -2){
		YYYY = -1;
		MM = -1;
		DD = -1;
		hh = -1;
		mm = -1;
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
			throw INVALID_LINE_INDEX;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
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
			throw INVALID_LINE_INDEX;

		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}
	return INVALID_LINE_INDEX;
}

string Logic::changeCompletion(unsigned int lineIndex, string completion){
	assert(lineIndex > 0);
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
			throw MESSAGE_INVALID_COMPLETION;
			return MESSAGE_INVALID_COMPLETION;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
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
			throw MESSAGE_INVALID_SORTTYPE;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}
	printSchedule(sortedDisplaySchedule);
	return sortedDisplaySchedule;
}


string Logic::changeCurrentSorting(string sortingMethod){
	if (isValidSortingMethod(sortingMethod)){
		changeCurrentSortingAsUserSpecified(sortingMethod);
		return MESSAGE_SUCCESSFUL_SORT + _currentSorting;
	} else {
		printSortTaskFailed();
		return MESSAGE_FAILED_SORT + MESSAGE_INVALID_SORTTYPE;
	}
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
	DateTime endTime = interpretStartEndTime(MODIFIER_START, YYYY, MM, DD, hh, mm);
	_startEndTime.startTime = startTime;
	_startEndTime.endTime = endTime;
	return _startEndTime;
}

DateTime Logic::interpretStartEndTime(string identifier, int YYYY, int MM, int DD, int hh, int mm){
	if (YYYY == -1){
		YYYY = getCurrentTime().getYear();
	}
	if (MM == -1) {
		MM = getCurrentTime().getMonth();
	}
	if (DD == -1){
		DD = getCurrentTime().getDay();
	}
	if (identifier == "start" && hh == -1 && mm == -1){
		hh = 0;
		mm = 0;
	}
	if (identifier == "end" && hh == -1 && mm == -1){
		hh = 23;
		mm = 59;
	}

	if (hh == -1){
		hh = 0;
	}
	if (mm == -1){
		mm = 0;
	}
	cout << YYYY << " " << MM << " " << DD << " " << hh << " " << mm << endl;
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
			throw MESSAGE_INVALID_COMPLETION;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}

	return _currentFilter;
}

char Logic::stringConvertToPriorityChar(string priority){
	_currentFilter = priority;
	try{
		if (priority == FILTER_PRIORITY_HIGH){
			return 'H';
		} else if (priority == FILTER_PRIORITY_MEDIUM){
			return 'M';
		} else if (priority == FILTER_PRIORITY_LOW){
			return 'L';
		} else {
			throw MESSAGE_INVALID_PRIORITY;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
	}
	return 'I';

}

string Logic::filterByPriority(char priority){
	try{
		if (priority != 'E'){
			_logicSchedule.retrieveDisplayScheduleFilteredByPriority(priority);
			return _currentFilter;
		} else {
			throw MESSAGE_INVALID_PRIORITY;
		}
	}
	catch (string errorMessage){
		cerr << errorMessage << endl;
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
	for (int i = 0; i < _keywordVec.size(); i++){
		_logicSchedule.retrieveDisplayScheduleFilteredByKeyword(_keywordVec[i]);
	}
	if (getDisplayScheduleSize() == 0){
		return MESSAGE_NO_TASK_FOUND;
	} else{
		_currentFilter = FILTER_KEYWORD;
		return MESSAGE_TASK_FOUND;
	}
}

string Logic::trimText(string& text) {
	text = trimFront(text);
	text = trimBack(text);
	return MESSAGE_SUCCESS;
}

string Logic::trimFront(string text) {
	unsigned int startIndex = 0;

	while (startIndex < text.length() && (text[startIndex] == ' ' || text[startIndex] == '\t')) {
		startIndex++;
	}

	return text.substr(startIndex);
}

string Logic::trimBack(string text) {
	unsigned int endIndex = text.length();

	while (endIndex > 0 && (text[endIndex - 1] == ' ' || text[endIndex - 1] == '\t')) {
		endIndex--;
	}

	return text.substr(0, endIndex);
}

/////////////////////////////////////
////*SAVE FILE RELATED FUNCTIONS*////
/////////////////////////////////////


string Logic::changeSavingDirectory(string userInputDirectory){
	string directoryToMake = "";
	int truncatePosition;
	if (userInputDirectory == "default"){
		userInputDirectory = "";
	}

	while (userInputDirectory != ""){
		truncatePosition = userInputDirectory.find_first_of("/");
		if (truncatePosition != -1){
			directoryToMake = directoryToMake + assignOneFolderToMake(truncatePosition, userInputDirectory);
			userInputDirectory = truncateUserInputDirectory(truncatePosition, userInputDirectory);
		} else{
			directoryToMake = assignLastFolderToMake(userInputDirectory, directoryToMake);
			userInputDirectory = "";
		}
		_mkdir(directoryToMake.c_str());
	}
	_directoryToBeSaved = directoryToMake;
	saveBasicInformationToTextFile();
	printChangeSavingDirectorySuccessful();
	return directoryToMake;
}


string Logic::assignOneFolderToMake(int truncatePosition, string userInputDirectory){
	return userInputDirectory.substr(0, truncatePosition + 1);
}


string Logic::assignLastFolderToMake(string userInputDirectory, string directoryToMake){
	return  directoryToMake + userInputDirectory;
}


string Logic::truncateUserInputDirectory(int truncatePosition, string userInputDirectory){
	return userInputDirectory.substr(truncatePosition + 1);
}


void Logic::printChangeSavingDirectorySuccessful(){
	cout << "saving directory has been changed to   " << _directoryToBeSaved << endl;
}


void Logic::saveBasicInformationToTextFile(){
	ofstream writeFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	writeFile << _directoryToBeSaved << endl;
	writeFile << _fileNameToBeSaved << endl;
	writeFile << getScheduleSize() << endl;
	writeFile << _nextItemID << endl;
}


string Logic::convertKeywordVecToString(){
	string keywordString = "";
	if (_keywordVec.size() != 0){
		for (int i = 0; i < _keywordVec.size(); i++){
			if (i != _keywordVec.size() - 1){
				keywordString = keywordString + _keywordVec[i] + "+";
			} else{
				keywordString = keywordString + _keywordVec[i];
			}
		}
	}
	return keywordString;
}

void Logic::convertStringToKeywordVec(string keywordString){
	while (keywordString != ""){
		int breakPoint = keywordString.find_first_of("+");
		if (breakPoint != -1){
			string tokenisedKeyword = keywordString.substr(0, breakPoint);
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
	if (_directoryToBeSaved == ""){
		if (_fileNameToBeSaved == ""){
			_fileNameToBeSaved == DEFAULT_FILENAME;
		}
		return _fileNameToBeSaved;
	} else{
		return _directoryToBeSaved + "/" + _fileNameToBeSaved;
	}
}


string Logic::retrieveBasicInformation(){
	if (isExistingFileInDirectory(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME)){
		retrieveBasicInformationFromTextFile();
		return MESSAGE_RETRIEVED_FROM_TEXT_FILE;
	} else {
		//new user or basicinformation textfile is corrupted
		createNewTextFile();
		return MESSAGE_FILE_NOT_EXISTING;
	}
}


string Logic::retrieveBasicInformationFromTextFile(){
	ifstream readFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	getline(readFile, _directoryToBeSaved);
	getline(readFile, _fileNameToBeSaved);
	readFile >> _scheduleSize;
	readFile >> _nextItemID;

	cout << _directoryToBeSaved + "/" + _fileNameToBeSaved << endl;

	if (_directoryToBeSaved == ""){
		if (_fileNameToBeSaved == ""){
			_fileNameToBeSaved == DEFAULT_FILENAME;
		}
		return _fileNameToBeSaved;
	} else{
		return _directoryToBeSaved + "/" + _fileNameToBeSaved;
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
		for (unsigned int lineNumber = 0; lineNumber < _scheduleSize; lineNumber++){

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
			if (completionIndicator != 0){
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
	cout << "Schedule retrieived" << endl;
	resetAndGetDisplaySchedule();
	sortTask();
	cout << "SORT : " << _currentSorting << endl;
	cout << "Filter : " << _currentFilter << endl;
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
	string errorString = "";
	for (iter = errorList.begin(); iter != errorList.end(); ++iter){
		errorString = errorString + *iter + " ";
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
	if (getDisplayScheduleSize() >= lineIndexToBeChecked && lineIndexToBeChecked > 0){
		return true;
	} else{
		return false;
	}
}


