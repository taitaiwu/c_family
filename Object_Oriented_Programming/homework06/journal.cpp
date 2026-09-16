# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>

# include "publication.h"
# include "journal.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define UNDERLINE(string) "\x1b[4m" string "\x1b[0m"
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define RED_BG(string) "\x1b[41m"string "\x1b[0m"  

using namespace std;

void Journal::input (void)
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
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("ISSN"))" : ";
		getline(cin, ISSN);
		
		if (check_ISSN(ISSN)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a correct ISSN." << endl;
		cout << setw(2) << "e.g. 0317-8471" << endl;
	}	
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("impact factor"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> impact_factor) && !(s >> input) && (impact_factor >= 0) && (impact_factor <= 100)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a number between 1 to 100." << endl;
	}
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("annual subscription"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> annual_subscription) && !(s >> input) && (annual_subscription >= 0)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a non-positive integer." << endl;
	}
}

void Journal::output (void) const 
{
	Publication::output();
	
	cout << "¡° " << BOLD("Month") << setw(16) << ": " << month << endl;
	cout << "¡° " << BOLD("ISSN") << setw(17) << ": " << ISSN << endl;
	cout << "¡° " << BOLD("Impact Factor") << setw(8) << ": " << impact_factor  << "%" << endl;
	cout << "¡° " << BOLD("Annual Subscription") << ": $" << annual_subscription << endl;
}

bool Journal::check_ISSN (string issn)
{
	// ISSN rules:
	// Multiply first 7 digits by weights 8-2, check digit = (11 - sum%11) % 11, 'X' represents 10.
	
	string result;
	int sum = 0, temp, check;

    for (int i = 0; i < issn.length(); i++)
    {
        if (isdigit(issn[i]) || toupper(issn[i]) == 'X') result += toupper(issn[i]);
    }

    if (result.length() != 8) return false;

    for (int i = 0; i < 7; i++)
    {
        if (!isdigit(result[i])) return false;
    }
    
    for (int i = 0; i < 7; i++)
    {
        sum += (result[i] - '0') * (8 - i);
    }

    temp = sum % 11;
    check = (temp == 0) ? 0 : (11 - temp);

    if (check == 10) return (result[7] == 'X');
    else return (result[7] - '0') == check;
}
