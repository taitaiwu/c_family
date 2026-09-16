#include "hall_panel.h"

Hall_panel::Hall_panel(int f): floor(f)
{
}

void Hall_panel::add_passenger(Passenger* passenger)
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

bool Hall_panel::has_waiting(bool up) const
{
	return up ? !up_line.empty() : !down_line.empty();
}

Passenger* Hall_panel::front(bool up) const
{
	const vector<Passenger*>& line = up ? up_line : down_line;
	return line.front();
}

void Hall_panel::pop_front(bool up)
{
	vector<Passenger*>& line = up ? up_line : down_line;
	line.erase(line.begin());

	if (line.empty())
	{
		if (up) up_button.clear();
		else down_button.clear();
	}
}

bool Hall_panel::is_up_button_light(void) const
{
	return up_button.is_light();
}

bool Hall_panel::is_down_button_light(void) const
{
	return down_button.is_light();
}

int Hall_panel::get_up_count(void) const
{
	return static_cast<int>(up_line.size());
}

int Hall_panel::get_down_count(void) const
{
	return static_cast<int>(down_line.size());
}

int Hall_panel::get_floor(void) const
{
	return floor;
}
