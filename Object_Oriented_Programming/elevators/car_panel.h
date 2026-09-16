# ifndef CAR_PANEL_H
# define CAR_PANEL_H

# include <vector>

# include "button.h"

using namespace std;

class Car_panel
{
	private:
		vector<Button> floor_buttons;
		int floor_count;

	public:
		explicit Car_panel(int floor_count);

		void press(int floor);
		void clear(int floor);
		bool is_light(int floor) const;
		int get_floor_count(void) const;
};

# endif
