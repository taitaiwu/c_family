#include "floor.h"

Floor::Floor(int f): floor(f), hall_panel(f)
{
}

int Floor::get_floor(void) const
{
	return floor;
}

Hall_panel& Floor::get_panel(void)
{
	return hall_panel;
}
