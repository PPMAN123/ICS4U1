#include <iostream>

using namespace std;

int* mysteryArray(int n);

int main(){
  int *a = mysteryArray(6);

  for (int i = 0; i < 6; i++){
    cout << a[i] << endl;
  }
}

int* mysteryArray(int n){
  int *arr = new int[n];

  for (int i = 0; i < n; i++){
    arr[i] = 5;
  }

  return arr;
}