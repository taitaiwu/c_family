# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <sstream>

# include "inventory_file.h"
# include "color.h"

using namespace std;

// This project(homework08) has six files:
// inventory_item.h - struct Inventory_item
// inventory_file.h & inventory_file.cpp - functions
// color.h & color.cpp - CMD word color
// main.cpp - main program

// User can enter an integer between 1 to 3 to choose add, display, or change a record.
// Automatically appends ".dat" if no file extension is provided.
// Some inputs will be invaildated, such as integer input, data input, etc. 
// This program is based on Dev C++ 5.11 (C++98). Using other versions or compilers may result in compilation errors.
// This program is tested on CMD. (g++ inventory_file.cpp color.cpp main.cpp -o main)

int menu();

int main() 
{
	Color color;
    string file_name, input;
    int choose;
    
    cout << "Please input the file name you want to save :";
    getline(cin, file_name);
    
    size_t dotPos = file_name.find_last_of('.');
	size_t slashPos = file_name.find_last_of("/\\");
	
	if (dotPos == string::npos || (slashPos != string::npos && dotPos < slashPos)) file_name += ".dat";

    Inventory_file inventory(file_name);
    
    while (true)
    {
    	cout << endl << "============== " << color.bold("Inventory Menu") << " ==============" << endl;
		cout << setw(10) << color.bold("No") << "\t" << color.bold("Function") << endl;
		cout << setw(2) << "-----------------------------------------" << endl;
		cout << setw(2) << "1" << "\tAdd a New Item" << endl;
		cout << setw(2) << "2" << "\tDisplay an Item" << endl;
		cout << setw(2) << "3" << "\tChange an Item" << endl;
		cout << setw(11) << color.red("9") << "\t" << color.red("Exit the Progarm") << endl;
		cout << "=========================================" << endl << endl;
		
		while (true)
		{
			cout << "Please input an integer to choose a function : ";
			getline(cin, input);
			
			stringstream s(input);
			
			if ((s >> choose) && !(s >> input) && (((choose > 0) && (choose < 4)) || (choose == 9))) break;
			
			cout << endl << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input a integer between 1 to 3 or 9." << endl; 
		}
		
		if (choose == 1) inventory.add_record();
		else if (choose == 2) inventory.display_record();
		else if (choose == 3) inventory.change_record();
		else if (choose == 9)
		{
			cout << endl << color.shine("Exit the System, see you next time!") << endl;
			break;
		}
	}
}
