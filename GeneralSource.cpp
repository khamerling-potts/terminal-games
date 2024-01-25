#include <iostream>
#include "GeneralSource.h"

using namespace std;

int usageMessage(string programName1, string fileName1) {
	cout << "usage: " << programName1 << " <" << fileName1 << ">" << endl;
	return argumentFail;
}

void convertToLower(string &s) {
	for (unsigned int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) {
			s[i] += 'a' - 'A';
		}
	}
}