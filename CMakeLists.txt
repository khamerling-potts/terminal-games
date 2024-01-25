cmake_minimum_required(VERSION 3.24)
project(tictactoe VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(SOURCE_FILES
    GameBase.cpp
    GameBoard.cpp
    GamePiece.cpp
    GeneralSource.cpp
    GomokuGame.cpp
    lab3.cpp
    lab4.cpp
    TicTacToe.cpp)

add_executable(tictactoe ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
