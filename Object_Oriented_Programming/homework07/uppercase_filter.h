# ifndef UPPERCASE_FILTER

# define UPPERCASE_FILTER

# include "file_filter.h"

class Uppercase_filter: public File_filter
{
	public:
		char transform(char ch) override;
};

# endif
