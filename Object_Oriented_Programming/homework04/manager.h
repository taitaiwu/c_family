# ifndef MANAGER_H

# define MANAGER_H

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>

# include "service_quote.h"

class Manager
{
	private:
		vector<Service_quote> quotes;
		
	public:
		void add_quote(Service_quote quote);
		void delete_quote(int index);
		void show_all_quote();
		void search_by_name(string name);
		void search_by_date(string date);
		int get_quote_size();
};

# endif
