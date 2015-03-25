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

const string Logic::TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME = "directory.txt";
const string Logic::DEFAULT_FILENAME = "save.txt";

const string Logic::MESSAGE_SUCCESSFUL = "success";
const string Logic::MESSAGE_FAILED = "fail";

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
}

Logic::~Logic() {}

void Logic::printSchedule(){
	cout << endl;
	cout << "SCHEDULE" << endl;
	cout << "--------" << endl;
	for (unsigned int lineNumber = 0; lineNumber < getScheduleSize(); lineNumber++){
		cout << lineNumber + 1 << ". " << endl;
		printItem(getSchedule()[lineNumber].displayItemForUser());
		cout << endl;
	}
	cout << endl;
}

void Logic::printItem(string itemToBePrinted){
	cout << itemToBePrinted;
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
	ItemVerification verifier(*newItemToBeAdded, _nextItemID);
	if (verifier.isValidItem()) {
		string addCompleted = _logicSchedule.addItem(newItemToBeAdded);
		addedItemID = _nextItemID;
		increaseItemIDAndScheduleSize();
		printAddTaskSuccessful(addCompleted);
		printSchedule();
		return MESSAGE_SUCCESSFUL;
	}
	else{
		printSchedule();
		return MESSAGE_FAILED;
	}
}

void Logic::increaseItemIDAndScheduleSize(){
	_nextItemID++;
	_scheduleSize++;
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
}

DateTime Logic::interpreteDateTime(string infoToBeInterpreted){
	istringstream inputTime(infoToBeInterpreted);
	int YYYY, MM, DD, hh, mm;
	inputTime >> YYYY >> MM >> DD >> hh >> mm;
	DateTime interpretedDateTime(YYYY, MM, DD, hh, mm);
	return interpretedDateTime;
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

//passing line index, not itemID
string Logic::deleteTask(int lineIndexToBeDeleted){

	try{
		if (isValidLineIndex(lineIndexToBeDeleted)){
			cout << "lineIndex : " << lineIndexToBeDeleted << endl;
			string deletedItem = _logicSchedule.deleteItemGivenDisplayVectorIndex(lineIndexToBeDeleted);
			printDeleteTaskSuccessful(lineIndexToBeDeleted);
			_scheduleSize--;//Delete successful
			printSchedule();
			return MESSAGE_SUCCESSFUL;
		}
		else{
			throw(MESSAGE_INVALID_INPUT_FOR_DELETE); //Delete failed
			printSchedule();
		}
	}
	catch (const char* e){
		cout << e << endl;
	}
	return MESSAGE_FAILED;
}


bool Logic::isValidLineIndex(unsigned int lineIndexToBeChecked){
	if (getScheduleSize() >= lineIndexToBeChecked){
		return true;
	}
	else{
		return false;
	}
}

vector<Item> Logic::getSchedule(){
	return _logicSchedule.retrieveSchedule();
}

unsigned int Logic::getScheduleSize(){
	return _logicSchedule.getSizeOfSchedule();
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
	cout << "command : " << command << endl;
	cout << "itemInfo : " << itemInformation << endl;
	if (command == COMMAND_ADD) {
		returnMessage = addTask(parseInfoToBeProcessed);
	}
	else if (command == COMMAND_DELETE) {
		unsigned int lineIndexToBeDeleted = convertToDigit(itemInformation);
		returnMessage = deleteTask(lineIndexToBeDeleted);
	}
	else if (command == COMMAND_EXIT){
		saveDirectoryToTextFile();
		exit(0);
	}
	else if (command == COMMAND_EDIT){
		unsigned int lineIndexToBeEdited = convertToDigit(itemInformation);
		//	returnMessage = editTask(parseInfoToBeProcessed, lineIndexToBeEdited);
	}
	else if (command == COMMAND_UNDO){

	}
	else if (command == COMMAND_SORT){

	}
	else if (command == COMMAND_SEARCH){

	}
	else if (command == COMMAND_VIEW){

	}
	else if (command == COMMAND_SAVE){
		string directoryToBeChanged = itemInformation;
		changeSavingDirectory(directoryToBeChanged);
	}
	else {
		printInvalidInput();
	}
	return returnMessage;
}


/*
string Logic::editTask(list<COMMAND_AND_TEXT> parseInfoToBeProcessed, unsigned int lineIndexToBeEdited){
Item *editedItemToBeReplaced;
editedItemToBeReplaced = new Item;
*editedItemToBeReplaced = _logicSchedule.retrieveItem(lineIndexToBeEdited);
modifyItem(parseInfoToBeProcessed, editedItemToBeReplaced);
_logicSchedule.replaceItem(editedItemToBeReplaced, itemIDToBeEdited);
printSchedule();
return MESSAGE_SUCCESSFUL;
}

*/
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

string Logic::changeSavingDirectory(string directoryToBeSaved){
	string directoryToMake = "";
	int truncateDirectory;

	while (directoryToBeSaved != ""){
		truncateDirectory = directoryToBeSaved.find_first_of('/');
		if (truncateDirectory != -1){
			assignDirectorySpecifiedByUser(directoryToBeSaved, directoryToMake, truncateDirectory);
		}
		else {
			assignDefaultDirectory(directoryToBeSaved, directoryToMake);
		}
		_mkdir(directoryToMake.c_str());
	}
	_directoryToBeSaved = directoryToMake;
	return directoryToMake;
}
void Logic::assignDirectorySpecifiedByUser(string directoryToBeSaved, string directoryToMake, int truncateDirectory){
	directoryToMake = directoryToMake + directoryToBeSaved.substr(0, truncateDirectory + 1);
	directoryToBeSaved = directoryToBeSaved.substr(truncateDirectory + 1);
	return;
}
void Logic::assignDefaultDirectory(string directoryToBeSaved, string directoryToMake){
	directoryToMake = directoryToMake + directoryToBeSaved;
	directoryToBeSaved = "";
	return;
}
void Logic::saveDirectoryToTextFile(){
	ofstream writeFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
	writeFile << _directoryToBeSaved << endl;
	writeFile << _fileNameToBeSaved << endl;
	writeFile << _scheduleSize;
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
/*
int Logic::readDataFromFile() {
ifstream readFile(getDirectoryAndFileName());
for (unsigned int lineNumber = 0; lineNumber < _scheduleSize; lineNumber++){
//while (!readFile.eof()){
string itemName;
string description;
string junk;
char priority;
char label;
int DD;
int MM;
int YYYY;
int hh;
int mm;
getline(readFile, itemName);
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
Item item;
item.setItemName(itemName);
item.setStartTime(startTime);
item.setEndTime(EndTime);
item.setDescription(description);
item.setPriority(priority);
item.setLabel(label);
_logicSchedule.addItem(item);
}
cout << "Schedule received" << endl;
printSchedule();
return 1;
}

int Logic::writeDataOntoFile(){
ofstream writeFile(getDirectoryAndFileName());
for (unsigned int lineNumber = 0; lineNumber < _logicSchedule.getSizeOfSchedule(); lineNumber++){
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getItemName() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getYear() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getMonth() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getDay() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getHour() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getMinute() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getYear() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getMonth() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getDay() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getHour() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getMinute() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getDescription() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getPriority() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getLabel() << endl;
}
saveDirectoryToTextFile();
return 1;
}
*/

