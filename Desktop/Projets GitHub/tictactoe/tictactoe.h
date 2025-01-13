#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe {
private:
    char board[3][3]; //Le plateau
    char currentPlayer; //Le joueur actuel

public:
  tictactoe();
  void printBoard(); //afficher le tableau
  bool makeMove(int row, int col); //effectuer un coup
  void switchPlayer(); //changer le joueur 
  char checkWin(); //verifie s'il y a un gagnant
  char getCurrentPlayer(); //retourne le joueur actuel
};

#endif