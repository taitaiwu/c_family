# ifndef FLOOR_H
# define FLOOR_H

# include "elevator_panel.h"

class Floor
{
	private:
		int floor;
		Elevator_panel elevator_panel;
		
	public:
		explicit Floor(int f);
		int get_floor(void) const;
		Elevator_panel& get_panel(void);
};

# endif
