#include <iostream>
#include <vector>
using namespace std;


int findMin(vector<int> arr)
  {
    int min = /* some value */;
    int index = 0;
  
    while (index < arr.size())
      {
       if (arr[index] < min)
          min = arr[index];
       index++;
      }
     return min;
  }
  

  for (int i = 0; i < n; i += 2)
  {
    if (/* test */)
       /* perform some action */
  }
  

  void increment (int n)
    { 
      n++; 
    }
  
   void firstTestMethod()
    {
     for (int i = 0; i < 3; i++)
        {
          increment(testArray[i]);
          cout << testArray[i] <<" ";
        }
    }


  bool flag = true;
  
  int x = -1;
  
  if (flag && (x > 0))
     cout << "yes" << endl;
  
  else if (x == 0)
    cout << "maybe" << endl;
  
  else if (!flag)
    cout << "sometimes" << endl ;
  
  else
    cout << "no" << endl;



  for (int x = 0; x < _____; x = x + 2)
   cout << "-" << endl;



for(int x = 5; x > 0; x--)
  {
    for(int y = 0; y < 8; y++)
      cout << x*y << endl;
  }


while(num < max)
  num++;

  int y = 5;
  while (y >= 0)
    {
      cout << y << endl;
      y--;
     }

  if (team1Points == team2Points)
    outcome = "Tie game";
  
  if (team1Points > team2Points)
      outcome = "Victory for Team 1";
  else
     outcome = "Victory for Team 2";

for(int i = 1; i < 5; i++)
  {
   for (int k = i; k > 2; k--)
     cout << k  <<" ";
   }

  for (int i = 1; i < 25; i = i + 5)
  {
    if (i % 5 == 0)
      cout << i << " ";
  }

  int k = 8;
  while (k > 0)
  {
    k = k - 2;
    cout << k << endl;
  }



  for (int i = 0; i < 10; i--)
     cout << i <<" ";

for (int i = 10; i >= 0; i--)
   cout << i <<" ";


for (int i = 0; i <= 10; i++)
   cout << 10 - i <<" ";

for (int i = 0; i < 10; i++)
   cout << 10 - i <<" ";


for(int i = 10; i > 0; i--)
   cout << 10 - i <<" ";
 */


   int x = 10;
   int y = 5;
   if (x == 10) 
   {
      if (y <= 5)
        y++;
      else if (y < 4)
        x = 3;
      else
        y += 6;
   }

   if (y > 5)
   {
      if (x != 10)
        {
          x = 0;
          y = 0;
        }
   else
      x = −5;
   }


void check( int n ){
 for( int i = 0; i < n; i++ )
   {
    for( int j = 0; j < n; j++ )
    go( i * j );
  }
}


int n = // some integer greater than zero
int count = 0;
int p = 0;
int q = 0;

for(p = 1; p < n; p++)
  {
  for (q = 1; q <= n; q++)
  count ++;
  }

int sum = 0;

for (int i = 1; i < 2; i++)
  {
  for (int j = 1; j <= 3; j++)
    {
    for (int k = 1; k < 4; k++)
     sum += (i * j * k);
    }//..end for j
  }//..end for i

cout << sum << endl;



//             0   1   2   3   4   5
int  nums[] = {11, 22, 33, 44, 55, 66};

for(int i = 0; i < 6; i++)
  nums[nums[i]/11] = nums[i];


int temp = 90;
bool cloudy = false;

I.  if (temp >= 90 && !cloudy)
II. if (!(temp > 90 || cloudy))
III.if (!(temp > 90 && !cloudy))



   int a = 10;
   int b = 3;
   int t = 0;

   for (int i = 1; i < 4; i++)
    {
     t = a;
     a = i + b;
     b = t - i;
    }



  for(int i = 0; i <= 3; i++)
  {
   for(int j = 1; j <= 5; j+= 2)
    cout << "*" << endl;
  } 


  for (int k = 0; k < 20; k = k + 1)
  {
   if (k % 2 == 1)
    cout << k + 1 <<" ";
  }


   int p = 5;
   int q = 2;
   int sum = 0;
  
   while (p <= 8)
   {
     sum += p % q;
     p++;
     q++;
   }



