# ifndef USER_INPUT
# define USER_INPUT

# include <string>
# include <vector>

using namespace std;

class User_input
{
	private:
		vector<string> fatial_error;
		
	public:
		int floor_count;
		int elevator_count;
		double elevator_capacity;
		double arrival_probability;
		int total_time;
		int door_waiting_time;
		unsigned int random_seed;
		
		// set default value 
		void User_input(void);
		
		// file input and confirm success
		bool file_input(string& path);
		
		// if file input fail, user can manual input
		void manual_input(void);
		
		// output inputed data
		void data_output(void);
		
		// check data unfatial error
		bool data_check(vector<string> error) const;
		
		// check data fatial error
		const vector<string>& get_fatial_error(void) const;
		bool has_fatial_error(void) const;
};

# endif
