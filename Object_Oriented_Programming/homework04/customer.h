# ifndef CUSTOMER_H

# define CUSTOMER_H

# include <iostream>

using namespace std;

class Customer
{
	public:
		string name;
		string address;
		string phone;
		
		Customer(string customer_name, string customer_address, string customer_phone);
};

# endif 
