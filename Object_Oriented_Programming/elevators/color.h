# ifndef COLOR_H
# define COLOR_H

# include <string>

using namespace std;

class Color
{
	public:
		string bold(const string &s);
		string underline(const string &s);
		string shine(const string &s);
		string black(const string &s);
		string red(const string &s);
		string green(const string &s);
		string yellow(const string &s);
		string blue(const string &s);
		string purple(const string &s);
		string teal(const string &s);
		string white(const string &s);
		string black_bg(const string &s);
		string red_bg(const string &s);
		string green_bg(const string &s);
		string yellow_bg(const string &s);
		string blue_bg(const string &s);
		string purple_bg(const string &s);
		string teal_bg(const string &s);
		string white_bg(const string &s);
};

# endif
