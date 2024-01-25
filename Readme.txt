Additional Details

Test cases:
We checked for invalid arguments, such as providing too few or too many arguments or typing in an incorrect game name. Examples of our command lines include "tictactoe gmku" and "tictactoe gomoku t h f".
We got a usage message and a correct return value for these invalid arguments.

We tried typing invalid coordinates, such as letters and numbers out of range. Our program correctly prompted us again to enter a valid pair of coordinates.

We tried tictactoe by typing "tictactoe TicTacToe" to make sure tictactoe worked the same as it did from lab 3, which it correctly did.

For the following test cases, we used a smaller board (6x6):

We tested vertical wins, horizontal wins, and both kinds of diagonal wins, all of which correctly reported each player's moves as the game continued and reported who won the game after one of the types of wins was complete and stopped the game.

We tested the draw method by playing the game to a point where we knew there were no winning moves remaining. Our program correctly reported that it was a draw at this point and stopped the game.
Here is an example of a successful draw output:

6   B     W  B     W
5      W  B     B
4   W  W  B  W  W
3   W  B  B  W
2   B  W  B     B  B
1   B  B  W  B  W  W
X   1  2  3  4  5  6
Black player: (1,6) (4,6) (3,5) (5,5) (3,4) (2,3) (3,3) (1,2) (3,2) (5,2) (6,2) (1,1) (2,1) (4,1)
27 turns were played and there are no moves remaining


CUSTOM GAME BOARDS FOR GOMOKU:
We refactored our createGame function, our done function, and our gomoku constructor. 
In createGame, we used an istringstream to extract values from the console and store them in member variables for the class.
In done, we refactored our code so it calculated wins based on the connecting pieces member variable (number of pieces in a row needed to win).
We changed the constructor so it takes in two parameters.

To test, we tried 3x3, 4x4, 5x5, 6x6, and default board size. We also tried using numbers for connecting pieces that were different than the board dimensions.
We tested for draw, horizontal, vertical, and diagonal ways in the same way we did in the main part of the lab.

Output for the following command line after a vertical win: tictactoe Gomoku 5 4

5
4     B
3     B         W
2     B    W
1     B    W
X     1    2    3    4    5
Black player: (1,4) (1,3) (1,2) (1,1)
B won the game.


