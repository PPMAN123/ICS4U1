#include <iostream>

using namespace std;

class Student {
  private:

  // Variables
  string name;
  int mark;

  public:

  // Default constructor (no arg constructor)
  Student(){
    name = "Undocumented";
    mark = 0;
  }

  // Constructor
  Student(string name, int mark):name(name), mark(mark){}


  // Getters (One line)
  string getName(){return name;}
  int getMark(){return mark;}

  // Setters (One line)
  void setName(string name){this->name = name;}
  void setMark(int mark){
    if (mark < 0){
      cout << "Wrong dummy" << endl;
    } else {
      this->mark = mark;
    }
  }
};

int main(){
  Student students[5];

}