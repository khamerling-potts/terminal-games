#include "TicTacToe.h"
#include <iomanip>

//constructor initializes width, height, and a vector of empty gamepieces
TicTacToe::TicTacToe()
{
	width = 5;
	height = 5;
	
	for (int i = 0; i < width * height; i++) {
		game_piece piece = game_piece(noColor, " ", " ");
		pieces.push_back(piece);
	}
	
	player = 1; 
	winner = "";
	turns = 0;
	gameName = "TicTacToe";
}

TicTacToe::TicTacToe(GameBase* gb)
{
	width = 5;
	height = 5;

	for (int i = 0; i < width * height; i++) {
		game_piece piece = game_piece(noColor, " ", " ");
		pieces.push_back(piece);
	}

	player = 1;
	winner = "";
	turns = 0;
	gameName = "TicTacToe";
}


//returns whether there are 3 xs or 3 os in a row
bool TicTacToe::done()
{
	//vertical loop
	int verticalCount = 1;
	for (int x = 1; x < (width - 1); x++) {
		for (int y = (height - 2); y >= 1; y--) {
			int index = width * y + x;
			int nextIndex = width * (y - 1) + x;
			if (pieces[index].n_ != " ") {
				if (pieces[index].n_ == pieces[nextIndex].n_) {
					verticalCount++;
					winner = pieces[index].n_;
				}
			}
		}
		if (verticalCount >= 3) { //check for vertical tictactoe
			return true;
		}
		verticalCount = 1;
	}

	

	//horizontal loop
	int horizCount = 1;
	for (int y = (height - 2); y >= 1; y--) {
		for (int x = 1; x < (width - 1); x++) {
			int index = width * y + x;
			int nextIndex = width * y + (x + 1);
			if (pieces[index].n_ != " ") {
				if (pieces[index].n_ == pieces[nextIndex].n_) {
					horizCount++;
					winner = pieces[index].n_;
				}
			}
		}
		if (horizCount >= 3) {
			return true;
		}
		horizCount = 1;
	}

		


	//first diagonal loop
	int diag1Count = 1;
	int row = height - 2;
	int col = coordinates::one;
	while (row > 0 && col < (width - 1)) {
		int index = width * row + col;
		int nextIndex = width * (row + 1) + (col - 1);
		if (pieces[index].n_ != " ") {
			if (pieces[index].n_ == pieces[nextIndex].n_) {
				diag1Count++;
				winner = pieces[index].n_;
			}
		}
		row--;
		col++;
	}

	if (diag1Count >= 3) {
		return true;
	}


	//second diagonal loop
	int diag2Count = 1;
	int row1 = coordinates::one;
	int col1 = coordinates::one;
	while (row1 < (height-1) && col1 < (width - 1)) {
		int index = width * row1 + col1;
		int nextIndex = width * (row1 + 1) + (col1 + 1);
		if (pieces[index].n_ != " ") {
			if (pieces[index].n_ == pieces[nextIndex].n_) {
				diag2Count++;
				winner = pieces[index].n_;
			}
		}
		row1++;
		col1++;
	}

	if (diag2Count >= 3) {
		return true;
	}

	return false;


	
}

//returns whether or not the game is currently at a draw
bool TicTacToe::draw()
{
	int pieceCount = coordinates::zero;
	for (int y = 3; y >= 1; y--) {
		for (int x = 1; x < 4; x++) {
			int index = 5 * y + x;
			if (pieces[index].n_ != " ") {
				pieceCount++;
			}
		}
	}
	if (pieceCount < 9 || done()==true) {
		return false;
	}
	else {
		return true;
	}
}


int TicTacToe::turn() //game starts with player X
{

	unsigned int x = 0;
	unsigned int y = 0;

	if (prompt(x, y) == userInput::quit) {
		return userInput::quit;
	}
	int index = width * y + x;

	if (player == coordinates::one) {
		pieces[index].n_ = "X";
		pieces[index].d_ = "X";
		if (pieces[index].d_.length() > longestPiece) {
			longestPiece = pieces[index].d_.length();
		}
		cout << *this << endl;
		//cout << endl;
		cout << "Player X: " << flush;

		for (int i = height - 2; i >= 1; i--) { //print X's moves
			for (int j = 1; j <= width - 1; j++) {
				int itIndex = width * i + j;
				if (pieces[itIndex].n_ == "X") {
					cout << "(" << j << "," << i << ") " << flush; //It was more useful for me to use (x,y) format instead of x,y; format, so this is how I chose to print it
				}
			}
		}
		cout << endl;
		player = coordinates::two;
		turns++;

	}
	else {
		pieces[index].n_ = "O";
		pieces[index].d_ = "O";
		if (pieces[index].d_.length() > longestPiece) {
			longestPiece = pieces[index].d_.length();
		}
		cout << *this << endl;
		//cout << endl;
		cout << "Player O: " << flush;

		for (int i = 3; i >= 1; i--) { //print Y's moves
			for (int j = 1; j <= 3; j++) {
				int itIndex = width * i + j;
				if (pieces[itIndex].n_ == "O") {
					cout << "(" << j << "," << i << ") " << flush; //It was more useful for me to use (x,y) format instead of x,y; format, so this is how I chose to print it
				}
			}
		}
		cout << endl;
		player = coordinates::one;
		turns++;


	}
	return userInput::goodTurn;
}

//plays tic tac toe by calling turn, done, and draw


void TicTacToe::print()
{
	cout << *this << endl;
}

//prints out a tic tac toe game
ostream& operator<<(ostream& out, const TicTacToe& game)
{
	for (int y = game.width - 1; y >= 0; --y) {
		cout << y << flush;
		for (int x = 0; x < game.width; ++x) {
			int i = game.width * y + x;
			cout << setw(game.longestPiece + 1) << game.pieces[i].d_ << flush;
		}
		cout << endl;
	}

	cout << " " << setw(game.longestPiece + 1) << flush;
	for (int x = 0; x < game.width; x++) {
		cout << setw(game.longestPiece + 1) << x << flush;
	}
	cout << endl;
	return out;
}
