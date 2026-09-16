# include <iostream>
# include <string>
# include <sstream>

using namespace std;

template <class T>
T compare (T a, T b)
{
	if (a <= b)  cout << a << " " << b << endl;
	else cout << b << " " << a << endl;
}

int main (void)
{
	string input;
	int m, n;
	char o, p, choose;
	
	while (true)
	{
		while (true)
		{
			cout << "Please enter two integers or two character¡G";
			getline(cin, input);
			stringstream s1(input);
			stringstream s2(input);
			
			if ((s1 >> m >> n) && !(s1 >> input)) 
			{
				compare(m ,n);
				break;
			}
			
			else if ((s2 >> o >> p) && !(s2 >> input))
			{
				compare(o, p);
				break;
			}
			
			cout << endl << "INPUT ERROR!" << endl;
		}
		
		while (true)
		{
			cout << "Run the progarm again(Y/N)¡G";
			getline(cin, input);
			stringstream s3(input);
			
			if ((s3 >> choose) && !(s3 >> input)) 
			{
				choose = toupper(choose);
				if (choose == 'Y' || choose == 'N') break;
			}
			
			cout << endl << "INPUT ERROR! Please enter Y or N." << endl;
		}
		
		if (choose == 'N')
		{
			cout << endl << "End the program!" << endl;
			break;
		}
	}
} 
