// File: main.cpp
// Made by: Ethan Zhou
// Made for: Mr.Saleem
// Date: November 6th, 2023
// Class: ICS4U1

// Include statements
#include <iostream>
#include <iomanip>
#include "complex.h"

// Using statements
using namespace std;

// Prototypes
int menu();

int main() {

  // Create two complex objects
  Complex c1;
  Complex c2;

  cout << setprecision(2) << endl; // Format output to 2 decimal places

  // Collect user input for the first complex number
  cout << "Enter the first complex number . . ." << endl;
  cin >> c1;
  cout << "Enter the second complex number . . ." << endl;
  cin >> c2;

  // Confirmation on user input
  cout << "You entered numbers . . ." << endl;
  cout << "C1 = " << c1 << endl;
  cout << "C2 = " << c2 << endl;

  int menuOutput = 0; // Variable to store the menu choice

  // While the user wishes to not quit the program
  while (menuOutput != 9){
    menuOutput = menu(); // Gather user input from menu

    // Switch statement to perform the user's choice
    switch(menuOutput){
      case 1: // Addition
        cout << "C1 + C2 = " << c1 + c2 << endl;
        break;
      case 2: // Subtraction
        cout << "C1 - C2 = " << c1 - c2 << endl;
        break;
      case 3: // Multiplication
        cout << "C1 * C2 = " << c1 * c2 << endl;
        break;
      case 4: // Division
        cout << "C1 / C2 = " << c1 / c2 << endl;
        break;
      case 5: // Magnitude
        cout << "|C1| = " << c1.mag() << endl;
        break;
      case 6: // Conjugate
        cout << "The conjugate of C1 is " << c1.conjugate() << endl;
        break;
      case 7: // Magnitude
        double factor;
        cout << "Enter the factor: ";
        cin >> factor;
        cout << "The scalar product from left for C1 is: " << factor * c1 << endl;
        break;
      case 8: // Magnitude
        cout << "Enter the factor: ";
        cin >> factor;
        cout << "The scalar product from right for C1 is: " << c1 * factor << endl;
        break;
      case 9: // Quit
        break;
    } // ...end of switch
  } // ...end of while loop

  cout << "Thank you for using the complex numbers app!" << endl;

  return 0;
} // ...end of main


// Function that prints out the menu for users
int menu(){
  int selection; // Variable that stores user selection
  
  cout << "\n1: Addition" << endl;
  cout << "2: Subtraction" << endl;
  cout << "3: Multiplication" << endl;
  cout << "4: Division" << endl;
  cout << "5: Magnitude" << endl;
  cout << "6: Conjugate" << endl;
  cout << "7: Scalar multiplication from left" << endl;
  cout << "8: Scalar multiplication from right" << endl;
  cout << "9: Quit" << endl;

  // Collect user info
  cout << "\nEnter your selection: ";
  cin >> selection;

  return selection;
}