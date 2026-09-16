# ifndef DOOR_H
# define DOOR_H

class Door
{
	private:
		bool door_open;
		int open_time;   
		int time_left;     

	public:
		explicit Door(int time);

		void open(void);    
		void tick(void);     
		bool is_open(void) const;
		bool is_closed(void) const;
};

# endif
