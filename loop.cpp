//double loop
//10/8/15
#include <iostream>
using namespace std;
void pattern(int d);
void dpattern(int d);
void ppattern(int d);
void zpattern(int d);
int main()
{	int a;
	cout << "Please enter the size of the pattern: ";
	cin >> a;
	pattern(a);
	cout << endl;
	ppattern(a);
	cout << endl;
	dpattern(a);
	cout << endl;
	zpattern(a);
	cout << endl;
	return 0;
}
void pattern(int d)
{	for (int i = 1; i <= d; i++)
	{
		for (int k = 1; k <= i; k++)
			cout << k;
		cout << endl;
	 }
}
void zpattern(int d)
{	for (int i = 1; i <= d; i++)
	{	for (int k = 1; k <= d; k++)
			cout << k;
		cout << endl;
	}
}
void ppattern(int d)
{	for (int i = 1; i <= d; i++)
	{	for (int k = i; k <= d; k++)
			cout << k;
		cout << endl;
	}
}
void dpattern(int d)
{	for (int i = d; i >= 1; i--)
	{	for (int k = i; k >= 1; k--)
			cout << k;
		cout << endl;
	}
}
