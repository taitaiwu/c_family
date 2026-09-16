# include <iostream>
# include <fstream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <cctype>

# include "inventory_file.h"
# include "color.h"

using namespace std;

static bool date_check(const string &date) 
{
    if (date.length() != 10) return false;
    if (date[4] != '/' || date[7] != '/') return false;

    for (int i = 0; i < 10; i++) 
	{
        if (i == 4 || i == 7) continue;
        if (!isdigit(static_cast<unsigned char>(date[i]))) return false;
    }

    int year  = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;

    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    
    if (is_leap) days_in_month[1] = 29;

    if (day < 1 || day > days_in_month[month - 1]) return false;

    return true;
}

// ========================================================================================

Inventory_file::Inventory_file (const string &file): file_name(file) {}

void Inventory_file::get_item_data (Inventory_item &item)
{
	string input;
	Color color;
	
	// item_description
	cout << "  > Please input item description : ";
	cin.getline(item.item_description, DESC_SIZE);
	
	// quantity_on_hand
	while (true)
	{
		cout << "  > Please input quantity on hand : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> item.quantity_on_hand) && !(s >> input) && (item.quantity_on_hand >= 0)) break;
		
		cout << endl << "  "  << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input a non-positive integer." << endl; 
	}
	
	// wholesale_cost
	while (true)
	{
		cout << "  > Please input wholesale cost : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> item.wholesale_cost) && !(s >> input) && (item.wholesale_cost >= 0)) break;
		
		cout << endl << "  "  << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input a non-positive integer." << endl; 
	}
	
	// retail_cost
	while (true)
	{
		cout << "  > Please input retail cost : ";
		getline(cin, input);
		
		stringstream s(input);
		
		if ((s >> item.retail_cost) && !(s >> input) && (item.retail_cost >= 0)) break;
		
		cout << endl << "  "  << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input a non-positive integer." << endl; 
	}
	
	// date_added_to_inventory
	while (true)
	{
		cout << "  > Please input date added to inventory : ";
		cin.getline(item.date_added_to_inventory, DATE_SIZE);
		
		if (date_check(item.date_added_to_inventory)) break;
		
		cout << endl << "  " << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input correct date(YYYY/MM/NN)." << endl; 
	}
}

void Inventory_file::show_item(const Inventory_item &item, int record_num) const
{
	Color color; 
	
	cout << color.bold("Record #") << record_num << endl;
	cout << "Description:      " << item.item_description << endl;
    cout << "Quantity on hand: " << item.quantity_on_hand << endl;
    cout << "Wholesale cost:   $" << item.wholesale_cost << endl;
    cout << "Retail cost:      $" << item.retail_cost << endl;
    cout << "Date added:       " << item.date_added_to_inventory << endl;
}

int Inventory_file::get_record_count() const 
{
    fstream file(file_name.c_str(), ios::in | ios::binary);
    
	if (!file) return 0;
	
    file.seekg(0, ios::end);
    
    int num_records = static_cast<int>(file.tellg() / sizeof(Inventory_item));
    
    file.close();
    
    return num_records;
}

void Inventory_file::add_record (void)
{
	Color color;
	
	fstream file(file_name.c_str(), ios::out | ios::binary | ios::app);
	
    if (!file) 
	{
        cout << color.red_bg(color.yellow(" ERROR!! ")) << "Can not open the file." << endl; 
        return;
    }

    Inventory_item item;
    get_item_data(item);

    file.write(reinterpret_cast<char *>(&item), sizeof(Inventory_item));
    file.close();

    cout << color.bold(color.green("Record added.")) << endl;
}

void Inventory_file::display_record (void)
{
	string input;
	int record;
	Color color;
	
    if (get_record_count() == 0) 
	{
        cout << color.red_bg(color.yellow(" NO FOUND!! ")) << " There are not any records in the file." << endl;
        return;
    }

    cout << "There are " << get_record_count() << " record(s) in the file.\n";
    
    while (true)
    {
    	cout << "Enter the record number to display (1-" << get_record_count() << ") : ";
    	getline(cin, input);
    	
    	stringstream s(input);
    	
    	if ((s >> record) && !(s >> input) && (record > 0) && (record < get_record_count() + 1)) break;
    	
    	cout << endl << "  " << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input an integer between 1 to " << get_record_count() << "." << endl; 
	}

    fstream file(file_name.c_str(), ios::in | ios::binary);
    
    if (!file) 
	{
        cout << color.red_bg(color.yellow(" ERROR!! ")) << "Can not open the file." << endl; 
        return;
    }

    Inventory_item item;
    file.seekg((record - 1) * static_cast<long>(sizeof(Inventory_item)));
    file.read(reinterpret_cast<char *>(&item), sizeof(Inventory_item));
    file.close();

    show_item(item, record);
}

void Inventory_file::change_record (void)
{
	string input;
	int record;
	Color color;
	
    if (get_record_count() == 0) 
	{
        cout << color.red_bg(color.yellow(" NO FOUND!! ")) << " There are not any records in the file." << endl;
        return;
    }

    cout << "There are " << get_record_count() << " record(s) in the file.\n";

	while (true)
    {
    	cout << "Enter the record number to change (1-" << get_record_count() << ") : ";
    	getline(cin, input);
    	
    	stringstream s(input);
    	
    	if ((s >> record) && !(s >> input) && (record > 0) && (record < get_record_count() + 1)) break;
    	
    	cout << endl << "  " << color.red_bg(color.yellow(" INPUT ERROR!! ")) << " Please input an integer between 1 to " << get_record_count() << "." << endl; 
	}

    fstream file(file_name.c_str(), ios::in | ios::out | ios::binary);
    
    if (!file) 
	{
        cout << color.red_bg(color.yellow(" ERROR!! ")) << "Can not open the file." << endl; 
        return;
    }

    long pos = (record - 1) * static_cast<long>(sizeof(Inventory_item));

    Inventory_item item;
    file.seekg(pos);
    file.read(reinterpret_cast<char *>(&item), sizeof(Inventory_item));

    cout << endl << "Current data :" << endl;
    show_item(item, record);

    cout << endl << "Enter new data : " << endl;
    get_item_data(item);

    file.seekp(pos);
    file.write(reinterpret_cast<char *>(&item), sizeof(Inventory_item));
    file.close();

    cout << color.bold(color.green("Record updated.")) << endl;
}
