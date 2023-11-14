#include <iostream>
#include <iomanip>
using namespace std;

//...create an employee class
class Employee {

  public:
    //...data fields
    string first;
    string last;
    double salary;
    int id;

    //...constructor
    Employee(string first,string last, double salary, int id){
      this->first = first;
      this->last  = last;
      this->salary = salary;
      this->id = id;
    }

    Employee(){
      first = "";
      last = "";
      salary = 0;
      id = 0;
    }

    void printInfo(){
      cout << setprecision(2) << fixed;
      cout << "First name: " << first << endl;
      cout << "Last name: " << last << endl;
      cout << "Salary: $" << salary << endl;
      cout << "ID: " << id << endl;
    }
  

};

int main(){
  const int size = 5;
  Employee emp1 = Employee("Ethan", "Zhou", 500.50, 12093);
  Employee emps[5];

  emp1.printInfo();
}//...end main