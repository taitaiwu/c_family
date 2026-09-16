# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>

# include "publication.h"
# include "book.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define UNDERLINE(string) "\x1b[4m" string "\x1b[0m"
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define RED_BG(string) "\x1b[41m"string "\x1b[0m"  

using namespace std;

void Book::input (void)
{
	string input;
	
	Publication::input();
	
	cout << "¡° Please enter the "BOLD(UNDERLINE("author"))" : ";
	getline(cin, author);
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("ISBN"))" : ";
		getline(cin, ISBN);
		
		if (check_ISBN(ISBN)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a correct ISBN." << endl;
		cout << setw(2) << "e.g. 0-306-40615-2(ISBN-10) or 978-0-306-40615-7(ISBN-13)" << endl;
	}
	
	while (true)
	{
		cout << "¡° Please enter the "BOLD(UNDERLINE("price"))" : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> price) && !(s >> input) && (price >= 0)) break;
		
		cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a non-negative integer." << endl;
	}	
}

void Book::output (void) const
{
	Publication::output();
	
	cout << "¡° " << BOLD("Author") << setw(15) << ": " << author << endl;
	cout << "¡° " << BOLD("ISBN") << setw(17) << ": " << ISBN << endl;
	cout << "¡° " << BOLD("Price") << setw(17) << ": $" << price << endl;
}

bool Book::check_ISBN (string isbn)
{
	string result;
	int sum = 0;
	
	for (int i = 0; i < isbn.length(); i++)
	{
		if (isdigit(isbn[i]) || toupper(isbn[i]) == 'X') result += isbn[i];
	}
	
	if (result.length() == 10)
	{
		// ISBN-10 rules:
		// Multiply first 9 digits by weights 10-2, add check digit (0-9 or X=10), total must be divisible by 11.
		
        for (int i = 0; i < 9; i++) 
		{
			sum += (result[i] - '0') * (10 - i);
        }

        if (result[9] == 'X') sum += 10;
        else if (isdigit(result[9])) sum += (result[9] - '0');
        else return false;

        return (sum % 11 == 0);
	}
	
	else if (result.length() == 13)
	{
		// ISBN-13 rules:
		// Multiply 13 digits alternately by 1 and 3, total must be divisible by 10.
		
        for (int i = 0; i < 13; i++) 
		{
            int digit = result[i] - '0';
            
            sum += (i % 2 == 0) ? digit : digit * 3;   
        }

        return (sum % 10 == 0);
	}
	
	else return false;
}
