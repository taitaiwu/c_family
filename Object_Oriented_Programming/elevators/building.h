# ifndef BUILDING_H
# define BUILDING_H

# include <vector>

# include "floor.h"
# include "elevator.h"

using namespace std;

class Building
{
	private:
		vector<Floor> floors;
		vector<Elevator> elevators;

	public:
		Building(int floor_count, int elevator_count, double elevator_capacity, int door_open_time);

		int get_floor_count(void) const;
		int get_elevator_count(void) const;

		Floor& get_floor(int floor_number);         
		vector<Elevator>& get_elevators(void);
};

# endif