int i = /* a random number such that 1 <= i <= n; */

 for (int a = 2; a <= i; a++)
  {
   for (int b = 1; b < i; b++)
     cout << "*" << endl;
  }

if (x >= 1) 
   x = x * 3;

if (x > 3) 
   x = 0;



  int calculate (int x)
  {
     x = x + x;
     x = x + x;
     x = x + x;
     return x;
  }


  void whatIsIt(int a, int b)
  {
   if(a < b && a > 0) 
     cout <<"W";
     
   else if (a == b) 
   {
    if(b > 0) 
     cout <<"X" << endl;
      
    else if(b < 0) 
      
     cout <<"Y" << endl;
      
    else 
     cout <<"Z" << endl;
    }
  }

I.   whatIsIt(10, 10)
II.  whatIsIt(-5, 5)
III. whatIsIt(7, 10)



  int a = 24;
  int b = 30;

  while(b != 0)
  {
     int r = a % b;
     a = b;
     b = r;
  }
  cout << a << endl;


int myValue = 17;
int multiplier = 3;
int answer = myValue % multiplier + myValue / multiplier;
answer = answer * multiplier;
cout << answer << endl; */
 */


  
int main()
{


int y = 5;
while(y >= 0)
  {
    cout << y << endl;
    y = y - 1;
  }


  int calculate(int x)
  {
    x = x + x;
    x = x + x;
    x = x + x;
    return x;
  }


  void whatIsIt(int a, int b)
  {
    if ((a < b) && (a > 0))
      cout <<"W";
      
    else if (a == b)
      {
      if (b > 0)
        cout <<"X" << endl;
        
      else if (b < 0)
        cout <<"Y" << endl;
        
      else
        cout <<"Z" << endl;
      }
  }//..end whatIsIt
  
  

  class Coordinates
  {
    private:
      int x, y;
  
    public:
      Coordinates(int myX, int myY):x(myX), y(myY) {}
  
      void setX(int myX) { x = myX; }
    
      void setY(int myY) { y = myY; }
  
      int getX() { return x; }
  
      int getY() { return y; }
  };


  Coordinates c1(0, 10);
  Coordinates c3 = c1;
  Coordinates c2(20, 30);
  
  c3.setX(c2.getY());
  
  c3 = c2;
  
  c3.setY(c2.getX());
  
  c2.setX(c1.getX());



  int a = 24;
  int b = 30;
  
  while (b != 0)
  {
    int r = a % b;
    a = b;
    b = r;
  }
  cout << a << endl;



  class Food
  { 
    public:
   /* implementation not shown */
  };

  class Snack : public Food
  { 
   public: 
     /* implementation not shown */ 
  };

  class Pizza : public Snack
  { 
    public: 
    /* implementation not shown */
  };




  int someMethod(int val)
  {
    for(int i = 2; i < 7; i++)
      {
        if( (val + i) % 2 == 0)
           val += 3;
      }
    return val;
  }



  int calculate(vector<int> numbers)
  {
    int sum = 0;
    for(int n: numbers)
      {
        if( n - 8 > 0 )
          sum += n;
    }
    return sum;
  }



  int myValue = 17;
  int multiplier = 3;
  int answer = myValue % multiplier + myValue / multiplier;
  
  answer = answer * multiplier;
  cout << answer << endl;


  bool myBool;
  myBool = !(a < b || b <= c) && !(a < c || b >= a);



int pathways(int n)
{
  int ans;
  
  if(n < -5)
    ans = 1;
  else if(n < 0)
    ans = 2;
  else if(n > 10)
    ans = 3;
  else
    ans = 4;
  
  return ans;
}