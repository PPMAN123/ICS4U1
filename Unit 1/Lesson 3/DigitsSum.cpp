#include <iostream>

using namespace std;

int main(){
  string number;
  int digitsSum = 0, counter;

  cout << "Enter a positive integer: ";
  cin >> number;
  while (counter < number.length()){
    digitsSum += number[counter] - '0';
    counter++;
  }
  cout << "The sum of the digits is " << digitsSum << endl;
}