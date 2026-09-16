# include "door.h"

Door::Door(int time): door_open(false), open_time(time), time_left(0)
{
}

void Door::open(void)
{
	door_open = true;
	time_left = open_time;
}

void Door::tick(void)
{
	if (!door_open) return;

	time_left--;

	if (time_left <= 0) door_open = false;
}

bool Door::is_open(void) const
{
	return door_open;
}

bool Door::is_closed(void) const
{
	return !door_open;
}
