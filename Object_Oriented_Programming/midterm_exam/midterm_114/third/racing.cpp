# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <ctime>

# include "car.h"

using namespace std;

int main (void)
{
	srand(time(0));
	
	while (true)
	{
		Car car1(0, "");
		Car car2(0, "");
		Car car3(0, "");
		Car car4(0, "");
		Car car5(0, "");
		Car car6(0, "");
		
		string input, car_mark;
		char choose;
		int num, limit, round;
		int i, j;
		float temp;
	
		while (true)
		{
			cout << "How many car¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> num) && !(s >> input) && (num > 1) && (num < 7)) break;
			
			cout << endl << "INPUT ERROR! Please enter an integer between 2 to 6." << endl;
		}
		
		for (i = 0; i < num; i++)
		{
			cout << "The make of number " << i+1 << "¡G";
			getline(cin, car_mark);
			
			if (i == 0) car1.constructor(i+1, car_mark);
			else if (i == 1) car2.constructor(i+1, car_mark);
			else if (i == 2) car3.constructor(i+1, car_mark);
			else if (i == 3) car4.constructor(i+1, car_mark);
			else if (i == 4) car5.constructor(i+1, car_mark);
			else if (i == 5) car6.constructor(i+1, car_mark);
		}
		
		while (true)
		{
			cout << "Speed limits of car¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> limit) && !(s >> input) && (limit > 0)) break;
			
			cout << endl << "INPUT ERROR! Please enter an integer greater than 0." << endl;
		}
		
		while (true)
		{
			cout << "How many round of acceleration/braking¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> round) && !(s >> input) && (round >= 0)) break;
			
			cout << endl << "INPUT ERROR! Please enter a positive integer." << endl;
		}
		
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < round; j++)
			{
				temp = rand() % 100 + 1;
				
				if (i == 0)
				{
					if (temp < 20) car1.brake();
					else car1.accelerate();
				}
				
				else if (i == 1)
				{
					if (temp < 20) car2.brake();
					else car2.accelerate();
				}
				
				else if (i == 2)
				{
					if (temp < 20) car3.brake();
					else car3.accelerate();
				}
				
				else if (i == 3)
				{
					if (temp < 20) car4.brake();
					else car4.accelerate();
				}
				
				else if (i == 4)
				{
					if (temp < 20) car5.brake();
					else car5.accelerate();
				}
				
				else if (i == 5)
				{
					if (temp < 20) car6.brake();
					else car6.accelerate();
				}
			}
		}
		
		cout << "The final speed of each car¡G" << endl;
		
		for (i = 0; i < num; i++)
		{
			if (i == 0) 
			{
				if (car1.get_speed() > limit) cout << "Race number " << i+1 << " " << car1.get_make() << "¡Gcrashed (" << car1.get_speed() << ")" << endl;
				else cout << "Race number " << i+1 << " " << car1.get_make() << "¡G" << car1.get_speed() << endl;
			}
			
			else if (i == 1) 
			{
				if (car2.get_speed() > limit) cout << "Race number " << i+1 << " " << car2.get_make() << "¡Gcrashed (" << car2.get_speed() << ")" << endl;
				else cout << "Race number " << i+1 << " " << car2.get_make() << "¡G" << car2.get_speed() << endl;
			}
			
			else if (i == 2) 
			{
				if (car3.get_speed() > limit) cout << "Race number " << i+1 << " " << car3.get_make() << "¡Gcrashed (" << car3.get_speed() << ")" << endl;
				else cout << "Race number " << i+1 << " " << car1.get_make() << "¡G" << car3.get_speed() << endl;
			}
			
			else if (i == 3) 
			{
				if (car4.get_speed() > limit) cout << "Race number " << i+1 << " " << car4.get_make() << "¡Gcrashed (" << car4.get_speed() << ")" << endl;
				else cout << "Race number " << i+1 << " " << car4.get_make() << "¡G" << car4.get_speed() << endl;
			}
			
			else if (i == 4) 
			{
				if (car5.get_speed() > limit) cout << "Race number " << i+1 << " " << car5.get_make() << "¡Gcrashed (" << car5.get_speed() << ")" << endl;
				else cout << "Race number " << i+1 << " " << car5.get_make() << "¡G" << car5.get_speed() << endl;
			}
			
			else if (i == 5) 
			{
				if (car6.get_speed() > limit) cout << "Race number " << i+1 << " " << car6.get_make() << "¡Gcrashed (" << car6.get_speed() << ")" << endl;
				else cout << "Race number " << i+1 << " " << car6.get_make() << "¡G" << car6.get_speed() << endl;
			}
		}
		
		while (true)
		{
			cout << "Want to play again(Y/N)?";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> choose) && !(s >> input))
			{
				choose = toupper(choose);
				if (choose == 'Y' || choose == 'N') break;
			}
			
			cout << endl << "INPUT ERROR! Please enter Y or N" << endl;
		}
		
		if (choose == 'N')
		{
			cout << "End the program!" << endl;
			break;
		}
	}
}
