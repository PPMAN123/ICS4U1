#include <iostream>

using namespace std;

struct Student {
  string name;
  int mark;
};

void highestMark(Student s[5]){
  Student s1 = {"", 0};
  for (int i = 0; i < 5; i++){
    if (s[i].mark > s1.mark){
      s1 = s[i];
    }
  }

  cout << s1.name << s1.mark << endl;
}

int main(){
  Student s[5] = {
    {"A", 100}, 
    {"B", 99},
    {"C", 98},
    {"D", 97},
    {"E", 5}
  };

  highestMark(s);

}