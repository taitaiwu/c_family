# ifndef MAGAZINE_H

# define MAGAZINE_H

# include "publication.h"

class Magazine: public Publication
{
	private:
		int month;
		string editor;
		int annual_subscription;
		
	public:
		void input(void);
		void output(void) const;
};

# endif
