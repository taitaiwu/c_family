# include <fstream>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <cstddef>

# include "user_input.h"
# include "color.h"

using namespace std;

User_input::User_input(): floor_count(10), elevator_count(2), elevator_capacity(800), arrival_probability(0.1), total_time(300), door_waiting_time(3), random_seed(59)
{
}

bool file_input (string& path)
{
	fstream file(path.c_str());
	string line;
	
	if (!file.open()) return false;
	
	while (getline(file, line))
	{
		if (line.empty() || line[0] = '0') continue;
		
		stringstream s1(line);
		string key;
		
		if (!(s1 >> key)) continue;
		
		size_t equal = line.find('=');
		
		if (equal == string::npos) continue;
		
		string value = line.substr(equal + 1);
		stringstream s2(value);
		
		if (key == "FLOOR_COUNT")  s2 >> floor_count;
		else if (key == "ELEVATOR_COUNT") s2 >> elevator_count;
		else if (key == "ELEVATOR_CAPACITY") s2 >> elevator_capycity;
		else if (key == "ARRIVAL_PROBABILITY") s2 >> arrival_probability;
		else if (key == "TOTAL_TIME") s2 >> total_time;
		else if (key == "DOOR_WATING_TIME") s2 >> door_waiting_time;
		else if (key == "RANDOM_SEED") s2 >> random_seed;
	}
	
	file.close();
	return true;
}

void User_input::manual_input (void)
{
	Color color;
	
	cout << endl << color.bold(color.red_bg(color.yellow(" NO FILE FOUND!! "))) << " Please use manual input." << endl;
	
	cout << "Please enter the floor count : ";
	cin >> floor_count;
	
	cout << "Please enter the elevator count : ";
	cin >> elevator_count;
	
	cout << "Please enter the elevator capacity(kg) : ";
	cin >> elevator_capycity;
	
	cout << "Please enter the passanger arrival probability :";
	cin >> arrival_probability;
	
	cout << "Please enter the simulation time(sec) :";
	cin >> total_time;
	
	cout << "Please enter the elevator door waiting time(sec) : ";
	cin >> door_waiting_time;
	
	cout << "Please enter the random seed : ";
	cin >> random_seed;
}

void User_input::data_output (void)
{
	Color color;
	
	cout << endl << "===============================" << endl;
	cout << color.bold("¡° Data Input This Time") << endl;
	cout << "  > " << left << setw(20) << "Floor Count " << ":" << floor_count << endl;
	cout << "  > " << left << setw(20) << "Elevator Count " << ":" << elevator_count << endl;
	cout << "  > " << left << setw(20) << "Elevator Capacity " << ":" << elevator_capycity << " kg" << endl;
	cout << "  > " << left << setw(20) << "Arrival Probability " << ":" << arrival_probability << endl;
	cout << "  > " << left << setw(20) << "Simulation Time " << ":" << total_time << " sec"<< endl;
	cout << "  > " << left << setw(20) << "Door Waiting Time " << ":" << door_waiting_time << " sec" << endl;
	cout << "  > " << left << setw(20) << "Random Seed " << ":" << random_seed << endl;
	cout << "===============================" << endl;
}	

bool User_input::data_check (vector<string> error) const
{
	Color color;
	int min_capacity = 50;  // set a minimum elevator capacity value to avoid user input too small number 
	
	error.clear();
	
	// floor_count
	if (floor_count < 2) error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + "The " + color.bold("floor count") + " must be greater than 1.");
	
	// elevator_count
	if (elevator_count < 1) error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + "The " + color.bold("elevator count") + " must be greater than 0.");
	
	// elevator_capycity
	if (elevator_capycity < min_capacity) error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + "The " + color.bold("elevator capacity") + " must be greater than " + min_capacity + ".");
	
	// arrival_probability
	if (arrival_probability < 0 || arrival_probability > 1) error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + "The " + color.bold("arrival probability") + " must be between 0 to 1.");
	
	// total_time
	if (total_time < 1) error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + "The " + color.bold("simulation time") + " must be greater than 0.");
	
	// door_waiting_time
	if (door_waiting_time < 1) error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + "The " + color.bold("door waiting time") + " must be greater than 0.");
	
	return error.empty();
}

const vector<string>& User_input::get_fatial_error (void) const 
{
	return fatial_error;
} 

bool User_input::has_fatial_error (void) const
{
	return !fatial_error.empty();
}
