//Dean Schulz
//Lab: Operators: Not just for Classes anymore!
#include<iostream>
#include<string>
using namespace std;

enum suit {clubs, diamonds, hearts, spades, Clubs, Diamonds, Hearts, Spades};
const string str[8] = {"clubs", "diamonds", "hearts", "spades", "Clubs", "Diamonds", "Hearts", "Spades"}; 

istream & operator >> (istream & is, suit & x)
{
  	size_t i = 0;
	do
	{
	i = 0;
	string s;
        is >> s;
        while (i < 8 && s != str[i].substr(0,s.size()))
  	{
               i++;
        }
	if (i == 8)
  	{	cout << "Not valid!\nWhat is the suit of your card?  ";
	}
	}while(i == 8);
        x = static_cast<suit>(i);    
        return is;
}

ostream & operator<<(ostream & os, const suit & cardsuit)
{
        return os << str[cardsuit];
}
 
int main() 
{
  system("clear");
  suit card;
  char a;
  bool more = true, t = false;
  cout << "\t\tWelcome to the Card Suit Entering Program!!!\n\n";
do
{  
  	cout << "What is the suit of your card?  ";
  	cin >> card;

        cout << "\nI see you have a " << card << " up your sleeve!\n";

        switch (card)
        {
            case clubs: cout << "Ah, a club! Don't beat me up!!";
	        break;
            case diamonds: cout << "Ooo...diamonds.  Don't cut my monitor with those!";
	        break;
            case hearts: cout << "You have a heart!  Don't wear it on your sleeve..!";  
	        break;
	    case spades: cout << "So, you have a spade!  Dig me a hole out back, won't you?";
            	break;
            case Clubs: cout << "Ah, a club! Don't beat me up!!";
	        break;
            case Diamonds: cout << "Ooo...diamonds.  Don't cut my monitor with those!";
	        break;
            case Hearts: cout << "You have a heart!  Don't wear it on your sleeve..!";  
	        break;
	    case Spades: cout << "So, you have a spade!  Dig me a hole out back, won't you?";
            	break;
        }
  do
  {
  	cout << "\n\nAnother card? (y/n): ";
  	cin >> a;
  	if (a == 'y')
  	{	t = false;
		continue;
  	}
  	else if (a == 'n')
  	{	more = false;
		t = false;
  	}
  	else
  	{	cout << "\nNot an option!\n\n";
		t = true;
		continue;
  	}
  }while(t == true);
  cout << "\n\n";
}while(more == true);
  cout << "Thank you for using the CSEP!!\n\n";
  return 0;
}
