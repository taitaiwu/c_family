# include "clock.h"

Clock::Clock(int simulation_total_time): current_time(0), total_time(simulation_total_time)
{
}

void Clock::tick(void)
{
	current_time++;
}

int Clock::get_current_time(void) const
{
	return current_time;
}

int Clock::get_total_time(void) const
{
	return total_time;
}

bool Clock::is_running(void) const
{
	return current_time < total_time;
}
