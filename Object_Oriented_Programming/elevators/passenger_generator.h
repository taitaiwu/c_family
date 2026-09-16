# ifndef PASSENGER_GENERATOR_H
# define PASSENGER_GENERATOR_H

# include <random>

# include "passenger.h"

using namespace std;

class Passenger_generator
{
	private:
		mt19937 engine;
		int floor_count;
		double arrival_probability;
		uniform_real_distribution<double> arrival_dist;
		uniform_int_distribution<int> floor_dist;
		uniform_real_distribution<double> weight_dist;
		int next_id;

	public:
		Passenger_generator(unsigned int seed, int floor_count, double arrival_probability);

		Passenger* try_generate(int floor, int time);
};

# endif
