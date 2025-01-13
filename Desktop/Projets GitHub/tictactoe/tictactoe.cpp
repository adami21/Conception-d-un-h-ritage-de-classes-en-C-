#include <iostream>
#include "tictactoe.h"

//constructeur qui initialise le jeu
tictactoe::tictactoe() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; i < 3; i++) {
      board=[i][j] = ' ';
    }
  }
   
  currentPlayer = 'X';
}

void tictactoe::printBoard() {
  std::cout << " " << board[0][0] << " | " <<
}