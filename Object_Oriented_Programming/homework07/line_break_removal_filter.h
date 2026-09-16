# ifndef LINE_BREAK_REMOVAL_FILTER_H

# define LINE_BREAK_REMOVAL_FILTER_H

# include "file_filter.h"

class Line_break_removal_filter: public File_filter
{
	public:
		char transform(char ch) override;	
};

# endif
