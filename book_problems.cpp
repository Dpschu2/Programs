// Dean Schulz
// Displays book numbers (you want me to do what problems?)
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctype.h>
#include<sstream>

using namespace std;
class book
{	public:
		book();
		void enter();
		void Even();
		void Odds();
		void sort();
		void output(string & temp, bool &out);
		void func(char &sep, int &x, int &y, string &input, bool &out);
		vector<int> list;
		int count;
};
int main()
{		
	bool dont = true; 
	do
	{
        book page;	
	ostringstream oss;
	char sep, z;
	int x, y, login, option, yup, yep;
	bool more = true;
	bool out = true;
	string temp = "";
	string input = "";
	
	cout << "\n\t\t\tProblem Numbers Login Screen\n\n";	
	cout << "\t\t-----------------------------------------\n\n";
	cout << "\t\t1. Enter problem numbers\n";
	cout << "\t\t2. Exit\n\n\n";
	cout << "Enter #: ";
	cin >> login;
	if (login == 1)
	{
	
	cout << "\nEnter book numbers starting with a name\n---------------------------------------\n";
	    cin >> z;
	    if (z == '\"')
	    {	 temp = temp + z;
		 input = input + z;
	    	 do
		 {	z = cin.get();
			input = input + z;
			temp = temp + z;
		 } while (z != '\"');
		 cin >> x;
		 oss << x;
		 input = input + oss.str();
	    }
	    else if (z == '\'')
	    {	 temp = temp + z;
		 input = input + z;
	    	 do
		 {	z = cin.get();
			input = input + z;
			temp = temp + z;
		 } while (z != '\'');
		 cin >> x;
		 oss << x;
		 input = input + oss.str();
	    }
	    else
	    {	 while (more) 
		 {	temp = temp + z;
			input = input + z;
			z = cin.get();
			if (z >= '0' && z <= '9')
			{	more = false;
				x = z - '0';
		 		oss << x;
		 		input = input + oss.str();
			}
		 }
	    }
	for (unsigned int u = 1; u <= temp.length(); u++)
	{	if (temp.substr(u,1) == "\"" || temp.substr(u,1) == "'")
		{	temp.erase(u,1);
			temp.erase(0,1);
		}
	}
	page.func(sep, x, y, input, out);
	page.sort();
	page.output(temp, out);
	page.enter();
	cout << "\nWhat would you like to do?\n\n\t1. Display hyphenated list\n\n\t2. Display Odds\n\n\t3. Display Evens\n\n\t4. Start over\n\n\t5. Quit\n\nChoose one: ";
	cin >> option; 
	if (option == 1)
	{	system("clear");
		cout << "\nHyphenated list: " << input << "\n\n\n";
		cout << "\nWhat would you like to do?\n\n\t1. Display problem numbers\n\n\t2. Display Odds\n\n\t3. Display Evens\n\n\t4. Start over\n\n\t5. Quit\n\nChoose one: ";
		cin >> yup;
		if (yup == 1)
		{	
			page.output(temp, out);
			cout << "\nWhat would you like to do?\n\n\t1. Start over\n\n\t2. Quit\n\nChoose one: ";
			cin >> yep;
			if (yep == 1)
			{	
				continue;
			}
			else
				exit(0);
		}
		else if (yup == 2)
		{	
			cout << "\nOdds in " << temp << ": ";
			page.Odds();
			cout << "\n\n\n";
			page.enter();
		}
		else if (yup == 3)
		{
			cout << "\nEvens in " << temp << ": ";
			page.Even();
			cout << "\n\n\n";
			page.enter();
		}
		else if (yup == 4)
		{	
			continue;
		}
		else
			exit(0);
		
	}
	else if (option == 2)
	{	
		cout << "\nOdds in " << temp << ": ";
		page.Odds();
		cout << "\n\n\n";
		page.enter();
	}
	else if (option == 3)
	{	
		cout << "\nEvens in " << temp << ": ";
		page.Even();
		cout << "\n\n\n";
		page.enter();
	}
	else if (option == 4)
	{	
		continue;
	}
	else
		exit(0);
	}
	else
		exit(0);
	} while (dont != false);
	return 0;
}
book :: book() : list(), count(0)
{
}
void book :: enter()
{	cout << "\n\n\nPress [Enter] to continue . . .";
	cin.ignore();
	cin.get();
}
void book :: Odds()
{	if (count < 1)
	{
	for (unsigned int s = 0; s < list.size(); s++)
	{	if (s == list.size() - 1 && list[s] % 2 != 0)
			cout << list[s];
		else if (s == list.size() - 2 && list[s] % 2 != 0 && list[list.size() - 1] % 2 == 0)
			cout << list[s];
		else
		{	if (list[s] % 2 != 0)
				cout << list[s] << ", ";
		}
		if (list[s] % 10 == 0)
			cout << "\n\n";
	}
	}
	else
	{
	for (unsigned int d = 0; d <= list.size(); d++)
	{	if (d == list.size() && list[d] % 2 != 0)
			cout << list[d];
		else if (d == list.size() - 1 && list[d] % 2 != 0 && list[list.size()] % 2 == 0)
			cout << list[d];
		else
		{	if (list[d] % 2 != 0)
				cout << list[d] << ", ";
		}
		if (list[d] % 10 == 0)
			cout << "\n\n";
	}
	}
}
void book :: Even()
{	if (count < 1)
	{
	for (unsigned int s = 0; s < list.size(); s++)
	{	if (s == list.size() - 1 && list[s] % 2 == 0)
			cout << list[s];
		else if (s == list.size() - 2 && list[s] % 2 == 0 && list[list.size() - 1] % 2 != 0)
			cout << list[s];
		else
		{	if (list[s] % 2 == 0)
				cout << list[s] << ", ";
		}
		if (list[s] % 10 == 0)
			cout << "\n\n";
	}
	}
	else
	{
	for (unsigned int d = 0; d <= list.size(); d++)
	{	if (d == list.size() && list[d] % 2 == 0)
			cout << list[d];
		else if (d == list.size() - 1 && list[d] % 2 == 0 && list[list.size()] % 2 != 0)
			cout << list[d];
		else
		{	if (list[d] % 2 == 0)
				cout << list[d] << ", ";
		}
		if (list[d] % 10 == 0)
			cout << "\n\n";
	}
	}
}
void book :: func(char &sep, int &x, int &y, string &input, bool &out)        
{	ostringstream a, b;
	while (cin.peek() != '\n')
        {  
	    cin >> sep;
	    input = input + sep;
            if (sep == ',')
            {
                 list.push_back(x);
	         cin >> x;
		 a << x;
		 input = input + a.str();
		 a.str("");
		 out = false;
            }
            else
            {	 count++;
                 cin >> y;
		 b << y;
		 input = input + b.str();
		 b.str("");
                 for (int n = x; n <= y; n++)
                 {
			 list.push_back(n);
                 }
            }
	}
	if (sep == ',')	
	{	list.push_back(x);
	}
	if (list.empty())
        {	list.push_back(x);
	}
}
void book :: sort()
{	int temp;
	for (unsigned int i = 1; i < list.size(); i++)
	{	for (unsigned int j = 0; j < list.size() - i; j++)
		{	if (list[j] > list[j + 1])
			{	temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	for (unsigned int q = 0; q < list.size(); q++)
	{	if (list[q] == list[(q + 1)])
		{	
			list.erase(list.begin() + q);
		}
	}
}
void book :: output(string & temp, bool &out)
{	if (list.size() == 1)
		cout << "\nDo problem:\n-----------\n";
	else
		cout << "\nDo problems:\n------------\n";
	if (out == true || count == 0)
	{
	for (unsigned int i = 0; i < list.size(); i++)
	{	if (i == list.size() - 2)
			cout << list[i] << ", and ";
		else if (i == list.size() - 1)
			cout << list[i];
		else
			cout << list[i] << ", ";
		if (list[i] % 10 == 0)
			cout << "\n\n";
	}
	}
	else
	{
	for (unsigned int p = 0; p <= list.size(); p++)
	{	if (p == list.size() - 1)
			cout << list[p] << ", and ";
		else if (p == list.size())
			cout << list[p];
		else
			cout << list[p] << ", ";
		if (list[p] % 10 == 0)
			cout << "\n\n";
	}
	}
	cout << " of " << temp << "\n\n";	
}
