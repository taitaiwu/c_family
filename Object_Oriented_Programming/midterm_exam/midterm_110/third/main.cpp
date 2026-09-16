# include <iostream>
# include <stdlib.h>
# include <ctime>
# include <string>
# include <sstream>
# include <algorithm>

# include "PokerCard.h"

using namespace std;

int main (void)
{
	string input;
	
	char choose;
	int i, j, k, suit_temp, number_temp;
	int poker[52] = {0};
	int suit[4][5] = {0};
	int number[4][5] = {0};
	
	PokerCard poker_card;
	srand(time(0));
	 
	while (true)
	{
		while (true)
		{
			cout << "Deal Cards?";
			getline(cin, input);
			stringstream s(input);
			
			if ((s >> choose) && !(s >> input)) 
			{
				choose = toupper(choose);
				if (choose == 'Y' || choose == 'N') break;
			}
			
			cout << endl << "INPUT ERROR!! Please enter Y/N or y/n." << endl;
		}
		
		if (choose == 'Y') 
		{
			for (i = 0; i < 4; i++)
			{
				cout << "Hand " << i+1 << "¡G";
				
				for (j = 0; j < 5; j++)
				{
					while (true)
					{
						poker_card.deal();
						suit_temp = poker_card.getSuit();
						number_temp = poker_card.getNumber();
						
						if (poker[suit_temp*13 + number_temp - 1] != 1)
						{
							suit[i][j] = suit_temp;
							number[i][j] = number_temp;
							poker[suit_temp*13 + number_temp - 1] = 1;
							
							if (suit_temp == 0) cout << "Club " << number_temp << " ";
							else if (suit_temp == 1) cout << "Diamond " << number_temp << " ";
							else if (suit_temp == 2) cout << "Heart " << number_temp << " ";
							else if (suit_temp == 3) cout << "Spade " << number_temp << " ";
							
							break;
						}
					}
				}
				
				cout << endl;
			}
			
			cout << endl << "Sort the Card¡G" << endl;
			
			for (i = 0; i < 4; i++)
			{
				cout << "Hand " << i+1 << "¡G";
				
				for (j = 0; j < 4; j++)
			    {
			        for (k = 0; k < 4 - j; k++)
			        {
			            if (number[i][k] > number[i][k+1] || (number[i][k] == number[i][k+1] && suit[i][k] > suit[i][k+1]))
			            {
			                int temp = number[i][k];
			                number[i][k] = number[i][k+1];
			                number[i][k+1] = temp;
			
			                temp = suit[i][k];
			                suit[i][k] = suit[i][k+1];
			                suit[i][k+1] = temp;
			            }
			        }
				}
				
				for (j = 0; j < 5; j++)
			    {
			        if (suit[i][j] == 0) cout << "Club " << number[i][j] << " ";
			        else if (suit[i][j] == 1) cout << "Diamond " << number[i][j] << " ";
			        else if (suit[i][j] == 2) cout << "Heart " << number[i][j] << " ";
			        else if (suit[i][j] == 3) cout << "Spade " << number[i][j] << " ";
			    }
			
			    cout << endl;
			}
		}
		
		else if (choose == 'N')
		{
			cout << endl << "End Progarm!" << endl;
			break;
		}
		
		cout << endl;
	}
}
