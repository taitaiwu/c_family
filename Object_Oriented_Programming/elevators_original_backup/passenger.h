# ifndef PASSENGER_H
# define PASSENGER_H

class Passenger
{
	private:
		int id;
		int ori_floor;
		int des_floor;
		double weight;
		int create_time;
		int enter_time;
		int leave_time;
		
	public:
		void Passenger(int i, int o, int d, double w, int c);
		
		int get_id(void) const;
		int get_ori_floor(void) const;
		int get_des_floor(void) const;
		double get_weight(void) const;
		int get_create_time(void) const;
		int get_enter_time(void) const;
		int get_leave_time(void) const;
		
		void set_enter_time(int time);
		void set_leave_time(int time);
		
		bool is_watiting(void) const;
		bool is_in_elevator(void) const;
		bool is_arrived(void) const;
		bool is_up(void) const;
};

# endif
