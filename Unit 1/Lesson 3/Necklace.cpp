#include <iostream>

using namespace std;

int getNextNum(int prevNum, int currentNum){
  return to_string(prevNum + currentNum)[to_string(prevNum + currentNum).length() - 1]  - '0';
}

int main(){
  int prevNum, currentNum, nextNum, steps = 0, initialPrev, initialCurrent;

  cout << "Please enter two digits separated by a space: ";
  cin >> prevNum >> currentNum;

  initialPrev = prevNum;
  initialCurrent = currentNum;

  cout << prevNum << ' ' << currentNum;

  do {
    steps++;
    nextNum = getNextNum(prevNum, currentNum);
    prevNum = currentNum;
    currentNum = nextNum;
    cout << ' ' << currentNum;
  } while (prevNum != initialPrev || currentNum != initialCurrent);

  cout << endl;

  cout << "Total steps: " << steps << endl;
}