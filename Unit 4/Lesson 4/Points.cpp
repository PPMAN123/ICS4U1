#include <iostream>

using namespace std;

class Point {
  public:
  int x, y;

  Point(){
    x = 0;
    y = 0;
  }

  Point(int x, int y): x(x), y(y){}

  Point operator++(){
    return Point(++x, ++y);
  }

  Point operator++(int){
    return Point(x++, y++);
  }

  Point operator+(Point &p){
    return Point(x + p.x, y + p.y);
  }

  Point operator+=(Point &p){
    x += p.x;
    y += p.y;
    return *this;
  }

  friend ostream& operator<<(ostream &out, Point &p){
    out << '(' << p.x << ',' << p.y << ')' << endl;

    return out;
  }

  friend istream& operator>>(istream &inp, Point &p){
    inp >> p.x;
    inp >> p.y;
    
    return inp;
  }
};

int main(){
  Point a = Point(1, 2);
  Point c = Point(2, 3);
  c += a;

  cout << c;

}