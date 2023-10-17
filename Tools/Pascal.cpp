#include <iostream>

using namespace std;

int roofToOdd(int x){
  if (x % 2 == 0){
    return x + 1;
  }
  return x;
}

unsigned long factorial(unsigned long x){
  unsigned long acc = 1;
  for (unsigned long i = 1; i <= x; i++){
    acc *= i;
  }
  return acc;
}

long combination(unsigned long n, unsigned long r){
  return factorial(n)/(factorial(r)*factorial(n-r));
}

string getRow(int row, int largestNum){
  string rowString = "";
  for (int i = 0; i <= row; i++){
    rowString += to_string(combination(row,i));
    if (i != row){
      for (int j = 0; j < roofToOdd(largestNum); j++){
        rowString += ' ';
      }
    }
  }

  return rowString;
}

int main(){
  unsigned long row, largestNum = 0;
  string longestRow;
  cin >> row;

  largestNum = combination(row, row/2);
  longestRow = getRow(row, largestNum);

  cout << longestRow.length() << endl;


  for (int i = 0; i < row; i++){
    string currentRow = getRow(i, largestNum);
    for (int j = 0; j < (longestRow.length()- currentRow.length()) / 2; j++){
      cout << ' ';
    }
    cout << currentRow << endl;
  }
  cout << longestRow << endl;
}