#include <iostream>

using namespace std;

class BMI {
  public:
    string name;
    int age;
    float weight;
    float height;

    BMI(string name, int age, float weight, float height){
      this->name = name;
      this->age = age;
      this->weight = weight;
      this->height = height;
    }

    float getBMI(){
      return weight / height / height * 10000;
    }

    string getStatus(){
      if (getBMI() < 18.5) return "Underweight";
      else if (getBMI() < 25) return "Normal";
      else if (getBMI() < 30) return "Overweight";
      else return "Obese";
    }
};

int main(){
  BMI dude = BMI("Ethan", 17, 88, 181);
  cout << dude.getBMI() << endl;
  cout << dude.getStatus() << endl;
}