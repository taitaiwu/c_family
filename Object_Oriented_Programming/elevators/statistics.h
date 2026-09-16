# ifndef STATISTICS_H
# define STATISTICS_H

# include "passenger.h"

class Statistics
{
	private:
		int served_count;  
		long total_wait_time;  
		long total_ride_time;     

	public:
		Statistics(void);

		void record(const Passenger& passenger);

		int get_served_count(void) const;
		double get_average_wait_time(void) const;
		double get_average_ride_time(void) const;

		void print_report(int total_time, int generated_count, int floor_count, int elevator_count) const;
};

# endif
