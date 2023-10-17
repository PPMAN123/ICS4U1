#include <iostream>

using namespace std;

int main(){
  int arr[5];

  for (int i = 0; i < 5; i++){
    arr[i] = i;
    cout << i;
  }
  cout << endl;

  int *start = &arr[0];

}