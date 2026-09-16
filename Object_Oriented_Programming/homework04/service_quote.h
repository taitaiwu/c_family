# ifndef SERVICE_QUOTE

# define SERVICE_QUOTE

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <cmath>

# include "customer.h"
# include "car.h"

class Service_quote
{
	public:
		Customer customer;
		Car car;
		
		int parts_charge;
		int labor_charge;
		double sale_tax;
		string date;
		
		Service_quote(Customer service_customer, Car service_car, int parts, int labor, double tax=0.05);
		int get_tax() const;
		int get_total() const;
		void output();
};

# endif
