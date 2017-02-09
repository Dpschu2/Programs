//Dean Schulz
//Lab: "Now where'd I put that?"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
string inputstr();
void find(string r);
int main()
{	char y = 'y';
	do
	{
	string s1;
	system("clear");
	s1 = inputstr();
	find(s1);
	cout << "\n\n\n\n\nWould you like to start again? (y/n): ";
	cin >> y;
	}while (y == 'y');
	return 0;
}
string inputstr()
{       string r;	
        cout << "\nEnter string: ";
	getline(cin, r);
        return r;
}
void find(string r)
{	
	string temp, t;
	int d = -1;
	int b;
	char x;
	cout << "\nSearch for: ";
	getline(cin, t);	
	cout << "\nSearch from: ";
	cin >> b;
	cout << "\nCase sensitive? (y/n): ";
	cin >> x;
	int s = r.size();
	int p = t.size();
	system("clear");
	cout << "\nString";
	if ((s + 2) > 6)
	{	for (int a = 0; a <= s - 4; a++)
			cout << " ";
	}
	else 
		cout << " ";
	cout << "| Looking for";
	if ((p + 2) > 12)
	{	for (int z = 0; z <= p - 5; z++)
			cout << " ";
	}
	else 
		cout << " ";
	cout << "| Returned | Which find\n------"; 
	if ((s + 2) > 6)
	{	for (int l = 0; l <= s - 4; l++)
			cout << "-";
	}
	else 
		cout << "-";
	cout << "+------------";
	if ((p + 2) > 12)
	{	for (int o = 0; o <= p - 5; o++)
			cout << "-";
	}
	else 
		cout << "-";
	cout << "+----------+------------\n";
	cout << "\"" << r << "\"";
	if (s <= 4)
	{	for (int n = 0; n <= 4 - s; n++)
			cout << " ";
	}
	else 
		cout << " ";
	cout << "| ";
	if (p == 1)
		cout << "'" << t << "'";
	else
		cout << "\"" << t << "\"";
	if (p <= 9)
	{	for (int u = 0; u <= 9 - p; u++)
			cout << " ";
	}
	else
		cout << " ";
	if (x == 'y')
	{
	while (b <= s - p)
	{	if (r.substr(b, p) == t)
		{	d = b;
			b = (s - p) + 1;
		}
		else
			b++;
	}
	}
	else if (x == 'n')
	{
	transform(r.begin(), r.end(), r.begin(), ::tolower);
	transform(t.begin(), t.end(), t.begin(), ::tolower);
	while (b <= s - p)
	{	if (r.substr(b, p) == t)
		{	d = b;
			b = (s - p) + 1;
		}
		else
			b++;
	}
	}
	else
	{	cout << "\nWrong input, try again\n";
		exit(0);
	}
	cout << "|       " << d;
	if (d == -1)
		cout << " | ";
	else if (d >= 10)
		cout << " | ";
	else
		cout << "  | ";
	if (p == 1)
		cout << "char";
	else 
		cout << "c-string";
}
