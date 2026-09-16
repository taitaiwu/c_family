# include <iostream>
# include <iomanip>

# include "statistics.h"
# include "color.h"

using namespace std;

Statistics::Statistics(void): served_count(0), total_wait_time(0), total_ride_time(0)
{
}

void Statistics::record(const Passenger& passenger)
{
	served_count++;
	total_wait_time += passenger.get_enter_time() - passenger.get_create_time();
	total_ride_time += passenger.get_leave_time() - passenger.get_enter_time();
}

int Statistics::get_served_count(void) const
{
	return served_count;
}

double Statistics::get_average_wait_time(void) const
{
	if (served_count == 0) return 0.0;

	return static_cast<double>(total_wait_time) / served_count;
}

double Statistics::get_average_ride_time(void) const
{
	if (served_count == 0) return 0.0;

	return static_cast<double>(total_ride_time) / served_count;
}

void Statistics::print_report(int total_time, int generated_count, int floor_count, int elevator_count) const
{
	Color color;

	cout << endl;
	cout << color.bold(color.teal_bg(color.white(" Simulation Report "))) << endl;
	cout << "===============================" << endl;
	cout << "  > " << left << setw(22) << "Building Floors" << ":" << floor_count << endl;
	cout << "  > " << left << setw(22) << "Elevator Count" << ":" << elevator_count << endl;
	cout << "  > " << left << setw(22) << "Simulation Time" << ":" << total_time << " sec" << endl;
	cout << "  > " << left << setw(22) << "Passengers Generated" << ":" << generated_count << endl;
	cout << "  > " << left << setw(22) << "Passengers Served" << ":" << served_count << endl;
	cout << "  > " << left << setw(22) << "Passengers Unfinished" << ":" << (generated_count - served_count) << endl;
	cout << fixed << setprecision(2);
	cout << "  > " << left << setw(22) << "Average Wait Time" << ":" << get_average_wait_time() << " sec" << endl;
	cout << "  > " << left << setw(22) << "Average Ride Time" << ":" << get_average_ride_time() << " sec" << endl;
	cout << "===============================" << endl;
}
