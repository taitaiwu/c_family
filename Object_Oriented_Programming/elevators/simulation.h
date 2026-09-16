# ifndef SIMULATION_H
# define SIMULATION_H

# include <vector>

# include "building.h"
# include "dispatcher.h"
# include "clock.h"
# include "passenger_generator.h"
# include "statistics.h"
# include "user_input.h"
# include "visualizer.h"

using namespace std;

class Simulation
{
	private:
		Building building;
		Dispatcher dispatcher;
		Clock clock;
		Passenger_generator generator;
		Statistics statistics;
		vector<Passenger*> all_passengers;
		bool animate;            
		int animation_delay_ms;  

		void generate_passengers(void); 
		void move_elevators(void);     

	public:
		explicit Simulation(const User_input& config);
		~Simulation(void);

		void run(void);              
		void print_report(void) const;  
};

#endif
