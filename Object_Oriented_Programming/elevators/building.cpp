# include "building.h"

Building::Building(int floor_count, int elevator_count, double elevator_capacity, int door_open_time)
{
	for (int f = 1; f <= floor_count; f++)
	{
		floors.push_back(Floor(f));
	}

	for (int e = 1; e <= elevator_count; e++)
	{
		elevators.push_back(Elevator(e, floor_count, elevator_capacity, door_open_time));
	}
}

int Building::get_floor_count(void) const
{
	return static_cast<int>(floors.size());
}

int Building::get_elevator_count(void) const
{
	return static_cast<int>(elevators.size());
}

Floor& Building::get_floor(int floor_number)
{
	return floors[floor_number - 1];
}

vector<Elevator>& Building::get_elevators(void)
{
	return elevators;
}
