#include "Logic.h"
#include <exception>

const string Logic::MESSAGE_SUCCESS = "execution success";
const string Logic::MESSAGE_INVALID_INPUT = "invalid input";
const string Logic::MESSAGE_INVALID_INPUT_FOR_DELETE = "invalid input for delete task";
const string Logic::COMMAND_ADD = "add";
const string Logic::COMMAND_DELETE = "delete";
const string Logic::COMMAND_EDIT = "edit";
const string Logic::COMMAND_UNDO = "undo";
const string Logic::COMMAND_SORT = "sort";
const string Logic::COMMAND_SEARCH = "search";
const string Logic::COMMAND_VIEW = "view";
const string Logic::COMMAND_DONE = "done";
const string Logic::COMMAND_SAVE = "save";
const string Logic::COMMAND_EXIT = "exit";
const string Logic::MODIFIER_START = "start";
const string Logic::MODIFIER_END = "end";
const string Logic::MODIFIER_DESCRIPTION = "description";
const string Logic::MODIFIER_LABEL = "label";
const string Logic::MODIFIER_PRIORITY = "priority";
const string Logic::MODIFIER_COMPLETION = "done";
const string Logic::SORT_NAME = "name";
const string Logic::SORT_DATE = "date";
const string Logic::SORT_PRIORITY = "priority";
const string Logic::SORT_COMPLETION = "completion";
const string Logic::SORT_LAST_UPDATE = "update";
const string Logic::FILTER_COMPLETION = "done";
const string Logic::FILTER_PRIORITY = "priority";
const string Logic::FILTER_LABEL = "label";
const string Logic::FILTER_ALL = "all";


const string Logic::TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME = "basicinformation.txt";
const string Logic::DEFAULT_FILENAME = "save.txt";
const string Logic::DEFAULT_SORTING = "update";

const string Logic::MESSAGE_SUCCESSFUL_ADD = "Task added to Schedule";
const string Logic::MESSAGE_SUCCESSFUL_DELETE = "Task deleted from Schedule";
const string Logic::MESSAGE_SUCCESSFUL_EDIT = "Task edited";
const string Logic::MESSAGE_SUCCESSFUL_SORT = "Schedule sorted";
const string Logic::MESSAGE_SUCCESSFUL_VIEW = "Schedule filtered";
const string Logic::MESSAGE_SUCCESSFUL_SAVE = "Save directory changed";
const string Logic::MESSAGE_SUCCESSFUL_UNDO = "Last action reversed";
const string Logic::MESSAGE_SUCCESSFUL_MARK_DONE = "Task is completed";

const string Logic::MESSAGE_FAILED_ADD = "Sorry, Task was not added to Schedule";
const string Logic::MESSAGE_FAILED_DELETE = "Sorry, Task was not deleted from Schedule";
const string Logic::MESSAGE_FAILED_EDIT = "Sorry, Unable to edit the specified Task";
const string Logic::MESSAGE_FAILED_VIEW = "Schedule not filtered";
const string Logic::MESSAGE_FAILED_SAVE = "Sorry, save directory not changed";
const string Logic::MESSAGE_FAILED_UNDO = "Sorry, last action was not reversed";
const string Logic::MESSAGE_FAILED_SORT = "Sorry, Schedule was not sorted";
const string Logic::MESSAGE_INVALID_PRIORITY = "Invalid Priority Type";

char Logic::buffer[300];
const string Logic::ADD_TASK_SUCCESSFUL = "Task is added to schedule";
const string Logic::DELETE_TASK_SUCCESSFUL = "Task %d is removed from schedule";
const string Logic::EDIT_TASK_SUCCESSFUL = "Task %d is edited from schedule";
const string Logic::SORT_TASK_SUCCESSFUL = "Sorting Changed to : ";
const string Logic::MARK_DONE_SUCCESSFUL = "Task %d is done";
const string Logic::TASK_FOUND = "Tasks are found";

const string Logic::ADD_TASK_FAILED = "Task cannot be added to schedule";
const string Logic::DELETE_TASK_FAILED = "Task cannot be removed from schedule";
const string Logic::INVALID_LINE_INDEX = "invalid line index";
const string Logic::SORT_TASK_FAILED = "Invalid Sort Method";
const string Logic::EDIT_TASK_FAILED = "Task cannot be edited from schedule";
const string Logic::NO_TASK_FOUND = "No item can be found";

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
	//default sorting is by last update
	_currentFilter = FILTER_ALL;
	//default filter is view all

}


