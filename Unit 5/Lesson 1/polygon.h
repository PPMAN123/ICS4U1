#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>

using namespace std;

class Polygon {
  public:
    int numSides;
    int *sides;

    Polygon(int n);
    Polygon(){numSides = 3;}

    friend ostream& operator <<(ostream& os, Polygon &p);
    friend istream& operator >>(istream& inp, Polygon &p);
};

#endif