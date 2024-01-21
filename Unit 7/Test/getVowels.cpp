#include <iostream>

using namespace std;

int getVowels(string &s, char c, int n, int i){
  if (i == s.size()){
    return n;
  } else {
    int temp = n;

    if (s[i] == c) temp++;

    getVowels(s, c, temp, i + 1);
  }
}

int getVowels(string s, char c){
  return getVowels(s, c, 0, 0);
}

int fun(int a, int b){
  if (b == 0){
    return 1;
  } else {
    return a * fun(a, b - 1);
  }
}

int main(){
  string line = "yabadabadoo";

  cout << getVowels(line, 'a') << endl;
  cout << fun(5, 3) << endl;
}