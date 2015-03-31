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
const string Logic::MODIFIER_COMPLETION = "completion";
const string Logic::SORT_NAME = "name";
const string Logic::SORT_DATE = "date";
const string Logic::SORT_PRIORITY = "priority";
const string Logic::SORT_COMPLETION = "completion";
const string Logic::SORT_LAST_UPDATE = "update";


const string Logic::TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME = "directory.txt";
const string Logic::DEFAULT_FILENAME = "save.txt";
const string Logic::DEFAULT_SORTING = "update";

const string Logic::MESSAGE_SUCCESSFUL_ADD = "successful_add";
const string Logic::MESSAGE_SUCCESSFUL_DELETE = "successful_delete";
const string Logic::MESSAGE_SUCCESSFUL_EDIT = "successful_edit";
const string Logic::MESSAGE_SUCCESSFUL_SORT = "successful_sort";
const string Logic::MESSAGE_SUCCESSFUL_VIEW = "successful_view";
const string Logic::MESSAGE_SUCCESSFUL_SAVE = "successful_save";
const string Logic::MESSAGE_SUCCESSFUL_UNDO = "successful_undo";

const string Logic::MESSAGE_FAILED_ADD = "failed_add";
const string Logic::MESSAGE_FAILED_DELETE = "failed_delete";
const string Logic::MESSAGE_FAILED_EDIT = "failed_edit";
const string Logic::MESSAGE_FAILED_VIEW = "failed_view";
const string Logic::MESSAGE_FAILED_SAVE = "failed_save";
const string Logic::MESSAGE_FAILED_UNDO = "failed_undo";
const string Logic::MESSAGE_FAILED_SORT = "failed_sort";

char Logic::buffer[300];
const string Logic::ADD_TASK_SUCCESSFUL = "Task is added to schedule";
const string Logic::DELETE_TASK_SUCCESSFUL = "Task %d is removed from schedule";


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


void Logic::printInvalidInput(){
	cout << "Error: " << MESSAGE_INVALID_INPUT << endl << endl;
}


string Logic::addTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed){
	unsigned int addedItemID = DEFAULT_ITEM_ID;

	Item *newItemToBeAdded;
	newItemToBeAdded = new Item;
	setItemNameAndIDForNewItem(newItemToBeAdded, parseInfoToBeProcessed);
	modifyItem(parseInfoToBeProcessed, newItemToBeAdded);
	cout << "ItemID : " << newItemToBeAdded->getItemID() << endl;
	ItemVerification verifier(*newItemToBeAdded, _nextItemID);
	if (verifier.isValidItem()) {
		string addCompleted = _logicSchedule.addItem(newItemToBeAdded);
		addedItemID = _nextItemID;
		increaseItemID();
		resetAndPrintSchedule();
		printAddTaskSuccessful(addCompleted);
		return MESSAGE_SUCCESSFUL_ADD;
	}
	else{
		printErrorList(verifier);
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


vector<Item> Logic::resetAndPrintSchedule(){
	vector<Item> retrievedDisplaySchedule = resetAndGetDisplaySchedule();
	printSchedule(retrievedDisplaySchedule);
	return retrievedDisplaySchedule;
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
	}
	else if (modifier == MODIFIER_START){
		itemToBeModified->setStartTime(interpreteDateTime(iter->text));
	}
	else if (modifier == MODIFIER_END){
		itemToBeModified->setEndTime(interpreteDateTime(iter->text));
	}
	else if (modifier == MODIFIER_LABEL){
		char labelToBeModified = iter->text[0];
		itemToBeModified->setLabel(labelToBeModified);
	}
	else if (modifier == MODIFIER_PRIORITY){
		char priorityToBeModified = iter->text[0];
		itemToBeModified->setPriority(priorityToBeModified);
	}
}

DateTime Logic::interpreteDateTime(string infoToBeInterpreted){
	istringstream inputTime(infoToBeInterpreted);
	int YYYY, MM, DD, hh, mm;
	inputTime >> YYYY >> MM >> DD >> hh >> mm;
	if (mm == -1) {
		mm = 0;
	}
	if (MM != -1 && DD != -1 && YYYY == -1) {

	}
	DateTime interpretedDateTime(YYYY, MM, DD, hh, mm);
	return interpretedDateTime;
}


bool Logic::isValidSortingMethod(string itemInformation){
	if (itemInformation == SORT_NAME || itemInformation == SORT_COMPLETION || itemInformation == SORT_DATE ||
		itemInformation == SORT_LAST_UPDATE || itemInformation == SORT_PRIORITY){
		return true;
	}
	else{
		return false;
	}
}

bool Logic::isValidItemInLogic(Item itemToBeChecked){
	ItemVerification itemVerifier(itemToBeChecked, _nextItemID);
	if (itemVerifier.isValidItem()) {
		return true;
	}
	else {
		return false;
	}
}


string Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	//try{
	if (isValidLineIndex(lineIndexToBeDeleted)){
		cout << "lineIndex : " << lineIndexToBeDeleted << endl;
		string deletedItem = _logicSchedule.deleteItemGivenDisplayVectorIndex(lineIndexToBeDeleted);
		printDeleteTaskSuccessful(lineIndexToBeDeleted);
		_scheduleSize--;//Delete successful
		resetAndPrintSchedule();
		return MESSAGE_SUCCESSFUL_DELETE;
	}
	else{
		//	throw(MESSAGE_INVALID_INPUT_FOR_DELETE); //Delete failed
		resetAndPrintSchedule();
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
	}
	else{
		return false;
	}
}



