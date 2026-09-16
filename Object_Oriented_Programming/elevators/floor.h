# ifndef FLOOR_H
# define FLOOR_H

# include "hall_panel.h"

class Floor
{
	private:
		int floor;
		Hall_panel hall_panel;

	public:
		explicit Floor(int f);

		int get_floor(void) const;
		Hall_panel& get_panel(void);
};

# endif
