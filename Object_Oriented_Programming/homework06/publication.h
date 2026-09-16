# ifndef PUBLICATION_H

# define PUBLICATION_H

using namespace std;

class Publication
{
	protected:
		string title;
		int volume;
		int year;
		
	public:
		void input(void);
		void output(void) const;
};

# endif
