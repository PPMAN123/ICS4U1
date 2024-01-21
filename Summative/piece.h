#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int boardSize = 8;

class Piece {
private:
  bool isPiece;
  bool reachedEnd;
  char colour;
  int x;
  int y;

  // Helper methods
  bool isMoveInRange(int targetX, int targetY);
  bool isMoveDiagonal(int targetX, int targetY);
  bool isDirectionCorrect(int targetX, int targetY);
  bool isTargetEmpty(int targetX, int targetY, Piece* board[boardSize][boardSize]);

public:

  // Constructors
  Piece(char colour, int x, int y, bool isPiece){
    this->x = x;
    this->y = y;
    this->colour = colour;
    this->isPiece = isPiece;
    reachedEnd = false;
  }
  Piece(){};
  ~Piece(){};

  // Getters
  int getX(){return x;}
  int getY(){return y;}
  char getColour(){return colour;}
  bool isCheckersPiece(){return isPiece;}

  // Setters
  void setX(int x){this->x = x;}
  void setY(int y){this->y = y;}
  void setReachedEnd(bool reachedEnd){this->reachedEnd = reachedEnd;}

  // Methods
  string toString(){
    string s;
    if (colour == 'w' || colour == 'b'){
      s.push_back(colour);
      s.push_back('P');
    } else {
      s = "  ";
    }
    return s;
  }
  bool isTaking(int targetX, int targetY, Piece* board[boardSize][boardSize]);
  bool isLegalMove(int targetX, int targetY, Piece* board[boardSize][boardSize]);
};

#endif