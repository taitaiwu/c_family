# ifndef RECTANGLE_H

# define RECTANGLE_H

# include <iostream>
# include <string>
# include <sstream>

# include "length.h"

class Rectangle
{
	private:
		Length side1;
		Length side2;
		
	public:
		void set_sides(void); 
		void get_sides(void) const;
		
		bool is_square(void) const;
		
		int get_area(void) const;
		
		Length get_perimeter(void) const;
};

# endif
