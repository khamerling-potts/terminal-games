# Instructions

This C++ terminal application allows you to play TicTacToe or Gomoku. It was configured and built on MacOS using CMake (installed by homebrew). If you use different software, you may need to build the C++ code on your own using your respective compiler before playing.

1. Download a local copy of this repo to your machine.
2. In your terminal, navigate to the project folder (tictactoe-main).
3. Once in the project directory, navigate to the build folder with the command $ cd build.
4. The build directory already contains an executable file, called "tictactoe". Play the game from the build directory by running the executable file and specifying your game ($ ./tictactoe TicTacToe OR $ ./tictactoe Gomoku).
5. If playing Gomoku, you can optionally specify the board size and number of connecting pieces needed to win. For example, the command $ ./tictactoe Gomoku 5 4 would load a 5x5 Gomoku board where you need 4 pieces in a row to win.
6. TicTacToe only allows the traditional 3x3 format. x & y coordinates for each turn must be between 1-3.
7. If you input invalid parameters or coordinates, the game will continue to prompt you to enter valid values.
8. Take turns until someone wins the game or it ends in a draw. Users can also quit in the middle of the game with the command quit.

# TicTacToe demo

![tictactoe gif](https://github.com/khamerling-potts/tictactoe/blob/main/tictactoe%20gif.gif)

# Gomoku demo

![gomoku gif](https://github.com/khamerling-potts/tictactoe/blob/main/gomoku%20gif.gif)
