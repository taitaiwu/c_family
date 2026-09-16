# include "passenger.h"

void Passenger::Passenger (int i, int o, int d, double w, int c): id(id), ori_floor(ori_floor), des_floor(des_floor), weight(weight), create_time(create_time), enter_time(-1), leave_time(-1)
{
}

int Passenger::get_id (void) const
{
	return id;
}

int Passenger::get_ori_floor (void) const
{
	return ori_floor;
}

int Passenger::get_des_floor (void) const
{
	return des_floor;
}

double Passenger::get_weight (void) const
{
	return weight;
}

int Passenger::get_create_time (void) const
{
	return create_time;
}

int Passenger::get_enter_time (void) const
{
	return enter_time;
}

int Passenger::get_leave_time (void) const
{
	return leave_time;
}

int Passenger::set_enter_time (int time)
{
	enter_time = time;
}

int Passenger::set_leave_time (int time)
{
	leave_time = time;
}

bool Passenger::is_watiting (void)
{
	return enter_time < 0;
}

bool Passenger::is_in_elevator() (void)
{
	return enter_time >= 0 && leave_time < 0;
}

bool Passenger::is_arrived() (void)
{
	return leave_time >= 0;
}

bool Passenger::is_up (void)
{
	return ori_floor < des_floor;
}
