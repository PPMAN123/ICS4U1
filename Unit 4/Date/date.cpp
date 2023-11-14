#include <iostream>
#include "date.h"

using namespace std;

bool Date::isLeapYear()
{
  return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}//..end

int Date::getDaysInYear()
{
  if(isLeapYear())
    return 366;
  else
    return 365;
}//..end


int Date::getDaysInMonth()
{
  int count = 0;
  switch(month)
  {
    
    //..month with 30 days
    case 9:
    case 4:
    case 6:
    case 11:
    count = 30;
    break;
    case 2:
    count = isLeapYear()?29:28;
    break;
    default:
    count = 31;
  }
  return count;
}//..end getDaysInMonth

void Date::nextDay()
{
  //1. advance in the same month
  day = day + 1;
  //2. wrap around to the next month
  if(day > getDaysInMonth())
  {
    day = 1;
    month = month + 1;
    if(month > 12)
    {
      //3. wrap around to the next year
      year = year + 1;
      month = 1;
      day = 1;
    }
  }//..end if
}

ostream& operator<<(ostream& out, Date &d)
{
  out << d.year <<" - " << d.month <<" - " << d.day;
  return out;
}//..end 

istream& operator>>(istream& inp, Date &d)
{
  cout <<"Enter year: ";
  inp >> d.year;
  cout <<"Enter month: ";
  inp >> d.month;
  cout <<"Enter day: ";
  inp >> d.day;
  return inp;
}

int Date::daysBetweenDates(Date &d)
{
  int count = 0;
  while(year != d.year || month != d.month || day != d.day)
    {
      nextDay();
      count = count + 1;
    }//.end while
  return count;
}