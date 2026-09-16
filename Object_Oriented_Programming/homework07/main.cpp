# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <sstream>
# include <vector>

# include "encryption_filter.h"
# include "uppercase_filter.h"
# include "copy_filter.h"
# include "line_break_removal_filter.h"

# define BOLD(s) "\x1b[1m" s "\x1b[0m" 
# define UNDERLINE(s) "\x1b[4m" s "\x1b[0m" 
# define SHINE(s) "\x1b[6m" s "\x1b[0m" 
# define BLACK(s) "\x1b[30m" s "\x1b[0m"
# define RED(s) "\x1b[31m" s "\x1b[0m" 
# define YELLOW(s) "\x1b[33m" s "\x1b[0m" 
# define BLUE(s) "\x1b[34m"s "\x1b[0m" 
# define GREEN(s) "\x1b[36m"s "\x1b[0m" 
# define RED_BG(s) "\x1b[41m"s "\x1b[0m" 
# define WHITE_BG(s) "\x1b[47m"s "\x1b[0m"

// This project(homework07) has eleven files:
// file_filter.h & file_filter.cpp - main class
// encryption_filter.h & encryption_filter.cpp - an integer key and uses it to encrypt each character (XOR)
// uppercase_filter.h & uppercase_filter.cpp - converts all characters to uppercase
// copy_filter.h & copy_filter.cpp - passes characters through unchanged
// line_break_removal_filter.h & line_break_removal_filter.cpp - replaces every newline character in the file with a single space
// main.cpp - main program

// User can enter an integer between 1 to 4 to choose four types of filters.
// Multiple filters can be selected and applied in sequence.
// Automatically appends ".txt" if no file extension is provided.
// Some inputs will be invaildated, such as input file, function choose, continue choose, etc. 
// This program is based on Dev C++ 5.11 (C++98). Using other versions or compilers may result in compilation errors.

// User can use test file(input.txt) to test, the test output should be as follows(test data generate by claude).
// uppercase¡G
// HELLO WORLD
// THIS IS A TEST
// ABC 123 DEF

// line-break removal:
// hello world this is a test abc 123 def

// encryption (key = 5):
// mjqqt%|twqi
// if you user the same key, you can get origin input.

// uppercase+line-break removal (choose 2 4)¡G
// HELLO WORLD THIS IS A TEST ABC 123 DEF


using namespace std;

int main (void)
{
	cout << BOLD(SHINE("~~~ Welcome to OOP File Filter System ~~~ ")) << endl << endl;
	
	while (true)
	{
		string input_file, output_file, input, output;
		ifstream in;
		ofstream out;
		vector<int> function;
		vector<File_filter*> filters;	
		int choose;
		bool vaild;
		char ch, yn;
		
		while (true)
		{
			cout << "Please enter input file name : ";
			getline(cin, input_file);
			
			if (input_file.find('.') == string::npos) input_file += ".txt";
			
			in.open(input_file.c_str());
			
			if (in) break;
			
			cout << endl  << BOLD(YELLOW(RED_BG(" ERROR 404 "))) << " " << input_file << " not found." << endl;
		}
		
		cout << "Please enter output file name : ";
		getline(cin, output_file);
		
		if (output_file.find('.') == string::npos) output_file += ".txt";
		
		out.open(output_file.c_str());
		
		cout << endl << "¡° " << input_file << " has been found." << endl;
		cout << "¡° " << output_file << " has been created." << endl;
		
		cout << endl << "============== " << BOLD("Filter Menu") << " ==============" << endl;
		cout << setw(10) << BOLD("No") << "\t" << BOLD("Function") << endl;
		cout << setw(2) << "-----------------------------------------" << endl;
		cout << setw(2) << "1" << "\tEncryption Filter" << endl;
		cout << setw(2) << "2" << "\tUppercase Filter" << endl;
		cout << setw(2) << "3" << "\tCopy Filter" << endl;
		cout << setw(2) << "4" << "\tLine-Break Removal Filter" << endl;
		cout << "=========================================" << endl << endl;
		
		cout << BOLD("¡° You can choose one and more function, separated by spaces.") << endl;
		cout << BOLD("¡° Different input orders may result in different results.") << endl << endl;
		
		while (true)
		{
			vaild = true;
			
			cout << "Please enter the filter you need : ";
			getline(cin >> ws, input);
			
			stringstream s(input);
			
			while (s >> choose)
			{
				if (choose < 1 || choose > 4)
				{
					vaild = false;
					break;
				}
				
				function.push_back(choose);
			}
			
			if (s >> input) vaild = false;
			
			if (!vaild)
			{
				cout << endl  << BOLD(YELLOW(RED_BG(" INPUT ERROR "))) << " Please enter integers between 1 to 4" << endl;
				continue;
			}		
			
			break;
		}
		
		for (int i = 0; i < function.size(); i++)
		{
			if (function[i] == 1)
			{
				int key;
				
				while (true)
				{
					cout << "Please enter encryption key (integer) : ";
					getline(cin, input);
					
					stringstream s(input);
					
					if ((s >> key) && !(s >> input)) break;
					
					cout << endl << BOLD(YELLOW(RED_BG(" INPUT ERROR "))) << " Please enter an integer." << endl;
				}
				
				filters.push_back(new Encryption_filter(key));
				output += "encryption filter, ";
			}
			
			else if (function[i] == 2)
			{
				filters.push_back(new Uppercase_filter());
				output += "uppercase filter, ";
			}
			
			else if (function[i] == 3)
			{
				filters.push_back(new Copy_filter());
				output += "copy filter, ";
			}
			
			else if (function[i] == 4)
			{
				filters.push_back(new Line_break_removal_filter());
				output += "line-break removal filter, ";
			}
		}
		
		output[0] = toupper(output[0]);
		output = output.substr(0, output.size() - 2);
		
		while (in.get(ch))
		{
			for (int i = 0; i < filters.size(); i++)
			{
				ch = filters[i]->transform(ch);
			} 
			
			out.put(ch);
		}
		
		for (int i = 0; i < filters.size(); i++)
		{
			delete filters[i];
		} 
		
		cout << endl << "\x1b[1m\x1b[36m" << output << "(" << output_file << ")" << "\x1b[0m" << GREEN(" is done!") << endl;
		
		while (true)
		{
			cout << endl << BOLD("Do you want to continue(Y/N) : ");
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> yn) && !(s >> input)) 
			{
				yn = toupper(yn);
				if (yn == 'Y' || yn == 'N') break;
			}
			
			cout << endl << BOLD(YELLOW(RED_BG(" INPUT ERROR "))) << " Please enter Y or N" << endl;
		}
		
		if (yn == 'N')
		{
			cout << endl << SHINE("Exit the System, see you next time!") << endl;
			break;
		}
		
		cout << endl;
	}
}
