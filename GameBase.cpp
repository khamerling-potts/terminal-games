#include "GameBase.h"
#include <sstream>
#include "TicTacToe.h"
#include "GomokuGame.h"

//repeatedly prompts the user for x and y coordinates until they input a valid pair or until they type "quit"
//a valid "quit" entry just has the word "quit", can be uppercase or lowercase, but no spaces or other characters
//negative coordinates are invalid
//coordinates with no comma (or more than one comma) are invalid
//coordinates with any characters besides two comma separated digits and spaces are invalid. (0 1, 0) would be invalid, (0,1,) would be indalid, etc. 
//if x or y is out of the range of 1-3, they are invalid.
int GameBase::prompt(unsigned int& x, unsigned int& y)
{

string input;
while (true) {
	cout << "Please type positive x and y coordinates separated by a comma, or type 'quit' to end the game" << endl;
	getline(cin, input);
	convertToLower(input);
	if (input == "quit") {
		cout << turns << " turns were played. You quit the game." << endl;
		return userInput::quit;
	}

	int commaCount = 0;
	for (char c : input) {
		if (c == ',') {
			commaCount++;
		}
	}

	if (commaCount != coordinates::one) { //if there isn't exactly one comma in the input, it's invalid
		continue;
	}
	else {
		for (int c = 0; c < input.length(); c++) { //replace the comma with a space
			if (input[c] == ',') {
				input[c] = ' ';
			}
		}
	}

	istringstream iss;
	string xinput;
	string yinput;
	int xnumber;
	int ynumber;
	iss.str(input);
	if (iss >> xinput && iss >> yinput) {
			istringstream iss2;
			string concatInput = xinput + " " + yinput;
			iss2.str(concatInput);
			iss2 >> xnumber;
			iss2 >> ynumber;
			int index = 0;
			if (gameName == "TicTacToe") {
				index = width * ynumber + xnumber;
				if (xnumber < 1 || xnumber>=(width-1) || ynumber < 1 || ynumber>=(height-1)) { //if they're out of range, they're invalid
					continue;
				}
				else if (pieces[index].n_ == " ") { //if the space is occupied, it's invalid
					x = xnumber;
					y = ynumber;
					return userInput::inputSuccess;
				}
				else {
					continue;
				}
			}
			if (gameName == "Gomoku") {
				index = width * (ynumber-1) + (xnumber-1);
				if (xnumber < 1 || xnumber>width || ynumber < 1 || ynumber>height) { //if they're out of range, they're invalid
					continue;
				}
				else if (pieces[index].n_ == " ") { //if the space is occupied, it's invalid
					x = xnumber;
					y = ynumber;
					return userInput::inputSuccess;
				}
				else {
					continue;
				}
			}
 				
		}
		else {
			continue;
		}
}

}

GameBase* GameBase::createGame(int argc, char* argv[])
{
	if (argc >= coordinates::two) {
		if (string(argv[coordinates::one]) == "TicTacToe") {
			TicTacToe* t = new TicTacToe;
			return t;
		}
		else if (string(argv[coordinates::one]) == "Gomoku") {
			istringstream iss;
			istringstream iss2;
			int n; //n will be the board dimensions
			int m; //holds n for a bit
			int c; //c will be the # of connecting pieces in a row to win
			int d; //d holds c for a bit
			if (argc < 5) {
				if (argc > 2) {
					iss.str(argv[coordinates::two]);
					if (iss >> m && m >= 3 && m <= 30) {
						n = m + 1;
					}
					else {
						cerr << "Invalid board dimensions" << endl;
						return 0;
					}
					if (argc == coordinates::four) {
						iss2.str(argv[coordinates::three]);
						if (iss2 >> d && d < n && d >= 3) {
							c = d;
						}
						else {
							cerr << "Invalid number of connecting pieces" << endl;
							return 0;
							/*if (n <= 5) {
								c = n - 1;
							}
							else {
								c = 5;
							}*/
						}
					}
					else {
						if (n <= 5) {
							c = n - 1;
						}
						else {
							c = 5;
						}
					}
				}
				else {
					n = 20;
					c = 5;
				}
				GomokuGame* g = new GomokuGame(n, c);
				return g;
			}
			else {
				
				GameBase* p = 0;
				return p;
			}
			
		}
		else {
			GameBase* p = 0;
			return p;
		}
	}
	else {
		GameBase* p = 0;
		return p;
	}
}

int GameBase::play()
{
print();

while (true) {
	if (turn() == userInput::quit) {
		return userInput::quit;
	}
	if (draw() == true) {
		cout << turns << " turns were played and there are no moves remaining" << endl;
		return result::drawGame;
	}
	if (done() == true) {
		cout << winner << " won the game." << endl;
		return result::successfulGame;
	}

}


}

