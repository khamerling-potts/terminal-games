#include <iostream>
#include "GamePiece.h"
#include "GeneralSource.h"


string redName = "red";
string blackName = "black";
string whiteName = "white";
string invalidName = "invalid";

game_piece::game_piece(piece_color color, string name, string display)
	: c_(color), n_(name), d_(display) {}

string pieceColor(int v) {
	if (v == piece_color::red) {
		convertToLower(redName);
		
		return redName;
	}
	else if (v == piece_color::black) {
		convertToLower(blackName);
		
		return blackName;
	}
	else if (v == piece_color::white) {
		convertToLower(whiteName);
		
		return whiteName;
	}
	else {
		
		return invalidName;
	}
}


piece_color stringToColor(string s) {
	
	if (s == "red") {
		
		return piece_color::red;
	}
	else if (s == "black") {
		
		return piece_color::black;
	}
	else if (s == "white") {
		
		return piece_color::white;
	}
	else {
		
		return piece_color::invalid;
	}

}





