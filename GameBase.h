#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "GamePiece.h"
#include "lab4.h"


using namespace std;

class GameBase {
public:
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	int play();
	virtual ~GameBase(){
    }
	int prompt(unsigned int& x, unsigned int& y);
	static GameBase* createGame(int argc, char* argv[]);
protected:
	int width = 0;
	int height = 0;
	int connectingPieces = 0;
	size_t longestPiece = 1;
	vector<game_piece> pieces;
	int player = 0;
	string winner;
	int turns = 0;
	string gameName;
};

