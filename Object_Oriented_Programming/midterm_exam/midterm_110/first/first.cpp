# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

using namespace std;

int main (void)
{
	string input, output;
	float n;
	
	while (true)
	{
		cout << "Please input a number¡G";
		getline(cin, input);
		stringstream s(input);
		
		if ((s >> n) && !(s >> input)) break;
		
		cout << "Input ERROR!" << endl << endl;
	}
	
	stringstream s;
	s << n;
	output = s.str();
	
	if (n > 0) cout << setw(24 - output.length()) << "+" << output << endl;
	else if (n < 0) cout << setw(24 - output.length()) << "-" << output << endl;
	
	cout << string(25 - output.length(), '$') << output << endl;
	
	if (output.find('.') == string::npos) cout << output;
	else cout << fixed << setprecision(2) << n;
}
