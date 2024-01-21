#include <iostream>
#include <vector>
#include "piece.h"
#include <cstdlib>

using namespace std;

void populateBoard(Piece* board[boardSize][boardSize]);
void makeBackgroundBlack();
void makeBackgroundWhite();
void printBlankSpaces(bool isStartingBlack);
void printCurrentBoard(Piece* board[boardSize][boardSize]);
bool isGameOver(Piece* board[boardSize][boardSize]);
void makeMove(Piece* board[boardSize][boardSize], char &currentPlayer);
void printFiles();

int main(){
  char currentPlayer = 'w';
  Piece* board[boardSize][boardSize];
  populateBoard(board);

  while (!isGameOver(board)){
    printCurrentBoard(board);
    makeMove(board, currentPlayer);
  }
}

void makeBackgroundBlack(){
  // Helper function to print the board, makes background black
  cout << "\x1b[40m";
}

void makeBackgroundWhite(){
  // Helper function to print the board, makes background white
  cout << "\x1b[47m";
}

void printBlankSpaces(bool isStartingBlack){
  /**
   * @brief A helper function that prints the empty filler spaces within the chess board
   * @params: isStartingBlack - boolean that keeps track if the starting grid of the row is black
  */

  cout << "   "; // Spacer

  for (int i = 0; i < 57; i++){
    // 57 square wide
    if (i % 7 == 0){
      // Every 7 spaces, print a bar
      cout << "\x1b[0m"; // Resets the background colours
      cout << '|';
    } else {
      if (isStartingBlack){
        // If it starts with black
        if (i % 14 > 0 && i % 14 < 7){
          // Makes the grid black, and prints empty spaces
          makeBackgroundBlack();
          cout << ' ';
        } else if (i % 14 > 7 && i % 14 != 0){
          // Makes the grid white, and prints empty spaces
          makeBackgroundWhite();
          cout << ' ';
        }
      } else {
        // If it starts with white, flip the operations
        if (i % 14 > 0 && i % 14 < 7){
          makeBackgroundWhite();
          cout << ' ';
        } else if (i % 14 > 7 && i % 14 != 0){
          makeBackgroundBlack();
          cout << ' ';
        }
      }
      if (i == 56){
        // Print a bar at the end of every line
        cout << '|';
      }
    }
  }
}

void printFiles(){
  /**
   * @brief Prints the files of the board
  */

  string files = "abcdefgh"; // String of all the files

  cout << "   "; // Spacer

  for (int i = 0, j = 0; i < 57; i++){
    // 57 Wide grid

    if (i % 7 == 3){
      // When it's at the middle of the square
      cout << files[j]; // Print the current file
      j++; // Increment iterator for the string
    } else {
      cout << ' '; // Print an empty square when it's not in the middle of a square
    }
  }

  cout << endl;
}

void printCurrentBoard(Piece* board[boardSize][boardSize]){
  /**
   * @brief Function that prints out the chess board
   * @params: chessBoard - 2d pointer array of pieces that stores the current position of the board 
   */

  bool isSquareBlack = false;
  bool isStartingBlack = false;

  printFiles(); // Print the files of the chess board

  for (int y = 7; y >= 0; y--){
    // Prints out the borders
    cout << "   "; // Spacer
    for (int i = 0; i < 57; i++){
      // 57 Wide board
      if (i % 7 == 0){
        // Every 7 spaces, print edge
        cout << '+';
      } else {
        // Otherwise, print a dash
        cout << "-";
      }
    }

    cout << endl;

    printBlankSpaces(isStartingBlack); // Print the blank spaces

    cout << endl;

    cout << y + 1; // Print the ranks
    cout << "  ";

    for (int x = 0; x < boardSize; x++){
      // Loop through the pieces
      cout << "\x1b[0m"; // Print a normal bar
      cout << '|';

      if (isSquareBlack){
        // If square is black
        makeBackgroundBlack();

        // Print the piece text in white text
        cout << "  ";
        cout << "\x1b[37m";
        cout << board[y][x]->toString();
        cout << "  ";
      } else {
        // If square is white
        makeBackgroundWhite();

        // Print the piece text in black text
        cout << "  ";
        cout << "\x1b[37m";
        cout << board[y][x]->toString();
        cout << "  ";
      }

      if (x == 7){
        // Print a normal bar in the end
        cout << "\x1b[0m";
        cout << '|';
      }

      if (x != 7){
        // Swap the colours
        isSquareBlack = !isSquareBlack;
      }
    }

    cout << "  ";
    cout << y + 1;
    cout << endl;

    printBlankSpaces(isStartingBlack);

    cout << endl;
    isStartingBlack = !isStartingBlack; // Swap the starting grid colour
  }

  cout << "   ";
  for (int i = 0; i < 57; i++){
    // Print edge on the end
    if (i % 7 == 0){
      cout << '+';
    } else {
      cout << "-";
    }
  }

  cout << endl;

  printFiles(); // Print the files again
}

