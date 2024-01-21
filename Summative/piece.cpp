#include <iostream>
#include <vector>
#include "piece.h"

using namespace std;

bool Piece::isDirectionCorrect(int targetX, int targetY){
  if (colour == 'w'){
    if (!reachedEnd){
      if (targetY < y){
        return true;
      }
    } else {
      return true;
    }
  } else if (colour == 'b'){
    if (!reachedEnd){
      if (targetY > y){
        return true;
      }
    } else {
      return true;
    }
  }

  return false;
}

bool Piece::isMoveInRange(
  int targetX,
  int targetY
){
  if (targetX > 7 || targetX < 0){
    return false;
  }
  if (targetY > 7 || targetY < 0){
    return false;
  }

  return true;
}

bool Piece::isMoveDiagonal(
  int targetX,
  int targetY
){
  if (targetX != x && targetY != y){
    return true;
  }

  return false;
}

bool Piece::isTaking(
  int targetX,
  int targetY,
  Piece* board[boardSize][boardSize]
){
  if (isPiece) {
    if (abs(targetX - x) == 2 && abs(targetY - y) == 2){
      if (targetX > x){
        if (targetY > y){
          if (board[targetY + 1][targetX + 1]->isCheckersPiece() && board[targetY + 1][targetX + 1]->getColour() != colour){
            board[targetY + 1][targetX + 1] =  new Piece(' ', targetX + 1, targetY + 1, false);

            cout << "TAKING SOMETHING 1" << endl;
            return true;
          }
        } else {
          if (board[targetY - 1][targetX + 1]->isCheckersPiece() && board[targetY - 1][targetX + 1]->getColour() != colour){
            cout << board[targetY - 1][targetX + 1]->getColour() << endl;
            board[targetY - 1][targetX + 1] = new Piece(' ', targetX + 1, targetY - 1, false);

            cout << "TAKING SOMETHING 2" << endl;
            return true;
          }
        }
      } else {
        if (targetY > y){
          if (board[targetY + 1][targetX - 1]->isCheckersPiece() && board[targetY + 1][targetX - 1]->getColour() != colour){
            board[targetY + 1][targetX - 1] = new Piece(' ', targetX - 1, targetY + 1, false);

            cout << "TAKING SOMETHING 3" << endl;
            return true;
          }
        } else {
          if (board[targetY - 1][targetX - 1]->isCheckersPiece() && board[targetY - 1][targetX - 1]->getColour() != colour){
            board[targetY - 1][targetX - 1] = new Piece(' ', targetX - 1, targetY - 1, false);

            cout << "TAKING SOMETHING 4" << endl;
            return true;
          }
        }
      }
    }
  }

  return false;
}

bool Piece::isTargetEmpty(int targetX, int targetY, Piece* board[boardSize][boardSize]){
  if (board[targetY][targetX]->isCheckersPiece() || board[targetY][targetX]->getColour() == ' '){
    cout << "YAHOO" << targetY << targetX << endl;
    return true;
  } else {
    cout << "NOPE" << targetY << targetX << endl;
    return false;
  }
}

bool Piece::isLegalMove(
  int targetX,
  int targetY,
  Piece* board[boardSize][boardSize]
){
  if (isMoveInRange(targetX, targetY)){
    cout << "IN RANGE" << endl;
    if (isTargetEmpty(targetX, targetY, board)){
      cout << "TARGET EMPTY" << endl;
      if (abs(targetX - x) == 1 && abs(targetY - y) == 1){
        cout << "ONE GRID" << endl;
        if (isMoveDiagonal(targetX, targetY)){
          cout << "MOVING DIAGONALLY" << endl;
          if (isDirectionCorrect(targetX, targetY)){
            cout << "CORRECT DIRECTION" << endl;
            return true;
          }
        }
      }
    }
  }

  return false;
}