Logic::~Logic() {}


void Logic::printSchedule(vector<Item> retrievedDisplaySchedule){
	cout << endl;
	cout << "SCHEDULE" << endl;
	cout << "--------" << endl;
	for (unsigned int lineNumber = 0; lineNumber < retrievedDisplaySchedule.size(); lineNumber++){
		cout << lineNumber + 1 << ". " << endl;
		printItem(retrievedDisplaySchedule[lineNumber]);
		cout << endl;
	}
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
	printErrorList(verifier);
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

void Logic::printSortTaskFailed(){
	cout << SORT_TASK_FAILED << endl;
	return;
}
void Logic::printEditTaskInvalidItemParts(ItemVerification verifier){
	cout << EDIT_TASK_FAILED << endl;
	printErrorList(verifier);
	return;
}

void Logic::printInvalidInput(){
	cout << "Error: " << MESSAGE_INVALID_INPUT << endl << endl;
}

void Logic::printInvalidLineIndex(){
	cout << INVALID_LINE_INDEX << endl;
}

string Logic::addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed){
	unsigned int addedItemID = DEFAULT_ITEM_ID;

	Item *newItemToBeAdded;
	newItemToBeAdded = new Item;
	setItemNameAndIDForNewItem(newItemToBeAdded, parseInfoToBeProcessed);
	modifyItem(parseInfoToBeProcessed, newItemToBeAdded);
	ItemVerification verifier(*newItemToBeAdded, _nextItemID);
	if (verifier.isValidItem()) {
		string addCompleted = _logicSchedule.addItem(newItemToBeAdded);
		addedItemID = _nextItemID;
		increaseItemID();
		printAddTaskSuccessful(addCompleted);
		newItemToBeAdded = NULL;
		delete newItemToBeAdded;
		return MESSAGE_SUCCESSFUL_ADD;
	} else{

		printAddTaskFailed(verifier);
		newItemToBeAdded = NULL;
		delete newItemToBeAdded;
		return MESSAGE_FAILED_ADD;
	}
}


vector<Item> Logic::resetDisplaySchedule(){
	_logicSchedule.resetDisplaySchedule();
	return getDisplaySchedule();
}


vector<Item> Logic::getDisplaySchedule(){
	return _logicSchedule.retrieveDisplaySchedule();
}


vector<Item> Logic::resetAndGetDisplaySchedule(){
	_logicSchedule.resetDisplaySchedule();
	vector<Item>retrievedDisplaySchedule = _logicSchedule.retrieveDisplaySchedule();
	return retrievedDisplaySchedule;
}


unsigned int Logic::increaseItemID(){
	_nextItemID++;
	return _nextItemID;
}



void Logic::setItemNameAndIDForNewItem(Item *newItem, list<COMMAND_AND_TEXT> parseInfoToBeProcessed){
	newItem->setItemName(parseInfoToBeProcessed.begin()->text);
	newItem->setItemID(_nextItemID);
}


void Logic::modifyItem(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, Item* itemToBeModified){
	list<COMMAND_AND_TEXT>::iterator iter;
	for (iter = ++parseInfoToBeProcessed.begin(); iter != parseInfoToBeProcessed.end(); ++iter){
		modifyItemParts(iter, itemToBeModified);
	}
}


