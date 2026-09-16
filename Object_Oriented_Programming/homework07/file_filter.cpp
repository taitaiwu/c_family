# include "file_filter.h"

using namespace std;

void File_filter::do_filter (ifstream &in, ofstream &out)
{
	char ch;
	
	while (in.get(ch))
	{
		out.put(transform(ch));
	}
}
