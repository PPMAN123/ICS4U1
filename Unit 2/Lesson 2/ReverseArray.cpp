#include <iostream>

using namespace std;

void reverseArray(int array[], int size){
  for (int i = 0; i < size / 2; i++){
    swap(array[i], array[size - 1 - i]);
  }
}

void reverseArray(int array[], int reversedArray[], int size){
  for (int i = 0; i < size; i++){
    reversedArray[i] = array[size - 1 - i];
  }
}

int main(){
  int size;
  cin >> size;
  int array1[size], array2[size];

  for (int i = 1; i <= size; i++){
    array1[i-1] = i;
  }

  reverseArray(array1, array2, size);

  for (int i = 0; i < size; i++){
    cout << array1[i] << ' ';
  }

  cout << endl;

  for (int i = 0; i < size; i++){
    cout << array2[i] << ' ';
  }

  cout << endl;

  for (int i = 0; i < size; i++){
    cout << array1[i] << ' ';
  }

  cout << endl;

  reverseArray(array1, size);

  for (int i = 0; i < size; i++){
    cout << array1[i] << ' ';
  }

  cout << endl;
}
