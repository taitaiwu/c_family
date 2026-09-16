# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <ctime>

# include "publication.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define UNDERLINE(string) "\x1b[4m" string "\x1b[0m"
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define RED_BG(string) "\x1b[41m"string "\x1b[0m"  

using namespace std;

void Publication::input (void)
{
	string input;
	
	time_t now = time(0);
	tm* local_time = localtime(&now);
	int current_year = local_time->tm_year + 1900;
	
	cout << "¡° Please enter the "BOLD(UNDERLINE("title"))" : ";
	getline(cin, title);
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("volume"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> volume) && !(s >> input) && (volume >= 0)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a non-negative integer." << endl;
	}
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("year"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> year) && !(s >> input) && (year <= current_year)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer." << endl;
	}
}

void Publication::output (void) const
{
	cout << "¡° " << BOLD("Title") << setw(16) << ": " << title << endl;
	cout << "¡° " << BOLD("Volume") << setw(15) << ": " << volume << endl;
	cout << "¡° " << BOLD("Year") << setw(17) << ": " << year << endl;
}
