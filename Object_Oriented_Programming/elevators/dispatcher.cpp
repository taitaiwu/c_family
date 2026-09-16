# include <cstdlib>

# include "dispatcher.h"

Dispatcher::Dispatcher(Building& b): building(b)
{
}

void Dispatcher::dispatch(void)
{
	int floor_count = building.get_floor_count();
	vector<Elevator>& elevators = building.get_elevators();

	for (int f = 1; f <= floor_count; f++)
	{
		Hall_panel& panel = building.get_floor(f).get_panel();

		if (!panel.is_up_button_light() && !panel.is_down_button_light()) continue;

		bool already_assigned = false;

		for (size_t i = 0; i < elevators.size(); i++)
		{
			if (elevators[i].has_stop(f))
			{
				already_assigned = true;
				break;
			}
		}

		if (already_assigned) continue;

		Elevator* best = choose_best(f);

		if (best != NULL) best->add_stop(f);
	}
}

Elevator* Dispatcher::choose_best(int floor)
{
	vector<Elevator>& elevators = building.get_elevators();
	Elevator* best = NULL;
	double best_score = 0.0;

	for (size_t i = 0; i < elevators.size(); i++)
	{
		Elevator& e = elevators[i];

		if (e.get_load() >= e.get_capacity()) continue; 

		if (e.get_current_floor() == floor && !e.is_idle()) continue;

		double score = abs(e.get_current_floor() - floor);
		if (e.is_idle()) score -= 0.5;

		if (best == NULL || score < best_score)
		{
			best_score = score;
			best = &e;
		}
	}

	return best;
}
