#include <iostream>

using namespace std;

void func(int n){
  if (n == 0){
    cout << n << endl;
    return;
  }
  cout << n << endl;
  func(n-1);
}

void printChar(char c){
  cout << c << endl;
}

void print(string s){
  int n = s.size() - 1;
  if (n == -1){
    printChar(s[n]);
    return;
  }
  printChar(s[n]);
  s = s.substr(0, n);
  print(s);
}

int main(){
  print("ABCD");
}