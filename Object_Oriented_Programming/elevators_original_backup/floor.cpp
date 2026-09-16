# include "floor.h"

explicit Floor::Floor (int f): floor(f), elevator_panel(f)
{
}

void Floor::get_floor (void) const
{
	return floor;
}

Elevator_panel& Floor::get_panel()
{
	return elevator_panel;
}
