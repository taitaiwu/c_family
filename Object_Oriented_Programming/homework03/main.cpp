// This homework was to be completed independently by the individual.

// This Project(homework3) has seven files¡G 
// main.cpp
// patient_account.h
// patient_account.cpp
// surgery.h
// surgery.cpp
// pharmacy.h
// pharmacy.cpp

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <ctime>

# include "patient_account.h"
# include "surgery.h"
# include "pharmacy.h"

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

using namespace std;

int main (void)
{
	int cost, room_cost;
	int choose, surgery_choose, pharmacy_choose, room_choose, day_choose;
	string choose_input, surgery_input, pharmacy_input, room_input, day_input, output;
	time_t now = time(0);
	
	Surgery surgery;
	Pharmacy pharmacy;
	Patient_account patient_account;
	
	cout << ""SHINE(BOLD(" ~~ Welcome to OOP Hospital Pricing System ~~ "))"" << endl << endl;
	
	while (true)
	{
		cout << "============== "BOLD("Function Menu")" ==============" << endl;
		cout << setw(10) << ""BOLD("No")"" << "\t"BOLD("Function Name")"" << endl;
		cout << setw(2) << "1" << "\tAdd Surgery" << endl;
		cout << setw(2) << "2" << "\tAdd Pharmacy" << endl;
		cout << setw(2) << "3" << "\tAdd Inpatient" << endl;
		cout << setw(2) << "4" << "\tShow Total Fees and Quit" << endl;
		
		while (true)
		{
			cout << "Please enter a integer to choose a function¡G";
			getline(cin, choose_input);
			stringstream s(choose_input);
			
			if ((s >> choose) && !(s >> choose_input) && (choose > 0) && (choose < 5))  break;
	
	    	cout << endl << ""BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))" Please enter a integer between "RED("1")" to "RED("4")".")"" << endl;
		}
		
		if (choose == 1)
		{
			cout << endl << "¡° Function 1¡G"BOLD(BLUE("Add Surgery"))"" << endl << endl;
			cout << "============== Surgery Menu ==============" << endl;
			cout << setw(10) << ""BOLD("No")""  << setw(34) << ""BOLD("Surgery Type")"" << setw(20) << ""BOLD("Price(NTD)")"" << endl;
			cout << setw(2) << "1" << setw(26) << "Cataract Surgery" << setw(11) << "$50000" << endl;
			cout << setw(2) << "2" << setw(26) << "Cesarean Section" << setw(11) << "$35000" << endl;
			cout << setw(2) << "3" << setw(26) << "Appendectomy" << setw(11) << "$60000" << endl;
			cout << setw(2) << "4" << setw(26) << "Knee Replacement Surgery" << setw(12) << "$150000" << endl;
			cout << setw(2) << "5" << setw(26) << "Laser Eye Surgery" << setw(11) << "$80000" << endl << endl;
			
			while (true)
			{
				cout << "Please enter a integer to choose a surgery¡G";
				getline(cin, surgery_input);
				stringstream s(surgery_input);
				
				if ((s >> surgery_choose) && !(s >> surgery_input) && (surgery_choose > 0) && (surgery_choose < 6))  break;
		
		    	cout << endl << ""BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))" Please enter a integer between "RED("1")" to "RED("5")".")"" << endl;
			}
			
			cost = surgery.get_cost(surgery_choose);
			patient_account.fee_cal(cost);
			
			cout << "=> "GREEN("Surgery Added¡G "UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << cost << "\x1b[0m" << endl;
			cout << "=> "GREEN("Cumulative Amount¡G "UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << patient_account.get_total() << "\x1b[0m" << endl << endl;
		}
		
		else if (choose == 2)
		{
			cout << endl << "¡° Function 2¡G"BOLD(BLUE("Add Pharmacy"))"" << endl << endl;
			cout << "============== Pharmacy Menu ==============" << endl;
			cout << setw(10) << ""BOLD("No")""  << setw(23) << ""BOLD("Surgery Type")"" << setw(20) << ""BOLD("Price(NTD)")"" << endl;
			cout << setw(2) << "1" << setw(15) << "Acetaminophen" << setw(11) << "$480" << endl;
			cout << setw(2) << "2" << setw(15) << "Ibuprofen" << setw(11) << "$150" << endl;
			cout << setw(2) << "3" << setw(15) << "Antacid" << setw(11) << "$120" << endl;
			cout << setw(2) << "4" << setw(15) << "Antihistamine" << setw(11) << "$100" << endl;
			cout << setw(2) << "5" << setw(15) << "Cold Medicine" << setw(11) << "$200" << endl << endl;
			
			while (true)
			{
				cout << "Please enter a integer to choose a surgery¡G";
				getline(cin, pharmacy_input);
				stringstream s(pharmacy_input);
				
				if ((s >> pharmacy_choose) && !(s >> pharmacy_input) && (pharmacy_choose > 0) && (pharmacy_choose < 6))  break;
		
		    	cout << endl << ""BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))" Please enter a integer between "RED("1")" to "RED("5")".")"" << endl;
			}
			
			cost = pharmacy.get_cost(pharmacy_choose);
			patient_account.fee_cal(cost);
			
			cout << "=> "GREEN("Pharmacy Added¡G "UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << cost << "\x1b[0m" << endl;
			cout << "=> "GREEN("Cumulative Amount¡G "UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << patient_account.get_total() << "\x1b[0m" << endl << endl;
		}
		
		else if (choose == 3)
		{
			cout << endl << "¡° Function 3¡G"BOLD(BLUE("Add Inpatient"))"" << endl << endl;
			cout << "=========== Hospital Room Menu ===========" << endl;
			cout << setw(10) << ""BOLD("No")""  << setw(34) << ""BOLD("Room Type")"" << setw(20) << ""BOLD("Price(NTD)")"" << endl;
			cout << setw(2) << "1" << setw(26) << "General Ward" << setw(11) << "$1000" << endl;
			cout << setw(2) << "2" << setw(26) << "Triple Room" << setw(11) << "$1800" << endl;
			cout << setw(2) << "3" << setw(26) << "Double Room" << setw(11) << "$2500" << endl;
			cout << setw(2) << "4" << setw(26) << "Single Room" << setw(11) << "$4500" << endl;
			cout << setw(2) << "5" << setw(26) << "Intensive Care Unit(ICU)" << setw(11) << "$10000" << endl;
			
			while (true)
			{
				cout << "Please enter a integer to choose a room type¡G";
				getline(cin, room_input);
				stringstream s(room_input);
				
				if ((s >> room_choose) && !(s >> room_input) && (room_choose > 0) && (room_choose < 6))  break;
		
		    	cout << endl << ""BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))" Please enter a integer between "RED("1")" to "RED("5")".")"" << endl;
			}
			
			while (true)
			{
				cout << "Please enter the number of days of hospital stay¡G";
				getline(cin, day_input);
				stringstream s(day_input);
				
				if ((s >> day_choose) && !(s >> day_input) && (day_choose > -1))  break;
		
		    	cout << endl << ""BOLD(YELLOW(RED_BG(" INPUT ERROR!! "))" Please enter a integer greater than "RED("0")".")"" << endl;
			}
			
			patient_account.days_cal(day_choose, room_choose);
			
			if (room_choose == 1) room_cost = 1000;
			else if (room_choose == 2) room_cost = 1800;
			else if (room_choose == 3) room_cost = 2500;
			else if (room_choose == 4) room_cost = 4500;
			else if (room_choose == 5) room_cost = 10000;
			else room_cost = 0;
			
			cout << "=> "GREEN("Inpatient Added¡G "UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << day_choose * room_cost << "\x1b[0m" << endl;
			cout << "=> "GREEN("Cumulative Amount¡G "UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << patient_account.get_total() << "\x1b[0m" << endl << endl;
		}
		
		else if (choose == 4)
		{
			cout << endl << "¡° Function 4¡G"BOLD(BLUE("Show Total Fees and Quit"))"" << endl << endl << endl;
			cout << ""SHINE(BOLD(" ~~~~~ OOP Hospital Bill ~~~~~ "))"" << endl << endl;
			cout << " => Total Fees¡G "GREEN(UNDERLINE(BOLD("$")))"" << "\x1b[1;4;36m" << patient_account.get_total() << "\x1b[0m" << endl;
			cout << " => Inpatient Days¡G " << "\x1b[1;4;36m" << patient_account.get_days() << " Day" << "\x1b[0m" << endl;
			
			if (patient_account.get_rate() == 1000) cout << " => Hospital Room¡G "GREEN(BOLD(UNDERLINE("General Ward ($1000)")))"" << endl;
			else if (patient_account.get_rate() == 1800) cout << " => Hospital Room¡G "GREEN(BOLD(UNDERLINE("Triple Room ($1800)")))"" << endl; 
			else if (patient_account.get_rate() == 2500) cout << " => Hospital Room¡G "GREEN(BOLD(UNDERLINE("Double Room ($2500)")))"" << endl;
			else if (patient_account.get_rate() == 4500) cout << " => Hospital Room¡G "GREEN(BOLD(UNDERLINE("Single Room ($4500)")))"" << endl;
			else if (patient_account.get_rate() == 10000) cout << " => Hospital Room¡G "GREEN(BOLD(UNDERLINE("Intensive Care Unit(ICU) ($10000)")))"" << endl;
			else cout << " => Hospital Room¡G "GREEN(BOLD(UNDERLINE("None")))"" << endl;
			
			cout << " => Export Time¡G " << "\x1b[1;4;36m" << ctime(&now) << "\x1b[0m" << endl;
			cout << " "WHITE_BG(BLACK("______ Wish You a Speedly Recovery. ______"))"" << endl;
			  
			break;
		}
	}
}
