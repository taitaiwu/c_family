# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>

# include "publication.h"
# include "magazine.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define UNDERLINE(string) "\x1b[4m" string "\x1b[0m"
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define RED_BG(string) "\x1b[41m"string "\x1b[0m"  

using namespace std;

void Magazine::input (void)
{
	string input;
	
	Publication::input();
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("month"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> month) && !(s >> input) && (month > 0) && (month < 13)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 1 to 12." << endl;
	}
	
	cout << "¡° Please enter the "BOLD(UNDERLINE("editor"))" : ";
	getline(cin, editor);
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("annual subscription"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> annual_subscription) && !(s >> input) && (annual_subscription >= 0)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a non-positive integer." << endl;
	}
}

void Magazine::output (void) const
{
	Publication::output();
	
	cout << "¡° " << BOLD("Month") << setw(16) << ": " << month << endl;
	cout << "¡° " << BOLD("Editor") << setw(15) << ": " << editor << endl;
	cout << "¡° " << BOLD("Annual Subscription") << ": " << annual_subscription << endl;	
}
