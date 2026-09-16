# ifndef INVENTORY_FILE

# define INVENTORY_FILE

# include "inventory_item.h"

using namespace std;

class Inventory_file
{
	private:
		string file_name;
		void get_item_data(Inventory_item &item);
		void show_item(const Inventory_item &item, int record_num) const;
		
	public:
		Inventory_file(const string &file);
		
		int get_record_count(void) const;
		
		void add_record(void);
		void display_record(void);
		void change_record(void);
		
};

# endif
