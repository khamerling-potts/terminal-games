#pragma once
#include "GeneralSource.h"
#include "GamePiece.h"
#include "GameBase.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include "lab4.h"



//gomoku class with variables and functions
class GomokuGame : public GameBase {
	friend ostream& operator<<(ostream& out, const GomokuGame& game);
public:
	GomokuGame(unsigned int n, unsigned int connecting);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
};

//prints gomoku game
ostream& operator<<(ostream& out, const GomokuGame& game);