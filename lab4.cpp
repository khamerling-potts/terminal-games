// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameBase.h"
#include "Gameboard.h"
#include "GamePiece.h"
#include "GeneralSource.h"
#include "TicTacToe.h"
#include "lab3.h"
#include "lab4.h"
#include "GomokuGame.h"

int main(int argc, char * argv[])
{
	if (argc<coordinates::two || argc>coordinates::four) {
		return usageMessage(argv[programName], "<Name of Game>");

	}

	//shared_ptr<GameBase> game;
	GameBase* game;
	if (string(argv[fileName]) == "Gomoku") {
		game = GameBase::createGame(argc, argv);
		//game = make_shared<GomokuGame>(GameBase::createGame(argc, argv));
	}
	else if (string(argv[fileName]) == "TicTacToe") {
		game = GameBase::createGame(argc, argv);
			//make_shared<TicTacToe>(GameBase::createGame(argc, argv));
	}
	else {
		return usageMessage(argv[programName], "<Name of Game> (choose TicTacToe or Gomoku)");
	}
	if (game == 0) {
		return usageMessage(argv[programName], "<Name of Game> dimension number_connecting_pieces");
	}
	else {
		int result = game->play();
		delete game;
		return result;
	}
}