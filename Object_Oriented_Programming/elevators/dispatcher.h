# ifndef DISPATCHER_H
# define DISPATCHER_H

# include "building.h"

class Dispatcher
{
	private:
		Building& building;
		Elevator* choose_best(int floor);

	public:
		explicit Dispatcher(Building& b);
		void dispatch(void); 
};

 #endif
