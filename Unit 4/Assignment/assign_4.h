/**
 * @file assign_4.h
 * @author Ethan Zhou
 * @for: Mr.Saleem
 * @class ICS4U1
 * @brief Header file with classes Account and QuadraticEquation
 * @date 2023-10-27
 */

// Include Statements
#include <iostream>
#include <cmath>

using namespace std;

class Account {

  // Variables
private:
  string name;
  int id;
  double balance;

public:

  // Constructors
  Account();

  Account(string name, int id, double balance);

  // Getters
  string getName() { return name; }
  int getId() { return id; }
  double getBalance() { return balance; }

  // Setters
  void setId(int id) { this->id = id; }
  void setBalance(double balance) { this->balance = balance; }

  // Methods
  void withdraw(double amount);
  void deposit(double amount);
}; //... end of account class

class QuadraticEquation {

private:
  // Variables
  double a, b, c;

public:
  // Constructors
  QuadraticEquation(double a, double b, double c);

  // Getters
  double getA(){return a;}
  double getB(){return b;}
  double getC(){return c;}

  // Methods
  double getDiscriminant();
  double getRoot1();
  double getRoot2();
}; //... end of quadratic equation class