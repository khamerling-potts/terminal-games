#include <iostream>
#include "Gameboard.h"
#include "GeneralSource.h"
#include <istream>
#include <fstream>
#include <sstream>

/*
//read dimensions
int readDimensions(ifstream& ifs, unsigned int& a, unsigned int& b)
{
	string s;
	if (getline(ifs, s)) {
		istringstream iss(s);
		if (iss >> a && iss >> b) {
				return dimensionSuccess;
		}
		else {
			return extractFail;
		}
	}
	else {
		
		return readFail;
	}
}

int readPieces(ifstream& ifs, vector<game_piece>& v, unsigned int a, unsigned int b)
{
	string s;
	int successCount = 0;
	while (getline(ifs, s)) {
		istringstream iss(s);

		string name;
		string color;
		string display;
		unsigned int x;
		unsigned int y;

		if (iss >> color && iss >> name && iss >> display && iss >> x && iss >> y) {
			piece_color c = stringToColor(color);
			if (c != piece_color::invalid) {
				if (x <= a && y <= b) {
					int index = a * y + x;
					v[index].c_ = c;
					v[index].n_ = name;
					v[index].d_ = display;
					++successCount;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
		else {
			continue;
		}
	}

	//if the program read at least one well formed piece, return success (0), otherwise return fail (1)
	if (successCount != 0) {
		return pieceSuccess;
	}
	else {
		return pieceFail;
	}
}



//print out the board
//int printBoard(const vector<game_piece>& v, unsigned int a, unsigned int b)
//{
//	if (v.size() == (a * b)) {
//		for (int y = (b - 1); y >= 0; --y) {
//			for (unsigned int x = 0; x < a; ++x) {
//				int i = a * y + x;
//				cout << v[i].d_ << flush;
//			}
//			cout << endl;
//		}
//		return printSuccess;
//	}
//	else {
//		return printFail;
//	}
//	
//	
//}



//EXTRA CREDIT FUNCTIONS BELOW

void printNeighborsHelper(const vector<game_piece>&v, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	if ((y+1)<height && (x-1)<width) {
		if (v[width * (y + 1) + (x - 1)].n_ != " " && v[width * (y + 1) + (x - 1)].c_ != piece_color::invalid) {
			cout << x - 1 << "," << y + 1 << " " << flush;
			cout << pieceColor(v[width * (y + 1) + (x - 1)].c_) << " " << flush;
			cout << v[width * (y + 1) + (x - 1)].n_ << "; " << flush;
		}
	}

	if ((y) < height && (x - 1) < width) {
		if (v[width * (y)+(x - 1)].n_ != " " && v[width * (y)+(x - 1)].c_ != piece_color::invalid) {
			cout << x - 1 << "," << y << " " << flush;
			cout << pieceColor(v[width * (y)+(x - 1)].c_) << " " << flush;
			cout << v[width * (y)+(x - 1)].n_ << "; " << flush;
		}
		
	}

	if ((y - 1) < height && (x - 1) < width) {
		if (v[width * (y - 1) + (x - 1)].n_ != " " && v[width * (y - 1) + (x - 1)].c_ != piece_color::invalid) {
			cout << x - 1 << "," << y - 1 << " " << flush;
			cout << pieceColor(v[width * (y - 1) + (x - 1)].c_) << " " << flush;
			cout << v[width * (y - 1) + (x - 1)].n_ << "; " << flush;
		}
		
	}

	if ((y + 1) < height && (x) < width) {
		if (v[width * (y + 1) + (x)].n_ != " " && v[width * (y + 1) + (x)].c_ != piece_color::invalid) {
			cout << x << "," << y + 1 << " " << flush;
			cout << pieceColor(v[width * (y + 1) + (x)].c_) << " " << flush;
			cout << v[width * (y + 1) + (x)].n_ << "; " << flush;
		}
		
	}

	if ((y - 1) < height && (x) < width) {
		if (v[width * (y - 1) + (x)].n_ != " " && v[width * (y - 1) + (x)].c_ != piece_color::invalid) {
			cout << x << "," << y - 1 << " " << flush;
			cout << pieceColor(v[width * (y - 1) + (x)].c_) << " " << flush;
			cout << v[width * (y - 1) + (x)].n_ << "; " << flush;
		}
		
	}

	if ((y + 1) < height && (x + 1) < width) {
		if (v[width * (y + 1) + (x + 1)].n_ != " " && v[width * (y + 1) + (x + 1)].c_ != piece_color::invalid) {
			cout << x + 1 << "," << y + 1 << " " << flush;
			cout << pieceColor(v[width * (y + 1) + (x + 1)].c_) << " " << flush;
			cout << v[width * (y + 1) + (x + 1)].n_ << "; " << flush;
		}
		
	}

	if ((y) < height && (x + 1) < width) {
		if (v[width * (y)+(x + 1)].n_ != " " && v[width * (y)+(x + 1)].c_ != piece_color::invalid) {
			cout << x + 1 << "," << y << " " << flush;
			cout << pieceColor(v[width * (y)+(x + 1)].c_) << " " << flush;
			cout << v[width * (y)+(x + 1)].n_ << "; " << flush;
		}
		
	}

	if ((y - 1) < height && (x + 1) < width) {
		if (v[width * (y - 1) + (x + 1)].n_ != " " && v[width * (y - 1) + (x + 1)].c_!=piece_color::invalid) {
			cout << x + 1 << "," << y - 1 << " " << flush;
			cout << pieceColor(v[width * (y - 1) + (x + 1)].c_) << " " << flush;
			cout << v[width * (y - 1) + (x + 1)].n_ << "; " << flush;
		}
		
	}
	
}

int printNeighbors(const vector<game_piece>& v, unsigned int a, unsigned int b)
{
	if (v.size() == a * b) {
		for (int y = (b - 1); y >= 0; --y) {
			for (unsigned int x = 0; x < a; ++x) {
				int i = a * y + x;
				if (v[i].n_ != " " && v[i].c_ != piece_color::invalid) {
					cout << x << "," << y << " " << flush; //print coordinates
					cout << pieceColor(v[i].c_) << " " << flush; //print color
					cout << v[i].n_ << ": " << flush;
					printNeighborsHelper(v, x, y, a, b);
					cout << endl;
				}
			}
			
		}
		return printSuccess;
	}
	else {
		return printFail;
	}
}

*/