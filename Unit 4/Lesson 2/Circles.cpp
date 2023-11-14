#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
  public:
    int length;
    int width;

    Rectangle(int length, int width){
      this->length = length;
      this->width = width;
    }

    int getArea(){
      return length * width;
    }

    int getPerimeter(){
      return 2*length + 2*width;
    }
};

int main(){
  cout << setw(12) << left << "Length";
  cout << setw(12) << left << "Width";
  cout << setw(12) << left << "Area";
  cout << setw(12) << left << "Perimeter";
  cout << endl;

  for (int i = 0; i < 48; i++){
    cout << '-';
  }
  cout << endl;

  for (int i = 1; i <= 9; i++){
    Rectangle rect = Rectangle(i, 2*i);
    cout << setw(12) << left << rect.length;
    cout << setw(12) << left << rect.width;
    cout << setw(12) << left << rect.getArea();
    cout << setw(12) << left << rect.getPerimeter();
    cout << endl;
  }
}