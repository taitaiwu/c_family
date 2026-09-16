# ifndef COPY_FILTER

# define COPY_FILTER

# include "file_filter.h"

class Copy_filter: public File_filter
{
	public:
		char transform(char ch) override;
};

# endif
