#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;

double Triangle::calcPerm(){
  double perimeter = 0;
  for (int i = 0; i < 3; i++){
    perimeter += sides[i];
  }

  return perimeter;
}

double Triangle::calcArea(){
  double semiPerm = calcPerm()/2.0;
  return sqrt(semiPerm * (semiPerm - sides[0]) * (semiPerm - sides[1]) * (semiPerm - sides[2]));
}