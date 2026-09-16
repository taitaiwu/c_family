# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

using namespace std;

int main (void)
{
	int n;
	string input;
	
	while (true)
	{
		cout << "How many screening cases¡G";
		getline(cin, input);
		stringstream s(input);
		
		if ((s >> n) && !(s >> input)) break;
		
		cout << endl << "INPUT ERROR!! Please try again." << endl;
	}
	
	cout << "Input the number and CT of the cases¡G" << endl;
	
	int* num = new int[n];
	int* ct = new int[n];
	int i;
	
	for (i = 0; i < n; i++)
	{
		while (true)
		{
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> *(num+i) >> *(ct+i)) && !(s >> input)) break;
			
			cout << endl << "INPUT ERROR!! Please try again." << endl; 
		}
	}
	
	int ct_value;
	int counter = 0;
	
	while (true)
	{
		while (true)
		{
			cout << "Input the diagnosed CT value¡G";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> ct_value) && !(s >> input)) break;
			
			cout << endl << "INPUT ERROR!! Please try again." << endl;
		}
		
		if (ct_value == -1) break;
		
		for (i = 0; i < n; i++)
		{
			if (*(ct+i) <= ct_value) counter++;
		}
		
		cout << "Diagnosed¡G" << counter << " ( ";
		
		for (i = 0; i < n; i++)
		{
			if (*(ct+i) <= ct_value) cout << *(num+i) << " ";
		}
		
		cout << ")" << endl;
	}
}
