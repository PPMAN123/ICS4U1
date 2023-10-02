#include <iostream>

using namespace std;

int main(){
  int a = 10, b = 20;

  cout << a << b << endl;

  a += b;
  b = a - b;
  a -= b;

  cout << a << b << endl;
}