#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

void removeZero(vector<int> &v){
  for (int i = 0; i < v.size(); i++){
    if (v[i] == 0){
      v.erase(v.begin() + i);
    }
  }
}

void drawColumns(int n, int i){
  if (n == i){
    cout << '*' << endl;
  } else {
    cout << '*';
    drawColumns(n, i + 1);
  }
}

void drawRows(int n, int i){
  if (n != i){
    drawColumns(i, 0);
    drawRows(n, i + 1);
  }
}

void drawTriangle(int n){
  drawRows(n, 0);
}


int main(){
  vector <int> v = {1,2,0,3,0,4,5};

  removeZero(v);

  for (int i = 0; i < v.size(); i++){
    cout << v[i] << ' ';
  }

  cout << endl;

  drawTriangle(5);
}