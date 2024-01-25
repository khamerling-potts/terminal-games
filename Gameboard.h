#pragma once
#include <iostream>
#include <string>
#include "GeneralSource.h"
#include <vector>
#include "GamePiece.h"
using namespace std;

enum dimension {
	dimensionSuccess,
	extractFail = 3,
	readFail = 4
};

enum piece {
	pieceSuccess,
	pieceFail = 5
};

enum print {
	printSuccess,
	printFail = 6
};



int readDimensions(ifstream& ifs, unsigned int& a, unsigned int& b);

int readPieces(ifstream& ifs, vector<game_piece>& v, unsigned int a, unsigned int b);

int printBoard(const vector<game_piece>& v, unsigned int a, unsigned int b);

void printNeighborsHelper(const vector<game_piece>& v, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

int printNeighbors(const vector<game_piece>& v, unsigned int a, unsigned int b);

