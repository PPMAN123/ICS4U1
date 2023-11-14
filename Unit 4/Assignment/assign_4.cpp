/**
 * @file assign_4.cpp
 * @author Ethan Zhou
 * @for: Mr.Saleem
 * @class ICS4U1
 * @brief File with all functions for assign 4 classes
 * @date 2023-10-27
 */

// Include statements
#include "assign_4.h"
#include <iostream>

using namespace std;

// No-arg constructor for Account
Account::Account() {
  id = 0;
  balance = 0;
} //... end of Constructor

// Constructor for Account with parameters
Account::Account(string name, int id, double balance) {

  // Set parameters to variables
  this->name = name;
  this->id = id;
  this->balance = balance;
} //... end of Constructor

// Withdraw function for Account, subtracts balance by parameter
void Account::withdraw(double amount) { balance -= amount; }

// Deposit function for Account, adds balance by parameter
void Account::deposit(double amount) { balance += amount; }

// Constructor for QuadraticEquation, sets parameter to variables
QuadraticEquation::QuadraticEquation(double a, double b, double c)
    : a(a), b(b), c(c) {} //... end of Constructor

// Function that returns the discriminant of a quadratic equation
double QuadraticEquation::getDiscriminant(){
  return (b*b) - (4*a*c);
}//... end of getDiscriminant method

// Function that returns the first root of a quadratic equation
double QuadraticEquation::getRoot1(){

  // If discriminant is not negative, return root 1
  if (getDiscriminant() >= 0){
    return ((b*-1) + sqrt(getDiscriminant()))/(2*a);
  } 
  return 0;
}//... end of getRoot1 method

// Function that returns the second root of a quadratic equation
double QuadraticEquation::getRoot2(){

  // If discriminant is not negative, return root 2
  if (getDiscriminant() >= 0){
    return ((b*-1) - sqrt(getDiscriminant()))/(2*a);
  } 
  
  return 0;
} //... end of getRoot2 method