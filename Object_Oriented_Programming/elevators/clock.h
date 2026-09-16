# ifndef CLOCK_H
# define CLOCK_H

class Clock
{
	private:
		int current_time;
		int total_time;

	public:
		explicit Clock(int simulation_total_time);

		void tick(void);                   
		int get_current_time(void) const;
		int get_total_time(void) const;
		bool is_running(void) const;      
};

# endif
