# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>
# include <vector>

# include "publication.h"
# include "book.h"
# include "journal.h"
# include "magazine.h"

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

// This project(homework06) has nine files:
// publication.h & publication.cpp - set a publication's information, such as title, volume, and year
// book.h & book.cpp - set a book's information, such as author, ISBN and price
// journal.h & journal.cpp - set a journal's information, such as month, ISSN, impact factor and annual subscription
// magazine.h & magazine.cpp - set a magazine's information, such as a month, editor and annual subscription
// main.cpp - main program

// User can enter an integer between 1 to 3 to choose add, delete, or show publications.
// User can enter an integer between 1 to 3 to choose book, journal, or magazine in add and delete function.
// User can enter 9 to exit or cancel in every function.
// Some inputs will be invaildated, such as integer input, year, ISBN, ISSN, etc. 
// This program is based on Dev C++ 5.11 (C++98). Using other versions or compilers may result in compilation errors.

using namespace std;

int main (void)
{
	vector<Book>     books;
    vector<Journal>  journals;
    vector<Magazine> magazines;
    
    Book book;
    Journal journal;
    Magazine magazine;
    
	string input;
	int choose1, choose2;
	
	cout << BOLD(SHINE("~~~ Welcome to OOP Publication Management System ~~~ ")) << endl;
	
	while (true)
	{
		cout << endl << "============== "BOLD("Function Menu")" ==============" << endl;
		cout << setw(10) << BOLD("No") << "\t"BOLD("Function Name") << endl;
		cout << setw(2) << "1" << "\tAdd a Publication" << endl;
		cout << setw(2) << "2" << "\tDelete a Publication" << endl;
		cout << setw(2) << "3" << "\tShow All Publication" << endl;
		cout << setw(19) << BOLD(RED("9")) << "\t"BOLD(RED("Exit")) << endl;
		cout << "===========================================" << endl;
		
		while (true)
		{
			cout << endl << "Choose a function¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> choose1) && !(s >> input) && ((choose1 > 0 && choose1 < 4) || choose1 == 9)) break;
			
			cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 1 to 3 or 9." << endl;
		}
		
		if (choose1 == 1) // Add
		{
			cout << endl << "¡¹ Function 1¡G"BOLD(BLUE("Add a Publication"))"" << endl << endl;
			cout << "=========== Publication Menu ===========" << endl;
			cout << setw(10) << BOLD("No") << BOLD("\tPublication Type") << endl;
			cout << setw(2) << "1" << "\tBook" << endl;
			cout << setw(2) << "2" << "\tJournal"  << endl;
			cout << setw(2) << "3" << "\tMagazine" << endl;
			cout << setw(19) << BOLD(RED("9")) << "\tCancel" << endl << endl;
			
			while (true)
			{
				cout << "Please enter a integer to choose a publication : ";
				getline(cin, input);
				stringstream s(input);
				
				if ((s >> choose2) && !(s >> input) && ((choose2 > 0 && choose2 < 4) || choose2 == 9))  break;
		
		    	cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 1 to 3 or 9." << endl;
			}
			
			if (choose2 == 1)  // Add a Book
			{
				cout << endl << "¡¹ Function 1-1¡G"BOLD(BLUE("Add a Book"))"" << endl << endl;			
				book.input();
				books.push_back(book);
				cout << endl << "> " << GREEN("Add a book successfully.") << endl;
			}
			
			else if (choose2 == 2)  // Add a Journal
			{
				cout << endl << "¡¹ Function 1-2¡G"BOLD(BLUE("Add a Journal"))"" << endl << endl;			
				journal.input();
				journals.push_back(journal);
				cout << endl << "> " << GREEN("Add a journal successfully.") << endl;
			}
			
			else if (choose2 == 3)  // Add a Magazine
			{
				cout << endl << "¡¹ Function 1-3¡G"BOLD(BLUE("Add a Magazine"))"" << endl << endl;			
				magazine.input();
				magazines.push_back(magazine);
				cout << endl << "> " << GREEN("Add a magazine successfully.") << endl;
			}
			
			else if (choose2 == 9)  // Cancel Add
			{
				cout << endl << "> " << WHITE_BG(BLACK(" Cancel add. ")) << endl;
			}
		}
		
		else if (choose1 == 2)  // Delete
		{
			cout << endl << "¡¹ Function 2¡G"BOLD(BLUE("Delete a Publication"))"" << endl << endl;
			cout << "=========== Publication Menu ===========" << endl;
			cout << setw(10) << BOLD("No") << BOLD("\tPublication Type") << endl;
			cout << setw(2) << "1" << "\tBook" << endl;
			cout << setw(2) << "2" << "\tJournal"  << endl;
			cout << setw(2) << "3" << "\tMagazine" << endl;
			cout << setw(19) << BOLD(RED("9")) << "\tCancel" << endl << endl;
			
			while (true)
			{
				cout << "Please enter a integer to choose a publication : ";
				getline(cin, input);
				stringstream s(input);
				
				if ((s >> choose2) && !(s >> input) && ((choose2 > 0 && choose2 < 4) || choose2 == 9))  break;
		
		    	cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 1 to 3 or 9." << endl;
			}
			
			if (choose2 == 1)  // Delete a Book
			{
				cout << endl << "¡¹ Function 2-1¡G"BOLD(BLUE("Delete a Book"))"" << endl << endl;
				
				if (books.empty()) cout << "> " << BOLD(RED(" There are no any books.")) << endl;
				
				else
				{
					for (int i = 0; i < books.size(); i++)
					{
						cout << "# No." << setw(2) << i+1 << endl;
						books[i].output();
						cout << "------------------------------" << endl;
					}
					
					while (true)
					{
						cout << "Please enter a index to delete the book (enter 0 to cancel) : ";
						getline(cin, input);
						stringstream s(input);
						
						if ((s >> choose2) && !(s >> input) && (choose2 >= 0) && (choose2 <= books.size()))  break;
				
				    	cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 0 to " << books.size() << "." << endl;
					}
					
					if (choose2 == 0) cout << endl << WHITE_BG(BLACK(" Cancel delete a book. ")) << endl;
					else
					{
						books.erase(books.begin() + choose2 - 1);
						cout << endl << "> " << GREEN("Delete a book successfully.") << "(No." << setw(2) << choose2 << ")" << endl;
					} 
				}
			}
			
			else if (choose2 == 2)  // Delete a Journal
			{ 
				cout << endl << "¡¹ Function 2-2¡G"BOLD(BLUE("Delete a Journal"))"" << endl << endl;
				
				if (journals.empty()) cout << "> " << BOLD(RED(" There are no any journals.")) << endl;
				
				else
				{
					for (int i = 0; i < journals.size(); i++)
					{
						cout << "# No." << setw(2) << i+1 << endl;
						journals[i].output();
						cout << "------------------------------" << endl;
					}
					
					while (true)
					{
						cout << "Please enter a index to delete the journal (enter 0 to cancel) : ";
						getline(cin, input);
						stringstream s(input);
						
						if ((s >> choose2) && !(s >> input) && (choose2 >= 0) && (choose2 <= journals.size()))  break;
				
				    	cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 0 to " << journals.size() << "." << endl;
					}
					
					if (choose2 == 0) cout << endl << WHITE_BG(BLACK(" Cancel delete a journal. ")) << endl;
					else
					{
						journals.erase(journals.begin() + choose2 - 1);
						cout << endl << "> " << GREEN("Delete a journal successfully.") << "(No." << setw(2) << choose2 << ")" << endl;
					} 
				}
			}
			
			else if (choose2 == 3)  // Delete a Magazine
			{
				cout << endl << "¡¹ Function 2-3¡G"BOLD(BLUE("Delete a Magazine"))"" << endl << endl;
				
				if (magazines.empty()) cout << "> " << BOLD(RED(" There are no any magazines.")) << endl;
				
				else
				{
					for (int i = 0; i < magazines.size(); i++)
					{
						cout << "# No." << setw(2) << i+1 << endl;
						magazines[i].output();
						cout << "------------------------------" << endl;
					}
					
					while (true)
					{
						cout << "Please enter a index to delete the magazine (enter 0 to cancel) : ";
						getline(cin, input);
						stringstream s(input);
						
						if ((s >> choose2) && !(s >> input) && (choose2 >= 0) && (choose2 <= magazines.size()))  break;
				
				    	cout << endl << setw(2) << BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))) << " Please enter a integer between 0 to " << magazines.size() << "." << endl;
					}
					
					if (choose2 == 0) cout << endl << WHITE_BG(BLACK(" Cancel delete a magazine. ")) << endl;
					else
					{
						magazines.erase(magazines.begin() + choose2 - 1);
						cout << endl << "> " << GREEN("Delete a magazine successfully.") << "(No." << setw(2) << choose2 << ")" << endl;
					} 
				}
			}
		}
		
		else if (choose1 == 3) // Show all
		{
			cout << endl << "¡¹ Function 3¡G"BOLD(BLUE("Show All Publication"))"" << endl << endl;
			
			cout << "@ Books" << endl;
			if (books.size() == 0) cout << "None." << endl;
			else
			{
				for (int i = 0; i < books.size(); i++)
				{
					cout << "# No." << setw(2) << i+1 << endl;
					books[i].output();
					cout << "------------------------------" << endl;
				}
			}
			
			cout << endl << "@ Journal" << endl;
			if (journals.size() == 0) cout << "None." << endl;
			else
			{
				for (int i = 0; i < journals.size(); i++)
				{
					cout << "# No." << setw(2) << i+1 << endl;
					journals[i].output();
					cout << "------------------------------" << endl;
				}
			}
			
			cout << endl << "@ Magazine" << endl;
			if (magazines.size() == 0) cout << "None." << endl;
			else
			{
				for (int i = 0; i < magazines.size(); i++)
				{
					cout << "# No." << setw(2) << i+1 << endl;
					magazines[i].output();
					cout << "------------------------------" << endl;
				}
			}
		}
		
		else if (choose1 == 9)
		{
			cout << endl << SHINE("Exit the System, see you next time!") << endl;
			break;
		}
	}
}
