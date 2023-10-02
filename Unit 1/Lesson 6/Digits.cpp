#include <iostream>

using namespace std;

struct Results{
  int odds = 0;
  int zeroes = 0;
  int evens = 0;
};

Results* analyze(const long& input){
  Results* returnValue = new Results();
  string inputString = to_string(input);
  for (int i = 0; i < inputString.length(); i++){
    if (inputString[i] == '0'){
      returnValue->zeroes++;
    } else if (((inputString[i] - '0') % 2) == 0){
      returnValue->evens++;
    } else {
      returnValue->odds++;
    }
  }

  return returnValue;
}

int main(){
  long input;
  cin >> input;
  Results* analysis = analyze(input);

  cout << analysis->odds << analysis->zeroes << analysis->evens << endl;
}