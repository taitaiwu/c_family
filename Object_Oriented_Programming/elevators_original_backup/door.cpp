# include "door.h"

void Door::Door (int time): door_open(false), open_time(time), time_left(0)
{
}

void Door::open (void)
{
	door_open = true;
	time_left = open_time;
} 

bool Door::is_close (void) const
{
	if (door_open) return false;
	
	time_left--;
	
	if (time_left <= 0)
	{
		door_open = false;
		return true;	
	}
	
	return false; 
}

bool Door::is_open (void) const
{
	return door_open;
}
