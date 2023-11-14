// File: complex.h
// Made by: Ethan Zhou
// Made for: Mr.Saleem
// Date: November 6th, 2023
// Class: ICS4U1

// Include statements
#include <iostream>
#include <cmath>

// Using statements
using namespace std;

class Complex {
  public:

  // Variables
  double real;
  double imag;

  // Constructors
  Complex(){
    real = imag = 0;
  };
  Complex(double real, double imag): real(real), imag(imag){}

  // Methods
  double mag();
  Complex conjugate();

  // Operator overloads
  Complex operator+(Complex c); // Adding complex numbers
  Complex operator-(Complex c); // Subtracting complex numbers
  Complex operator*(Complex c); // Multiplying complex numbers
  Complex operator/(Complex c); // Dividing complex numbers

  // Friend functions
  // Overloaded operator to scalar multiply from left
  friend Complex operator*(double s, const Complex c){
    return Complex(s*c.real, s*c.imag);
  }; // ...end of operator

  // Overloaded operator to scalar multiply from left
  friend Complex operator*(const Complex c, double s){
    return Complex(c.real*s, c.imag*s);
  }; // ...end of operator

  // Overloaded operator to collect input for complex number
  friend ostream &operator<<(ostream &out, const Complex &c){
    out << c.real << (c.imag < 0 ? " - " : " + ") << abs(c.imag) << 'i';
    
    return out;
  } // ...end of operator

  // Overloaded operator to output data of a complex number
  friend istream &operator>>(istream &in, Complex &c){
    cout << "Enter the real part: ";
    in >> c.real;
    cout << "Enter imag part: ";
    in >> c.imag;
    
    return in;
  } // ...end of operator
};