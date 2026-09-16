# ifndef FILE_FILTER_H

# define FILE_FILTER_H

# include <fstream>

using namespace std;

class File_filter
{
	public:
    	void do_filter(ifstream &in, ofstream &out);
    	
    	virtual char transform(char ch) = 0;
    	virtual ~File_filter() {}
};

# endif
