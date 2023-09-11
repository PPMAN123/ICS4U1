#include <iostream>
#include <iomanip>

using namespace std;

int dunderMufflin(int reams){
  if (reams < 1000){
    return reams * 4.59;
  } else if (reams < 2500){
    return (1000 * 4.59) + (reams - 1000) * 3.99;
  } else {
    return (1000 * 4.59) + (1500 * 3.99) + (reams - 2500) * 3.59;
  }
}

int michaelScott(int reams){
  return reams * 4.09;
}

int main(){
  int reams; 
  double dunderCost, michaelCost;
  system("clear");
  cout << "Please enter the number of reams: ";
  cin >> reams;

  dunderCost = dunderMufflin(reams);
  michaelCost = michaelScott(reams);

  cout << setprecision(2) << fixed;
  cout << "Cost for Dunder Mufflin: $";
  cout << dunderCost << endl;
  cout << "Cost for Michael Scott: $";
  cout << michaelCost << endl;

  if (dunderCost > michaelCost){
    cout << "You should switch to The Michael Scott Paper Company" << endl;
  } else {
    cout << "You should stay with Dunder Mifflin" << endl;
  }
}