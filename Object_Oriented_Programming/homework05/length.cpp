# include <iostream>
# include <string>
# include <sstream>

# include "length.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define RED_BG(string) "\x1b[41m"string "\x1b[0m" 

using namespace std;

void Length::translate (void)
{
	centimeters += millimeters / 10;
	millimeters %= 10;
}

Length::Length (void)
{
	centimeters = 0;
	millimeters = 0;
}

Length::Length (int cm, int mm)
{
	centimeters = cm;
	millimeters = mm;
	translate();
}

void Length::set_length (void)
{
	string input;
	
	while (true)
	{
		cout << string(2, ' ') << "> Please input centimeters : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> centimeters) && !(s >> input) && (centimeters >= 0)) break;
		
		cout << endl << string(2, ' ') << BOLD(YELLOW(RED_BG(" INPUT ERROR! ")) "Please input a positive integer.") << endl;
	}
	
	while (true)
	{
		cout << string(2, ' ') << "> Please input millmeters : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> millimeters) && !(s >> input) && (millimeters >= 0)) break;
		
		cout << endl << string(2, ' ') << BOLD(YELLOW(RED_BG(" INPUT ERROR! ")) "Please input a positive integer.") << endl;
	}
	
	
}

void Length::get_length (void) const
{
	cout << centimeters << " cm " << millimeters << " mm.";
}

int Length::get_length_mm (void) const
{
	return centimeters * 10 + millimeters;
}

bool Length::operator== (const Length& other) const
{
	return get_length_mm() == other.get_length_mm();
}

Length Length::operator+ (const Length& other) const
{
	int total_mm = get_length_mm() + other.get_length_mm();
	
	return Length(total_mm / 10, total_mm % 10);
}

int Length::operator* (const Length& other) const
{
	return get_length_mm() * other.get_length_mm();
}
