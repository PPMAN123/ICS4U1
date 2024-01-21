#include <iostream>
using namespace std;

class Performer
  {
  public:
    void perform() { cout << " act"; }
  
    virtual void act() 
    {
      cout << " bow";
      perform();
    }
  };

class Singer : public Performer
  {
    public:
    
    void act()
    {
      cout << " rise";
      Performer::act();
      cout << " encore";
    }
  
    void perform() { cout << " aria"; }
};


int mystery(int w)
{
  if(w < 0) return 0;
  
  int x = mystery(w - 2);
  
  return w - x;
}

void mystery(string str, int n)
{
  if(n > 1)
  {
    cout << str << endl;
    mystery(str, n - 1);
  }
}

class Tester
{
  public:
    int testArray[3];

    //..constructor
    Tester()
      {
      testArray[0] = 3;
      testArray[1] = 4;
      testArray[2] = 5;
      }

     //pre-condition: n >= 0
    void increment(int n) { n++; }

    void firstMethod()
    {
      for(int i = 0; i < 3; i++)
      {
        increment(testArray[i]);
        cout << testArray[i] <<" ";
      }
    }//..end firstMethod
};

int main() {
  Tester t;
  t.firstMethod();
}
