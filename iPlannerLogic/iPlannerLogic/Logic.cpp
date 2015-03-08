#include "Logic.h"

Logic::Logic()
{
}


Logic::~Logic()
{
}

int Logic::writeDataOntoFile(char * fileName) {
  // Variable to denote successful processing of function
  int retCode = -1;
  ofstream outfile(fileName);

  if (!outfile.bad()) {
    
    outfile << _taskName << endl;
    outfile.close();
    retCode = 0;
  }
  
  return retCode;
}