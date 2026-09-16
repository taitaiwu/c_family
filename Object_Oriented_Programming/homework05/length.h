# ifndef LENGTH_H

# define LENGTH_H

# include <iostream>
# include <string>
# include <sstream>
class Length
{
	private:
		int centimeters;
		int millimeters;
		void translate(void);
		
	public:
		Length(void);
		Length(int cm, int mm);
		
		void set_length(void);
		void get_length(void) const;
		
		int get_length_mm(void) const;
		
		bool operator==(const Length& other) const;
		Length operator+(const Length& other) const;
		int operator*(const Length& other) const;
};

# endif
