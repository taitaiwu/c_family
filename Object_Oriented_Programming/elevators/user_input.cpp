# include <fstream>
# include <sstream>
# include <iostream>
# include <iomanip>

# include "user_input.h"
# include "color.h"

using namespace std;

namespace
{
	string trim(const string& s)
	{
		size_t start = s.find_first_not_of(" \t\r\n");

		if (start == string::npos) return "";

		size_t end = s.find_last_not_of(" \t\r\n");

		return s.substr(start, end - start + 1);
	}
}

User_input::User_input(void)
	: floor_count(10), elevator_count(2), elevator_capacity(800), arrival_probability(0.1),
	  total_time(300), door_waiting_time(3), random_seed(59), animate(true), animation_delay_ms(80)
{
}

bool User_input::file_input(const string& path)
{
	ifstream file(path.c_str());

	if (!file.is_open()) return false;

	string line;

	while (getline(file, line))
	{
		if (line.empty() || line[0] == '#') continue;

		size_t equal = line.find('=');

		if (equal == string::npos) continue;

		string key = trim(line.substr(0, equal));
		string value = trim(line.substr(equal + 1));

		if (key.empty()) continue;

		stringstream stream(value);

		if (key == "FLOOR_COUNT") stream >> floor_count;
		else if (key == "ELEVATOR_COUNT") stream >> elevator_count;
		else if (key == "ELEVATOR_CAPACITY") stream >> elevator_capacity;
		else if (key == "ARRIVAL_PROBABILITY") stream >> arrival_probability;
		else if (key == "TOTAL_TIME" || key == "SIMULATION_DURATION") stream >> total_time;
		else if (key == "DOOR_WAITING_TIME" || key == "DOOR_DWELL_TIME") stream >> door_waiting_time;
		else if (key == "RANDOM_SEED") stream >> random_seed;
		else if (key == "ANIMATE") stream >> animate;
		else if (key == "ANIMATION_DELAY_MS") stream >> animation_delay_ms;
	}

	file.close();
	return true;
}

void User_input::manual_input(void)
{
	Color color;

	cout << endl << color.bold(color.red_bg(color.yellow(" NO FILE FOUND!! "))) << " Please use manual input." << endl;

	cout << "Please enter the floor count : ";
	cin >> floor_count;

	cout << "Please enter the elevator count : ";
	cin >> elevator_count;

	cout << "Please enter the elevator capacity(kg) : ";
	cin >> elevator_capacity;

	cout << "Please enter the passenger arrival probability : ";
	cin >> arrival_probability;

	cout << "Please enter the simulation time(sec) : ";
	cin >> total_time;

	cout << "Please enter the elevator door waiting time(sec) : ";
	cin >> door_waiting_time;

	cout << "Please enter the random seed : ";
	cin >> random_seed;

	cout << "Show live animation while simulating? (1 = yes, 0 = no) : ";
	cin >> animate;
}

void User_input::data_output(void) const
{
	Color color;

	cout << endl << "===============================" << endl;
	cout << color.bold("Data Input This Time") << endl;
	cout << "  > " << left << setw(22) << "Floor Count" << ":" << floor_count << endl;
	cout << "  > " << left << setw(22) << "Elevator Count" << ":" << elevator_count << endl;
	cout << "  > " << left << setw(22) << "Elevator Capacity" << ":" << elevator_capacity << " kg" << endl;
	cout << "  > " << left << setw(22) << "Arrival Probability" << ":" << arrival_probability << endl;
	cout << "  > " << left << setw(22) << "Simulation Time" << ":" << total_time << " sec" << endl;
	cout << "  > " << left << setw(22) << "Door Waiting Time" << ":" << door_waiting_time << " sec" << endl;
	cout << "  > " << left << setw(22) << "Random Seed" << ":" << random_seed << endl;
	cout << "  > " << left << setw(22) << "Live Animation" << ":" << (animate ? "ON" : "OFF") << endl;
	cout << "===============================" << endl;
}

bool User_input::data_check(void)
{
	Color color;
	const int min_capacity = 50; // �קK�ϥΪ̿�J�L�p�������q����

	fatal_error.clear();

	if (floor_count < 2)
		fatal_error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + " The " + color.bold("floor count") + " must be greater than 1.");

	if (elevator_count < 1)
		fatal_error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + " The " + color.bold("elevator count") + " must be greater than 0.");

	if (elevator_capacity < min_capacity)
		fatal_error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + " The " + color.bold("elevator capacity") + " must be greater than " + to_string(min_capacity) + ".");

	if (arrival_probability < 0 || arrival_probability > 1)
		fatal_error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + " The " + color.bold("arrival probability") + " must be between 0 and 1.");

	if (total_time < 1)
		fatal_error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + " The " + color.bold("simulation time") + " must be greater than 0.");

	if (door_waiting_time < 1)
		fatal_error.push_back(color.bold(color.red_bg(color.yellow(" INPUT ERROR!! "))) + " The " + color.bold("door waiting time") + " must be greater than 0.");

	return fatal_error.empty();
}

const vector<string>& User_input::get_fatal_error(void) const
{
	return fatal_error;
}

bool User_input::has_fatal_error(void) const
{
	return !fatal_error.empty();
}
