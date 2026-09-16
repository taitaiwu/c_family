# include <iostream>
# include <string>
# include <sstream>

# include "length.h"
# include "rectangle.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 

using namespace std;

void Rectangle::set_sides (void)
{
	cout << BOLD("¡° The first side") << endl;
	side1.set_length();
	
	cout << endl << BOLD("¡° The second side") << endl;
	side2.set_length();
}

void Rectangle::get_sides (void) const
{
	cout << "¡° The first side length is ";
	side1.get_length(); 
	cout << endl;
	
	cout << "¡° The second side length is "; 
	side2.get_length();
	cout << endl;
} 

bool Rectangle::is_square (void) const
{
	return side1 == side2;
}

int Rectangle::get_area (void) const
{
	return side1 * side2;
}

Length Rectangle::get_perimeter (void) const
{
	return (side1 + side2) + (side1 + side2);
}