void Logic::modifyItemParts(list<COMMAND_AND_TEXT>::iterator iter, Item* itemToBeModified){
	string modifier = iter->command;
	if (modifier == MODIFIER_DESCRIPTION){
		string descriptionToBeAdded = iter->text;
		itemToBeModified->setDescription(descriptionToBeAdded);
	} else if (modifier == MODIFIER_START){
		DateTime startTimeToBeModified = itemToBeModified->getStartTime();
		itemToBeModified->setStartTime(interpreteDateTime(iter->text,itemToBeModified->getStartTime()));
	} else if (modifier == MODIFIER_END){
		itemToBeModified->setEndTime(interpreteDateTime(iter->text,itemToBeModified->getEndTime()));
	} else if (modifier == MODIFIER_LABEL){
		char labelToBeModified = iter->text[0];
		itemToBeModified->setLabel(labelToBeModified);
	} else if (modifier == MODIFIER_PRIORITY){
		char priorityToBeModified = checkPriority(iter->text);
		itemToBeModified->setPriority(priorityToBeModified);
	} else if (modifier == MODIFIER_COMPLETION){
		bool done = true;
		itemToBeModified->setCompletion(done);
	}
}
char Logic::checkPriority(string priorityToBeModified){
	if (priorityToBeModified == "high" || priorityToBeModified == "h" || priorityToBeModified == "H"){
		return 'H';
	} else if (priorityToBeModified == "medium" || priorityToBeModified == "m" || priorityToBeModified == "M"){
		return 'M';
	} else if (priorityToBeModified == "low" || priorityToBeModified == "l" || priorityToBeModified == "L"){
		return 'L';
	} else
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

	if (YYYY == -1 && YYYY2 == -1 && MM == -1 && MM2 == -1 && DD == -1 && DD2 == -1){
		YYYY = getCurrentTime().getYear();
		MM = getCurrentTime().getMonth();
		DD = getCurrentTime().getDay();
	}

	if (YYYY == -1 && YYYY2 == -1){
		YYYY = getCurrentTime().getYear();
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


bool Logic::isValidSortingMethod(string itemInformation){
	if (itemInformation == SORT_NAME || itemInformation == SORT_COMPLETION || itemInformation == SORT_DATE ||
		itemInformation == SORT_LAST_UPDATE || itemInformation == SORT_PRIORITY){
		return true;
	} else{
		return false;
	}
}

bool Logic::isValidItemInLogic(Item itemToBeChecked){
	ItemVerification itemVerifier(itemToBeChecked, _nextItemID);
	if (itemVerifier.isValidItem()) {
		return true;
	} else {
		return false;
	}
}


string Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	//try{
	if (isValidLineIndex(lineIndexToBeDeleted)){
		string deletedItem = _logicSchedule.deleteItemGivenDisplayVectorIndex(lineIndexToBeDeleted);
		printDeleteTaskSuccessful(lineIndexToBeDeleted);
		_scheduleSize--;//Delete successful
		return MESSAGE_SUCCESSFUL_DELETE;
	} else{
		//	throw(MESSAGE_INVALID_INPUT_FOR_DELETE); //Delete failed
		printDeleteTaskFailed();
		return MESSAGE_FAILED_DELETE;
	}
	//}
	//catch (const char* e){
	//	cout << e << endl;
	//}

}



bool Logic::isValidLineIndex(unsigned int lineIndexToBeChecked){
	if (getScheduleSize() >= lineIndexToBeChecked){
		return true;
	} else{
		return false;
	}
}

unsigned int Logic::getScheduleSize(){
	_scheduleSize = _logicSchedule.getSizeOfSchedule();
	return _scheduleSize;
}

unsigned int Logic::getDisplayScheduleSize(){
	return _logicSchedule.getSizeOfDisplaySchedule();
}


list<string> Logic::getErrorList(ItemVerification verifier){
	return verifier.getItemVerificationErrors();
}


list<string> Logic::printErrorList(ItemVerification verifier){
	list<string> errorList = getErrorList(verifier);
	list<string>::iterator iter;
	for (iter = errorList.begin(); iter != errorList.end(); ++iter){
		cout << *iter << endl;
	}
	return errorList;
}


list<COMMAND_AND_TEXT> Logic::getParseInfo(iParser parser, string input){
	parser.parse(input);
	return parser.getParseInfo();
}


int Logic::convertToDigit(string text) {
	int digit;
	istringstream convert(text);
	convert >> digit;
	return digit;
}



string Logic::initiateCommandAction(iParser parser, string input) {
	list<COMMAND_AND_TEXT> parseInfoToBeProcessed = getParseInfo(parser, input);
	string command = parseInfoToBeProcessed.begin()->command;
	string itemInformation = parseInfoToBeProcessed.begin()->text;
	string returnMessage;
	/*Debugging*//*
	list<COMMAND_AND_TEXT>::iterator iter;
	for (iter = parseInfoToBeProcessed.begin(); iter != parseInfoToBeProcessed.end(); ++iter){
		cout << "command : " << iter->command << endl;
		cout << "text : " << iter->text << endl;
	}*/
	/*Debegging Done*/
	if (command == COMMAND_ADD) {
		returnMessage = addTask(parseInfoToBeProcessed);
	} else if (command == COMMAND_DELETE) {
		unsigned int lineIndexToBeDeleted = convertToDigit(itemInformation);
		returnMessage = deleteTask(lineIndexToBeDeleted);
	} else if (command == COMMAND_EDIT){
		unsigned int lineIndexToBeEdited = convertToDigit(itemInformation);
		returnMessage = editTask(parseInfoToBeProcessed, lineIndexToBeEdited);
	} else if (command == COMMAND_UNDO){
		returnMessage = _logicSchedule.undoLastCommand();
		cout << "Undo Previous command" << endl;
	} else if (command == COMMAND_SORT){
		returnMessage = changeCurrentSorting(itemInformation);
	} else if (command == COMMAND_SEARCH){
		returnMessage = searchTask(itemInformation);
	} else if (command == COMMAND_VIEW){
		returnMessage = filterTask(itemInformation);
	} else if (command == COMMAND_SAVE){
		changeSavingDirectory(itemInformation);
		returnMessage = MESSAGE_SUCCESSFUL_SAVE;
	} else if (command == COMMAND_EXIT){
		saveBasicInformationToTextFile();
		exit(0);
	}else if(command == COMMAND_DONE){
		unsigned int lineIndex = convertToDigit(itemInformation);
		returnMessage = markDone(lineIndex);
	} else {
		printInvalidInput();
		returnMessage = MESSAGE_INVALID_INPUT;
	}
	thingsToDoAfterEveryExecution();
	return returnMessage;
}


string Logic::markDone(unsigned int lineIndex){
	if (lineIndex <= getDisplayScheduleSize()){
		Item* retrievedItem;
		retrievedItem = new Item;
		*retrievedItem = _logicSchedule.retrieveItemGivenDisplayVectorIndex(lineIndex);
		bool done = true;
		retrievedItem->setCompletion(done);
		_logicSchedule.replaceItemGivenDisplayVectorIndex(retrievedItem, lineIndex);
		printMarkDoneSuccessful(lineIndex);
		retrievedItem = NULL;
		delete retrievedItem;
		return MESSAGE_SUCCESSFUL_MARK_DONE;
	} else{
		printInvalidLineIndex();
		return INVALID_LINE_INDEX;
	}
}


string Logic::changeCurrentSorting(string itemInformation){
	if (isValidSortingMethod(itemInformation)){
		_currentSorting = itemInformation;
		printSortTaskSuccessful();
		return MESSAGE_SUCCESSFUL_SORT;
	} else {
		printSortTaskFailed();
		return MESSAGE_FAILED_SORT;
	}
}



string Logic::editTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, unsigned int lineIndexToBeEdited){
	if (lineIndexToBeEdited <= getDisplaySchedule().size()){
		Item *editedItemToBeReplaced;
		editedItemToBeReplaced = new Item;
		*editedItemToBeReplaced = _logicSchedule.retrieveItemGivenDisplayVectorIndex(lineIndexToBeEdited);
		modifyItem(parseInfoToBeProcessed, editedItemToBeReplaced);
		ItemVerification verifier(*editedItemToBeReplaced, editedItemToBeReplaced->getItemID());
		if (verifier.isValidItem()){
			_logicSchedule.replaceItemGivenDisplayVectorIndex(editedItemToBeReplaced, lineIndexToBeEdited);
			editedItemToBeReplaced = NULL;
			delete editedItemToBeReplaced;
			return MESSAGE_SUCCESSFUL_EDIT;
		} else{
			editedItemToBeReplaced = NULL;
			delete editedItemToBeReplaced;
			printEditTaskInvalidItemParts(verifier);
			return MESSAGE_FAILED_EDIT;
		}
	} else{
		printEditTaskInvalidLineIndex();
		return MESSAGE_INVALID_INPUT;
	}
}

