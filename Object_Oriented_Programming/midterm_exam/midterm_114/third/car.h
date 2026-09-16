# ifndef CAR_H

# define CAR_H
# include <iostream>
# include <string>

class Car
{
	private:
		int number;
		std::string make;
		int speed;
		
	public:
		explicit Car(int car_number, std::string car_mark);
		void constructor(int car_number, std::string car_mark);
		int get_number() const;
		std::string get_make() const;
		int get_speed() const;
		void accelerate();
		void brake();	
};

# endif
