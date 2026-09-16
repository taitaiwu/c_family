# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <windows.h>

# include "visualizer.h"

using namespace std;

namespace
{
	string direction_label(Direction dir)
	{
		if (dir == Direction::UP) return "UP";
		if (dir == Direction::DOWN) return "DOWN";
		return "--";
	}
}

void Visualizer::render(Building& building, int current_time, int total_time,
                         int generated_count, int served_count, int delay_ms)
{
	system("cls");

	int floor_count = building.get_floor_count();
	vector<Elevator>& elevators = building.get_elevators();

	cout << "============ Elevator Simulation   t = " << current_time << " / " << total_time << " sec ============" << endl;
	cout << left << setw(7) << "Floor" << setw(6) << "Hall";

	for (size_t i = 0; i < elevators.size(); i++)
	{
		cout << setw(15) << ("E" + to_string(elevators[i].get_id()));
	}

	cout << endl;

	for (int f = floor_count; f >= 1; f--)
	{
		Hall_panel& panel = building.get_floor(f).get_panel();
		string hall;

		if (panel.is_up_button_light()) hall += "^";
		if (panel.is_down_button_light()) hall += "v";

		cout << left << setw(7) << f << setw(6) << hall;

		for (size_t i = 0; i < elevators.size(); i++)
		{
			Elevator& e = elevators[i];
			string cell;

			if (e.get_current_floor() == f)
			{
				if (e.is_door_open()) cell = "[OPEN " + to_string(e.get_passenger_count()) + "p]";
				else cell = "[" + direction_label(e.get_direction()) + " " + to_string(e.get_passenger_count()) + "p]";
			}
			else
			{
				cell = "|";
			}

			cout << setw(15) << cell;
		}

		cout << endl;
	}

	cout << "=================================================================================" << endl;
	cout << "Passengers generated: " << generated_count << "   served: " << served_count << endl;

	if (delay_ms > 0) Sleep(delay_ms);
}
