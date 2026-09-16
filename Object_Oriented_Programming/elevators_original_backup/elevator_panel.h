# ifndef ELEVATOR_PANEL
# define ELEVATOR_PANEL

# include <vector>

# include "button.h"
# include "passenger.h"

using namespace std;

class Elevator_panel
{
	private:
		int floor;
		Button up_button;
		Button down_button;
		vector<Passenger*> up_line;
		vector<Passenger*> down_line;
		
	public:
		explicit Elevator_panel(int f);
		void passenger_line(Passenger* passenger);
		vector<Passenger*>& get_passenger_line(bool up);
		void remove_in_elevator(bool up, int count);
		void clear_button(bool up);
		bool is_up_button_light(void) const;
		bool is_down_button_light(void) const;
		int get_up_size(void) const;
		int get_down_size(void) const;
		int get_floor(void) const;
		vector<Passenger*> clear_line(void);
		vector<Passenger*> clear_waiting(void);
};

# endif
