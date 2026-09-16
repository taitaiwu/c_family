# include <cstdlib>

# include "elevator.h"
# include "statistics.h"

Elevator::Elevator(int elevator_id, int floor_count_, double load_capacity, int door_open_time)
	: id(elevator_id), floor_count(floor_count_), current_floor(1), direction(Direction::IDLE),
	  capacity(load_capacity), current_load(0), door(door_open_time), car_panel(floor_count_)
{
}

void Elevator::add_stop(int floor)
{
	if (floor < 1 || floor > floor_count) return;

	stops.insert(floor);
}

void Elevator::decide_direction(void)
{
	if (stops.empty())
	{
		direction = Direction::IDLE;
		return;
	}


	if (direction == Direction::UP)
	{
		for (set<int>::const_iterator it = stops.begin(); it != stops.end(); ++it)
			if (*it > current_floor) return;
	}
	else if (direction == Direction::DOWN)
	{
		for (set<int>::const_iterator it = stops.begin(); it != stops.end(); ++it)
			if (*it < current_floor) return;
	}


	int nearest = *stops.begin();
	int best_dist = abs(nearest - current_floor);

	for (set<int>::const_iterator it = stops.begin(); it != stops.end(); ++it)
	{
		int dist = abs(*it - current_floor);
		if (dist < best_dist)
		{
			best_dist = dist;
			nearest = *it;
		}
	}

	if (nearest > current_floor) direction = Direction::UP;
	else if (nearest < current_floor) direction = Direction::DOWN;
}

void Elevator::service_current_floor(int time, Hall_panel& panel, Statistics& stats)
{

	vector<Passenger*>::iterator it = passengers.begin();

	while (it != passengers.end())
	{
		Passenger* p = *it;

		if (p->get_des_floor() == current_floor)
		{
			p->set_leave_time(time);
			stats.record(*p);
			current_load -= p->get_weight();
			car_panel.clear(current_floor);
			it = passengers.erase(it);
		}
		else ++it;
	}




	bool boarded_any = true;

	while (boarded_any)
	{
		boarded_any = false;

		for (int dir = 0; dir < 2; dir++)
		{
			bool up = (dir == 0);

			if (!panel.has_waiting(up)) continue;

			Passenger* p = panel.front(up);

			if (current_load + p->get_weight() > capacity) continue;

			panel.pop_front(up);
			p->set_enter_time(time);
			current_load += p->get_weight();
			passengers.push_back(p);
			car_panel.press(p->get_des_floor());
			add_stop(p->get_des_floor());
			boarded_any = true;
		}
	}

	stops.erase(current_floor);
}

void Elevator::tick(int time, Hall_panel& panel, Statistics& stats)
{
	if (door.is_open())
	{
		door.tick();
		return;
	}

	if (stops.count(current_floor) > 0)
	{
		service_current_floor(time, panel, stats);
		door.open();
		return;
	}

	decide_direction();

	if (direction == Direction::UP) current_floor++;
	else if (direction == Direction::DOWN) current_floor--;

}

int Elevator::get_id(void) const
{
	return id;
}

int Elevator::get_current_floor(void) const
{
	return current_floor;
}

Direction Elevator::get_direction(void) const
{
	return direction;
}

bool Elevator::is_idle(void) const
{
	return direction == Direction::IDLE;
}

bool Elevator::has_stop(int floor) const
{
	return stops.count(floor) > 0;
}

double Elevator::get_load(void) const
{
	return current_load;
}

double Elevator::get_capacity(void) const
{
	return capacity;
}

int Elevator::get_passenger_count(void) const
{
	return static_cast<int>(passengers.size());
}

bool Elevator::is_door_open(void) const
{
	return door.is_open();
}
