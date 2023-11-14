#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
public:
//..data fields
int year;
int month;
int day;

//methods
//no-arg constructor
Date(){}

//..parameterized constructor
Date(int year, int month, int day):year(year), month(month), day(day){}

//..this function return true if the year is leap other false
bool isLeapYear();

//..this function return number of days in year
int getDaysInYear();

//..this function returns the number of days in a given month
int getDaysInMonth();

//.. this function advances the date one day
void nextDay();

//..This function returns the number of days between two dates
int daysBetweenDates(Date &d);
//..overload the stream insertion operator <<
friend ostream& operator<<(ostream& out, Date &d){
  out << d.year << " - " << d.month << " - " << d.day;
  return out;
};

//..overload the stream extraction operator >>
friend istream& operator>>(istream& inp, Date &d){
  cout << "Enter Year: ";
  inp >> d.year;
  cout << "Enter month: ";
  inp >> d.month;
  cout << "Enter day: ";
  inp >> d.day;
  return inp;
};
};//..end Date

#endif