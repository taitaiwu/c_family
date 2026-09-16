# include <iostream>
# include <string>
# include <cstdlib>
# include <unistd.h> 

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define UNDERLINE(string) "\x1b[4m" string "\x1b[0m" 
# define SHINE(string) "\x1b[6m" string "\x1b[0m" 
# define BLACK(string) "\x1b[30m" string "\x1b[0m"
# define RED(string) "\x1b[31m" string "\x1b[0m" 
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define BLUE(string) "\x1b[34m"string "\x1b[0m" 
# define GREEN(string) "\x1b[36m"string "\x1b[0m" 
# define WHITE(string) "\x1b[37m"string "\x1b[0m"
# define RED_BG(string) "\x1b[41m"string "\x1b[0m" 
# define BLUE_BG(string) "\x1b[46m"string "\x1b[0m" 
# define WHITE_BG(string) "\x1b[47m"string "\x1b[0m"

using namespace std;

int calculate(int day, int daily_rate, int medication, int service)
{
	return day*daily_rate + medication + service;
}

int calculate(int medication, int service)
{
	return medication + service;
}

int main (void)
{
	int id, day, daily_rate, medication, service, total;
	char user;
		
	do
	{
		cout << "" BLACK(BOLD(WHITE_BG(SHINE(" Welcome to OOP Hospital Pricing System~ "))))"" << endl << endl;
		cout << "What kind of patient are you, an inpatient or an outpatient?" << endl;
		cout << "- If you are an inpatirnt, please enter number \"" BOLD(RED("1"))"\"" << endl; 
		cout << "- If you are an outpatient, please enter number \"" BOLD(RED("2"))"\"" << endl;
		cout << "- If you want to exit the system, please enter number \"" BOLD(RED("9"))"\"" << endl;
		cout << "Please enter a integer to choose your identity : ";
		cin >> id;
	
		while (id != 1 && id != 2 && id != 9)
		{
			cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
			cout << "Please enter a integer to choose your identity : ";
			cin >> id;
		}
		
		if (id == 1)
		{
			cout << endl << "Please enter the price of the item below as an integer." << endl;
			
			cout << " The number of days spent in the hospital : ";
			cin >> day;
			while (day < 0)
			{
				cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
				cout << " The number of days spent in the hospital : ";
				cin >> day;
			}
			
			cout << " The daily rate : ";
			cin >> daily_rate;
			while (daily_rate < 0)
			{
				cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
				cout << " The daily rate : ";
				cin >> daily_rate;
			}
			
			cout << " Hospital medication charges : ";
			cin >> medication;
			while (medication < 0)
			{
				cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
				cout << " Hospital medication charges : ";
				cin >> medication;
			}
			
			cout << " Charges for hospital services (lab tests, etc.) : ";;
			cin >> service;
			while (service < 0)
			{
				cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
				cout << " Charges for hospital services (lab tests, etc.) : ";
				cin >> service;
			}
			
			total = calculate(day, daily_rate, medication, service);
			cout << endl << " The total price is " BOLD(UNDERLINE(WHITE(BLUE_BG(" $"))))"" << "\x1b[1;4;37;46m" << total << "\x1b[0m" << "" BOLD(UNDERLINE(WHITE(BLUE_BG(" "))))" ." << endl;
			cout << " ($" << day << " กั $" << daily_rate << " + $" << medication << " + $" << service <<")" << endl;
		}
		
		else if (id == 2)
		{
			cout << endl << "Please enter the price of the item below as an integer." << endl;
			
			cout << " Charges for hospital services (lab tests, etc.) : ";;
			cin >> service;
			while (service < 0)
			{
				cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
				cout << " Charges for hospital services (lab tests, etc.) : ";
				cin >> service;
			}
			
			cout << " Hospital medication charges : ";
			cin >> medication;
			while (medication < 0)
			{
				cout << endl << "" BOLD(""RED_BG("Input error!!")" Please try again.")"" << endl;
				cout << " Hospital medication charges : ";
				cin >> medication;
			}
			
			total = calculate(medication, service);
			cout << endl << " The total price is " BOLD(UNDERLINE(WHITE(BLUE_BG(" $"))))"" << "\x1b[1;4;37;46m" << total << "\x1b[0m" << "" BOLD(UNDERLINE(WHITE(BLUE_BG(" "))))" ." << endl;
			cout << " ($"  << medication << " + $" << service <<")" << endl;
		}
		
		else if (id == 9)
		{
			cout << endl << "" WHITE_BG(GREEN(" Thanks for your using. See you next time! "))"" << endl;
			break;
		}
		
		cout << endl << "" YELLOW(UNDERLINE("=============================================="))"" << endl << endl;	
	}while(1);
}
