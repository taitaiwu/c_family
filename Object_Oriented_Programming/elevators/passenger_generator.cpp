# include <ctime>

# include "passenger_generator.h"

Passenger_generator::Passenger_generator(unsigned int seed, int floor_count_, double arrival_probability_)
	: engine(seed == 0 ? static_cast<unsigned int>(time(NULL)) : seed), floor_count(floor_count_),
	  arrival_probability(arrival_probability_),
	  arrival_dist(0.0, 1.0), floor_dist(1, floor_count_), weight_dist(40.0, 100.0), next_id(1)
{
}

Passenger* Passenger_generator::try_generate(int floor, int time)
{
	if (arrival_dist(engine) >= arrival_probability) return NULL;

	int destination = floor_dist(engine);

	while (destination == floor) destination = floor_dist(engine);

	double weight = weight_dist(engine);

	Passenger* passenger = new Passenger(next_id, floor, destination, weight, time);
	next_id++;

	return passenger;
}
