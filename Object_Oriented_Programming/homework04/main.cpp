# include <iostream>
# include <string>
# include <sstream>
# include <cctype>
# include <ctime>

# include "customer.h"
# include "car.h"
# include "service_quote.h"
# include "manager.h"

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

// This project(homework4) has nine files:
// customer.h & customer.cpp - customer information
// car.h & car.cpp - car information 
// service_quote.h & service_quote.h - create a quote
// manager.h & manager.cpp - manage all quotes
// main.cpp - main program

// User can enter 1~5 to choose a function and enter 9 to end the program.
// Some inputs will be invaildated, such as phone number, car number, date. 

using namespace std;

bool check_phone (string phone)
{
	int i = 0;
	
	if (phone.length() == 10 && phone[0] == '0' && phone[1] == '9')
	{
		for (i = 0; i < phone.length(); i++)
		{
			if (!isdigit(phone[i])) return false;
		}
		
		return true;
	}
	
	int dash = phone.find('-');
	
    if (dash == string::npos) return false;

    string area = phone.substr(0, dash);
    string number = phone.substr(dash + 1);

    if (area[0] != '0') return false;
    
    for (i = 0; i < area.length(); i++)
    {
    	if (!isdigit(area[i])) return false;
	}

    for (i = 0; i < number.length(); i++)
    {
    	if (!isdigit(number[i])) return false;
	}

    if (number.length() < 6 || number.length() > 8) return false;

    return true;
}

bool check_number (string number)
{
	int i;
	
    if (number.length() < 5 || number.length() > 8) return false;

    for (i = 0; i < number.length(); i++)
    {
        if (!(isalnum(number[i]) || number[i] == '-')) return false;
    }

    return true;
}

bool check_date (string date)
{
    if (date.length() != 10) return false;
    if (date[4] != '/' || date[7] != '/') return false;

    int year = atoi(date.substr(0,4).c_str());
    int month = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8,2).c_str());

    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) days[1] = 29;

    if (day > days[month - 1]) return false;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int this_year = 1900 + ltm->tm_year;
    int this_month = 1 + ltm->tm_mon;
    int this_day = ltm->tm_mday;

    if (year > this_year) return false;
    if (year == this_year && month > this_month) return false;
    if (year == this_year && month == this_month && day > this_day) return false;

    return true;
}

