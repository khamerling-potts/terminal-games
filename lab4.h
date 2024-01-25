#pragma once
//keep track of user's input and turn return values
enum userInput {
	inputSuccess,
	quit = 9,
	goodTurn = 11
};

//enum for a completed game or draw
enum result {
	successfulGame,
	drawGame = 10
};

//coordinate values that are applicable to this version os tictactoe
enum coordinates {
	zero = 0,
	one = 1,
	two = 2,
	three = 3,
	four = 4
};