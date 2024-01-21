#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascal(int n){
  vector<vector<int>> t(n);

  for (int i = 0; i < n; i++){
    t[i].resize(i + 1);

    t[i][0] = t[i][i] = 1;

    for (int j = 1; j < t[i].size(); j++){
      t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
    }

  }


  return t;
}

int main(){
  vector<vector<int>> t = pascal(6);

  for (auto r : t){
    for (auto c : r){
      cout << c << ' ';
    }
    cout << endl;
  }
}