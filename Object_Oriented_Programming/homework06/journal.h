# ifndef JOURNAL_H

# define JOURNAL_H

# include "publication.h"

class Journal: public Publication
{
	private:
		int month;
		string ISSN;
		double impact_factor;
		int annual_subscription;
		
	public:
		void input(void);
		void output(void) const;
		bool check_ISSN(string issn);
};

# endif
