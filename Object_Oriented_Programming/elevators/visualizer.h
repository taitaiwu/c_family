# ifndef VISUALIZER_H
# define VISUALIZER_H

# include "building.h"

class Visualizer
{
	public:
		static void render(Building& building, int current_time, int total_time, int generated_count, int served_count, int delay_ms);
};

# endif