int main (void)
{
	string input;
	int choose;
	
	Manager manager;
	
	time_t now = time(0);
	tm* ltm = localtime(&now);
	
	cout << BOLD(SHINE("~~~ Welcome to Joe's Automotive Shop Online System ~~~ ")) << endl;
	
	while (true)
	{
		cout << endl << "============== "BOLD("Function Menu")" ==============" << endl;
		cout << setw(10) << BOLD("No") << "\t"BOLD("Function Name") << endl;
		cout << setw(2) << "1" << "\tAdd a Quote" << endl;
		cout << setw(2) << "2" << "\tDelete a Quote" << endl;
		cout << setw(2) << "3" << "\tSearch Quote by Guest Name" << endl;
		cout << setw(2) << "4" << "\tSearch Quote by Date" << endl;
		cout << setw(2) << "5" << "\tShow All Quotes" << endl;
		cout << setw(19) << BOLD(RED("9")) << "\t"BOLD(RED("Exit")) << endl;
		cout << "===========================================" << endl;
		
		while (true)
		{
			cout << endl << "Choose a function¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> choose) && !(s >> input) && ((choose > 0 && choose < 6) || choose == 9)) break;
			
			cout << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Please enter an integer between 1 to 5 or 9." << endl;
		}
		
		if (choose == 1)
		{
			string name, address, phone, make, model, number;
			int year, parts, labor;
			
			cout << endl << "¡° Function 1¡G"BOLD(BLUE("Add a Quote"))"" << endl << endl;
			cout << "Please fill in the following question." << endl;
			
			cout << BOLD("¡´ Customer Information") << endl;
			
			cout << string(2, ' ') << "¡³ Customer Name¡G";
			getline(cin, name);
			
			cout << string(2, ' ') << "¡³ Customer Address¡G";
			getline(cin, address);
			
			while (true)
			{
				cout << string(2, ' ') << "¡³ Customer Phone Number¡G";
				getline(cin, phone);
				
				if (check_phone(phone)) break;
				
				cout << endl << string(2, ' ') << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Input example¡G0912345678 or 04-7232105" << endl;
			}
			
			cout << endl << BOLD("¡´ Car Information") << endl;
			
			cout << string(2, ' ') << "¡³ Car Make¡G";
			getline(cin, make);
			
			cout << string(2, ' ') << "¡³ Car Model¡G";
			getline(cin, model);
			
			while (true)
			{
				cout << string(2, ' ') << "¡³ Car Year¡G";
				getline(cin, input);
				stringstream s(input);
				
				// data from https://zh.wikipedia.org/zh-tw/%E8%87%BA%E7%81%A3%E8%BB%8A%E8%BC%9B%E7%89%8C%E7%85%A7#:~:text=%E5%8F%B0%E7%81%A3%E7%9B%AE%E5%89%8D%E6%9C%89%E6%95%88%E7%9A%84%E8%BB%8A%E7%89%8C%E8%99%9F%E7%A2%BC%E6%98%AF%E4%BB%A51992%E5%B9%B4%E6%8F%9B%E7%99%BC%E7%9A%84%E7%82%BA%E4%B8%BB
				if ((s >> year) && !(s >> input) && (year > 1991) && (year < 1900 + ltm->tm_year + 1)) break;
				
				cout << endl << string(2, ' ') << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Please enter a number between 1992 to " << 1900 + ltm->tm_year << endl;
			}
			
			while (true)
			{
				cout << string(2, ' ') << "¡³ Car Number¡G";
				getline(cin, number);
				
				if (check_number(number)) break;
				
				cout << endl << string(2, ' ') << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Input example¡GABC-1254, AB-1234, or 1234-AB" << endl;
			}
			
			cout << endl << BOLD("¡´ Charge Information") << endl;
			
			while (true)
			{
				cout << string(2, ' ') << "¡³ Patrs Charge¡G";
				getline(cin, input);
				stringstream s(input);
				
				if ((s >> parts) && !(s >> input) && (parts >= 0)) break;
				
				cout << endl << string(2, ' ') << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Please enter a positive integer." << endl;
			}
			
			while (true)
			{
				cout << string(2, ' ') << "¡³ Labor Charge¡G";
				getline(cin, input);
				stringstream s(input);
				
				if ((s >> labor) && !(s >> input) && (labor >= 0)) break;
				
				cout << endl << string(2, ' ') << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Please enter a positive integer." << endl;
			}
			
			Customer customer(name, address, phone);
			Car car(make, model, year, number);
			Service_quote q(customer, car, parts, labor);
			manager.add_quote(q);
		}
		
		else if (choose == 2)
		{
			int index;
			
			cout << endl << "¡° Function 2¡G"BOLD(BLUE("Delete a Quote"))"" << endl << endl;
			
			manager.show_all_quote();
			
			if (manager.get_quote_size() == 0) continue;
			
			while (true)
			{
				cout << "Please enter a index which you want to delete¡G";
				getline(cin, input);
				stringstream s(input);
				
				if ((s >> index) && !(s >> input) && (index > 0)) break;
				
				cout << endl << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Please enter a positive integer." << endl;
			}
			
			manager.delete_quote(index-1);
		}
		
		else if (choose == 3)
		{
			string name;
			
			cout << endl << "¡° Function 3¡G"BOLD(BLUE("Search Quote by Guest Name"))"" << endl << endl;
			cout << "Please enter a name¡G";
			getline(cin, name);
			manager.search_by_name(name);
		}
		
		else if (choose == 4)
		{
			string date;
			
			cout << endl << "¡° Function 4¡G"BOLD(BLUE("Search Quote by Date"))"" << endl << endl;
			
			while (true)
			{
				cout << "Please enter a date (YYYY/MM/DD)¡G";
				getline(cin, date);
				
				if (check_date(date)) break;
				
				cout << endl << BOLD(RED_BG(YELLOW(" INPUT ERROR! "))) << " Please enter a correct date (YYYY/MM/DD)." << endl;
			}
			
			manager.search_by_date(date);
		}
		
		else if (choose == 5)
		{
			cout << endl << "¡° Function 5¡G"BOLD(BLUE("Show All Quotes"))"" << endl << endl;
			manager.show_all_quote();
		}
		
		else if (choose == 9)
		{
			cout << endl << BLACK(WHITE_BG(" ~ Good Bye ~ ")) << endl;
			break;
		}
	}
}