string Logic::filterTask(string filterToBeImplemented){
	istringstream iss(filterToBeImplemented);
	string filterType;
	string modifierType;
	iss >> filterType >> modifierType;
	if (filterType == FILTER_COMPLETION){
		bool done = true;
		_logicSchedule.retrieveDisplayScheduleFilteredByCompletion(done);
		_currentFilter = FILTER_COMPLETION;
	}/* else if (filterType == FILTER_LABEL) {
		_logicSchedule.retrieveDisplayScheduleFilteredByLabel(modifierType);
	} */else if (filterType == FILTER_PRIORITY){
		char priorityType = checkPriority(modifierType);
		if (priorityType != 'E'){
			_logicSchedule.retrieveDisplayScheduleFilteredByPriority(priorityType);
			_currentFilter = FILTER_PRIORITY;
		} else {
			return MESSAGE_INVALID_PRIORITY;
		}
	} else if (filterType == FILTER_ALL){
		_currentFilter = FILTER_ALL;
	}else{
		return MESSAGE_FAILED_VIEW;
	}
	return MESSAGE_SUCCESSFUL_VIEW;
}
string Logic::sortTaskWithFilter(){
	vector<Item> sortedDisplaySchedule = getDisplaySchedule();
	if (_currentSorting == SORT_NAME){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByItemName();
	} else if (_currentSorting == SORT_PRIORITY){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByPriority();
	} else if (_currentSorting == SORT_COMPLETION){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByCompletionStatus();
	} else if (_currentSorting == SORT_DATE){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByDate();
	} /*else if (_currentSorting == SORT_LAST_UPDATE){
	  sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByLastUpdate();
	  } */else{
		return MESSAGE_FAILED_SORT;
	}
	printSchedule(sortedDisplaySchedule);
	return MESSAGE_SUCCESSFUL_SORT;
}


