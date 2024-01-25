#pragma once
#include <iostream>
#include <string>
#include "GeneralSource.h"
using namespace std;

//values for the color options of pieces
enum piece_color {
		red,
		black,
		white,
		invalid = 7,
		noColor = 8
};


//game piece struct with variables
struct game_piece {
	piece_color c_;
	string n_;
	string d_;
	game_piece(piece_color color, string name, string display);
};

//color to string
string pieceColor(int);
//string to color
piece_color stringToColor(std::string s);


