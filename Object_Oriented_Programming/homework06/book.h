# ifndef BOOK_H

# define BOOK_H

# include "publication.h"

class Book: public Publication
{
	private:
		string author;
		string ISBN;
		int price;
		
	public:
		void input(void);
		void output(void) const;
		bool check_ISBN(string isbn);
};

# endif
