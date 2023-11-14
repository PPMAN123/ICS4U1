/**
 * @file main.cpp
 * @author Ethan Zhou
 * @for: Mr.Saleem
 * @class ICS4U1
 * @brief Program with main method for test code for accounts and quadratic equations
 * @date 2023-10-27
 */

// Include statements
#include "assign_4.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Prototypes
void getAccountData(Account accounts[]);
QuadraticEquation getQuadraticData();
void printQuadraticRoots(QuadraticEquation equation);
void printBalance(Account accounts[], int numOfAccounts);


int main() {
  const int numOfAccounts = 5; // Constant for the number of accounts
  Account accounts[numOfAccounts]; // Array of Accounts
  QuadraticEquation equation = getQuadraticData();
  
  printQuadraticRoots(equation);
  
  getAccountData(accounts); // Populate array of accounts with data

  // Print account data before deposits and withdraws
  cout << "Account data before deposits and withdraws" << endl;
  printBalance(accounts, numOfAccounts);

  // Loop through every account and deposit 2k, withdraw 400
  for (int i = 0; i < numOfAccounts; i++){
    accounts[i].deposit(2000);
    accounts[i].withdraw(400);
  } //... end for loop

  cout << "Account data after deposits and withdraws" << endl;
  printBalance(accounts, numOfAccounts);
} //... end of main method

// Function to get account data from file and populate array
void getAccountData(Account accounts[]) {
  ifstream infile("data.txt"); // Input file
  string line; // Current line
  int i = 0; // Index of line

  // If file is open
  if (infile.is_open()) {

    // Variables to generate new account
    string name;
    int id;
    double balance;

    // Loop through file
    while (getline(infile, line)) {

      // Switch to see what line it is
      switch (i % 4) {
      case 0: // Line for name
        name = line;
        break;
      case 1: // Line for id
        id = stoi(line);
        break;
      case 2: // Line for account balance
        balance = stod(line);
        break;
      }//... end of switch

      Account currentAccount = Account(name, id, balance); // Create new account with according information
      accounts[i / 4] = currentAccount; // Populate array of accounts with newly created account
      
      i++;
      
    } //... end of while loop
  }

  infile.close();
} //... end of getAccountData function


// Function that populates data of a QuadraticEquation object
QuadraticEquation getQuadraticData(){
  double a,b,c;

  // Gather data
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  cout << "Enter c: ";
  cin >> c;

  QuadraticEquation equation = QuadraticEquation(a,b,c); // Create new equation object to return

  return equation;
} //... end of getQuadraticData

// Function that prints the roots of quadratic equation
void printQuadraticRoots(QuadraticEquation equation){

  // Check for number of roots and print them
  if (equation.getDiscriminant() < 0){

    // 0 roots
    cout << "\nNo real roots" << endl;
  } else if (equation.getDiscriminant() == 0){

    // 1 root
    cout << "\nThere is one root:" << endl;
    cout << "Root: " << equation.getRoot1() << endl;
  } else {

    // 2 roots
    cout << "\nThere are two roots:" << endl;
    cout << "Root 1: " << equation.getRoot1() << endl;
    cout << "Root 2: " << equation.getRoot2() << endl;
  }
} //.. end of printQuadraticRoots function

// Function that prints out information of account balances
void printBalance(Account accounts[], int numOfAccounts){

  // Prints header
  cout << endl;
  cout << setw(25) << left << "Name" << right << '|';
  cout << setw(15) << left << "ID" << right << '|';
  cout << setw(15) << left << "Balance";
  cout << endl;

  // Print 55 dashes
  for (int i = 0; i < 55; i++) {
    cout << '-';
  } //... end of for loop
  cout << endl;

  // Print out information of each account
  for (int i = 0; i < numOfAccounts; i++) {
    cout << setw(25) << left << accounts[i].getName() << right << '|';
    cout << setw(15) << left << accounts[i].getId() << right << '|';
    cout << setw(15) << left << fixed << setprecision(2)
         << accounts[i].getBalance();
    cout << endl;
  } //... end of for loop
} //.. end of printBalance function