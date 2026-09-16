# ifndef INVENTORY_ITEM

# define INVENTORY_ITEM

# include <string>

using namespace std;

const int DESC_SIZE = 50;
const int DATE_SIZE = 11; // "YYYY/MM/DD" + '\0'

struct Inventory_item
{
	char item_description[DESC_SIZE];
	int quantity_on_hand;
	int wholesale_cost;
	int retail_cost;
	char date_added_to_inventory[DATE_SIZE];
};

# endif
