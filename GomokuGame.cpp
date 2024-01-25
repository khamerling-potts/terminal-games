#include "GomokuGame.h"
#include <iomanip>

//constructor initializes width, height, and a vector of empty gamepieces
GomokuGame::GomokuGame(unsigned int n, unsigned int connecting)
{
	width = n;
	height = n;
	connectingPieces = connecting;

	for (int i = 0; i < width * height; i++) {
		game_piece piece = game_piece(noColor, " ", " ");
		pieces.push_back(piece);
	}

	player = 1;
	winner = "";
	turns = 0;
	longestPiece = 3;
	gameName = "Gomoku";
}


//returns whether there are 5 bs or 5 ws in a row
bool GomokuGame::done()
{
	//vertical loop
	for (int x = 1; x < width; x++) {
		for (int y = height - 1; y >= connectingPieces; y--) {
			int index = width * (y - 1) + (x - 1);

			if (pieces[index].d_ == " ") {
				continue;
			}
			bool won = true;
			for (int i = 1; i < connectingPieces; ++i) {
				int nextIndex = width * (y - 1 - i) + (x - 1);
				if (pieces[index].d_ != pieces[nextIndex].d_) {
					won = false;
				}
			}
			if (won) {
				winner = pieces[index].d_;
				return won;
			}

		}

	}

	//horizontal loop
	for (int y = (height - 1); y >= 1; --y) {
		for (int x = 1; x <= width - connectingPieces; ++x) {
			int index = width * (y - 1) + (x - 1);
			if (pieces[index].d_ == " ") {
				continue;
			}
			bool won = true;
			
			if (pieces[index].d_ != " ") {
				for (int i = 1; i < connectingPieces; ++i) {
					int nextIndex = width * (y - 1) + (x - 1 + i);
					if (pieces[index].d_ != pieces[nextIndex].d_) {
						won = false;
					}
				}
				if (won) {
					winner = pieces[index].d_;
					return won;
				}
			}
			
		}
		
	}

	//diagonal loop top left --> bottom right
	int row = height - 1;
	int col = coordinates::one;
	for (int y = row; y >= connectingPieces; --y) {
		for (int x = col; x <= width - connectingPieces; ++x) {
			int index = width * (y - 1) + (x - 1);
			if (pieces[index].d_ == " ") {
				continue;
			}
			bool won = true;
			for (int i = 1; i < connectingPieces; ++i) {
				int nextIndex = width * (y - 1 - i) + (x - 1 + i);
				if (pieces[index].d_ != pieces[nextIndex].d_) {
					won = false;
				}
			}
			if (won) {
				winner = pieces[index].d_;
				return won;
			}
		}
	}

	//diagonal loop bottom left --> top right
	int row1 = coordinates::one;
	int col1 = coordinates::one;
	for (int y = row1; y <= height - connectingPieces; ++y) {
		for (int x = col1; x <= width - connectingPieces; ++x) {
			int index = width * (y - 1) + (x - 1);
			if (pieces[index].d_ == " ") {
				continue;
			}
			bool won = true;
			for (int i = 0; i < connectingPieces - 1; ++i) {
				int nextIndex = width * (y + i) + (x + i);
				if (pieces[index].d_ != pieces[nextIndex].d_) {
					won = false;
				}
			}
			if (won) {
				winner = pieces[index].d_;
				return won;
			}
		}
	}
	return false;
}

