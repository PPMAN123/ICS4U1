// File: complex.cpp
// Made by: Ethan Zhou
// Made for: Mr.Saleem
// Date: November 6th, 2023
// Class: ICS4U1

// Include statements
#include "complex.h"
#include <iostream>
#include <cmath>

// Using statements
using namespace std;

// Function to get magnitude of complex number
double Complex::mag(){
  return abs(sqrt(pow(real,2) + pow(imag,2)));
} // ...end of method

// Function to get conjugate of complex number
Complex Complex::conjugate(){
  return Complex(real, imag * -1);
}// ...end of method

// Overloaded operator to add complex numbers
Complex Complex::operator+(Complex c){
  return Complex(real + c.real, imag + c.imag);
} // ...end of method

// Overloaded operator to subtract complex numbers
Complex Complex::operator-(Complex c){
  return Complex(real - c.real, imag - c.imag);
} // ...end of method

// Overloaded operator to multiple complex numbers
Complex Complex::operator*(Complex c){
  return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
} // ...end of method

// Overloaded operator to divide complex numbers
Complex Complex::operator/(Complex c){
  double denom = c.real * c.real + c.imag * c.imag; // denominator
  return Complex((real * c.real + imag * c.imag)/denom, (imag * c.real - real * c.imag)/denom);
} // ...end of method