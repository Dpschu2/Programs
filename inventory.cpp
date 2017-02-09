/* Dean Schulz
   Video Game Store Inventory Project
   This program displays the inventory, 
   then asks what and how many items you want to buy, 
   then displays before inventory, receipt, and after inventory.
   11/30/15 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
class store
{	public:
		store();
		void enter();
		void sort();
		void names();
		void items();
		void money();
		void units();
		void inventory();
		void inventorycp();
		void receipt();
	  	void calculate();
	private:
		vector<string> name;
		vector<double> cost;
		vector<int> amount;
		vector<string> namecp;
		vector<double> costcp;
		vector<int> amountcp;
		vector<string> namer;
		vector<double> costr;
		vector<int> amountr;
		int howmany;
		double subtotal;
		double subtax;
		double total;
};
store :: store(): name(), cost(), amount(), namecp(), costcp(), 
amountcp(), namer(), costr(), amountr(), howmany(), 
subtotal(0), subtax(), total(0)
{ }
void store :: enter()
{	cout << "Press [enter] to continue . . .";
	cin.ignore();
	cin.get();
}
void store :: items()
{	string a, b, c, d, e, f, g, h, i, j;
	a = "Super Mario";
	b = "Donkey Kong";
	c = "Golden Eye";
	d = "Zelda";
	e = "Pokemon";
	f = "Star Fox";
	g = "Tony Hawk";
	h = "Mario Party";
	i = "Mario Tennis";
	j = "Mario Kart";
	name.push_back(a);
	name.push_back(b);
	name.push_back(c);
	name.push_back(d);
	name.push_back(e);
	name.push_back(f);
	name.push_back(g);
	name.push_back(h);
	name.push_back(i);
	name.push_back(j);
	// copies for before inventory display
	namecp.push_back(a);
	namecp.push_back(b);
	namecp.push_back(c);
	namecp.push_back(d);
	namecp.push_back(e);
	namecp.push_back(f);
	namecp.push_back(g);
	namecp.push_back(h);
	namecp.push_back(i);
	namecp.push_back(j);
}
void store :: sort() // sorts cost from low to high
{	double temp;
	for (unsigned i = 1; i < cost.size(); i++)
	{
	    for (unsigned j = 0; j < cost.size() - i; j++)
	    {
		if (cost[j] > cost[j + 1])
		{
			temp = cost[j];
			cost[j] = cost[j + 1];
			cost[j + 1] = temp;
		}
	    }
	}
}
void store :: names()
{	
	string c;
	int s, g;
	char b;
	bool ext = true;
	do
	{
	cout << "How many products you do want to buy? ";
	cin >> howmany;
	if (howmany == 0)
	{	cout << "\tTry Again\n";
		enter();
		continue;
	}
	} while (howmany == 0);
	for(int i = 1; i <= howmany; i++)
	{	do{
		int z;
		cout << "Enter name of product " << i << " : ";
		cin.ignore();
		getline(cin, c);
		if (c == "Super Mario" || c == "super mario")
			z = 0;	
		else if (c == "Donkey Kong" || c == "donkey kong")
			z = 1;	
		else if (c == "Golden Eye" || c == "golden eye")
			z = 2;	
		else if (c == "Zelda" || c == "zelda")
			z = 3;	
		else if (c == "Pokemon" || c == "pokemon")
			z = 4;	
		else if (c == "Star Fox" || c == "star fox")
			z = 5;	
		else if (c == "Tony Hawk" || c == "tony hawk")
			z = 6;	
		else if (c == "Mario Party" || c == "mario party")
			z = 7;	
		else if (c == "Mario Tennis" || c == "mario tennis")
			z = 8;	
		else if (c == "Mario Kart" || c == "mario kart")
			z = 9;	
		else
		{	ext = false;
			cout << "\nName not in inventory\nContinue? (y/n): ";
			cin >> b;
			if (b == 'n')
				exit(0);
			else
				b = 'y';
		}
			while (ext)
			{
			do{
			cout << "Enter quantity of " << c << " games: ";
			cin >> s;
			if (s > amount[z] || s == 0)
			{	cout << "\nInvalid number\n";
				g = 2;
			}
			else
				g = 1;
			} while (g != 1);
			for (int i = 1; i <= s; i++)
			{	subtotal = subtotal + cost[z];
				amount[z]--;
			}
			amountr.push_back(s);
			namer.push_back(name[z]);
			costr.push_back(cost[z]);
			cout << endl;
			b = 'n';
			ext = false;
			}
		
		} while (b != 'n');
	}
}
void store :: money()
{ 	for (unsigned i = 0; i < 10; i++)
	{ 
	int z = 20, t = 60; 
	z = z + rand() % (t - z + 1);
	cost.push_back(z);
	costcp.push_back(z);
	}
}
void store :: units()
{	for (unsigned i = 0; i < 10; i++)
	{
	int q = 20, w = 100;
	q = q + rand() % (w - q + 1);
	amount.push_back(q);
	amountcp.push_back(q);
	}
}
void store :: calculate()
{	double tax = 0.08; // Tax is set at 8%
	subtax = subtotal * tax;
	total = subtotal + subtax;
}
void store :: receipt() // Receipt
{	cout << "\n\n\nYour Receipt:";
	cout << "\n================================================================\n";
	cout << "Description\t\tCost\t\tUnits\n";
	cout << "----------------------------------------------------------------\n\n";
	for (int i = 0; i < howmany; i++)
	{	cout << left << setw(24) << namer[i] << "$" << left << setw(16) 
		<< costr[i] << amountr[i] << endl;
	}
	cout << "\n________________________________________________________________\n";
	cout << setw(32) << "Subtotal" << "$" << subtotal << endl;
	cout << setw(32) << "Tax (8%)" << "$" << subtax << endl;
	cout << "----------------------------------------------------------------\n";
	cout << setw(32) << "Total" << "$" << total << endl;
	cout << "================================================================\n\n\n";
}
void store :: inventory()
{
	// Inventory display
	cout << fixed << setprecision(2);
	cout << "==================================================================\n";
	cout << left << setw(24) << "Item name" << left << setw(16) << "Cost" << left << setw(6) << "# on Hand\n";
	cout << "__________________________________________________________________\n";
	for (int o = 0; o < 10; o++)
		cout << left << setw(24) << name[o] << "$" << left << setw(16) << cost[o] << left << setw(24) << amount[o] << endl;
	cout << "==================================================================\n";
}	 
void store :: inventorycp()
{ 	// Inventory Before display
	cout << fixed << setprecision(2);
	cout << "\nThe following items were in our inventory:\n";
	cout << "==================================================================\n";
	cout << left << setw(24) << "Item name" << left << setw(16) << "Cost" << left << setw(6) << "# on Hand\n";
	cout << "__________________________________________________________________\n";
	for (int p = 0; p < 10; p++)
		cout << left << setw(24) << namecp[p] << "$" << left << setw(16) << costcp[p] << left << setw(24) << amountcp[p] << endl;
	cout << "==================================================================\n";
}	 
int main()
{	char i = 'n';
	do
	{
	system("clear");
	srand(time(0));
	store customer;
	customer.items();
	customer.money();
	customer.units();
	customer.sort();
	cout << "\t\tWelcome to Classic Game Store!!!\n\n";
	cout << "The following items are in our inventory:\n";
	customer.inventory();
	customer.names();
	customer.enter();
	customer.calculate();
	system("clear");
	cout << "\nInventory Before:";
	customer.inventorycp();
	customer.receipt();
	cout << "\n\nInventory After:\n";
	customer.inventory();
	cout << "\nWould you like to shop again? (y/n): ";
	cin >> i;
	if (i == 'y')
		continue;
	else
		i = 'n';
	} while(i != 'n');
	system("clear");
	return 0;
}	
