#include <iostream>

using namespace std;

struct Salsa {
  string name;
  int sales;
};

int main(){
  Salsa salsas[5] = {
    {"mild", 0},
    {"medium", 0},
    {"sweet", 0},
    {"hot", 0},
    {"zesty", 0}
  };


  for (int i = 0; i < 5; i++){
    string numSold;
    cin >> salsas[i].sales;
  }

  for (int i = 0; i < 5; i++){
    cout << salsas[i].name << ' ' << salsas[i].sales << endl;
  }


}