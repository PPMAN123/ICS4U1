#include <iostream>

using namespace std;

void breakUp(int &digit1, int &digit2, int &digit3, const int& parameter){
  string parameterString = to_string(parameter);

  switch(parameterString.length()){
    case 1:
      digit1 = parameterString[0] - '0';
      break;
    case 2:
      digit1 = parameterString[1] - '0';
      digit2 = parameterString[0] - '0';
      break;
    case 3:
      digit1 = parameterString[2] - '0';
      digit2 = parameterString[1] - '0';
      digit3 = parameterString[0] - '0';
      break;
    default:
      digit1 = 0;
      digit2 = 0;
      digit3 = 0;
  }
}

int main(){
  int digit1, digit2, digit3, parameter = 0;

  cin >> parameter;

  breakUp(digit1, digit2, digit3, parameter);

  cout << "\nSPLIT: " << digit3 << digit2 << digit1 << endl;
}