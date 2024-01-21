#include <iostream>

using namespace std;

void printTwos(int n, string left, string right){
  if (n % 2 != 0){
    cout << left << n << right << endl;
  } else if (n % 4 == 0){
    left += "2 * ";
    right += " * 2";
    return printTwos(n / 4, left, right);
  } else if (n % 2 == 0){
    left += "2 * ";
    return printTwos(n / 2, left, right);
  }
}

void printTwos(int n){
  printTwos(n, "", "");
}

string f(const string s, int n){
  if (n == 0) return s;
  return f('(' + s + ')', n - 1);
}

int sum(int first, int last, int n){
  if (first == last){
    return n + first;
  } else {
    n += first;
    sum(first + 1, last, n);
  }
}

int sum(int first, int last){
  return sum(first, last, 0);
}

int main(){
  cout << sum(1, 10) << endl;
}