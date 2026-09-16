# include  <iostream>

# include "rectangle.h"

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define UNDERLINE(string) "\x1b[4m" string "\x1b[0m" 
# define SHINE(string) "\x1b[6m" string "\x1b[0m" 
# define BLACK(string) "\x1b[30m" string "\x1b[0m"
# define RED(string) "\x1b[31m" string "\x1b[0m" 
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define BLUE(string) "\x1b[34m"string "\x1b[0m" 
# define GREEN(string) "\x1b[36m"string "\x1b[0m" 
# define RED_BG(string) "\x1b[41m"string "\x1b[0m" 
# define WHITE_BG(string) "\x1b[47m"string "\x1b[0m"

// This project(homework5) has five files:
// length.h & length.cpp - length setting and information persentation
// rectangle.h & rectangle.cpp - rectangle setting and information persentation 
// main.cpp - main program

// User can enter rectangle's sides, then the system will print information about this rectangle.
// Some inputs will be invaildated, such as side input.
// At the end of each round, user can enter Y(y) or N(n) to decide whether to end or continue.

using namespace std;

int main (void)
{
	Rectangle rectangle;
	string input;
	char choose;
	
	cout << BOLD(SHINE(" ~ Welcome to OOP Rectangle System ~")) << endl;
	
	while (true)
	{
		cout << endl << string(50, '=') << endl;
		
		cout << endl << BOLD(WHITE_BG(BLUE("¡¶ Setting"))) << endl << endl;
		rectangle.set_sides();
		
		cout << endl << string(50, '-') << endl;
		
		cout << endl << BOLD(WHITE_BG(BLUE("¡¶ Rectangle  Information"))) << endl;
		
		cout << endl << BOLD(GREEN("1. Rectangle Sides")) << endl;
		rectangle.get_sides();
		
		cout << endl << BOLD(GREEN("2. Square Judge")) << endl;
		if (rectangle.is_square()) cout << "¡° The rectangle is a square." << endl;
		else cout << "¡° The rectangle is "BOLD(RED("not"))" a square." << endl;
		
		cout << endl << BOLD(GREEN("3. Rectangle Area")) << endl;
		cout << "¡° The rectangle's area is " << rectangle.get_area() << " square "BOLD(UNDERLINE("millimeters"))"." << endl;
		cout << "¡° The rectangle's area is " << (double)rectangle.get_area()/100 << " square "BOLD(UNDERLINE("centimeters"))"." << endl;
		
		cout << endl << BOLD(GREEN("4. Rectangle Perimeter")) << endl;
		cout << "¡° The rectangle's perimeter is ";
		rectangle.get_perimeter().get_length();
		cout << endl;
		
		cout << endl << string(50, '=') << endl;
		
		while (true)
		{
			cout << endl << "Do you want to continue (Y/N) : ";
			getline(cin, input);
			
			stringstream s(input);
			
			if ((s >> choose) && !(s >> input))
			{
				choose = toupper(choose);
				
				if (choose == 'Y' || choose == 'N') break;
			}
			
			cout << endl << BOLD(YELLOW(RED_BG(" INPUT ERROR! ")) "Please enter Y or N.") << endl;
		}
		
		if (choose == 'N')
		{
			cout << endl << SHINE("Exit the System, see you next time!") << endl;
			break;
		}
	}
}
