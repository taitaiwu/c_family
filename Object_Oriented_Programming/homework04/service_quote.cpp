# include <iostream>
# include "service_quote.h"

Service_quote::Service_quote (Customer service_customer, Car service_car, int parts, int labor, double tax):
	customer(service_customer), car(service_car),  parts_charge(parts), labor_charge(labor),  sale_tax(tax)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);

        stringstream ss;
        
        ss << 1900 + ltm->tm_year << "/" << setw(2) << setfill('0') << 1 + ltm->tm_mon << "/" << setw(2) << setfill('0') << ltm->tm_mday;

        date = ss.str();
	}
	
int Service_quote::get_tax() const
{
	return round((parts_charge + labor_charge) * sale_tax);
}

int Service_quote::get_total() const
{
	return parts_charge + labor_charge + get_tax();
}

void Service_quote::output()
{
	cout << endl << "========== Service Quote ==========" << endl;
	cout << "¡° Date¡G" << date << endl;
	cout << "¡° Customer¡G" << customer.name  << " (" << customer.phone << ")" << endl;
	cout << "¡° Car¡G" << car.number << " (" <<  car.make << " " << car.model << " - " << car.year << ")" << endl << endl;
	cout << "¡° Parts Charge¡G\t$" << parts_charge << endl;
	cout << "¡° Labor Charge¡G\t$" << labor_charge << endl;
	cout << "¡° Sale Tax¡G\t\t$" << get_tax() << endl;
	cout << "¡° Total Charge¡G\t$" << get_total() << endl;
	cout << "===================================" << endl;
}
