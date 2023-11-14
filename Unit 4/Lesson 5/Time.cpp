#include <ctime>
#include <iostream>

using namespace std;

int main(){
  // Define a struct to represent the date
  struct tm date;
  
  // Set the date components (year, month, day, hour, minute, second)
  date.tm_year = 1970 - 1900; // Year - 1900
  date.tm_mon = 10;           // Month (0-11, so 10 represents November)
  date.tm_mday = 8;           // Day of the month
  date.tm_hour = 0;           // Hour
  date.tm_min = 0;            // Minute
  date.tm_sec = 0;            // Second
  
  // Convert the date to a UNIX timestamp
  time_t timestamp = mktime(&date);
  
  if (timestamp != -1) {
      cout << "UNIX timestamp: " << timestamp << endl;
  } else {
      cerr << "Invalid date." << endl;
  }
  
  return 0;
}