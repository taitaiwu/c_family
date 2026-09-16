# include "car_panel.h"

Car_panel::Car_panel(int total_floors): floor_buttons(total_floors), floor_count(total_floors)
{
}

void Car_panel::press(int floor)
{
	floor_buttons[floor - 1].press();
}

void Car_panel::clear(int floor)
{
	floor_buttons[floor - 1].clear();
}

bool Car_panel::is_light(int floor) const
{
	return floor_buttons[floor - 1].is_light();
}

int Car_panel::get_floor_count(void) const
{
	return floor_count;
}