unsigned int Logic::getScheduleSize(){
	_scheduleSize = _logicSchedule.getSizeOfDisplaySchedule();
	return _scheduleSize;
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
	if (command == COMMAND_ADD) {
		returnMessage = addTask(parseInfoToBeProcessed);
	}
	else if (command == COMMAND_DELETE) {
		unsigned int lineIndexToBeDeleted = convertToDigit(itemInformation);
		returnMessage = deleteTask(lineIndexToBeDeleted);
	}

	else if (command == COMMAND_EDIT){
		unsigned int lineIndexToBeEdited = convertToDigit(itemInformation);
		returnMessage = editTask(parseInfoToBeProcessed, lineIndexToBeEdited);
	}
	else if (command == COMMAND_UNDO){

	}
	else if (command == COMMAND_SORT){
		returnMessage = changeCurrentSorting(itemInformation);
	}
	else if (command == COMMAND_SEARCH){

	}
	else if (command == COMMAND_VIEW){

	}
	else if (command == COMMAND_SAVE){
		changeSavingDirectory(itemInformation);
		returnMessage = MESSAGE_SUCCESSFUL_SAVE;
	}
	else if (command == COMMAND_EXIT){
		saveDirectoryToTextFile();
		exit(0);
	}
	else {
		printInvalidInput();
		returnMessage = MESSAGE_INVALID_INPUT;
	}
	thingsToDoAfterEveryExecution();
	return returnMessage;
}




string Logic::changeCurrentSorting(string itemInformation){
	if (isValidSortingMethod(itemInformation)){
		_currentSorting = itemInformation;
		return MESSAGE_SUCCESSFUL_SORT;
	}
	else {
		printInvalidInput();
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
			resetAndPrintSchedule();
			return MESSAGE_SUCCESSFUL_EDIT;
		}
		else{
			printErrorList(verifier);
			return MESSAGE_FAILED_EDIT;
		}
	}
	else{
		return MESSAGE_INVALID_INPUT;
	}
}


string Logic::sortTask(){
	vector<Item> sortedDisplaySchedule = resetAndGetDisplaySchedule();
	if (_currentSorting == SORT_NAME){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByItemName();
	}
	else if (_currentSorting == SORT_PRIORITY){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByPriority();
	}
	else if (_currentSorting == SORT_COMPLETION){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByCompletionStatus();
	}
	else if (_currentSorting == SORT_DATE){
		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByDate();
	}
	//	else if (_currentSorting == SORT_LAST_UPDATE){
	//		sortedDisplaySchedule = _logicSchedule.retrieveDisplayScheduleByLastUpdate();
	//	}
	else{
		return MESSAGE_FAILED_SORT;
	}
	printSchedule(sortedDisplaySchedule);
	return MESSAGE_SUCCESSFUL_SORT;
}