//returns whether or not the game is currently at a draw
bool GomokuGame::draw()
{
	bool movesLeft = false;
	for (int y = width-1; y >= 1; --y) {
		for (int x = 1; x < width; ++x) {
			int index = width * (y - 1) + (x - 1);
			if (pieces[index].d_ == " ") {
				movesLeft = true;
			}
		}
	}

	if (done()) {
		return false;
	}

	// check for winning moves left for B and W
	GomokuGame * copyOfGame = new GomokuGame(this->height, this->connectingPieces);
	copyOfGame->pieces = this->pieces;
	copyOfGame->height = this->height;
	copyOfGame->width = this->width;
	//cout << "initial copy" << endl;
	for (int y = height - 1; y >= 1; --y) {
		for (int x = 1; x < width; ++x) {
			int index = width * (y - 1) + (x - 1);
			if (copyOfGame->pieces[index].d_ == " ") {
				copyOfGame->pieces[index].d_ = "B";
				copyOfGame->pieces[index].n_ = "black stone";
			}
		}
	}
	//cout << *copyOfGame << endl;
	if (copyOfGame->done()) {
		delete copyOfGame;
		return false;
	}
	delete copyOfGame;

	GomokuGame* copy2OfGame = new GomokuGame(this->height, this->connectingPieces);
	copy2OfGame->pieces = this->pieces;
	copy2OfGame->height = this->height;
	copy2OfGame->width = this->width;
	for (int y = width - 1; y >= 1; --y) {
		for (int x = 1; x < width; ++x) {
			int index = width * (y - 1) + (x - 1);
			if (copy2OfGame->pieces[index].n_ == " ") {
				copy2OfGame->pieces[index].d_ = "W";
				copy2OfGame->pieces[index].n_ = "white stone";
			}
		}
	}
	if (copy2OfGame->done()) {
		delete copy2OfGame;
		return false;
	}
	delete copy2OfGame;

	/*if (movesLeft) {
		return false;
	}*/
	return true;

}


int GomokuGame::turn() //game starts with player B
{

	unsigned int x = 0;
	unsigned int y = 0;

	if (prompt(x, y) == userInput::quit) {
		return userInput::quit;
	}
	int index = width * (y-1) + (x-1);
	if (player == coordinates::one) {
		pieces[index].n_ = "black stone";
		pieces[index].d_ = "B";
		if (pieces[index].d_.length() > longestPiece) {
			longestPiece = pieces[index].d_.length();
		}
		print();
		
		cout << "Black player: " << flush;

		for (int i = height - 1; i >= 1; --i) { //print B's moves
			for (int j = 1; j <= width - 1; ++j) {
				int itIndex = width * (i-1) + (j-1);
				if (pieces[itIndex].d_ == "B") {
					cout << "(" << j << "," << i << ") " << flush; //It was more useful for me to use (x,y) format instead of x,y; format, so this is how I chose to print it
				}
			}
		}
		cout << endl;
		player = coordinates::two;
		turns++;

	}
	else {
		pieces[index].n_ = "white stone";
		pieces[index].d_ = "W";
		if (pieces[index].d_.length() > longestPiece) {
			longestPiece = pieces[index].d_.length();
		}
		print();
		cout << "White player: " << flush;

		for (int i = height - 1; i >= 1; --i) { //print W's moves
			for (int j = 1; j <= width - 1; ++j) {
				int itIndex = width * (i-1) + (j-1);
				if (pieces[itIndex].d_ == "W") {
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

void GomokuGame::print()
{
	cout << *this << endl;
}

//prints out a gomoku game
ostream& operator<<(ostream& out, const GomokuGame& game)
{
	for (int y = game.height - 1; y >= 1; --y) {
		if (y < 10) {
			cout << y << " " << flush;
		}
		else {
			cout << y << flush;
		}
		for (int x = 0; x < game.width - 1; ++x) {
			int i = game.width * (y-1) + x;
			if (x < 10) {
				cout << setw(game.longestPiece + 2) << game.pieces[i].d_ << flush;
			}
			else {
				cout << setw(game.longestPiece + 3) << game.pieces[i].d_ << flush;
			}

			
		}
		cout << endl;
	}
	
	cout << "X " << setw(game.longestPiece + 2) << flush;
	for (int x = 1; x < game.width; ++x) {
		if (x < 10) {
			cout << setw(game.longestPiece + 2) << x <<  flush;
		}
		else {
			cout << setw(game.longestPiece + 3) << x <<  flush;
		}
	}

	return out;
}
