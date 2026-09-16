# include "elevator_panel.h"

using namespace std;

explicit Elevator_panel::Elevator_panel (int f): floor(f)
{
}

void Elevator_panel::passenger_line (Passenger* passenger)
{
	if (passenger->is_up())
	{
		up_line.push_back(passenger);
		up_button.press();
	}
	
	else
	{
		down_line.push_back(passenger);
		down_button.press();
	}
}

vector<Passenger*> Elevator_panel::get_passenger_line (bool up)
{
	return up? up_line:down_line;
}

void Elevator_panel::remove_in_elevator (bool up, int count)
{
	vector<Passenger*>& line = up? up_line:down_line;
	int n = count < static_cast<int>(line.size())? count:static_cast<int>(line.size());
	line.erase(line.begin(), line.begin() + n);
}

void Elevator_panel::clear_button (bool up)
{
	if (up && up_line.empty()) up_button.clear();
	else if (!up && down_line.empty()) down_button.clear();
}

bool Elevator_panel::is_up_button_light (void) const
{
	return up_button.is_light();
}

bool Elevator_panel::is_down_button_light (void) const
{
	return down_button.is_light();
}

int Elevator_panel::get_up_size (void) const
{
	return static_cast<int>(up_line.size());
}

int Elevator_panel::get_down_size (void) const
{
	return static_cast<int>(down_line.size());
}

int Elevator_panel::get_floor (void) const
{
	return floor;
}

vector<Passenger*> Elevator_panel::clear_line(void)
{
	vector<Passenger> all;
	
	all.insert(all.end(), up_line.begin(), up_line.end());
	all.insert(all.end(), down_line.begin(), down_line.end());
	up_line.clear();
	down_line.clear();
	return all;
}

vector<Passenger*> Elevator_panel::clear_waiting(void)
{
	vector<Passenger> all;
	
	all.insert(all.end(), up_line.begin(), up_line.end());
	all.insert(all.end(), down_line.begin(), down_line.end());
	up_line.clear();
	down_line.clear();
	up_button.clear();
	down_button.clear();
	return all;
}
