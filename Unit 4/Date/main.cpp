#include <iostream>
#include "date.h"

using namespace std;

int menu();

int main() {
  
}//..end main

int menu(){
  int selection;

  cout << "\n1. Get days in year" << endl;
  cout << "2. Get days in month" << endl;
  cout << "3. Check if year is leap" << endl;
  cout << "4. Check next day" << endl;
  cout << "5. Check number of days between two dates" << endl;
  cout << "6. Quit" << endl;
  cout << "\t Enter your choice: ";
  cin >> selection;

  return selection;
}
