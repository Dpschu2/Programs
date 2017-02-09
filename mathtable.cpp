//Dean Schulz
//LAB: A little to the left louie
#include<iostream>
#include<string>
#include<climits>
#include<iomanip>
using namespace std;
void add()
{
	int s;
	bool j = true;
	do
	{
		cout << "\n\nWhat size should the addition table be?  ";
		cin >> s;
		if (s > 9)
		{
			cout << "I'm sorry, " << s << " is too large of an addition table to print on the screen...";
			continue;
		}
		else if (s < 1)
		{
			cout << "I'm sorry, " << s << " is too small of an addition table to print on the screen...";
			continue;
		}
		else
			j = false;
	} while (j == true);
	cout << "\nThank you...calculating...\n\n";
	cout << " + | ";
	for (int i = 1; i <= s; i++)
	{
		cout << left << setw(3) << i;
	}
	cout << "\n---+----------------------------\n";
	for (int row = 1; row <= s; ++row)
	{
		cout << " " << row << " | ";
		for (int column = 1; column <= s; ++column)
		{
			cout << left << setw(3) << (column)+(row);
		}
		cout << endl;
	}
}
void mult()
{
	int s;
	bool j = true;
	do
	{
		cout << "\n\nWhat size should the multiplication table be?  ";
		cin >> s;
		if (s > 9)
		{
			cout << "I'm sorry, " << s << " is too large of an multiplication table to print on the screen...";
			continue;
		}
		else if (s < 1)
		{
			cout << "I'm sorry, " << s << " is too small of an multiplication table to print on the screen...";
			continue;
		}
		else
			j = false;
	} while (j == true);
	cout << "\nThank you...calculating...\n\n";
	cout << " * | ";
	for (int i = 1; i <= s; i++)
	{
		cout << left << setw(3) << i;
	}
	cout << "\n---+----------------------------\n";
	for (int row = 1; row <= s; ++row)
	{
		cout << " " << row << " | ";
		for (int column = 1; column <= s; ++column)
		{
			cout << left << setw(3) << (column)*(row);
		}
		cout << endl;
	}
}
void sub()
{
	int s;
	bool j = true;
	do
	{
		cout << "\n\nWhat size should the subtraction table be?  ";
		cin >> s;
		if (s > 9)
		{
			cout << "I'm sorry, " << s << " is too large of an subtraction table to print on the screen...";
			continue;
		}
		else if (s < 1)
		{
			cout << "I'm sorry, " << s << " is too small of an subtraction table to print on the screen...";
			continue;
		}
		else
			j = false;
	} while (j == true);
	cout << "\nThank you...calculating...\n\n";
	cout << " - | ";
	for (int i = 1; i <= s; i++)
	{
		cout << left << setw(3) << i;
	}
	cout << "\n---+----------------------------\n";
	for (int row = 1; row <= s; ++row)
	{
		cout << " " << row << " |";
		for (int column = 1; column <= s; ++column)
		{
			if (column == 1)
				cout << right << setw(2) << (column)-(row);
			else
				cout << right << setw(3) << (column)-(row);
		}
		cout << endl;
	}
}
void divide()
{
	int s;
	bool j = true;
	do
	{
		cout << "\n\nWhat size should the division table be?  ";
		cin >> s;
		if (s > 9)
		{
			cout << "I'm sorry, " << s << " is too large of an division table to print on the screen...";
			continue;
		}
		else if (s < 1)
		{
			cout << "I'm sorry, " << s << " is too small of an division table to print on the screen...";
			continue;
		}
		else
			j = false;
	} while (j == true);
	cout << "\nThank you...calculating...\n\n";
	cout << " / | ";
	for (int i = 1; i <= s; i++)
	{
		cout << left << setw(5) << i;
	}
	cout << "\n---+--------------------------------------------\n";
	for (int row = 1; row <= s; ++row)
	{
		cout << " " << row << " | ";
		for (int column = 1; column <= s; ++column)
		{
			cout << setw(5) << (double)(column)/(double)(row);
		}
		cout << endl;
	}
}
void remainder()
{
	int s;
	bool j = true;
	do
	{
		cout << "\n\nWhat size should the remainder table be?  ";
		cin >> s;
		if (s > 9)
		{
			cout << "I'm sorry, " << s << " is too large of a remainder table to print on the screen...";
			continue;
		}
		else if (s < 1)
		{
			cout << "I'm sorry, " << s << " is too small of an remainder table to print on the screen...";
			continue;
		}
		else
			j = false;
	} while (j == true);
	cout << "\nThank you...calculating...\n\n";
	cout << " % | ";
	for (int i = 1; i <= s; i++)
	{
		cout << left << setw(3) << i;
	}
	cout << "\n---+----------------------------\n";
	for (int row = 1; row <= s; ++row)
	{
		cout << " " << row << " | ";
		for (int column = 1; column <= s; ++column)
		{
			cout << left << setw(3) << (column)%(row);
		}
		cout << endl;
	}
}
int main()
{
	system("clear");
	cout << fixed << setprecision(1);
	int a;
	bool y = true;
	string op;

	cout << "\n\t\tWelcome to the Math Table Program! ! !\n\n";
	do
	{
		do
		{
		cout << "Table Menu\n\n" << "1) Addition table\n2) Multiplication table\n"
			<< "3) Subtraction table\n4) Division table\n5) Remainder table\n6) Quit\n\nChoice:  ";
		cin >> a;
		if (a == 1)
		{
			add();
		}
		else if (a == 2)
		{
			mult();
		}
		else if (a == 3)
		{
			sub();
		}
		else if (a == 4)
		{
			divide();
		}
		else if (a == 5)
		{
			remainder();
		}
		else if (a == 6)
		{
			exit(0);
		}
		else
		{
			cout << "\nNot an option, try again\n\n";
			y = false;
		}
		} while (y == false);
		cin.ignore();
		cout << "\n\nStart again? (y/n): ";
		getline(cin, op);
		while (op != "y" && op != "n" && op != "Yes" && op != "yes" && op != "Y" && op != "No" && op != "no" && op != "N")
		{
			cout << "\nNot an option\nStart again? (y/n): ";
			getline(cin, op);
		}
		
	} while (op == "y" || op == "Yes" || op == "yes" || op == "Y");

	cout << "\nThank you for using the MTP!\n\n";
	
	return 0;
}
