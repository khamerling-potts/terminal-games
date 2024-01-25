#pragma once

#include <iostream>
#include <string>
#include "ctype.h"


//useful enums for multiple labs
enum ordinal {
	programName,
	fileName,
	arguments
};
enum message {
	success,
	fileFail,
	argumentFail,
	exceptionThrown,
	invalid_dimensions
};

//convert to lowercase
void convertToLower(std::string& s);
//usage message
int usageMessage(std::string programName1, std::string fileName1);