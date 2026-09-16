# ifndef DOOR_H
# define DOOR_H

class Door
{
	private:
		bool door_open;
		int open_time;
		int time_left;
		
	public:
		void Door(int time);
		void open(void);
		bool is_close(void);
		bool is_open(void) const;
};

# endif