/*

vector<Item> Logic::searchTask(string phraseToSearch){
vector<Item> searchedItems;
Item foundItem;
unsigned int lineIndex;
unsigned int scheduleSize = getScheduleSize();
for (lineIndex = 0; lineIndex < scheduleSize; lineIndex++){
if (isFound(lineIndex, phraseToSearch)){
foundItem = getItemFromLineIndex(lineIndex);
searchedItems.push_back(foundItem);
}
}
return searchedItems;
}

bool Logic::isFound(int lineIndex, string& phraseToSearch){
Item itemFromLogicSchedule;
itemFromLogicSchedule = getItemFromLineIndex(lineIndex);
unsigned int phraseFoundFromItemName;
unsigned int phraseFoundFromItemDescription;
phraseFoundFromItemName = itemFromLogicSchedule.getItemName().find(phraseToSearch);
if (phraseFoundFromItemName != string::npos) {
return true;
}
phraseFoundFromItemDescription = itemFromLogicSchedule.getDescription().find(phraseToSearch);
if (phraseFoundFromItemDescription != string::npos) {
return true;
}
return false;
}
*/


string Logic::changeSavingDirectory(string userInputDirectory){
	string directoryToMake = "";
	int truncatePosition;

	while (userInputDirectory != ""){
		truncatePosition = userInputDirectory.find_first_of("/");
		if (truncatePosition != -1){
			directoryToMake = directoryToMake + assignOneFolderToMake(truncatePosition, userInputDirectory);
			userInputDirectory = truncateUserInputDirectory(truncatePosition, userInputDirectory);
		}
		else{
			directoryToMake = assignLastFolderToMake(userInputDirectory, directoryToMake);
			userInputDirectory = "";
		}
		_mkdir(directoryToMake.c_str());
	}
	_directoryToBeSaved = directoryToMake;
	saveDirectoryToTextFile();
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


void Logic::saveDirectoryToTextFile(){
	ofstream writeFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	writeFile << _directoryToBeSaved << endl;
	writeFile << _fileNameToBeSaved << endl;
	writeFile << getScheduleSize() << endl;
	writeFile << _currentSorting;
}

string Logic::getDirectoryAndFileName(){
	if (_directoryToBeSaved == ""){
		if (_fileNameToBeSaved == ""){
			_fileNameToBeSaved == DEFAULT_FILENAME;
		}
		return _fileNameToBeSaved;
	}
	else{
		return _directoryToBeSaved + "/" + _fileNameToBeSaved;
	}
}

string Logic::retrieveDirectoryFromTextFile(){
	ifstream readFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	getline(readFile, _directoryToBeSaved);
	getline(readFile, _fileNameToBeSaved);
	readFile >> _scheduleSize;
	readFile >> _currentSorting;
	cout << _directoryToBeSaved + "/" + _fileNameToBeSaved << endl;

	if (_directoryToBeSaved == ""){
		if (_fileNameToBeSaved == ""){
			_fileNameToBeSaved == DEFAULT_FILENAME;
		}
		return _fileNameToBeSaved;
	}
	else{
		return _directoryToBeSaved + "/" + _fileNameToBeSaved;
	}
}

string Logic::changeSavingFileName(string FileNameToBeSaved){
	_fileNameToBeSaved = FileNameToBeSaved;
	saveDirectoryToTextFile();
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
		getline(readFile, itemName);
		getline(readFile, itemID);
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
		item->setStartTime(startTime);
		item->setEndTime(EndTime);
		item->setDescription(description);
		item->setPriority(priority);
		item->setLabel(label);
		_logicSchedule.addItem(item);
	}
	cout << "Schedule retrieived" << endl;
	resetAndPrintSchedule();
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
	saveDirectoryToTextFile();
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
