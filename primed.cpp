//prime numbers
// 10/22/15
#include <iostream>
#include <ctime>
using namespace std;
void rand(int &a, int b);
bool isprime(int n);
int main()
{	int x, y, num = 0;
	system("clear");
	srand(time(0));
	x = 1;
	y = 100;
	rand(x, y);
	if (x >= 2) cout << "2\n";
	for (int i = 1; i <= x; i = i + 2)
	{
		if (isprime(i))
		{	cout << i << " | ";
			num++;
		}
		if (i % 11 == 0) 
		cout << endl;
	}
	cout << endl << "Number of prime numbers = " << num + 1 << endl;
	cout << endl;
	return 0;
}
void rand(int &a, int b)
{	a = a + rand() % (b - a + 1);
}
bool isprime(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int k = 3;
	while (k * k <= n)
	{
		if (n % k == 0) return false;
		   k = k + 2;
	}
	return true;
}
