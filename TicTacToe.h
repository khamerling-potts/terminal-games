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



//tictactoe class with variables and functions
class TicTacToe : public GameBase {
	friend ostream& operator<<(ostream& out, const TicTacToe& game);
public:
	TicTacToe();
	TicTacToe(GameBase* gb);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
};

//prints tictactoe game
ostream& operator<<(ostream& out, const TicTacToe& game);