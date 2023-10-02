#include <iostream>

using namespace std;

int build(const int& hundreds, const int& tens, const int& ones){
  return hundreds*100 + tens*10 + ones;
}

int main(){
  int hundreds, tens, ones;

  cin >> hundreds >> tens >> ones;

  cout << build(hundreds, tens, ones) << endl;
}