void populateBoard(Piece* board[boardSize][boardSize]){
  for (int i = 0; i < boardSize; i++){
    if (i % 2 == 0){
      board[0][i] = new Piece('b', i, 0, true);
      board[1][i] = new Piece(' ', i, 1, false);
      board[2][i] = new Piece('b', i, 2, true);
      board[5][i] = new Piece(' ', i, 5, false);
      board[6][i] = new Piece('w', i, 6, true);
      board[7][i] = new Piece(' ', i, 7, false);
    } else {
      board[0][i] = new Piece(' ', i, 0, false);
      board[1][i] = new Piece('b', i, 1, true);
      board[2][i] = new Piece(' ', i, 2, false);
      board[5][i] = new Piece('w', i, 5, true);
      board[6][i] = new Piece(' ', i, 6, false);
      board[7][i] = new Piece('w', i, 7, true);
    }
  }

  for (int i = 3; i < 4; i++){
    for (int j = 0; j < boardSize; j++){
      board[i][j] = new Piece(' ', j, i, false);
    }
  }
}

bool isGameOver(Piece* board[boardSize][boardSize]){
  int blackCount = 0;
  int whiteCount = 0;
  
  for (int i = 0; i < boardSize; i++){
    for (int j = 0; j < boardSize; j++){
      if (board[i][j]->getColour() == 'b'){
        blackCount++;
      } else if (board[i][j]->getColour() == 'w'){
        whiteCount++;
      }
    }
  }

  if (blackCount == 0){
    return true;
  }
  if (whiteCount == 0){
    return true;
  }
  
  return false;
}

void makeMove(Piece* board[boardSize][boardSize], char &currentPlayer){
  string from, to;
  if (currentPlayer == 'w'){
    cout << "White's turn." << endl;
  } else {
    cout << "Black's turn." << endl;
  }

  cout << "Enter coords of your piece then destination: ";
  cin >> from >> to;

  int fromY = from[1] - '1';
  int fromX = from[0] - 'a';
  int toY = to[1] - '1';
  int toX = to[0] - 'a';

  cout << fromX << fromY << endl;
  cout << toX << toY << endl;

  if (board[fromY][fromX]->getColour() == currentPlayer){
    
    if (board[fromY][fromX]->isLegalMove(toX, toY, board)){
      board[toY][toX] = new Piece(currentPlayer, toX, toY, true);
      board[fromY][fromX] = new Piece(' ', fromX, fromY, false);
      
      if (currentPlayer == 'w'){
        currentPlayer = 'b';
      } else {
        currentPlayer = 'w';
      }

      if (currentPlayer == 'b' && toY == 7){
        board[toY][toX]->setReachedEnd(true);
      } else if (currentPlayer == 'w' && toY == 0){
        board[toY][toX]->setReachedEnd(true);
      }
      
    }  else {
      if(board[fromY][fromX]->isTaking(toX, toY, board)){
        cout << "TAKING" << endl;
        board[toY][toX] = new Piece(currentPlayer, toX, toY, true);
        board[fromY][fromX] = new Piece(' ', fromX, fromY, false);

        if (currentPlayer == 'b' && toY == 7){
          board[toY][toX]->setReachedEnd(true);
        } else if (currentPlayer == 'w' && toY == 0){
          board[toY][toX]->setReachedEnd(true);
        }
      }
    }
  }
}