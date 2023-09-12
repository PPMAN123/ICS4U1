#include <iostream>
#include <iomanip>
using namespace std;


void separator(double x, string (&data)[3]){
  string stringForm = to_string(x);
  string whole;
  int beginningIndex = 0;

  if (x > 0){
    data[0] = "+";
  } else if (x == 0){
    data[0] = "";
  } else {
    data[0] = "-";
  }

  if (x < 0){
    beginningIndex = 1;
  }

  data[1] = stringForm.substr(beginningIndex, stringForm.find('.') - beginningIndex);
  data[2] = stringForm.substr(stringForm.find('.'));



}

int main(){
  cout << setprecision(2) << fixed << showpoint;
  double input;
  string data[3];

  cin >> input;

  separator(input, data);

  cout << data[0] << endl;
  cout << data[1] << endl;
  cout << data[2] << endl;
}