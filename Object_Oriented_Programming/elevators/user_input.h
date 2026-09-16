# ifndef USER_INPUT_H
# define USER_INPUT_H

# include <string>
# include <vector>

using namespace std;

class User_input
{
	private:
		vector<string> fatal_error;

	public:
		int floor_count;
		int elevator_count;
		double elevator_capacity;
		double arrival_probability;
		int total_time;
		int door_waiting_time;
		unsigned int random_seed;
		bool animate;
		int animation_delay_ms;

		User_input(void);

		bool file_input(const string& path);  
		void manual_input(void);               
		void data_output(void) const;          

		bool data_check(void);                
		const vector<string>& get_fatal_error(void) const;
		bool has_fatal_error(void) const;
};

# endif
