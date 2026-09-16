#ifndef HALL_PANEL_H
#define HALL_PANEL_H

#include <vector>

#include "button.h"
#include "passenger.h"

using namespace std;

class Hall_panel
{
	private:
		int floor;
		Button up_button;
		Button down_button;
		vector<Passenger*> up_line;
		vector<Passenger*> down_line;

	public:
		explicit Hall_panel(int f);

		void add_passenger(Passenger* passenger);



		bool has_waiting(bool up) const;
		Passenger* front(bool up) const;
		void pop_front(bool up);

		bool is_up_button_light(void) const;
		bool is_down_button_light(void) const;
		int get_up_count(void) const;
		int get_down_count(void) const;
		int get_floor(void) const;
};

#endif
