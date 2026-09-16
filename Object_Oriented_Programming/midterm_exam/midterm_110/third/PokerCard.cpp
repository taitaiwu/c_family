# include <iostream>
# include <stdlib.h>
# include <ctime>

# include "PokerCard.h"

PokerCard::deal (void)
{
	number = rand() % 13 + 1;
	suit = rand() % 4;
}

int PokerCard::getNumber() const 
{
	return number;
}

int PokerCard::getSuit() const
{
	return suit;
}
