# include "simulation.h"

Simulation::Simulation(const User_input& config)
	: building(config.floor_count, config.elevator_count, config.elevator_capacity, config.door_waiting_time),
	  dispatcher(building),
	  clock(config.total_time),
	  generator(config.random_seed, config.floor_count, config.arrival_probability),
	  animate(config.animate),
	  animation_delay_ms(config.animation_delay_ms)
{
}

Simulation::~Simulation(void)
{
	for (size_t i = 0; i < all_passengers.size(); i++)
	{
		delete all_passengers[i];
	}
}

void Simulation::generate_passengers(void)
{
	int floor_count = building.get_floor_count();
	int time = clock.get_current_time();

	for (int f = 1; f <= floor_count; f++)
	{
		Passenger* passenger = generator.try_generate(f, time);

		if (passenger != NULL)
		{
			building.get_floor(f).get_panel().add_passenger(passenger);
			all_passengers.push_back(passenger);
		}
	}
}

void Simulation::move_elevators(void)
{
	vector<Elevator>& elevators = building.get_elevators();
	int time = clock.get_current_time();

	for (size_t i = 0; i < elevators.size(); i++)
	{
		Elevator& elevator = elevators[i];
		Hall_panel& panel = building.get_floor(elevator.get_current_floor()).get_panel();
		elevator.tick(time, panel, statistics);
	}
}

void Simulation::run(void)
{
	while (clock.is_running())
	{
		clock.tick();
		generate_passengers(); 
		dispatcher.dispatch();  
		move_elevators();      

		if (animate)
		{
			Visualizer::render(building, clock.get_current_time(), clock.get_total_time(),
			                    static_cast<int>(all_passengers.size()), statistics.get_served_count(),
			                    animation_delay_ms);
		}
	}
}

void Simulation::print_report(void) const
{
	statistics.print_report(
		clock.get_total_time(),
		static_cast<int>(all_passengers.size()),
		building.get_floor_count(),
		building.get_elevator_count()
	);
}
