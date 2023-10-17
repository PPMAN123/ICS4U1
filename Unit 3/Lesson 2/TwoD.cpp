#include <iostream>

using namespace std;

const int COLS = 2;

int getColSums(int m[][COLS], int row){
  int acc;

  for (int r = 0; r < 3; r++){
    acc += m[r][row];
  }

  return acc;
}

int main(){
  int m[][COLS] = {
    {1, 2},
    {3, 4},
    {5, 6}
  };

  cout << getColSums(m, 0) << endl;

}