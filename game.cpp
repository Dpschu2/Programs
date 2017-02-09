//game
//10/15/15
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void math(int &a, int &b);
char operation();
void answer(int a, int b, char c);
int main()
{	system("clear");
	srand(time(0));
	int x, y;
	char z;
        x = 10;
        y = 99;
	math(x, y);
        z = operation(); 
	answer(x, y, z);
	cout << endl;		
	return 0;
}
void math(int &a, int &b)
{	a = a + rand() % (b - a + 1);
    	b = a + rand() % (b - a + 1);
}
char operation()
{	int r;
	r = rand() % 3;

	if(r == 0)
          return '+';
	if(r == 1)
          return '-';
	else
          return '*';
}
void answer(int a, int b, char c)
{
	int p, key;
	if (c == '+')
	{	key = a + b;
	        cout << "Enter the answer to " << a << " " << c << " " << b << " = ";
		cin >> p;
		if( p == key)
		   cout << "Good job!\n";
		else
	           cout << "The answer is " << a + b << endl;
	}
	if (c == '-')
	{	key = a - b;
	        cout << "Enter the answer to " << a << " " << c << " " << b << " = ";
		cin >> p;
		if( p == key)
		   cout << "Good job!\n";
		else
	           cout << "The answer is " << a - b << endl;
	}
	if (c == '*')
	{	key = a * b;
	        cout << "Enter the answer to " << a << " " << c << " " << b << " = ";
		cin >> p;
		if( p == key)
		   cout << "Good job!\n";
		else
	           cout << "The answer is " << a * b << endl;
	}
}
