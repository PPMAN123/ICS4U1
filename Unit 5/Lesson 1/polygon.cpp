#include "polygon.h"
#include <iostream>

using namespace std;

Polygon::Polygon(int n){
  numSides = n;
  sides = new int[numSides];

  for (int i = 0; i < numSides; i++){
    sides[i] = 1;
  }
}

ostream& operator<<(ostream &os, Polygon &p){
  os << "The sides are: ";
  for (int i = 0; i < p.numSides; i++){
    os << p.sides[i] << '\t';
  }
  return os;
}

istream& operator>>(istream &inp, Polygon &p){
  for (int i = 0; i < p.numSides; i++){
    cout << "Enter side " << i + 1 << ": ";
    inp >> p.sides[i]; 
  }

  return inp;
}