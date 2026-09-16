# ifndef ENCRYPTION_FILTER

# define ENCRYPTION_FILTER

# include "file_filter.h"

class Encryption_filter: public File_filter
{
	private:
		int key;
		
	public:
		Encryption_filter(int key);
		char transform(char ch) override;
};

# endif
