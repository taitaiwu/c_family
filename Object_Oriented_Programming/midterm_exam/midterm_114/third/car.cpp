# include <iostream>
# include <string>

# include "car.h"

using namespace std;

Car::Car(int car_number, string car_mark)
{
	constructor(car_number, car_mark);
}

void  Car::constructor(int car_number, string car_make)
{
	number = car_number;
	make = car_make;
	speed = 0;
} 

int Car::get_number() const
{
	return number;
} 

string Car::get_make() const
{
	return make;
} 

int Car::get_speed() const
{
	return speed;
} 

void Car::accelerate()
{
	speed += 5;
}

void Car::brake()
{
	speed -= 5;
}
