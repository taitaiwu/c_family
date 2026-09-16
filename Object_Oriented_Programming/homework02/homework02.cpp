# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <ctime>

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 

// 支援考試標題和姓名有空格輸入
// Support to enter title and name with space 

using namespace std;

int partition(string* name, int* score, int left, int right)
{
	int i = left;
	int j = right;
	int score_temp;
	string name_temp;
	
	while (i < j)
	{
		while ((i < j) && (*(score + j) >= *(score + left)))
		{
			j--;
		}
		
		while ((i < j) && (*(score + i) <= *(score + left)))
		{
			i++;
		}
		
		score_temp = *(score + i);
		*(score + i) = *(score + j);
		*(score + j) = score_temp;
	}
	
	score_temp = *(score + i);
	*(score + i) = *(score + left);
	*(score + left) = score_temp;
	
	return i;
}

void sort(string* name, int* score, int left, int right)
{
	int pivot;
	
	while (left < right)
	{
		pivot = partition(name, score, left, right);
		
		if (pivot - left < right - pivot)
		{
			sort(name, score, left, pivot-1);
			left = pivot + 1;
		}
		
		else
		{
			sort(name, score, pivot+1, right);
			right = pivot - 1;
		}
	}
}

int summation(int* score, int num)
{
	int i, sum = 0;
	
	for (i = 0; i < num; i++)
	{
		sum += *(score+i);
	}
	
	return sum;	
}

double average (int* score, int num)
{
	int sum = summation(score, num);
	
	return (double)sum/(double)num;
}

int main (void)
{
	int num, i, output1_len, sum;
	double mean;
	string title, num_input, score_input;
	time_t now = time(0);
	
	cout << "Please enter the test name：";
	getline(cin, title);
	
	while (true)
	{
		cout << "Please enter the number of students：";
		getline(cin, num_input);
		stringstream s(num_input);
		
		if ((s >> num) && !(s >> num_input) && (num >= 0))  break;

    	if (num < 0)  cout << endl << "INPUT ERROR!! You entered a negative number." << endl;
    	else if (s >> num_input)  cout << endl << "INPUT ERROR!! You entered a non-integer or letter." << endl;
    	else cout << endl << "INPUT ERROR!! Please try again." << endl;
	}
	
	int* score = new int[num];
	string* name = new string[num];
	
	cout << endl << "Now you can enter " << num << " students\' name and score (0~100)." << endl;
	
	for (i = 0; i < num; i++)
	{
		cout << endl << "No." << setw(3) << i+1 << setw(7) << " name：";
		getline(cin, *(name + i));
		
		while (true)
		{
			cout << "No." << setw(3) << i+1 << setw(7) << " score：";
			getline(cin, score_input);
			stringstream s(score_input);
			
			if ((s >> *(score + i)) && !(s >> score_input) && (*(score + i) >= 0) && (*(score + i) <= 100))  break;
	
	    	if (*(score + i) < 0)  cout << endl << "INPUT ERROR!! You entered a negative number." << endl;
	    	else if (*(score + i) > 100)  cout << endl << "INPUT ERROR!! You entered a number greater than 100." << endl;
	    	else if (s >> score_input)  cout << endl << "INPUT ERROR!! You entered a non-integer or letter." << endl;
	    	else cout << endl << "INPUT ERROR!! Please try again." << endl;
		}
	}
	
	sort(name, score, 0, num-1);
	sum = summation(score, num);
	mean = average(score, num);
	
	cout << endl << "※ "BOLD("Test Name")"：" << title << "\t※ "BOLD("Number of Students")"：" << num << endl;
	cout << "※ "BOLD("Sorted List")"：" << endl;
	cout << endl << setw(5) << "No." << setw(20) << "Name" << "\tScore" << endl;
	
	for (i = 0; i < num; i++)
	{
		cout << setw(5) << i+1 << setw(20) << *(name+i)  << "\t" << setw(5) << *(score+i) << endl;
	}
	
	cout << endl << "※ "BOLD("Sum")"：" << sum << "\t※ "BOLD("Average")"：" << setprecision(2) << mean << endl; 
	cout << "※ "BOLD("Export Time")"：" << ctime(&now) << endl;
} 
