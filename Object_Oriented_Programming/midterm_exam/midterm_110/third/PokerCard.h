# ifndef POKER_CARD_H

# define POKER_CARD_H

class PokerCard
{
	private:
		int number;
		int suit;
		
	public:
		deal();
		int getNumber() const;
		int getSuit() const;
};

# endif
