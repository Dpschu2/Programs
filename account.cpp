//Checking Account Balance Statement
// Dean Schulz
//9/29/15
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int account;
	char choice;
	double wamount = 0;
	double damount = 0; 
	double babom;
	double balance;	
	double dcount = 0;
	double wcount = 0;
	double service = 25;
	bool more = true;
	cout << fixed << setprecision(2);

	//Input 
	system("clear");
	cout << "========================================\n";
	cout << "Please enter your Account number: ";
	cin >> account;
	cout << "========================================\n\n";
	if (account == 4444)
	{
	   cout << "------------------------------------------------------------------\n";
	   cout << "Your Account balance at the beginning of the month is: $" << babom << "\n";
	   cout << "------------------------------------------------------------------\n";
           
	   while (more)
	   {
	      cout << "(w for withdrawl, d for deposit, 1 to submit): ";
	      cin >> choice;
	      if (choice == '1')
		 more = false;
	      else if (choice == 'w')
	      {
	         double w;
	         cout << "\nPlease enter how much to withdrawl: $";
	         cin >> w;
		 cout << endl;
	         wamount = wamount + w;
	   	 wcount++;
	      }
	      else if (choice == 'd')
	      {
	         double d;
	         cout << "\nPlease enter how much to deposit: $";
	         cin >> d;
		 cout << endl;
	         damount = damount + d;
		 dcount++;
	      }
	      else
	      {  cout << "\nNot an option\n";
		 return 0;
	      }
	   }
	//Output
	cout << "\n=====================================================================================\n";
	cout << "\t\t\t\tChecking Account Balance\n";
	cout << "=====================================================================================\n";
	cout << "Account number:\t\t\t\t\t\t" << account << endl;
	cout << "-------------------------------------------------------------------------------------\n";
	cout << "Balance at the beginning of the month:\t\t\t$" << babom << endl;
	cout << "-------------------------------------------------------------------------------------\n";
	cout << "Total amount of deposit:\t\t\t\t+$" << damount << endl;
	cout << "-------------------------------------------------------------------------------------\n"; 
	cout << "Number of deposits:\t\t\t\t\t" << dcount << endl;
	cout << "-------------------------------------------------------------------------------------\n"; 
	cout << "Total amount of withdrawal:\t\t\t\t-$" << wamount << endl;
	cout << "-------------------------------------------------------------------------------------\n"; 
	cout << "Number of withdrawals:\t\t\t\t\t" << wcount << endl;    
	cout << "-------------------------------------------------------------------------------------\n";
	cout << "Service charge:\t\t\t\t\t\t"; 
	balance = babom - wamount + damount;	
	{if (balance < 1000)
	{
	   balance = balance - service;
	   cout << "-$" << service << endl;
	}
	else
	{
	   cout << "$0\n";
	}}  
	cout << "-------------------------------------------------------------------------------------\n"; 
	cout << "Balance at the end of the month:\t\t\t$" << balance << endl;
	cout << "=====================================================================================\n\n";
	}
	else
	{
	   cout << "Error: account does not exist\n";
	}
	return 0;	
}
