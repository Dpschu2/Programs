//Dean Schulz
//LAB: Fall in!
#include<iostream>
#include<iomanip>
#include<string>
#include<climits>
#include<fstream>
using namespace std;
class ppl
{
        string n, t, m, p;
public:
	ppl();
        void gather_data(ifstream & infile);
        void skipcmts(ifstream & infile);
	void dots();
	void names();
	void major();
	void phone();
	void town();
};
ppl::ppl()  : n(), t(), m(), p()
{ }
void ppl::dots()
{
	cout << string(16, '-') << "+" << string(20, '-') << "+" << string(15, '-') 
		<< "+" << string(19, '-') << endl;
}
void ppl::skipcmts(ifstream & infile)
{
	string a,b,c,d;
	while (infile.peek() == '#')
        {
		getline(infile, a);
		infile.ignore(INT_MAX, '\n');
		getline(infile, b);
		infile.ignore(INT_MAX, '\n');
		getline(infile, c);
		getline(infile, d);
		cout << a.substr(1) << string(11, ' ') << "|" << d.substr(1) << string(14, ' ') 
		<< "|" << c.substr(1) << string(2, ' ') << "|" << b.substr(1, 8) << "\n"; 
        }
}
void ppl::gather_data(ifstream & infile)
{
	getline(infile, n);
        infile.ignore(INT_MAX,'\n');   // id number
        infile.ignore(INT_MAX,'\n');   // street adrs
	getline(infile, t);
	getline(infile, p);
	getline(infile, m);
}
void ppl::names()
{
	const size_t s = 16;
	char print_name[s];
	strncpy(print_name, n.c_str(), s);
	print_name[s-1] = '\0';  
	cout << left << setw(s) << print_name;
}
void ppl::major()
{
	char print_name[19];
	size_t s = 19;
	strncpy(print_name, m.c_str(), s);       
	print_name[s-1] = '\0';  
	cout << left << setw(s) << print_name;
}
void ppl::phone()
{
	char print_name[14];
	size_t s = 14;
	strncpy(print_name, p.c_str(), s);      
	print_name[s-1] = '\0';  
	cout << left << setw(s) << print_name;
}
void ppl::town() 
{
	char print_name[18];
	size_t s = 18;
	strncpy(print_name, t.c_str(), s);        
	print_name[s] = '\0';  
	cout << left << setw(s) << print_name;
}
int main()
{
	system("clear");
	string op;
	ifstream infile;
	ppl user;
	string stu, cpfile;
	int num = 0;
	cout << "\n\t\tWelcome to the Roster Generator Program! ! !\n\n";
		cout << "Please enter the name of your names file: ";
		getline(cin, stu);
		infile.open(stu.c_str());
		while (infile.fail())
		{
			cout << "I'm sorry, I could not open '" << stu << "'. Please enter another name: ";
			infile.clear();
			getline(cin, stu);
			infile.open(stu.c_str());
		}
		cout << "File '" << stu << "' opened successfully!\n\n";
                user.skipcmts(infile);
		infile.peek();
		while (!infile.eof())
		{
			if (num == 0)
				user.dots();
			user.skipcmts(infile);
			user.gather_data(infile);
			user.names();
			cout << "| ";
			num++;
			user.major();
			cout << "| ";
			user.phone();
			cout << "| ";
			user.town();
			cout << endl;
			if (num == 4)
				cout << endl;
			infile.peek();
		}
		cout << "\n\n Total Enrollment:  " << num << "\n\n";
	cout << "Thank you for using the RGP!\n\n";
	infile.clear();
	infile.close();
	return 0;
}
