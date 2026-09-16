# include "manager.h"

void Manager::add_quote (Service_quote quote)
{
	quotes.push_back(quote);
	
	cout << endl << "Add a quote was successful." << endl;
}

void Manager::delete_quote (int index)
{
	if (index >= 0 && index < quotes.size())
	{
		quotes.erase(quotes.begin() + index);
		cout << "Delete Quote No. " << index + 1 << " was successful." << endl;
	}
	
	else cout << "Can't find No. " << index + 1 << " ." << endl;
}

void Manager::show_all_quote()
{
	int i;
	
	if (quotes.size() == 0) cout << "There is not any quote, please go add a few more!" << endl;
	
	else 
	{
		for (i = 0; i < quotes.size(); i++)
		{
			cout << "No." << setw(2) << i+1 << " " << quotes[i].customer.name << " - " << quotes[i].date << endl;
		}
		
		cout << endl;
	}
}

void Manager::search_by_name (string name)
{
	int i;
	bool find = false;
	
	for (i = 0; i < quotes.size(); i++)
	{
		Service_quote &q = quotes[i];
		if (q.customer.name == name) 
		{
			q.output();
			find = true;
		}
		
		if (!find) cout << "Can't find any " << name << "'s quote." << endl;
	}
}

void Manager::search_by_date (string date)
{
	int i;
	bool find = false;
	
	for (i = 0; i < quotes.size(); i++)
	{
		Service_quote &q = quotes[i];
		if (q.date == date) 
		{
			q.output();
			find = true;
		}
	}
	
	if (!find) cout << "Can't find any quote for" << date << "." << endl;
}

int Manager::get_quote_size()
{
	return quotes.size();
}