string Logic::sortTask(){
	vector<Item> sortedDisplaySchedule;
	if (_currentFilter == FILTER_ALL){
		sortedDisplaySchedule = resetAndGetDisplaySchedule();
	} else{
		sortedDisplaySchedule = getDisplaySchedule();
	}
	if (_currentSorting == SORT_NAME){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByItemName();
	} else if (_currentSorting == SORT_PRIORITY){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByPriority();
	} else if (_currentSorting == SORT_COMPLETION){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByCompletionStatus();
	} else if (_currentSorting == SORT_DATE){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByDate();
	} /*else if (_currentSorting == SORT_LAST_UPDATE){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByLastUpdate();
	} */else{
		return MESSAGE_FAILED_SORT;
	}
	printSchedule(sortedDisplaySchedule);
	return MESSAGE_SUCCESSFUL_SORT;
}

string Logic::searchTask(string keyWord){
	_logicSchedule.retrieveDisplayScheduleFilteredByKeyword(keyWord);
	if (getDisplayScheduleSize() == 0){
		return NO_TASK_FOUND;
	} else{
		_currentFilter = "keyword";
		return TASK_FOUND;
	}
}

string Logic::changeSavingDirectory(string userInputDirectory){
	string directoryToMake = "";
	int truncatePosition;
	if (userInputDirectory == "default"){
		userInputDirectory == "";
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
	writeFile << _currentSorting << endl;
	writeFile << _nextItemID << endl;
	writeFile << _currentFilter;
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

string Logic::retrieveDirectoryFromTextFile(){
	ifstream readFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	getline(readFile, _directoryToBeSaved);
	getline(readFile, _fileNameToBeSaved);
	readFile >> _scheduleSize;
	readFile >> _currentSorting;
	readFile >> _nextItemID;
	readFile >> _currentFilter;
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

string Logic::changeSavingFileName(string FileNameToBeSaved){
	_fileNameToBeSaved = FileNameToBeSaved;
	saveBasicInformationToTextFile();
	return FileNameToBeSaved;
}

int Logic::readDataFromFile() {
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
		_logicSchedule.addItem(item);
		item = NULL;
		delete item;
	}
	cout << "Schedule retrieived" << endl;
	resetAndGetDisplaySchedule();
	return 1;
}


int Logic::writeDataOntoFile(){
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
	}
	saveBasicInformationToTextFile();
	return 1;
}

vector<Item> Logic::getSchedule(){
	return _logicSchedule.retrieveSchedule();
}

string Logic::setCurrentSorting(string currentSorting){
	_currentSorting = currentSorting;
	return _currentSorting;
}


void Logic::thingsToDoAfterEveryExecution(){
	sortTask();
	writeDataOntoFile();
}

bool Logic::isExistingFileInDirectory(string directoryAndFileName) {
	ifstream infile(directoryAndFileName);
	return infile.good();
}
