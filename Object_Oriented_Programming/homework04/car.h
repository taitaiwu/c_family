# ifndef CAR_H

# define CAR_H

# include <iostream>

using namespace std;

class Car
{
	public:
		string make;
		string model;
		int year;
		string number;
		
		Car(string car_make, string car_model, int car_year, string car_number);	
};

# endif 
