//Dean Schulz
//LAB: Copy XYZ
#include<iostream>
#include<string>
#include<climits>
#include<fstream>
#include<unistd.h>
using namespace std;
class ppl
{	public:
		ppl();
		void read(ifstream & infile);
		void write(ofstream & cp);
		
	private:
		string a; int b; double c; char d;
};
ppl :: ppl(): a(), b(), c(), d()
{ }
void ppl :: read(ifstream & infile)
{	getline(infile, a);
	infile >> b >> c >> d;
        infile.ignore(INT_MAX,'\n');
}
void ppl :: write(ofstream & cp)
{	cp << a << endl << b << endl << c << endl << d << endl;
}
int main()
{	system("clear");
	string op;
	ifstream infile;
	ppl user;
	ofstream cp;
	string stu, cpfile;
	
	cout << "\n\t\tWelcome to the People Data Copying Program! ! !\n\n";
	do
	{
	cout << "Please enter the name of your data file: ";
	getline(cin, stu);
	infile.open(stu.c_str());	
		while(infile.fail())
		{	
			cout << "I'm sorry, I could not open '" << stu << "'. Please enter another name: ";
			infile.clear();
			getline(cin, stu); 
			infile.open(stu.c_str());	
		}
		cout << "File '" << stu << "' opened successfully!\n";
		cout << "Please enter the name of the copy file: ";
		getline(cin, cpfile); 
		cp.open(cpfile.c_str());
		while(cp.fail())
		{	
			cout << "I'm sorry, I could not open '" << cpfile << "'. Please enter another name: ";
			cp.clear();
			getline(cin, cpfile); 
			cp.open(cpfile.c_str());
		}
		cout << "File '" << cpfile << "' opened successfully!";
		cout << "\nCopying data from '" << stu << "' to '" << cpfile << "' . . .\n";
		infile.peek();
		while (!infile.eof())
		{	
			user.read(infile);
			user.write(cp);
			infile.peek();
		}
		usleep(1000000);
		cout << "\nDone copying data!";
	cout << "\n\nStart again? (y/n): ";
	getline(cin, op);
	while (op != "y" && op != "n" && op != "Yes" && op != "yes" && op != "Y" && op != "No" && op != "no" && op != "N")
	{	
		cout << "\nNot an option\nStart again? (y/n): ";
		getline(cin, op);
	}
	infile.clear();
	infile.close();
	cp.clear();
	cp.close();	
	}while(op == "y" || op == "Yes" || op == "yes" || op == "Y");
	
	cout << "\nThank you for using the PCP!\n\n";
	infile.close();
	cp.close();	
	return 0;
}
