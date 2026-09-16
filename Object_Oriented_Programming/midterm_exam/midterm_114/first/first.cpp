# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>

using namespace std;

int main (void)
{
	string input;
	char choose;
	int length, money;
	
	
	while (true)
	{
		while (true)
		{
			cout << "Please enter the length of column¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> length) && !(s >> input) && (length > 2) && (length < 50)) break;
			
			cout << endl << "INPUT ERROR! Please enter an integer between 3 to 49." << endl;
		}
		
		while (true)
		{
			cout << "How much do you enter¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> money) && !(s >> input) && (money > 0)) break;
			
			cout << endl << "INPUT ERROR! Please enter an integer greater than 0." << endl;
		}
		
		cout << string(length - input.length() - 1, '*') << "$" << money << endl << endl;
		
		while (true)
		{
			cout << "Do you want to continue(Y/N)¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> choose) && !(s >> input)) 
			{
				choose = toupper(choose);
				if (choose == 'Y' || choose == 'N') break;
			}
			
			cout << endl << "INPUT ERROR! Please enter Y or N" << endl;
		}
		
		if (choose == 'N')
		{
			cout << "Exit the progarm!" << endl;
			break;
		}
		
		
		cout << endl;
		
	}
}
