/**
 * @file XYZ.cpp
 * @author Ethan Zhou
 * @for: Mr.Saleem
 * @class ICS4U1
 * @brief Program that prints out salary information based off of text file
 * input
 * @date 2023-10-11
 */

// Package imports
#include <cfloat>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

// Struct that keeps track of Employees
struct Employee {
  string firstName;     // First name of employee
  string lastName;      // Last name of employee
  vector<double> wages; // Vector of wages stored as doubles
};

// Prototypes
void getWages(vector<Employee> &employees);
void printAverageWages(vector<Employee> employees);
void printHighestPaidEmployee(vector<Employee> employees);
void printLowestPaidEmployee(vector<Employee> employees);
void printTotalWages(vector<Employee> employees);
void printAverageWageForMonth(vector<Employee> employees);
int menu();

int main() {
  char toContinue =
      'y'; // Char to keep track of if user wants to continue printing
  vector<Employee>
      employees;       // Vector of employees to keep track of employee data
  getWages(employees); // Populate vector

  // Format printouts
  cout << setprecision(2) << fixed;

  // While the user wants to continue using program
  while (tolower(toContinue) == 'y') {

    // Switch that takes input from user and calls the appropriate function
    switch (menu()) {
    case 1:
      // Print average wages of employees
      cout << endl;
      printAverageWages(employees);
      break;
    case 2:
      // Print highest paid employee and wage
      cout << endl;
      printHighestPaidEmployee(employees);
      break;
    case 3:
      // Print lowest paid employee and wage
      cout << endl;
      printLowestPaidEmployee(employees);
      break;
    case 4:
      // Print total wages paid to all employees
      cout << endl;
      printTotalWages(employees);
      break;
    case 5:
      // Print average wage for a given month
      cout << endl;
      printAverageWageForMonth(employees);
      break;
    }
    cout << "\nDo you wish to print something else? (y/n): ";
    cin >> toContinue;
  }

  cout << "Thank you for using this program!" << endl;
}

// Function that populates vector of employees with data from text file
void getWages(vector<Employee> &employees) {
  ifstream inFile("input.txt"); // input file declaration

  if (inFile.is_open()) {
    string line; // Current line in text file

    // Loop through the text file via lines
    while (getline(inFile, line)) {
      Employee employee; // Employee variable that gets pushed into vector of
                         // employees
      stringstream ss(
          line);            // Create a string stream to separate data by spaces
      int i = 0;            // Counter
      string currentString; // Current String in line in text file

      // Loops through the current line in text file, separated by spaces
      while (getline(ss, currentString, ' ')) {
        if (i == 0) {
          // Set first string as employee's first name
          employee.firstName = currentString;
        } else if (i == 1) {
          // Set second string as employee's last name
          employee.lastName = currentString;
        } else {
          // Push current string as employee's wage
          employee.wages.push_back(stod(currentString));
        }
        i++; // Increment counter
      }
      employees.push_back(
          employee); // Push current empyee to vector of employees
    }
  }
}

// Function that prints average wages of all employees
void printAverageWages(vector<Employee> employees) {
  for (int i = 0; i < employees.size(); i++) {
    // Loop through vector of employees
    double sum = 0; // Accumulator for sum of wages
    for (int j = 0; j < employees[i].wages.size(); j++) {
      // Loop through wages of every employee, add to accumulator
      sum += employees[i].wages[j];
    }

    // Print out average wage of employee and pay with formatting
    cout << employees[i].firstName << ' ' << left << employees[i].lastName
         << setw(50 - (employees[i].firstName + employees[i].lastName).length())
         << right << sum / employees[i].wages.size() << right << endl;
  }
}

// Function that prints out highest paid employee
void printHighestPaidEmployee(vector<Employee> employees) {
  Employee highestPaidEmployee;        // Highest paid employee
  double highestPaidEmployeeTotal = 0; // Highest paid employee's total wage
  for (int i = 0; i < employees.size(); i++) {
    // Loop through the vector of employees
    double employeeTotal = 0; // Current employee's total wages
    for (int j = 0; j < employees[i].wages.size(); j++) {
      // Loop through wages of current employee, add to accumulator
      employeeTotal += employees[i].wages[j];
    }
    if (employeeTotal > highestPaidEmployeeTotal) {
      // If current employee's total wage is higher than highest paid employee's
      highestPaidEmployeeTotal = employeeTotal;
      highestPaidEmployee = employees[i];
    }
  }

  // Print out highest paid employee and pay with formatting
  cout << highestPaidEmployee.firstName << ' ' << left
       << highestPaidEmployee.lastName
       << setw(50 -
               (highestPaidEmployee.firstName + highestPaidEmployee.lastName)
                   .length())
       << right << highestPaidEmployeeTotal << right << endl;
}

// Function that prints lowest paid employee's name and wage
void printLowestPaidEmployee(vector<Employee> employees) {
  Employee lowestPaidEmployee; // Lowest paid employee
  double lowestPaidEmployeeTotal =
      numeric_limits<double>::max(); // Lowest paid employee's total wage
  for (int i = 0; i < employees.size(); i++) {
    // Loop through vector of employees
    double employeeTotal = 0; // Current employee's total wages
    for (int j = 0; j < employees[i].wages.size(); j++) {
      // Loop through current employee's wages, add to accumulator
      employeeTotal += employees[i].wages[j];
    }
    if (employeeTotal < lowestPaidEmployeeTotal) {
      // If current employee total is less than lowest paid employee total
      lowestPaidEmployeeTotal = employeeTotal;
      lowestPaidEmployee = employees[i];
    }
  }

  // Print out lowest paid employee name and wage with formatting
  cout << lowestPaidEmployee.firstName << ' ' << left
       << lowestPaidEmployee.lastName
       << setw(50 - (lowestPaidEmployee.firstName + lowestPaidEmployee.lastName)
                        .length())
       << right << lowestPaidEmployeeTotal << right << endl;
}

// Print the sum of wages paid to all employees
void printTotalWages(vector<Employee> employees) {
  double totalWages = 0;
  for (int i = 0; i < employees.size(); i++) {
    for (int j = 0; j < employees[i].wages.size(); j++) {
      totalWages += employees[i].wages[j];
    }
  }

  cout << "Total Wages Paid: " << setw(50 - 17) << right << totalWages << right
       << endl;
}

// Print the average wage of all employees for a given month
void printAverageWageForMonth(vector<Employee> employees) {
  int month;
  cout << "Enter the month you wish to check average wage for: ";
  cin >> month;

  double total = 0; // Total wages for all employees
  for (int i = 0; i < employees.size(); i++) {
    // Loop through every employee, add selected month's wage to total
    total += employees[i].wages[month - 1];
  }

  // Print out average wage for selected month with formatting
  cout << "Average Wage for Month " << month << ": "
       << setw(50 -
               ("Average Wage for Month " + to_string(month) + " ").length())
       << right << total / employees.size() << right << endl;
}

// Function that prints out the menu
int menu() {
  int choice; // Integer to keep track of name

  // Print out menu
  cout << "\n1. Print each employee name and their monthly average wages"
       << endl;
  cout << "2. Print the highest paid employee and his/her pay" << endl;
  cout << "3. Print the lowest paid employee and his/her pay" << endl;
  cout << "4. Print the sum of wages paid to all employees" << endl;
  cout << "5. Print the average wage of all employees for a given month"
       << endl;
  cout << "\nEnter your choice (1-5): ";

  cin >> choice; // Collect choice from user

  return choice;
}