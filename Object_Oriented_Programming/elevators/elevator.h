# ifndef ELEVATOR_H
# define ELEVATOR_H

# include <set>
# include <vector>

# include "door.h"
# include "car_panel.h"
# include "passenger.h"
# include "hall_panel.h"

class Statistics;

using namespace std;

enum class Direction { UP, DOWN, IDLE };

class Elevator
{
	private:
		int id;
		int floor_count;
		int current_floor;
		Direction direction;
		double capacity;
		double current_load;
		Door door;
		Car_panel car_panel;
		vector<Passenger*> passengers;
		set<int> stops;

		void decide_direction(void);
		void service_current_floor(int time, Hall_panel& panel, Statistics& stats);

	public:
		Elevator(int elevator_id, int floor_count, double load_capacity, int door_open_time);

		void add_stop(int floor);
		void tick(int time, Hall_panel& panel, Statistics& stats);

		int get_id(void) const;
		int get_current_floor(void) const;
		Direction get_direction(void) const;
		bool is_idle(void) const;
		bool has_stop(int floor) const;
		double get_load(void) const;
		double get_capacity(void) const;
		int get_passenger_count(void) const;
		bool is_door_open(void) const;
};

#endif
