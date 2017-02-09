// Dean Schulz
// Holiday Inn Hotel Reservation
// 10/27/15
/* This program asks for the customer's information, 
   then asks for type of room and choice of extras, 
   and then displays the bill.
*/ 
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
class math
{	public:
		double getadd(double a, double b);
		double gettax(double c);
		void enter();
};
string inputstr(double &t);
int main()
{	int age;
	int young = 18, old = 110;
	double fridge, bed, rprice = 0;
	double days, subtotal, tax, total, extra, room;
	char login, again, till, choice, opt, c, b;
	string name, roomname, fyes = "", byes = "";
	math now;
	do
	{
	// Main Menu
	system("clear");
	cout << "\n\t\t\tHoliday Inn Login Screen\n\n";	
	cout << "\t\t-----------------------------------------\n\n";
	cout << "\t\t1. Make Reservation\n";
	cout << "\t\t2. Exit\n\n\n";
	cout << "Enter #: ";
	cin >> login;
	if (login == '1')
	{	// Customer Information
		system("clear");
		cout << "\n========================================================================\n";
		cout << "\t\t\tWelcome to Holiday Inn!\n";
		cout << "========================================================================\n\n";
		cout << "Enter name:\t\t";	
		cin.ignore();
		getline (cin,name);
		cout << "\n\n";
		cout << "Enter age:\t\t";
		cin >> age;
		if (age < young)
		{	cout << "\n\nYou are too young\n\n";
			cout << "Would you like to start again? (y/n): ";
			cin >> again;
			if (again == 'y')
				continue;
			else
				exit(0);
		}
		if (age > old)
		{	cout << "\n\nHow are you still alive?\n\n";
			cout << "Would you like to start again? (y/n): ";
			cin >> till;
			if (till == 'y')
				continue;
			else
				exit(0);
		}
		cout << "\n\n";
		cout << "How many days of stay?\t";
		cin >> days;
		cout << "\n\n\n-------------------------------------------------------------------------\n";
		cout << "\t\t\tSmall Room = $115.00 per day\n";
		cout << "\t\t\tStandard Room = $330.00 per day\n";
		cout << "\t\t\tLuxury Room = $510.00 per day\n";
		cout << "-------------------------------------------------------------------------\n\n";
		
		// Call from Room Function
		roomname = inputstr(room);
		rprice = room * days;
		cout << "\n\n-------------------------------------------------------------------------\n";
		cout << "\t\t\tRefrigerator = $10.00 extra per day\n";
		cout << "-------------------------------------------------------------------------\n\n";
		// Do, While loops in case the wrong letters are pressed
		do{
		cout << "would you like a refrigerator? (y/n): ";
		cin >> choice;
		if (choice == 'y')
		{	fridge = 10 * days; 
			fyes = "Yes";
			b = 'x';
		}
		else if (choice == 'n')
		{	fyes = "No";
			fridge = 0;
			b = 'x';
		}
		else
		{	now.enter();
			continue;
		}
		} while (b != 'x');
		cout << "\n\n-------------------------------------------------------------------------\n";
		cout << "\t\t\tExtra Bed = $50.00 extra per day\n";
		cout << "-------------------------------------------------------------------------\n\n";
		
		do {
		cout << "would you like an extra bed? (y/n): ";
		cin >> opt;
		if (opt == 'y')
		{	bed = 50 * days; 
			byes = "Yes";
			c = 'x';
		}
		else if (opt == 'n')
		{	byes = "No";
			bed = 0;
			c = 'x';
		}
		else
		{	now.enter();
			continue;
		}
		} while(c != 'x');	
		cout << "\n\n-------------------------------------------------------------------------\n";
		now.enter();
	}
	else if (login == '2')
	{	exit(0);	
	}
	else
	{	cout << "Not an option\n";
		continue;
	}
	extra = now.getadd(fridge, bed);
	subtotal = now.getadd(rprice, extra);
	tax = now.gettax(subtotal);
	total = now.getadd(subtotal, tax);
	// Statement
	system("clear");
	cout << "====================================================================================================\n";
	cout << name << "'s Statement\t\tThank you for choosing Holiday Inn!\n";
	cout << "----------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t# of Days Stay\t\tRoom Type\tRefrigerator\tExtra Bed";
	cout << "\n\t\t\t\t\t\t" << roomname << "\t" << fyes << "\t\t" << byes << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t" << days << "\t\t\t" << "$" << rprice << "\t\t$" << fridge << "\t\t$" << bed << "\n\n";
	cout << "====================================================================================================\n\n";
	cout << fixed << setprecision(2);
	cout << "Room Charges:\t\tUSD " << rprice << "\n\n";
	cout << "Extra fees:\t\tUSD " << extra << "\n\n";
	cout << "Subtotal:\t\tUSD " << subtotal << "\n\n";
	cout << "Tax:\t\t\tUSD " << tax << "\n\n";
	cout << "____________________________________________________________________________________________________\n\n";
	cout << "Total Bill:\t\tUSD " << total << "\n\n";
	cout << "====================================================================================================\n";
	cout << "Would you like to start again? (y/n) ";
	cin >> again;
	if (again == 'y')
	{	system("clear");
		continue;
	}
	else
	{	system("clear");
		return 0;
	}
	} while(again != 'n');
}
string inputstr(double &t)
{       // Choosing Room
	char a;
	string r;
	do{	
	cout << "Select Room Type:\t";
	cin.ignore();
	getline(cin, r);
	if (r == "small room" || r == "Small Room")
	{	t = 115;
		a = 'n';
	}
	else if (r == "standard room" || r == "Standard Room")
	{	t = 330;
		a = 'n';
	}
	else if (r == "luxury room" || r == "Luxury Room")
	{	t = 510;
		a = 'n';
	}
	else
	{	cout << "\nNot valid\nContinue? (y/n): ";
		cin >> a;
		if (a == 'y')
			continue;
		else
			exit(0);		
	}} while (a != 'n');
        return r;
}
void math::enter()
{	cout << "Press [enter] to continue . . .";
	cin.ignore();
	cin.get();
}
double math::getadd(double a, double b)
{	double t = a + b;
	return t;
}
double math::gettax(double c)
{	double t = c * 0.0625;
	// Tax is set at 6.25%
	return t;
}
