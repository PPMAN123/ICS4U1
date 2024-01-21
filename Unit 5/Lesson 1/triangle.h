#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "polygon.h"
#include <iostream>

using namespace std;

class Triangle: public Polygon {
  public:
    Triangle():Polygon(3){}

    double calcPerm();
    double calcArea();
};

#endif